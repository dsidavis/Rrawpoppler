#
# This generates the C++ methods for the ROutputDev class.
# It implements each method in the class by creating a C++ routine with that 
# signature.  It looks up the list of R functions registered by the caller to
# implement the methods using the name of the method.  (In our case, there is no overloading.)
#  
#


# source("fun.R")

createMethod =
function(fun, className = "ROutputDev", typeMap = NULL, defaultValues = character())
{
   rt = fun@returnType

   isVoid = rt$kind == CXType_Void
   
   code = c( sprintf('SEXP fun = lookupRMethod("%s");', fun@name),
             "if(fun == R_NilValue)",
             paste("  ", if(isVoid) "return" else getDefaultReturnValue(fun@name, rt, defaultValues), ";"))

   params = fun@params
   if(length(names(params)) == 0 || all(names(params) == ""))
       names(params) = LETTERS[seq(along = params) ]
   numParams = length(params)

   body = 
         c(code,
           "",
           "",
           "SEXP e, cur;",
           sprintf("PROTECT(e = cur = allocVector(LANGSXP, %d));", numParams + 1),
           "SETCAR(cur, fun); cur = CDR(cur);",
           sprintf("SETCAR(cur, %s); cur = CDR(cur);", mapply(convertCArgsToR, params, names(params), MoreArgs = list(typeMap = typeMap))),
           sprintf("%s invokeMethod(e);", if(isVoid) "" else "SEXP r_ans ="),
           if(!isVoid)
              paste(getCReturn(rt, c("r_ans", "ans"), typeMap), ";"),
           "UNPROTECT(1);",
           if(!isVoid)
            "return(ans);"
         )

   # signature could be just print the def and replace the name with className::name
#   sig = as(fun, "character")
# 
   sig = c(getName(rt), fun@name, "(", paste(mapply(mkParam, params, names(params)), collapse = ", "),  ")")
   sig = paste(sig, collapse = " ")
   osig = gsub(sprintf(" (%s) ?\\(", fun@name), sprintf(" %s::\\1(", className), sig)

   list(code = c(osig, "{", sprintf("\t%s", body), "}"), decl = sig)
}    

mkParam =
function(type, name)
{
    paste(getName(getType(type)), name)
}



convertCArgsToR =
function(param, name, typeMap = NULL)    
{
  convertValueToR(getType(param), name, typeMap = typeMap, rvar = character())
}

getCReturn =
function(type, vars, typeMap = NULL)
{
  paste(getName(type), getConvertRValue(type, vars[2], vars[1], typeMap = typeMap))
}


getDefaultReturnValue  =
function(method, type, defaultValues = character())
{
  if(method %in% names(defaultValues))
     return(sprintf("return(%s)", defaultValues[[method]]))

  tyname = getName(type)
  if(tyname %in% names(defaultValues))
     return(sprintf("return(%s)", defaultValues[[tyname]]))

  if(tyname %in% c("GBool", "bool"))
      return("return(0)")

  if(isPointerType(type))
      return("return(NULL)")

  "return()"
}
    


if(FALSE) {
m = k$OutputDev@methods
m = m[-1] # remove the constructor
m = m [ setdiff(names(m), c("checkPageSlice", "drawForm")) ]

code = lapply(m, createMethod, typeMap = typemap)
cat(unlist(sapply(code, `[[`, 1)), sep = "\n", file = "../src/ROutputDev_auto.cpp_code")
cat(paste(sapply(code, `[[`, 2), ";"), sep = "\n", file = "../src/ROutputDev_auto.h")
}


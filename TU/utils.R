genClassCode =
function(def, typeMap = NULL, omit = character(), omitRX = character(), fun = createCppMethod)
{
  methods = def@methods[! sapply(def@methods, is, "C++ClassConstructor") ]

#XXX Fix
  if(length(omit))
     methods = methods[ setdiff(names(methods), omit) ]

  if(length(omitRX))
      methods = methods[ !grepl(omitRX, names(methods)) ]

  methods = methods[ !grepl("^operator", names(methods)) ]
  
#XXX Fix
  i = sapply(methods, function(x) x@returnType$kind %in% c(CXType_Enum, CXType_Record))
  methods = methods[ !i ]

  if(length(fun))
     lapply(getPublic(methods), fun, typeMap = typeMap)
  else
      methods
}

cppCodeToFile =
function(defs, file)
{
    funs = sapply(defs, as, "character")
    txt = sprintf('extern "C"\n%s', funs)
    cat("#define R_NO_REMAP 1", '#include "Rpoppler.h"', txt, file = file, sep = "\n\n")
}



mkClassDefs =
function(defs)
{
  lapply(defs, function(def)  {
           super = gsub("^class ", "", sapply(def@superClasses, getName))
           if(length(super))
              super = paste("c(", paste(sprintf('"%s"', super), collapse = ", "), ")")
           else
              super = "'RC++Reference'"
           c(sprintf("setClass('%s', contains = %s)", def@name, super),
             sprintf("setClass('%sPtr', contains = '%s')", def@name, def@name))
       })
}


getClassNames =
function(defs)
{
   ids = sapply(defs, slot, "name")
   sprintf("'%s', '%sPtr'",  ids, ids)
}


############################

mkRGenericMethods =
    #
    # Given the R functions generated from all of the classes methods, we look for overloaded
    # functions. In our case of poppler, there is no overloading within class. So this is a simpler case.
    #
    # We convert each of the overloaded functions into methods and generate generics
    #
    # Assumes names are on the rcode object identifying the classes
function(rcode)
{
   tt = sort(table(unlist(lapply(rcode, names))))
   funNames = names(tt)[tt > 1]

   if(length(funNames) == 0)
       return(rcode)

   generics = sapply(funNames, mkGeneric)


   list(rcode = mapply(convertToMethods, rcode, names(rcode), MoreArgs = list(funNames = funNames)),
        generics = generics)
}


mkGeneric =
function(funName)
{
   sprintf( 'setGeneric("%s", function(this, ...) standardGeneric("%s"))', funName, funName)
}

convertToMethods =
function(classCode, className, funNames)
{
   i = match(funNames, names(classCode), 0)
   classCode[i] = lapply(classCode[i], cvtToMethod, className)
   classCode
}


cvtToMethod =
function(fun, className)
{
    m = as(fun, "RMethodDefinition")
    m@dispatchSignature = className
    m
}



defaultParamValue =
function(param)
{

   toks = getCursorTokens(param)
   i = match("=", toks)
   if(is.na(i))
      return(NULL)

   toks = toks[-(1:i)]
   if(toks[length(toks)] %in% c(")", ","))
       toks = toks[-length(toks)]

   paste(toks, collapse = " ")
}


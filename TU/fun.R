library(RCIndex)
library(RCodeGen)
gen = 
function()
{
    ans = list()
    v = function(cur, ...) {
         if(cur$kind == CXCursor_ClassDecl)
            ans[[ length(ans) + 1]]  <<- cur
        
        CXChildVisit_Continue
    }
    list(visitor = v, ans = function() ans)
}

if(TRUE) {
#source("fun.R")
#tu = createTU("/usr/local/include/poppler/PDFDoc.h", includes = c("/usr/local/include/poppler", "/usr/local/include"), args = "-xc++")

tu = createTU("poppler.cc", includes = c("/usr/local/include/poppler", "/usr/local/include"), args = "-xc++")
g = gen()
visitTU(tu, g$visitor)
e = g$ans()
# We pick up simple forward declarations such as class PDFDoc;  so discard those.
e = e[ sapply(e, function(x) length(children(x))) > 0]
names(e) = sapply(e, getName)

if(FALSE) {
    # These are specific
doc = readCppClass(e[["PDFDoc"]])
names(doc@methods)

code = createCppMethod(doc@methods$getDocInfoCreator, typeMap = typemap)
rotate = createCppMethod(doc@methods$getPageRotate, typeMap = typemap)

a = createRProxy(doc@methods$getDocInfoCreator, typeMap = typemap)
b = createRProxy(doc@methods$getPageRotate, typeMap = typemap)
}


# Convert the actual class definitions into R objects
k = lapply(e, readCppClass)



# Resolve GBool
# Goffset
# Are these typedef
#  in makeLocalVar():  getTypeKind(type) - typedef
#   getCanonicalType(type)
#

# Generate code for Page, PDFDoc,
# OutputDev we do in genOutputDev.R so ignore here.


#source("utils.R")


if(FALSE) {
cpp.page = lapply(getPublic(k$Page@methods), createCppMethod, typeMap = typemap)
cpp.doc = lapply(getPublic(k$PDFDoc@methods), createCppMethod, typeMap = typemap)
cpp.state = lapply(getPublic(k$GfxState@methods), createCppMethod, typeMap = typemap)
cpp.obj = lapply(getPublic(k$Object@methods), createCppMethod, typeMap = typemap)
}


# This specifies how to deal with several types. We could resolve the typedefs for GBool
#
# XXX Deal with passing an R string as GooString.
#
logicCFun = function(cvar, rvar, type, typeMap, cast) { sprintf("%s = LOGICAL(%s)[0];", cvar, rvar)}
logicToR = function(cvar, rvar, type, typeMap, cast){sprintf("Rf_ScalarLogical(%s)", cvar)}
longlongToR = function(cvar, rvar, type, typeMap, cast){sprintf("Rf_ScalarReal(%s)", cvar)}
typemap = list("GooString *"= list(convertValueToR = "GooStringToR",
                                   convertRValue = "GooStringFromR",
                                   coerceRParam = function(var, type, typeMap, ...)
                                                            sprintf("as(%s, 'GooStringOrCharacter')", var) ),
               "long long" = list(convertValueToR = longlongToR,
                                  convertRValue = function(cvar, rvar, type, typeMap, cast) sprintf("%s = REAL(%s)[0];", cvar, rvar)),
               GBool = list(convertRValue = logicCFun, convertValueToR = logicToR),
               "Guchar *" = list(convertRValue = function(cvar, rvar, type, typeMap, cast){ sprintf("%s = (Guchar *) RAW(%s);", cvar, rvar) }),
               bool = list(convertRValue = logicCFun, convertValueToR = logicToR))


if(FALSE) {
cpp.obj = genClassCode(k$Object, typemap)
cppCodeToFile(cpp.obj, "../src/RObject.cc")


cpp.doc = genClassCode(k$PDFDoc, typemap, c("displayPage", "displayPages", "displayPageSlice"))
cppCodeToFile(cpp.doc, "../src/RPDFDoc.cc")

cpp.state = genClassCode(k$GfxState, typemap)
cppCodeToFile(cpp.state, "../src/RGfxState.cc")
}

ids = c("PDFDoc", "Object", "GfxState", "Catalog", "Dict", "GfxColorSpace", "GfxPath", "GfxSubpath", "Page", "PDFRectangle", "XRef") # "PageAttrs",
code = lapply(ids, function(x) genClassCode(k[[x]], typemap, c("displayPage", "displayPages", "displayPageSlice", "displaySlice", "getSignatureWidgets", "createGfx"), "get(RGB|RGBX|CMYK|DeviceN|Gray)Line"))
invisible(mapply(cppCodeToFile, code, sprintf("../src/R%s.cc", ids)))

# Now the R code

rcode = lapply(ids, function(x) genClassCode(k[[x]], typemap, c("displayPage", "displayPages", "displayPageSlice", "displaySlice", "getSignatureWidgets", "createGfx"), "get(RGB|RGBX|CMYK|DeviceN|Gray)Line", fun = createRProxy))
names(rcode) = ids

#XXX Temp
rcode[["GfxColorSpace"]] = rcode[["GfxColorSpace"]][ setdiff(names(rcode[["GfxColorSpace"]]), "setDisplayProfile") ]


tmp = mkRGenericMethods(rcode) 
rcode = tmp$rcode
#Testing: envs = lapply(rcode, function(x) { e = new.env(); eval(parse(text = sapply(rcode, as, 'character')), e); e})
cat(tmp$generics, file = "../R/A_generics.R", sep = "\n\n")

invisible(mapply(function(code, file) cat(sapply(code, as, 'character'), sep = "\n\n", file = file), rcode, sprintf("../R/R_%s_auto.R", ids)))

cat(unlist(mkClassDefs(k)), sep = "\n", file = "../R/A_classes.R")

# For the NAMESPACE
cat(paste(getClassNames(k), collapse = ",\n"))

# Names of the R functions
unlist(lapply(rcode, names)) 
}




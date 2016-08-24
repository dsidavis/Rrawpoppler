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


genClassCode =
function(def, typeMap = NULL, omit = character(), omitRX = character())
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

  lapply(getPublic(methods), createCppMethod, typeMap = typeMap)
}

cppCodeToFile =
function(defs, file)
{
    cat("#define R_NO_REMAP 1", '#include "Rpoppler.h"', sapply(defs, as, "character"), file = file, sep = "\n\n")
}


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
typemap = list("GooString *"= list(convertValueToR = "GooStringToR"),
               "long long" = list(convertValueToR = longlongToR,
                                  convertRValue = function(cvar, rvar, type, typeMap, cast) sprintf("%s = REAL(%s)[0];", cvar, rvar)),
               GBool = list(convertRValue = logicCFun, convertValueToR = logicToR),
               "Guchar *" = list(convertRValue = function(cvar, rvar, type, typeMap, cast){ sprintf("%s = (Guchar *) RAW(%s);", cvar, rvar) }),
               bool = list(convertRValue = logicCFun, convertValueToR = logicToR))


cpp.obj = genClassCode(k$Object, typemap)
cppCodeToFile(cpp.obj, "../src/RObject.cc")


cpp.doc = genClassCode(k$PDFDoc, typemap, c("displayPage", "displayPages", "displayPageSlice"))
cppCodeToFile(cpp.doc, "../src/RPDFDoc.cc")

cpp.state = genClassCode(k$GfxState, typemap)
cppCodeToFile(cpp.state, "../src/RGfxState.cc")

ids = c("PDFDoc", "Object", "GfxState", "Catalog", "Dict", "GfxColorSpace", "GfxPath", "GfxSubpath", "Page", "PageAttrs", "PDFRectangle", "XRef")
code = lapply(ids, function(x) genClassCode(k[[x]], typemap, c("displayPage", "displayPages", "displayPageSlice", "displaySlice", "getSignatureWidgets", "createGfx"), "get(RGB|RGBX|CMYK|DeviceN|Gray)Line"))
invisible(mapply(cppCodeToFile, code, sprintf("../src/R%s.cc", ids)))
}



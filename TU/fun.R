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
tu = createTU("/usr/local/include/poppler/PDFDoc.h", includes = c("/usr/local/include/poppler", "/usr/local/include"), args = "-xc++")
tu = createTU("poppler.cc", includes = c("/usr/local/include/poppler", "/usr/local/include"), args = "-xc++")
g = gen()
visitTU(tu, g$visitor)
e = g$ans()
e = e[ sapply(e, function(x) length(children(x))) > 0]
names(e) = sapply(e, getName)

if(FALSE) {
doc = readCppClass(e[["PDFDoc"]])
names(doc@methods)

code = createCppMethod(doc@methods$getDocInfoCreator, typeMap = typemap)
rotate = createCppMethod(doc@methods$getPageRotate, typeMap = typemap)

a = createRProxy(doc@methods$getDocInfoCreator, typeMap = typemap)
b = createRProxy(doc@methods$getPageRotate, typeMap = typemap)
}


k = lapply(e, readCppClass)

logicCFun = function(cvar, rvar, type, typeMap) { sprintf("%s = LOGICAL(%s)[0]", cvar, rvar)}
logicToR = function(cvar, rvar, type, typeMap){sprintf("ScalarLogical(%s)", rvar)}
longlongToR = function(cvar, rvar, type, typeMap){sprintf("ScalarReal(%s)", rvar)}
typemap = list("GooString *"= list(convertValueToR = "GooStringToR"),
               "long long" = list(convertValueToR = longlongToR, convertRValue = function(cvar, rvar, type, typeMap) sprintf("ScalarReal(%s)", cvar)),
               GBool = list(convertRValue = logicCFun, convertValueToR = logicToR),
               bool = list(convertRValue = logicCFun, convertValueToR = logicToR))

# Resolve GBool
# Goffset
# Are these typedef
#  in makeLocalVar():  getTypeKind(type) - typedef
#   getCanonicalType(type)
#

cpp = lapply(k$Page@methods, createCppMethod, typeMap = typemap)
cpp.doc = lapply(k$PDFDoc@methods, createCppMethod, typeMap = typemap)


}

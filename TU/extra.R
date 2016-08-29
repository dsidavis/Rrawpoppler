if(FALSE) {
    # These are specific
doc = readCppClass(e[["PDFDoc"]])
names(doc@methods)

code = createCppMethod(doc@methods$getDocInfoCreator, typeMap = typemap)
rotate = createCppMethod(doc@methods$getPageRotate, typeMap = typemap)

a = createRProxy(doc@methods$getDocInfoCreator, typeMap = typemap)
b = createRProxy(doc@methods$getPageRotate, typeMap = typemap)
}


if(FALSE) {
cpp.page = lapply(getPublic(k$Page@methods), createCppMethod, typeMap = typemap)
cpp.doc = lapply(getPublic(k$PDFDoc@methods), createCppMethod, typeMap = typemap)
cpp.state = lapply(getPublic(k$GfxState@methods), createCppMethod, typeMap = typemap)
cpp.obj = lapply(getPublic(k$Object@methods), createCppMethod, typeMap = typemap)
}


if(FALSE) {
cpp.obj = genClassCode(k$Object, typemap)
cppCodeToFile(cpp.obj, "../src/RObject.cc")


cpp.doc = genClassCode(k$PDFDoc, typemap, c("displayPage", "displayPages", "displayPageSlice"))
cppCodeToFile(cpp.doc, "../src/RPDFDoc.cc")

cpp.state = genClassCode(k$GfxState, typemap)
cppCodeToFile(cpp.state, "../src/RGfxState.cc")
}

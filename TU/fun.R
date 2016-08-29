# This script actually generates the code
if(!exists("k"))
  source("makeClasses.R")


#source("fun.R")
#tu = createTU("/usr/local/include/poppler/PDFDoc.h", includes = c("/usr/local/include/poppler", "/usr/local/include"), args = "-xc++")


# Resolve GBool
# Goffset
# Are these typedef
#  in makeLocalVar():  getTypeKind(type) - typedef
#   getCanonicalType(type)
#

# Generate code for Page, PDFDoc,
# OutputDev we do in genOutputDev.R so ignore here.

# This explicitly specifies how to deal with several types. We could resolve the typedefs for GBool
#
# [Done] Deal with passing an R string as GooString. See Todo.xml in (strangely) RCodeGen.
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



# Generate the C++ code for the following classes
ids = c("PDFDoc", "Object", "GfxState", "Catalog", "Dict", "GfxColorSpace", "GfxPath", "GfxSubpath", "Page", "PDFRectangle", "XRef", "PageAttrs")
code = lapply(ids, function(x) genClassCode(k[[x]], typemap, c("display", "displayPage", "displayPages", "displayPageSlice", "displaySlice", "getSignatureWidgets", "createGfx"), "get(RGB|RGBX|CMYK|DeviceN|Gray)Line"))
names(code) = ids
invisible(mapply(cppCodeToFile, code, sprintf("../src/R%s.cc", ids)))

# Now generate the corresponding R code

rcode = lapply(ids, function(x) genClassCode(k[[x]], typemap, c("displayPage", "displayPages", "displayPageSlice", "displaySlice", "getSignatureWidgets", "createGfx"), "get(RGB|RGBX|CMYK|DeviceN|Gray)Line", fun = createRProxy))
names(rcode) = ids

#XXX Temp. This method causes problems. Will fix.
rcode[["GfxColorSpace"]] = rcode[["GfxColorSpace"]][ !(names(rcode[["GfxColorSpace"]]) %in% c("getDisplayProfile", "setDisplayProfile")) ]

# Now generate the setGeneric() for the overloaded methods and then update the corresponding functions to be setMethod()
tmp = mkRGenericMethods(rcode) 
rcode = tmp$rcode
#Testing can parse/eval: envs = lapply(rcode, function(x) { e = new.env(); eval(parse(text = sapply(rcode, as, 'character')), e); e})
cat(tmp$generics, file = "../R/A_generics.R", sep = "\n\n")

invisible(mapply(function(code, file) cat(sapply(code, as, 'character'), sep = "\n\n", file = file), rcode, sprintf("../R/R_%s_auto.R", ids)))

# Make the class definitions
cat(unlist(mkClassDefs(k)), sep = "\n", file = "../R/A_classes.R")

# For the NAMESPACE - not putting them in there.
cat(paste(getClassNames(k), collapse = ",\n"))

# Names of the R functions we generated.
unlist(lapply(rcode, names)) 





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

source("typemap.R")


# Generate the C++ code for the following classes
ids = c("PDFDoc", "Object", "GfxState", "Catalog", "Dict", "GfxColorSpace", "GfxPath", "GfxSubpath", "Page", "PDFRectangle", "XRef", "PageAttrs", "GfxFont")

# temporary
 ids = ids[-length(ids)]

omitMethods = c("display", "displayPage", "displayPages", "displayPageSlice", "displaySlice", "getSignatureWidgets", "createGfx")
omitRX = "get(RGB|RGBX|CMYK|DeviceN|Gray)Line"


source("overloadedFuns.R")
generics = findOverloaded(k[ids], omitMethods, omitRX)


code = lapply(ids, function(x) genClassCode(k[[x]], typemap, omitMethods, omitRX))
names(code) = ids
invisible(mapply(cppCodeToFile, code, sprintf("../src/R%s.cc", ids)))

# Now generate the corresponding R code

rcode = lapply(ids, function(x) genClassCode(k[[x]], typemap, omitMethods, omitRX, fun = createRProxy, generics = generics))
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





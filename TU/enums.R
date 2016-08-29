enums = getEnums(tu)
enums = enums[grep("poppler", sapply(enums, getFileName))]

enums = enums[ !grepl("Activation", names(enums)) ]

cenums = lapply(enums, makeEnumDef)
renums = lapply(enums, makeEnumClass)

cat(sapply(cenums, function(x) paste(c(x[1:2], ";"), collapse = " ")), sep = "\n", file = "../src/R_auto_enums.h")
cat(c('#include "Rpoppler.h"', sapply(cenums, paste, collapse = "\n")), sep = "\n\n", file = "../src/R_auto_enums.cc")



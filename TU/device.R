library(RCIndex)

tu = createTU("device.cc", includes = c("/usr/local/include/", "/usr/local/include/poppler"))
source("readClasses.R")

g = gen()
visitTU(tu, g$visitor)
e = g$ans()
names(e) = sapply(e, getName)

dev = readCppClass(e$OutputDev)

names(dev@methods)

dev@methods = dev@methods[-1] # constructor

library(RCodeGen)
rcode = lapply(dev@methods, createRProxy)
# The rcode elements are RFunctionDefinition objects, not regular R functions at this point.

# return types
rt = lapply(dev@methods, function(x) x@returnType)

rcode = mapply(function(rfun, type) {
                 rfun@code = type
                 rfun
               },
                rcode, sprintf("'%s'", lapply(rt, getName)))

# Generate documentation for these methods.



m = dev@methods
m = m [ !(names(m) %in% c("checkPageSlice", "drawForm")) ]

m = lapply(m, fixParamNames)
             
source("typemap.R")

code = lapply(m, createMethod, className = "ROutputDev", typeMap = typemap, baseClassName = "OutputDev")
cat(unlist(sapply(code, `[[`, 1)), sep = "\n", file = "../src/ROutputDev_auto.cpp_code")

# Instead of this, generate the .h directly using
#cat(paste(sapply(code, `[[`, 2), ";"), sep = "\n", file = "../src/ROutputDev_auto.h")

cat(c(c('#include <poppler/PDFDoc.h>', '#include <poppler/OutputDev.h>', '#include "Rpoppler.h"'),
      defineRSubclass(dev, m)), sep = "\n", file = "../src/ROutputDev.h")






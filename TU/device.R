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



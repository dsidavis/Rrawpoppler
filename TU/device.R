library(RCIndex)

tu = createTU("device.cc", includes = c("/usr/local/include/", "/usr/local/include/poppler"))
source("readClasses.R")

g = gen()
visitTU(tu, g$visitor)
e = g$ans()
names(e) = sapply(e, getName)

dev = readCppClass(e$OutputDev)

names(dev@methods)

library(RCodeGen)




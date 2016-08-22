library(RCIndex)

tu = createTU("poppler.cc", includes = c("/usr/local/include/poppler", "/usr/local/include"))

k = getCppClasses(tu)
names(k)

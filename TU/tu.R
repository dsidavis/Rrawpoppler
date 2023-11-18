library(RCIndex)

tu = createTU("poppler.cc", includes = c("/usr/local/include/poppler", "/usr/local/include"))

k = getCppClasses(tu, "/poppler/", nodesOnly = TRUE)
k = getCppClasses(tu, "/poppler/")
#k = getCppClasses(tu)
names(k)



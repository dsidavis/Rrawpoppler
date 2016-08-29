library(RCIndex)
library(RCodeGen)
source("readClasses.R")

tu = createTU("poppler.cc", includes = c("/usr/local/include/poppler", "/usr/local/include"), args = "-xc++")
g = gen()
visitTU(tu, g$visitor)
e = g$ans()
# We pick up simple forward declarations such as class PDFDoc;  so discard those.
e = e[ sapply(e, function(x) length(children(x))) > 0]
names(e) = sapply(e, getName)



# Convert the actual class definitions into R objects
k = lapply(e, readCppClass)

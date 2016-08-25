
#
# Can use RMethodDefinition object. But have to create this first.
#
# In our case, there are no overloadings within a class!
# This means we can dispatch entirely on the first argument.
#
summary(sapply(k, function(x) sum(duplicated(names(x@methods)))))
#

# We'll work from the actual rcode objects generated since we omit some methods
tt = sort(table(unlist(lapply(rcode, names))))
overloadIds = names(tt[tt > 1])

names(rcode) = ids

# Consider isOk()
#
w = sapply(rcode, function(x) "isOk" %in% names(x))
# So in ids[w]
# "PDFDoc"  "Catalog" "Page"    "XRef"   

defs = sapply(rcode[w], `[[`, "isOk")

# So we can create a new generic function
generic = 'setGeneric("isOk", function(this, ...) standardGeneric("isOk"))'

# Then we change the 4 functions to be methods
#
methods = mapply(function(fun, className)  {  m = as(fun, "RMethodDefinition"); m@dispatchSignature = className ; m}, defs, names(defs))


# The next step is to put these back into the relevant rcode objects

rcode[w] = mapply(function(code, method) {  code[["isOk"]] = method ; code}, rcode[w], methods)
 





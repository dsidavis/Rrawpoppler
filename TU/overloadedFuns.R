findOverloaded =
function(classDefs, omit = character(), omitRX = character())
{
    methods = lapply(classDefs, slot, "methods")
    amethods = unlist(methods, recursive = FALSE)
    names(amethods) = sapply(amethods, getName)

    if(length(omit))
         amethods = amethods[ !(names(amethods) %in% omit) ]

    if(length(omitRX))
         amethods = amethods[ !grepl(omitRX, names(amethods)) ]
    

     tt = table(names(amethods))
     over = names(tt)[tt > 1]

     tmp = amethods[names(amethods) %in% over]
     byName = split(tmp, names(tmp))

     mapply(makeGeneric, byName, names(byName))

# Now call mkRGenericMethods. But we don't have the R-functions here, just the 
}


makeGeneric =
function(funs, fname)
{
    numArgs = sapply(funs, function(x) length(x@params))
    p = funs[[  which.max(numArgs)[1] ]]@params


    g = function() standardGeneric("name") 
    v = replicate(length(p)+1, alist(x=))
    names(v) =  c("this", names(p))
    formals(g) = v
    body(g)[[2]] = fname
    
    g
      
}

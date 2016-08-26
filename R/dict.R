setMethod("[[", c("Dict", "character"),
           function(x, i, j, ...)#, recursion = FALSE)
            {
               o = Object()
               lookup(x, i, o, recursion)
               o
           })

setMethod("[", c("Dict", "character"),
           function(x, i, j, ...)#, recursion = FALSE)
           {
               lapply(i, function(x) x[[i, recursion = recursion]])
           })

DictToR =
function(dict)
{
    n = getLength(dict)
    ans = sapply(seq(1, length = n),
           function(i) {
              o = Object()
              getVal(dict, i, o) #XXX ?? Object as the third arg.
              o
           })
    names(ans) = names(dict)
}

setMethod("names", "Dict",
          function(x) {
              n = getLength(x)
              sapply(seq(0, length = n),
                         function(i) 
                            getKey(x, i) #XXX ?? Object as the third arg.
                    )
          })

          

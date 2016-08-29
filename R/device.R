setGeneric("setMethods",     # very close to S4 setMethod()
           function(x, methods, ...)
               standardGeneric("setMethods"))

setMethod("setMethods", "ROutputDev",
          function(x, methods, protect = TRUE, ...) {
              .Call("R_ROutputDev_setFunctions", x, methods, as.logical(protect))
          })


setGeneric("getMethods",
            function(x, ...)
              standardGeneric("getMethods"))

setMethod("getMethods", "ROutputDev",
            function(x, ...)
               .Call("R_ROutputDev_getFunctions", x))
    



ROutputDev = ROutputDevice =
function(..., .funs = list(...))
{
    if(length(.funs) == 1  && is.list(.funs[[1]]) && all(sapply(.funs[[1]], is.function)))
        .funs = .funs[[1]]
    
    funs = ROutputFunctions(.funs = .funs)
    .Call("R_ROutputDev_new", funs)
}

DefaultDeviceFunctions =
    list(upsideDown = function(){ message("in upsideDown") ;  TRUE},
         useDrawChar = function() TRUE,
         interpretType3Chars = function() FALSE)


ROutputFunctions =
function(..., .funs = list(...), defaults = DefaultDeviceFunctions)
{
 #XXX Check the names.    
   defaults[names(.funs)] = .funs
   defaults
}





setGeneric("setMethods",     # very close to S4 setMethod()
           function(x, methods, ...)
               standardGeneric("setMethods"))

setGeneric("getMethods",
            function(x, ...)
              standardGeneric("getMethods"))


setMethod("setMethods", "ROutputDev",
          function(x, methods, protect = TRUE, ...) {
              .Call("R_ROutputDev_setFunctions", x, methods, as.logical(protect))
#              .Call("R_RFunctionsNativeMethods_setFunctions", x, methods, as.logical(protect))              
          })


setMethod("getMethods", "ROutputDev",
            function(x, ...)
               .Call("R_ROutputDev_getFunctions", x)
#               .Call("R_RFunctionsNativeMethods_getFunctions", x)          
          )
    



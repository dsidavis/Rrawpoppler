library(Rrawpoppler)

devFuns =
function()
{    
    list(upsideDown = function(){ message("in upsideDown") ;  TRUE},
         useDrawChar = function() { message("useDrawChar"); TRUE},
         interpretType3Chars = function() { message("interpretType3Chars"); FALSE},
         startPage = function(num, state, xref) { message(paste("startPage", num)) },
         endPage = function() {  message("endPage") }         
        )
}

D = devFuns()
# Generate the ROutputDev instance, passing it the list of functions to implement the methods
dev = ROutputDev(.funs = D)

ofuns = getMethods(dev)
# Page has a print() method that we don't want to use.
base::print(names(ofuns))

doc = pdfDoc(system.file("samples", "map.pdf", package = "Rrawpoppler"))
displayPages(doc, dev, 1)

ofuns$drawString = function(state, str) cat("drawString:", str, "\n")
ofuns$beginString = function(state, str) { message(paste("begin string ", str)); }
base::print(names(ofuns))

setMethods(dev, ofuns)

nfuns = getMethods(dev)
base::print(names(nfuns))

displayPages(doc, dev, 1)


rm(dev)
gc()
gc()

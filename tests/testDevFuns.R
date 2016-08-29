library(Rrawpoppler)

dev =
function()
{    
    list(upsideDown = function(){ message("in upsideDown") ;  TRUE},
         useDrawChar = function() { message("useDrawChar"); TRUE},
         interpretType3Chars = function() { message("interpretType3Chars"); FALSE},
         startPage = function(num, state, xref) { message(paste("startPage", num)) },
         endPage = function() {  message("endPage") }         
        )
}

D = dev()
# Generate the ROutputDev instance, passing it the list of functions to implement the methods
dev = ROutputDev(.funs = D)

ofuns = getMethods(dev)
doc = pdfDoc(system.file("samples", "map.pdf", package = "Rrawpoppler"))
displayPages(doc, dev, 1)

ofuns$drawString = function(state, str) cat("drawString:", str, "\n")

setMethods(dev, ofuns)

nfuns = getMethods(dev)

displayPages(doc, dev, 1)



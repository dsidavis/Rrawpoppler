library(Rpoppler)

dev =
function()
{
    txt = character()
    list(upsideDown = function(){ message("in upsideDown") ;  TRUE},
         useDrawChar = function() TRUE,
         interpretType3Chars = function() FALSE,
         startPage = function(num, state, xref) { message(paste("startPage", num)) },
         endPage = function() {  message("endPage") },
         beginString = function(state, str) {
             txt <<- c(txt, str)
         },
         text = function() txt
        )
}


d = dev()
dev = ROutputDevice(.funs = d)
f = system.file("samples", "map.pdf", package = "Rpoppler")
displayPages(f, dev)

text = d$text()


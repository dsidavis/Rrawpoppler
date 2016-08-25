library(Rpoppler)

dev =
function()
{    
    list(upsideDown = function(){ message("in upsideDown") ;  TRUE},
         useDrawChar = function() TRUE,
         interpretType3Chars = function() FALSE,
         startPage = function(num, state, xref) { message(paste("startPage", num)) },
         endPage = function() {  message("endPage") },
         updateFillColor = function(state) { message("setting fill color") },
         beginStringOp = function(state) { message("begin string op") },
         beginString = function(state, str) { message(paste("begin string ", str)); browser() },
         drawString = function(state, str) { message(paste("draw string ", str)); browser()  },
         endString = function(state) { message(paste("end string ")) },
         updateLineWidth = function(state) message("updateLineWidth"),
         updateLineCap = function(state) message("updateLineWidth"),
         updateLineDash = function(state) message("updateLineDash"),                  
         dump = function() message("dump"),
         beginActualText = function(state, str) message("beginActualText"),
         endActualText = function(state) message("endActualText"),
         updateFont = function(state) message("updateFont"),
         eoFill = function(state) message("eoFill"),
         fill = function(state) message("fill")
        )
}


dev = ROutputDevice(.funs = dev())
f = system.file("samples", "map.pdf", package = "Rpoppler")
displayPages(f, dev)



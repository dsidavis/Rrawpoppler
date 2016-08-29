library(Rrawpoppler)

devFuns =
function(withThis = TRUE)
{

  funs =  list(upsideDown = function(this){ message("in upsideDown") ;  TRUE},
         useDrawChar = function(this) TRUE,
         interpretType3Chars = function(this) FALSE,
         startPage = function(this, num, state, xref) { message(paste("startPage", num)) },
         endPage = function(this) {  message("endPage") },
         updateFillColor = function(this, state) { message("setting fill color") },
         beginStringOp = function(this,state) { message("begin string op") },
         beginString = function(this, state, str) { message(paste("begin string ", str)); },
         drawString = function(this, state, str) { message(paste("draw string ", str));  },
         endString = function(this, state) { message(paste("end string ")) },
         updateLineWidth = function(this, state) message("updateLineWidth"),
         updateLineCap = function(this, state) message("updateLineWidth"),
         updateLineDash = function(this, state) message("updateLineDash"),                  
         dump = function(this) message("dump"),
         beginActualText = function(this, state, str) message("beginActualText"),
         endActualText = function(this, state) message("endActualText"),
         updateFont = function(this, state) message("updateFont"),
         eoFill = function(this, state) message("eoFill"),
         fill = function(this, state) message("fill")
        )

   if(!withThis) {
       lapply(funs, removeThis)
   else
       funs
}


dev = ROutputDevice(devFuns())
f = system.file("samples", "map.pdf", package = "Rrawpoppler")
displayPages(f, dev)

rm(dev)
gc()
gc()





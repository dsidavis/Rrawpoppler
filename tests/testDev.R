library(Rpoppler)

dev =
function()
{    
    list(upsideDown = function(){ message("in upsideDown") ;  TRUE},
         useDrawChar = function() TRUE,
         interpretType3Chars = function() FALSE,
         startPage = function(num, state, xref) { message(paste("startPage", num)) },
         endPage = function() {  message("endPage") },
         updateFillColor = function(state) { message("setting color") },
         beginStringOp = function(state) { message("begin string op") },
         beginString = function(state, str) { message(paste("begin string ", str)) },
         drawString = function(state, str) { message(paste("draw string ", str)) },
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


# Generate the list of functions
D = dev()
# Generate the ROutputDev instance, passing it the list of functions to implement the methods
dev = .Call("R_ROutputDev_new", D)

# Create a PDFDoc with a PDF file
doc = pdfDoc(system.file("samples", "map.pdf", package = "Rpoppler"))

# Process one page
invisible()

# Process 3 pages
invisible(.Call("R_PDFDoc_displayPage", doc, dev, c(1L, 3L), c(300, 300), 0L, TRUE, FALSE, FALSE))


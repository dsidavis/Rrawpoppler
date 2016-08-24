
displayPages =
function(doc, dev = ROutputDevice(doc), pageNum = seq(1, getNumPages(doc)), dpi = c(600, 600), rotate = 0, useMediaBox = FALSE, crop = FALSE, printing = FALSE)
{

  if(is.character(doc))
     doc = pdfDoc(doc)
    
  dpi = as.numeric(dpi)
  if(length(dpi) < 2)
      dpi = rep(dpi, 2)
  
  .Call("R_PDFDoc_displayPage", as(doc, "PDFDoc"), dev, as.integer(pageNum), dpi,
                                as.numeric(rotate), as.logical(useMediaBox), as.logical(crop), as.logical(printing))
}
    
ROutputDevice =
function(..., .funs = list(...))
{
    funs = ROutputFunctions(.funs)
    .Call("R_ROutputDev_new", funs)
}

DefaultDeviceFunctions =
    list(upsideDown = function(){ message("in upsideDown") ;  TRUE},
         useDrawChar = function() TRUE,
         interpretType3Chars = function() FALSE)


ROutputFunctions =
function(..., .funs = list(...), defaults = DefaultDeviceFunctions)
{
   defaults[names(funs)] = .funs
   defaults
}



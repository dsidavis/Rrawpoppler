
displayPages =
function(doc, dev = ROutputDevice(doc), pageNum = seq(1, getNumPages(doc)), dpi = c(600, 600), rotate = 0, useMediaBox = FALSE, crop = FALSE, printing = FALSE)
{
  dpi = as.numeric(dpi)
  if(length(dpi) < 2)
      dpi = rep(dpi, 2)
  
  .Call("R_PDFDoc_displayPage", as(doc, "PDFDoc"), dev, as.integer(pageNum), dpi,
                                as.numeric(rotate), as.logical(useMediaBox), as.logical(crop), as.logical(printing))
}
    
ROutputDevice =
function(..., funs = ROutputFunctions(...))
{

}

DefaultDeviceFunctions =
    list(upsideDown = function(){ message("in upsideDown") ;  TRUE},
         useDrawChar = function() TRUE,
         interpretType3Chars = function() FALSE)


ROutputFunctions =
function(..., defaults = DefaultDeviceFunctions)
{
   funs = list(...)
   defaults[names(funs)] = funs
   defaults
}



displayPages =
function(doc, dev = ROutputDevice(doc), pageNum = c(1, getNumPages(doc)), dpi = c(600, 600), rotate = 0, useMediaBox = FALSE, crop = FALSE, printing = FALSE)
{

  if(is.character(doc))
     doc = pdfDoc(doc)
    
  dpi = as.numeric(dpi)
  if(length(dpi) < 2)
      dpi = rep(dpi, 2)
  
  .Call("R_PDFDoc_displayPage", as(doc, "PDFDoc"), dev, as.integer(pageNum), dpi,
                                as.integer(rotate), as.logical(useMediaBox), as.logical(crop), as.logical(printing))
}
    


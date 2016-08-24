pdfDoc =
function(file, password = NA)
{
  file = path.expand(as.character(file))
  if(!file.exists(file))
      stop("File needs to exist")
  
  .Call("R_PDFDoc_constructor", file, as.character(password))
}

getNumPages =
function(doc)
{
    .Call("R_PDFDoc_getNumPages", as(pdf, "PDFDoc"))
}


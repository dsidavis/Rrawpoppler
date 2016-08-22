pdfDoc =
function(file, password = NA)
{
  .Call("R_PDFDoc_constructor", as.character(file), as.character(password))
}

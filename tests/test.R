library(Rpoppler)
pdf = pdfDoc("~/DSIProjects/pdftohtml/examples/rplot.pdf")
.Call("R_PDFDoc_getNumPages", pdf)
.Call("R_PDFDoc_readMetadata", pdf)

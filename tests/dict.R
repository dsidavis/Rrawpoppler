library(Rrawpoppler)
doc = pdfDoc("inst/samples/plot.pdf")
p = doc[[1]]
d = getResourceDict(p)
o = Object()
z = getVal(d, 1, o)

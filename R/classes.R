setClass("PDFDoc", contains = "RC++Reference")

setClass("GfxState", contains = "RC++Reference")
setClass("GfxStatePtr", contains = "GfxState") # XXX Fix

setClass("XRef", contains = "RC++Reference")
setClass("XRefPtr", contains = "XRef") # XXX Fix


setClass("ROutputDev", contains = "RC++Reference")


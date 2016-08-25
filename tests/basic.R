library(Rpoppler)
doc = pdfDoc("inst/samples/map.pdf")
getFileName(doc)
isOk(doc) # conflicts with XRef, but okay now.

isEncrypted(doc)

#  Currently need the second argument. Will be able to use default.
okToPrint(doc, FALSE)
okToCopy(doc, FALSE)
okToAddNotes(doc, FALSE)

getNumPages(doc)
getErrorCode(doc)

isLinearized(doc, FALSE)
checkLinearization(doc)
getXRef(doc)

getPageRotate(doc, 1)

readMetadata(doc)

getPage(doc, 1)

getPDFMajorVersion(doc)
getPDFMinorVersion(doc)


getDocInfoCreator(doc)
getDocInfoCreatDate(doc)
getDocInfoProducer(doc)

savePageAs(doc, "/tmp/p1.pdf", 1)


p = getPage(doc, 1)
isOk(p)

getNum(p)
getRotate(p)

getMediaWidth(p)
getMediaHeight(p)
getLastModified(p)


dd = getDoc(p)
identical(dd, doc) # Not identical. Probably in the tag in the external poiner. XXX

dict = getResourceDict(p)

getLength(dict) # 3

getKey(dict, 1) # XObject

hasKey(dict, "XObject")
hasKey(dict, "XObjectx")

getDuration(p) # -1


# Page::processLinks  with an OutputDev.

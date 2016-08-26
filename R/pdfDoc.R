pdfDoc =
function(file, password = NA)
{
  file = path.expand(as.character(file))
  if(!file.exists(file))
      stop("File needs to exist")
  
  .Call("R_PDFDoc_constructor", file, as.character(password))
}


setMethod("[[", "PDFDoc",
          function(x, i, j, ...) {
             n =  getNumPages(x)
             if(i < 1 || i > n)
                stop("page number must be between 1 and ", n)

             getPage(x, i)
          })

setMethod("[", "PDFDoc",
          function(x, i, j, ...) {
             n =  getNumPages(x)
             if(any(i < 1 | i > n))
                stop("page number must be between 1 and ", n)

             lapply(i, function(num) getPage(x, num))
          })

setMethod("lapply", "PDFDoc",
           function(X, FUN, ...) {

             lapply(seq(1, length = getNumPages(X)),
                          function(i)
                             FUN(getPage(X, i), ...))
           })

setMethod("sapply", "PDFDoc",
           function(X, FUN, ..., simplify = TRUE, USE.NAMES = TRUE) {

             sapply(seq(1, length = getNumPages(X)),
                          function(i)
                             FUN(getPage(X, i), ...), simplify = simplify, USE.NAMES = USE.NAMES)
           })


pdf_info =
function(doc)
{
    if(is.character(doc))
       doc = pdfDoc(doc)

    structure(
        list( pdfVersion = c(major = getPDFMajorVersion(doc), minor = getPDFMinorVersion(doc)),
             page = getNumPages(doc),
             encrypted = isEncrypted(doc),
             linearized = isLinearized(doc),
             rotate = sapply(doc, getRotate),
             author = getDocInfoAuthor(doc),                          
             title = getDocInfoTitle(doc),             
             creator = getDocInfoCreator(doc),
             createDate = convertDate(getDocInfoCreatDate(doc)),
             producer = getDocInfoProducer(doc),
             canPrint = okToPrint(doc),
             canCopy = okToCopy(doc)
            ), class = "PDFInfo")
         
}

convertDate =
function(str)
{
   strptime(substring(str, 3), "%Y%m%d%H%M%S")
}

docName = getFileName

splitPages =
    #
    # Separate each of the specified pages into a separate file.
    # This can be helpful, for example, when we want to convert them then to images
    # for Optical Character Recognition.
    #
function(doc, pages = seq(1, length = getNumPages(doc)),
         files = sprintf("%s_p%d.pdf", gsub("\\.pdf$", "", getFileName(doc)), seq(1, length = getNumPages(doc))))
{
  mapply(function(page, file)
           savePageAs(doc, page, file),
         files)
}
   

#getNumPages =
#function(doc)
#    .Call("R_PDFDoc_getNumPages", as(doc, "PDFDoc"))



Object =
function()
{
    .Call("R_Object_new")
}

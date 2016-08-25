ErrorPDFDoc <-
function( errorCode, fileNameA )
{
    .Call('R_PDFDoc_ErrorPDFDoc', as(errorCode, 'integer'), as(fileNameA, 'GooStringOrCharacter'))
}

setMethod( 'isOk' , c( 'PDFDoc' ),       
function( this )
{
    .Call('R_PDFDoc_isOk', as(this, 'PDFDoc'))
} )


setMethod( 'getErrorCode' , c( 'PDFDoc' ),       
function( this )
{
    .Call('R_PDFDoc_getErrorCode', as(this, 'PDFDoc'))
} )


getFopenErrno <-
function( this )
{
    .Call('R_PDFDoc_getFopenErrno', as(this, 'PDFDoc'))
}

getFileName <-
function( this )
{
    .Call('R_PDFDoc_getFileName', as(this, 'PDFDoc'))
}

getLinearization <-
function( this )
{
    .Call('R_PDFDoc_getLinearization', as(this, 'PDFDoc'))
}

checkLinearization <-
function( this )
{
    .Call('R_PDFDoc_checkLinearization', as(this, 'PDFDoc'))
}

setMethod( 'getXRef' , c( 'PDFDoc' ),       
function( this )
{
    .Call('R_PDFDoc_getXRef', as(this, 'PDFDoc'))
} )


setMethod( 'getCatalog' , c( 'PDFDoc' ),       
function( this )
{
    .Call('R_PDFDoc_getCatalog', as(this, 'PDFDoc'))
} )


setMethod( 'getOptContentConfig' , c( 'PDFDoc' ),       
function( this )
{
    .Call('R_PDFDoc_getOptContentConfig', as(this, 'PDFDoc'))
} )


getBaseStream <-
function( this )
{
    .Call('R_PDFDoc_getBaseStream', as(this, 'PDFDoc'))
}

getPageMediaWidth <-
function( this, page )
{
    .Call('R_PDFDoc_getPageMediaWidth', as(this, 'PDFDoc'), as(page, 'integer'))
}

getPageMediaHeight <-
function( this, page )
{
    .Call('R_PDFDoc_getPageMediaHeight', as(this, 'PDFDoc'), as(page, 'integer'))
}

getPageCropWidth <-
function( this, page )
{
    .Call('R_PDFDoc_getPageCropWidth', as(this, 'PDFDoc'), as(page, 'integer'))
}

getPageCropHeight <-
function( this, page )
{
    .Call('R_PDFDoc_getPageCropHeight', as(this, 'PDFDoc'), as(page, 'integer'))
}

getPageRotate <-
function( this, page )
{
    .Call('R_PDFDoc_getPageRotate', as(this, 'PDFDoc'), as(page, 'integer'))
}

setMethod( 'getNumPages' , c( 'PDFDoc' ),       
function( this )
{
    .Call('R_PDFDoc_getNumPages', as(this, 'PDFDoc'))
} )


setMethod( 'readMetadata' , c( 'PDFDoc' ),       
function( this )
{
    .Call('R_PDFDoc_readMetadata', as(this, 'PDFDoc'))
} )


setMethod( 'getStructTreeRoot' , c( 'PDFDoc' ),       
function( this )
{
    .Call('R_PDFDoc_getStructTreeRoot', as(this, 'PDFDoc'))
} )


setMethod( 'getPage' , c( 'PDFDoc' ),       
function( this, page )
{
    .Call('R_PDFDoc_getPage', as(this, 'PDFDoc'), as(page, 'integer'))
} )


setMethod( 'findPage' , c( 'PDFDoc' ),       
function( this, num, gen )
{
    .Call('R_PDFDoc_findPage', as(this, 'PDFDoc'), as(num, 'integer'), as(gen, 'integer'))
} )


setMethod( 'getLinks' , c( 'PDFDoc' ),       
function( this, page )
{
    .Call('R_PDFDoc_getLinks', as(this, 'PDFDoc'), as(page, 'integer'))
} )


setMethod( 'findDest' , c( 'PDFDoc' ),       
function( this, name )
{
    .Call('R_PDFDoc_findDest', as(this, 'PDFDoc'), as(name, 'GooStringOrCharacter'))
} )


setMethod( 'processLinks' , c( 'PDFDoc' ),       
function( this, out, page )
{
    .Call('R_PDFDoc_processLinks', as(this, 'PDFDoc'), as(out, 'OutputDevPtr'), as(page, 'integer'))
} )


setMethod( 'getOutline' , c( 'PDFDoc' ),       
function( this )
{
    .Call('R_PDFDoc_getOutline', as(this, 'PDFDoc'))
} )


setMethod( 'isEncrypted' , c( 'PDFDoc' ),       
function( this )
{
    .Call('R_PDFDoc_isEncrypted', as(this, 'PDFDoc'))
} )


setMethod( 'okToPrint' , c( 'PDFDoc' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_PDFDoc_okToPrint', as(this, 'PDFDoc'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToPrintHighRes' , c( 'PDFDoc' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_PDFDoc_okToPrintHighRes', as(this, 'PDFDoc'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToChange' , c( 'PDFDoc' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_PDFDoc_okToChange', as(this, 'PDFDoc'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToCopy' , c( 'PDFDoc' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_PDFDoc_okToCopy', as(this, 'PDFDoc'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToAddNotes' , c( 'PDFDoc' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_PDFDoc_okToAddNotes', as(this, 'PDFDoc'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToFillForm' , c( 'PDFDoc' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_PDFDoc_okToFillForm', as(this, 'PDFDoc'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToAccessibility' , c( 'PDFDoc' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_PDFDoc_okToAccessibility', as(this, 'PDFDoc'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToAssemble' , c( 'PDFDoc' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_PDFDoc_okToAssemble', as(this, 'PDFDoc'), as(ignoreOwnerPW, 'GBool'))
} )


isLinearized <-
function( this, tryingToReconstruct = FALSE )
{
    .Call('R_PDFDoc_isLinearized', as(this, 'PDFDoc'), as(tryingToReconstruct, 'GBool'))
}

setMethod( 'getDocInfo' , c( 'PDFDoc' ),       
function( this, obj )
{
    .Call('R_PDFDoc_getDocInfo', as(this, 'PDFDoc'), as(obj, 'ObjectPtr'))
} )


setMethod( 'getDocInfoNF' , c( 'PDFDoc' ),       
function( this, obj )
{
    .Call('R_PDFDoc_getDocInfoNF', as(this, 'PDFDoc'), as(obj, 'ObjectPtr'))
} )


setMethod( 'createDocInfoIfNoneExists' , c( 'PDFDoc' ),       
function( this, obj )
{
    .Call('R_PDFDoc_createDocInfoIfNoneExists', as(this, 'PDFDoc'), as(obj, 'ObjectPtr'))
} )


setMethod( 'removeDocInfo' , c( 'PDFDoc' ),       
function( this )
{
    .Call('R_PDFDoc_removeDocInfo', as(this, 'PDFDoc'))
} )


setDocInfoStringEntry <-
function( this, key, value )
{
    .Call('R_PDFDoc_setDocInfoStringEntry', as(this, 'PDFDoc'), as(key, 'character'), as(value, 'GooStringOrCharacter'))
}

setDocInfoTitle <-
function( this, title )
{
    .Call('R_PDFDoc_setDocInfoTitle', as(this, 'PDFDoc'), as(title, 'GooStringOrCharacter'))
}

setDocInfoAuthor <-
function( this, author )
{
    .Call('R_PDFDoc_setDocInfoAuthor', as(this, 'PDFDoc'), as(author, 'GooStringOrCharacter'))
}

setDocInfoSubject <-
function( this, subject )
{
    .Call('R_PDFDoc_setDocInfoSubject', as(this, 'PDFDoc'), as(subject, 'GooStringOrCharacter'))
}

setDocInfoKeywords <-
function( this, keywords )
{
    .Call('R_PDFDoc_setDocInfoKeywords', as(this, 'PDFDoc'), as(keywords, 'GooStringOrCharacter'))
}

setDocInfoCreator <-
function( this, creator )
{
    .Call('R_PDFDoc_setDocInfoCreator', as(this, 'PDFDoc'), as(creator, 'GooStringOrCharacter'))
}

setDocInfoProducer <-
function( this, producer )
{
    .Call('R_PDFDoc_setDocInfoProducer', as(this, 'PDFDoc'), as(producer, 'GooStringOrCharacter'))
}

setDocInfoCreatDate <-
function( this, creatDate )
{
    .Call('R_PDFDoc_setDocInfoCreatDate', as(this, 'PDFDoc'), as(creatDate, 'GooStringOrCharacter'))
}

setDocInfoModDate <-
function( this, modDate )
{
    .Call('R_PDFDoc_setDocInfoModDate', as(this, 'PDFDoc'), as(modDate, 'GooStringOrCharacter'))
}

getDocInfoStringEntry <-
function( this, key )
{
    .Call('R_PDFDoc_getDocInfoStringEntry', as(this, 'PDFDoc'), as(key, 'character'))
}

getDocInfoTitle <-
function( this )
{
    .Call('R_PDFDoc_getDocInfoTitle', as(this, 'PDFDoc'))
}

getDocInfoAuthor <-
function( this )
{
    .Call('R_PDFDoc_getDocInfoAuthor', as(this, 'PDFDoc'))
}

getDocInfoSubject <-
function( this )
{
    .Call('R_PDFDoc_getDocInfoSubject', as(this, 'PDFDoc'))
}

getDocInfoKeywords <-
function( this )
{
    .Call('R_PDFDoc_getDocInfoKeywords', as(this, 'PDFDoc'))
}

getDocInfoCreator <-
function( this )
{
    .Call('R_PDFDoc_getDocInfoCreator', as(this, 'PDFDoc'))
}

getDocInfoProducer <-
function( this )
{
    .Call('R_PDFDoc_getDocInfoProducer', as(this, 'PDFDoc'))
}

getDocInfoCreatDate <-
function( this )
{
    .Call('R_PDFDoc_getDocInfoCreatDate', as(this, 'PDFDoc'))
}

getDocInfoModDate <-
function( this )
{
    .Call('R_PDFDoc_getDocInfoModDate', as(this, 'PDFDoc'))
}

getPDFMajorVersion <-
function( this )
{
    .Call('R_PDFDoc_getPDFMajorVersion', as(this, 'PDFDoc'))
}

getPDFMinorVersion <-
function( this )
{
    .Call('R_PDFDoc_getPDFMinorVersion', as(this, 'PDFDoc'))
}

getID <-
function( this, permanent_id, update_id )
{
    .Call('R_PDFDoc_getID', as(this, 'PDFDoc'), as(permanent_id, 'GooStringOrCharacter'), as(update_id, 'GooStringOrCharacter'))
}

savePageAs <-
function( this, name, pageNo )
{
    .Call('R_PDFDoc_savePageAs', as(this, 'PDFDoc'), as(name, 'GooStringOrCharacter'), as(pageNo, 'integer'))
}

saveAs <-
function( this, outStr, mode )
{
    .Call('R_PDFDoc_saveAs', as(this, 'PDFDoc'), as(outStr, 'OutStreamPtr'), as(mode, 'PDFWriteMode'))
}

saveWithoutChangesAs <-
function( this, outStr )
{
    .Call('R_PDFDoc_saveWithoutChangesAs', as(this, 'PDFDoc'), as(outStr, 'OutStreamPtr'))
}

getGUIData <-
function( this )
{
    .Call('R_PDFDoc_getGUIData', as(this, 'PDFDoc'))
}

replacePageDict <-
function( this, pageNo, rotate, mediaBox, cropBox )
{
    .Call('R_PDFDoc_replacePageDict', as(this, 'PDFDoc'), as(pageNo, 'integer'), as(rotate, 'integer'), as(mediaBox, 'PDFRectanglePtr'), as(cropBox, 'PDFRectanglePtr'))
}

markPageObjects <-
function( this, pageDict, xRef, countRef, numOffset, oldRefNum, newRefNum )
{
    .Call('R_PDFDoc_markPageObjects', as(this, 'PDFDoc'), as(pageDict, 'DictPtr'), as(xRef, 'XRefPtr'), as(countRef, 'XRefPtr'), as(numOffset, 'Guint'), as(oldRefNum, 'integer'), as(newRefNum, 'integer'))
}

markAnnotations <-
function( this, annots, xRef, countRef, numOffset, oldPageNum, newPageNum )
{
    .Call('R_PDFDoc_markAnnotations', as(this, 'PDFDoc'), as(annots, 'ObjectPtr'), as(xRef, 'XRefPtr'), as(countRef, 'XRefPtr'), as(numOffset, 'Guint'), as(oldPageNum, 'integer'), as(newPageNum, 'integer'))
}

markAcroForm <-
function( this, acrpForm, xRef, countRef, numOffset, oldPageNum, newPageNum )
{
    .Call('R_PDFDoc_markAcroForm', as(this, 'PDFDoc'), as(acrpForm, 'ObjectPtr'), as(xRef, 'XRefPtr'), as(countRef, 'XRefPtr'), as(numOffset, 'Guint'), as(oldPageNum, 'integer'), as(newPageNum, 'integer'))
}

writePageObjects <-
function( this, outStr, xRef, numOffset, combine = FALSE )
{
    .Call('R_PDFDoc_writePageObjects', as(this, 'PDFDoc'), as(outStr, 'OutStreamPtr'), as(xRef, 'XRefPtr'), as(numOffset, 'Guint'), as(combine, 'GBool'))
}

writeHeader <-
function( outStr, major, minor )
{
    .Call('R_PDFDoc_writeHeader', as(outStr, 'OutStreamPtr'), as(major, 'integer'), as(minor, 'integer'))
}

createTrailerDict <-
function( uxrefSize, incrUpdate, startxRef, root, xRef, fileName, fileSize )
{
    .Call('R_PDFDoc_createTrailerDict', as(uxrefSize, 'integer'), as(incrUpdate, 'GBool'), as(startxRef, 'Goffset'), as(root, 'RefPtr'), as(xRef, 'XRefPtr'), as(fileName, 'character'), as(fileSize, 'Goffset'))
}

writeXRefStreamTrailer <-
function( trailerDict, uxref, uxrefStreamRef, uxrefOffset, outStr, xRef )
{
    .Call('R_PDFDoc_writeXRefStreamTrailer', as(trailerDict, 'DictPtr'), as(uxref, 'XRefPtr'), as(uxrefStreamRef, 'RefPtr'), as(uxrefOffset, 'Goffset'), as(outStr, 'OutStreamPtr'), as(xRef, 'XRefPtr'))
}

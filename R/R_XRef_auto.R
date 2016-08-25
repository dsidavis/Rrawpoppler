setMethod( 'copy' , c( 'XRef' ),       
function( this )
{
    .Call('R_XRef_copy', as(this, 'XRef'))
} )


setMethod( 'isOk' , c( 'XRef' ),       
function( this )
{
    .Call('R_XRef_isOk', as(this, 'XRef'))
} )


isXRefStream <-
function( this )
{
    .Call('R_XRef_isXRefStream', as(this, 'XRef'))
}

setMethod( 'getErrorCode' , c( 'XRef' ),       
function( this )
{
    .Call('R_XRef_getErrorCode', as(this, 'XRef'))
} )


setEncryption <-
function( this, permFlagsA, ownerPasswordOkA, fileKeyA, keyLengthA, encVersionA, encRevisionA, encAlgorithmA )
{
    .Call('R_XRef_setEncryption', as(this, 'XRef'), as(permFlagsA, 'integer'), as(ownerPasswordOkA, 'GBool'), as(fileKeyA, 'GucharPtr'), as(keyLengthA, 'integer'), as(encVersionA, 'integer'), as(encRevisionA, 'integer'), as(encAlgorithmA, 'CryptAlgorithm'))
}

getEncryptionParameters <-
function( this, fileKeyA, encAlgorithmA, keyLengthA )
{
    .Call('R_XRef_getEncryptionParameters', as(this, 'XRef'), as(fileKeyA, 'GucharPtr'), as(encAlgorithmA, 'CryptAlgorithmPtr'), as(keyLengthA, 'integer'))
}

setMethod( 'isEncrypted' , c( 'XRef' ),       
function( this )
{
    .Call('R_XRef_isEncrypted', as(this, 'XRef'))
} )


setMethod( 'okToPrint' , c( 'XRef' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_XRef_okToPrint', as(this, 'XRef'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToPrintHighRes' , c( 'XRef' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_XRef_okToPrintHighRes', as(this, 'XRef'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToChange' , c( 'XRef' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_XRef_okToChange', as(this, 'XRef'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToCopy' , c( 'XRef' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_XRef_okToCopy', as(this, 'XRef'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToAddNotes' , c( 'XRef' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_XRef_okToAddNotes', as(this, 'XRef'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToFillForm' , c( 'XRef' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_XRef_okToFillForm', as(this, 'XRef'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToAccessibility' , c( 'XRef' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_XRef_okToAccessibility', as(this, 'XRef'), as(ignoreOwnerPW, 'GBool'))
} )


setMethod( 'okToAssemble' , c( 'XRef' ),       
function( this, ignoreOwnerPW = FALSE )
{
    .Call('R_XRef_okToAssemble', as(this, 'XRef'), as(ignoreOwnerPW, 'GBool'))
} )


getPermFlags <-
function( this )
{
    .Call('R_XRef_getPermFlags', as(this, 'XRef'))
}

setMethod( 'getCatalog' , c( 'XRef' ),       
function( this, obj )
{
    .Call('R_XRef_getCatalog', as(this, 'XRef'), as(obj, 'ObjectPtr'))
} )


setMethod( 'fetch' , c( 'XRef' ),       
function( this, num, gen, obj, recursion = 0 )
{
    .Call('R_XRef_fetch', as(this, 'XRef'), as(num, 'integer'), as(gen, 'integer'), as(obj, 'ObjectPtr'), as(recursion, 'integer'))
} )


setMethod( 'getDocInfo' , c( 'XRef' ),       
function( this, obj )
{
    .Call('R_XRef_getDocInfo', as(this, 'XRef'), as(obj, 'ObjectPtr'))
} )


setMethod( 'getDocInfoNF' , c( 'XRef' ),       
function( this, obj )
{
    .Call('R_XRef_getDocInfoNF', as(this, 'XRef'), as(obj, 'ObjectPtr'))
} )


setMethod( 'createDocInfoIfNoneExists' , c( 'XRef' ),       
function( this, obj )
{
    .Call('R_XRef_createDocInfoIfNoneExists', as(this, 'XRef'), as(obj, 'ObjectPtr'))
} )


setMethod( 'removeDocInfo' , c( 'XRef' ),       
function( this )
{
    .Call('R_XRef_removeDocInfo', as(this, 'XRef'))
} )


getNumObjects <-
function( this )
{
    .Call('R_XRef_getNumObjects', as(this, 'XRef'))
}

getRootNum <-
function( this )
{
    .Call('R_XRef_getRootNum', as(this, 'XRef'))
}

getRootGen <-
function( this )
{
    .Call('R_XRef_getRootGen', as(this, 'XRef'))
}

getStreamEnd <-
function( this, streamStart, streamEnd )
{
    .Call('R_XRef_getStreamEnd', as(this, 'XRef'), as(streamStart, 'Goffset'), as(streamEnd, 'GoffsetPtr'))
}

getNumEntry <-
function( this, offset )
{
    .Call('R_XRef_getNumEntry', as(this, 'XRef'), as(offset, 'Goffset'))
}

scanSpecialFlags <-
function( this )
{
    .Call('R_XRef_scanSpecialFlags', as(this, 'XRef'))
}

getEntry <-
function( this, i, complainIfMissing = TRUE )
{
    .Call('R_XRef_getEntry', as(this, 'XRef'), as(i, 'integer'), as(complainIfMissing, 'GBool'))
}

getTrailerDict <-
function( this )
{
    .Call('R_XRef_getTrailerDict', as(this, 'XRef'))
}

isModified <-
function( this )
{
    .Call('R_XRef_isModified', as(this, 'XRef'))
}

setModified <-
function( this )
{
    .Call('R_XRef_setModified', as(this, 'XRef'))
}

setModifiedObject <-
function( this, o, r )
{
    .Call('R_XRef_setModifiedObject', as(this, 'XRef'), as(o, 'ObjectPtr'), as(r, 'Ref'))
}

removeIndirectObject <-
function( this, r )
{
    .Call('R_XRef_removeIndirectObject', as(this, 'XRef'), as(r, 'Ref'))
}

setMethod( 'add' , c( 'XRef' ),       
function( this, num, gen, offs, used )
{
    .Call('R_XRef_add', as(this, 'XRef'), as(num, 'integer'), as(gen, 'integer'), as(offs, 'Goffset'), as(used, 'GBool'))
} )


writeTableToFile <-
function( this, outStr, writeAllEntries )
{
    .Call('R_XRef_writeTableToFile', as(this, 'XRef'), as(outStr, 'OutStreamPtr'), as(writeAllEntries, 'GBool'))
}

writeStreamToBuffer <-
function( this, stmBuf, xrefDict, xref )
{
    .Call('R_XRef_writeStreamToBuffer', as(this, 'XRef'), as(stmBuf, 'GooStringOrCharacter'), as(xrefDict, 'DictPtr'), as(xref, 'XRefPtr'))
}

lock <-
function( this )
{
    .Call('R_XRef_lock', as(this, 'XRef'))
}

unlock <-
function( this )
{
    .Call('R_XRef_unlock', as(this, 'XRef'))
}

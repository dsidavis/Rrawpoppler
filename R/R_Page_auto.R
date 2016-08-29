setMethod( 'isOk' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_isOk', as(this, 'Page'))
} )


setMethod( 'getNum' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getNum', as(this, 'Page'))
} )


setMethod( 'getMediaBox' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getMediaBox', as(this, 'Page'))
} )


setMethod( 'getCropBox' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getCropBox', as(this, 'Page'))
} )


setMethod( 'isCropped' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_isCropped', as(this, 'Page'))
} )


getMediaWidth <-
function( this )
{
    .Call('R_Page_getMediaWidth', as(this, 'Page'))
}

getMediaHeight <-
function( this )
{
    .Call('R_Page_getMediaHeight', as(this, 'Page'))
}

getCropWidth <-
function( this )
{
    .Call('R_Page_getCropWidth', as(this, 'Page'))
}

getCropHeight <-
function( this )
{
    .Call('R_Page_getCropHeight', as(this, 'Page'))
}

setMethod( 'getBleedBox' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getBleedBox', as(this, 'Page'))
} )


setMethod( 'getTrimBox' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getTrimBox', as(this, 'Page'))
} )


setMethod( 'getArtBox' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getArtBox', as(this, 'Page'))
} )


setMethod( 'getRotate' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getRotate', as(this, 'Page'))
} )


setMethod( 'getLastModified' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getLastModified', as(this, 'Page'))
} )


setMethod( 'getBoxColorInfo' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getBoxColorInfo', as(this, 'Page'))
} )


setMethod( 'getGroup' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getGroup', as(this, 'Page'))
} )


setMethod( 'getMetadata' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getMetadata', as(this, 'Page'))
} )


setMethod( 'getPieceInfo' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getPieceInfo', as(this, 'Page'))
} )


setMethod( 'getSeparationInfo' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getSeparationInfo', as(this, 'Page'))
} )


getDoc <-
function( this )
{
    .Call('R_Page_getDoc', as(this, 'Page'))
}

setMethod( 'getResourceDict' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getResourceDict', as(this, 'Page'))
} )


getResourceDictCopy <-
function( this, xrefA )
{
    .Call('R_Page_getResourceDictCopy', as(this, 'Page'), as(xrefA, 'XRefPtr'))
}

setMethod( 'getAnnots' , c( 'Page' ),       
function( this, obj, xrefA )
{
    .Call('R_Page_getAnnotsObject_Ptr_XRef_Ptr', as(this, 'Page'), as(obj, 'ObjectPtr'), as(xrefA, 'XRefPtr'))
} )


addAnnot <-
function( this, annot )
{
    .Call('R_Page_addAnnot', as(this, 'Page'), as(annot, 'AnnotPtr'))
}

removeAnnot <-
function( this, annot )
{
    .Call('R_Page_removeAnnot', as(this, 'Page'), as(annot, 'AnnotPtr'))
}

setMethod( 'getLinks' , c( 'Page' ),       
function( this )
{
    .Call('R_Page_getLinks', as(this, 'Page'))
} )


getAnnots <-
function( this, xrefA )
{
    .Call('R_Page_getAnnotsXRef_Ptr', as(this, 'Page'), as(xrefA, 'XRefPtr'))
}

getContents <-
function( this, obj )
{
    .Call('R_Page_getContents', as(this, 'Page'), as(obj, 'ObjectPtr'))
}

getThumb <-
function( this, obj )
{
    .Call('R_Page_getThumb', as(this, 'Page'), as(obj, 'ObjectPtr'))
}

loadThumb <-
function( this, data, width, height, rowstride )
{
    .Call('R_Page_loadThumb', as(this, 'Page'), as(data, 'unsigned charPtr'), as(width, 'integer'), as(height, 'integer'), as(rowstride, 'integer'))
}

getTrans <-
function( this, obj )
{
    .Call('R_Page_getTrans', as(this, 'Page'), as(obj, 'ObjectPtr'))
}

getFormWidgets <-
function( this )
{
    .Call('R_Page_getFormWidgets', as(this, 'Page'))
}

getDuration <-
function( this )
{
    .Call('R_Page_getDuration', as(this, 'Page'))
}

getActions <-
function( this, obj )
{
    .Call('R_Page_getActions', as(this, 'Page'), as(obj, 'ObjectPtr'))
}

setMethod( 'getAdditionalAction' , c( 'Page' ),       
function( this, type )
{
    .Call('R_Page_getAdditionalAction', as(this, 'Page'), as(type, 'Page::PageAdditionalActionsType'))
} )


setMethod( 'display' , c( 'Page' ),       
function( this, out, hDPI, vDPI, rotate, useMediaBox, crop, printing, abortCheckCbk, abortCheckCbkData, annotDisplayDecideCbk, annotDisplayDecideCbkData, copyXRef = FALSE )
{
    .Call('R_Page_displayOutputDev_Ptr_double_double_int_GBool_GBool_GBool_GBool_(Ptr)(void_Ptr)_void_Ptr_GBool_(Ptr)(Annot_Ptr,_void_Ptr)_void_Ptr_GBool', as(this, 'Page'), as(out, 'OutputDevPtr'), as(hDPI, 'numeric'), as(vDPI, 'numeric'), as(rotate, 'integer'), as(useMediaBox, 'GBool'), as(crop, 'GBool'), as(printing, 'GBool'), as(abortCheckCbk, 'GBool (void *)Ptr'), as(abortCheckCbkData, 'voidPtr'), as(annotDisplayDecideCbk, 'GBool (Annot *, void *)Ptr'), as(annotDisplayDecideCbkData, 'voidPtr'), as(copyXRef, 'GBool'))
} )


display <-
function( this, gfx )
{
    .Call('R_Page_displayGfx_Ptr', as(this, 'Page'), as(gfx, 'GfxPtr'))
}

makeBox <-
function( this, hDPI, vDPI, rotate, useMediaBox, upsideDown, sliceX, sliceY, sliceW, sliceH, box, crop )
{
    .Call('R_Page_makeBox', as(this, 'Page'), as(hDPI, 'numeric'), as(vDPI, 'numeric'), as(rotate, 'integer'), as(useMediaBox, 'GBool'), as(upsideDown, 'GBool'), as(sliceX, 'numeric'), as(sliceY, 'numeric'), as(sliceW, 'numeric'), as(sliceH, 'numeric'), as(box, 'PDFRectanglePtr'), as(crop, 'GBoolPtr'))
}

setMethod( 'processLinks' , c( 'Page' ),       
function( this, out )
{
    .Call('R_Page_processLinks', as(this, 'Page'), as(out, 'OutputDevPtr'))
} )


getDefaultCTM <-
function( this, ctm, hDPI, vDPI, rotate, useMediaBox, upsideDown )
{
    .Call('R_Page_getDefaultCTM', as(this, 'Page'), as(ctm, 'numeric'), as(hDPI, 'numeric'), as(vDPI, 'numeric'), as(rotate, 'integer'), as(useMediaBox, 'GBool'), as(upsideDown, 'GBool'))
}

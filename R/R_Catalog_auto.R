setMethod( 'isOk' , c( 'Catalog' ),       
function( this )
{
    .Call('R_Catalog_isOk', as(this, 'Catalog'))
} )


setMethod( 'getNumPages' , c( 'Catalog' ),       
function( this )
{
    .Call('R_Catalog_getNumPages', as(this, 'Catalog'))
} )


setMethod( 'getPage' , c( 'Catalog' ),       
function( this, i )
{
    .Call('R_Catalog_getPage', as(this, 'Catalog'), as(i, 'integer'))
} )


getPageRef <-
function( this, i )
{
    .Call('R_Catalog_getPageRef', as(this, 'Catalog'), as(i, 'integer'))
}

getBaseURI <-
function( this )
{
    .Call('R_Catalog_getBaseURI', as(this, 'Catalog'))
}

setMethod( 'readMetadata' , c( 'Catalog' ),       
function( this )
{
    .Call('R_Catalog_readMetadata', as(this, 'Catalog'))
} )


setMethod( 'getStructTreeRoot' , c( 'Catalog' ),       
function( this )
{
    .Call('R_Catalog_getStructTreeRoot', as(this, 'Catalog'))
} )


getMarkInfo <-
function( this )
{
    .Call('R_Catalog_getMarkInfo', as(this, 'Catalog'))
}

setMethod( 'findPage' , c( 'Catalog' ),       
function( this, num, gen )
{
    .Call('R_Catalog_findPage', as(this, 'Catalog'), as(num, 'integer'), as(gen, 'integer'))
} )


setMethod( 'findDest' , c( 'Catalog' ),       
function( this, name )
{
    .Call('R_Catalog_findDest', as(this, 'Catalog'), as(name, 'GooStringOrCharacter'))
} )


getDests <-
function( this )
{
    .Call('R_Catalog_getDests', as(this, 'Catalog'))
}

numEmbeddedFiles <-
function( this )
{
    .Call('R_Catalog_numEmbeddedFiles', as(this, 'Catalog'))
}

embeddedFile <-
function( this, i )
{
    .Call('R_Catalog_embeddedFile', as(this, 'Catalog'), as(i, 'integer'))
}

numJS <-
function( this )
{
    .Call('R_Catalog_numJS', as(this, 'Catalog'))
}

getJSName <-
function( this, i )
{
    .Call('R_Catalog_getJSName', as(this, 'Catalog'), as(i, 'integer'))
}

getJS <-
function( this, i )
{
    .Call('R_Catalog_getJS', as(this, 'Catalog'), as(i, 'integer'))
}

labelToIndex <-
function( this, label, index )
{
    .Call('R_Catalog_labelToIndex', as(this, 'Catalog'), as(label, 'GooStringOrCharacter'), as(index, 'integer'))
}

indexToLabel <-
function( this, index, label )
{
    .Call('R_Catalog_indexToLabel', as(this, 'Catalog'), as(index, 'integer'), as(label, 'GooStringOrCharacter'))
}

setMethod( 'getOutline' , c( 'Catalog' ),       
function( this )
{
    .Call('R_Catalog_getOutline', as(this, 'Catalog'))
} )


getAcroForm <-
function( this )
{
    .Call('R_Catalog_getAcroForm', as(this, 'Catalog'))
}

setMethod( 'getOptContentConfig' , c( 'Catalog' ),       
function( this )
{
    .Call('R_Catalog_getOptContentConfig', as(this, 'Catalog'))
} )


getForm <-
function( this )
{
    .Call('R_Catalog_getForm', as(this, 'Catalog'))
}

getViewerPreferences <-
function( this )
{
    .Call('R_Catalog_getViewerPreferences', as(this, 'Catalog'))
}

setMethod( 'getAdditionalAction' , c( 'Catalog' ),       
function( this, type )
{
    .Call('R_Catalog_getAdditionalAction', as(this, 'Catalog'), as(type, 'Catalog::DocumentAdditionalActionsType'))
} )


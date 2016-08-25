setMethod( 'getMediaBox' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getMediaBox', as(this, 'PageAttrs'))
} )


setMethod( 'getCropBox' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getCropBox', as(this, 'PageAttrs'))
} )


setMethod( 'isCropped' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_isCropped', as(this, 'PageAttrs'))
} )


setMethod( 'getBleedBox' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getBleedBox', as(this, 'PageAttrs'))
} )


setMethod( 'getTrimBox' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getTrimBox', as(this, 'PageAttrs'))
} )


setMethod( 'getArtBox' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getArtBox', as(this, 'PageAttrs'))
} )


setMethod( 'getRotate' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getRotate', as(this, 'PageAttrs'))
} )


setMethod( 'getLastModified' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getLastModified', as(this, 'PageAttrs'))
} )


setMethod( 'getBoxColorInfo' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getBoxColorInfo', as(this, 'PageAttrs'))
} )


setMethod( 'getGroup' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getGroup', as(this, 'PageAttrs'))
} )


setMethod( 'getMetadata' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getMetadata', as(this, 'PageAttrs'))
} )


setMethod( 'getPieceInfo' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getPieceInfo', as(this, 'PageAttrs'))
} )


setMethod( 'getSeparationInfo' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getSeparationInfo', as(this, 'PageAttrs'))
} )


setMethod( 'getResourceDict' , c( 'PageAttrs' ),       
function( this )
{
    .Call('R_PageAttrs_getResourceDict', as(this, 'PageAttrs'))
} )


replaceResource <-
function( this, obj1 )
{
    .Call('R_PageAttrs_replaceResource', as(this, 'PageAttrs'), as(obj1, 'Object'))
}

clipBoxes <-
function( this )
{
    .Call('R_PageAttrs_clipBoxes', as(this, 'PageAttrs'))
}

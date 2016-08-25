setMethod( 'copy' , c( 'GfxPath' ),       
function( this )
{
    .Call('R_GfxPath_copy', as(this, 'GfxPath'))
} )


setMethod( 'isCurPt' , c( 'GfxPath' ),       
function( this )
{
    .Call('R_GfxPath_isCurPt', as(this, 'GfxPath'))
} )


setMethod( 'isPath' , c( 'GfxPath' ),       
function( this )
{
    .Call('R_GfxPath_isPath', as(this, 'GfxPath'))
} )


getNumSubpaths <-
function( this )
{
    .Call('R_GfxPath_getNumSubpaths', as(this, 'GfxPath'))
}

getSubpath <-
function( this, i )
{
    .Call('R_GfxPath_getSubpath', as(this, 'GfxPath'), as(i, 'integer'))
}

setMethod( 'getLastX' , c( 'GfxPath' ),       
function( this )
{
    .Call('R_GfxPath_getLastX', as(this, 'GfxPath'))
} )


setMethod( 'getLastY' , c( 'GfxPath' ),       
function( this )
{
    .Call('R_GfxPath_getLastY', as(this, 'GfxPath'))
} )


setMethod( 'moveTo' , c( 'GfxPath' ),       
function( this, x, y )
{
    .Call('R_GfxPath_moveTo', as(this, 'GfxPath'), as(x, 'numeric'), as(y, 'numeric'))
} )


setMethod( 'lineTo' , c( 'GfxPath' ),       
function( this, x, y )
{
    .Call('R_GfxPath_lineTo', as(this, 'GfxPath'), as(x, 'numeric'), as(y, 'numeric'))
} )


setMethod( 'curveTo' , c( 'GfxPath' ),       
function( this, x1, y1, x2, y2, x3, y3 )
{
    .Call('R_GfxPath_curveTo', as(this, 'GfxPath'), as(x1, 'numeric'), as(y1, 'numeric'), as(x2, 'numeric'), as(y2, 'numeric'), as(x3, 'numeric'), as(y3, 'numeric'))
} )


setMethod( 'close' , c( 'GfxPath' ),       
function( this )
{
    .Call('R_GfxPath_close', as(this, 'GfxPath'))
} )


append <-
function( this, path )
{
    .Call('R_GfxPath_append', as(this, 'GfxPath'), as(path, 'GfxPathPtr'))
}

setMethod( 'offset' , c( 'GfxPath' ),       
function( this, dx, dy )
{
    .Call('R_GfxPath_offset', as(this, 'GfxPath'), as(dx, 'numeric'), as(dy, 'numeric'))
} )


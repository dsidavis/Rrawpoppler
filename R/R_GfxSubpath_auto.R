setMethod( 'copy' , c( 'GfxSubpath' ),       
function( this )
{
    .Call('R_GfxSubpath_copy', as(this, 'GfxSubpath'))
} )


getNumPoints <-
function( this )
{
    .Call('R_GfxSubpath_getNumPoints', as(this, 'GfxSubpath'))
}

getX <-
function( this, i )
{
    .Call('R_GfxSubpath_getX', as(this, 'GfxSubpath'), as(i, 'integer'))
}

getY <-
function( this, i )
{
    .Call('R_GfxSubpath_getY', as(this, 'GfxSubpath'), as(i, 'integer'))
}

getCurve <-
function( this, i )
{
    .Call('R_GfxSubpath_getCurve', as(this, 'GfxSubpath'), as(i, 'integer'))
}

setX <-
function( this, i, a )
{
    .Call('R_GfxSubpath_setX', as(this, 'GfxSubpath'), as(i, 'integer'), as(a, 'numeric'))
}

setY <-
function( this, i, a )
{
    .Call('R_GfxSubpath_setY', as(this, 'GfxSubpath'), as(i, 'integer'), as(a, 'numeric'))
}

setMethod( 'getLastX' , c( 'GfxSubpath' ),       
function( this )
{
    .Call('R_GfxSubpath_getLastX', as(this, 'GfxSubpath'))
} )


setMethod( 'getLastY' , c( 'GfxSubpath' ),       
function( this )
{
    .Call('R_GfxSubpath_getLastY', as(this, 'GfxSubpath'))
} )


setMethod( 'lineTo' , c( 'GfxSubpath' ),       
function( this, x1, y1 )
{
    .Call('R_GfxSubpath_lineTo', as(this, 'GfxSubpath'), as(x1, 'numeric'), as(y1, 'numeric'))
} )


setMethod( 'curveTo' , c( 'GfxSubpath' ),       
function( this, x1, y1, x2, y2, x3, y3 )
{
    .Call('R_GfxSubpath_curveTo', as(this, 'GfxSubpath'), as(x1, 'numeric'), as(y1, 'numeric'), as(x2, 'numeric'), as(y2, 'numeric'), as(x3, 'numeric'), as(y3, 'numeric'))
} )


setMethod( 'close' , c( 'GfxSubpath' ),       
function( this )
{
    .Call('R_GfxSubpath_close', as(this, 'GfxSubpath'))
} )


isClosed <-
function( this )
{
    .Call('R_GfxSubpath_isClosed', as(this, 'GfxSubpath'))
}

setMethod( 'offset' , c( 'GfxSubpath' ),       
function( this, dx, dy )
{
    .Call('R_GfxSubpath_offset', as(this, 'GfxSubpath'), as(dx, 'numeric'), as(dy, 'numeric'))
} )


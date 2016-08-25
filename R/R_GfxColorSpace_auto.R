setMethod( 'copy' , c( 'GfxColorSpace' ),       
function( this )
{
    .Call('R_GfxColorSpace_copy', as(this, 'GfxColorSpace'))
} )


parse <-
function( res, csObj, out, state, recursion )
{
    .Call('R_GfxColorSpace_parse', as(res, 'GfxResourcesPtr'), as(csObj, 'ObjectPtr'), as(out, 'OutputDevPtr'), as(state, 'GfxStatePtr'), as(recursion, 'integer'))
}

getGray <-
function( this, color, gray )
{
    .Call('R_GfxColorSpace_getGray', as(this, 'GfxColorSpace'), as(color, 'GfxColorPtr'), as(gray, 'GfxGrayPtr'))
}

getRGB <-
function( this, color, rgb )
{
    .Call('R_GfxColorSpace_getRGB', as(this, 'GfxColorSpace'), as(color, 'GfxColorPtr'), as(rgb, 'GfxRGBPtr'))
}

getCMYK <-
function( this, color, cmyk )
{
    .Call('R_GfxColorSpace_getCMYK', as(this, 'GfxColorSpace'), as(color, 'GfxColorPtr'), as(cmyk, 'GfxCMYKPtr'))
}

getDeviceN <-
function( this, color, deviceN )
{
    .Call('R_GfxColorSpace_getDeviceN', as(this, 'GfxColorSpace'), as(color, 'GfxColorPtr'), as(deviceN, 'GfxColorPtr'))
}

createMapping <-
function( this, separationList, maxSepComps )
{
    .Call('R_GfxColorSpace_createMapping', as(this, 'GfxColorSpace'), as(separationList, 'GooListPtr'), as(maxSepComps, 'integer'))
}

useGetRGBLine <-
function( this )
{
    .Call('R_GfxColorSpace_useGetRGBLine', as(this, 'GfxColorSpace'))
}

useGetGrayLine <-
function( this )
{
    .Call('R_GfxColorSpace_useGetGrayLine', as(this, 'GfxColorSpace'))
}

useGetCMYKLine <-
function( this )
{
    .Call('R_GfxColorSpace_useGetCMYKLine', as(this, 'GfxColorSpace'))
}

useGetDeviceNLine <-
function( this )
{
    .Call('R_GfxColorSpace_useGetDeviceNLine', as(this, 'GfxColorSpace'))
}

getNComps <-
function( this )
{
    .Call('R_GfxColorSpace_getNComps', as(this, 'GfxColorSpace'))
}

getDefaultColor <-
function( this, color )
{
    .Call('R_GfxColorSpace_getDefaultColor', as(this, 'GfxColorSpace'), as(color, 'GfxColorPtr'))
}

getDefaultRanges <-
function( this, decodeLow, decodeRange, maxImgPixel )
{
    .Call('R_GfxColorSpace_getDefaultRanges', as(this, 'GfxColorSpace'), as(decodeLow, 'numeric'), as(decodeRange, 'numeric'), as(maxImgPixel, 'integer'))
}

isNonMarking <-
function( this )
{
    .Call('R_GfxColorSpace_isNonMarking', as(this, 'GfxColorSpace'))
}

getOverprintMask <-
function( this )
{
    .Call('R_GfxColorSpace_getOverprintMask', as(this, 'GfxColorSpace'))
}

getNumColorSpaceModes <-
function(  )
{
    .Call('R_GfxColorSpace_getNumColorSpaceModes')
}

getColorSpaceModeName <-
function( idx )
{
    .Call('R_GfxColorSpace_getColorSpaceModeName', as(idx, 'integer'))
}

setupColorProfiles <-
function(  )
{
    .Call('R_GfxColorSpace_setupColorProfiles')
}

setDisplayProfileName <-
function( name )
{
    .Call('R_GfxColorSpace_setDisplayProfileName', as(name, 'GooStringOrCharacter'))
}

getRGBProfile <-
function(  )
{
    .Call('R_GfxColorSpace_getRGBProfile')
}

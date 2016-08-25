setMethod( 'copy' , c( 'GfxState' ),       
function( this, copyPath = FALSE )
{
    .Call('R_GfxState_copy', as(this, 'GfxState'), as(copyPath, 'GBool'))
} )


getHDPI <-
function( this )
{
    .Call('R_GfxState_getHDPI', as(this, 'GfxState'))
}

getVDPI <-
function( this )
{
    .Call('R_GfxState_getVDPI', as(this, 'GfxState'))
}

getCTM <-
function( this, m )
{
    .Call('R_GfxState_getCTM', as(this, 'GfxState'), as(m, 'MatrixPtr'))
}

getX1 <-
function( this )
{
    .Call('R_GfxState_getX1', as(this, 'GfxState'))
}

getY1 <-
function( this )
{
    .Call('R_GfxState_getY1', as(this, 'GfxState'))
}

getX2 <-
function( this )
{
    .Call('R_GfxState_getX2', as(this, 'GfxState'))
}

getY2 <-
function( this )
{
    .Call('R_GfxState_getY2', as(this, 'GfxState'))
}

getPageWidth <-
function( this )
{
    .Call('R_GfxState_getPageWidth', as(this, 'GfxState'))
}

getPageHeight <-
function( this )
{
    .Call('R_GfxState_getPageHeight', as(this, 'GfxState'))
}

setMethod( 'getRotate' , c( 'GfxState' ),       
function( this )
{
    .Call('R_GfxState_getRotate', as(this, 'GfxState'))
} )


getFillColor <-
function( this )
{
    .Call('R_GfxState_getFillColor', as(this, 'GfxState'))
}

getStrokeColor <-
function( this )
{
    .Call('R_GfxState_getStrokeColor', as(this, 'GfxState'))
}

getFillGray <-
function( this, gray )
{
    .Call('R_GfxState_getFillGray', as(this, 'GfxState'), as(gray, 'GfxGrayPtr'))
}

getStrokeGray <-
function( this, gray )
{
    .Call('R_GfxState_getStrokeGray', as(this, 'GfxState'), as(gray, 'GfxGrayPtr'))
}

getFillRGB <-
function( this, rgb )
{
    .Call('R_GfxState_getFillRGB', as(this, 'GfxState'), as(rgb, 'GfxRGBPtr'))
}

getStrokeRGB <-
function( this, rgb )
{
    .Call('R_GfxState_getStrokeRGB', as(this, 'GfxState'), as(rgb, 'GfxRGBPtr'))
}

getFillCMYK <-
function( this, cmyk )
{
    .Call('R_GfxState_getFillCMYK', as(this, 'GfxState'), as(cmyk, 'GfxCMYKPtr'))
}

getFillDeviceN <-
function( this, deviceN )
{
    .Call('R_GfxState_getFillDeviceN', as(this, 'GfxState'), as(deviceN, 'GfxColorPtr'))
}

getStrokeCMYK <-
function( this, cmyk )
{
    .Call('R_GfxState_getStrokeCMYK', as(this, 'GfxState'), as(cmyk, 'GfxCMYKPtr'))
}

getStrokeDeviceN <-
function( this, deviceN )
{
    .Call('R_GfxState_getStrokeDeviceN', as(this, 'GfxState'), as(deviceN, 'GfxColorPtr'))
}

getFillColorSpace <-
function( this )
{
    .Call('R_GfxState_getFillColorSpace', as(this, 'GfxState'))
}

getStrokeColorSpace <-
function( this )
{
    .Call('R_GfxState_getStrokeColorSpace', as(this, 'GfxState'))
}

getFillPattern <-
function( this )
{
    .Call('R_GfxState_getFillPattern', as(this, 'GfxState'))
}

getStrokePattern <-
function( this )
{
    .Call('R_GfxState_getStrokePattern', as(this, 'GfxState'))
}

getFillOpacity <-
function( this )
{
    .Call('R_GfxState_getFillOpacity', as(this, 'GfxState'))
}

getStrokeOpacity <-
function( this )
{
    .Call('R_GfxState_getStrokeOpacity', as(this, 'GfxState'))
}

getFillOverprint <-
function( this )
{
    .Call('R_GfxState_getFillOverprint', as(this, 'GfxState'))
}

getStrokeOverprint <-
function( this )
{
    .Call('R_GfxState_getStrokeOverprint', as(this, 'GfxState'))
}

getOverprintMode <-
function( this )
{
    .Call('R_GfxState_getOverprintMode', as(this, 'GfxState'))
}

getTransfer <-
function( this )
{
    .Call('R_GfxState_getTransfer', as(this, 'GfxState'))
}

getLineWidth <-
function( this )
{
    .Call('R_GfxState_getLineWidth', as(this, 'GfxState'))
}

getLineDash <-
function( this, dash, length, start )
{
    .Call('R_GfxState_getLineDash', as(this, 'GfxState'), as(dash, 'numeric'), as(length, 'integer'), as(start, 'numeric'))
}

getFlatness <-
function( this )
{
    .Call('R_GfxState_getFlatness', as(this, 'GfxState'))
}

getLineJoin <-
function( this )
{
    .Call('R_GfxState_getLineJoin', as(this, 'GfxState'))
}

getLineCap <-
function( this )
{
    .Call('R_GfxState_getLineCap', as(this, 'GfxState'))
}

getMiterLimit <-
function( this )
{
    .Call('R_GfxState_getMiterLimit', as(this, 'GfxState'))
}

getStrokeAdjust <-
function( this )
{
    .Call('R_GfxState_getStrokeAdjust', as(this, 'GfxState'))
}

getAlphaIsShape <-
function( this )
{
    .Call('R_GfxState_getAlphaIsShape', as(this, 'GfxState'))
}

getTextKnockout <-
function( this )
{
    .Call('R_GfxState_getTextKnockout', as(this, 'GfxState'))
}

getFont <-
function( this )
{
    .Call('R_GfxState_getFont', as(this, 'GfxState'))
}

getFontSize <-
function( this )
{
    .Call('R_GfxState_getFontSize', as(this, 'GfxState'))
}

getTextMat <-
function( this )
{
    .Call('R_GfxState_getTextMat', as(this, 'GfxState'))
}

getCharSpace <-
function( this )
{
    .Call('R_GfxState_getCharSpace', as(this, 'GfxState'))
}

getWordSpace <-
function( this )
{
    .Call('R_GfxState_getWordSpace', as(this, 'GfxState'))
}

getHorizScaling <-
function( this )
{
    .Call('R_GfxState_getHorizScaling', as(this, 'GfxState'))
}

getLeading <-
function( this )
{
    .Call('R_GfxState_getLeading', as(this, 'GfxState'))
}

getRise <-
function( this )
{
    .Call('R_GfxState_getRise', as(this, 'GfxState'))
}

getRender <-
function( this )
{
    .Call('R_GfxState_getRender', as(this, 'GfxState'))
}

getRenderingIntent <-
function( this )
{
    .Call('R_GfxState_getRenderingIntent', as(this, 'GfxState'))
}

getPath <-
function( this )
{
    .Call('R_GfxState_getPath', as(this, 'GfxState'))
}

setPath <-
function( this, pathA )
{
    .Call('R_GfxState_setPath', as(this, 'GfxState'), as(pathA, 'GfxPathPtr'))
}

getCurX <-
function( this )
{
    .Call('R_GfxState_getCurX', as(this, 'GfxState'))
}

getCurY <-
function( this )
{
    .Call('R_GfxState_getCurY', as(this, 'GfxState'))
}

getClipBBox <-
function( this, xMin, yMin, xMax, yMax )
{
    .Call('R_GfxState_getClipBBox', as(this, 'GfxState'), as(xMin, 'numeric'), as(yMin, 'numeric'), as(xMax, 'numeric'), as(yMax, 'numeric'))
}

getUserClipBBox <-
function( this, xMin, yMin, xMax, yMax )
{
    .Call('R_GfxState_getUserClipBBox', as(this, 'GfxState'), as(xMin, 'numeric'), as(yMin, 'numeric'), as(xMax, 'numeric'), as(yMax, 'numeric'))
}

getLineX <-
function( this )
{
    .Call('R_GfxState_getLineX', as(this, 'GfxState'))
}

getLineY <-
function( this )
{
    .Call('R_GfxState_getLineY', as(this, 'GfxState'))
}

setMethod( 'isCurPt' , c( 'GfxState' ),       
function( this )
{
    .Call('R_GfxState_isCurPt', as(this, 'GfxState'))
} )


setMethod( 'isPath' , c( 'GfxState' ),       
function( this )
{
    .Call('R_GfxState_isPath', as(this, 'GfxState'))
} )


transform <-
function( this, x1, y1, x2, y2 )
{
    .Call('R_GfxState_transform', as(this, 'GfxState'), as(x1, 'numeric'), as(y1, 'numeric'), as(x2, 'numeric'), as(y2, 'numeric'))
}

transformDelta <-
function( this, x1, y1, x2, y2 )
{
    .Call('R_GfxState_transformDelta', as(this, 'GfxState'), as(x1, 'numeric'), as(y1, 'numeric'), as(x2, 'numeric'), as(y2, 'numeric'))
}

textTransform <-
function( this, x1, y1, x2, y2 )
{
    .Call('R_GfxState_textTransform', as(this, 'GfxState'), as(x1, 'numeric'), as(y1, 'numeric'), as(x2, 'numeric'), as(y2, 'numeric'))
}

textTransformDelta <-
function( this, x1, y1, x2, y2 )
{
    .Call('R_GfxState_textTransformDelta', as(this, 'GfxState'), as(x1, 'numeric'), as(y1, 'numeric'), as(x2, 'numeric'), as(y2, 'numeric'))
}

transformWidth <-
function( this, w )
{
    .Call('R_GfxState_transformWidth', as(this, 'GfxState'), as(w, 'numeric'))
}

getTransformedLineWidth <-
function( this )
{
    .Call('R_GfxState_getTransformedLineWidth', as(this, 'GfxState'))
}

getTransformedFontSize <-
function( this )
{
    .Call('R_GfxState_getTransformedFontSize', as(this, 'GfxState'))
}

getFontTransMat <-
function( this, m11, m12, m21, m22 )
{
    .Call('R_GfxState_getFontTransMat', as(this, 'GfxState'), as(m11, 'numeric'), as(m12, 'numeric'), as(m21, 'numeric'), as(m22, 'numeric'))
}

setCTM <-
function( this, a, b, c, d, e, f )
{
    .Call('R_GfxState_setCTM', as(this, 'GfxState'), as(a, 'numeric'), as(b, 'numeric'), as(c, 'numeric'), as(d, 'numeric'), as(e, 'numeric'), as(f, 'numeric'))
}

concatCTM <-
function( this, a, b, c, d, e, f )
{
    .Call('R_GfxState_concatCTM', as(this, 'GfxState'), as(a, 'numeric'), as(b, 'numeric'), as(c, 'numeric'), as(d, 'numeric'), as(e, 'numeric'), as(f, 'numeric'))
}

shiftCTMAndClip <-
function( this, tx, ty )
{
    .Call('R_GfxState_shiftCTMAndClip', as(this, 'GfxState'), as(tx, 'numeric'), as(ty, 'numeric'))
}

setFillColorSpace <-
function( this, colorSpace )
{
    .Call('R_GfxState_setFillColorSpace', as(this, 'GfxState'), as(colorSpace, 'GfxColorSpacePtr'))
}

setStrokeColorSpace <-
function( this, colorSpace )
{
    .Call('R_GfxState_setStrokeColorSpace', as(this, 'GfxState'), as(colorSpace, 'GfxColorSpacePtr'))
}

setFillColor <-
function( this, color )
{
    .Call('R_GfxState_setFillColor', as(this, 'GfxState'), as(color, 'GfxColorPtr'))
}

setStrokeColor <-
function( this, color )
{
    .Call('R_GfxState_setStrokeColor', as(this, 'GfxState'), as(color, 'GfxColorPtr'))
}

setFillPattern <-
function( this, pattern )
{
    .Call('R_GfxState_setFillPattern', as(this, 'GfxState'), as(pattern, 'GfxPatternPtr'))
}

setStrokePattern <-
function( this, pattern )
{
    .Call('R_GfxState_setStrokePattern', as(this, 'GfxState'), as(pattern, 'GfxPatternPtr'))
}

setBlendMode <-
function( this, mode )
{
    .Call('R_GfxState_setBlendMode', as(this, 'GfxState'), as(mode, 'GfxBlendMode'))
}

setFillOpacity <-
function( this, opac )
{
    .Call('R_GfxState_setFillOpacity', as(this, 'GfxState'), as(opac, 'numeric'))
}

setStrokeOpacity <-
function( this, opac )
{
    .Call('R_GfxState_setStrokeOpacity', as(this, 'GfxState'), as(opac, 'numeric'))
}

setFillOverprint <-
function( this, op )
{
    .Call('R_GfxState_setFillOverprint', as(this, 'GfxState'), as(op, 'GBool'))
}

setStrokeOverprint <-
function( this, op )
{
    .Call('R_GfxState_setStrokeOverprint', as(this, 'GfxState'), as(op, 'GBool'))
}

setOverprintMode <-
function( this, op )
{
    .Call('R_GfxState_setOverprintMode', as(this, 'GfxState'), as(op, 'integer'))
}

setTransfer <-
function( this, funcs )
{
    .Call('R_GfxState_setTransfer', as(this, 'GfxState'), as(funcs, 'FunctionPtr'))
}

setLineWidth <-
function( this, width )
{
    .Call('R_GfxState_setLineWidth', as(this, 'GfxState'), as(width, 'numeric'))
}

setLineDash <-
function( this, dash, length, start )
{
    .Call('R_GfxState_setLineDash', as(this, 'GfxState'), as(dash, 'numeric'), as(length, 'integer'), as(start, 'numeric'))
}

setFlatness <-
function( this, flatness1 )
{
    .Call('R_GfxState_setFlatness', as(this, 'GfxState'), as(flatness1, 'integer'))
}

setLineJoin <-
function( this, lineJoin1 )
{
    .Call('R_GfxState_setLineJoin', as(this, 'GfxState'), as(lineJoin1, 'integer'))
}

setLineCap <-
function( this, lineCap1 )
{
    .Call('R_GfxState_setLineCap', as(this, 'GfxState'), as(lineCap1, 'integer'))
}

setMiterLimit <-
function( this, limit )
{
    .Call('R_GfxState_setMiterLimit', as(this, 'GfxState'), as(limit, 'numeric'))
}

setStrokeAdjust <-
function( this, sa )
{
    .Call('R_GfxState_setStrokeAdjust', as(this, 'GfxState'), as(sa, 'GBool'))
}

setAlphaIsShape <-
function( this, ais )
{
    .Call('R_GfxState_setAlphaIsShape', as(this, 'GfxState'), as(ais, 'GBool'))
}

setTextKnockout <-
function( this, tk )
{
    .Call('R_GfxState_setTextKnockout', as(this, 'GfxState'), as(tk, 'GBool'))
}

setFont <-
function( this, fontA, fontSizeA )
{
    .Call('R_GfxState_setFont', as(this, 'GfxState'), as(fontA, 'GfxFontPtr'), as(fontSizeA, 'numeric'))
}

setTextMat <-
function( this, a, b, c, d, e, f )
{
    .Call('R_GfxState_setTextMat', as(this, 'GfxState'), as(a, 'numeric'), as(b, 'numeric'), as(c, 'numeric'), as(d, 'numeric'), as(e, 'numeric'), as(f, 'numeric'))
}

setCharSpace <-
function( this, space )
{
    .Call('R_GfxState_setCharSpace', as(this, 'GfxState'), as(space, 'numeric'))
}

setWordSpace <-
function( this, space )
{
    .Call('R_GfxState_setWordSpace', as(this, 'GfxState'), as(space, 'numeric'))
}

setHorizScaling <-
function( this, scale )
{
    .Call('R_GfxState_setHorizScaling', as(this, 'GfxState'), as(scale, 'numeric'))
}

setLeading <-
function( this, leadingA )
{
    .Call('R_GfxState_setLeading', as(this, 'GfxState'), as(leadingA, 'numeric'))
}

setRise <-
function( this, riseA )
{
    .Call('R_GfxState_setRise', as(this, 'GfxState'), as(riseA, 'numeric'))
}

setRender <-
function( this, renderA )
{
    .Call('R_GfxState_setRender', as(this, 'GfxState'), as(renderA, 'integer'))
}

setRenderingIntent <-
function( this, intent )
{
    .Call('R_GfxState_setRenderingIntent', as(this, 'GfxState'), as(intent, 'character'))
}

setDisplayProfile <-
function( this, localDisplayProfileA )
{
    .Call('R_GfxState_setDisplayProfile', as(this, 'GfxState'), as(localDisplayProfileA, 'voidPtr'))
}

getDisplayProfile <-
function( this )
{
    .Call('R_GfxState_getDisplayProfile', as(this, 'GfxState'))
}

getXYZ2DisplayTransform <-
function( this )
{
    .Call('R_GfxState_getXYZ2DisplayTransform', as(this, 'GfxState'))
}

setMethod( 'moveTo' , c( 'GfxState' ),       
function( this, x, y )
{
    .Call('R_GfxState_moveTo', as(this, 'GfxState'), as(x, 'numeric'), as(y, 'numeric'))
} )


setMethod( 'lineTo' , c( 'GfxState' ),       
function( this, x, y )
{
    .Call('R_GfxState_lineTo', as(this, 'GfxState'), as(x, 'numeric'), as(y, 'numeric'))
} )


setMethod( 'curveTo' , c( 'GfxState' ),       
function( this, x1, y1, x2, y2, x3, y3 )
{
    .Call('R_GfxState_curveTo', as(this, 'GfxState'), as(x1, 'numeric'), as(y1, 'numeric'), as(x2, 'numeric'), as(y2, 'numeric'), as(x3, 'numeric'), as(y3, 'numeric'))
} )


closePath <-
function( this )
{
    .Call('R_GfxState_closePath', as(this, 'GfxState'))
}

clearPath <-
function( this )
{
    .Call('R_GfxState_clearPath', as(this, 'GfxState'))
}

clip <-
function( this )
{
    .Call('R_GfxState_clip', as(this, 'GfxState'))
}

clipToStrokePath <-
function( this )
{
    .Call('R_GfxState_clipToStrokePath', as(this, 'GfxState'))
}

clipToRect <-
function( this, xMin, yMin, xMax, yMax )
{
    .Call('R_GfxState_clipToRect', as(this, 'GfxState'), as(xMin, 'numeric'), as(yMin, 'numeric'), as(xMax, 'numeric'), as(yMax, 'numeric'))
}

textSetPos <-
function( this, tx, ty )
{
    .Call('R_GfxState_textSetPos', as(this, 'GfxState'), as(tx, 'numeric'), as(ty, 'numeric'))
}

textMoveTo <-
function( this, tx, ty )
{
    .Call('R_GfxState_textMoveTo', as(this, 'GfxState'), as(tx, 'numeric'), as(ty, 'numeric'))
}

textShift <-
function( this, tx, ty )
{
    .Call('R_GfxState_textShift', as(this, 'GfxState'), as(tx, 'numeric'), as(ty, 'numeric'))
}

shift <-
function( this, dx, dy )
{
    .Call('R_GfxState_shift', as(this, 'GfxState'), as(dx, 'numeric'), as(dy, 'numeric'))
}

save <-
function( this )
{
    .Call('R_GfxState_save', as(this, 'GfxState'))
}

restore <-
function( this )
{
    .Call('R_GfxState_restore', as(this, 'GfxState'))
}

hasSaves <-
function( this )
{
    .Call('R_GfxState_hasSaves', as(this, 'GfxState'))
}

isParentState <-
function( this, state )
{
    .Call('R_GfxState_isParentState', as(this, 'GfxState'), as(state, 'GfxStatePtr'))
}

parseBlendMode <-
function( this, obj, mode )
{
    .Call('R_GfxState_parseBlendMode', as(this, 'GfxState'), as(obj, 'ObjectPtr'), as(mode, 'GfxBlendModePtr'))
}

getReusablePath <-
function( this )
{
    .Call('R_GfxState_getReusablePath', as(this, 'GfxState'))
}

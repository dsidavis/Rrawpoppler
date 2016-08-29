#include <poppler/PDFDoc.h>
#include <poppler/OutputDev.h>
#include "Rpoppler.h"
#include "RFunctionsNativeMethods.h"

class ROutputDev : public OutputDev, public RFunctionsNativeMethods {


  public:
	GBool upsideDown();
	GBool useDrawChar();
	GBool useTilingPatternFill();
	GBool useShadedFills(int type );
	GBool useFillColorStop();
	GBool useDrawForm();
	GBool interpretType3Chars();
	GBool needNonText();
	GBool needCharCount();
	GBool needClipToCropBox();
	void setDefaultCTM(double * ctm );
	void startPage(int pageNum , GfxState * state , XRef * xref );
	void endPage();
	void dump();
	void cvtDevToUser(double dx , double dy , double * ux , double * uy );
	void cvtUserToDev(double ux , double uy , int * dx , int * dy );
	double * getDefCTM();
	double * getDefICTM();
	void saveState(GfxState * /*state*/);
	void restoreState(GfxState * /*state*/);
	void updateAll(GfxState * state );
	void updateCTM(GfxState * /*state*/, double /*m11*/, double /*m12*/, double /*m21*/, double /*m22*/, double /*m31*/, double /*m32*/);
	void updateLineDash(GfxState * /*state*/);
	void updateFlatness(GfxState * /*state*/);
	void updateLineJoin(GfxState * /*state*/);
	void updateLineCap(GfxState * /*state*/);
	void updateMiterLimit(GfxState * /*state*/);
	void updateLineWidth(GfxState * /*state*/);
	void updateStrokeAdjust(GfxState * /*state*/);
	void updateAlphaIsShape(GfxState * /*state*/);
	void updateTextKnockout(GfxState * /*state*/);
	void updateFillColorSpace(GfxState * /*state*/);
	void updateStrokeColorSpace(GfxState * /*state*/);
	void updateFillColor(GfxState * /*state*/);
	void updateStrokeColor(GfxState * /*state*/);
	void updateBlendMode(GfxState * /*state*/);
	void updateFillOpacity(GfxState * /*state*/);
	void updateStrokeOpacity(GfxState * /*state*/);
	void updatePatternOpacity(GfxState * /*state*/);
	void clearPatternOpacity(GfxState * /*state*/);
	void updateFillOverprint(GfxState * /*state*/);
	void updateStrokeOverprint(GfxState * /*state*/);
	void updateOverprintMode(GfxState * /*state*/);
	void updateTransfer(GfxState * /*state*/);
	void updateFillColorStop(GfxState * /*state*/, double /*offset*/);
	void updateFont(GfxState * /*state*/);
	void updateTextMat(GfxState * /*state*/);
	void updateCharSpace(GfxState * /*state*/);
	void updateRender(GfxState * /*state*/);
	void updateRise(GfxState * /*state*/);
	void updateWordSpace(GfxState * /*state*/);
	void updateHorizScaling(GfxState * /*state*/);
	void updateTextPos(GfxState * /*state*/);
	void updateTextShift(GfxState * /*state*/, double /*shift*/);
	void saveTextPos(GfxState * /*state*/);
	void restoreTextPos(GfxState * /*state*/);
	void stroke(GfxState * /*state*/);
	void fill(GfxState * /*state*/);
	void eoFill(GfxState * /*state*/);
	GBool tilingPatternFill(GfxState * /*state*/, Gfx * /*gfx*/, Catalog * /*cat*/, Object * /*str*/, double * /*pmat*/, int /*paintType*/, int /*tilingType*/, Dict * /*resDict*/, double * /*mat*/, double * /*bbox*/, int /*x0*/, int /*y0*/, int /*x1*/, int /*y1*/, double /*xStep*/, double /*yStep*/);
	GBool functionShadedFill(GfxState * /*state*/, GfxFunctionShading * /*shading*/);
	GBool axialShadedFill(GfxState * /*state*/, GfxAxialShading * /*shading*/, double /*tMin*/, double /*tMax*/);
	GBool axialShadedSupportExtend(GfxState * /*state*/, GfxAxialShading * /*shading*/);
	GBool radialShadedFill(GfxState * /*state*/, GfxRadialShading * /*shading*/, double /*sMin*/, double /*sMax*/);
	GBool radialShadedSupportExtend(GfxState * /*state*/, GfxRadialShading * /*shading*/);
	GBool gouraudTriangleShadedFill(GfxState * state , GfxGouraudTriangleShading * shading );
	GBool patchMeshShadedFill(GfxState * state , GfxPatchMeshShading * shading );
	void clip(GfxState * /*state*/);
	void eoClip(GfxState * /*state*/);
	void clipToStrokePath(GfxState * /*state*/);
	void beginStringOp(GfxState * /*state*/);
	void endStringOp(GfxState * /*state*/);
	void beginString(GfxState * /*state*/, GooString * /*s*/);
	void endString(GfxState * /*state*/);
	void drawChar(GfxState * /*state*/, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, double /*originX*/, double /*originY*/, CharCode /*code*/, int /*nBytes*/, Unicode * /*u*/, int /*uLen*/);
	void drawString(GfxState * /*state*/, GooString * /*s*/);
	GBool beginType3Char(GfxState * /*state*/, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, CharCode /*code*/, Unicode * /*u*/, int /*uLen*/);
	void endType3Char(GfxState * /*state*/);
	void beginTextObject(GfxState * /*state*/);
	void endTextObject(GfxState * /*state*/);
	void incCharCount(int /*nChars*/);
	void beginActualText(GfxState * /*state*/, GooString * /*text*/);
	void endActualText(GfxState * /*state*/);
	void drawImageMask(GfxState * state , Object * ref , Stream * str , int width , int height , GBool invert , GBool interpolate , GBool inlineImg );
	void setSoftMaskFromImageMask(GfxState * state , Object * ref , Stream * str , int width , int height , GBool invert , GBool inlineImg , double * baseMatrix );
	void unsetSoftMaskFromImageMask(GfxState * state , double * baseMatrix );
	void drawImage(GfxState * state , Object * ref , Stream * str , int width , int height , GfxImageColorMap * colorMap , GBool interpolate , int * maskColors , GBool inlineImg );
	void drawMaskedImage(GfxState * state , Object * ref , Stream * str , int width , int height , GfxImageColorMap * colorMap , GBool interpolate , Stream * maskStr , int maskWidth , int maskHeight , GBool maskInvert , GBool maskInterpolate );
	void drawSoftMaskedImage(GfxState * state , Object * ref , Stream * str , int width , int height , GfxImageColorMap * colorMap , GBool interpolate , Stream * maskStr , int maskWidth , int maskHeight , GfxImageColorMap * maskColorMap , GBool maskInterpolate );
	void endMarkedContent(GfxState * state );
	void beginMarkedContent(char * name , Dict * properties );
	void markPoint(char * name );
	void markPoint(char * name , Dict * properties );
	void opiBegin(GfxState * state , Dict * opiDict );
	void opiEnd(GfxState * state , Dict * opiDict );
	void type3D0(GfxState * /*state*/, double /*wx*/, double /*wy*/);
	void type3D1(GfxState * /*state*/, double /*wx*/, double /*wy*/, double /*llx*/, double /*lly*/, double /*urx*/, double /*ury*/);
	void psXObject(Stream * /*psStream*/, Stream * /*level1Stream*/);
	void startProfile();
	GooHash * getProfileHash();
	GooHash * endProfile();
	GBool checkTransparencyGroup(GfxState * /*state*/, GBool /*knockout*/);
	void beginTransparencyGroup(GfxState * /*state*/, double * /*bbox*/, GfxColorSpace * /*blendingColorSpace*/, GBool /*isolated*/, GBool /*knockout*/, GBool /*forSoftMask*/);
	void endTransparencyGroup(GfxState * /*state*/);
	void paintTransparencyGroup(GfxState * /*state*/, double * /*bbox*/);
	void setSoftMask(GfxState * /*state*/, double * /*bbox*/, GBool /*alpha*/, Function * /*transferFunc*/, GfxColor * /*backdropColor*/);
	void clearSoftMask(GfxState * /*state*/);
	void processLink(AnnotLink * /*link*/);
	GBool getVectorAntialias();
	void setVectorAntialias(GBool /*vaa*/);
	PopplerCache * getIccColorSpaceCache();

  public:
	ROutputDev(SEXP funs) {  setFunctions(funs, true); }
};

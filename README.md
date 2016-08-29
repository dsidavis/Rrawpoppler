# The Rrawpoppler package

This is an R package that provides an interface to the poppler library. 
poppler is a C++ library for reading and querying PDF documents.
This package allows us to read and query PDF documents directly in R.

There is the Rpoppler package on CRAN by Kurt Hornik.
Also, Jeroen Ooms created the pdftools package. 
Both of these provide excellent high-level facilities for extracting certain
information from PDF documents.  Rrawpoppler provides lower-level facilities
for working with a lot more of the PDF contents. Rpoppler and pdftools
are higher-level and easier to use.  Rrawpoppler is good for building
new functionality.

Rrawpoppler is a direct interface to (almost) all methods in 13 C++
classes in the poppler software.  The bindings are programmatically
generated using the RCIndex and RCodeGen packages.  What this means is
that we can readily expand the functionality to more classes and
methods. It takes very little human time.

One of the motivations for creating Rrawpoppler is to be able to
recover tabular data in PDF documents.  Previously we used pdfminer
and pdftohtml and wanted to make extending these easy via R code.  We
can often recover tables if we have the location of each text segment
in the table, and also if we know about horizontal and vertical lines
that appear on the page(s).  We can recover these details and then
can often determine rows and columns and process tables with missing
cells. We have been doing this with a modified version of pdftohtml
and using it to generate XML which we read into R and process.
pdftohtml uses the same basic xpdf libraries in poppler, and
so Rrawpoppler allows us to customize how we extract the data
rather than having to modify and recompile pdftohtml.


# Alternative Approaches

We have been working with PDF over the last few months and have used
(and adapted)
* pdfminer  (to XML)
* pdftohtml (to XML)
* pdf2htmlEX (to HTML)
* poppler   (native)

pdfminer is a Python module. We used this to generate an XML
represenation of the PDF contents. We use the CVRead package to ingest
the resulting XML.  This gaves us the text as individual
characters. Within R, we recombined these based on their x and y
locations into strings.  We adapted the tool to give us the
information we needed, e.g., text, lines, ...  We used it because,
written in a high-level language, it was flexible and easy to
adapt. It is slower than the other approaches and its support for
Unicode characters became challenging.


[pdftohtml](http://pdftohtml.sourceforge.net/)C is a standalone program written in C++ that uses the xpdf libraries. This was easy 
to adapt to make it do what we wanted. Importantly, we used its -xml command line flag to 
generate XML.  This gave us the text.  We modified the code to get the rectangles, lines
and images. This is much faster than pdfminer.

pdf2htmlEX generates HTML rather than XML. It creates faithful renderings of the 
original pages. However, it is cumbersome to query the contents. Using the XML and RCSS
packages, we could recover much of the information and details. 
Unfortunately, the tool collapses contents into &lt;div&gt; elements, but does not combine
all &lt;divs&gt; at the same location into the same element. As a result, we have to do 
computations to identify cells at the same location. Importantly for our application,
this tool does not give information about lines and rectangles. Instead, it renders
them as background PNG files on the HTML, but conceals this information from those of
use querying the HTML.


The Rrawpoppler package (this package) is a reasonably low-cost interface
to the poppler XPDF library(s).  This is the same code underlying
pdftohtml so we already have some experience with using and adapting
it.  After some initial configuration and experimentation, we
programmatically generated bindings to the important classes in this
library. We used the RCIndex and (adapted) the RCodeGen packages to create
the approximately 8000 lines of C++ and R code that define the interface.

This gives us access to reading, splitting and querying a PDF document
and all the other aspects of the poppler API.

One element we learned from pdftohtml and is shared by poppler is the
event-driven/streaming processing provided by the OutputDev class.
The idea is quite simple. There is a generic top-level OutptDev class
defined that defines an interface for the PDF processor to call when
certain events occur. We can sub-class/extend this device to provide
handlers for these events.  (This is similar to XML's SAX, libclang's
vistors's, etc.)   


# Streaming Devices

We have extended the OuptutDev class with an R-specific class that allows the
R user to create an OutputDev implemented using R functions for the methods
of OutputDev. One can implement zero or more of these functions/methods.
When a C++ method in the device is invoked, we find the corresponding 
R function or we use the default routine.

This is the most likely mechanism for extracting information from a document.
We are notified for different events in the processing.
The names of the methods for which we can provide an R function method are
```
  [1] "upsideDown"                 "useDrawChar"                "useTilingPatternFill"       "useShadedFills"             "useFillColorStop"          
  [6] "useDrawForm"                "interpretType3Chars"        "needNonText"                "needCharCount"              "needClipToCropBox"         
 [11] "setDefaultCTM"              "checkPageSlice"             "startPage"                  "endPage"                    "dump"                      
 [16] "cvtDevToUser"               "cvtUserToDev"               "getDefCTM"                  "getDefICTM"                 "saveState"                 
 [21] "restoreState"               "updateAll"                  "updateCTM"                  "updateLineDash"             "updateFlatness"            
 [26] "updateLineJoin"             "updateLineCap"              "updateMiterLimit"           "updateLineWidth"            "updateStrokeAdjust"        
 [31] "updateAlphaIsShape"         "updateTextKnockout"         "updateFillColorSpace"       "updateStrokeColorSpace"     "updateFillColor"           
 [36] "updateStrokeColor"          "updateBlendMode"            "updateFillOpacity"          "updateStrokeOpacity"        "updatePatternOpacity"      
 [41] "clearPatternOpacity"        "updateFillOverprint"        "updateStrokeOverprint"      "updateOverprintMode"        "updateTransfer"            
 [46] "updateFillColorStop"        "updateFont"                 "updateTextMat"              "updateCharSpace"            "updateRender"              
 [51] "updateRise"                 "updateWordSpace"            "updateHorizScaling"         "updateTextPos"              "updateTextShift"           
 [56] "saveTextPos"                "restoreTextPos"             "stroke"                     "fill"                       "eoFill"                    
 [61] "tilingPatternFill"          "functionShadedFill"         "axialShadedFill"            "axialShadedSupportExtend"   "radialShadedFill"          
 [66] "radialShadedSupportExtend"  "gouraudTriangleShadedFill"  "patchMeshShadedFill"        "clip"                       "eoClip"                    
 [71] "clipToStrokePath"           "beginStringOp"              "endStringOp"                "beginString"                "endString"                 
 [76] "drawChar"                   "drawString"                 "beginType3Char"             "endType3Char"               "beginTextObject"           
 [81] "endTextObject"              "incCharCount"               "beginActualText"            "endActualText"              "drawImageMask"             
 [86] "setSoftMaskFromImageMask"   "unsetSoftMaskFromImageMask" "drawImage"                  "drawMaskedImage"            "drawSoftMaskedImage"       
 [91] "endMarkedContent"           "beginMarkedContent"         "markPoint"                  "opiBegin"                   "opiEnd"                    
 [96] "type3D0"                    "type3D1"                    "drawForm"                   "psXObject"                  "startProfile"              
[101] "getProfileHash"             "endProfile"                 "checkTransparencyGroup"     "beginTransparencyGroup"     "endTransparencyGroup"      
[106] "paintTransparencyGroup"     "setSoftMask"                "clearSoftMask"              "processLink"                "getVectorAntialias"        
[111] "setVectorAntialias"        
```
These are all the public methods.

The idea is, for example, we can implement startPage() and endPage() to identify the transition between pages. 
Methods such as updateLineCap(), updateMiterLimit(), updateLineDash(), updateLineWidth(), ... allow us to 
update the current drawing state for lines.  Similarly, updateFillColor() and updateStrokeColor() update the current
color to use for subsequent elements.  Likewise, updateFont() identifies a change for the font of the subsequent text.
drawChar() and drawString().  useDrawChar() indicates whether the device uses drawChar() or drawSring().
The methods stroke(), fill(), eoFill() ...  identify when we are drawing a shape.


Simple examples of this device are in [tests/dev.R](tests/dev.R) and [tests/testDev.R](tests/testDev.R) and 
[tests/collectText.R](tests/collectText.R).
We'll add more "soon".

Implementing devices with R functions is of course slower than using C++ methods.
In the not-necessarily-near future, we hope to be able to compile R functions to native code
using the RLLVMCompile and RLLVM packages and make the code fast.


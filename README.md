This is an R package that provides an interface to the poppler library. 
poppler is a C++ library for reading and querying PDF documents.
This package allows us to read and query PDF documents directly in R.

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


pdftohtml is a standalone program written in C++ that uses the xpdf libraries. This was easy 
to adapt to make it do what we wanted. Importantly, we used its -xml command line flag to 
generate XML.  This gave us the text.  We modified the code to get the rectangles, lines
and images. This is much faster than pdfminer.

pdf2htmlEX generates HTML rather than XML. It creates faithful renderings of the 
original pages. However, it is cumbersome to query the contents. Using the XML and RCSS
packages, we could recover much of the information and details. 
Unfortunately, the tool collapses contents into <div> elements, but does not combine
all <div>s at the same location into the same element. As a result, we have to do 
computations to identify cells at the same location. Importantly for our application,
this tool does not give information about lines and rectangles. Instead, it renders
them as background PNG files on the HTML, but conceals this information from those of
use querying the HTML.


The Rpoppler package (this package) is a reasonably low-cost interface
to the poppler XPDF library(s).  This is the same code underlying
pdftohtml so we already have some experience with using and adapting
it.  After some initial configuration and experimentation, we
programmatically generated bindings to the important classes in this
library. We used the RCIndex and (adapted) the RCodeGen packages to create
the approximately 8000 lines of C++ and R code that define the interface.

This gives us access to reading, splitting and querying a PDF document.


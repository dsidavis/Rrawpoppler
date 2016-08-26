setMethod("dim", "Page",
          function(x)
            c(getMediaWidth(x), getMediaHeight(x)))

          

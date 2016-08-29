# This explicitly specifies how to deal with several types. We could resolve the typedefs for GBool
#
# [Done] Deal with passing an R string as GooString. See Todo.xml in (strangely) RCodeGen.
#
logicCFun = function(cvar, rvar, type, typeMap, cast) { sprintf("%s = LOGICAL(%s)[0];", cvar, rvar)}
logicToR = function(cvar, rvar, type, typeMap, cast){sprintf("Rf_ScalarLogical(%s)", cvar)}
longlongToR = function(cvar, rvar, type, typeMap, cast){sprintf("Rf_ScalarReal(%s)", cvar)}
typemap = list("GooString *"= list(convertValueToR = "GooStringToR",
                                   convertRValue = "GooStringFromR",
                                   coerceRParam = function(var, type, typeMap, ...)
                                                            sprintf("as(%s, 'GooStringOrCharacter')", var) ),
               "long long" = list(convertValueToR = longlongToR,
                                  convertRValue = function(cvar, rvar, type, typeMap, cast) sprintf("%s = REAL(%s)[0];", cvar, rvar)),
               GBool = list(convertRValue = logicCFun, convertValueToR = logicToR),
               "Guchar *" = list(convertRValue = function(cvar, rvar, type, typeMap, cast){ sprintf("%s = (Guchar *) RAW(%s);", cvar, rvar) }),
               bool = list(convertRValue = logicCFun, convertValueToR = logicToR))


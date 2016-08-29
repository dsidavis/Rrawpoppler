removeThis =
function(fun)
{    
    formals(fun) = formals(fun)[-1]
    fun
}


addThis =
function(fun)
{
    p = alist(this=)
    i = seq(along = formals(fun)) + 1
    p[i] = formals(fun)
    names(p)[i] = names(formals(fun))
    formals(fun) = p
    fun
}


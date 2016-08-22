gen = 
function()
{
    ans = list()
    v = function(cur, ...) {
         if(cur$kind == CXCursor_ClassDecl)
            ans[[ length(ans) + 1]]  <<- cur
        
        CXChildVisit_Continue
    }
    list(visitor = v, ans = function() ans)
}

// round for +inf
template<typename INT>
inline INT div_ceil(INT x,INT y){
    return (x<0?x/y:(x+y-1)/y);
}

// round for -inf
template<typename INT>
inline INT div_floor(INT x,INT y){
    return (x>0?x/y:(x-y+1)/y);
}
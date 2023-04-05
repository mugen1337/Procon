// angle of a-b-c
Real get_smaller_angle(Point a,Point b,Point c){
    Point v=a-b,w=c-b;
    auto A=atan2(imag(v),real(v));
    auto B=atan2(imag(w),real(w));
    if(A>B) swap(A,B);
    Real res=B-A;
    return min(res,pi*2.0-res);
}

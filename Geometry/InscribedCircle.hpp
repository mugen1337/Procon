// 内接円
Circle inscribed_circle(Point a,Point b,Point c){
    Real A,B;
    {
        Point t=c-a;
        t*=conj(b-a);
        t/=norm(b-a);
        A=atan2(imag(t),real(t));
    }
    {
        Point t=a-b;
        t*=conj(c-b);
        t/=norm(c-b);
        B=atan2(imag(t),real(t));
    }
    Line Amid=Line(a,a+rotate(A*0.5,b-a)),Bmid=Line(b,b+rotate(B*0.5,c-b));
    auto center=crosspoint(Amid,Bmid);
    auto h=projection(Line(a,b),center);
    return Circle(center,dis(h,center));
}
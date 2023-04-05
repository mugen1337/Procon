// 外接円
Circle circumscribed_circle(Point a,Point b,Point c){
    Line orth_ab((a+b)*0.5,(a+b)*0.5+Point(-imag(b-a),real(b-a)));
    Line orth_bc((b+c)*0.5,(b+c)*0.5+Point(-imag(c-b),real(c-b)));
    Point center=crosspoint(orth_ab,orth_bc);
    Real r=dis(a,center);
    return Circle(center,r);
}
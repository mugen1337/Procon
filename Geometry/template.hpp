// Real
using Real=double;
const Real EPS=1e-6;
const Real pi=acosl(-1);

// Point
using Point=complex<Real>;
istream &operator>>(istream &is,Point &p){
    Real a,b;
    is>>a>>b;
    p=Point(a,b);
    return is;
}
ostream &operator<<(ostream &os,Point &p){
    return os<<fixed<<setprecision(12)<<p.real()<<' '<<p.imag();
}
inline bool eq(Real a,Real b){
    return fabs(a-b)<EPS;
}
Point operator*(const Point &p,const Real &d){
    return Point(real(p)*d,imag(p)*d);
}

// Line
struct Line{
    Point p1,p2;
    Line()=default;
    Line(Point p1,Point p2):p1(p1),p2(p2){}
    //Ax + By = C
    Line(Real A,Real B,Real C){
        if(eq(A,0))     p1=Point(0,C/B),p2=Point(1,C/B);
        else if(eq(B,0))p1=Point(C/A,0),p2=Point(C/A,1);
        else            p1=Point(0,C/B),p2=Point(C/A,0);
    }
};

// Segment
struct Segment:Line{
    Segment()=default;
    Segment(Point p1,Point p2):Line(p1,p2){}
};
struct Circle{
    Point center;
    Real r;
    Circle()=default;
    Circle(Point center,Real r):center(center),r(r){}
};

// Polygon
using Polygon=vector<Point>;
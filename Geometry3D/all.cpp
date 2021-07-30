using Real=double;
const Real EPS=1e-6;
const Real pi=acosl(-1);

inline bool eq(const Real &a,const Real &b){
    return fabs(a-b)<EPS;
}

inline int sign(const Real &x){
    if(x<=-EPS) return -1;
    if(x>=EPS)  return 1;
    return 0;
}

struct Point{
    Real x,y,z;

    Point(Real x,Real y,Real z):x(x),y(y),z(z){}
    Point():x(0),y(0),z(0){}
    Point &operator-=(const Point &rhs){
        x-=rhs.x;
        y-=rhs.y;
        z-=rhs.z;
        return *this;
    }
    Point &operator+=(const Point &rhs){
        x+=rhs.x;
        y+=rhs.y;
        z+=rhs.z;
        return *this;
    }
    Point &operator*=(const Real &d){
        x*=d;
        y*=d;
        z*=d;
        return *this;
    }
    Point operator+(const Point &rhs)const{return Point(*this)+=rhs;}
    Point operator-(const Point &rhs)const{return Point(*this)-=rhs;}
    Point operator*(const Real &d)const{return Point(*this)*=d;}
    bool operator==(const Point &rhs)const{return eq(x,rhs.x) and eq(y,rhs.y) and eq(z,rhs.z);}
    bool operator!=(const Point &rhs)const{return !eq(x,rhs.x) or !eq(y,rhs.y) or !eq(z,rhs.z);}
};

istream &operator>>(istream &is,Point &p){
    Real x,y,z;
    is>>x>>y>>z;
    p=Point(x,y,z);
    return is;
}

ostream &operator<<(ostream &os,Point &p){
    return os<<fixed<<setprecision(12)<<p.x<<" "<<p.y<<" "<<p.z;
}

struct Line{
    Point a,b;
    Line()=default;
    Line(Point a,Point b):a(a),b(b){}
};

struct Segment:Line{
    Segment()=default;
    Segment(Point a,Point b):Line(a,b){}
};

struct Sphere{
    Point center;
    Real r;
    Sphere(Point center,Real r):center(center),r(r){}
};

Real dot(Point a,Point b){
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

Real dis(const Point &lhs,const Point &rhs){
    return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y)+(lhs.z-rhs.z)*(lhs.z-rhs.z));
}

Real norm(const Point &p){
    return p.x*p.x+p.y*p.y+p.z*p.z;
}

Real abs(const Point &p){
    return sqrt(norm(p));
}

/*
垂線の足をh
h = k * (p1-p2)
dot(p2-p1, ph)=0
ph・(p2-p1) = 0
=> {(p-p1)-(h-p1)}・(p2-p1) = 0
=> ...
=> k = dot(p1-p2, p-p1) / norm(p1-p2)
*/
Point projection(const Line &l,const Point &p){
    Real k=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);
    return l.a+(l.a-l.b)*k;
}
Point projection(const Segment &l,const Point &p){
    Real k=dot(l.a-l.b,p-l.a)/norm(l.a-l.b);
    return l.a+(l.a-l.b)*k;
}

bool intersect(Sphere c,Point p){
    return abs(abs(p-c.center)-c.r)<EPS;
}

// 交点の個数
int intersect(Sphere c,Segment l){
    Point h=projection(l,c.center);
    if(sign(norm(h-c.center)-norm(c.r))>0) return 0;
    Real da=dis(c.center,l.a),db=dis(c.center,l.b);
    if(sign(c.r-da)>=0 and sign(c.r-db)>=0) return 0;
    if((sign(da-c.r)<0 and sign(db-c.r)>0) or (sign(da-c.r)>0 and sign(db-c.r)<0)) return 1;
    if(sign(dot(l.a-h,l.b-h))<0) return 2;
    return 0;
}
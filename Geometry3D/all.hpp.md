---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry3D/all.hpp\"\nusing Real=double;\nconst Real EPS=1e-6;\n\
    const Real pi=acosl(-1);\n\ninline bool eq(const Real &a,const Real &b){\n   \
    \ return fabs(a-b)<EPS;\n}\n\ninline int sign(const Real &x){\n    if(x<=-EPS)\
    \ return -1;\n    if(x>=EPS)  return 1;\n    return 0;\n}\n\nstruct Point{\n \
    \   Real x,y,z;\n\n    Point(Real x,Real y,Real z):x(x),y(y),z(z){}\n    Point():x(0),y(0),z(0){}\n\
    \    Point &operator-=(const Point &rhs){\n        x-=rhs.x;\n        y-=rhs.y;\n\
    \        z-=rhs.z;\n        return *this;\n    }\n    Point &operator+=(const\
    \ Point &rhs){\n        x+=rhs.x;\n        y+=rhs.y;\n        z+=rhs.z;\n    \
    \    return *this;\n    }\n    Point &operator*=(const Real &d){\n        x*=d;\n\
    \        y*=d;\n        z*=d;\n        return *this;\n    }\n    Point operator+(const\
    \ Point &rhs)const{return Point(*this)+=rhs;}\n    Point operator-(const Point\
    \ &rhs)const{return Point(*this)-=rhs;}\n    Point operator*(const Real &d)const{return\
    \ Point(*this)*=d;}\n    bool operator==(const Point &rhs)const{return eq(x,rhs.x)\
    \ and eq(y,rhs.y) and eq(z,rhs.z);}\n    bool operator!=(const Point &rhs)const{return\
    \ !eq(x,rhs.x) or !eq(y,rhs.y) or !eq(z,rhs.z);}\n};\n\nistream &operator>>(istream\
    \ &is,Point &p){\n    Real x,y,z;\n    is>>x>>y>>z;\n    p=Point(x,y,z);\n   \
    \ return is;\n}\n\nostream &operator<<(ostream &os,Point &p){\n    return os<<fixed<<setprecision(12)<<p.x<<\"\
    \ \"<<p.y<<\" \"<<p.z;\n}\n\nstruct Line{\n    Point a,b;\n    Line()=default;\n\
    \    Line(Point a,Point b):a(a),b(b){}\n};\n\nstruct Segment:Line{\n    Segment()=default;\n\
    \    Segment(Point a,Point b):Line(a,b){}\n};\n\nstruct Sphere{\n    Point center;\n\
    \    Real r;\n    Sphere(Point center,Real r):center(center),r(r){}\n};\n\nReal\
    \ dot(Point a,Point b){\n    return a.x*b.x+a.y*b.y+a.z*b.z;\n}\n\nReal dis(const\
    \ Point &lhs,const Point &rhs){\n    return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y)+(lhs.z-rhs.z)*(lhs.z-rhs.z));\n\
    }\n\nReal norm(const Point &p){\n    return p.x*p.x+p.y*p.y+p.z*p.z;\n}\n\nReal\
    \ abs(const Point &p){\n    return sqrt(norm(p));\n}\n\n/*\n\u5782\u7DDA\u306E\
    \u8DB3\u3092h\nh = k * (p1-p2)\ndot(p2-p1, ph)=0\nph\u30FB(p2-p1) = 0\n=> {(p-p1)-(h-p1)}\u30FB\
    (p2-p1) = 0\n=> ...\n=> k = dot(p1-p2, p-p1) / norm(p1-p2)\n*/\nPoint projection(const\
    \ Line &l,const Point &p){\n    Real k=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);\n   \
    \ return l.a+(l.a-l.b)*k;\n}\nPoint projection(const Segment &l,const Point &p){\n\
    \    Real k=dot(l.a-l.b,p-l.a)/norm(l.a-l.b);\n    return l.a+(l.a-l.b)*k;\n}\n\
    \nbool intersect(Sphere c,Point p){\n    return abs(abs(p-c.center)-c.r)<EPS;\n\
    }\n\n// \u4EA4\u70B9\u306E\u500B\u6570\nint intersect(Sphere c,Segment l){\n \
    \   Point h=projection(l,c.center);\n    if(sign(norm(h-c.center)-norm(c.r))>0)\
    \ return 0;\n    Real da=dis(c.center,l.a),db=dis(c.center,l.b);\n    if(sign(c.r-da)>=0\
    \ and sign(c.r-db)>=0) return 0;\n    if((sign(da-c.r)<0 and sign(db-c.r)>0) or\
    \ (sign(da-c.r)>0 and sign(db-c.r)<0)) return 1;\n    if(sign(dot(l.a-h,l.b-h))<0)\
    \ return 2;\n    return 0;\n}\n"
  code: "using Real=double;\nconst Real EPS=1e-6;\nconst Real pi=acosl(-1);\n\ninline\
    \ bool eq(const Real &a,const Real &b){\n    return fabs(a-b)<EPS;\n}\n\ninline\
    \ int sign(const Real &x){\n    if(x<=-EPS) return -1;\n    if(x>=EPS)  return\
    \ 1;\n    return 0;\n}\n\nstruct Point{\n    Real x,y,z;\n\n    Point(Real x,Real\
    \ y,Real z):x(x),y(y),z(z){}\n    Point():x(0),y(0),z(0){}\n    Point &operator-=(const\
    \ Point &rhs){\n        x-=rhs.x;\n        y-=rhs.y;\n        z-=rhs.z;\n    \
    \    return *this;\n    }\n    Point &operator+=(const Point &rhs){\n        x+=rhs.x;\n\
    \        y+=rhs.y;\n        z+=rhs.z;\n        return *this;\n    }\n    Point\
    \ &operator*=(const Real &d){\n        x*=d;\n        y*=d;\n        z*=d;\n \
    \       return *this;\n    }\n    Point operator+(const Point &rhs)const{return\
    \ Point(*this)+=rhs;}\n    Point operator-(const Point &rhs)const{return Point(*this)-=rhs;}\n\
    \    Point operator*(const Real &d)const{return Point(*this)*=d;}\n    bool operator==(const\
    \ Point &rhs)const{return eq(x,rhs.x) and eq(y,rhs.y) and eq(z,rhs.z);}\n    bool\
    \ operator!=(const Point &rhs)const{return !eq(x,rhs.x) or !eq(y,rhs.y) or !eq(z,rhs.z);}\n\
    };\n\nistream &operator>>(istream &is,Point &p){\n    Real x,y,z;\n    is>>x>>y>>z;\n\
    \    p=Point(x,y,z);\n    return is;\n}\n\nostream &operator<<(ostream &os,Point\
    \ &p){\n    return os<<fixed<<setprecision(12)<<p.x<<\" \"<<p.y<<\" \"<<p.z;\n\
    }\n\nstruct Line{\n    Point a,b;\n    Line()=default;\n    Line(Point a,Point\
    \ b):a(a),b(b){}\n};\n\nstruct Segment:Line{\n    Segment()=default;\n    Segment(Point\
    \ a,Point b):Line(a,b){}\n};\n\nstruct Sphere{\n    Point center;\n    Real r;\n\
    \    Sphere(Point center,Real r):center(center),r(r){}\n};\n\nReal dot(Point a,Point\
    \ b){\n    return a.x*b.x+a.y*b.y+a.z*b.z;\n}\n\nReal dis(const Point &lhs,const\
    \ Point &rhs){\n    return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y)+(lhs.z-rhs.z)*(lhs.z-rhs.z));\n\
    }\n\nReal norm(const Point &p){\n    return p.x*p.x+p.y*p.y+p.z*p.z;\n}\n\nReal\
    \ abs(const Point &p){\n    return sqrt(norm(p));\n}\n\n/*\n\u5782\u7DDA\u306E\
    \u8DB3\u3092h\nh = k * (p1-p2)\ndot(p2-p1, ph)=0\nph\u30FB(p2-p1) = 0\n=> {(p-p1)-(h-p1)}\u30FB\
    (p2-p1) = 0\n=> ...\n=> k = dot(p1-p2, p-p1) / norm(p1-p2)\n*/\nPoint projection(const\
    \ Line &l,const Point &p){\n    Real k=dot(p-l.a,l.a-l.b)/norm(l.a-l.b);\n   \
    \ return l.a+(l.a-l.b)*k;\n}\nPoint projection(const Segment &l,const Point &p){\n\
    \    Real k=dot(l.a-l.b,p-l.a)/norm(l.a-l.b);\n    return l.a+(l.a-l.b)*k;\n}\n\
    \nbool intersect(Sphere c,Point p){\n    return abs(abs(p-c.center)-c.r)<EPS;\n\
    }\n\n// \u4EA4\u70B9\u306E\u500B\u6570\nint intersect(Sphere c,Segment l){\n \
    \   Point h=projection(l,c.center);\n    if(sign(norm(h-c.center)-norm(c.r))>0)\
    \ return 0;\n    Real da=dis(c.center,l.a),db=dis(c.center,l.b);\n    if(sign(c.r-da)>=0\
    \ and sign(c.r-db)>=0) return 0;\n    if((sign(da-c.r)<0 and sign(db-c.r)>0) or\
    \ (sign(da-c.r)>0 and sign(db-c.r)<0)) return 1;\n    if(sign(dot(l.a-h,l.b-h))<0)\
    \ return 2;\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Geometry3D/all.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry3D/all.hpp
layout: document
redirect_from:
- /library/Geometry3D/all.hpp
- /library/Geometry3D/all.hpp.html
title: Geometry3D/all.hpp
---

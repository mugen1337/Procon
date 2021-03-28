---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Geometry/include.cpp
    title: Geometry/include.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ_2173.test.cpp
    title: test/AOJ_2173.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry/template.cpp\"\n// Real\nusing Real=double;\nconst\
    \ Real EPS=1e-6;\nconst Real pi=acosl(-1);\n\n// Point\nusing Point=complex<Real>;\n\
    istream &operator>>(istream &is,Point &p){\n    Real a,b;\n    is>>a>>b;\n   \
    \ p=Point(a,b);\n    return is;\n}\nostream &operator<<(ostream &os,Point &p){\n\
    \    return os<<fixed<<setprecision(12)<<p.real()<<' '<<p.imag();\n}\ninline bool\
    \ eq(Real a,Real b){\n    return fabs(a-b)<EPS;\n}\nPoint operator*(const Point\
    \ &p,const Real &d){\n    return Point(real(p)*d,imag(p)*d);\n}\n\n// Line\nstruct\
    \ Line{\n    Point p1,p2;\n    Line()=default;\n    Line(Point p1,Point p2):p1(p1),p2(p2){}\n\
    \    //Ax + By = C\n    Line(Real A,Real B,Real C){\n        if(eq(A,0))     p1=Point(0,C/B),p2=Point(1,C/B);\n\
    \        else if(eq(B,0))p1=Point(C/A,0),p2=Point(C/A,1);\n        else      \
    \      p1=Point(0,C/B),p2=Point(C/A,0);\n    }\n};\n\n// Segment\nstruct Segment:Line{\n\
    \    Segment()=default;\n    Segment(Point p1,Point p2):Line(p1,p2){}\n};\nstruct\
    \ Circle{\n    Point center;\n    Real r;\n    Circle()=default;\n    Circle(Point\
    \ center,Real r):center(center),r(r){}\n};\n\n// Polygon\nusing Polygon=vector<Point>;\n"
  code: "// Real\nusing Real=double;\nconst Real EPS=1e-6;\nconst Real pi=acosl(-1);\n\
    \n// Point\nusing Point=complex<Real>;\nistream &operator>>(istream &is,Point\
    \ &p){\n    Real a,b;\n    is>>a>>b;\n    p=Point(a,b);\n    return is;\n}\nostream\
    \ &operator<<(ostream &os,Point &p){\n    return os<<fixed<<setprecision(12)<<p.real()<<'\
    \ '<<p.imag();\n}\ninline bool eq(Real a,Real b){\n    return fabs(a-b)<EPS;\n\
    }\nPoint operator*(const Point &p,const Real &d){\n    return Point(real(p)*d,imag(p)*d);\n\
    }\n\n// Line\nstruct Line{\n    Point p1,p2;\n    Line()=default;\n    Line(Point\
    \ p1,Point p2):p1(p1),p2(p2){}\n    //Ax + By = C\n    Line(Real A,Real B,Real\
    \ C){\n        if(eq(A,0))     p1=Point(0,C/B),p2=Point(1,C/B);\n        else\
    \ if(eq(B,0))p1=Point(C/A,0),p2=Point(C/A,1);\n        else            p1=Point(0,C/B),p2=Point(C/A,0);\n\
    \    }\n};\n\n// Segment\nstruct Segment:Line{\n    Segment()=default;\n    Segment(Point\
    \ p1,Point p2):Line(p1,p2){}\n};\nstruct Circle{\n    Point center;\n    Real\
    \ r;\n    Circle()=default;\n    Circle(Point center,Real r):center(center),r(r){}\n\
    };\n\n// Polygon\nusing Polygon=vector<Point>;"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/template.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-03-29 03:23:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ_2173.test.cpp
documentation_of: Geometry/template.cpp
layout: document
redirect_from:
- /library/Geometry/template.cpp
- /library/Geometry/template.cpp.html
title: Geometry/template.cpp
---

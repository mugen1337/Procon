---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Geometry/CounterClockWise.cpp
    title: Geometry/CounterClockWise.cpp
  - icon: ':warning:'
    path: Geometry/Cross.cpp
    title: Geometry/Cross.cpp
  - icon: ':warning:'
    path: Geometry/Distance.cpp
    title: Geometry/Distance.cpp
  - icon: ':warning:'
    path: Geometry/Dot.cpp
    title: Geometry/Dot.cpp
  - icon: ':warning:'
    path: Geometry/Intersect.cpp
    title: Geometry/Intersect.cpp
  - icon: ':warning:'
    path: Geometry/Projection.cpp
    title: Geometry/Projection.cpp
  - icon: ':warning:'
    path: Geometry/template.cpp
    title: Geometry/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ center,Real r):center(center),r(r){}\n};\n\n// Polygon\nusing Polygon=vector<Point>;\n\
    #line 1 \"Geometry/Dot.cpp\"\n// Dot\nReal dot(Point a,Point b) {\n    return\
    \ real(a)*real(b)+imag(a)*imag(b);\n}\n#line 1 \"Geometry/Cross.cpp\"\n// Cross\n\
    Real cross(Point a,Point b){\n    return real(a)*imag(b)-imag(a)*real(b);\n}\n\
    #line 1 \"Geometry/CounterClockWise.cpp\"\n// ccw (counter clockwise) (Requires:\
    \ cross, dot)\n//https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C\n\
    int ccw(Point a,Point b,Point c){\n   b-=a;c-=a;\n   if(cross(b,c)>EPS)      \
    \ return  1;//COUNTER CLOCKWISE\n   else if(cross(b,c)<-EPS) return -1;//CLOCKWISE\n\
    \   else if(dot(b,c)<0)      return  2;//c--a--b ONLINE BACK\n   else if(norm(b)<norm(c))\
    \ return -2;//a--b--c ONLINE FRONT\n   else                     return  0;//a--c--b\
    \ ON SEGMENT\n}\n#line 1 \"Geometry/Projection.cpp\"\n// Projection (Requires:\
    \ dot)\nPoint projection(Line l,Point p){\n    // \u30D9\u30AF\u30C8\u30EBl\u4E57\
    \u306B\u70B9p\u304B\u3089\u304A\u308D\u3057\u305F\u5782\u7DDA\u306E\u8DB3\n  \
    \  Real k=dot(l.p1-l.p2,p-l.p1)/norm(l.p1-l.p2);\n    return l.p1+(l.p1-l.p2)*k;\n\
    }\nPoint projection(Segment l,Point p){\n    Real k=dot(l.p1-l.p2,p-l.p1)/norm(l.p1-l.p2);\n\
    \    return l.p1+(l.p1-l.p2)*k;\n}\n#line 1 \"Geometry/Intersect.cpp\"\n// Intersect\
    \ (Requires : ccw, Dots, Cross, Projection)\nbool intersect(Line l,Point p){\n\
    \    return abs(ccw(l.p1,l.p2,p))!=1;\n}\n//\u76F4\u7DDA\u306E\u4EA4\u5DEE\u5224\
    \u5B9A\uFF0C\u5916\u7A4D\nbool intersect(Line l1,Line l2){\n    return abs(cross(l1.p2-l1.p1,l2.p2-l2.p1))>EPS\
    \ or abs(cross(l1.p2-l1.p1,l2.p2-l1.p1))<EPS;\n}\n//\u7DDA\u5206\u306B\u70B9\u304C\
    \u4E57\u308B\u304B\u306E\u5224\u5B9A\uFF0Cccw\nbool intersect(Segment s,Point\
    \ p){\n    return ccw(s.p1,s.p2,p)==0;\n}\n//\u76F4\u7DDA\u3068\u7DDA\u5206\u306E\
    \u4EA4\u5DEE\u5224\u5B9A\nbool intersect(Line l,Segment s){\n    return cross(l.p2-l.p1,s.p1-l.p1)*cross(l.p2-l.p1,s.p2-l.p1)<EPS;\n\
    }\n//\u5186\u3068\u76F4\u7DDA\u306E\u4EA4\u5DEE\u5224\u5B9A\nbool intersect(Circle\
    \ c,Line l){\n    return abs(c.center-projection(l,c.center))<=c.r+EPS;\n}\n//\u5186\
    \u4E0A\u304B\u3069\u3046\u304B\uFF0C\u5185\u90E8\u304B\u3069\u3046\u304B\u3067\
    \u306F\u306A\u3044\nbool intersect(Circle c,Point p){\n    return abs(abs(p-c.center)-c.r)<EPS;\n\
    }\n//\u7DDA\u5206\u3068\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\nbool intersect(Segment\
    \ s,Segment t){\n    return ccw(s.p1,s.p2,t.p1)*ccw(s.p1,s.p2,t.p2) <=0 and ccw(t.p1,t.p2,s.p1)*ccw(t.p1,t.p2,s.p2)<=0;\n\
    }\n//\u7DDA\u5206\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A\uFF0C\u4EA4\u70B9\u306E\
    \u500B\u6570\u3092\u8FD4\u3059\nint intersect(Circle c,Segment l){\n    Point\
    \ h=projection(l,c.center);\n    //\u76F4\u7DDA\u307E\u308B\u3063\u3068\u5186\u306E\
    \u5916\u5074\n    if(norm(h-c.center)-c.r*c.r>EPS)    return 0;\n    Real d1=abs(c.center-l.p1),d2=abs(c.center-l.p2);\n\
    \    //\u7DDA\u5206\u304C\u5186\u5185\n    if(d1<c.r+EPS and d2<c.r+EPS) return\
    \ 0;\n    if((d1<c.r-EPS and d2>c.r+EPS) or (d2<c.r-EPS and d1>c.r+EPS)) return\
    \ 1;\n    //\u5186\u306E\u5916\u90E8\u306B\u307E\u308B\u307E\u308B\u306F\u307F\
    \u51FA\u3066\u3044\u306A\u3044\u304B\n    if(dot(l.p1-h,l.p2-h)<0) return 2;\n\
    \    return 0;\n}\n//\u5186\u3068\u5186\u306E\u4F4D\u7F6E\u95A2\u4FC2\uFF0C\u5171\
    \u901A\u63A5\u7DDA\u306E\u500B\u6570\u3092\u8FD4\u3059\nint intersect(Circle c1,Circle\
    \ c2){\n    if(c1.r<c2.r) swap(c1,c2);\n    Real d=abs(c1.center-c2.center);\n\
    \    //2\u5186\u304C\u96E2\u308C\u3066\u3044\u308B\n    if(c1.r+c2.r<d)     return\
    \ 4;\n    //2\u5186\u304C\u5916\u63A5\u3059\u308B\n    if(eq(c1.r+c2.r,d)) return\
    \ 3;\n    //2\u5186\u304C\u4EA4\u308F\u308B\n    if(c1.r-c2.r<d)     return 2;\n\
    \    //\u5186\u304C\u5185\u63A5\u3059\u308B\n    if(eq(c1.r-c2.r,d)) return 1;\n\
    \    //\u5185\u5305\n                        return 0;\n}\n#line 1 \"Geometry/Distance.cpp\"\
    \n// Distance (Requires: Projection, Intersect)\nReal dis(Point a,Point b){\n\
    \    return abs(a-b);\n}\nReal dis(Line l,Point p){\n    return abs(p-projection(l,p));\n\
    }\nReal dis(Segment s,Point p){\n    Point r=projection(s,p);\n    if(intersect(s,r))\
    \ return abs(r-p);\n    return min(abs(s.p1-p),abs(s.p2-p));\n}\nReal dis(Segment\
    \ a,Segment b){\n    if(intersect(a,b)) return 0;\n    return min({dis(a,b.p1),dis(a,b.p2),dis(b,a.p1),dis(b,a.p2)});\n\
    }\nReal dis(Polygon a,Polygon b){\n    Real ret=-10;\n    int n=(int)a.size(),m=(int)b.size();\n\
    \    for(int i=0;i<n;i++)for(int j=0;j<m;j++){\n        Real d=dis(Segment(a[i],a[(i+1)%n]),Segment(b[j],b[(j+1)%m]));\n\
    \        if(ret<0) ret=d;\n        else      ret=min(ret,d);\n    }\n    return\
    \ ret;\n}\n#line 8 \"Geometry/include.cpp\"\n"
  code: '#include "./template.cpp"

    #include "./Dot.cpp"

    #include "./Cross.cpp"

    #include "./CounterClockWise.cpp"

    #include "./Projection.cpp"

    #include "./Intersect.cpp"

    #include "./Distance.cpp"

    '
  dependsOn:
  - Geometry/template.cpp
  - Geometry/Dot.cpp
  - Geometry/Cross.cpp
  - Geometry/CounterClockWise.cpp
  - Geometry/Projection.cpp
  - Geometry/Intersect.cpp
  - Geometry/Distance.cpp
  isVerificationFile: false
  path: Geometry/include.cpp
  requiredBy: []
  timestamp: '2021-03-29 03:23:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/include.cpp
layout: document
redirect_from:
- /library/Geometry/include.cpp
- /library/Geometry/include.cpp.html
title: Geometry/include.cpp
---

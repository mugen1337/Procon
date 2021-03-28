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
  bundledCode: "#line 1 \"Geometry/Intersect.cpp\"\n// Intersect (Requires : ccw,\
    \ Dots, Cross, Projection)\nbool intersect(Line l,Point p){\n    return abs(ccw(l.p1,l.p2,p))!=1;\n\
    }\n//\u76F4\u7DDA\u306E\u4EA4\u5DEE\u5224\u5B9A\uFF0C\u5916\u7A4D\nbool intersect(Line\
    \ l1,Line l2){\n    return abs(cross(l1.p2-l1.p1,l2.p2-l2.p1))>EPS or abs(cross(l1.p2-l1.p1,l2.p2-l1.p1))<EPS;\n\
    }\n//\u7DDA\u5206\u306B\u70B9\u304C\u4E57\u308B\u304B\u306E\u5224\u5B9A\uFF0C\
    ccw\nbool intersect(Segment s,Point p){\n    return ccw(s.p1,s.p2,p)==0;\n}\n\
    //\u76F4\u7DDA\u3068\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\nbool intersect(Line\
    \ l,Segment s){\n    return cross(l.p2-l.p1,s.p1-l.p1)*cross(l.p2-l.p1,s.p2-l.p1)<EPS;\n\
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
    \    //\u5185\u5305\n                        return 0;\n}\n"
  code: "// Intersect (Requires : ccw, Dots, Cross, Projection)\nbool intersect(Line\
    \ l,Point p){\n    return abs(ccw(l.p1,l.p2,p))!=1;\n}\n//\u76F4\u7DDA\u306E\u4EA4\
    \u5DEE\u5224\u5B9A\uFF0C\u5916\u7A4D\nbool intersect(Line l1,Line l2){\n    return\
    \ abs(cross(l1.p2-l1.p1,l2.p2-l2.p1))>EPS or abs(cross(l1.p2-l1.p1,l2.p2-l1.p1))<EPS;\n\
    }\n//\u7DDA\u5206\u306B\u70B9\u304C\u4E57\u308B\u304B\u306E\u5224\u5B9A\uFF0C\
    ccw\nbool intersect(Segment s,Point p){\n    return ccw(s.p1,s.p2,p)==0;\n}\n\
    //\u76F4\u7DDA\u3068\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\nbool intersect(Line\
    \ l,Segment s){\n    return cross(l.p2-l.p1,s.p1-l.p1)*cross(l.p2-l.p1,s.p2-l.p1)<EPS;\n\
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
    \    //\u5185\u5305\n                        return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Intersect.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-03-29 03:23:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ_2173.test.cpp
documentation_of: Geometry/Intersect.cpp
layout: document
redirect_from:
- /library/Geometry/Intersect.cpp
- /library/Geometry/Intersect.cpp.html
title: Geometry/Intersect.cpp
---

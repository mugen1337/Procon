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
  bundledCode: "#line 1 \"Geometry/Distance.cpp\"\n// Distance (Requires: Projection,\
    \ Intersect)\nReal dis(Point a,Point b){\n    return abs(a-b);\n}\nReal dis(Line\
    \ l,Point p){\n    return abs(p-projection(l,p));\n}\nReal dis(Segment s,Point\
    \ p){\n    Point r=projection(s,p);\n    if(intersect(s,r)) return abs(r-p);\n\
    \    return min(abs(s.p1-p),abs(s.p2-p));\n}\nReal dis(Segment a,Segment b){\n\
    \    if(intersect(a,b)) return 0;\n    return min({dis(a,b.p1),dis(a,b.p2),dis(b,a.p1),dis(b,a.p2)});\n\
    }\nReal dis(Polygon a,Polygon b){\n    Real ret=-10;\n    int n=(int)a.size(),m=(int)b.size();\n\
    \    for(int i=0;i<n;i++)for(int j=0;j<m;j++){\n        Real d=dis(Segment(a[i],a[(i+1)%n]),Segment(b[j],b[(j+1)%m]));\n\
    \        if(ret<0) ret=d;\n        else      ret=min(ret,d);\n    }\n    return\
    \ ret;\n}\n"
  code: "// Distance (Requires: Projection, Intersect)\nReal dis(Point a,Point b){\n\
    \    return abs(a-b);\n}\nReal dis(Line l,Point p){\n    return abs(p-projection(l,p));\n\
    }\nReal dis(Segment s,Point p){\n    Point r=projection(s,p);\n    if(intersect(s,r))\
    \ return abs(r-p);\n    return min(abs(s.p1-p),abs(s.p2-p));\n}\nReal dis(Segment\
    \ a,Segment b){\n    if(intersect(a,b)) return 0;\n    return min({dis(a,b.p1),dis(a,b.p2),dis(b,a.p1),dis(b,a.p2)});\n\
    }\nReal dis(Polygon a,Polygon b){\n    Real ret=-10;\n    int n=(int)a.size(),m=(int)b.size();\n\
    \    for(int i=0;i<n;i++)for(int j=0;j<m;j++){\n        Real d=dis(Segment(a[i],a[(i+1)%n]),Segment(b[j],b[(j+1)%m]));\n\
    \        if(ret<0) ret=d;\n        else      ret=min(ret,d);\n    }\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Distance.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-03-29 03:23:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ_2173.test.cpp
documentation_of: Geometry/Distance.cpp
layout: document
redirect_from:
- /library/Geometry/Distance.cpp
- /library/Geometry/Distance.cpp.html
title: Geometry/Distance.cpp
---

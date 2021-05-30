---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/include.cpp
    title: Geometry/include.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry/Tangent.cpp\"\n//v\n//\u70B9p\u304B\u3089\u5F15\
    \u3044\u305F\u5186c\u306E\u63A5\u7DDA\u306E\u63A5\u70B9\u3092\u8FD4\u3059\nvector<Point>\
    \ tangent(Circle c,Point p){\n    return crosspoint(c,Circle(p,sqrt(norm(c.center-p)-c.r*c.r)));\n\
    }\n//v\n//\u4E8C\u5186\u306E\u5171\u901A\u63A5\u7DDA\uFF0CLine\u306E2\u70B9\u306F\
    \u63A5\u70B9\u3092\u8868\u3059\nvector<Line> tangent(Circle c1,Circle c2){\n \
    \   vector<Line> ret;\n    if(c1.r<c2.r) swap(c1,c2);\n    Real g=norm(c1.center-c2.center);\n\
    \    if(eq(g,0)) return ret;\n    Point u=(c2.center-c1.center)/sqrt(g);\n   \
    \ Point v=rotate(pi*0.5,u);\n    for(int s:{-1,1}){\n        Real h=(c1.r+s*c2.r)/sqrt(g);\n\
    \        if(eq(1-h*h,0)){\n            ret.push_back(Line(c1.center+u*c1.r,c1.center+(u+v)*c1.r));\n\
    \        }\n        else if(1-h*h>0){\n            Point uu=u*h,vv=v*sqrt(1-h*h);\n\
    \            ret.push_back(Line(c1.center+(uu+vv)*c1.r,c2.center-(uu+vv)*c2.r*s));\n\
    \            ret.push_back(Line(c1.center+(uu-vv)*c1.r,c2.center-(uu-vv)*c2.r*s));\n\
    \        }\n    }\n    return ret;\n}\n"
  code: "//v\n//\u70B9p\u304B\u3089\u5F15\u3044\u305F\u5186c\u306E\u63A5\u7DDA\u306E\
    \u63A5\u70B9\u3092\u8FD4\u3059\nvector<Point> tangent(Circle c,Point p){\n   \
    \ return crosspoint(c,Circle(p,sqrt(norm(c.center-p)-c.r*c.r)));\n}\n//v\n//\u4E8C\
    \u5186\u306E\u5171\u901A\u63A5\u7DDA\uFF0CLine\u306E2\u70B9\u306F\u63A5\u70B9\u3092\
    \u8868\u3059\nvector<Line> tangent(Circle c1,Circle c2){\n    vector<Line> ret;\n\
    \    if(c1.r<c2.r) swap(c1,c2);\n    Real g=norm(c1.center-c2.center);\n    if(eq(g,0))\
    \ return ret;\n    Point u=(c2.center-c1.center)/sqrt(g);\n    Point v=rotate(pi*0.5,u);\n\
    \    for(int s:{-1,1}){\n        Real h=(c1.r+s*c2.r)/sqrt(g);\n        if(eq(1-h*h,0)){\n\
    \            ret.push_back(Line(c1.center+u*c1.r,c1.center+(u+v)*c1.r));\n   \
    \     }\n        else if(1-h*h>0){\n            Point uu=u*h,vv=v*sqrt(1-h*h);\n\
    \            ret.push_back(Line(c1.center+(uu+vv)*c1.r,c2.center-(uu+vv)*c2.r*s));\n\
    \            ret.push_back(Line(c1.center+(uu-vv)*c1.r,c2.center-(uu-vv)*c2.r*s));\n\
    \        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Tangent.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-05-30 19:44:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Tangent.cpp
layout: document
redirect_from:
- /library/Geometry/Tangent.cpp
- /library/Geometry/Tangent.cpp.html
title: Geometry/Tangent.cpp
---

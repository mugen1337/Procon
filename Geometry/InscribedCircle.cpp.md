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
  bundledCode: "#line 1 \"Geometry/InscribedCircle.cpp\"\n// \u5185\u63A5\u5186\n\
    Circle inscribed_circle(Point a,Point b,Point c){\n    Real A,B;\n    {\n    \
    \    Point t=c-a;\n        t*=conj(b-a);\n        t/=norm(b-a);\n        A=atan2(imag(t),real(t));\n\
    \    }\n    {\n        Point t=a-b;\n        t*=conj(c-b);\n        t/=norm(c-b);\n\
    \        B=atan2(imag(t),real(t));\n    }\n    Line Amid=Line(a,a+rotate(A*0.5,b-a)),Bmid=Line(b,b+rotate(B*0.5,c-b));\n\
    \    auto center=crosspoint(Amid,Bmid);\n    auto h=projection(Line(a,b),center);\n\
    \    return Circle(center,dis(h,center));\n}\n"
  code: "// \u5185\u63A5\u5186\nCircle inscribed_circle(Point a,Point b,Point c){\n\
    \    Real A,B;\n    {\n        Point t=c-a;\n        t*=conj(b-a);\n        t/=norm(b-a);\n\
    \        A=atan2(imag(t),real(t));\n    }\n    {\n        Point t=a-b;\n     \
    \   t*=conj(c-b);\n        t/=norm(c-b);\n        B=atan2(imag(t),real(t));\n\
    \    }\n    Line Amid=Line(a,a+rotate(A*0.5,b-a)),Bmid=Line(b,b+rotate(B*0.5,c-b));\n\
    \    auto center=crosspoint(Amid,Bmid);\n    auto h=projection(Line(a,b),center);\n\
    \    return Circle(center,dis(h,center));\n}"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/InscribedCircle.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-05-23 14:57:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/InscribedCircle.cpp
layout: document
redirect_from:
- /library/Geometry/InscribedCircle.cpp
- /library/Geometry/InscribedCircle.cpp.html
title: Geometry/InscribedCircle.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/include.hpp
    title: Geometry/include.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry/InscribedCircle.hpp\"\n// \u5185\u63A5\u5186\n\
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
  path: Geometry/InscribedCircle.hpp
  requiredBy:
  - Geometry/include.hpp
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/InscribedCircle.hpp
layout: document
redirect_from:
- /library/Geometry/InscribedCircle.hpp
- /library/Geometry/InscribedCircle.hpp.html
title: Geometry/InscribedCircle.hpp
---

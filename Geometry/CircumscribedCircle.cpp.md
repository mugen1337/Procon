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
  bundledCode: "#line 1 \"Geometry/CircumscribedCircle.cpp\"\n// \u5916\u63A5\u5186\
    \nCircle circumscribed_circle(Point a,Point b,Point c){\n    Line orth_ab((a+b)*0.5,(a+b)*0.5+Point(-imag(b-a),real(b-a)));\n\
    \    Line orth_bc((b+c)*0.5,(b+c)*0.5+Point(-imag(c-b),real(c-b)));\n    Point\
    \ center=crosspoint(orth_ab,orth_bc);\n    Real r=dis(a,center);\n    return Circle(center,r);\n\
    }\n"
  code: "// \u5916\u63A5\u5186\nCircle circumscribed_circle(Point a,Point b,Point\
    \ c){\n    Line orth_ab((a+b)*0.5,(a+b)*0.5+Point(-imag(b-a),real(b-a)));\n  \
    \  Line orth_bc((b+c)*0.5,(b+c)*0.5+Point(-imag(c-b),real(c-b)));\n    Point center=crosspoint(orth_ab,orth_bc);\n\
    \    Real r=dis(a,center);\n    return Circle(center,r);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/CircumscribedCircle.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-05-23 14:57:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/CircumscribedCircle.cpp
layout: document
redirect_from:
- /library/Geometry/CircumscribedCircle.cpp
- /library/Geometry/CircumscribedCircle.cpp.html
title: Geometry/CircumscribedCircle.cpp
---

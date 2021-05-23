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
  bundledCode: "#line 1 \"Geometry/Rotate.cpp\"\nPoint rotate(Real theta,Point p){\n\
    \    return Point(cos(theta)*real(p)-sin(theta)*imag(p),sin(theta)*real(p)+cos(theta)*imag(p));\n\
    }\n"
  code: "Point rotate(Real theta,Point p){\n    return Point(cos(theta)*real(p)-sin(theta)*imag(p),sin(theta)*real(p)+cos(theta)*imag(p));\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Rotate.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-05-23 14:57:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Rotate.cpp
layout: document
redirect_from:
- /library/Geometry/Rotate.cpp
- /library/Geometry/Rotate.cpp.html
title: Geometry/Rotate.cpp
---

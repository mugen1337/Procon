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
  bundledCode: "#line 1 \"Geometry/Rotate.hpp\"\nPoint rotate(Real theta,Point p){\n\
    \    return Point(cos(theta)*real(p)-sin(theta)*imag(p),sin(theta)*real(p)+cos(theta)*imag(p));\n\
    }\n"
  code: "Point rotate(Real theta,Point p){\n    return Point(cos(theta)*real(p)-sin(theta)*imag(p),sin(theta)*real(p)+cos(theta)*imag(p));\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Rotate.hpp
  requiredBy:
  - Geometry/include.hpp
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Rotate.hpp
layout: document
redirect_from:
- /library/Geometry/Rotate.hpp
- /library/Geometry/Rotate.hpp.html
title: Geometry/Rotate.hpp
---

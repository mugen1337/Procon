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
  bundledCode: "#line 1 \"Geometry/Angle.cpp\"\n// angle of a-b-c\nReal get_smaller_angle(Point\
    \ a,Point b,Point c){\n    Point v=b-a,w=c-b;\n    auto A=atan2(imag(v),real(v));\n\
    \    auto B=atan2(imag(w),real(w));\n    if(A>B) swap(A,B);\n    Real res=B-A;\n\
    \    return min(res,pi*2.0-res);\n}\n"
  code: "// angle of a-b-c\nReal get_smaller_angle(Point a,Point b,Point c){\n   \
    \ Point v=b-a,w=c-b;\n    auto A=atan2(imag(v),real(v));\n    auto B=atan2(imag(w),real(w));\n\
    \    if(A>B) swap(A,B);\n    Real res=B-A;\n    return min(res,pi*2.0-res);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Angle.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-05-23 14:57:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Angle.cpp
layout: document
redirect_from:
- /library/Geometry/Angle.cpp
- /library/Geometry/Angle.cpp.html
title: Geometry/Angle.cpp
---

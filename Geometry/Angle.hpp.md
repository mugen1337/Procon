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
  bundledCode: "#line 1 \"Geometry/Angle.hpp\"\n// angle of a-b-c\nReal get_smaller_angle(Point\
    \ a,Point b,Point c){\n    Point v=a-b,w=c-b;\n    auto A=atan2(imag(v),real(v));\n\
    \    auto B=atan2(imag(w),real(w));\n    if(A>B) swap(A,B);\n    Real res=B-A;\n\
    \    return min(res,pi*2.0-res);\n}\n"
  code: "// angle of a-b-c\nReal get_smaller_angle(Point a,Point b,Point c){\n   \
    \ Point v=a-b,w=c-b;\n    auto A=atan2(imag(v),real(v));\n    auto B=atan2(imag(w),real(w));\n\
    \    if(A>B) swap(A,B);\n    Real res=B-A;\n    return min(res,pi*2.0-res);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Angle.hpp
  requiredBy:
  - Geometry/include.hpp
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Angle.hpp
layout: document
redirect_from:
- /library/Geometry/Angle.hpp
- /library/Geometry/Angle.hpp.html
title: Geometry/Angle.hpp
---

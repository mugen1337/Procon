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
  bundledCode: "#line 1 \"Geometry/Contain.hpp\"\n// out 0, on 1, in 2\nint contains(Polygon\
    \ poly,Point p){\n    int res=0;\n    int n=(int)poly.size();\n    for(int i=0;i<n;i++){\n\
    \        Point a=poly[i]-p,b=poly[(i+1)%n]-p;\n        if(imag(a)>imag(b)) swap(a,b);\n\
    \        if(imag(a)<=0 and 0<imag(b) and cross(a,b)<0) res^=1;\n        if(eq(cross(a,b),0)\
    \ and (dot(a,b)<0 or eq(dot(a,b),0))) return 1;\n    }\n    if(res) res=2;\n \
    \   return res;\n}\n"
  code: "// out 0, on 1, in 2\nint contains(Polygon poly,Point p){\n    int res=0;\n\
    \    int n=(int)poly.size();\n    for(int i=0;i<n;i++){\n        Point a=poly[i]-p,b=poly[(i+1)%n]-p;\n\
    \        if(imag(a)>imag(b)) swap(a,b);\n        if(imag(a)<=0 and 0<imag(b) and\
    \ cross(a,b)<0) res^=1;\n        if(eq(cross(a,b),0) and (dot(a,b)<0 or eq(dot(a,b),0)))\
    \ return 1;\n    }\n    if(res) res=2;\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Contain.hpp
  requiredBy:
  - Geometry/include.hpp
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Contain.hpp
layout: document
redirect_from:
- /library/Geometry/Contain.hpp
- /library/Geometry/Contain.hpp.html
title: Geometry/Contain.hpp
---

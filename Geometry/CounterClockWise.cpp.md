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
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C
  bundledCode: "#line 1 \"Geometry/CounterClockWise.cpp\"\n// ccw (counter clockwise)\
    \ (Requires: cross, dot)\n//https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C\n\
    int ccw(Point a,Point b,Point c){\n   b-=a;c-=a;\n   if(cross(b,c)>EPS)      \
    \ return  1;//COUNTER CLOCKWISE\n   else if(cross(b,c)<-EPS) return -1;//CLOCKWISE\n\
    \   else if(dot(b,c)<0)      return  2;//c--a--b ONLINE BACK\n   else if(norm(b)<norm(c))\
    \ return -2;//a--b--c ONLINE FRONT\n   else                     return  0;//a--c--b\
    \ ON SEGMENT\n}\n"
  code: "// ccw (counter clockwise) (Requires: cross, dot)\n//https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C\n\
    int ccw(Point a,Point b,Point c){\n   b-=a;c-=a;\n   if(cross(b,c)>EPS)      \
    \ return  1;//COUNTER CLOCKWISE\n   else if(cross(b,c)<-EPS) return -1;//CLOCKWISE\n\
    \   else if(dot(b,c)<0)      return  2;//c--a--b ONLINE BACK\n   else if(norm(b)<norm(c))\
    \ return -2;//a--b--c ONLINE FRONT\n   else                     return  0;//a--c--b\
    \ ON SEGMENT\n}"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/CounterClockWise.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-03-29 03:23:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/CounterClockWise.cpp
layout: document
redirect_from:
- /library/Geometry/CounterClockWise.cpp
- /library/Geometry/CounterClockWise.cpp.html
title: Geometry/CounterClockWise.cpp
---

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
  bundledCode: "#line 1 \"Geometry/Projection.cpp\"\n// Projection (Requires: dot)\n\
    Point projection(Line l,Point p){\n    // \u30D9\u30AF\u30C8\u30EBl\u4E57\u306B\
    \u70B9p\u304B\u3089\u304A\u308D\u3057\u305F\u5782\u7DDA\u306E\u8DB3\n    Real\
    \ k=dot(l.p1-l.p2,p-l.p1)/norm(l.p1-l.p2);\n    return l.p1+(l.p1-l.p2)*k;\n}\n\
    Point projection(Segment l,Point p){\n    Real k=dot(l.p1-l.p2,p-l.p1)/norm(l.p1-l.p2);\n\
    \    return l.p1+(l.p1-l.p2)*k;\n}\n"
  code: "// Projection (Requires: dot)\nPoint projection(Line l,Point p){\n    //\
    \ \u30D9\u30AF\u30C8\u30EBl\u4E57\u306B\u70B9p\u304B\u3089\u304A\u308D\u3057\u305F\
    \u5782\u7DDA\u306E\u8DB3\n    Real k=dot(l.p1-l.p2,p-l.p1)/norm(l.p1-l.p2);\n\
    \    return l.p1+(l.p1-l.p2)*k;\n}\nPoint projection(Segment l,Point p){\n   \
    \ Real k=dot(l.p1-l.p2,p-l.p1)/norm(l.p1-l.p2);\n    return l.p1+(l.p1-l.p2)*k;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Projection.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-03-29 03:23:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Projection.cpp
layout: document
redirect_from:
- /library/Geometry/Projection.cpp
- /library/Geometry/Projection.cpp.html
title: Geometry/Projection.cpp
---

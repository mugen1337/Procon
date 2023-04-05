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
  bundledCode: "#line 1 \"Geometry/Projection.hpp\"\n// Projection (Requires: dot)\n\
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
  path: Geometry/Projection.hpp
  requiredBy:
  - Geometry/include.hpp
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Projection.hpp
layout: document
redirect_from:
- /library/Geometry/Projection.hpp
- /library/Geometry/Projection.hpp.html
title: Geometry/Projection.hpp
---

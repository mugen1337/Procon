---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tips/CountSubpermutation.cpp
    title: tips/CountSubpermutation.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Other/RandomNumberGenerator.cpp\"\nstruct RandomNumberGenerator{\n\
    \    mt19937 mt;\n    RandomNumberGenerator():mt(chrono::steady_clock::now().time_since_epoch().count()){}\n\
    \    // [a,b)\n    int operator()(int a,int b){\n        uniform_int_distribution<int>\
    \ d(a,b-1);\n        return d(mt);\n    }\n};\n"
  code: "struct RandomNumberGenerator{\n    mt19937 mt;\n    RandomNumberGenerator():mt(chrono::steady_clock::now().time_since_epoch().count()){}\n\
    \    // [a,b)\n    int operator()(int a,int b){\n        uniform_int_distribution<int>\
    \ d(a,b-1);\n        return d(mt);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Other/RandomNumberGenerator.cpp
  requiredBy:
  - tips/CountSubpermutation.cpp
  timestamp: '2021-01-11 03:22:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Other/RandomNumberGenerator.cpp
layout: document
redirect_from:
- /library/Other/RandomNumberGenerator.cpp
- /library/Other/RandomNumberGenerator.cpp.html
title: Other/RandomNumberGenerator.cpp
---

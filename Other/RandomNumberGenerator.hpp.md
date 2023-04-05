---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tips/CountSubpermutation.hpp
    title: "\u9806\u5217\u3067\u3042\u308B\u9023\u7D9A\u90E8\u5206\u5217\u306E\u6570\
      \u3048\u4E0A\u3052"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Other/RandomNumberGenerator.hpp\"\nstruct RandomNumberGenerator{\n\
    \    mt19937 mt;\n    RandomNumberGenerator():mt(chrono::steady_clock::now().time_since_epoch().count()){}\n\
    \    // [a,b)\n    int operator()(int a,int b){\n        uniform_int_distribution<int>\
    \ d(a,b-1);\n        return d(mt);\n    }\n};\n"
  code: "struct RandomNumberGenerator{\n    mt19937 mt;\n    RandomNumberGenerator():mt(chrono::steady_clock::now().time_since_epoch().count()){}\n\
    \    // [a,b)\n    int operator()(int a,int b){\n        uniform_int_distribution<int>\
    \ d(a,b-1);\n        return d(mt);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Other/RandomNumberGenerator.hpp
  requiredBy:
  - tips/CountSubpermutation.hpp
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Other/RandomNumberGenerator.hpp
layout: document
redirect_from:
- /library/Other/RandomNumberGenerator.hpp
- /library/Other/RandomNumberGenerator.hpp.html
title: Other/RandomNumberGenerator.hpp
---

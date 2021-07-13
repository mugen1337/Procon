---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Other/EnumerateCombination.cpp\"\nvector<int> enumerate_combination(int\
    \ n, int k){\n    int comb = (1<<k) - 1;\n    vector<int> ret;\n    while(comb\
    \ < (1<<n)){\n        ret.push_back(comb);\n        int x = comb & (-comb),y =\
    \ comb + x;\n        comb = ((comb&~y) / x>>1) | y;\n    }\n    return ret;\n\
    }\n"
  code: "vector<int> enumerate_combination(int n, int k){\n    int comb = (1<<k) -\
    \ 1;\n    vector<int> ret;\n    while(comb < (1<<n)){\n        ret.push_back(comb);\n\
    \        int x = comb & (-comb),y = comb + x;\n        comb = ((comb&~y) / x>>1)\
    \ | y;\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Other/EnumerateCombination.cpp
  requiredBy: []
  timestamp: '2021-07-12 17:11:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Other/EnumerateCombination.cpp
layout: document
redirect_from:
- /library/Other/EnumerateCombination.cpp
- /library/Other/EnumerateCombination.cpp.html
title: Other/EnumerateCombination.cpp
---

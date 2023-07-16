---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki2855.test.cpp
    title: test/yuki2855.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Sieve.hpp\"\nvector<bool> sieve(int n){\n    vector<bool>\
    \ ret(n+1,true);\n    ret[0]=false;\n    if(n>0) ret[1]=false;\n    for(int i=2;i*i<=n;i++){\n\
    \        if(!ret[i]) continue;\n        for(int j=i*2;j<=n;j+=i) ret[j]=false;\n\
    \    }\n    return ret;\n}\n"
  code: "vector<bool> sieve(int n){\n    vector<bool> ret(n+1,true);\n    ret[0]=false;\n\
    \    if(n>0) ret[1]=false;\n    for(int i=2;i*i<=n;i++){\n        if(!ret[i])\
    \ continue;\n        for(int j=i*2;j<=n;j+=i) ret[j]=false;\n    }\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Sieve.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki2855.test.cpp
documentation_of: Math/Sieve.hpp
layout: document
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---

## 概要  
エラトステネスの篩です

O(nloglogn)  

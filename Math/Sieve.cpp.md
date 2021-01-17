---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki2855.test.cpp
    title: test/yuki2855.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Sieve.cpp\"\nvector<bool> sieve(int n){\n    vector<bool>\
    \ ret(n+1,true);\n    ret[0]=false;\n    if(n>0) ret[1]=false;\n    for(int i=2;i*i<=n;i++){\n\
    \        if(!ret[i]) continue;\n        for(int j=i*2;j<=n;j+=i) ret[j]=false;\n\
    \    }\n    return ret;\n}\n"
  code: "vector<bool> sieve(int n){\n    vector<bool> ret(n+1,true);\n    ret[0]=false;\n\
    \    if(n>0) ret[1]=false;\n    for(int i=2;i*i<=n;i++){\n        if(!ret[i])\
    \ continue;\n        for(int j=i*2;j<=n;j+=i) ret[j]=false;\n    }\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Sieve.cpp
  requiredBy: []
  timestamp: '2021-01-17 15:20:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki2855.test.cpp
documentation_of: Math/Sieve.cpp
layout: document
redirect_from:
- /library/Math/Sieve.cpp
- /library/Math/Sieve.cpp.html
title: Math/Sieve.cpp
---

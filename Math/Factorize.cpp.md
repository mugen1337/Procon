---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_NTL_1_A.test.cpp
    title: test/AOJ_NTL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Factorize.cpp\"\ntemplate<typename INT>\nvector<INT>\
    \ Factorize(INT x){\n    vector<INT> ret;\n    for(INT i=2;i*i<=x;i++){\n    \
    \    while(x%i==0){\n            ret.push_back(i);\n            x/=i;\n      \
    \  }\n    }\n    if(x!=1) ret.push_back(x);\n    sort(begin(ret),end(ret));\n\
    \    return ret;\n}\n"
  code: "template<typename INT>\nvector<INT> Factorize(INT x){\n    vector<INT> ret;\n\
    \    for(INT i=2;i*i<=x;i++){\n        while(x%i==0){\n            ret.push_back(i);\n\
    \            x/=i;\n        }\n    }\n    if(x!=1) ret.push_back(x);\n    sort(begin(ret),end(ret));\n\
    \    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Factorize.cpp
  requiredBy: []
  timestamp: '2021-01-24 01:54:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_NTL_1_A.test.cpp
documentation_of: Math/Factorize.cpp
layout: document
redirect_from:
- /library/Math/Factorize.cpp
- /library/Math/Factorize.cpp.html
title: Math/Factorize.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ_NTL_1_A.test.cpp
    title: test/AOJ_NTL_1_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Factorize.hpp\"\ntemplate<typename INT>\nvector<INT>\
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
  path: Math/Factorize.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ_NTL_1_A.test.cpp
documentation_of: Math/Factorize.hpp
layout: document
redirect_from:
- /library/Math/Factorize.hpp
- /library/Math/Factorize.hpp.html
title: Math/Factorize.hpp
---

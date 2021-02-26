---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/log_mod.cpp
    title: "\u96E2\u6563\u5BFE\u6570 (log mod)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_DiscreteLog.test.cpp
    title: test/yosupo_DiscreteLog.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/inv_mod.cpp\"\nll inv_mod(ll a,ll m){\n    ll b=m,u=1,v=0,t;\n\
    \    while(b){\n        t=a/b;\n        swap(a-=t*b,b);swap(u-=t*v,v);\n    }\n\
    \    u%=m;\n    if(u<0) u+=m;\n    return u;\n}\n"
  code: "ll inv_mod(ll a,ll m){\n    ll b=m,u=1,v=0,t;\n    while(b){\n        t=a/b;\n\
    \        swap(a-=t*b,b);swap(u-=t*v,v);\n    }\n    u%=m;\n    if(u<0) u+=m;\n\
    \    return u;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/inv_mod.cpp
  requiredBy:
  - Math/log_mod.cpp
  timestamp: '2021-02-27 00:20:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_DiscreteLog.test.cpp
documentation_of: Math/inv_mod.cpp
layout: document
redirect_from:
- /library/Math/inv_mod.cpp
- /library/Math/inv_mod.cpp.html
title: Math/inv_mod.cpp
---

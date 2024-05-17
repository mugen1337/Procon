---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Math/log_mod.hpp
    title: "\u96E2\u6563\u5BFE\u6570 (log mod)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_DiscreteLog.test.cpp
    title: test/yosupo_DiscreteLog.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/inv_mod.hpp\"\nll inv_mod(ll a,ll m){\n    ll b=m,u=1,v=0,t;\n\
    \    while(b){\n        t=a/b;\n        swap(a-=t*b,b);swap(u-=t*v,v);\n    }\n\
    \    u%=m;\n    if(u<0) u+=m;\n    return u;\n}\n"
  code: "ll inv_mod(ll a,ll m){\n    ll b=m,u=1,v=0,t;\n    while(b){\n        t=a/b;\n\
    \        swap(a-=t*b,b);swap(u-=t*v,v);\n    }\n    u%=m;\n    if(u<0) u+=m;\n\
    \    return u;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/inv_mod.hpp
  requiredBy:
  - Math/log_mod.hpp
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_DiscreteLog.test.cpp
documentation_of: Math/inv_mod.hpp
layout: document
redirect_from:
- /library/Math/inv_mod.hpp
- /library/Math/inv_mod.hpp.html
title: Math/inv_mod.hpp
---

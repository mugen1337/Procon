---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/log_mod.hpp
    title: "\u96E2\u6563\u5BFE\u6570 (log mod)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_DiscreteLog.test.cpp
    title: test/yosupo_DiscreteLog.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/pow_mod.hpp\"\n// a^n (mod m)\nll pow_mod(ll a,ll n,ll\
    \ m){\n    ll ret=1;\n    while(n){\n        if(n&1) ret=ret*a%m;\n        a=(a*a)%m;\n\
    \        n/=2;\n    }\n    return ret;\n}\n"
  code: "// a^n (mod m)\nll pow_mod(ll a,ll n,ll m){\n    ll ret=1;\n    while(n){\n\
    \        if(n&1) ret=ret*a%m;\n        a=(a*a)%m;\n        n/=2;\n    }\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/pow_mod.hpp
  requiredBy:
  - Math/log_mod.hpp
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_DiscreteLog.test.cpp
documentation_of: Math/pow_mod.hpp
layout: document
redirect_from:
- /library/Math/pow_mod.hpp
- /library/Math/pow_mod.hpp.html
title: Math/pow_mod.hpp
---

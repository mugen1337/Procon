---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/pow_mod.cpp\"\n// a^n (mod m)\nll pow_mod(ll a,ll n,ll\
    \ m){\n    ll ret=1;\n    while(n){\n        if(n&1) ret=ret*a%m;\n        a=(a*a)%m;\n\
    \        n/=2;\n    }\n    return ret;\n}\n"
  code: "// a^n (mod m)\nll pow_mod(ll a,ll n,ll m){\n    ll ret=1;\n    while(n){\n\
    \        if(n&1) ret=ret*a%m;\n        a=(a*a)%m;\n        n/=2;\n    }\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/pow_mod.cpp
  requiredBy: []
  timestamp: '2021-01-16 20:39:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/pow_mod.cpp
layout: document
redirect_from:
- /library/Math/pow_mod.cpp
- /library/Math/pow_mod.cpp.html
title: Math/pow_mod.cpp
---

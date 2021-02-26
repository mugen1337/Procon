---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/inv_mod.cpp
    title: Math/inv_mod.cpp
  - icon: ':heavy_check_mark:'
    path: Math/pow_mod.cpp
    title: Math/pow_mod.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_DiscreteLog.test.cpp
    title: test/yosupo_DiscreteLog.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/suisen_cp/items/d597c8ec576ae32ee2d7
  bundledCode: "#line 1 \"Math/inv_mod.cpp\"\nll inv_mod(ll a,ll m){\n    ll b=m,u=1,v=0,t;\n\
    \    while(b){\n        t=a/b;\n        swap(a-=t*b,b);swap(u-=t*v,v);\n    }\n\
    \    u%=m;\n    if(u<0) u+=m;\n    return u;\n}\n#line 1 \"Math/pow_mod.cpp\"\n\
    // a^n (mod m)\nll pow_mod(ll a,ll n,ll m){\n    ll ret=1;\n    while(n){\n  \
    \      if(n&1) ret=ret*a%m;\n        a=(a*a)%m;\n        n/=2;\n    }\n    return\
    \ ret;\n}\n#line 3 \"Math/log_mod.cpp\"\n\n// https://qiita.com/suisen_cp/items/d597c8ec576ae32ee2d7\n\
    // \u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570x\u3092\u8FD4\u3059\n// a ^ x = b\
    \ mod m\nll log_mod(ll a,ll b,ll m){\n    auto BSGS=[](ll a,ll b,ll m){\n    \
    \    ll sq_m=sqrt(m)+1;\n\n        // baby-step\n        unordered_map<ll,ll>\
    \ bs;\n        ll bab=1;\n        for(int i=0;i<sq_m;i++,bab=bab*a%m)if(!bs.count(bab))\
    \ bs[bab]=i;\n\n        // giant-step\n        ll a_m=pow_mod(inv_mod(a,m),sq_m,m);\n\
    \        ll gia=b;\n        for(int i=0;i<=sq_m;i++,gia=gia*a_m%m)if(bs.count(gia))\
    \ return sq_m*i+bs[gia];\n        return -1ll;\n    };\n\n    function<ll(ll,ll,ll)>\
    \ decomp_BSGS=[&decomp_BSGS, &BSGS](ll a,ll b,ll m){\n        a%=m,b%=m;\n   \
    \     \n        if(m==1) return 0ll;\n        if(b==1) return 0ll;\n\n       \
    \ ll g=gcd(a,m);\n        if(g==1) return BSGS(a,b,m);\n\n        if(b%g) return\
    \ -1ll;\n        m/=g;\n        b=(b/g)*inv_mod(a/g,m);\n        ll res=decomp_BSGS(a,b,m);\n\
    \        if(res<0) return -1ll;\n        return res+1;\n    };\n    return decomp_BSGS(a,b,m);\n\
    }\n"
  code: "#include \"./inv_mod.cpp\"\n#include \"./pow_mod.cpp\"\n\n// https://qiita.com/suisen_cp/items/d597c8ec576ae32ee2d7\n\
    // \u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570x\u3092\u8FD4\u3059\n// a ^ x = b\
    \ mod m\nll log_mod(ll a,ll b,ll m){\n    auto BSGS=[](ll a,ll b,ll m){\n    \
    \    ll sq_m=sqrt(m)+1;\n\n        // baby-step\n        unordered_map<ll,ll>\
    \ bs;\n        ll bab=1;\n        for(int i=0;i<sq_m;i++,bab=bab*a%m)if(!bs.count(bab))\
    \ bs[bab]=i;\n\n        // giant-step\n        ll a_m=pow_mod(inv_mod(a,m),sq_m,m);\n\
    \        ll gia=b;\n        for(int i=0;i<=sq_m;i++,gia=gia*a_m%m)if(bs.count(gia))\
    \ return sq_m*i+bs[gia];\n        return -1ll;\n    };\n\n    function<ll(ll,ll,ll)>\
    \ decomp_BSGS=[&decomp_BSGS, &BSGS](ll a,ll b,ll m){\n        a%=m,b%=m;\n   \
    \     \n        if(m==1) return 0ll;\n        if(b==1) return 0ll;\n\n       \
    \ ll g=gcd(a,m);\n        if(g==1) return BSGS(a,b,m);\n\n        if(b%g) return\
    \ -1ll;\n        m/=g;\n        b=(b/g)*inv_mod(a/g,m);\n        ll res=decomp_BSGS(a,b,m);\n\
    \        if(res<0) return -1ll;\n        return res+1;\n    };\n    return decomp_BSGS(a,b,m);\n\
    }"
  dependsOn:
  - Math/inv_mod.cpp
  - Math/pow_mod.cpp
  isVerificationFile: false
  path: Math/log_mod.cpp
  requiredBy: []
  timestamp: '2021-02-27 00:20:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_DiscreteLog.test.cpp
documentation_of: Math/log_mod.cpp
layout: document
redirect_from:
- /library/Math/log_mod.cpp
- /library/Math/log_mod.cpp.html
title: Math/log_mod.cpp
---

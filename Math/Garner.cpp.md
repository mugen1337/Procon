---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yuki447.test.cpp
    title: test/yuki447.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Garner.cpp\"\n// (val, mod)\npair<ll,ll> Garner(const\
    \ vector<ll> &rems,const vector<ll> &mods){\n    // {g, x}, g=gcd(a,b), xa = g\
    \ (mod b)\n    function<pair<ll,ll>(ll,ll)> gcd_inv=[](ll a,ll b){\n        a%=b;\n\
    \        if(a<0) a+=b;\n        if(a==0) return make_pair(b,0ll);\n        ll\
    \ s=b,t=a,m0=0,m1=1;\n        while(t){\n            ll u=s/t;\n            s-=t*u,m0-=m1*u;\n\
    \            swap(s,t);\n            swap(m0,m1);\n        }\n        if(m0<0)\
    \ m0+=b/s;\n        return make_pair(s,m0);\n    };\n\n    ll R=0,M=1;\n    for(int\
    \ i=0;i<(int)rems.size();i++){\n        ll r=rems[i],m=mods[i];\n        r%=m;if(r<0)\
    \ r+=m;\n        if(m>M) swap(m,M),swap(r,R);\n        if(M%m==0){\n         \
    \   if(R%m!=r) return {0,0};\n            continue;\n        }\n        auto [g,iM]=gcd_inv(M,m);\n\
    \        ll u=m/g;\n        if((r-R)%g) return {0,0};\n        ll x=(r-R)/g%u*iM%u;\n\
    \        R+=x*M;\n        M*=u;\n        if(R<0) R+=M;\n    }\n    return {R,M};\n\
    }\n"
  code: "// (val, mod)\npair<ll,ll> Garner(const vector<ll> &rems,const vector<ll>\
    \ &mods){\n    // {g, x}, g=gcd(a,b), xa = g (mod b)\n    function<pair<ll,ll>(ll,ll)>\
    \ gcd_inv=[](ll a,ll b){\n        a%=b;\n        if(a<0) a+=b;\n        if(a==0)\
    \ return make_pair(b,0ll);\n        ll s=b,t=a,m0=0,m1=1;\n        while(t){\n\
    \            ll u=s/t;\n            s-=t*u,m0-=m1*u;\n            swap(s,t);\n\
    \            swap(m0,m1);\n        }\n        if(m0<0) m0+=b/s;\n        return\
    \ make_pair(s,m0);\n    };\n\n    ll R=0,M=1;\n    for(int i=0;i<(int)rems.size();i++){\n\
    \        ll r=rems[i],m=mods[i];\n        r%=m;if(r<0) r+=m;\n        if(m>M)\
    \ swap(m,M),swap(r,R);\n        if(M%m==0){\n            if(R%m!=r) return {0,0};\n\
    \            continue;\n        }\n        auto [g,iM]=gcd_inv(M,m);\n       \
    \ ll u=m/g;\n        if((r-R)%g) return {0,0};\n        ll x=(r-R)/g%u*iM%u;\n\
    \        R+=x*M;\n        M*=u;\n        if(R<0) R+=M;\n    }\n    return {R,M};\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Math/Garner.cpp
  requiredBy: []
  timestamp: '2021-03-02 23:29:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yuki447.test.cpp
documentation_of: Math/Garner.cpp
layout: document
redirect_from:
- /library/Math/Garner.cpp
- /library/Math/Garner.cpp.html
title: Math/Garner.cpp
---

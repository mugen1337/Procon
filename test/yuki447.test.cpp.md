---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/Garner.hpp
    title: "Garner (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)"
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/447
    links:
    - https://yukicoder.me/problems/447
  bundledCode: "#line 1 \"test/yuki447.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/447\"\
    \n\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int i=0;i<(n);i++)\n#define\
    \ debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n#define mod\
    \ 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\n\
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \nstruct IOSetup{\n    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n\
    \        cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/yuki447.test.cpp\"\n\n#line 1 \"Math/Garner.hpp\"\
    \n// (val, mod)\npair<ll,ll> Garner(const vector<ll> &rems,const vector<ll> &mods){\n\
    \    // {g, x}, g=gcd(a,b), xa = g (mod b)\n    function<pair<ll,ll>(ll,ll)> gcd_inv=[](ll\
    \ a,ll b){\n        a%=b;\n        if(a<0) a+=b;\n        if(a==0) return make_pair(b,0ll);\n\
    \        ll s=b,t=a,m0=0,m1=1;\n        while(t){\n            ll u=s/t;\n   \
    \         s-=t*u,m0-=m1*u;\n            swap(s,t);\n            swap(m0,m1);\n\
    \        }\n        if(m0<0) m0+=b/s;\n        return make_pair(s,m0);\n    };\n\
    \n    ll R=0,M=1;\n    for(int i=0;i<(int)rems.size();i++){\n        ll r=rems[i],m=mods[i];\n\
    \        r%=m;if(r<0) r+=m;\n        if(m>M) swap(m,M),swap(r,R);\n        if(M%m==0){\n\
    \            if(R%m!=r) return {0,0};\n            continue;\n        }\n    \
    \    auto [g,iM]=gcd_inv(M,m);\n        ll u=m/g;\n        if((r-R)%g) return\
    \ {0,0};\n        ll x=(r-R)/g%u*iM%u;\n        R+=x*M;\n        M*=u;\n     \
    \   if(R<0) R+=M;\n    }\n    return {R,M};\n}\n#line 6 \"test/yuki447.test.cpp\"\
    \n\nsigned main(){\n\n    vector<ll> r(3),m(3);\n    rep(i,3) cin>>r[i]>>m[i];\n\
    \n    auto p=Garner(r,m);\n    if(p.second==0) cout<<-1<<endl;\n    else if(p.first==0)\
    \ cout<<p.second<<endl;\n    else cout<<p.first<<endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/447\"\n\n#include \"../template.hpp\"\
    \n\n#include \"../Math/Garner.hpp\"\n\nsigned main(){\n\n    vector<ll> r(3),m(3);\n\
    \    rep(i,3) cin>>r[i]>>m[i];\n\n    auto p=Garner(r,m);\n    if(p.second==0)\
    \ cout<<-1<<endl;\n    else if(p.first==0) cout<<p.second<<endl;\n    else cout<<p.first<<endl;\n\
    \    return 0;\n}\n"
  dependsOn:
  - template.hpp
  - Math/Garner.hpp
  isVerificationFile: true
  path: test/yuki447.test.cpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yuki447.test.cpp
layout: document
redirect_from:
- /verify/test/yuki447.test.cpp
- /verify/test/yuki447.test.cpp.html
title: test/yuki447.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/inv_mod.hpp
    title: Math/inv_mod.hpp
  - icon: ':heavy_check_mark:'
    path: Math/log_mod.hpp
    title: "\u96E2\u6563\u5BFE\u6570 (log mod)"
  - icon: ':heavy_check_mark:'
    path: Math/pow_mod.hpp
    title: Math/pow_mod.hpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/yosupo_DiscreteLog.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#line 1 \"bits/stdc++.h\"\n// C\n#ifndef _GLIBCXX_NO_ASSERT\n#include <cassert>\n\
    #endif\n#include <cctype>\n#include <cerrno>\n#include <cfloat>\n#include <ciso646>\n\
    #include <climits>\n#include <clocale>\n#include <cmath>\n#include <csetjmp>\n\
    #include <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <ctime>\n\n#if __cplusplus >=\
    \ 201103L\n#include <ccomplex>\n#include <cfenv>\n#include <cinttypes>\n#include\
    \ <cstdalign>\n#include <cstdbool>\n#include <cstdint>\n#include <ctgmath>\n#include\
    \ <cwchar>\n#include <cwctype>\n#endif\n\n// C++\n#include <algorithm>\n#include\
    \ <bitset>\n#include <complex>\n#include <deque>\n#include <exception>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <ios>\n#include\
    \ <iosfwd>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <locale>\n#include <map>\n#include <memory>\n\
    #include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <typeinfo>\n#include <utility>\n#include\
    \ <valarray>\n#include <vector>\n\n#if __cplusplus >= 201103L\n#include <array>\n\
    #include <atomic>\n#include <chrono>\n#include <condition_variable>\n#include\
    \ <forward_list>\n#include <future>\n#include <initializer_list>\n#include <mutex>\n\
    #include <random>\n#include <ratio>\n#include <regex>\n#include <scoped_allocator>\n\
    #include <system_error>\n#include <thread>\n#include <tuple>\n#include <typeindex>\n\
    #include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n#endif\n\
    #line 2 \"template.hpp\"\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto\
    \ x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\nusing ll=long long;\n\
    const int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n\
    // ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\ntemplate<class T>bool chmax(T &a,const\
    \ T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool chmin(T\
    \ &a,const T &b){if(b<a){a=b;return true;}return false;}\n\nstruct IOSetup{\n\
    \    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n     \
    \   cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename T>\n\
    ostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/yosupo_DiscreteLog.test.cpp\"\n\n#line 1 \"\
    Math/inv_mod.hpp\"\nll inv_mod(ll a,ll m){\n    ll b=m,u=1,v=0,t;\n    while(b){\n\
    \        t=a/b;\n        swap(a-=t*b,b);swap(u-=t*v,v);\n    }\n    u%=m;\n  \
    \  if(u<0) u+=m;\n    return u;\n}\n#line 1 \"Math/pow_mod.hpp\"\n// a^n (mod\
    \ m)\nll pow_mod(ll a,ll n,ll m){\n    ll ret=1;\n    while(n){\n        if(n&1)\
    \ ret=ret*a%m;\n        a=(a*a)%m;\n        n/=2;\n    }\n    return ret;\n}\n\
    #line 3 \"Math/log_mod.hpp\"\n\n// https://qiita.com/suisen_cp/items/d597c8ec576ae32ee2d7\n\
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
    }\n#line 6 \"test/yosupo_DiscreteLog.test.cpp\"\n\nvoid solve(){\n    ll a,b,m;cin>>a>>b>>m;\n\
    \    ll k=log_mod(a,b,m);\n    cout<<k<<endl;\n    // cout<<\"a^res \"<<pow_mod(a,k,m)<<\"\
    \ =? \"<<b<<endl;\n}\n\nsigned main(){\n    int q;cin>>q;\n    while(q--) solve();\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include \"./template.hpp\"\n\n#include \"../Math/log_mod.hpp\"\n\nvoid solve(){\n\
    \    ll a,b,m;cin>>a>>b>>m;\n    ll k=log_mod(a,b,m);\n    cout<<k<<endl;\n  \
    \  // cout<<\"a^res \"<<pow_mod(a,k,m)<<\" =? \"<<b<<endl;\n}\n\nsigned main(){\n\
    \    int q;cin>>q;\n    while(q--) solve();\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - bits/stdc++.h
  - Math/log_mod.hpp
  - Math/inv_mod.hpp
  - Math/pow_mod.hpp
  isVerificationFile: true
  path: test/yosupo_DiscreteLog.test.cpp
  requiredBy: []
  timestamp: '2024-05-15 18:03:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_DiscreteLog.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_DiscreteLog.test.cpp
- /verify/test/yosupo_DiscreteLog.test.cpp.html
title: test/yosupo_DiscreteLog.test.cpp
---

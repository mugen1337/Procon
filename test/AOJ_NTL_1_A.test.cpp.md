---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Factorize.hpp
    title: Math/Factorize.hpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=jp
  bundledCode: "#line 1 \"test/AOJ_NTL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=jp\"\
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
    \   return is;\n}\n\n#line 4 \"test/AOJ_NTL_1_A.test.cpp\"\n\n#line 1 \"Math/Factorize.hpp\"\
    \ntemplate<typename INT>\nvector<INT> Factorize(INT x){\n    vector<INT> ret;\n\
    \    for(INT i=2;i*i<=x;i++){\n        while(x%i==0){\n            ret.push_back(i);\n\
    \            x/=i;\n        }\n    }\n    if(x!=1) ret.push_back(x);\n    sort(begin(ret),end(ret));\n\
    \    return ret;\n}\n#line 6 \"test/AOJ_NTL_1_A.test.cpp\"\n\nsigned main(){\n\
    \    ll x;cin>>x;\n    cout<<x<<\": \"<<Factorize(x)<<endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=jp\"\
    \n\n#include \"../template.hpp\"\n\n#include \"../Math/Factorize.hpp\"\n\nsigned\
    \ main(){\n    ll x;cin>>x;\n    cout<<x<<\": \"<<Factorize(x)<<endl;\n    return\
    \ 0;\n}\n"
  dependsOn:
  - template.hpp
  - Math/Factorize.hpp
  isVerificationFile: true
  path: test/AOJ_NTL_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ_NTL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_NTL_1_A.test.cpp
- /verify/test/AOJ_NTL_1_A.test.cpp.html
title: test/AOJ_NTL_1_A.test.cpp
---

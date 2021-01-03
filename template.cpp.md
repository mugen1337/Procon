---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_2292.test.cpp
    title: test/AOJ_2292.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DSL_1_B.test.cpp
    title: test/AOJ_DSL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
    title: test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Point-Add-Range-Sum.test.cpp
    title: test/yosupo_Point-Add-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp
    title: test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Unionfind.test.cpp
    title: test/yosupo_Unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Unionfind_undo.test.cpp
    title: test/yosupo_Unionfind_undo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_scc.test.cpp
    title: test/yosupo_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki1601.test.cpp
    title: test/yuki1601.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int i=0;i<(n);i++)\n\
    #define debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n#define\
    \ mod 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\n\
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \nstruct IOSetup{\n    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n\
    \        cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
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
    \   return is;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: template.cpp
  requiredBy: []
  timestamp: '2021-01-03 23:01:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp
  - test/yosupo_Unionfind_undo.test.cpp
  - test/yosupo_scc.test.cpp
  - test/AOJ_2292.test.cpp
  - test/yosupo_Point-Add-Range-Sum.test.cpp
  - test/yuki1601.test.cpp
  - test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - test/yosupo_Unionfind.test.cpp
  - test/AOJ_DSL_1_B.test.cpp
documentation_of: template.cpp
layout: document
redirect_from:
- /library/template.cpp
- /library/template.cpp.html
title: template.cpp
---

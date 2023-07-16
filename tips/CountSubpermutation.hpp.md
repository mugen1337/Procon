---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Other/RandomNumberGenerator.hpp
    title: Other/RandomNumberGenerator.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/1175/F
  bundledCode: "#line 1 \"tips/CountSubpermutation.hpp\"\n// https://codeforces.com/problemset/problem/1175/F\n\
    \n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ ALL(x) begin(x),end(x)\n#define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v)\
    \ cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\n\
    using ll=long long;\nconst int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\n\
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \nstruct IOSetup{\n    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n\
    \        cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"tips/CountSubpermutation.hpp\"\n\n#line 1 \"Other/RandomNumberGenerator.hpp\"\
    \nstruct RandomNumberGenerator{\n    mt19937 mt;\n    RandomNumberGenerator():mt(chrono::steady_clock::now().time_since_epoch().count()){}\n\
    \    // [a,b)\n    int operator()(int a,int b){\n        uniform_int_distribution<int>\
    \ d(a,b-1);\n        return d(mt);\n    }\n};\n#line 6 \"tips/CountSubpermutation.hpp\"\
    \n\n// 1-indexed permutation\nll Subpermutations(vector<int> v){\n    int n=(int)v.size();\n\
    \n    RandomNumberGenerator rng;\n    vector<ll> hash(n+1),hash_s(n+2,0);\n  \
    \  for(int i=1;i<=n;i++){\n        hash[i]=rng(0,1<<31);\n        hash_s[i]=hash_s[i-1]^hash[i];\n\
    \    }\n    ll res=0;\n    // 1\u306E\u53F3\u306B\u6700\u5927\u5024\u304C\u3042\
    \u308B\u5834\u5408, 1\u306E\u5DE6\u306B\u6700\u5927\u5024\u304C\u3042\u308B\u5834\
    \u5408\u3067\u89E3\u304F\n    rep(_,2){\n        vector<ll> hash_vs(n+1,0);\n\
    \        rep(i,n){\n            hash_vs[i+1]=hash_vs[i]^hash[v[i]];\n        }\n\
    \n        rep(i,n)if(v[i]==1){\n            if(_) res++;\n            int mx=0;\n\
    \            for(int j=i+1;j<n;j++){\n                if(v[j]==1) break;\n   \
    \             chmax(mx,v[j]);\n                if(j+1-mx>=0 and ((hash_vs[j+1]^hash_vs[j+1-mx])==hash_s[mx]))\
    \ res++;\n            }\n        }\n        reverse(ALL(v));\n    }\n\n    return\
    \ res;\n}\n\nsigned main(){\n    int n;cin>>n;\n    vector<int> a(n);\n    cin>>a;\n\
    \    cout<<Subpermutations(a)<<endl;\n    return 0;\n}\n"
  code: "// https://codeforces.com/problemset/problem/1175/F\n\n#include \"../template.hpp\"\
    \n\n#include \"../Other/RandomNumberGenerator.hpp\"\n\n// 1-indexed permutation\n\
    ll Subpermutations(vector<int> v){\n    int n=(int)v.size();\n\n    RandomNumberGenerator\
    \ rng;\n    vector<ll> hash(n+1),hash_s(n+2,0);\n    for(int i=1;i<=n;i++){\n\
    \        hash[i]=rng(0,1<<31);\n        hash_s[i]=hash_s[i-1]^hash[i];\n    }\n\
    \    ll res=0;\n    // 1\u306E\u53F3\u306B\u6700\u5927\u5024\u304C\u3042\u308B\
    \u5834\u5408, 1\u306E\u5DE6\u306B\u6700\u5927\u5024\u304C\u3042\u308B\u5834\u5408\
    \u3067\u89E3\u304F\n    rep(_,2){\n        vector<ll> hash_vs(n+1,0);\n      \
    \  rep(i,n){\n            hash_vs[i+1]=hash_vs[i]^hash[v[i]];\n        }\n\n \
    \       rep(i,n)if(v[i]==1){\n            if(_) res++;\n            int mx=0;\n\
    \            for(int j=i+1;j<n;j++){\n                if(v[j]==1) break;\n   \
    \             chmax(mx,v[j]);\n                if(j+1-mx>=0 and ((hash_vs[j+1]^hash_vs[j+1-mx])==hash_s[mx]))\
    \ res++;\n            }\n        }\n        reverse(ALL(v));\n    }\n\n    return\
    \ res;\n}\n\nsigned main(){\n    int n;cin>>n;\n    vector<int> a(n);\n    cin>>a;\n\
    \    cout<<Subpermutations(a)<<endl;\n    return 0;\n}\n"
  dependsOn:
  - template.hpp
  - Other/RandomNumberGenerator.hpp
  isVerificationFile: false
  path: tips/CountSubpermutation.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tips/CountSubpermutation.hpp
layout: document
title: "\u9806\u5217\u3067\u3042\u308B\u9023\u7D9A\u90E8\u5206\u5217\u306E\u6570\u3048\
  \u4E0A\u3052"
---

## 概要  
https://codeforces.com/contest/1175/problem/F  
https://kmjp.hatenablog.jp/entry/2019/09/02/0930  

ある部分列が順列であるかどうかを判定するためにはhashが速い．  
他には区間種類数+区間maxもあるが，hashが爆速だし，その気になれば余裕で更新に耐えうる  

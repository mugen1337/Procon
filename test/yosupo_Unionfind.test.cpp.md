---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: UnionFind/UnionFind.cpp
    title: UnionFind/UnionFind.cpp
  - icon: ':question:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo_Unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 1 \"template.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
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
    \   return is;\n}\n\n#line 4 \"test/yosupo_Unionfind.test.cpp\"\n\n#line 1 \"\
    UnionFind/UnionFind.cpp\"\nstruct UnionFind{\n    int con;\n    vector<int> par,siz;\n\
    \    UnionFind(int n):con(n),par(n),siz(n,1){\n        iota(begin(par),end(par),0);\n\
    \    }\n    int root(int x){\n        return (par[x]==x?x:(par[x]=root(par[x])));\n\
    \    }\n    bool sameroot(int x,int y){\n        return root(x)==root(y);\n  \
    \  }\n    bool unite(int x,int y){\n        x=root(x);y=root(y);\n        if(x==y)\
    \ return false;\n        if(siz[x]<siz[y])swap(x,y);\n        siz[x]+=siz[y];\n\
    \        par[y]=x;\n        con--;\n        return true;\n    }\n    int size(int\
    \ x){\n        return siz[root(x)];\n    }\n};\n#line 6 \"test/yosupo_Unionfind.test.cpp\"\
    \n\nsigned main(){\n    int n,q;cin>>n>>q;\n    UnionFind uf(n);\n    while(q--){\n\
    \        int t,u,v;cin>>t>>u>>v;\n        if(t) cout<<uf.sameroot(u,v)<<endl;\n\
    \        else  uf.unite(u,v);\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../template.cpp\"\n\n#include \"../UnionFind/UnionFind.cpp\"\n\nsigned main(){\n\
    \    int n,q;cin>>n>>q;\n    UnionFind uf(n);\n    while(q--){\n        int t,u,v;cin>>t>>u>>v;\n\
    \        if(t) cout<<uf.sameroot(u,v)<<endl;\n        else  uf.unite(u,v);\n \
    \   }\n    return 0;\n}"
  dependsOn:
  - template.cpp
  - UnionFind/UnionFind.cpp
  isVerificationFile: true
  path: test/yosupo_Unionfind.test.cpp
  requiredBy: []
  timestamp: '2021-01-04 00:35:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_Unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Unionfind.test.cpp
- /verify/test/yosupo_Unionfind.test.cpp.html
title: test/yosupo_Unionfind.test.cpp
---

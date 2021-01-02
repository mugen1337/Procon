---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"UnionFind/UnionFind.test.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int\
    \ i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n\
    #define mod 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst\
    \ ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\ntemplate<class\
    \ T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class\
    \ T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\nstruct UnionFind{\n\
    \    int con;\n    vector<int> par,siz;\n    UnionFind(int n):con(n),par(n),siz(n,1){\n\
    \        iota(begin(par),end(par),0);\n    }\n    int root(int x){\n        return\
    \ (par[x]==x?x:(par[x]=root(par[x])));\n    }\n    bool sameroot(int x,int y){\n\
    \        return root(x)==root(y);\n    }\n    bool unite(int x,int y){\n     \
    \   x=root(x);y=root(y);\n        if(x==y) return false;\n        if(siz[x]<siz[y])swap(x,y);\n\
    \        siz[x]+=siz[y];\n        par[y]=x;\n        con--;\n        return true;\n\
    \    }\n    int size(int x){\n        return siz[root(x)];\n    }\n};\n\n\nsigned\
    \ main(){\n    int n,q;cin>>n>>q;\n    UnionFind uf(n);\n    while(q--){\n   \
    \     int t,u,v;cin>>t>>u>>v;\n        if(t) cout<<uf.sameroot(u,v)<<endl;\n \
    \       else  uf.unite(u,v);\n    }\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto\
    \ x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\nusing ll=long long;\n\
    const int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\nstruct UnionFind{\n\
    \    int con;\n    vector<int> par,siz;\n    UnionFind(int n):con(n),par(n),siz(n,1){\n\
    \        iota(begin(par),end(par),0);\n    }\n    int root(int x){\n        return\
    \ (par[x]==x?x:(par[x]=root(par[x])));\n    }\n    bool sameroot(int x,int y){\n\
    \        return root(x)==root(y);\n    }\n    bool unite(int x,int y){\n     \
    \   x=root(x);y=root(y);\n        if(x==y) return false;\n        if(siz[x]<siz[y])swap(x,y);\n\
    \        siz[x]+=siz[y];\n        par[y]=x;\n        con--;\n        return true;\n\
    \    }\n    int size(int x){\n        return siz[root(x)];\n    }\n};\n\n\nsigned\
    \ main(){\n    int n,q;cin>>n>>q;\n    UnionFind uf(n);\n    while(q--){\n   \
    \     int t,u,v;cin>>t>>u>>v;\n        if(t) cout<<uf.sameroot(u,v)<<endl;\n \
    \       else  uf.unite(u,v);\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: UnionFind/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-01-02 03:44:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: UnionFind/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/UnionFind/UnionFind.test.cpp
- /verify/UnionFind/UnionFind.test.cpp.html
title: UnionFind/UnionFind.test.cpp
---

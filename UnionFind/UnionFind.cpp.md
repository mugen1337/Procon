---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Graph2/GraphRelabel.cpp
    title: Graph2/GraphRelabel.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_2821.test.cpp
    title: test/AOJ_2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Unionfind.test.cpp
    title: test/yosupo_Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"UnionFind/UnionFind.cpp\"\nstruct UnionFind{\n    private:\n\
    \    vector<int> par,siz;\n\n    public:\n    int con;\n    UnionFind(int n):par(n),siz(n,1),con(n){\n\
    \        iota(begin(par),end(par),0);\n    }\n    int root(int x){\n        return\
    \ (par[x]==x?x:(par[x]=root(par[x])));\n    }\n    bool sameroot(int x,int y){\n\
    \        return root(x)==root(y);\n    }\n    bool unite(int x,int y){\n     \
    \   x=root(x);y=root(y);\n        if(x==y) return false;\n        if(siz[x]<siz[y])swap(x,y);\n\
    \        siz[x]+=siz[y];\n        par[y]=x;\n        con--;\n        return true;\n\
    \    }\n    int size(int x){\n        return siz[root(x)];\n    }\n};\n"
  code: "struct UnionFind{\n    private:\n    vector<int> par,siz;\n\n    public:\n\
    \    int con;\n    UnionFind(int n):par(n),siz(n,1),con(n){\n        iota(begin(par),end(par),0);\n\
    \    }\n    int root(int x){\n        return (par[x]==x?x:(par[x]=root(par[x])));\n\
    \    }\n    bool sameroot(int x,int y){\n        return root(x)==root(y);\n  \
    \  }\n    bool unite(int x,int y){\n        x=root(x);y=root(y);\n        if(x==y)\
    \ return false;\n        if(siz[x]<siz[y])swap(x,y);\n        siz[x]+=siz[y];\n\
    \        par[y]=x;\n        con--;\n        return true;\n    }\n    int size(int\
    \ x){\n        return siz[root(x)];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: UnionFind/UnionFind.cpp
  requiredBy:
  - Graph2/GraphRelabel.cpp
  timestamp: '2021-01-04 16:08:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_2821.test.cpp
  - test/yosupo_Unionfind.test.cpp
documentation_of: UnionFind/UnionFind.cpp
layout: document
redirect_from:
- /library/UnionFind/UnionFind.cpp
- /library/UnionFind/UnionFind.cpp.html
title: UnionFind/UnionFind.cpp
---

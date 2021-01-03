---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Unionfind.test.cpp
    title: test/yosupo_Unionfind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"UnionFind/UnionFind.cpp\"\nstruct UnionFind{\n    int con;\n\
    \    vector<int> par,siz;\n    UnionFind(int n):con(n),par(n),siz(n,1){\n    \
    \    iota(begin(par),end(par),0);\n    }\n    int root(int x){\n        return\
    \ (par[x]==x?x:(par[x]=root(par[x])));\n    }\n    bool sameroot(int x,int y){\n\
    \        return root(x)==root(y);\n    }\n    bool unite(int x,int y){\n     \
    \   x=root(x);y=root(y);\n        if(x==y) return false;\n        if(siz[x]<siz[y])swap(x,y);\n\
    \        siz[x]+=siz[y];\n        par[y]=x;\n        con--;\n        return true;\n\
    \    }\n    int size(int x){\n        return siz[root(x)];\n    }\n};\n"
  code: "struct UnionFind{\n    int con;\n    vector<int> par,siz;\n    UnionFind(int\
    \ n):con(n),par(n),siz(n,1){\n        iota(begin(par),end(par),0);\n    }\n  \
    \  int root(int x){\n        return (par[x]==x?x:(par[x]=root(par[x])));\n   \
    \ }\n    bool sameroot(int x,int y){\n        return root(x)==root(y);\n    }\n\
    \    bool unite(int x,int y){\n        x=root(x);y=root(y);\n        if(x==y)\
    \ return false;\n        if(siz[x]<siz[y])swap(x,y);\n        siz[x]+=siz[y];\n\
    \        par[y]=x;\n        con--;\n        return true;\n    }\n    int size(int\
    \ x){\n        return siz[root(x)];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: UnionFind/UnionFind.cpp
  requiredBy: []
  timestamp: '2021-01-04 00:35:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_Unionfind.test.cpp
documentation_of: UnionFind/UnionFind.cpp
layout: document
redirect_from:
- /library/UnionFind/UnionFind.cpp
- /library/UnionFind/UnionFind.cpp.html
title: UnionFind/UnionFind.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"UnionFind/PartiallyPersistentUnionFind.hpp\"\nstruct PartiallyPersistentUnionFind{\n\
    \    private:\n    vector<int> ch,par;\n    vector<vector<pair<int,int>>> siz;\n\
    \n    public:\n    int time;\n    PartiallyPersistentUnionFind(int n):ch(n,1000000000),par(n,-1),siz(n),time(-1){\n\
    \        for(int i=0;i<n;i++) siz[i].emplace_back(-1,-1);\n    }\n    int root(int\
    \ t,int x){\n        if(ch[x]>t) return x;\n        return root(t,par[x]);\n \
    \   }\n    bool sameroot(int t,int x,int y){\n        return root(t,x)==root(t,y);\n\
    \    }\n    bool unite(int x,int y){\n        time++;\n        x=root(time,x);\n\
    \        y=root(time,y);\n        if(x==y) return false;\n        if(par[x]>par[y])\
    \ swap(x,y);\n        par[x]+=par[y];\n        par[y]=x;\n        ch[y]=time;\n\
    \        siz[x].emplace_back(time,par[x]);\n        return true;\n    }\n    int\
    \ size(int t,int x){\n        x=root(t,x);\n        return -prev(lower_bound(begin(siz[x]),end(siz[x]),make_pair(t,0)))->second;\n\
    \    }\n};\n"
  code: "struct PartiallyPersistentUnionFind{\n    private:\n    vector<int> ch,par;\n\
    \    vector<vector<pair<int,int>>> siz;\n\n    public:\n    int time;\n    PartiallyPersistentUnionFind(int\
    \ n):ch(n,1000000000),par(n,-1),siz(n),time(-1){\n        for(int i=0;i<n;i++)\
    \ siz[i].emplace_back(-1,-1);\n    }\n    int root(int t,int x){\n        if(ch[x]>t)\
    \ return x;\n        return root(t,par[x]);\n    }\n    bool sameroot(int t,int\
    \ x,int y){\n        return root(t,x)==root(t,y);\n    }\n    bool unite(int x,int\
    \ y){\n        time++;\n        x=root(time,x);\n        y=root(time,y);\n   \
    \     if(x==y) return false;\n        if(par[x]>par[y]) swap(x,y);\n        par[x]+=par[y];\n\
    \        par[y]=x;\n        ch[y]=time;\n        siz[x].emplace_back(time,par[x]);\n\
    \        return true;\n    }\n    int size(int t,int x){\n        x=root(t,x);\n\
    \        return -prev(lower_bound(begin(siz[x]),end(siz[x]),make_pair(t,0)))->second;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: UnionFind/PartiallyPersistentUnionFind.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: UnionFind/PartiallyPersistentUnionFind.hpp
layout: document
redirect_from:
- /library/UnionFind/PartiallyPersistentUnionFind.hpp
- /library/UnionFind/PartiallyPersistentUnionFind.hpp.html
title: UnionFind/PartiallyPersistentUnionFind.hpp
---

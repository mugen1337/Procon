---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DSL_1_B.test.cpp
    title: test/AOJ_DSL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"UnionFind/WeightedUnionFind.cpp\"\ntemplate<typename T>\n\
    struct WeightedUnionFind{\n    int con;\n    vector<int> par,siz;\n    vector<T>\
    \ h;// height, h[root]=0\n    WeightedUnionFind(int n):con(n),par(n),siz(n,1),h(n,T(0)){\n\
    \        iota(begin(par),end(par),0);\n    }\n    int root(int x){\n        if(x==par[x])\
    \ return x;\n        int r=root(par[x]);\n        h[x]+=h[par[x]];\n        return\
    \ par[x]=r;\n    }\n    bool sameroot(int x,int y){\n        return root(x)==root(y);\n\
    \    }\n    // y\u306Fx\u3088\u308Adiff_h\u9AD8\u3044, h[y]=h[x]+diff_h, x->y\
    \ (diff_h)\n    bool unite(int x,int y,T diff_h){\n        int root_x=root(x),root_y=root(y);\n\
    \        if(root_x==root_y){\n            // // x and y are already in same group\n\
    \            // assert(false);\n            return false;\n        }\n       \
    \ diff_h=-h[x]+diff_h+h[y];\n        if(siz[root_x]>siz[root_y]) swap(root_x,root_y),diff_h=-diff_h;\
    \ \n        siz[root_y]+=siz[root_x];\n        par[root_x]=root_y;\n        h[root_x]=diff_h;\n\
    \        con--;\n        return true;\n    }\n    // h[y]-h[x]\n    T diff(int\
    \ x,int y){\n        assert(sameroot(x,y));\n        return h[y]-h[x];\n    }\n\
    \    int size(int x){\n        return siz[root(x)];\n    }\n};\n"
  code: "template<typename T>\nstruct WeightedUnionFind{\n    int con;\n    vector<int>\
    \ par,siz;\n    vector<T> h;// height, h[root]=0\n    WeightedUnionFind(int n):con(n),par(n),siz(n,1),h(n,T(0)){\n\
    \        iota(begin(par),end(par),0);\n    }\n    int root(int x){\n        if(x==par[x])\
    \ return x;\n        int r=root(par[x]);\n        h[x]+=h[par[x]];\n        return\
    \ par[x]=r;\n    }\n    bool sameroot(int x,int y){\n        return root(x)==root(y);\n\
    \    }\n    // y\u306Fx\u3088\u308Adiff_h\u9AD8\u3044, h[y]=h[x]+diff_h, x->y\
    \ (diff_h)\n    bool unite(int x,int y,T diff_h){\n        int root_x=root(x),root_y=root(y);\n\
    \        if(root_x==root_y){\n            // // x and y are already in same group\n\
    \            // assert(false);\n            return false;\n        }\n       \
    \ diff_h=-h[x]+diff_h+h[y];\n        if(siz[root_x]>siz[root_y]) swap(root_x,root_y),diff_h=-diff_h;\
    \ \n        siz[root_y]+=siz[root_x];\n        par[root_x]=root_y;\n        h[root_x]=diff_h;\n\
    \        con--;\n        return true;\n    }\n    // h[y]-h[x]\n    T diff(int\
    \ x,int y){\n        assert(sameroot(x,y));\n        return h[y]-h[x];\n    }\n\
    \    int size(int x){\n        return siz[root(x)];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: UnionFind/WeightedUnionFind.cpp
  requiredBy: []
  timestamp: '2021-01-04 00:35:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_DSL_1_B.test.cpp
documentation_of: UnionFind/WeightedUnionFind.cpp
layout: document
redirect_from:
- /library/UnionFind/WeightedUnionFind.cpp
- /library/UnionFind/WeightedUnionFind.cpp.html
title: UnionFind/WeightedUnionFind.cpp
---

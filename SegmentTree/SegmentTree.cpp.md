---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Point-Add-Range-Sum.test.cpp
    title: test/yosupo_Point-Add-Range-Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SegmentTree/SegmentTree.cpp\"\ntemplate<typename Monoid>\n\
    struct SegmentTree{\n    int sz;\n    vector<Monoid> seg;\n    Monoid M0;// \u30E2\
    \u30CE\u30A4\u30C9\u306E\u5143\n    using F=function<Monoid(Monoid,Monoid)>;\n\
    \    F f;\n    SegmentTree(int n,Monoid M0,F f):M0(M0),f(f){\n        sz=1;\n\
    \        while(sz<n)sz<<=1;\n        seg.assign(2*sz,M0);\n    }\n    void set(int\
    \ k,Monoid x){\n        seg[k+sz]=x;\n    }\n    void build(){\n        for(int\
    \ k=sz-1;k>0;k--) seg[k]=f(seg[2*k],seg[2*k+1]);\n    }\n    void update(int k,Monoid\
    \ x){\n        k+=sz;\n        seg[k]=x;\n        k>>=1;\n        for(;k;k>>=1)\
    \ seg[k]=f(seg[2*k],seg[2*k+1]);\n    }\n    Monoid query(int a,int b,int k=1,int\
    \ l=0,int r=-1){\n        if(r==-1) r=sz;\n        if(a<=l and r<=b)   return\
    \ seg[k];\n        if(b<=l or r<=a)    return M0;\n        Monoid L=query(a,b,2*k,l,(l+r)/2);\n\
    \        Monoid R=query(a,b,2*k+1,(l+r)/2,r);\n        return f(L,R);\n    }\n\
    };\n"
  code: "template<typename Monoid>\nstruct SegmentTree{\n    int sz;\n    vector<Monoid>\
    \ seg;\n    Monoid M0;// \u30E2\u30CE\u30A4\u30C9\u306E\u5143\n    using F=function<Monoid(Monoid,Monoid)>;\n\
    \    F f;\n    SegmentTree(int n,Monoid M0,F f):M0(M0),f(f){\n        sz=1;\n\
    \        while(sz<n)sz<<=1;\n        seg.assign(2*sz,M0);\n    }\n    void set(int\
    \ k,Monoid x){\n        seg[k+sz]=x;\n    }\n    void build(){\n        for(int\
    \ k=sz-1;k>0;k--) seg[k]=f(seg[2*k],seg[2*k+1]);\n    }\n    void update(int k,Monoid\
    \ x){\n        k+=sz;\n        seg[k]=x;\n        k>>=1;\n        for(;k;k>>=1)\
    \ seg[k]=f(seg[2*k],seg[2*k+1]);\n    }\n    Monoid query(int a,int b,int k=1,int\
    \ l=0,int r=-1){\n        if(r==-1) r=sz;\n        if(a<=l and r<=b)   return\
    \ seg[k];\n        if(b<=l or r<=a)    return M0;\n        Monoid L=query(a,b,2*k,l,(l+r)/2);\n\
    \        Monoid R=query(a,b,2*k+1,(l+r)/2,r);\n        return f(L,R);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/SegmentTree.cpp
  requiredBy: []
  timestamp: '2021-01-03 23:15:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_Point-Add-Range-Sum.test.cpp
documentation_of: SegmentTree/SegmentTree.cpp
layout: document
title: Segment Tree
---

## 概要  
Segment Tree (再起)
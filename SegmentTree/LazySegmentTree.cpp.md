---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki1249.test.cpp
    title: test/yuki1249.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki4374.test.cpp
    title: test/yuki4374.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki899.test.cpp
    title: test/yuki899.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SegmentTree/LazySegmentTree.cpp\"\ntemplate<typename Monoid,\
    \ typename OperatorMonoid=Monoid>\nstruct LazySegmentTree{\n    using F=function<Monoid(Monoid,Monoid)>;\n\
    \    using G=function<Monoid(Monoid,OperatorMonoid)>;\n    using H=function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;\n\
    \ \n    private:\n \n    int sz,height;\n    vector<Monoid> data;\n    vector<OperatorMonoid>\
    \ lazy;\n    // propagate lazy value -> data (node k)\n    inline void propagate(int\
    \ k){\n        if(lazy[k]!=OM0){\n            if(k<sz){\n                lazy[2*k+0]=h(lazy[2*k+0],lazy[k]);\n\
    \                lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);\n            }\n        \
    \    data[k]=g(data[k],lazy[k]);\n            lazy[k]=OM0;\n        }\n    }\n\
    \ \n    void update(int a,int b,const OperatorMonoid &x,int k,int l,int r){\n\
    \        propagate(k);\n        if(b<=l or r<=a) return ;\n        if(a<=l and\
    \ r<=b){\n            lazy[k]=h(lazy[k],x);\n            propagate(k);\n     \
    \   }else{\n            update(a,b,x,2*k,l,(l+r)/2);\n            update(a,b,x,2*k+1,(l+r)/2,r);\n\
    \            data[k]=f(data[2*k],data[2*k+1]);\n        }\n    }\n \n    Monoid\
    \ query(int a,int b,int k,int l,int r){\n        if(b<=l or r<=a) return M1;\n\
    \ \n        propagate(k);\n        if(a<=l and r<=b) return data[k];\n \n    \
    \    Monoid L=query(a,b,2*k+0,l,(l+r)/2);\n        Monoid R=query(a,b,2*k+1,(l+r)/2,r);\n\
    \        return f(L,R);\n    }\n \n    public:\n \n    const F f;\n    const G\
    \ g;\n    const H h;\n    const Monoid M1;\n    const OperatorMonoid OM0;\n \n\
    \    LazySegmentTree(int n,const F f,const G g,const H h,const Monoid &M1,const\
    \ OperatorMonoid OM0)\n    : f(f),g(g),h(h),M1(M1),OM0(OM0) {\n        sz=1;height=0;\n\
    \        while(sz<n) sz<<=1,height++;\n        data.assign(2*sz,M1);lazy.assign(2*sz,OM0);\n\
    \    }\n \n    void set(int k,const Monoid &x){\n        data[k+sz]=x;\n    }\n\
    \    void build(){\n        for(int k=sz-1;k>0;k--) data[k]=f(data[2*k+0],data[2*k+1]);\n\
    \    }\n    void update(int a,int b,const OperatorMonoid &x){\n        update(a,b,x,1,0,sz);\n\
    \    }\n    Monoid query(int a,int b){\n        return query(a,b,1,0,sz);\n  \
    \  }\n    Monoid operator[](const int &k){\n        return query(k,k+1);\n   \
    \ }\n}; \n\n// // range set range min\n// using M=ll;\n// using OM=ll;\n// const\
    \ M M1=LINF;\n// const OM OM0=-LINF;\n// M segf(M a,M b){\n//     return (a<b?a:b);\n\
    // }\n// M segg(M a,OM b){\n//     return (b==OM0?a:b);\n// }\n// OM segh(OM a,OM\
    \ b){\n//     return (b==OM0?a:b);\n// }\n \n// // range set range max\n// using\
    \ M=ll;\n// using OM=ll;\n// const M M1=-LINF;\n// const OM OM0=-LINF;\n// M segf(M\
    \ a,M b){\n//     return (a>b?a:b);\n// }\n// M segg(M a,OM b){\n//     return\
    \ (b==OM0?a:b);\n// }\n// OM segh(OM a,OM b){\n//     return (b==OM0?a:b);\n//\
    \ }\n \n// // range add range min\n// using M=ll;\n// using OM=ll;\n// const M\
    \ M1=LINF;\n// const OM OM0=0;\n// M segf(M a,M b){\n//     return (a<b?a:b);\n\
    // }\n// M segg(M a,OM b){\n//     return a+b;\n// }\n// OM segh(OM a,OM b){\n\
    //     return a+b;\n// }\n \n// // range add range max\n// using M=ll;\n// using\
    \ OM=ll;\n// const M M1=-LINF;\n// const OM OM0=0;\n// M segf(M a,M b){\n//  \
    \   return (a>b?a:b);\n// }\n// M segg(M a,OM b){\n//     return a+b;\n// }\n\
    // OM segh(OM a,OM b){\n//     return a+b;\n// }\n \n// // range set range sum\
    \ (sum, count)\n// using M=pair<ll,ll>;\n// using OM=ll;\n// const M M1=M(0,0);\n\
    // const OM OM0=-LINF;\n// M segf(M a,M b){\n//     return M(a.first+b.first,a.second+b.second);\n\
    // }\n// M segg(M a,OM b){\n//     return M(a.second*b,a.second);\n// }\n// ll\
    \ segh(ll a,ll b){\n//     return (b==OM0?a:b);\n// }\n"
  code: "template<typename Monoid, typename OperatorMonoid=Monoid>\nstruct LazySegmentTree{\n\
    \    using F=function<Monoid(Monoid,Monoid)>;\n    using G=function<Monoid(Monoid,OperatorMonoid)>;\n\
    \    using H=function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;\n \n   \
    \ private:\n \n    int sz,height;\n    vector<Monoid> data;\n    vector<OperatorMonoid>\
    \ lazy;\n    // propagate lazy value -> data (node k)\n    inline void propagate(int\
    \ k){\n        if(lazy[k]!=OM0){\n            if(k<sz){\n                lazy[2*k+0]=h(lazy[2*k+0],lazy[k]);\n\
    \                lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);\n            }\n        \
    \    data[k]=g(data[k],lazy[k]);\n            lazy[k]=OM0;\n        }\n    }\n\
    \ \n    void update(int a,int b,const OperatorMonoid &x,int k,int l,int r){\n\
    \        propagate(k);\n        if(b<=l or r<=a) return ;\n        if(a<=l and\
    \ r<=b){\n            lazy[k]=h(lazy[k],x);\n            propagate(k);\n     \
    \   }else{\n            update(a,b,x,2*k,l,(l+r)/2);\n            update(a,b,x,2*k+1,(l+r)/2,r);\n\
    \            data[k]=f(data[2*k],data[2*k+1]);\n        }\n    }\n \n    Monoid\
    \ query(int a,int b,int k,int l,int r){\n        if(b<=l or r<=a) return M1;\n\
    \ \n        propagate(k);\n        if(a<=l and r<=b) return data[k];\n \n    \
    \    Monoid L=query(a,b,2*k+0,l,(l+r)/2);\n        Monoid R=query(a,b,2*k+1,(l+r)/2,r);\n\
    \        return f(L,R);\n    }\n \n    public:\n \n    const F f;\n    const G\
    \ g;\n    const H h;\n    const Monoid M1;\n    const OperatorMonoid OM0;\n \n\
    \    LazySegmentTree(int n,const F f,const G g,const H h,const Monoid &M1,const\
    \ OperatorMonoid OM0)\n    : f(f),g(g),h(h),M1(M1),OM0(OM0) {\n        sz=1;height=0;\n\
    \        while(sz<n) sz<<=1,height++;\n        data.assign(2*sz,M1);lazy.assign(2*sz,OM0);\n\
    \    }\n \n    void set(int k,const Monoid &x){\n        data[k+sz]=x;\n    }\n\
    \    void build(){\n        for(int k=sz-1;k>0;k--) data[k]=f(data[2*k+0],data[2*k+1]);\n\
    \    }\n    void update(int a,int b,const OperatorMonoid &x){\n        update(a,b,x,1,0,sz);\n\
    \    }\n    Monoid query(int a,int b){\n        return query(a,b,1,0,sz);\n  \
    \  }\n    Monoid operator[](const int &k){\n        return query(k,k+1);\n   \
    \ }\n}; \n\n// // range set range min\n// using M=ll;\n// using OM=ll;\n// const\
    \ M M1=LINF;\n// const OM OM0=-LINF;\n// M segf(M a,M b){\n//     return (a<b?a:b);\n\
    // }\n// M segg(M a,OM b){\n//     return (b==OM0?a:b);\n// }\n// OM segh(OM a,OM\
    \ b){\n//     return (b==OM0?a:b);\n// }\n \n// // range set range max\n// using\
    \ M=ll;\n// using OM=ll;\n// const M M1=-LINF;\n// const OM OM0=-LINF;\n// M segf(M\
    \ a,M b){\n//     return (a>b?a:b);\n// }\n// M segg(M a,OM b){\n//     return\
    \ (b==OM0?a:b);\n// }\n// OM segh(OM a,OM b){\n//     return (b==OM0?a:b);\n//\
    \ }\n \n// // range add range min\n// using M=ll;\n// using OM=ll;\n// const M\
    \ M1=LINF;\n// const OM OM0=0;\n// M segf(M a,M b){\n//     return (a<b?a:b);\n\
    // }\n// M segg(M a,OM b){\n//     return a+b;\n// }\n// OM segh(OM a,OM b){\n\
    //     return a+b;\n// }\n \n// // range add range max\n// using M=ll;\n// using\
    \ OM=ll;\n// const M M1=-LINF;\n// const OM OM0=0;\n// M segf(M a,M b){\n//  \
    \   return (a>b?a:b);\n// }\n// M segg(M a,OM b){\n//     return a+b;\n// }\n\
    // OM segh(OM a,OM b){\n//     return a+b;\n// }\n \n// // range set range sum\
    \ (sum, count)\n// using M=pair<ll,ll>;\n// using OM=ll;\n// const M M1=M(0,0);\n\
    // const OM OM0=-LINF;\n// M segf(M a,M b){\n//     return M(a.first+b.first,a.second+b.second);\n\
    // }\n// M segg(M a,OM b){\n//     return M(a.second*b,a.second);\n// }\n// ll\
    \ segh(ll a,ll b){\n//     return (b==OM0?a:b);\n// }"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/LazySegmentTree.cpp
  requiredBy: []
  timestamp: '2021-02-14 20:15:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki899.test.cpp
  - test/yuki4374.test.cpp
  - test/yuki1249.test.cpp
documentation_of: SegmentTree/LazySegmentTree.cpp
layout: document
title: Lazy Segment Tree
---

## 概要  
Lazy Segment Tree (再起)

f : 要素同士のマージ  
g : 作用素を要素の適用  
h : 作用素同士のマージ  

## refs  
https://ei1333.github.io/library/structure/segment-tree/lazy-segment-tree.cpp  
https://tsutaj.hatenablog.com/entry/2017/03/30/224339  

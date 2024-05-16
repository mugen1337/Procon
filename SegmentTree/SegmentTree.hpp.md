---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/ManhattanSquareSum.hpp
    title: Math/ManhattanSquareSum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Point-Add-Range-Sum.test.cpp
    title: test/yosupo_Point-Add-Range-Sum.test.cpp
  - icon: ':x:'
    path: test/yuki3784.test.cpp
    title: test/yuki3784.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - http://codeforces.com/contest/914/submission/107505449
    - http://codeforces.com/contest/914/submission/107505582
  bundledCode: "#line 1 \"SegmentTree/SegmentTree.hpp\"\ntemplate<typename Monoid>\n\
    struct SegmentTree{\n    using F=function<Monoid(Monoid,Monoid)>;\n\n    private:\n\
    \    int sz;\n    vector<Monoid> seg;\n\n    Monoid query(int a,int b,int k,int\
    \ l,int r){\n        if(a<=l and r<=b)   return seg[k];\n        if(b<=l or r<=a)\
    \    return M0;\n        Monoid L=query(a,b,2*k,l,(l+r)/2);\n        Monoid R=query(a,b,2*k+1,(l+r)/2,r);\n\
    \        return f(L,R);\n    }\n    template<typename C>\n    int find_first(int\
    \ a,const C &check,Monoid &acc,int k,int l,int r){\n        if(k>=sz){\n     \
    \       acc=f(acc,seg[k]);\n            if(check(acc))  return -1;\n         \
    \   else            return k-sz;\n        }\n        int m=(l+r)/2;\n        if(m<=a)\
    \ return find_first(a,check,acc,2*k+1,m,r);\n        if(a<=l and check(f(acc,seg[k]))){\n\
    \            acc=f(acc,seg[k]);\n            return -1;\n        }\n        int\
    \ x=find_first(a,check,acc,2*k+0,l,m);\n        if(x>=0) return x;\n        return\
    \ find_first(a,check,acc,2*k+1,m,r);\n    }\n    template<typename C>\n    int\
    \ find_last(int b,const C &check,Monoid &acc,int k,int l,int r){\n        if(k>=sz){\n\
    \            acc=f(acc,seg[k]);\n            if(check(acc))  return -1;\n    \
    \        else            return k-sz+1;//\u3053\u3053\u306Ffalse, +1\u3057\u305F\
    \u4F4D\u7F6E\u306Ftrue\n        }\n        int m=(l+r)/2;\n        if(b<=m) return\
    \ find_last(b,check,acc,2*k,l,m);\n        if(r<=b and check(f(acc,seg[k]))){\n\
    \            acc=f(acc,seg[k]);\n            return -1;\n        }\n        int\
    \ x=find_last(b,check,acc,2*k+1,m,r);\n        if(x>=0) return x;\n        return\
    \ find_last(b,check,acc,2*k,l,m);\n    }\n\n    public:\n\n    F f;\n    Monoid\
    \ M0;// \u30E2\u30CE\u30A4\u30C9\u306E\u5143\n    SegmentTree(int n, F f_, Monoid\
    \ M0_) : f(f_), M0(M0_)\n    {\n        sz=1;\n        while(sz<n)sz<<=1;\n  \
    \      seg.assign(2*sz,M0);\n    }\n    void set(int k,Monoid x){\n        seg[k+sz]=x;\n\
    \    }\n    void build(){\n        for(int k=sz-1;k>0;k--) seg[k]=f(seg[2*k],seg[2*k+1]);\n\
    \    }\n    void update(int k,Monoid x){\n        k+=sz;\n        seg[k]=x;\n\
    \        k>>=1;\n        for(;k;k>>=1) seg[k]=f(seg[2*k],seg[2*k+1]);\n    }\n\
    \    Monoid query(int a,int b){\n        return query(a,b,1,0,sz);\n    }\n  \
    \  Monoid operator[](const int &k)const{\n        return seg[k+sz];\n    }\n\n\
    \    // http://codeforces.com/contest/914/submission/107505449\n    // max x,\
    \ check(query(a, x)) = true \n    template<typename C>\n    int find_first(int\
    \ a,const C &check){\n        Monoid val=M0;\n        return find_first(a,check,val,1,0,sz);\n\
    \    }\n    // http://codeforces.com/contest/914/submission/107505582\n    //\
    \ min x, check(query(x, b)) = true\n    template<typename C>\n    int find_last(int\
    \ b,C &check){\n        Monoid val=M0;\n        return find_last(b,check,val,1,0,sz);\n\
    \    }\n};\n"
  code: "template<typename Monoid>\nstruct SegmentTree{\n    using F=function<Monoid(Monoid,Monoid)>;\n\
    \n    private:\n    int sz;\n    vector<Monoid> seg;\n\n    Monoid query(int a,int\
    \ b,int k,int l,int r){\n        if(a<=l and r<=b)   return seg[k];\n        if(b<=l\
    \ or r<=a)    return M0;\n        Monoid L=query(a,b,2*k,l,(l+r)/2);\n       \
    \ Monoid R=query(a,b,2*k+1,(l+r)/2,r);\n        return f(L,R);\n    }\n    template<typename\
    \ C>\n    int find_first(int a,const C &check,Monoid &acc,int k,int l,int r){\n\
    \        if(k>=sz){\n            acc=f(acc,seg[k]);\n            if(check(acc))\
    \  return -1;\n            else            return k-sz;\n        }\n        int\
    \ m=(l+r)/2;\n        if(m<=a) return find_first(a,check,acc,2*k+1,m,r);\n   \
    \     if(a<=l and check(f(acc,seg[k]))){\n            acc=f(acc,seg[k]);\n   \
    \         return -1;\n        }\n        int x=find_first(a,check,acc,2*k+0,l,m);\n\
    \        if(x>=0) return x;\n        return find_first(a,check,acc,2*k+1,m,r);\n\
    \    }\n    template<typename C>\n    int find_last(int b,const C &check,Monoid\
    \ &acc,int k,int l,int r){\n        if(k>=sz){\n            acc=f(acc,seg[k]);\n\
    \            if(check(acc))  return -1;\n            else            return k-sz+1;//\u3053\
    \u3053\u306Ffalse, +1\u3057\u305F\u4F4D\u7F6E\u306Ftrue\n        }\n        int\
    \ m=(l+r)/2;\n        if(b<=m) return find_last(b,check,acc,2*k,l,m);\n      \
    \  if(r<=b and check(f(acc,seg[k]))){\n            acc=f(acc,seg[k]);\n      \
    \      return -1;\n        }\n        int x=find_last(b,check,acc,2*k+1,m,r);\n\
    \        if(x>=0) return x;\n        return find_last(b,check,acc,2*k,l,m);\n\
    \    }\n\n    public:\n\n    F f;\n    Monoid M0;// \u30E2\u30CE\u30A4\u30C9\u306E\
    \u5143\n    SegmentTree(int n, F f_, Monoid M0_) : f(f_), M0(M0_)\n    {\n   \
    \     sz=1;\n        while(sz<n)sz<<=1;\n        seg.assign(2*sz,M0);\n    }\n\
    \    void set(int k,Monoid x){\n        seg[k+sz]=x;\n    }\n    void build(){\n\
    \        for(int k=sz-1;k>0;k--) seg[k]=f(seg[2*k],seg[2*k+1]);\n    }\n    void\
    \ update(int k,Monoid x){\n        k+=sz;\n        seg[k]=x;\n        k>>=1;\n\
    \        for(;k;k>>=1) seg[k]=f(seg[2*k],seg[2*k+1]);\n    }\n    Monoid query(int\
    \ a,int b){\n        return query(a,b,1,0,sz);\n    }\n    Monoid operator[](const\
    \ int &k)const{\n        return seg[k+sz];\n    }\n\n    // http://codeforces.com/contest/914/submission/107505449\n\
    \    // max x, check(query(a, x)) = true \n    template<typename C>\n    int find_first(int\
    \ a,const C &check){\n        Monoid val=M0;\n        return find_first(a,check,val,1,0,sz);\n\
    \    }\n    // http://codeforces.com/contest/914/submission/107505582\n    //\
    \ min x, check(query(x, b)) = true\n    template<typename C>\n    int find_last(int\
    \ b,C &check){\n        Monoid val=M0;\n        return find_last(b,check,val,1,0,sz);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/SegmentTree.hpp
  requiredBy:
  - Math/ManhattanSquareSum.hpp
  timestamp: '2023-07-17 17:05:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo_Point-Add-Range-Sum.test.cpp
  - test/yuki3784.test.cpp
documentation_of: SegmentTree/SegmentTree.hpp
layout: document
title: Segment Tree
---

## 概要  
Segment Tree (再起)
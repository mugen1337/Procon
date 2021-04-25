---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"BinarySearchTree/ImplicitTreap.cpp\"\ntemplate<typename\
    \ T>\nstruct Treap{\n\nprivate:\n\n    inline int xorshift() const {\n       \
    \ static int x=122312555;\n        static int y=336261662;\n        static int\
    \ z=558127122;\n        static int w=917277772;\n        int t;\n        t=x^(x<<11);\n\
    \        x=y;y=z;z=w;\n        return w=(w^(w>>19))^(t^(t>>8));\n    }\n\n   \
    \ struct Node;\n    using Ptr=unique_ptr<Node>;\n\n    struct Node{\n        Ptr\
    \ l,r;\n        int sz,pri;// priority\n        T val;\n        bool rev;\n  \
    \      Node()=default;\n        Node(const T &val,int pri):\n        l(nullptr),r(nullptr),sz(1),pri(pri),val(val),rev(false){}\n\
    \    };\n    Ptr root;\n\n    explicit Treap(Ptr root):root(move(root)){}\n  \
    \  int size(Ptr &t)const{return (t?t->sz:0);}\n    Ptr merge(Ptr l,Ptr r){\n \
    \       if(!l) return move(r);\n        if(!r) return move(l);\n        push(l);push(r);\n\
    \        if(l->pri>r->pri){\n            l->r=merge(move(l->r),move(r));\n   \
    \         l->sz=size(l->l)+1+size(l->r);\n            return move(l);\n      \
    \  }else{\n            r->l=merge(move(l),move(r->l));\n            r->sz=size(r->l)+1+size(r->r);\n\
    \            return move(r);\n        }\n    }\n    pair<Ptr,Ptr> split(Ptr t,int\
    \ k){\n        if(!t) return {nullptr,nullptr};\n        push(t);\n        if(k<=size(t->l)){\n\
    \            auto x=split(move(t->l),k);\n            t->l=move(x.second);\n \
    \           t->sz=size(t->l)+1+size(t->r);\n            return {move(x.first),move(t)};\n\
    \        }else{\n            auto x=split(move(t->r),k-size(t->l)-1);\n      \
    \      t->r=move(x.first);\n            t->sz=size(t->l)+1+size(t->r);\n     \
    \       return {move(t),move(x.second)};\n        }\n    }\n    T &access(Ptr\
    \ &cur,int k){\n        assert(cur);\n        push(cur);\n        if(k==size(cur->l))\
    \ return cur->val;\n        if(k<size(cur->l))  return access(cur->l,k);\n   \
    \     else                return access(cur->r,k-1-size(cur->l));\n    }\n   \
    \ void push(Ptr &t){\n        if(t->rev){\n            swap(t->l,t->r);\n    \
    \        if(t->l) t->l->rev^=true;\n            if(t->r) t->r->rev^=true;\n  \
    \          t->rev=false;\n        }\n    }\n\npublic:\n\n    Treap():root(nullptr){}\n\
    \n    void insert(int k,const T &x){\n        auto s=split(move(root),k);\n  \
    \      Ptr i(new Node(x,xorshift()));\n        root=merge(merge(move(s.first),move(i)),move(s.second));\n\
    \    }\n\n    void erase(int k){\n        auto l=split(move(root),k);\n      \
    \  auto r=split(move(l.second),1);\n        root=merge(move(l.first),move(r.second));\n\
    \    }\n\n    T &operator[](int k){ return access(root,k); }\n\n    int size(){\
    \ return size(root); }\n\n    void push_back(T x){\n        Ptr b(new Node(x,xorshift()));\n\
    \        root=merge(move(root),move(b));\n    }\n    void push_front(T x){\n \
    \       Ptr f(new Node(x,xorshift()));\n        root=merge(move(f),move(root));\n\
    \    }\n    void pop_back(){ root=split(move(root),1).second; }\n    void pop_front(){\
    \ root=split(move(root),size()-1).second; }\n\n    void reverse(int l,int r){\n\
    \        auto x=split(move(root),l);\n        auto y=split(move(x.second),r-l);\n\
    \        y.first->rev^=true;\n        root=merge(merge(move(x.first),move(y.first)),move(y.second));\n\
    \    }\n\n    void rotate(int l,int m,int r){\n        reverse(l,r);\n       \
    \ reverse(l,l+r-m);\n        reverse(l+r-m,r);\n    }\n};\n"
  code: "template<typename T>\nstruct Treap{\n\nprivate:\n\n    inline int xorshift()\
    \ const {\n        static int x=122312555;\n        static int y=336261662;\n\
    \        static int z=558127122;\n        static int w=917277772;\n        int\
    \ t;\n        t=x^(x<<11);\n        x=y;y=z;z=w;\n        return w=(w^(w>>19))^(t^(t>>8));\n\
    \    }\n\n    struct Node;\n    using Ptr=unique_ptr<Node>;\n\n    struct Node{\n\
    \        Ptr l,r;\n        int sz,pri;// priority\n        T val;\n        bool\
    \ rev;\n        Node()=default;\n        Node(const T &val,int pri):\n       \
    \ l(nullptr),r(nullptr),sz(1),pri(pri),val(val),rev(false){}\n    };\n    Ptr\
    \ root;\n\n    explicit Treap(Ptr root):root(move(root)){}\n    int size(Ptr &t)const{return\
    \ (t?t->sz:0);}\n    Ptr merge(Ptr l,Ptr r){\n        if(!l) return move(r);\n\
    \        if(!r) return move(l);\n        push(l);push(r);\n        if(l->pri>r->pri){\n\
    \            l->r=merge(move(l->r),move(r));\n            l->sz=size(l->l)+1+size(l->r);\n\
    \            return move(l);\n        }else{\n            r->l=merge(move(l),move(r->l));\n\
    \            r->sz=size(r->l)+1+size(r->r);\n            return move(r);\n   \
    \     }\n    }\n    pair<Ptr,Ptr> split(Ptr t,int k){\n        if(!t) return {nullptr,nullptr};\n\
    \        push(t);\n        if(k<=size(t->l)){\n            auto x=split(move(t->l),k);\n\
    \            t->l=move(x.second);\n            t->sz=size(t->l)+1+size(t->r);\n\
    \            return {move(x.first),move(t)};\n        }else{\n            auto\
    \ x=split(move(t->r),k-size(t->l)-1);\n            t->r=move(x.first);\n     \
    \       t->sz=size(t->l)+1+size(t->r);\n            return {move(t),move(x.second)};\n\
    \        }\n    }\n    T &access(Ptr &cur,int k){\n        assert(cur);\n    \
    \    push(cur);\n        if(k==size(cur->l)) return cur->val;\n        if(k<size(cur->l))\
    \  return access(cur->l,k);\n        else                return access(cur->r,k-1-size(cur->l));\n\
    \    }\n    void push(Ptr &t){\n        if(t->rev){\n            swap(t->l,t->r);\n\
    \            if(t->l) t->l->rev^=true;\n            if(t->r) t->r->rev^=true;\n\
    \            t->rev=false;\n        }\n    }\n\npublic:\n\n    Treap():root(nullptr){}\n\
    \n    void insert(int k,const T &x){\n        auto s=split(move(root),k);\n  \
    \      Ptr i(new Node(x,xorshift()));\n        root=merge(merge(move(s.first),move(i)),move(s.second));\n\
    \    }\n\n    void erase(int k){\n        auto l=split(move(root),k);\n      \
    \  auto r=split(move(l.second),1);\n        root=merge(move(l.first),move(r.second));\n\
    \    }\n\n    T &operator[](int k){ return access(root,k); }\n\n    int size(){\
    \ return size(root); }\n\n    void push_back(T x){\n        Ptr b(new Node(x,xorshift()));\n\
    \        root=merge(move(root),move(b));\n    }\n    void push_front(T x){\n \
    \       Ptr f(new Node(x,xorshift()));\n        root=merge(move(f),move(root));\n\
    \    }\n    void pop_back(){ root=split(move(root),1).second; }\n    void pop_front(){\
    \ root=split(move(root),size()-1).second; }\n\n    void reverse(int l,int r){\n\
    \        auto x=split(move(root),l);\n        auto y=split(move(x.second),r-l);\n\
    \        y.first->rev^=true;\n        root=merge(merge(move(x.first),move(y.first)),move(y.second));\n\
    \    }\n\n    void rotate(int l,int m,int r){\n        reverse(l,r);\n       \
    \ reverse(l,l+r-m);\n        reverse(l+r-m,r);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: BinarySearchTree/ImplicitTreap.cpp
  requiredBy: []
  timestamp: '2021-04-25 22:33:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: BinarySearchTree/ImplicitTreap.cpp
layout: document
title: Implicit Treap
---

## 概要  
vectorのようなインターフェースを提供する二分探索木  
内部はTreap

## 仕様  
- operator[] : ランダムアクセス
- insert(k, x) : a[k]<-x, 後ろを1個ずつずらす
- erase(k) : a[x]を消す, 後ろを1個ずつ詰める
- reverse(l, r) : a[l] ~ a[r]をreverseする
- rotate(l, m, r) : a[l]がa[m]になるまでrotateする
- push_back, push_front, pop_back, pop_front : はい



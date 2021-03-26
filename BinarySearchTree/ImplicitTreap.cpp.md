---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
    title: test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki5398.test.cpp
    title: test/yuki5398.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"BinarySearchTree/ImplicitTreap.cpp\"\ntemplate<typename\
    \ Monoid,typename OperatorMonoid>\nstruct ImplicitTreap{\n\n    private:\n\n \
    \   inline int xorshift(){\n        static int x=122312555;\n        static int\
    \ y=336261662;\n        static int z=558127122;\n        static int w=917277772;\n\
    \        int t;\n        t=x^(x<<11);\n        x=y;y=z;z=w;\n        return w=(w^(w>>19))^(t^(t>>8));\n\
    \    }\n\n    using F=function<Monoid(Monoid,Monoid)>;\n    using G=function<Monoid(Monoid,OperatorMonoid)>;\n\
    \    using H=function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;\n\n    struct\
    \ Node{\n        Node *l,*r;\n        int cnt,priority;\n        Monoid val,acc;\n\
    \        OperatorMonoid lazy;\n        bool rev;\n        Node()=default;\n  \
    \      Node(const Monoid &val,const OperatorMonoid &lazy,int priority):\n    \
    \    l(nullptr),r(nullptr),cnt(1),priority(priority),val(val),acc(val),lazy(lazy),rev(false){}\n\
    \    } *root=nullptr;\n\n    const F f;\n    const G g;\n    const H h;\n    const\
    \ Monoid M1;\n    const OperatorMonoid OM0;\n\n    int count(const Node *t){return\
    \ t?t->cnt:0;}\n    Monoid acc(const Node *t){return t?t->acc:M1;}\n\n    Node\
    \ *update(Node *t){\n        t->cnt=count(t->l)+count(t->r)+1;\n        t->acc=f(f(acc(t->l),t->val),acc(t->r));\n\
    \        return t;\n    }\n    Node *propagate(Node *t){\n        if(t and t->rev){\n\
    \            t->rev=false;\n            swap(t->l,t->r);\n            if(t->l)\
    \ t->l->rev^=1;\n            if(t->r) t->r->rev^=1;\n        }\n        if(t and\
    \ t->lazy!=OM0){\n            t->val=g(t->val,t->lazy);\n            if(t->l){\n\
    \                t->l->lazy=h(t->l->lazy,t->lazy);\n                t->l->acc=g(t->l->acc,t->lazy);\n\
    \            }\n            if(t->r){\n                t->r->lazy=h(t->r->lazy,t->lazy);\n\
    \                t->r->acc=g(t->r->acc,t->lazy);\n            }\n            t->lazy=OM0;\n\
    \        }\n        return update(t);\n    }\n\n    Node *merge(Node *l,Node *r){\n\
    \        if(!l or !r) return l?l:r;\n        if(l->priority>r->priority){\n  \
    \          l=propagate(l);\n            l->r=merge(l->r,r);\n            return\
    \ update(l);\n        }else{\n            r=propagate(r);\n            r->l=merge(l,r->l);\n\
    \            return update(r);\n        }\n    }\n    pair<Node *,Node *> split(Node\
    \ *t,int k){\n        if(!t) return {nullptr,nullptr};\n        t=propagate(t);\n\
    \        if(k<=count(t->l)){\n            auto s=split(t->l,k);\n            t->l=s.second;\n\
    \            return {s.first,update(t)};\n        }else{\n            auto s=split(t->r,k-count(t->l)-1);\n\
    \            t->r=s.first;\n            return {update(t),s.second};\n       \
    \ }\n    }\n\n    void insert(Node *&t,int k,const Monoid &x){\n        auto s=split(t,k);\n\
    \        t=merge(merge(s.first,new Node(x,OM0,xorshift())),s.second);\n    }\n\
    \    void erase(Node *&t,int k){\n        auto s=split(t,k);\n        t=merge(s.first,split(s.second,1).second);\n\
    \    }\n\n    Monoid query(Node *&t,int a,int b){\n        if(a>b) return M1;\n\
    \        auto x=split(t,a);\n        auto y=split(x.second,b-a);\n        auto\
    \ ret=acc(y.first);\n        t=merge(x.first,merge(y.first,y.second));\n     \
    \   return ret;\n    }\n    void update(Node *&t,int a,int b,const OperatorMonoid\
    \ &o){\n        if(a>b) return ;\n        auto x=split(t,a);\n        auto y=split(x.second,b-a);\n\
    \        y.first->lazy=h(y.first->lazy,o);\n        t=merge(x.first,merge(propagate(y.first),y.second));\n\
    \    }\n    void reverse(Node *&t,int a,int b){\n        if(a>b) return ;\n  \
    \      auto x=split(t,a);\n        auto y=split(x.second,b-a);\n        y.first->rev^=1;\n\
    \        t=merge(x.first,merge(y.first,y.second));\n    }\n    // [l,r)\u306E\u5148\
    \u982D\u304Cm\u306B\u306A\u308B\u307E\u3067\u5DE6\u30B7\u30D5\u30C8\n    void\
    \ rotate(Node *&t,int l,int m,int r){\n        reverse(t,l,r);\n        reverse(t,l,l+r-m);\n\
    \        reverse(t,l+r-m,r);   \n    }\n    void dump(Node *t,typename vector<Monoid>::iterator\
    \ &ite){\n        if(!t) return ;\n        t=propagate(t);\n        dump(t->l,ite);\n\
    \        *ite=t->val;\n        dump(t->r,++ite);\n    }\n\n    public:\n\n   \
    \ ImplicitTreap(const F &f,const G &g,const H &h,const Monoid &M1,const OperatorMonoid\
    \ &OM0):\n        f(f),g(g),h(h),M1(M1),OM0(OM0){}\n\n    int size(){return count(root);}\n\
    \    bool empty(){return !root;}\n\n    void build(const vector<Monoid> &v){\n\
    \        if(v.empty()) return ;\n        for(int i=(int)v.size()-1;i>=0;i--) insert(0,v[i]);\n\
    \    }\n\n    void insert(int k,const Monoid &x){insert(root,k,x);}\n    void\
    \ erase(int k){erase(root,k);}\n    void erase(int l,int r){\n        auto x=split(root,l);\n\
    \        auto y=split(x.second,r-l);\n        root=merge(x.first,y.second);\n\
    \    }\n    void reverse(int l,int r){reverse(root,l,r);}\n    Monoid query(int\
    \ l,int r){return query(root,l,r);}\n    void update(int l,int r,const OperatorMonoid\
    \ &x){update(root,l,r,x);}\n    vector<Monoid> dump(){\n        vector<Monoid>\
    \ ret(size());\n        auto ite=begin(ret);\n        dump(root,ite);\n      \
    \  return ret;\n    }\n\n    Monoid operator[](int idx){return query(idx,idx+1);}\n\
    };\n"
  code: "template<typename Monoid,typename OperatorMonoid>\nstruct ImplicitTreap{\n\
    \n    private:\n\n    inline int xorshift(){\n        static int x=122312555;\n\
    \        static int y=336261662;\n        static int z=558127122;\n        static\
    \ int w=917277772;\n        int t;\n        t=x^(x<<11);\n        x=y;y=z;z=w;\n\
    \        return w=(w^(w>>19))^(t^(t>>8));\n    }\n\n    using F=function<Monoid(Monoid,Monoid)>;\n\
    \    using G=function<Monoid(Monoid,OperatorMonoid)>;\n    using H=function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;\n\
    \n    struct Node{\n        Node *l,*r;\n        int cnt,priority;\n        Monoid\
    \ val,acc;\n        OperatorMonoid lazy;\n        bool rev;\n        Node()=default;\n\
    \        Node(const Monoid &val,const OperatorMonoid &lazy,int priority):\n  \
    \      l(nullptr),r(nullptr),cnt(1),priority(priority),val(val),acc(val),lazy(lazy),rev(false){}\n\
    \    } *root=nullptr;\n\n    const F f;\n    const G g;\n    const H h;\n    const\
    \ Monoid M1;\n    const OperatorMonoid OM0;\n\n    int count(const Node *t){return\
    \ t?t->cnt:0;}\n    Monoid acc(const Node *t){return t?t->acc:M1;}\n\n    Node\
    \ *update(Node *t){\n        t->cnt=count(t->l)+count(t->r)+1;\n        t->acc=f(f(acc(t->l),t->val),acc(t->r));\n\
    \        return t;\n    }\n    Node *propagate(Node *t){\n        if(t and t->rev){\n\
    \            t->rev=false;\n            swap(t->l,t->r);\n            if(t->l)\
    \ t->l->rev^=1;\n            if(t->r) t->r->rev^=1;\n        }\n        if(t and\
    \ t->lazy!=OM0){\n            t->val=g(t->val,t->lazy);\n            if(t->l){\n\
    \                t->l->lazy=h(t->l->lazy,t->lazy);\n                t->l->acc=g(t->l->acc,t->lazy);\n\
    \            }\n            if(t->r){\n                t->r->lazy=h(t->r->lazy,t->lazy);\n\
    \                t->r->acc=g(t->r->acc,t->lazy);\n            }\n            t->lazy=OM0;\n\
    \        }\n        return update(t);\n    }\n\n    Node *merge(Node *l,Node *r){\n\
    \        if(!l or !r) return l?l:r;\n        if(l->priority>r->priority){\n  \
    \          l=propagate(l);\n            l->r=merge(l->r,r);\n            return\
    \ update(l);\n        }else{\n            r=propagate(r);\n            r->l=merge(l,r->l);\n\
    \            return update(r);\n        }\n    }\n    pair<Node *,Node *> split(Node\
    \ *t,int k){\n        if(!t) return {nullptr,nullptr};\n        t=propagate(t);\n\
    \        if(k<=count(t->l)){\n            auto s=split(t->l,k);\n            t->l=s.second;\n\
    \            return {s.first,update(t)};\n        }else{\n            auto s=split(t->r,k-count(t->l)-1);\n\
    \            t->r=s.first;\n            return {update(t),s.second};\n       \
    \ }\n    }\n\n    void insert(Node *&t,int k,const Monoid &x){\n        auto s=split(t,k);\n\
    \        t=merge(merge(s.first,new Node(x,OM0,xorshift())),s.second);\n    }\n\
    \    void erase(Node *&t,int k){\n        auto s=split(t,k);\n        t=merge(s.first,split(s.second,1).second);\n\
    \    }\n\n    Monoid query(Node *&t,int a,int b){\n        if(a>b) return M1;\n\
    \        auto x=split(t,a);\n        auto y=split(x.second,b-a);\n        auto\
    \ ret=acc(y.first);\n        t=merge(x.first,merge(y.first,y.second));\n     \
    \   return ret;\n    }\n    void update(Node *&t,int a,int b,const OperatorMonoid\
    \ &o){\n        if(a>b) return ;\n        auto x=split(t,a);\n        auto y=split(x.second,b-a);\n\
    \        y.first->lazy=h(y.first->lazy,o);\n        t=merge(x.first,merge(propagate(y.first),y.second));\n\
    \    }\n    void reverse(Node *&t,int a,int b){\n        if(a>b) return ;\n  \
    \      auto x=split(t,a);\n        auto y=split(x.second,b-a);\n        y.first->rev^=1;\n\
    \        t=merge(x.first,merge(y.first,y.second));\n    }\n    // [l,r)\u306E\u5148\
    \u982D\u304Cm\u306B\u306A\u308B\u307E\u3067\u5DE6\u30B7\u30D5\u30C8\n    void\
    \ rotate(Node *&t,int l,int m,int r){\n        reverse(t,l,r);\n        reverse(t,l,l+r-m);\n\
    \        reverse(t,l+r-m,r);   \n    }\n    void dump(Node *t,typename vector<Monoid>::iterator\
    \ &ite){\n        if(!t) return ;\n        t=propagate(t);\n        dump(t->l,ite);\n\
    \        *ite=t->val;\n        dump(t->r,++ite);\n    }\n\n    public:\n\n   \
    \ ImplicitTreap(const F &f,const G &g,const H &h,const Monoid &M1,const OperatorMonoid\
    \ &OM0):\n        f(f),g(g),h(h),M1(M1),OM0(OM0){}\n\n    int size(){return count(root);}\n\
    \    bool empty(){return !root;}\n\n    void build(const vector<Monoid> &v){\n\
    \        if(v.empty()) return ;\n        for(int i=(int)v.size()-1;i>=0;i--) insert(0,v[i]);\n\
    \    }\n\n    void insert(int k,const Monoid &x){insert(root,k,x);}\n    void\
    \ erase(int k){erase(root,k);}\n    void erase(int l,int r){\n        auto x=split(root,l);\n\
    \        auto y=split(x.second,r-l);\n        root=merge(x.first,y.second);\n\
    \    }\n    void reverse(int l,int r){reverse(root,l,r);}\n    Monoid query(int\
    \ l,int r){return query(root,l,r);}\n    void update(int l,int r,const OperatorMonoid\
    \ &x){update(root,l,r,x);}\n    vector<Monoid> dump(){\n        vector<Monoid>\
    \ ret(size());\n        auto ite=begin(ret);\n        dump(root,ite);\n      \
    \  return ret;\n    }\n\n    Monoid operator[](int idx){return query(idx,idx+1);}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: BinarySearchTree/ImplicitTreap.cpp
  requiredBy: []
  timestamp: '2021-03-27 01:28:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki5398.test.cpp
  - test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
documentation_of: BinarySearchTree/ImplicitTreap.cpp
layout: document
redirect_from:
- /library/BinarySearchTree/ImplicitTreap.cpp
- /library/BinarySearchTree/ImplicitTreap.cpp.html
title: BinarySearchTree/ImplicitTreap.cpp
---

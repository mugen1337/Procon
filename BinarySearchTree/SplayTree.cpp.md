---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki5398_2.test.cpp
    title: test/yuki5398_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"BinarySearchTree/SplayTree.cpp\"\ntemplate<typename Monoid>\n\
    struct SplayTree{\npublic:\n    using F=function<Monoid(Monoid,Monoid)>;\n\n \
    \   struct Node{\n        Node *l,*r,*p;\n        Monoid val,sum;\n        int\
    \ sz;\n        bool rev;\n\n        bool is_root(){ return !p; }\n\n        Node(const\
    \ Monoid &val):l(nullptr),r(nullptr),p(nullptr),\n                           \
    \     val(val),sum(val),sz(1),rev(false){}\n    };\n\n    const F f;\n    const\
    \ Monoid e;\n\n    SplayTree(F f,Monoid e):f(f),e(e){}\n\n    int size(Node *t){return\
    \ t?t->sz:0;}\n    Monoid sum(Node *t){return t?t->sum:e;}\n\n    Node *build(const\
    \ vector<Monoid> &v){\n        return build(0,(int)v.size(),v);\n    }\n\n   \
    \ Node *build(){\n        return nullptr;\n    }\n\n    pair<Node *,Node *> split(Node\
    \ *t,int k){\n        if(!t) return {nullptr,nullptr};\n        push(t);\n   \
    \     if(k<=size(t->l)){\n            auto x=split(t->l,k);\n            t->l=x.second;\n\
    \            t->p=nullptr;\n            if(x.second) x.second->p=t;\n        \
    \    return {x.first,update(t)};\n        }else{\n            auto x=split(t->r,k-size(t->l)-1);\n\
    \            t->r=x.first;\n            t->p=nullptr;\n            if(x.first)\
    \ x.first->p=t;\n            return {update(t),x.second};\n        }\n    }\n\
    \    \n    Node *merge(Node *l,Node *r){\n        if(!l and !r) return nullptr;\n\
    \        if(!l){\n            splay(r);\n            return r;\n        }\n  \
    \      if(!r){\n            splay(l);\n            return l;\n        }\n    \
    \    splay(l);\n        splay(r);\n        l=get_right(l);\n        splay(l);\n\
    \        l->r=r;\n        r->p=l;\n        update(l);\n        return l;\n   \
    \ }\n\n    Node *insert(Node *&t,int k,Monoid val){\n        assert(k<=size(t));\n\
    \        if(!t){\n            t=new Node(val);\n            return t;\n      \
    \  }\n        splay(t);\n        auto x=split(t,k);\n        t=merge(merge(x.first,new\
    \ Node(val)),x.second);\n        return t;\n    }\n\n    Node *erase(Node *&t,int\
    \ k){\n        splay(t);\n        auto x=split(t,k);\n        auto y=split(x.second,1);\n\
    \        delete y.first;\n        t=merge(x.first,y.second);\n        return t;\n\
    \    }\n\n    // [a,b)\n    Monoid query(Node *&t,int a,int b){\n        splay(t);\n\
    \        auto x=split(t,a);\n        auto y=split(x.second,b-a);\n        auto\
    \ res=sum(y.first);\n        t=merge(merge(x.first,y.first),y.second);\n     \
    \   return res;\n    }\n\n    Node *push_front(Node *t,Monoid x){\n        if(!t){\n\
    \            t=new Node(x);\n            return t;\n        }\n        splay(t);\n\
    \        Node *cur=get_left(t),*add=new Node(x);\n        splay(cur);\n      \
    \  add->p=cur;\n        cur->l=add;\n        splay(add);\n        return add;\n\
    \    }\n\n    Node *push_back(Node *t,Monoid x){\n        if(!t){\n          \
    \  t=new Node(x);\n            return t;\n        }\n        Node *cur=get_right(t),*add=new\
    \ Node(x);\n        splay(cur);\n        add->p=cur;\n        cur->r=add;\n  \
    \      splay(add);\n        return add;\n    }\n\n    Node *reverse(Node *t,int\
    \ a,int b){\n        splay(t);\n        auto x=split(t,a);\n        auto y=split(x.second,b-a);\n\
    \        y.first->rev^=true;\n        return merge(x.first,merge(y.first,y.second));\n\
    \    }\n\n    // rotate v[l] <- v[m]\n    Node *rotate(Node *t,int a,int m,int\
    \ b){\n        t=reverse(t,a,b);\n        t=reverse(t,a,a+b-m);\n        t=reverse(t,a+b-m,b);\n\
    \        return t;\n    }\n\nprivate:\n\n    Node *build(int l,int r,const vector<Monoid>\
    \ &v){\n        if(l+1==r) return new Node(v[l]);\n        int m=(l+r)/2;\n  \
    \      return merge(build(l,m,v),build(m,r,v));\n    }\n    Node *get_left(Node\
    \ *cur){\n        while(true){\n            push(cur);\n            if(!cur->l)\
    \ return cur;\n            cur=cur->l;\n        }\n    }\n    Node *get_right(Node\
    \ *cur){\n        while(true){\n            push(cur);\n            if(!cur->r)\
    \ return cur;\n            cur=cur->r;\n        }\n    }\n    // t\u30921\u500B\
    \u4E0A\u306B\uFF0C\u53F3\u56DE\u8EE2\n    void rotr(Node *cur){\n        auto\
    \ *par=cur->p;\n        auto *parpar=par->p;\n        // A < cur < B < par < C\
    \ \n        // ((A) - cur - (B)) - par - (C) \n        auto *B=cur->r;\n     \
    \   par->l=B;\n        if(B) B->p=par;\n        cur->r=par;\n        par->p=cur;\n\
    \        update(par);// par\u304Ccur\u306E\u53F3\u5B50\u306B\u5909\u308F\u3063\
    \u305F\n        update(cur);\n        cur->p=parpar;\n        if(parpar){\n  \
    \          if(parpar->l==par) parpar->l=cur;\n            if(parpar->r==par) parpar->r=cur;\n\
    \            update(parpar);\n        }\n    }\n    // t\u30921\u500B\u4E0A\u306B\
    \uFF0C\u5DE6\u56DE\u8EE2\n    void rotl(Node *cur){\n        auto *par=cur->p;\n\
    \        auto *parpar=par->p;\n        // (C) - par - ((B) - cur - (A))\n    \
    \    // C < par < B < cur < A\n        auto *B=cur->l;\n        par->r=B;\n  \
    \      if(B) B->p=par;\n        cur->l=par;\n        par->p=cur;\n        update(par);//\
    \ par\u304Ccur\u306E\u53F3\u5B50\u306B\u5909\u308F\u3063\u305F\n        update(cur);\n\
    \        cur->p=parpar;\n        if(parpar){\n            if(parpar->l==par) parpar->l=cur;\n\
    \            if(parpar->r==par) parpar->r=cur;\n            update(parpar);\n\
    \        }\n    }\n    // \u5B50\u304B\u3089\u96C6\u7D04\n    Node *update(Node\
    \ *t){\n        t->sz=1;\n        t->sum=t->val;\n        if(t->l) t->sz+=t->l->sz,t->sum=f(t->l->sum,t->sum);\n\
    \        if(t->r) t->sz+=t->r->sz,t->sum=f(t->sum,t->r->sum);\n        return\
    \ t;\n    }\n\n    void push(Node *t){\n        if(t and t->rev){\n          \
    \  swap(t->l,t->r);\n            if(t->l) t->l->rev^=true;\n            if(t->r)\
    \ t->r->rev^=true;\n            t->rev=false;\n        }\n    }\n    void splay(Node\
    \ *cur){\n        push(cur);\n        while(!cur->is_root()){\n            auto\
    \ *par=cur->p;\n            if(par->is_root()){// zig\n                push(par);\n\
    \                push(cur);\n                if(par->l==cur) rotr(cur);\n    \
    \            else            rotl(cur);\n            }else{// zig-zig, zig-zag\n\
    \                auto *parpar=par->p;\n                push(parpar);\n       \
    \         push(par);\n                push(cur);\n                if(parpar->l==par){\n\
    \                    if(par->l==cur){// /\n                        rotr(par);\n\
    \                        rotr(cur);\n                    }else{// \u304F\n   \
    \                     rotl(cur);\n                        rotr(cur);\n       \
    \             }\n                }else{\n                    if(par->r==cur){\n\
    \                        rotl(par);\n                        rotl(cur);\n    \
    \                }else{\n                        rotr(cur);\n                \
    \        rotl(cur);\n                    }\n                }\n            }\n\
    \        }\n    }\n};\n"
  code: "template<typename Monoid>\nstruct SplayTree{\npublic:\n    using F=function<Monoid(Monoid,Monoid)>;\n\
    \n    struct Node{\n        Node *l,*r,*p;\n        Monoid val,sum;\n        int\
    \ sz;\n        bool rev;\n\n        bool is_root(){ return !p; }\n\n        Node(const\
    \ Monoid &val):l(nullptr),r(nullptr),p(nullptr),\n                           \
    \     val(val),sum(val),sz(1),rev(false){}\n    };\n\n    const F f;\n    const\
    \ Monoid e;\n\n    SplayTree(F f,Monoid e):f(f),e(e){}\n\n    int size(Node *t){return\
    \ t?t->sz:0;}\n    Monoid sum(Node *t){return t?t->sum:e;}\n\n    Node *build(const\
    \ vector<Monoid> &v){\n        return build(0,(int)v.size(),v);\n    }\n\n   \
    \ Node *build(){\n        return nullptr;\n    }\n\n    pair<Node *,Node *> split(Node\
    \ *t,int k){\n        if(!t) return {nullptr,nullptr};\n        push(t);\n   \
    \     if(k<=size(t->l)){\n            auto x=split(t->l,k);\n            t->l=x.second;\n\
    \            t->p=nullptr;\n            if(x.second) x.second->p=t;\n        \
    \    return {x.first,update(t)};\n        }else{\n            auto x=split(t->r,k-size(t->l)-1);\n\
    \            t->r=x.first;\n            t->p=nullptr;\n            if(x.first)\
    \ x.first->p=t;\n            return {update(t),x.second};\n        }\n    }\n\
    \    \n    Node *merge(Node *l,Node *r){\n        if(!l and !r) return nullptr;\n\
    \        if(!l){\n            splay(r);\n            return r;\n        }\n  \
    \      if(!r){\n            splay(l);\n            return l;\n        }\n    \
    \    splay(l);\n        splay(r);\n        l=get_right(l);\n        splay(l);\n\
    \        l->r=r;\n        r->p=l;\n        update(l);\n        return l;\n   \
    \ }\n\n    Node *insert(Node *&t,int k,Monoid val){\n        assert(k<=size(t));\n\
    \        if(!t){\n            t=new Node(val);\n            return t;\n      \
    \  }\n        splay(t);\n        auto x=split(t,k);\n        t=merge(merge(x.first,new\
    \ Node(val)),x.second);\n        return t;\n    }\n\n    Node *erase(Node *&t,int\
    \ k){\n        splay(t);\n        auto x=split(t,k);\n        auto y=split(x.second,1);\n\
    \        delete y.first;\n        t=merge(x.first,y.second);\n        return t;\n\
    \    }\n\n    // [a,b)\n    Monoid query(Node *&t,int a,int b){\n        splay(t);\n\
    \        auto x=split(t,a);\n        auto y=split(x.second,b-a);\n        auto\
    \ res=sum(y.first);\n        t=merge(merge(x.first,y.first),y.second);\n     \
    \   return res;\n    }\n\n    Node *push_front(Node *t,Monoid x){\n        if(!t){\n\
    \            t=new Node(x);\n            return t;\n        }\n        splay(t);\n\
    \        Node *cur=get_left(t),*add=new Node(x);\n        splay(cur);\n      \
    \  add->p=cur;\n        cur->l=add;\n        splay(add);\n        return add;\n\
    \    }\n\n    Node *push_back(Node *t,Monoid x){\n        if(!t){\n          \
    \  t=new Node(x);\n            return t;\n        }\n        Node *cur=get_right(t),*add=new\
    \ Node(x);\n        splay(cur);\n        add->p=cur;\n        cur->r=add;\n  \
    \      splay(add);\n        return add;\n    }\n\n    Node *reverse(Node *t,int\
    \ a,int b){\n        splay(t);\n        auto x=split(t,a);\n        auto y=split(x.second,b-a);\n\
    \        y.first->rev^=true;\n        return merge(x.first,merge(y.first,y.second));\n\
    \    }\n\n    // rotate v[l] <- v[m]\n    Node *rotate(Node *t,int a,int m,int\
    \ b){\n        t=reverse(t,a,b);\n        t=reverse(t,a,a+b-m);\n        t=reverse(t,a+b-m,b);\n\
    \        return t;\n    }\n\nprivate:\n\n    Node *build(int l,int r,const vector<Monoid>\
    \ &v){\n        if(l+1==r) return new Node(v[l]);\n        int m=(l+r)/2;\n  \
    \      return merge(build(l,m,v),build(m,r,v));\n    }\n    Node *get_left(Node\
    \ *cur){\n        while(true){\n            push(cur);\n            if(!cur->l)\
    \ return cur;\n            cur=cur->l;\n        }\n    }\n    Node *get_right(Node\
    \ *cur){\n        while(true){\n            push(cur);\n            if(!cur->r)\
    \ return cur;\n            cur=cur->r;\n        }\n    }\n    // t\u30921\u500B\
    \u4E0A\u306B\uFF0C\u53F3\u56DE\u8EE2\n    void rotr(Node *cur){\n        auto\
    \ *par=cur->p;\n        auto *parpar=par->p;\n        // A < cur < B < par < C\
    \ \n        // ((A) - cur - (B)) - par - (C) \n        auto *B=cur->r;\n     \
    \   par->l=B;\n        if(B) B->p=par;\n        cur->r=par;\n        par->p=cur;\n\
    \        update(par);// par\u304Ccur\u306E\u53F3\u5B50\u306B\u5909\u308F\u3063\
    \u305F\n        update(cur);\n        cur->p=parpar;\n        if(parpar){\n  \
    \          if(parpar->l==par) parpar->l=cur;\n            if(parpar->r==par) parpar->r=cur;\n\
    \            update(parpar);\n        }\n    }\n    // t\u30921\u500B\u4E0A\u306B\
    \uFF0C\u5DE6\u56DE\u8EE2\n    void rotl(Node *cur){\n        auto *par=cur->p;\n\
    \        auto *parpar=par->p;\n        // (C) - par - ((B) - cur - (A))\n    \
    \    // C < par < B < cur < A\n        auto *B=cur->l;\n        par->r=B;\n  \
    \      if(B) B->p=par;\n        cur->l=par;\n        par->p=cur;\n        update(par);//\
    \ par\u304Ccur\u306E\u53F3\u5B50\u306B\u5909\u308F\u3063\u305F\n        update(cur);\n\
    \        cur->p=parpar;\n        if(parpar){\n            if(parpar->l==par) parpar->l=cur;\n\
    \            if(parpar->r==par) parpar->r=cur;\n            update(parpar);\n\
    \        }\n    }\n    // \u5B50\u304B\u3089\u96C6\u7D04\n    Node *update(Node\
    \ *t){\n        t->sz=1;\n        t->sum=t->val;\n        if(t->l) t->sz+=t->l->sz,t->sum=f(t->l->sum,t->sum);\n\
    \        if(t->r) t->sz+=t->r->sz,t->sum=f(t->sum,t->r->sum);\n        return\
    \ t;\n    }\n\n    void push(Node *t){\n        if(t and t->rev){\n          \
    \  swap(t->l,t->r);\n            if(t->l) t->l->rev^=true;\n            if(t->r)\
    \ t->r->rev^=true;\n            t->rev=false;\n        }\n    }\n    void splay(Node\
    \ *cur){\n        push(cur);\n        while(!cur->is_root()){\n            auto\
    \ *par=cur->p;\n            if(par->is_root()){// zig\n                push(par);\n\
    \                push(cur);\n                if(par->l==cur) rotr(cur);\n    \
    \            else            rotl(cur);\n            }else{// zig-zig, zig-zag\n\
    \                auto *parpar=par->p;\n                push(parpar);\n       \
    \         push(par);\n                push(cur);\n                if(parpar->l==par){\n\
    \                    if(par->l==cur){// /\n                        rotr(par);\n\
    \                        rotr(cur);\n                    }else{// \u304F\n   \
    \                     rotl(cur);\n                        rotr(cur);\n       \
    \             }\n                }else{\n                    if(par->r==cur){\n\
    \                        rotl(par);\n                        rotl(cur);\n    \
    \                }else{\n                        rotr(cur);\n                \
    \        rotl(cur);\n                    }\n                }\n            }\n\
    \        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: BinarySearchTree/SplayTree.cpp
  requiredBy: []
  timestamp: '2021-04-21 21:33:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki5398_2.test.cpp
documentation_of: BinarySearchTree/SplayTree.cpp
layout: document
redirect_from:
- /library/BinarySearchTree/SplayTree.cpp
- /library/BinarySearchTree/SplayTree.cpp.html
title: BinarySearchTree/SplayTree.cpp
---

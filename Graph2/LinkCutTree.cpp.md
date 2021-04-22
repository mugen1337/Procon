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
  bundledCode: "#line 1 \"Graph2/LinkCutTree.cpp\"\ntemplate<typename Monoid>\nstruct\
    \ LinkCutTree{\n\n    using F=function<Monoid(Monoid,Monoid)>;\n    using G=function<Monoid(Monoid)>;\n\
    \n    LinkCutTree(int n,F f,Monoid e,G flip=nullptr):f(f),e(e),flip(flip){\n \
    \       for(int i=0;i<n;i++) nodes.push_back(new Node(e));\n    }\n\n    LinkCutTree(const\
    \ vector<Monoid> &v,F f,Monoid e,G flip=nullptr):f(f),e(e),flip(flip){\n     \
    \   for(const auto &x:v) nodes.push_back(new Node(x));\n    }\n\n    // v \u3092\
    \ root \u306B\n    void evert(int v){\n        expose(nodes[v]);\n        reverse(nodes[v]);\n\
    \    }\n\n    // link\n    void link(int ch,int par){\n        evert(ch);\n  \
    \      expose(nodes[par]);\n        nodes[ch]->p=nodes[par];\n        nodes[par]->r=nodes[ch];\n\
    \        recalc(nodes[par]);\n    }\n\n    // cut v-(v->p)\n    void cut(int v){\n\
    \        expose(nodes[v]);\n        nodes[v]->l->p=nullptr;\n        nodes[v]->l=nullptr;\n\
    \        recalc(nodes[v]);\n    }\n    // check u-v in E, cut u-v\n    void cut(int\
    \ u,int v){\n        evert(u);\n        expose(nodes[v]);\n        assert(nodes[u]==nodes[v]->l);\n\
    \        nodes[v]->l->p=nullptr;\n        nodes[v]->l=nullptr;\n        recalc(nodes[v]);\n\
    \    }\n\n    // path query u-v\n    // evert(u), expose(v)\u306E\u3042\u3068\uFF0C\
    splay(v)\u3055\u308C\u3066\u3044\u308B\u306E\u3067\n    // v\u3092root\u3068\u3059\
    \u308B\u4E8C\u5206\u6728\u306Bpath(u,v)\u306E\u9802\u70B9\u306E\u307F\u304C\u5168\
    \u3066\u542B\u307E\u308C\u308B\u72B6\u614B\u306B\n    // -> sum\u3092\u8FD4\u3059\
    \u3060\u3051\u3067\u3088\u3044\n    Monoid query(int u,int v){\n        evert(u);\n\
    \        expose(nodes[v]);\n        return nodes[v]->sum;\n    }\n\n    Monoid\
    \ get(int v){ return nodes[v]->val; }\n\n    void update(int v,const Monoid &x){\n\
    \        expose(nodes[v]);\n        nodes[v]->val=x;\n        recalc(nodes[v]);\n\
    \    }\n    \nprivate:\n    struct Node{\n        Node *l,*r,*p;\n        Monoid\
    \ val,sum;\n        int sz;\n        bool rev;\n        bool is_root()const{\n\
    \            return (!p or (p->l!=(this) and p->r!=(this)));\n        }\n    \
    \    Node(const Monoid &x)\n            :l(nullptr),r(nullptr),p(nullptr),\n \
    \           val(x),sum(x),sz(1),rev(false){}\n    };\n\n    const Monoid e;\n\
    \    const F f;\n    const G flip;\n    vector<Node *> nodes;\n\n    // root \u304B\
    \u3089 v \u3078\u306E\u30D1\u30B9\u3092\u78BA\u4FDD, \u5916\u304B\u3089\u89E6\u3089\
    \u306A\u3044\n    void expose(Node *t){\n        Node *pre=nullptr;\n        for(Node\
    \ *cur=t;cur;cur=cur->p){\n            splay(cur);\n            cur->r=pre;\n\
    \            recalc(cur);\n            pre=cur;\n        }\n        splay(t);\n\
    \    }\n    // t\u30921\u500B\u4E0A\u306B\uFF0C\u53F3\u56DE\u8EE2\n    void rotr(Node\
    \ *t){\n        // ((A) - lch - (B)) - t - (C) \n        Node *lch=t->l;// lch->top\n\
    \        t->l=lch->r;\n        if(lch->r) lch->r->p=t;// B\n        lch->p=t->p;\n\
    \        if(t->p){\n            if(t->p->l==t) t->p->l=lch;\n            if(t->p->r==t)\
    \ t->p->r=lch;\n        }\n        lch->r=t;\n        t->p=lch;\n        recalc(t);\n\
    \        recalc(lch);\n    }\n    // t\u30921\u500B\u4E0A\u306B\uFF0C\u5DE6\u56DE\
    \u8EE2\n    void rotl(Node *t){\n        // (C) - t - ((B) - rch - (A) )\n   \
    \     Node *rch=t->r;// lch->top\n        t->r=rch->l;\n        if(rch->l) rch->l->p=t;//\
    \ B\n        rch->p=t->p;\n        if(t->p){\n            if(t->p->l==t) t->p->l=rch;\n\
    \            if(t->p->r==t) t->p->r=rch;\n        }\n        rch->l=t;\n     \
    \   t->p=rch;\n        recalc(t);\n        recalc(rch);\n    }\n\n    int size(Node\
    \ *t){ return (t?t->sz:0); }\n\n    void recalc(Node *t){\n        if(!t) return\
    \ ;\n        t->sz=size(t->l)+1+size(t->r);\n        t->sum=t->val;\n        if(t->l)\
    \ t->sum=f(t->l->sum,t->sum);\n        if(t->r) t->sum=f(t->sum,t->r->sum);\n\
    \    }\n\n    void push(Node *t){\n        if(t->rev){\n            if(t->l) reverse(t->l);\n\
    \            if(t->r) reverse(t->r);\n            t->rev=false;\n        }\n \
    \   }\n\n    void reverse(Node *t){\n        swap(t->l,t->r);\n        if(flip)\
    \ t->sum=flip(t->sum);\n        t->rev^=true;\n    }\n    \n    void splay(Node\
    \ *cur){\n        push(cur);\n        while(!cur->is_root()){\n            Node\
    \ *par=cur->p;\n            if(par->is_root()){// zig\n                push(par);\n\
    \                push(cur);\n                if(par->l==cur) rotr(par);\n    \
    \            else            rotl(par);\n            }else{// zig-zig, zig-zag\n\
    \                Node *parpar=par->p;\n                push(parpar);\n       \
    \         push(par);\n                push(cur);\n                if(cur==par->l){\n\
    \                    if(par==parpar->l){\n                        rotr(parpar);\n\
    \                        rotr(par);\n                    }else{\n            \
    \            rotr(par);\n                        rotl(parpar);\n             \
    \       }\n                }else{\n                    if(par==parpar->l){\n \
    \                       rotl(par);\n                        rotr(parpar);\n  \
    \                  }else{\n                        rotl(parpar);\n           \
    \             rotl(par);\n                    }\n                }\n         \
    \   }\n        }\n    }\n};\n"
  code: "template<typename Monoid>\nstruct LinkCutTree{\n\n    using F=function<Monoid(Monoid,Monoid)>;\n\
    \    using G=function<Monoid(Monoid)>;\n\n    LinkCutTree(int n,F f,Monoid e,G\
    \ flip=nullptr):f(f),e(e),flip(flip){\n        for(int i=0;i<n;i++) nodes.push_back(new\
    \ Node(e));\n    }\n\n    LinkCutTree(const vector<Monoid> &v,F f,Monoid e,G flip=nullptr):f(f),e(e),flip(flip){\n\
    \        for(const auto &x:v) nodes.push_back(new Node(x));\n    }\n\n    // v\
    \ \u3092 root \u306B\n    void evert(int v){\n        expose(nodes[v]);\n    \
    \    reverse(nodes[v]);\n    }\n\n    // link\n    void link(int ch,int par){\n\
    \        evert(ch);\n        expose(nodes[par]);\n        nodes[ch]->p=nodes[par];\n\
    \        nodes[par]->r=nodes[ch];\n        recalc(nodes[par]);\n    }\n\n    //\
    \ cut v-(v->p)\n    void cut(int v){\n        expose(nodes[v]);\n        nodes[v]->l->p=nullptr;\n\
    \        nodes[v]->l=nullptr;\n        recalc(nodes[v]);\n    }\n    // check\
    \ u-v in E, cut u-v\n    void cut(int u,int v){\n        evert(u);\n        expose(nodes[v]);\n\
    \        assert(nodes[u]==nodes[v]->l);\n        nodes[v]->l->p=nullptr;\n   \
    \     nodes[v]->l=nullptr;\n        recalc(nodes[v]);\n    }\n\n    // path query\
    \ u-v\n    // evert(u), expose(v)\u306E\u3042\u3068\uFF0Csplay(v)\u3055\u308C\u3066\
    \u3044\u308B\u306E\u3067\n    // v\u3092root\u3068\u3059\u308B\u4E8C\u5206\u6728\
    \u306Bpath(u,v)\u306E\u9802\u70B9\u306E\u307F\u304C\u5168\u3066\u542B\u307E\u308C\
    \u308B\u72B6\u614B\u306B\n    // -> sum\u3092\u8FD4\u3059\u3060\u3051\u3067\u3088\
    \u3044\n    Monoid query(int u,int v){\n        evert(u);\n        expose(nodes[v]);\n\
    \        return nodes[v]->sum;\n    }\n\n    Monoid get(int v){ return nodes[v]->val;\
    \ }\n\n    void update(int v,const Monoid &x){\n        expose(nodes[v]);\n  \
    \      nodes[v]->val=x;\n        recalc(nodes[v]);\n    }\n    \nprivate:\n  \
    \  struct Node{\n        Node *l,*r,*p;\n        Monoid val,sum;\n        int\
    \ sz;\n        bool rev;\n        bool is_root()const{\n            return (!p\
    \ or (p->l!=(this) and p->r!=(this)));\n        }\n        Node(const Monoid &x)\n\
    \            :l(nullptr),r(nullptr),p(nullptr),\n            val(x),sum(x),sz(1),rev(false){}\n\
    \    };\n\n    const Monoid e;\n    const F f;\n    const G flip;\n    vector<Node\
    \ *> nodes;\n\n    // root \u304B\u3089 v \u3078\u306E\u30D1\u30B9\u3092\u78BA\
    \u4FDD, \u5916\u304B\u3089\u89E6\u3089\u306A\u3044\n    void expose(Node *t){\n\
    \        Node *pre=nullptr;\n        for(Node *cur=t;cur;cur=cur->p){\n      \
    \      splay(cur);\n            cur->r=pre;\n            recalc(cur);\n      \
    \      pre=cur;\n        }\n        splay(t);\n    }\n    // t\u30921\u500B\u4E0A\
    \u306B\uFF0C\u53F3\u56DE\u8EE2\n    void rotr(Node *t){\n        // ((A) - lch\
    \ - (B)) - t - (C) \n        Node *lch=t->l;// lch->top\n        t->l=lch->r;\n\
    \        if(lch->r) lch->r->p=t;// B\n        lch->p=t->p;\n        if(t->p){\n\
    \            if(t->p->l==t) t->p->l=lch;\n            if(t->p->r==t) t->p->r=lch;\n\
    \        }\n        lch->r=t;\n        t->p=lch;\n        recalc(t);\n       \
    \ recalc(lch);\n    }\n    // t\u30921\u500B\u4E0A\u306B\uFF0C\u5DE6\u56DE\u8EE2\
    \n    void rotl(Node *t){\n        // (C) - t - ((B) - rch - (A) )\n        Node\
    \ *rch=t->r;// lch->top\n        t->r=rch->l;\n        if(rch->l) rch->l->p=t;//\
    \ B\n        rch->p=t->p;\n        if(t->p){\n            if(t->p->l==t) t->p->l=rch;\n\
    \            if(t->p->r==t) t->p->r=rch;\n        }\n        rch->l=t;\n     \
    \   t->p=rch;\n        recalc(t);\n        recalc(rch);\n    }\n\n    int size(Node\
    \ *t){ return (t?t->sz:0); }\n\n    void recalc(Node *t){\n        if(!t) return\
    \ ;\n        t->sz=size(t->l)+1+size(t->r);\n        t->sum=t->val;\n        if(t->l)\
    \ t->sum=f(t->l->sum,t->sum);\n        if(t->r) t->sum=f(t->sum,t->r->sum);\n\
    \    }\n\n    void push(Node *t){\n        if(t->rev){\n            if(t->l) reverse(t->l);\n\
    \            if(t->r) reverse(t->r);\n            t->rev=false;\n        }\n \
    \   }\n\n    void reverse(Node *t){\n        swap(t->l,t->r);\n        if(flip)\
    \ t->sum=flip(t->sum);\n        t->rev^=true;\n    }\n    \n    void splay(Node\
    \ *cur){\n        push(cur);\n        while(!cur->is_root()){\n            Node\
    \ *par=cur->p;\n            if(par->is_root()){// zig\n                push(par);\n\
    \                push(cur);\n                if(par->l==cur) rotr(par);\n    \
    \            else            rotl(par);\n            }else{// zig-zig, zig-zag\n\
    \                Node *parpar=par->p;\n                push(parpar);\n       \
    \         push(par);\n                push(cur);\n                if(cur==par->l){\n\
    \                    if(par==parpar->l){\n                        rotr(parpar);\n\
    \                        rotr(par);\n                    }else{\n            \
    \            rotr(par);\n                        rotl(parpar);\n             \
    \       }\n                }else{\n                    if(par==parpar->l){\n \
    \                       rotl(par);\n                        rotr(parpar);\n  \
    \                  }else{\n                        rotl(parpar);\n           \
    \             rotl(par);\n                    }\n                }\n         \
    \   }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph2/LinkCutTree.cpp
  requiredBy: []
  timestamp: '2021-04-22 19:02:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph2/LinkCutTree.cpp
layout: document
redirect_from:
- /library/Graph2/LinkCutTree.cpp
- /library/Graph2/LinkCutTree.cpp.html
title: Graph2/LinkCutTree.cpp
---

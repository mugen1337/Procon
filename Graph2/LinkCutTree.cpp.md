---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
    title: test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph2/LinkCutTree.cpp\"\ntemplate<typename Monoid>\nstruct\
    \ LinkCutTree{\n\n    using F=function<Monoid(Monoid,Monoid)>;\n    using G=function<Monoid(Monoid)>;\n\
    \n    LinkCutTree(int n,F f,Monoid e,G flip=nullptr):f(f),e(e),flip(flip){\n \
    \       for(int i=0;i<n;i++) nodes.push_back(new Node(e,i));\n    }\n\n    LinkCutTree(const\
    \ vector<Monoid> &v,F f,Monoid e,G flip=nullptr):f(f),e(e),flip(flip){\n     \
    \   for(int i=0;i<(int)v.size();i++) nodes.push_back(new Node(v[i],i));\n    }\n\
    \n    // v \u3092 root \u306B\n    void evert(int v){\n        expose(nodes[v]);\n\
    \        reverse(nodes[v]);\n    }\n\n    // link\n    void link(int ch,int par){\n\
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
    \      nodes[v]->val=x;\n        recalc(nodes[v]);\n    }\n    \n    // verified\n\
    \    int get_root(int v){\n        Node *cur=nodes[v];\n        expose(cur);\n\
    \        while(cur->l){\n            push(cur);\n            cur=cur->l;\n   \
    \     }\n        return cur->idx;\n    }\n    \n    // verified\n    int lca(int\
    \ u,int v){\n        if(get_root(u)!=get_root(v)) return -1;\n        expose(nodes[u]);\n\
    \        return expose(nodes[v]);\n    }\n\n    // \u672Averify\n    int depth(int\
    \ v){\n        expose(nodes[v]);\n        return size(nodes[v])-1;\n    }\n  \
    \  // \u672Averify\n    // \u30E4\u30D0\u304B\u3063\u305F\u3089path query\u3067\
    \u5404\u9802\u70B91\u3092\u306E\u305B\u308D\n    int distance(int u,int v){\n\
    \        int p=lca(u,v);\n        if(p<0) return -1;\n        return depth(u)+depth(v)-depth(p)*2;\n\
    \    }\n    \nprivate:\n    struct Node{\n        Node *l,*r,*p;\n        Monoid\
    \ val,sum;\n        int sz,idx;\n        bool rev;\n        bool is_root()const{\n\
    \            return (!p or (p->l!=(this) and p->r!=(this)));\n        }\n    \
    \    Node(const Monoid &x,int idx)\n            :l(nullptr),r(nullptr),p(nullptr),\n\
    \            val(x),sum(x),sz(1),idx(idx),rev(false){}\n    };\n\n    const Monoid\
    \ e;\n    const F f;\n    const G flip;\n    vector<Node *> nodes;\n\n    int\
    \ expose(Node *t){\n        Node *pre=nullptr;\n        for(Node *cur=t;cur;cur=cur->p){\n\
    \            splay(cur);\n            cur->r=pre;\n            recalc(cur);\n\
    \            pre=cur;\n        }\n        splay(t);\n        return pre->idx;\n\
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
    \ Node(e,i));\n    }\n\n    LinkCutTree(const vector<Monoid> &v,F f,Monoid e,G\
    \ flip=nullptr):f(f),e(e),flip(flip){\n        for(int i=0;i<(int)v.size();i++)\
    \ nodes.push_back(new Node(v[i],i));\n    }\n\n    // v \u3092 root \u306B\n \
    \   void evert(int v){\n        expose(nodes[v]);\n        reverse(nodes[v]);\n\
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
    \    }\n    \n    // verified\n    int get_root(int v){\n        Node *cur=nodes[v];\n\
    \        expose(cur);\n        while(cur->l){\n            push(cur);\n      \
    \      cur=cur->l;\n        }\n        return cur->idx;\n    }\n    \n    // verified\n\
    \    int lca(int u,int v){\n        if(get_root(u)!=get_root(v)) return -1;\n\
    \        expose(nodes[u]);\n        return expose(nodes[v]);\n    }\n\n    //\
    \ \u672Averify\n    int depth(int v){\n        expose(nodes[v]);\n        return\
    \ size(nodes[v])-1;\n    }\n    // \u672Averify\n    // \u30E4\u30D0\u304B\u3063\
    \u305F\u3089path query\u3067\u5404\u9802\u70B91\u3092\u306E\u305B\u308D\n    int\
    \ distance(int u,int v){\n        int p=lca(u,v);\n        if(p<0) return -1;\n\
    \        return depth(u)+depth(v)-depth(p)*2;\n    }\n    \nprivate:\n    struct\
    \ Node{\n        Node *l,*r,*p;\n        Monoid val,sum;\n        int sz,idx;\n\
    \        bool rev;\n        bool is_root()const{\n            return (!p or (p->l!=(this)\
    \ and p->r!=(this)));\n        }\n        Node(const Monoid &x,int idx)\n    \
    \        :l(nullptr),r(nullptr),p(nullptr),\n            val(x),sum(x),sz(1),idx(idx),rev(false){}\n\
    \    };\n\n    const Monoid e;\n    const F f;\n    const G flip;\n    vector<Node\
    \ *> nodes;\n\n    int expose(Node *t){\n        Node *pre=nullptr;\n        for(Node\
    \ *cur=t;cur;cur=cur->p){\n            splay(cur);\n            cur->r=pre;\n\
    \            recalc(cur);\n            pre=cur;\n        }\n        splay(t);\n\
    \        return pre->idx;\n    }\n    // t\u30921\u500B\u4E0A\u306B\uFF0C\u53F3\
    \u56DE\u8EE2\n    void rotr(Node *t){\n        // ((A) - lch - (B)) - t - (C)\
    \ \n        Node *lch=t->l;// lch->top\n        t->l=lch->r;\n        if(lch->r)\
    \ lch->r->p=t;// B\n        lch->p=t->p;\n        if(t->p){\n            if(t->p->l==t)\
    \ t->p->l=lch;\n            if(t->p->r==t) t->p->r=lch;\n        }\n        lch->r=t;\n\
    \        t->p=lch;\n        recalc(t);\n        recalc(lch);\n    }\n    // t\u3092\
    1\u500B\u4E0A\u306B\uFF0C\u5DE6\u56DE\u8EE2\n    void rotl(Node *t){\n       \
    \ // (C) - t - ((B) - rch - (A) )\n        Node *rch=t->r;// lch->top\n      \
    \  t->r=rch->l;\n        if(rch->l) rch->l->p=t;// B\n        rch->p=t->p;\n \
    \       if(t->p){\n            if(t->p->l==t) t->p->l=rch;\n            if(t->p->r==t)\
    \ t->p->r=rch;\n        }\n        rch->l=t;\n        t->p=rch;\n        recalc(t);\n\
    \        recalc(rch);\n    }\n\n    int size(Node *t){ return (t?t->sz:0); }\n\
    \n    void recalc(Node *t){\n        if(!t) return ;\n        t->sz=size(t->l)+1+size(t->r);\n\
    \        t->sum=t->val;\n        if(t->l) t->sum=f(t->l->sum,t->sum);\n      \
    \  if(t->r) t->sum=f(t->sum,t->r->sum);\n    }\n\n    void push(Node *t){\n  \
    \      if(t->rev){\n            if(t->l) reverse(t->l);\n            if(t->r)\
    \ reverse(t->r);\n            t->rev=false;\n        }\n    }\n\n    void reverse(Node\
    \ *t){\n        swap(t->l,t->r);\n        if(flip) t->sum=flip(t->sum);\n    \
    \    t->rev^=true;\n    }\n    \n    void splay(Node *cur){\n        push(cur);\n\
    \        while(!cur->is_root()){\n            Node *par=cur->p;\n            if(par->is_root()){//\
    \ zig\n                push(par);\n                push(cur);\n              \
    \  if(par->l==cur) rotr(par);\n                else            rotl(par);\n  \
    \          }else{// zig-zig, zig-zag\n                Node *parpar=par->p;\n \
    \               push(parpar);\n                push(par);\n                push(cur);\n\
    \                if(cur==par->l){\n                    if(par==parpar->l){\n \
    \                       rotr(parpar);\n                        rotr(par);\n  \
    \                  }else{\n                        rotr(par);\n              \
    \          rotl(parpar);\n                    }\n                }else{\n    \
    \                if(par==parpar->l){\n                        rotl(par);\n   \
    \                     rotr(parpar);\n                    }else{\n            \
    \            rotl(parpar);\n                        rotl(par);\n             \
    \       }\n                }\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph2/LinkCutTree.cpp
  requiredBy: []
  timestamp: '2021-04-22 23:00:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
documentation_of: Graph2/LinkCutTree.cpp
layout: document
title: Link Cut Tree
---

# 概要  
Link Cut Tree

# 仕様  
各操作で根が変わったり変わらなかったりする  
- evert(v) : vをrootに
- link(u, v) : u-v辺をはる
- cut(v) : vとvの親を切る
- cut(u, v) : u-v辺を切る．あるかチェックもする
- query(u, v) : path query
- get_root(u) : 今のrootを返す
- lca(u, v) : u, vのLeast Common Ancestor
- deppth(v) : 今の木のrootからみたvの深さ
- distance(u, v) : 今の木のu-vの距離
大体どれもならしlogNらしい  
オリジナルでつけたのでdepth, distanceはまだverifyできていない．

# ref
https://www.slideshare.net/iwiwi/2-12188845
https://ei1333.hateblo.jp/entry/2018/05/29/011140
https://sotanishy.github.io/competitive-programming-library/tree/link_cut_tree.cpp

# todo
部分木クエリについての理解

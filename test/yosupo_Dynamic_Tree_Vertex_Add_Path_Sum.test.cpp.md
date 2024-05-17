---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Tree/LinkCutTree.hpp
    title: Tree/LinkCutTree.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int i=0;i<(n);i++)\n#define\
    \ debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n#define mod\
    \ 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\n\
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \nstruct IOSetup{\n    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n\
    \        cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp\"\
    \n\n#line 1 \"Tree/LinkCutTree.hpp\"\ntemplate<typename Monoid>\nstruct LinkCutTree{\n\
    \n    using F=function<Monoid(Monoid,Monoid)>;\n    using G=function<Monoid(Monoid)>;\n\
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
    \      nodes[v]->val=x;\n        recalc(nodes[v]);\n    }\n    \n    int get_root(int\
    \ v){\n        Node *cur=nodes[v];\n        expose(cur);\n        while(cur->l){\n\
    \            push(cur);\n            cur=cur->l;\n        }\n        splay(cur);\n\
    \        return cur->idx;\n    }\n    \n    // not connected -> return -1\n  \
    \  int lca(int u,int v){\n        if(!is_connected(u,v)) return -1;\n        expose(nodes[u]);\n\
    \        return expose(nodes[v]);\n    }\n\n    // faster than get_root(u)==get_root(v)\n\
    \    bool is_connected(int u,int v){\n        if(u==v) return true;\n        expose(nodes[u]);\n\
    \        expose(nodes[v]);\n        return bool(nodes[u]->p);\n    }\n\n    //\
    \ \u672Averify\n    int depth(int v){\n        expose(nodes[v]);\n        return\
    \ size(nodes[v])-1;\n    }\n    // \u672Averify\n    // \u30E4\u30D0\u304B\u3063\
    \u305F\u3089path query\u3067\u5404\u9802\u70B91\u3092\u306E\u305B\u308D\n    int\
    \ distance(int u,int v){\n        int p=lca(u,v);\n        if(p<0) return -1;\n\
    \        return depth(u)+depth(v)-depth(p)*2;\n    }\n    \nprivate:\n    struct\
    \ Node{\n        Node *l,*r,*p;\n        Monoid val,sum;\n        int sz,idx;\n\
    \        bool rev;\n        bool is_root()const{\n            return (!p or (p->l!=(this)\
    \ and p->r!=(this)));\n        }\n        Node(const Monoid &x,int idx)\n    \
    \        :l(nullptr),r(nullptr),p(nullptr),\n            val(x),sum(x),sz(1),idx(idx),rev(false){}\n\
    \    };\n\n    const F f;\n    const Monoid e;\n    const G flip;\n    vector<Node\
    \ *> nodes;\n\n    int expose(Node *t){\n        Node *pre=nullptr;\n        for(Node\
    \ *cur=t;cur;cur=cur->p){\n            splay(cur);\n            cur->r=pre;\n\
    \            recalc(cur);\n            pre=cur;\n        }\n        splay(t);\n\
    \        return pre->idx;\n    }\n    // t\u30921\u500B\u4E0B\u3078\n    void\
    \ rotr(Node *t){\n        // ((A) - lch - (B)) - t - (C) \n        Node *lch=t->l;//\
    \ lch->top\n        t->l=lch->r;\n        if(lch->r) lch->r->p=t;// B\n      \
    \  lch->p=t->p;\n        if(t->p){\n            if(t->p->l==t) t->p->l=lch;\n\
    \            if(t->p->r==t) t->p->r=lch;\n        }\n        lch->r=t;\n     \
    \   t->p=lch;\n        recalc(t);\n        recalc(lch);\n    }\n    void rotl(Node\
    \ *t){\n        // (C) - t - ((B) - rch - (A) )\n        Node *rch=t->r;// lch->top\n\
    \        t->r=rch->l;\n        if(rch->l) rch->l->p=t;// B\n        rch->p=t->p;\n\
    \        if(t->p){\n            if(t->p->l==t) t->p->l=rch;\n            if(t->p->r==t)\
    \ t->p->r=rch;\n        }\n        rch->l=t;\n        t->p=rch;\n        recalc(t);\n\
    \        recalc(rch);\n    }\n\n    int size(Node *t) const { return (t?t->sz:0);\
    \ }\n\n    void recalc(Node *t){\n        if(!t) return ;\n        t->sz=size(t->l)+1+size(t->r);\n\
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
    \       }\n                }\n            }\n        }\n    }\n};\n#line 6 \"\
    test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp\"\n\nsigned main(){\n  \
    \  int n,q;cin>>n>>q;\n    vector<ll> v(n);\n    cin>>v;\n\n    LinkCutTree<ll>\
    \ lct(v,[](ll a,ll b){return a+b;},0);\n\n    rep(i,n-1){\n        int u,v;cin>>u>>v;\n\
    \        lct.link(u,v);\n    }\n\n    while(q--){\n        int type;cin>>type;\n\
    \        if(type==0){\n            int a,b,c,d;cin>>a>>b>>c>>d;\n            lct.cut(a,b);\n\
    \            lct.link(c,d);\n        }else if(type==1){\n            int p;ll\
    \ x;cin>>p>>x;\n            lct.update(p,lct.get(p)+x);\n        }else{\n    \
    \        int u,v;cin>>u>>v;\n            cout<<lct.query(u,v)<<endl;\n       \
    \ }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#include \"../template.hpp\"\n\n#include \"../Tree/LinkCutTree.hpp\"\n\nsigned\
    \ main(){\n    int n,q;cin>>n>>q;\n    vector<ll> v(n);\n    cin>>v;\n\n    LinkCutTree<ll>\
    \ lct(v,[](ll a,ll b){return a+b;},0);\n\n    rep(i,n-1){\n        int u,v;cin>>u>>v;\n\
    \        lct.link(u,v);\n    }\n\n    while(q--){\n        int type;cin>>type;\n\
    \        if(type==0){\n            int a,b,c,d;cin>>a>>b>>c>>d;\n            lct.cut(a,b);\n\
    \            lct.link(c,d);\n        }else if(type==1){\n            int p;ll\
    \ x;cin>>p>>x;\n            lct.update(p,lct.get(p)+x);\n        }else{\n    \
    \        int u,v;cin>>u>>v;\n            cout<<lct.query(u,v)<<endl;\n       \
    \ }\n    }\n    return 0;\n}\n"
  dependsOn:
  - template.hpp
  - Tree/LinkCutTree.hpp
  isVerificationFile: true
  path: test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
  requiredBy: []
  timestamp: '2024-05-17 14:55:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
- /verify/test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp.html
title: test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
---

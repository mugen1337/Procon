---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Tree/LazyLinkCutTree.hpp
    title: Tree/LazyLinkCutTree.hpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/1249
    links:
    - https://yukicoder.me/problems/1249
  bundledCode: "#line 1 \"test/yuki1249_lct.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/1249\"\
    \n\n#line 1 \"bits/stdc++.h\"\n// C\n#ifndef _GLIBCXX_NO_ASSERT\n#include <cassert>\n\
    #endif\n#include <cctype>\n#include <cerrno>\n#include <cfloat>\n#include <ciso646>\n\
    #include <climits>\n#include <clocale>\n#include <cmath>\n#include <csetjmp>\n\
    #include <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <ctime>\n\n#if __cplusplus >=\
    \ 201103L\n#include <ccomplex>\n#include <cfenv>\n#include <cinttypes>\n#include\
    \ <cstdalign>\n#include <cstdbool>\n#include <cstdint>\n#include <ctgmath>\n#include\
    \ <cwchar>\n#include <cwctype>\n#endif\n\n// C++\n#include <algorithm>\n#include\
    \ <bitset>\n#include <complex>\n#include <deque>\n#include <exception>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <ios>\n#include\
    \ <iosfwd>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <locale>\n#include <map>\n#include <memory>\n\
    #include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <typeinfo>\n#include <utility>\n#include\
    \ <valarray>\n#include <vector>\n\n#if __cplusplus >= 201103L\n#include <array>\n\
    #include <atomic>\n#include <chrono>\n#include <condition_variable>\n#include\
    \ <forward_list>\n#include <future>\n#include <initializer_list>\n#include <mutex>\n\
    #include <random>\n#include <ratio>\n#include <regex>\n#include <scoped_allocator>\n\
    #include <system_error>\n#include <thread>\n#include <tuple>\n#include <typeindex>\n\
    #include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n#endif\n\
    #line 2 \"template.hpp\"\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto\
    \ x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\nusing ll=long long;\n\
    const int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n\
    // ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\ntemplate<class T>bool chmax(T &a,const\
    \ T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool chmin(T\
    \ &a,const T &b){if(b<a){a=b;return true;}return false;}\n\nstruct IOSetup{\n\
    \    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n     \
    \   cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename T>\n\
    ostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/yuki1249_lct.test.cpp\"\n\n#line 1 \"Tree/LazyLinkCutTree.hpp\"\
    \ntemplate<typename Monoid,typename OperatorMonoid=Monoid>\nstruct LazyLinkCutTree{\n\
    \n    using F=function<Monoid(Monoid,Monoid)>;\n    using G=function<Monoid(Monoid,OperatorMonoid)>;\n\
    \    using H=function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;\n    using\
    \ Flip=function<Monoid(Monoid)>;\n\n    LazyLinkCutTree(int n,F f,G g,H h,Monoid\
    \ e,OperatorMonoid oe,Flip flip=nullptr)\n    :f(f),g(g),h(h),e(e),oe(oe),flip(flip){\n\
    \        for(int i=0;i<n;i++) nodes.push_back(new Node(e,oe,i));\n    }\n\n  \
    \  LazyLinkCutTree(const vector<Monoid> &v,F f,G g,H h,Monoid e,OperatorMonoid\
    \ oe,Flip flip=nullptr)\n    :f(f),g(g),h(h),e(e),oe(oe),flip(flip){\n       \
    \ for(int i=0;i<(int)v.size();i++) nodes.push_back(new Node(v[i],oe,i));\n   \
    \ }\n\n    // v \u3092 root \u306B\n    void evert(int v){\n        expose(nodes[v]);\n\
    \        reverse(nodes[v]);\n    }\n\n    // link\n    void link(int ch,int par){\n\
    \        evert(ch);\n        expose(nodes[par]);\n        nodes[ch]->p=nodes[par];\n\
    \        nodes[par]->r=nodes[ch];\n        recalc(nodes[par]);\n    }\n\n    //\
    \ cut v-(v->p)\n    void cut(int v){\n        expose(nodes[v]);\n        nodes[v]->l->p=nullptr;\n\
    \        nodes[v]->l=nullptr;\n        recalc(nodes[v]);\n    }\n    // check\
    \ u-v in E, cut u-v\n    void cut(int u,int v){\n        evert(u);\n        expose(nodes[v]);\n\
    \        assert(nodes[u]==nodes[v]->l);\n        nodes[v]->l->p=nullptr;\n   \
    \     nodes[v]->l=nullptr;\n        recalc(nodes[v]);\n    }\n\n\n    Monoid query(int\
    \ u,int v){\n        evert(u);\n        expose(nodes[v]);\n\n        return nodes[v]->sum;\n\
    \    }\n\n    void update(int u,int v,OperatorMonoid x){\n        evert(u);\n\
    \        expose(nodes[v]);\n        propagate(nodes[v],x);\n        push(nodes[v]);\n\
    \    }\n    \n    int get_root(int v){\n        Node *cur=nodes[v];\n        expose(cur);\n\
    \        while(cur->l){\n            push(cur);\n            cur=cur->l;\n   \
    \     }\n        splay(cur);\n        return cur->idx;\n    }\n    \n    // not\
    \ connected -> return -1\n    int lca(int u,int v){\n        if(!is_connected(u,v))\
    \ return -1;\n        expose(nodes[u]);\n        return expose(nodes[v]);\n  \
    \  }\n\n    // faster than get_root(u)==get_root(v)\n    bool is_connected(int\
    \ u,int v){\n        if(u==v) return true;\n        expose(nodes[u]);\n      \
    \  expose(nodes[v]);\n        return bool(nodes[u]->p);\n    }\n\n    // \u672A\
    verify\n    int depth(int v){\n        expose(nodes[v]);\n        return size(nodes[v])-1;\n\
    \    }\n    // \u672Averify\n    // \u30E4\u30D0\u304B\u3063\u305F\u3089path query\u3067\
    \u5404\u9802\u70B91\u3092\u306E\u305B\u308D\n    int distance(int u,int v){\n\
    \        int p=lca(u,v);\n        if(p<0) return -1;\n        return depth(u)+depth(v)-depth(p)*2;\n\
    \    }\n    \nprivate:\n    struct Node{\n        Node *l,*r,*p;\n        Monoid\
    \ val,sum;\n        OperatorMonoid lazy;\n        int sz,idx;\n        bool rev;\n\
    \        bool is_root()const{\n            return (!p or (p->l!=(this) and p->r!=(this)));\n\
    \        }\n        Node(const Monoid &x,const OperatorMonoid &y,int idx)\n  \
    \          :l(nullptr),r(nullptr),p(nullptr),\n            val(x),sum(x),lazy(y),sz(1),idx(idx),rev(false){}\n\
    \    };\n\n    const F f;\n    const G g;\n    const H h;\n    const Monoid e;\n\
    \    const OperatorMonoid oe;\n    const Flip flip;\n    vector<Node *> nodes;\n\
    \n    int expose(Node *t){\n        Node *pre=nullptr;\n        for(Node *cur=t;cur;cur=cur->p){\n\
    \            splay(cur);\n            cur->r=pre;\n            recalc(cur);\n\
    \            pre=cur;\n        }\n        splay(t);\n        return pre->idx;\n\
    \    }\n    void rotr(Node *t){\n        auto *x=t->p,*y=x->p;\n        if((x->l=t->r))\
    \ t->r->p=x;\n        t->r=x,x->p=t;\n        recalc(x);\n        recalc(t);\n\
    \        if((t->p=y)){\n            if(y->l==x) y->l=t;\n            if(y->r==x)\
    \ y->r=t;\n            recalc(y);\n        }\n    }\n    void rotl(Node *t){\n\
    \        auto *x=t->p,*y=x->p;\n        if((x->r=t->l))t->l->p=x;\n        t->l=x,x->p=t;\n\
    \        recalc(x);\n        recalc(t);\n        if((t->p=y)){\n            if(y->l==x)\
    \ y->l=t;\n            if(y->r==x) y->r=t;\n            recalc(y);\n        }\n\
    \    }\n\n    int size(Node *t) const { return (t?t->sz:0); }\n\n    void recalc(Node\
    \ *t){\n        t->sum=t->val;\n        if(t->l) t->sum=f(t->l->sum,t->sum);\n\
    \        if(t->r) t->sum=f(t->sum,t->r->sum);\n    }\n\n    void propagate(Node\
    \ *t,OperatorMonoid x){\n        t->lazy=h(t->lazy,x);\n        t->val=g(t->val,x);\n\
    \        t->sum=g(t->sum,x);\n    }\n\n    void push(Node *t){\n        if(t->lazy!=oe){\n\
    \            if(t->l) propagate(t->l,t->lazy);\n            if(t->r) propagate(t->r,t->lazy);\n\
    \            t->lazy=oe;\n        }\n\n        if(t->rev){\n            if(t->l)\
    \ reverse(t->l);\n            if(t->r) reverse(t->r);\n            t->rev=false;\n\
    \        }\n    }\n\n    void reverse(Node *t){\n        swap(t->l,t->r);\n  \
    \      if(flip) t->sum=flip(t->sum);\n        t->rev^=true;\n    }\n    \n   \
    \ void splay(Node *cur){\n        push(cur);\n        while(!cur->is_root()){\n\
    \            Node *par=cur->p;\n            if(par->is_root()){// zig\n      \
    \          push(par);\n                push(cur);\n                if(par->l==cur)\
    \ rotr(cur);\n                else            rotl(cur);\n            }else{//\
    \ zig-zig, zig-zag\n                Node *parpar=par->p;\n                push(parpar);\n\
    \                push(par);\n                push(cur);\n                if(parpar->l==par){\n\
    \                    if(par->l==cur){rotr(par);rotr(cur);}\n                 \
    \   else           {rotl(cur);rotr(cur);}\n                }else{\n          \
    \          if(par->r==cur){rotl(par);rotl(cur);}\n                    else   \
    \        {rotr(cur);rotl(cur);}\n                }\n            }\n        }\n\
    \    }\n};\n#line 6 \"test/yuki1249_lct.test.cpp\"\n\nsigned main(){\n    int\
    \ n;cin>>n;\n\n    auto f=[&](pair<ll,ll> a,pair<ll,ll> b){\n        return make_pair(a.first+b.first,a.second+b.second);\n\
    \    };\n    auto g=[&](pair<ll,ll> a,ll b){\n        return make_pair(a.first+a.second*b,a.second);\n\
    \    };\n    auto h=[&](ll a,ll b){\n        return a+b;\n    };\n\n    vector<pair<ll,ll>>\
    \ ones(n,{1,1});\n    LazyLinkCutTree<pair<ll,ll>,ll> lct(ones,f,g,h,{0,0},0);\n\
    \n    rep(i,n-1){\n        int u,v;cin>>u>>v;u--,v--;\n        lct.link(u,v);\n\
    \    }\n\n    int q;cin>>q;\n    ll ans=0;\n    while(q--){\n        int a,b;cin>>a>>b;a--,b--;\n\
    \        ans+=lct.query(a,b).first;\n        lct.update(a,b,1);\n    }\n    cout<<ans<<endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/1249\"\n\n#include \"../template.hpp\"\
    \n\n#include \"../Tree/LazyLinkCutTree.hpp\"\n\nsigned main(){\n    int n;cin>>n;\n\
    \n    auto f=[&](pair<ll,ll> a,pair<ll,ll> b){\n        return make_pair(a.first+b.first,a.second+b.second);\n\
    \    };\n    auto g=[&](pair<ll,ll> a,ll b){\n        return make_pair(a.first+a.second*b,a.second);\n\
    \    };\n    auto h=[&](ll a,ll b){\n        return a+b;\n    };\n\n    vector<pair<ll,ll>>\
    \ ones(n,{1,1});\n    LazyLinkCutTree<pair<ll,ll>,ll> lct(ones,f,g,h,{0,0},0);\n\
    \n    rep(i,n-1){\n        int u,v;cin>>u>>v;u--,v--;\n        lct.link(u,v);\n\
    \    }\n\n    int q;cin>>q;\n    ll ans=0;\n    while(q--){\n        int a,b;cin>>a>>b;a--,b--;\n\
    \        ans+=lct.query(a,b).first;\n        lct.update(a,b,1);\n    }\n    cout<<ans<<endl;\n\
    \    return 0;\n}"
  dependsOn:
  - template.hpp
  - bits/stdc++.h
  - Tree/LazyLinkCutTree.hpp
  isVerificationFile: true
  path: test/yuki1249_lct.test.cpp
  requiredBy: []
  timestamp: '2024-05-15 18:03:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yuki1249_lct.test.cpp
layout: document
redirect_from:
- /verify/test/yuki1249_lct.test.cpp
- /verify/test/yuki1249_lct.test.cpp.html
title: test/yuki1249_lct.test.cpp
---

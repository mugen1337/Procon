---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: BinarySearchTree/ImplicitTreap.cpp
    title: Implicit Treap
  - icon: ':question:'
    path: template.cpp
    title: template.cpp
  - icon: ':heavy_check_mark:'
    path: type/modint.cpp
    title: type/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#line 1 \"template.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
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
    \   return is;\n}\n\n#line 4 \"test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp\"\
    \n\n#line 1 \"BinarySearchTree/ImplicitTreap.cpp\"\ntemplate<typename Monoid,typename\
    \ OperatorMonoid>\nstruct ImplicitTreap{\n\n    private:\n\n    inline int xorshift(){\n\
    \        static int x=122312555;\n        static int y=336261662;\n        static\
    \ int z=558127122;\n        static int w=917277772;\n        int t;\n        t=x^(x<<11);\n\
    \        x=y;y=z;z=w;\n        return w=(w^(w>>19))^(t^(t>>8));\n    }\n\n   \
    \ using F=function<Monoid(Monoid,Monoid)>;\n    using G=function<Monoid(Monoid,OperatorMonoid)>;\n\
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
    };\n#line 6 \"test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp\"\n\
    \n#line 1 \"type/modint.cpp\"\ntemplate<ll Mod>\nstruct ModInt{\n    long long\
    \ x;\n    ModInt():x(0){}\n    ModInt(long long y):x(y>=0?y%Mod:(Mod-(-y)%Mod)%Mod){}\n\
    \    ModInt &operator+=(const ModInt &p){\n        if((x+=p.x)>=Mod) x-=Mod;\n\
    \        return *this;\n    }\n    ModInt &operator-=(const ModInt &p){\n    \
    \    if((x+=Mod-p.x)>=Mod)x-=Mod;\n        return *this;\n    }\n    ModInt &operator*=(const\
    \ ModInt &p){\n        x=(int)(1ll*x*p.x%Mod);\n        return *this;\n    }\n\
    \    ModInt &operator/=(const ModInt &p){\n        (*this)*=p.inverse();\n   \
    \     return *this;\n    }\n    ModInt operator-()const{return ModInt(-x);}\n\
    \    ModInt operator+(const ModInt &p)const{return ModInt(*this)+=p;}\n    ModInt\
    \ operator-(const ModInt &p)const{return ModInt(*this)-=p;}\n    ModInt operator*(const\
    \ ModInt &p)const{return ModInt(*this)*=p;}\n    ModInt operator/(const ModInt\
    \ &p)const{return ModInt(*this)/=p;}\n    bool operator==(const ModInt &p)const{return\
    \ x==p.x;}\n    bool operator!=(const ModInt &p)const{return x!=p.x;}\n    ModInt\
    \ inverse()const{\n        int a=x,b=Mod,u=1,v=0,t;\n        while(b>0){\n   \
    \         t=a/b;\n            swap(a-=t*b,b);swap(u-=t*v,v);\n        }\n    \
    \    return ModInt(u);\n    }\n    ModInt pow(long long n)const{\n        ModInt\
    \ ret(1),mul(x);\n        while(n>0){\n            if(n&1) ret*=mul;\n       \
    \     mul*=mul;n>>=1;\n        }\n        return ret;\n    }\n    friend ostream\
    \ &operator<<(ostream &os,const ModInt &p){return os<<p.x;}\n    friend istream\
    \ &operator>>(istream &is,ModInt &a){long long t;is>>t;a=ModInt<Mod>(t);return\
    \ (is);}\n    static int get_mod(){return Mod;}\n};\n#line 8 \"test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp\"\
    \nusing mint=ModInt<998244353>;\n\nusing M=pair<mint,mint>;\nusing OM=pair<mint,mint>;\n\
    const M M1=M(0,0);\nconst OM OM0=OM(1,0);\nM segf(M a,M b){\n    return M(a.first+b.first,a.second+b.second);\n\
    }\nM segg(M a,OM b){\n    return M(a.first*b.first+a.second*b.second,a.second);\n\
    }\nOM segh(OM a,OM b){\n    return OM(a.first*b.first,a.second*b.first+b.second);\n\
    }\n\nsigned main(){\n    int n,q;cin>>n>>q;\n    vector<mint> a(n);\n    cin>>a;\n\
    \    ImplicitTreap<M,OM> seg(segf,segg,segh,M1,OM0);\n    reverse(ALL(a));\n \
    \   for(auto x:a) seg.insert(0,{x,1});\n\n    while(q--){\n        int t;cin>>t;\n\
    \        if(t==0){\n            int i;mint x;cin>>i>>x;\n            seg.insert(i,{x,1});\n\
    \        }else if(t==1){\n            int i;cin>>i;\n            seg.erase(i);\n\
    \        }else if(t==2){\n            int l,r;cin>>l>>r;\n            seg.reverse(l,r);\n\
    \        }else if(t==3){\n            int l,r;mint b,c;cin>>l>>r>>b>>c;\n    \
    \        seg.update(l,r,{b,c});\n        }else{\n            int l,r;cin>>l>>r;\n\
    \            cout<<seg.query(l,r).first<<endl;\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include \"../template.cpp\"\n\n#include \"../BinarySearchTree/ImplicitTreap.cpp\"\
    \n\n#include \"../type/modint.cpp\"\nusing mint=ModInt<998244353>;\n\nusing M=pair<mint,mint>;\n\
    using OM=pair<mint,mint>;\nconst M M1=M(0,0);\nconst OM OM0=OM(1,0);\nM segf(M\
    \ a,M b){\n    return M(a.first+b.first,a.second+b.second);\n}\nM segg(M a,OM\
    \ b){\n    return M(a.first*b.first+a.second*b.second,a.second);\n}\nOM segh(OM\
    \ a,OM b){\n    return OM(a.first*b.first,a.second*b.first+b.second);\n}\n\nsigned\
    \ main(){\n    int n,q;cin>>n>>q;\n    vector<mint> a(n);\n    cin>>a;\n    ImplicitTreap<M,OM>\
    \ seg(segf,segg,segh,M1,OM0);\n    reverse(ALL(a));\n    for(auto x:a) seg.insert(0,{x,1});\n\
    \n    while(q--){\n        int t;cin>>t;\n        if(t==0){\n            int i;mint\
    \ x;cin>>i>>x;\n            seg.insert(i,{x,1});\n        }else if(t==1){\n  \
    \          int i;cin>>i;\n            seg.erase(i);\n        }else if(t==2){\n\
    \            int l,r;cin>>l>>r;\n            seg.reverse(l,r);\n        }else\
    \ if(t==3){\n            int l,r;mint b,c;cin>>l>>r>>b>>c;\n            seg.update(l,r,{b,c});\n\
    \        }else{\n            int l,r;cin>>l>>r;\n            cout<<seg.query(l,r).first<<endl;\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - template.cpp
  - BinarySearchTree/ImplicitTreap.cpp
  - type/modint.cpp
  isVerificationFile: true
  path: test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '2021-03-27 01:28:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
- /verify/test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp.html
title: test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
---

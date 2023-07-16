---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/LazySegmentTree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/899
    links:
    - https://yukicoder.me/problems/899
  bundledCode: "#line 1 \"test/yuki899.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/899\"\
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
    \   return is;\n}\n\n#line 4 \"test/yuki899.test.cpp\"\n\n#line 1 \"SegmentTree/LazySegmentTree.hpp\"\
    \ntemplate<typename Monoid, typename OperatorMonoid=Monoid>\nstruct LazySegmentTree{\n\
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
    // }\n// M segg(M a,OM b){\n//     return M(a.second*b,a.second);\n// }\n// OM\
    \ segh(OM a,OM b){\n//     return (b==OM0?a:b);\n// }\n\n// // range add range\
    \ sum (sum, count)\n// using M=pair<ll,ll>;\n// using OM=ll;\n// const M M1=M(0,0);\n\
    // const OM OM0=0;\n// M segf(M a,M b){\n//     return M(a.first+b.first,a.second+b.second);\n\
    // }\n// M segg(M a,OM b){\n//     return M(a.first+a.second*b,a.second);\n//\
    \ }\n// OM segh(OM a,OM b){\n//     return a+b;\n// }\n#line 6 \"test/yuki899.test.cpp\"\
    \n\n// range set range min\nusing M=ll;\nusing OM=ll;\nconst M M1=LINF;\nconst\
    \ OM OM0=-LINF;\nM segf(M a,M b){\n    return (a<b?a:b);\n}\nM segg(M a,OM b){\n\
    \    return (b==OM0?a:b);\n}\nOM segh(OM a,OM b){\n    return (b==OM0?a:b);\n\
    }\n\nsigned main(){\n    int n;cin>>n;\n    map<int,int> l,r;\n    set<int> st;\n\
    \    \n    rep(i,n){\n        int x;cin>>x;\n        st.insert(x);\n        if(!l.count(x))\
    \ l[x]=i;\n        else l[x]=min(l[x],i);\n        if(!r.count(x)) r[x]=i;\n \
    \       else r[x]=max(r[x],i);\n    }\n\n    LazySegmentTree<M,OM> seg(n,segf,segg,segh,M1,OM0);\n\
    \    seg.build();\n    for(auto x:st) seg.update(l[x],r[x]+1,x);\n    rep(i,n)cout<<seg[i]<<(i+1==n?\"\
    \\n\":\" \");\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/899\"\n\n#include \"../template.hpp\"\
    \n\n#include \"../SegmentTree/LazySegmentTree.hpp\"\n\n// range set range min\n\
    using M=ll;\nusing OM=ll;\nconst M M1=LINF;\nconst OM OM0=-LINF;\nM segf(M a,M\
    \ b){\n    return (a<b?a:b);\n}\nM segg(M a,OM b){\n    return (b==OM0?a:b);\n\
    }\nOM segh(OM a,OM b){\n    return (b==OM0?a:b);\n}\n\nsigned main(){\n    int\
    \ n;cin>>n;\n    map<int,int> l,r;\n    set<int> st;\n    \n    rep(i,n){\n  \
    \      int x;cin>>x;\n        st.insert(x);\n        if(!l.count(x)) l[x]=i;\n\
    \        else l[x]=min(l[x],i);\n        if(!r.count(x)) r[x]=i;\n        else\
    \ r[x]=max(r[x],i);\n    }\n\n    LazySegmentTree<M,OM> seg(n,segf,segg,segh,M1,OM0);\n\
    \    seg.build();\n    for(auto x:st) seg.update(l[x],r[x]+1,x);\n    rep(i,n)cout<<seg[i]<<(i+1==n?\"\
    \\n\":\" \");\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - SegmentTree/LazySegmentTree.hpp
  isVerificationFile: true
  path: test/yuki899.test.cpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yuki899.test.cpp
layout: document
redirect_from:
- /verify/test/yuki899.test.cpp
- /verify/test/yuki899.test.cpp.html
title: test/yuki899.test.cpp
---

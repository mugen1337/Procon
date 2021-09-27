---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/SegmentTree.cpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo_Point-Add-Range-Sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 1 \"template.cpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
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
    \   return is;\n}\n\n#line 4 \"test/yosupo_Point-Add-Range-Sum.test.cpp\"\n\n\
    #line 1 \"SegmentTree/SegmentTree.cpp\"\ntemplate<typename Monoid>\nstruct SegmentTree{\n\
    \    using F=function<Monoid(Monoid,Monoid)>;\n\n    private:\n    int sz;\n \
    \   vector<Monoid> seg;\n\n    Monoid query(int a,int b,int k,int l,int r){\n\
    \        if(a<=l and r<=b)   return seg[k];\n        if(b<=l or r<=a)    return\
    \ M0;\n        Monoid L=query(a,b,2*k,l,(l+r)/2);\n        Monoid R=query(a,b,2*k+1,(l+r)/2,r);\n\
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
    \ M0;// \u30E2\u30CE\u30A4\u30C9\u306E\u5143\n    SegmentTree(int n,F f,Monoid\
    \ M0):f(f),M0(M0){\n        sz=1;\n        while(sz<n)sz<<=1;\n        seg.assign(2*sz,M0);\n\
    \    }\n    void set(int k,Monoid x){\n        seg[k+sz]=x;\n    }\n    void build(){\n\
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
    \    }\n};\n#line 6 \"test/yosupo_Point-Add-Range-Sum.test.cpp\"\n\nsigned main(){\n\
    \    int n,q;cin>>n>>q;\n\n    auto segfunc=[](ll a,ll b){\n        return a+b;\n\
    \    };\n    \n    SegmentTree<ll> seg(n,segfunc,0);\n    rep(i,n){\n        ll\
    \ a;cin>>a;\n        seg.set(i,a);\n    }\n    seg.build();\n\n    for(;q--;){\n\
    \        int type;cin>>type;\n        if(type==0){\n            int p;ll x;cin>>p>>x;\n\
    \            seg.update(p,seg.query(p,p+1)+x);\n        }\n        else{\n   \
    \         int l,r;cin>>l>>r;\n            cout<<seg.query(l,r)<<endl;\n      \
    \  }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../template.cpp\"\n\n#include \"../SegmentTree/SegmentTree.cpp\"\n\
    \nsigned main(){\n    int n,q;cin>>n>>q;\n\n    auto segfunc=[](ll a,ll b){\n\
    \        return a+b;\n    };\n    \n    SegmentTree<ll> seg(n,segfunc,0);\n  \
    \  rep(i,n){\n        ll a;cin>>a;\n        seg.set(i,a);\n    }\n    seg.build();\n\
    \n    for(;q--;){\n        int type;cin>>type;\n        if(type==0){\n       \
    \     int p;ll x;cin>>p>>x;\n            seg.update(p,seg.query(p,p+1)+x);\n \
    \       }\n        else{\n            int l,r;cin>>l>>r;\n            cout<<seg.query(l,r)<<endl;\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - template.cpp
  - SegmentTree/SegmentTree.cpp
  isVerificationFile: true
  path: test/yosupo_Point-Add-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '2021-04-19 13:27:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_Point-Add-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Point-Add-Range-Sum.test.cpp
- /verify/test/yosupo_Point-Add-Range-Sum.test.cpp.html
title: test/yosupo_Point-Add-Range-Sum.test.cpp
---

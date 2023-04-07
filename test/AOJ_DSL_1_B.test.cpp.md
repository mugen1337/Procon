---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: UnionFind/WeightedUnionFind.hpp
    title: UnionFind/WeightedUnionFind.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
  bundledCode: "#line 1 \"test/AOJ_DSL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\"\
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
    \   return is;\n}\n\n#line 4 \"test/AOJ_DSL_1_B.test.cpp\"\n\n#line 1 \"UnionFind/WeightedUnionFind.hpp\"\
    \ntemplate<typename T>\nstruct WeightedUnionFind{\n    int con;\n    vector<int>\
    \ par,siz;\n    vector<T> h;// height, h[root]=0\n    WeightedUnionFind(int n):con(n),par(n),siz(n,1),h(n,T(0)){\n\
    \        iota(begin(par),end(par),0);\n    }\n    int root(int x){\n        if(x==par[x])\
    \ return x;\n        int r=root(par[x]);\n        h[x]+=h[par[x]];\n        return\
    \ par[x]=r;\n    }\n    bool sameroot(int x,int y){\n        return root(x)==root(y);\n\
    \    }\n    // y\u306Fx\u3088\u308Adiff_h\u9AD8\u3044, h[y]=h[x]+diff_h, x->y\
    \ (diff_h)\n    bool unite(int x,int y,T diff_h){\n        int root_x=root(x),root_y=root(y);\n\
    \        if(root_x==root_y){\n            // // x and y are already in same group\n\
    \            // assert(false);\n            return false;\n        }\n       \
    \ diff_h=-h[x]+diff_h+h[y];\n        if(siz[root_x]>siz[root_y]) swap(root_x,root_y),diff_h=-diff_h;\
    \ \n        siz[root_y]+=siz[root_x];\n        par[root_x]=root_y;\n        h[root_x]=diff_h;\n\
    \        con--;\n        return true;\n    }\n    // h[y]-h[x]\n    T diff(int\
    \ x,int y){\n        assert(sameroot(x,y));\n        return h[y]-h[x];\n    }\n\
    \    int size(int x){\n        return siz[root(x)];\n    }\n};\n#line 6 \"test/AOJ_DSL_1_B.test.cpp\"\
    \n\nsigned main(){\n    int n,q;cin>>n>>q;\n    WeightedUnionFind<int> uf(n);\n\
    \    while(q--){\n        int t;cin>>t;\n        if(t){\n            int x,y;cin>>x>>y;\n\
    \            if(!uf.sameroot(x,y)) cout<<\"?\"<<endl;\n            else cout<<-uf.diff(x,y)<<endl;\n\
    \        }else{\n            int u,v,w;cin>>u>>v>>w;\n            uf.unite(u,v,w);\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\"\n\n\
    #include \"../template.hpp\"\n\n#include \"../UnionFind/WeightedUnionFind.hpp\"\
    \n\nsigned main(){\n    int n,q;cin>>n>>q;\n    WeightedUnionFind<int> uf(n);\n\
    \    while(q--){\n        int t;cin>>t;\n        if(t){\n            int x,y;cin>>x>>y;\n\
    \            if(!uf.sameroot(x,y)) cout<<\"?\"<<endl;\n            else cout<<-uf.diff(x,y)<<endl;\n\
    \        }else{\n            int u,v,w;cin>>u>>v>>w;\n            uf.unite(u,v,w);\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - UnionFind/WeightedUnionFind.hpp
  isVerificationFile: true
  path: test/AOJ_DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ_DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_DSL_1_B.test.cpp
- /verify/test/AOJ_DSL_1_B.test.cpp.html
title: test/AOJ_DSL_1_B.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph2/GraphTemplate.cpp
    title: Graph2/GraphTemplate.cpp
  - icon: ':x:'
    path: Graph2/WeightedMaximumIndependentSet.cpp
    title: Graph2/WeightedMaximumIndependentSet.cpp
  - icon: ':question:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/beta/room.html#ACPC2021Day2/problems/I
    links:
    - https://onlinejudge.u-aizu.ac.jp/beta/room.html#ACPC2021Day2/problems/I
  bundledCode: "#line 1 \"test/AOJ_ACPC_day2_I.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/beta/room.html#ACPC2021Day2/problems/I\"\
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
    \   return is;\n}\n\n#line 4 \"test/AOJ_ACPC_day2_I.test.cpp\"\n\n#line 1 \"Graph2/GraphTemplate.cpp\"\
    \n// graph template\n// ref : https://ei1333.github.io/library/graph/graph-template.cpp\n\
    template<typename T=int>\nstruct Edge{\n    int from,to;\n    T w;\n    int idx;\n\
    \    Edge()=default;\n    Edge(int from,int to,T w=1,int idx=-1):from(from),to(to),w(w),idx(idx){}\n\
    \    operator int() const{return to;}\n};\n\ntemplate<typename T=int>\nstruct\
    \ Graph{\n    vector<vector<Edge<T>>> g;\n    int V,E;\n    Graph()=default;\n\
    \    Graph(int n):g(n),V(n),E(0){}\n\n    int size(){\n        return (int)g.size();\n\
    \    }\n    void resize(int k){\n        g.resize(k);\n        V=k;\n    }\n \
    \   inline const vector<Edge<T>> &operator[](int k)const{\n        return (g.at(k));\n\
    \    }\n    inline vector<Edge<T>> &operator[](int k){\n        return (g.at(k));\n\
    \    }\n    void add_directed_edge(int from,int to,T cost=1){\n        g[from].emplace_back(from,to,cost,E++);\n\
    \    }\n    void add_edge(int from,int to,T cost=1){\n        g[from].emplace_back(from,to,cost,E);\n\
    \        g[to].emplace_back(to,from,cost,E++);\n    }\n    void read(int m,int\
    \ pad=-1,bool weighted=false,bool directed=false){\n        for(int i=0;i<m;i++){\n\
    \            int u,v;cin>>u>>v;\n            u+=pad,v+=pad;\n            T w=T(1);\n\
    \            if(weighted) cin>>w;\n            if(directed) add_directed_edge(u,v,w);\n\
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n#line 2 \"Graph2/WeightedMaximumIndependentSet.cpp\"\
    \n\n/*\n\u9802\u70B9\u3092\u30B0\u30EB\u30FC\u30D7A, B\u306B\u5206\u3051\u308B\
    \uFF0E\nB\u3067\u306F\ndp_B[S]:= (S\u306E\u90E8\u5206\u96C6\u5408\u306E\u3046\u3061\
    \uFF0C\u91CD\u307F\u306E\u548C\u304C\u6700\u5927\u306B\u306A\u308B\u72EC\u7ACB\
    \u96C6\u5408)\n\u3092\u6C42\u3081\u3066\u304A\u304F\uFF0E\nA\u5074\u3067\u5168\
    \u63A2\u7D22\u3057\uFF0C\u3068\u308C\u308B\u96C6\u5408\u3092\u6C42\u3081\uFF0C\
    \u6700\u5927\u5024\u3092\u6C42\u3081\u308B\uFF0E\n*/\ntemplate<typename T,typename\
    \ GT=int>\nT WeightedMaximumIndependentSet(Graph<GT> G,vector<T> W){\n    assert(G.size()==(int)W.size());\n\
    \    assert(W.size()<=50);\n\n    int N=(int)W.size();\n    int M=N/2;\n    int\
    \ K=N-M;\n    vector<int> E_AtoB(M,0),E_AtoA(M,0),E_BtoB(K,0);\n    for(int i=0;i<N;i++){\n\
    \        for(auto &e:G[i]){\n            if(e==i) continue;\n            if(i<M\
    \ and e<M)   E_AtoA[i]|=(1<<e);\n            if(i<M and e>=M)  E_AtoB[i]|=(1<<(e-M));\n\
    \            if(i>=M and e>=M) E_BtoB[i-M]|=(1<<(e-M));\n        }\n    }\n\n\
    \    vector<T> dp_B(1<<K,0);\n    for(int bit=0;bit<(1<<K);bit++){\n        T\
    \ S=0;\n        int to=0;\n        for(int i=0;i<K;i++)if((bit>>i)&1){\n     \
    \       to|=E_BtoB[i];\n            S+=W[M+i];\n        }\n\n        if((to&bit)==0)\
    \ dp_B[bit]=max(dp_B[bit],S);\n\n        for(int i=0;i<K;i++)if(!((bit>>i)&1))\
    \ dp_B[bit|(1<<i)]=max(dp_B[bit|(1<<i)],dp_B[bit]);\n    }\n\n    T ret=0;\n \
    \   int mask=(1<<K)-1;\n    for(int bit=0;bit<(1<<M);bit++){\n        T S=0;\n\
    \        int to=0,toB=0;\n        for(int i=0;i<M;i++)if((bit>>i)&1){\n      \
    \      to|=E_AtoA[i];\n            toB|=E_AtoB[i];\n            S+=W[i];\n   \
    \     }\n        if((to&bit)==0) ret=max(ret,S+dp_B[mask^toB]);\n    }\n    return\
    \ ret;\n}\n#line 6 \"test/AOJ_ACPC_day2_I.test.cpp\"\n\nsigned main(){\n    int\
    \ M,N;cin>>M>>N;\n    vector<vector<int>> P(N);\n    vector<int> W(M);\n    rep(i,M){\n\
    \        cin>>W[i];\n        rep(j,W[i]){\n            int p;cin>>p;p--;\n   \
    \         P[p].push_back(i);\n        }\n    }\n\n    Graph<int> G(M);\n    for(auto\
    \ &v:P){\n        int n=(int)v.size();\n        rep(i,n)rep(j,i) G.add_edge(v[i],v[j]);\n\
    \    }\n\n    int S=0;\n    for(auto &w:W) S+=w;\n    cout<<S-WeightedMaximumIndependentSet(G,W)<<endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/beta/room.html#ACPC2021Day2/problems/I\"\
    \n\n#include \"../template.cpp\"\n\n#include \"../Graph2/WeightedMaximumIndependentSet.cpp\"\
    \n\nsigned main(){\n    int M,N;cin>>M>>N;\n    vector<vector<int>> P(N);\n  \
    \  vector<int> W(M);\n    rep(i,M){\n        cin>>W[i];\n        rep(j,W[i]){\n\
    \            int p;cin>>p;p--;\n            P[p].push_back(i);\n        }\n  \
    \  }\n\n    Graph<int> G(M);\n    for(auto &v:P){\n        int n=(int)v.size();\n\
    \        rep(i,n)rep(j,i) G.add_edge(v[i],v[j]);\n    }\n\n    int S=0;\n    for(auto\
    \ &w:W) S+=w;\n    cout<<S-WeightedMaximumIndependentSet(G,W)<<endl;\n    return\
    \ 0;\n}"
  dependsOn:
  - template.cpp
  - Graph2/WeightedMaximumIndependentSet.cpp
  - Graph2/GraphTemplate.cpp
  isVerificationFile: true
  path: test/AOJ_ACPC_day2_I.test.cpp
  requiredBy: []
  timestamp: '2021-09-28 00:16:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ_ACPC_day2_I.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_ACPC_day2_I.test.cpp
- /verify/test/AOJ_ACPC_day2_I.test.cpp.html
title: test/AOJ_ACPC_day2_I.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph2/GraphTemplate.cpp
    title: Graph2/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ_ACPC_day2_I.test.cpp
    title: test/AOJ_ACPC_day2_I.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph2/GraphTemplate.cpp\"\n// graph template\n// ref :\
    \ https://ei1333.github.io/library/graph/graph-template.cpp\ntemplate<typename\
    \ T=int>\nstruct Edge{\n    int from,to;\n    T w;\n    int idx;\n    Edge()=default;\n\
    \    Edge(int from,int to,T w=1,int idx=-1):from(from),to(to),w(w),idx(idx){}\n\
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
    \ ret;\n}\n"
  code: "#include \"./GraphTemplate.cpp\"\n\n/*\n\u9802\u70B9\u3092\u30B0\u30EB\u30FC\
    \u30D7A, B\u306B\u5206\u3051\u308B\uFF0E\nB\u3067\u306F\ndp_B[S]:= (S\u306E\u90E8\
    \u5206\u96C6\u5408\u306E\u3046\u3061\uFF0C\u91CD\u307F\u306E\u548C\u304C\u6700\
    \u5927\u306B\u306A\u308B\u72EC\u7ACB\u96C6\u5408)\n\u3092\u6C42\u3081\u3066\u304A\
    \u304F\uFF0E\nA\u5074\u3067\u5168\u63A2\u7D22\u3057\uFF0C\u3068\u308C\u308B\u96C6\
    \u5408\u3092\u6C42\u3081\uFF0C\u6700\u5927\u5024\u3092\u6C42\u3081\u308B\uFF0E\
    \n*/\ntemplate<typename T,typename GT=int>\nT WeightedMaximumIndependentSet(Graph<GT>\
    \ G,vector<T> W){\n    assert(G.size()==(int)W.size());\n    assert(W.size()<=50);\n\
    \n    int N=(int)W.size();\n    int M=N/2;\n    int K=N-M;\n    vector<int> E_AtoB(M,0),E_AtoA(M,0),E_BtoB(K,0);\n\
    \    for(int i=0;i<N;i++){\n        for(auto &e:G[i]){\n            if(e==i) continue;\n\
    \            if(i<M and e<M)   E_AtoA[i]|=(1<<e);\n            if(i<M and e>=M)\
    \  E_AtoB[i]|=(1<<(e-M));\n            if(i>=M and e>=M) E_BtoB[i-M]|=(1<<(e-M));\n\
    \        }\n    }\n\n    vector<T> dp_B(1<<K,0);\n    for(int bit=0;bit<(1<<K);bit++){\n\
    \        T S=0;\n        int to=0;\n        for(int i=0;i<K;i++)if((bit>>i)&1){\n\
    \            to|=E_BtoB[i];\n            S+=W[M+i];\n        }\n\n        if((to&bit)==0)\
    \ dp_B[bit]=max(dp_B[bit],S);\n\n        for(int i=0;i<K;i++)if(!((bit>>i)&1))\
    \ dp_B[bit|(1<<i)]=max(dp_B[bit|(1<<i)],dp_B[bit]);\n    }\n\n    T ret=0;\n \
    \   int mask=(1<<K)-1;\n    for(int bit=0;bit<(1<<M);bit++){\n        T S=0;\n\
    \        int to=0,toB=0;\n        for(int i=0;i<M;i++)if((bit>>i)&1){\n      \
    \      to|=E_AtoA[i];\n            toB|=E_AtoB[i];\n            S+=W[i];\n   \
    \     }\n        if((to&bit)==0) ret=max(ret,S+dp_B[mask^toB]);\n    }\n    return\
    \ ret;\n}"
  dependsOn:
  - Graph2/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph2/WeightedMaximumIndependentSet.cpp
  requiredBy: []
  timestamp: '2021-09-28 00:16:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ_ACPC_day2_I.test.cpp
documentation_of: Graph2/WeightedMaximumIndependentSet.cpp
layout: document
redirect_from:
- /library/Graph2/WeightedMaximumIndependentSet.cpp
- /library/Graph2/WeightedMaximumIndependentSet.cpp.html
title: Graph2/WeightedMaximumIndependentSet.cpp
---

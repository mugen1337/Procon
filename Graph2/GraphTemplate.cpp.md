---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph2/CycleDetection.cpp
    title: Graph2/CycleDetection.cpp
  - icon: ':heavy_check_mark:'
    path: Graph2/Dijkstra.cpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: Graph2/Eppstein.cpp
    title: Eppstein's Algorithm (K-Shortest-Walk)
  - icon: ':warning:'
    path: Graph2/GraphRelabel.cpp
    title: Graph2/GraphRelabel.cpp
  - icon: ':heavy_check_mark:'
    path: Graph2/HeavyLightDecomposition.cpp
    title: "Heavy Light Decomposition (HL\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: Graph2/LowLink.cpp
    title: Low Link
  - icon: ':warning:'
    path: Graph2/RangeEdgeGraph.cpp
    title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
  - icon: ':heavy_check_mark:'
    path: Graph2/Rerooting.cpp
    title: Graph2/Rerooting.cpp
  - icon: ':heavy_check_mark:'
    path: Graph2/StronglyConnectedComponents.cpp
    title: Strongly Connected Components
  - icon: ':heavy_check_mark:'
    path: Graph2/TreeDiameter.cpp
    title: Graph2/TreeDiameter.cpp
  - icon: ':heavy_check_mark:'
    path: Graph2/TwoEdgeConnectedComponents.cpp
    title: Graph2/TwoEdgeConnectedComponents.cpp
  - icon: ':warning:'
    path: Graph2/WeightedMaximumIndependentSet.cpp
    title: Graph2/WeightedMaximumIndependentSet.cpp
  - icon: ':heavy_check_mark:'
    path: Graph2/Yen.cpp
    title: Yen's Algorithm (K-Shortest-Path)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_GRL_1_A.test.cpp
    title: test/AOJ_GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_GRL_3_A.test.cpp
    title: test/AOJ_GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_CycleDetection2.test.cpp
    title: test/yosupo_CycleDetection2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_KSW.test.cpp
    title: test/yosupo_KSW.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_TECC.test.cpp
    title: test/yosupo_TECC.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_TreeDiameter.test.cpp
    title: test/yosupo_TreeDiameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_scc2.test.cpp
    title: test/yosupo_scc2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki1249.test.cpp
    title: test/yuki1249.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki4227.test.cpp
    title: test/yuki4227.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki5436.test.cpp
    title: test/yuki5436.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.github.io/library/graph/graph-template.cpp
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n"
  code: "// graph template\n// ref : https://ei1333.github.io/library/graph/graph-template.cpp\n\
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph2/GraphTemplate.cpp
  requiredBy:
  - Graph2/RangeEdgeGraph.cpp
  - Graph2/HeavyLightDecomposition.cpp
  - Graph2/Eppstein.cpp
  - Graph2/TreeDiameter.cpp
  - Graph2/Dijkstra.cpp
  - Graph2/Yen.cpp
  - Graph2/GraphRelabel.cpp
  - Graph2/CycleDetection.cpp
  - Graph2/TwoEdgeConnectedComponents.cpp
  - Graph2/WeightedMaximumIndependentSet.cpp
  - Graph2/StronglyConnectedComponents.cpp
  - Graph2/Rerooting.cpp
  - Graph2/LowLink.cpp
  timestamp: '2021-07-04 13:54:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_TreeDiameter.test.cpp
  - test/AOJ_GRL_3_A.test.cpp
  - test/yuki1249.test.cpp
  - test/yuki4227.test.cpp
  - test/yosupo_scc2.test.cpp
  - test/AOJ_GRL_1_A.test.cpp
  - test/yosupo_CycleDetection2.test.cpp
  - test/yosupo_TECC.test.cpp
  - test/yuki5436.test.cpp
  - test/yosupo_KSW.test.cpp
documentation_of: Graph2/GraphTemplate.cpp
layout: document
redirect_from:
- /library/Graph2/GraphTemplate.cpp
- /library/Graph2/GraphTemplate.cpp.html
title: Graph2/GraphTemplate.cpp
---

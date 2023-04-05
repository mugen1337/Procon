---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Graph2/CycleDetection.hpp
    title: Graph2/CycleDetection.hpp
  - icon: ':x:'
    path: Graph2/Dijkstra.hpp
    title: Dijkstra
  - icon: ':x:'
    path: Graph2/Eppstein.hpp
    title: Eppstein's Algorithm (K-Shortest-Walk)
  - icon: ':warning:'
    path: Graph2/GraphRelabel.hpp
    title: Graph2/GraphRelabel.hpp
  - icon: ':x:'
    path: Graph2/HeavyLightDecomposition.hpp
    title: "Heavy Light Decomposition (HL\u5206\u89E3)"
  - icon: ':x:'
    path: Graph2/LowLink.hpp
    title: Low Link
  - icon: ':warning:'
    path: Graph2/RangeEdgeGraph.hpp
    title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
  - icon: ':x:'
    path: Graph2/Rerooting.hpp
    title: Graph2/Rerooting.hpp
  - icon: ':x:'
    path: Graph2/StronglyConnectedComponents.hpp
    title: Strongly Connected Components
  - icon: ':x:'
    path: Graph2/TreeDiameter.hpp
    title: Graph2/TreeDiameter.hpp
  - icon: ':x:'
    path: Graph2/TwoEdgeConnectedComponents.hpp
    title: Graph2/TwoEdgeConnectedComponents.hpp
  - icon: ':warning:'
    path: Graph2/WeightedMaximumIndependentSet.hpp
    title: Graph2/WeightedMaximumIndependentSet.hpp
  - icon: ':x:'
    path: Graph2/Yen.hpp
    title: Yen's Algorithm (K-Shortest-Path)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ_GRL_1_A.test.cpp
    title: test/AOJ_GRL_1_A.test.cpp
  - icon: ':x:'
    path: test/AOJ_GRL_3_A.test.cpp
    title: test/AOJ_GRL_3_A.test.cpp
  - icon: ':x:'
    path: test/yosupo_CycleDetection2.test.cpp
    title: test/yosupo_CycleDetection2.test.cpp
  - icon: ':x:'
    path: test/yosupo_KSW.test.cpp
    title: test/yosupo_KSW.test.cpp
  - icon: ':x:'
    path: test/yosupo_TECC.test.cpp
    title: test/yosupo_TECC.test.cpp
  - icon: ':x:'
    path: test/yosupo_TreeDiameter.test.cpp
    title: test/yosupo_TreeDiameter.test.cpp
  - icon: ':x:'
    path: test/yosupo_scc2.test.cpp
    title: test/yosupo_scc2.test.cpp
  - icon: ':x:'
    path: test/yuki1249.test.cpp
    title: test/yuki1249.test.cpp
  - icon: ':x:'
    path: test/yuki4227.test.cpp
    title: test/yuki4227.test.cpp
  - icon: ':x:'
    path: test/yuki5436.test.cpp
    title: test/yuki5436.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://ei1333.github.io/library/graph/graph-template.hpp
  bundledCode: "#line 1 \"Graph2/GraphTemplate.hpp\"\n// graph template\n// ref :\
    \ https://ei1333.github.io/library/graph/graph-template.hpp\ntemplate<typename\
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
  code: "// graph template\n// ref : https://ei1333.github.io/library/graph/graph-template.hpp\n\
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
  path: Graph2/GraphTemplate.hpp
  requiredBy:
  - Graph2/HeavyLightDecomposition.hpp
  - Graph2/LowLink.hpp
  - Graph2/Eppstein.hpp
  - Graph2/TwoEdgeConnectedComponents.hpp
  - Graph2/Yen.hpp
  - Graph2/GraphRelabel.hpp
  - Graph2/WeightedMaximumIndependentSet.hpp
  - Graph2/RangeEdgeGraph.hpp
  - Graph2/StronglyConnectedComponents.hpp
  - Graph2/CycleDetection.hpp
  - Graph2/Dijkstra.hpp
  - Graph2/TreeDiameter.hpp
  - Graph2/Rerooting.hpp
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ_GRL_1_A.test.cpp
  - test/yuki1249.test.cpp
  - test/yuki5436.test.cpp
  - test/yosupo_TECC.test.cpp
  - test/yuki4227.test.cpp
  - test/AOJ_GRL_3_A.test.cpp
  - test/yosupo_CycleDetection2.test.cpp
  - test/yosupo_scc2.test.cpp
  - test/yosupo_KSW.test.cpp
  - test/yosupo_TreeDiameter.test.cpp
documentation_of: Graph2/GraphTemplate.hpp
layout: document
redirect_from:
- /library/Graph2/GraphTemplate.hpp
- /library/Graph2/GraphTemplate.hpp.html
title: Graph2/GraphTemplate.hpp
---

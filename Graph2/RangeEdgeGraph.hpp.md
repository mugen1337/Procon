---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph2/GraphTemplate.hpp
    title: Graph2/GraphTemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/786/submission/131901643
  bundledCode: "#line 1 \"Graph2/GraphTemplate.hpp\"\n\n\n\n// graph template\n//\
    \ ref : https://ei1333.github.io/library/graph/graph-template.hpp\ntemplate<typename\
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n\n\n#line 2\
    \ \"Graph2/RangeEdgeGraph.hpp\"\n\n/*\nverified : https://codeforces.com/contest/786/submission/131901643\n\
    \nvertex -> [sz, sz*2)\nmap [sz * 3, sz * 4) -> [sz, sz*2)\n \n\u4ED6\u306E\u30B0\
    \u30E9\u30D5\u30E9\u30A4\u30D6\u30E9\u30EA\u306B\u9069\u7528\u3055\u305B\u305F\
    \u3044\u5834\u5408\n    RangeEdgeGraph.G\u3092\u4ED6\u306E\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u306B\u6E21\u3059\uFF0E\n    \u5143\u30B0\u30E9\u30D5\u306E\u9802\u70B9\
    u\u306E\u7D50\u679C\u3092\u5F97\u305F\u3044\u5834\u5408\u306FRangeEdgeGraph[u]\u304C\
    \n    RangeEdgeGraph.G\u306E\u9802\u70B9\u306B\u5BFE\u5FDC\u3059\u308B\u306E\u3067\
    \u3068\u308C\u308B\uFF0E\n*/\ntemplate<typename T>\nstruct RangeEdgeGraph{\npublic:\n\
    \    int N,M,sz;\n    Graph<T> G;\n \n    RangeEdgeGraph(int N,int M):N(N),M(M){\n\
    \        sz=1,p=0;\n        while(sz<N) sz<<=1;\n        G=Graph<T>(sz*3+M);\n\
    \ \n        for(int i=1;i<sz;i++){\n            G.add_directed_edge(i,i*2,  0);\n\
    \            G.add_directed_edge(i,i*2+1,0);\n \n            G.add_directed_edge(fix(i*2+sz*2),\
    \  i+sz*2,0);\n            G.add_directed_edge(fix(i*2+1+sz*2),i+sz*2,0);\n  \
    \      }\n    }\n \n    void add_edge(int from_l,int from_r,int to_l,int to_r,T\
    \ w=1){\n        assert(p<M);\n        int t=(p++)+sz*3;\n        for(from_l+=sz,from_r+=sz;from_l<from_r;from_l>>=1,from_r>>=1){\n\
    \            if(from_l&1) G.add_directed_edge(fix((from_l++)+sz*2),t,0);\n   \
    \         if(from_r&1) G.add_directed_edge(fix((--from_r)+sz*2),t,0);\n      \
    \  }\n        for(to_l+=sz,to_r+=sz;to_l<to_r;to_l>>=1,to_r>>=1){\n          \
    \  if(to_l&1) G.add_directed_edge(t,(to_l++),w);\n            if(to_r&1) G.add_directed_edge(t,(--to_r),w);\n\
    \        }\n    }\n \n    int get(const int &u) const { return u+sz; }\n    int\
    \ operator[](const int &k) const {return get(k);}\n \nprivate:\n    int p;\n \
    \   int fix(int u){\n        if(u>=3*sz) return u-=2*sz;\n        return u;\n\
    \    }\n};\n"
  code: "#include \"./GraphTemplate.hpp\"\n\n/*\nverified : https://codeforces.com/contest/786/submission/131901643\n\
    \nvertex -> [sz, sz*2)\nmap [sz * 3, sz * 4) -> [sz, sz*2)\n \n\u4ED6\u306E\u30B0\
    \u30E9\u30D5\u30E9\u30A4\u30D6\u30E9\u30EA\u306B\u9069\u7528\u3055\u305B\u305F\
    \u3044\u5834\u5408\n    RangeEdgeGraph.G\u3092\u4ED6\u306E\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u306B\u6E21\u3059\uFF0E\n    \u5143\u30B0\u30E9\u30D5\u306E\u9802\u70B9\
    u\u306E\u7D50\u679C\u3092\u5F97\u305F\u3044\u5834\u5408\u306FRangeEdgeGraph[u]\u304C\
    \n    RangeEdgeGraph.G\u306E\u9802\u70B9\u306B\u5BFE\u5FDC\u3059\u308B\u306E\u3067\
    \u3068\u308C\u308B\uFF0E\n*/\ntemplate<typename T>\nstruct RangeEdgeGraph{\npublic:\n\
    \    int N,M,sz;\n    Graph<T> G;\n \n    RangeEdgeGraph(int N,int M):N(N),M(M){\n\
    \        sz=1,p=0;\n        while(sz<N) sz<<=1;\n        G=Graph<T>(sz*3+M);\n\
    \ \n        for(int i=1;i<sz;i++){\n            G.add_directed_edge(i,i*2,  0);\n\
    \            G.add_directed_edge(i,i*2+1,0);\n \n            G.add_directed_edge(fix(i*2+sz*2),\
    \  i+sz*2,0);\n            G.add_directed_edge(fix(i*2+1+sz*2),i+sz*2,0);\n  \
    \      }\n    }\n \n    void add_edge(int from_l,int from_r,int to_l,int to_r,T\
    \ w=1){\n        assert(p<M);\n        int t=(p++)+sz*3;\n        for(from_l+=sz,from_r+=sz;from_l<from_r;from_l>>=1,from_r>>=1){\n\
    \            if(from_l&1) G.add_directed_edge(fix((from_l++)+sz*2),t,0);\n   \
    \         if(from_r&1) G.add_directed_edge(fix((--from_r)+sz*2),t,0);\n      \
    \  }\n        for(to_l+=sz,to_r+=sz;to_l<to_r;to_l>>=1,to_r>>=1){\n          \
    \  if(to_l&1) G.add_directed_edge(t,(to_l++),w);\n            if(to_r&1) G.add_directed_edge(t,(--to_r),w);\n\
    \        }\n    }\n \n    int get(const int &u) const { return u+sz; }\n    int\
    \ operator[](const int &k) const {return get(k);}\n \nprivate:\n    int p;\n \
    \   int fix(int u){\n        if(u>=3*sz) return u-=2*sz;\n        return u;\n\
    \    }\n};"
  dependsOn:
  - Graph2/GraphTemplate.hpp
  isVerificationFile: false
  path: Graph2/RangeEdgeGraph.hpp
  requiredBy: []
  timestamp: '2023-07-17 18:02:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph2/RangeEdgeGraph.hpp
layout: document
title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
---

## 概要  

https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656

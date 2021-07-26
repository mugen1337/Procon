---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph2/GraphTemplate.cpp
    title: Graph2/GraphTemplate.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Graph2/TwoEdgeConnectedComponents.cpp
    title: Graph2/TwoEdgeConnectedComponents.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_GRL_3_A.test.cpp
    title: test/AOJ_GRL_3_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n#line 2 \"Graph2/LowLink.cpp\"\
    \n\ntemplate<typename T>\nstruct LowLink{\n    Graph<T> &g;\n    vector<int> ord,low;\n\
    \    vector<int> art;// articulation (true/false)\n    vector<Edge<T>> bridge;\n\
    \n    LowLink(Graph<T> &g):g(g){\n        ord.assign(g.V,-1);\n        low.assign(g.V,-1);\n\
    \        art.resize(g.V);\n\n        int idx=0;\n        function<void(int,int)>\
    \ dfs=[&](int pre,int cur){\n            ord[cur]=idx++;\n            low[cur]=ord[cur];\n\
    \n            int pre_c=0,ch=0;\n            bool art_f=false;\n\n           \
    \ for(auto &e:g[cur]){\n                if(e==pre and pre_c==0){\n           \
    \         pre_c++;\n                    continue;\n                }\n       \
    \         if(ord[e]<0){\n                    ch++;\n                    dfs(cur,e);\n\
    \                    low[cur]=min(low[cur],low[e]);\n                    art_f|=(pre>=0\
    \ and low[e]>=ord[cur]);\n                    if(ord[cur]<low[e]) bridge.push_back(e);\n\
    \                }\n                else{\n                    low[cur]=min(low[cur],ord[e]);\n\
    \                }\n            }\n            if(pre==-1) art_f|=(ch>1);\n  \
    \          art[cur]=art_f;\n            return ;\n        };\n        for(int\
    \ i=0;i<g.V;i++)if(ord[i]<0) dfs(-1,i);\n    }\n};\n"
  code: "#include \"./GraphTemplate.cpp\"\n\ntemplate<typename T>\nstruct LowLink{\n\
    \    Graph<T> &g;\n    vector<int> ord,low;\n    vector<int> art;// articulation\
    \ (true/false)\n    vector<Edge<T>> bridge;\n\n    LowLink(Graph<T> &g):g(g){\n\
    \        ord.assign(g.V,-1);\n        low.assign(g.V,-1);\n        art.resize(g.V);\n\
    \n        int idx=0;\n        function<void(int,int)> dfs=[&](int pre,int cur){\n\
    \            ord[cur]=idx++;\n            low[cur]=ord[cur];\n\n            int\
    \ pre_c=0,ch=0;\n            bool art_f=false;\n\n            for(auto &e:g[cur]){\n\
    \                if(e==pre and pre_c==0){\n                    pre_c++;\n    \
    \                continue;\n                }\n                if(ord[e]<0){\n\
    \                    ch++;\n                    dfs(cur,e);\n                \
    \    low[cur]=min(low[cur],low[e]);\n                    art_f|=(pre>=0 and low[e]>=ord[cur]);\n\
    \                    if(ord[cur]<low[e]) bridge.push_back(e);\n              \
    \  }\n                else{\n                    low[cur]=min(low[cur],ord[e]);\n\
    \                }\n            }\n            if(pre==-1) art_f|=(ch>1);\n  \
    \          art[cur]=art_f;\n            return ;\n        };\n        for(int\
    \ i=0;i<g.V;i++)if(ord[i]<0) dfs(-1,i);\n    }\n};"
  dependsOn:
  - Graph2/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph2/LowLink.cpp
  requiredBy:
  - Graph2/TwoEdgeConnectedComponents.cpp
  timestamp: '2021-07-04 13:54:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_GRL_3_A.test.cpp
documentation_of: Graph2/LowLink.cpp
layout: document
title: Low Link
---

## 概要  
https://kagamiz.hatenablog.com/entry/2013/10/05/005213  
dfs木作る．  
ord[u] : dfsの訪問順  
low[u] : uから後退辺を1度だけ使って一番できる根側の頂点  

u->vの辺がある時，ord[u]<low[v]なら橋  

関節点の判定も可能．  
- 根なら子が2個以上あるか  
- そうでなければ，橋が生えているか  

## 仕様  
- art[i] : trueなら頂点iは関節点  
- bridge : 橋一覧  

## 計算量  
頂点数をV, 変数をEとする  
dfsしかしていないため  
O(V+E)  

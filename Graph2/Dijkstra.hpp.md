---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph2/GraphTemplate.hpp
    title: Graph2/GraphTemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_GRL_1_A.test.cpp
    title: test/AOJ_GRL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \ \"Graph2/Dijkstra.hpp\"\n\ntemplate<typename T>\nstruct Dijkstra{\n    const\
    \ T inf;\n    Graph<T> g;\n    vector<T> d;\n    vector<int> prev,eid;\n    \n\
    \    Dijkstra(Graph<T> g):inf(numeric_limits<T>::max()/4),g(g){}\n\n    vector<T>\
    \ build(int st){\n        d.assign(g.V,inf);\n        prev.assign(g.V,-1);\n \
    \       eid.assign(g.V,-1);\n        d[st]=0;\n        priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n        que.emplace(d[st],st);\n        while(!que.empty()){\n       \
    \     auto p=que.top();que.pop();\n            int cur=p.second;\n           \
    \ if(d[cur]<p.first) continue;\n            for(auto &e:g[cur]){\n           \
    \     if(d[e]>d[cur]+e.w){\n                    d[e]=d[cur]+e.w;\n           \
    \         prev[e]=cur;\n                    que.emplace(d[e],e);\n           \
    \     }\n            }\n        }\n        return d;\n    }\n\n    // vertex =\
    \ false :-> edge idx\n    vector<int> get_path(int gl,bool vertex=true){\n   \
    \     vector<int> ret;\n        if(d[gl]==inf) return ret;\n        for(;gl!=-1;gl=prev[gl]){\n\
    \            ret.push_back(vertex?gl:eid[gl]);\n        }\n        reverse(ret.begin(),ret.end());\n\
    \        return ret;\n    }\n};\n"
  code: "#include \"./GraphTemplate.hpp\"\n\ntemplate<typename T>\nstruct Dijkstra{\n\
    \    const T inf;\n    Graph<T> g;\n    vector<T> d;\n    vector<int> prev,eid;\n\
    \    \n    Dijkstra(Graph<T> g):inf(numeric_limits<T>::max()/4),g(g){}\n\n   \
    \ vector<T> build(int st){\n        d.assign(g.V,inf);\n        prev.assign(g.V,-1);\n\
    \        eid.assign(g.V,-1);\n        d[st]=0;\n        priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n        que.emplace(d[st],st);\n        while(!que.empty()){\n       \
    \     auto p=que.top();que.pop();\n            int cur=p.second;\n           \
    \ if(d[cur]<p.first) continue;\n            for(auto &e:g[cur]){\n           \
    \     if(d[e]>d[cur]+e.w){\n                    d[e]=d[cur]+e.w;\n           \
    \         prev[e]=cur;\n                    que.emplace(d[e],e);\n           \
    \     }\n            }\n        }\n        return d;\n    }\n\n    // vertex =\
    \ false :-> edge idx\n    vector<int> get_path(int gl,bool vertex=true){\n   \
    \     vector<int> ret;\n        if(d[gl]==inf) return ret;\n        for(;gl!=-1;gl=prev[gl]){\n\
    \            ret.push_back(vertex?gl:eid[gl]);\n        }\n        reverse(ret.begin(),ret.end());\n\
    \        return ret;\n    }\n};"
  dependsOn:
  - Graph2/GraphTemplate.hpp
  isVerificationFile: false
  path: Graph2/Dijkstra.hpp
  requiredBy: []
  timestamp: '2023-07-17 18:02:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_GRL_1_A.test.cpp
documentation_of: Graph2/Dijkstra.hpp
layout: document
title: Dijkstra
---

# 概要  
Dijkstra法  
O((E+V)logV)  

# 仕様  
- build(st) 始点をstとして構築  
- get_path(gl) st-glのパス上の頂点が入ったvectorを返す  

# あ  
これ書いてて思ったのですが，get_path, 辺のvectorを返す方が情報量多くていいかもしれないのでいつかそうするかもしれない  

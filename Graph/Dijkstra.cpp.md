---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Shortest_Path.test.cpp
    title: test/yosupo_Shortest_Path.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Dijkstra.cpp\"\ntemplate<typename T>\nstruct Dijkstra{\n\
    \    const T TINF=numeric_limits<T>::max();\n    using P=pair<T,int>;\n    int\
    \ n;\n    vector<vector<P>> G;\n    vector<T> d;\n    vector<int> prev;\n  \n\
    \    Dijkstra(int n):n(n),G(vector<vector<P>>(n)){}\n    void init(){\n      \
    \  d.assign(n,TINF);\n        prev.assign(n,-1);\n    }\n    void add_edge(int\
    \ s,int t,T cost){\n        G[s].push_back(P(cost,t));\n    }\n    void build(int\
    \ s){\n        init();\n        d[s]=0;\n        priority_queue<P,vector<P>,greater<P>>\
    \ q;\n        q.push(P(d[s],s));\n        while(!q.empty()){\n            P p=q.top();q.pop();\n\
    \            int v=p.second;\n            if(d[v]<p.first) continue;\n       \
    \     for(auto e:G[v]){\n                int u=e.second;\n                T cost=e.first;\n\
    \                if(d[u]>d[v]+e.first){\n                    d[u]=d[v]+cost;\n\
    \                    prev[u]=v;\n                    q.push(P(d[u],u));\n    \
    \            }\n            }\n        }\n    }\n \n    T operator[](const int\
    \ &p)const{\n        return d[p];\n    }\n \n    vector<int> get_path(int g){\n\
    \        vector<int> ret;\n        if(d[g]==TINF) return ret;\n        for(;g!=-1;g=prev[g]){\n\
    \            ret.push_back(g);\n        }\n        reverse(ret.begin(),ret.end());\n\
    \        return ret;\n    }\n};\n"
  code: "template<typename T>\nstruct Dijkstra{\n    const T TINF=numeric_limits<T>::max();\n\
    \    using P=pair<T,int>;\n    int n;\n    vector<vector<P>> G;\n    vector<T>\
    \ d;\n    vector<int> prev;\n  \n    Dijkstra(int n):n(n),G(vector<vector<P>>(n)){}\n\
    \    void init(){\n        d.assign(n,TINF);\n        prev.assign(n,-1);\n   \
    \ }\n    void add_edge(int s,int t,T cost){\n        G[s].push_back(P(cost,t));\n\
    \    }\n    void build(int s){\n        init();\n        d[s]=0;\n        priority_queue<P,vector<P>,greater<P>>\
    \ q;\n        q.push(P(d[s],s));\n        while(!q.empty()){\n            P p=q.top();q.pop();\n\
    \            int v=p.second;\n            if(d[v]<p.first) continue;\n       \
    \     for(auto e:G[v]){\n                int u=e.second;\n                T cost=e.first;\n\
    \                if(d[u]>d[v]+e.first){\n                    d[u]=d[v]+cost;\n\
    \                    prev[u]=v;\n                    q.push(P(d[u],u));\n    \
    \            }\n            }\n        }\n    }\n \n    T operator[](const int\
    \ &p)const{\n        return d[p];\n    }\n \n    vector<int> get_path(int g){\n\
    \        vector<int> ret;\n        if(d[g]==TINF) return ret;\n        for(;g!=-1;g=prev[g]){\n\
    \            ret.push_back(g);\n        }\n        reverse(ret.begin(),ret.end());\n\
    \        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2021-01-09 19:32:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_Shortest_Path.test.cpp
documentation_of: Graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/Graph/Dijkstra.cpp
- /library/Graph/Dijkstra.cpp.html
title: Graph/Dijkstra.cpp
---
---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph2/Namori.cpp\"\n/*\nNamori Graph\n\nloop_vertex[i]\
    \ - loop_edge[i] loop_vertex[i+1]\nforest : loop_vertex\u304B\u3089\u3076\u3089\
    \u4E0B\u304C\u308B\u6728\n         loop_vertex\u3092root, 0\u3068\u3057\u3066\
    id\u3075\u308A\u76F4\u3057\n*/\ntemplate<typename T>\nstruct Namori{\n    Graph<T>\
    \ G;\n    vector<int> loop_vertex;\n    vector<Edge<T>> loop_edge;\n    vector<Graph<int>>\
    \ forest;\n\n    Namori(Graph<T> G):G(G){\n        int N=G.size();\n\n       \
    \ // loop \u53D6\u308A\u51FA\u3057\n        vector<bool> used(N, false);\n   \
    \     {\n            vector<int> deg(N);\n            queue<int> que;\n      \
    \      for(int i=0;i<N;i++){\n                deg[i]=G[i].size();\n          \
    \      if(deg[i]==1){\n                    que.push(i);\n                    used[i]=true;\n\
    \                }\n            }\n\n            while(not que.empty()){\n   \
    \             int cur=que.front();que.pop();\n\n                for(auto &e:G[cur])if(not\
    \ used[e]){\n                    deg[e]--;\n                    if(deg[e]==1){\n\
    \                        que.push(e);\n                        used[e]=true;\n\
    \                    }\n                }\n            }\n        }\n\n      \
    \  // loop\u9806\u5E8F\n        {\n            queue<int> que;\n            vector<bool>\
    \ visited(N, false);\n            for(int i=0;i<N;i++){\n                if(not\
    \ used[i]){\n                    que.push(i);\n                    visited[i]=true;\n\
    \                    loop_vertex.push_back(i);\n                    break;\n \
    \               }\n            }\n            while(not que.empty()){\n      \
    \          int cur=que.front();que.pop();\n                for(auto &e:G[cur])if((not\
    \ used[e]) and (not visited[e])){\n                    visited[e]=true;\n    \
    \                que.push(e);\n                    loop_vertex.push_back(e);\n\
    \                    loop_edge.emplace_back(e.from, e.to, e.w, e.idx);\n     \
    \               break;\n                }\n            }\n            for(auto\
    \ &e:G[loop_vertex.back()])\n                if(minmax(e.from, e.to)==minmax(loop_vertex[0],\
    \ loop_vertex.back()))\n                    loop_edge.push_back(e);\n        }\n\
    \        \n\n\n        // forest \u69CB\u7BC9\n        {\n            vector<int>\
    \ id(N, -1);\n            for(int root:loop_vertex){\n                vector<Edge<T>>\
    \ es;\n                int V=0;\n                function<void(int,int)> dfs=[&](int\
    \ par, int cur){\n                    for(auto &e:G[cur])if(par!=e and (used[e])){\n\
    \                        if(id[e]==-1) id[e]=V++;\n                        es.emplace_back(id[cur],\
    \ id[e], e.w, e.idx);\n                        dfs(cur, e);\n                \
    \    }\n                };\n                id[root]=V++;\n                dfs(-1,\
    \ root);\n\n                Graph<T> g(V);\n                for(auto &e:es) g.add_edge(e.from,\
    \ e.to, e.w);\n                forest.push_back(g);\n            }\n        }\n\
    \    }\n};\n"
  code: "/*\nNamori Graph\n\nloop_vertex[i] - loop_edge[i] loop_vertex[i+1]\nforest\
    \ : loop_vertex\u304B\u3089\u3076\u3089\u4E0B\u304C\u308B\u6728\n         loop_vertex\u3092\
    root, 0\u3068\u3057\u3066id\u3075\u308A\u76F4\u3057\n*/\ntemplate<typename T>\n\
    struct Namori{\n    Graph<T> G;\n    vector<int> loop_vertex;\n    vector<Edge<T>>\
    \ loop_edge;\n    vector<Graph<int>> forest;\n\n    Namori(Graph<T> G):G(G){\n\
    \        int N=G.size();\n\n        // loop \u53D6\u308A\u51FA\u3057\n       \
    \ vector<bool> used(N, false);\n        {\n            vector<int> deg(N);\n \
    \           queue<int> que;\n            for(int i=0;i<N;i++){\n             \
    \   deg[i]=G[i].size();\n                if(deg[i]==1){\n                    que.push(i);\n\
    \                    used[i]=true;\n                }\n            }\n\n     \
    \       while(not que.empty()){\n                int cur=que.front();que.pop();\n\
    \n                for(auto &e:G[cur])if(not used[e]){\n                    deg[e]--;\n\
    \                    if(deg[e]==1){\n                        que.push(e);\n  \
    \                      used[e]=true;\n                    }\n                }\n\
    \            }\n        }\n\n        // loop\u9806\u5E8F\n        {\n        \
    \    queue<int> que;\n            vector<bool> visited(N, false);\n          \
    \  for(int i=0;i<N;i++){\n                if(not used[i]){\n                 \
    \   que.push(i);\n                    visited[i]=true;\n                    loop_vertex.push_back(i);\n\
    \                    break;\n                }\n            }\n            while(not\
    \ que.empty()){\n                int cur=que.front();que.pop();\n            \
    \    for(auto &e:G[cur])if((not used[e]) and (not visited[e])){\n            \
    \        visited[e]=true;\n                    que.push(e);\n                \
    \    loop_vertex.push_back(e);\n                    loop_edge.emplace_back(e.from,\
    \ e.to, e.w, e.idx);\n                    break;\n                }\n        \
    \    }\n            for(auto &e:G[loop_vertex.back()])\n                if(minmax(e.from,\
    \ e.to)==minmax(loop_vertex[0], loop_vertex.back()))\n                    loop_edge.push_back(e);\n\
    \        }\n        \n\n\n        // forest \u69CB\u7BC9\n        {\n        \
    \    vector<int> id(N, -1);\n            for(int root:loop_vertex){\n        \
    \        vector<Edge<T>> es;\n                int V=0;\n                function<void(int,int)>\
    \ dfs=[&](int par, int cur){\n                    for(auto &e:G[cur])if(par!=e\
    \ and (used[e])){\n                        if(id[e]==-1) id[e]=V++;\n        \
    \                es.emplace_back(id[cur], id[e], e.w, e.idx);\n              \
    \          dfs(cur, e);\n                    }\n                };\n         \
    \       id[root]=V++;\n                dfs(-1, root);\n\n                Graph<T>\
    \ g(V);\n                for(auto &e:es) g.add_edge(e.from, e.to, e.w);\n    \
    \            forest.push_back(g);\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph2/Namori.cpp
  requiredBy: []
  timestamp: '2022-03-09 15:59:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph2/Namori.cpp
layout: document
redirect_from:
- /library/Graph2/Namori.cpp
- /library/Graph2/Namori.cpp.html
title: Graph2/Namori.cpp
---

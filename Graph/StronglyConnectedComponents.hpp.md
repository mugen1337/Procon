---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_scc.test.cpp
    title: test/yosupo_scc.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/StronglyConnectedComponents.hpp\"\nstruct StronglyConnectedComponents{\n\
    \    private:\n    vector<vector<int>> g,rg;\n    vector<int> check;\n    void\
    \ dfs(int cur,vector<int> &ord){\n        for(auto &to:g[cur])if(!check[to]){\n\
    \            check[to]=true;\n            dfs(to,ord);\n        }\n        ord.push_back(cur);\n\
    \    }\n    void rdfs(int cur,int p){\n        for(auto &to:rg[cur])if(comp[to]==-1){\n\
    \            comp[to]=p;\n            rdfs(to,p);\n        }\n    }\n\n    public:\n\
    \    vector<int> comp;\n    vector<vector<int>> compressed,group;\n    \n    StronglyConnectedComponents(vector<vector<int>>\
    \ &g):g(g),rg(g.size()),check(g.size()),comp(g.size(),-1){\n        for(int i=0;i<(int)g.size();i++)for(auto\
    \ &j:g[i]) rg[j].push_back(i);\n    }\n    // return compressed graph\n    vector<vector<int>>\
    \ build(){\n        vector<int> ord;\n        for(int i=0;i<(int)g.size();i++)if(!check[i]){\n\
    \            check[i]=true;\n            dfs(i,ord);\n        }\n        int ptr=0;;\n\
    \        for(int i=(int)ord.size()-1;i>=0;i--)if(comp[ord[i]]==-1){\n        \
    \    comp[ord[i]]=ptr;\n            rdfs(ord[i],ptr);ptr++;\n        }\n     \
    \   compressed.resize(ptr);\n        group.resize(ptr);\n        for(int i=0;i<(int)g.size();i++){\n\
    \            int u=comp[i];\n            group[u].push_back(i);\n            for(auto\
    \ &j:g[i]){\n                int v=comp[j];\n                if(u!=v) compressed[u].push_back(v);\n\
    \            }\n        }\n        return compressed;\n    }\n};\n"
  code: "struct StronglyConnectedComponents{\n    private:\n    vector<vector<int>>\
    \ g,rg;\n    vector<int> check;\n    void dfs(int cur,vector<int> &ord){\n   \
    \     for(auto &to:g[cur])if(!check[to]){\n            check[to]=true;\n     \
    \       dfs(to,ord);\n        }\n        ord.push_back(cur);\n    }\n    void\
    \ rdfs(int cur,int p){\n        for(auto &to:rg[cur])if(comp[to]==-1){\n     \
    \       comp[to]=p;\n            rdfs(to,p);\n        }\n    }\n\n    public:\n\
    \    vector<int> comp;\n    vector<vector<int>> compressed,group;\n    \n    StronglyConnectedComponents(vector<vector<int>>\
    \ &g):g(g),rg(g.size()),check(g.size()),comp(g.size(),-1){\n        for(int i=0;i<(int)g.size();i++)for(auto\
    \ &j:g[i]) rg[j].push_back(i);\n    }\n    // return compressed graph\n    vector<vector<int>>\
    \ build(){\n        vector<int> ord;\n        for(int i=0;i<(int)g.size();i++)if(!check[i]){\n\
    \            check[i]=true;\n            dfs(i,ord);\n        }\n        int ptr=0;;\n\
    \        for(int i=(int)ord.size()-1;i>=0;i--)if(comp[ord[i]]==-1){\n        \
    \    comp[ord[i]]=ptr;\n            rdfs(ord[i],ptr);ptr++;\n        }\n     \
    \   compressed.resize(ptr);\n        group.resize(ptr);\n        for(int i=0;i<(int)g.size();i++){\n\
    \            int u=comp[i];\n            group[u].push_back(i);\n            for(auto\
    \ &j:g[i]){\n                int v=comp[j];\n                if(u!=v) compressed[u].push_back(v);\n\
    \            }\n        }\n        return compressed;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/StronglyConnectedComponents.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_scc.test.cpp
documentation_of: Graph/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/Graph/StronglyConnectedComponents.hpp
- /library/Graph/StronglyConnectedComponents.hpp.html
title: Graph/StronglyConnectedComponents.hpp
---

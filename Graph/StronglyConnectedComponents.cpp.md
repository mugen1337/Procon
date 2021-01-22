---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_scc.test.cpp
    title: test/yosupo_scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/StronglyConnectedComponents.cpp\"\nstruct StronglyConnectedComponents{\n\
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
  path: Graph/StronglyConnectedComponents.cpp
  requiredBy: []
  timestamp: '2021-01-04 00:24:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_scc.test.cpp
documentation_of: Graph/StronglyConnectedComponents.cpp
layout: document
redirect_from:
- /library/Graph/StronglyConnectedComponents.cpp
- /library/Graph/StronglyConnectedComponents.cpp.html
title: Graph/StronglyConnectedComponents.cpp
---

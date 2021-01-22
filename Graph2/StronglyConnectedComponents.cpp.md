---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph2/GraphTemplate.cpp
    title: Graph2/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_scc2.test.cpp
    title: test/yosupo_scc2.test.cpp
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
    \    Graph(int n):g(n),V(n),E(0){}\n\n    size_t size(){\n        return g.size();\n\
    \    }\n    void resize(int k){\n        g.resize(k);\n    }\n    inline const\
    \ vector<Edge<T>> &operator[](int k)const{\n        return (g.at(k));\n    }\n\
    \    inline vector<Edge<T>> &operator[](int k){\n        return (g.at(k));\n \
    \   }\n    void add_directed_edge(int from,int to,T cost=1){\n        g[from].emplace_back(from,to,cost,E++);\n\
    \    }\n    void add_edge(int from,int to,T cost=1){\n        g[from].emplace_back(from,to,cost,E);\n\
    \        g[to].emplace_back(to,from,cost,E++);\n    }\n    void read(int m,int\
    \ pad=-1,bool weighted=false,bool directed=false){\n        for(int i=0;i<m;i++){\n\
    \            int u,v;cin>>u>>v;\n            u+=pad,v+=pad;\n            T w=T(1);\n\
    \            if(weighted) cin>>w;\n            if(directed) add_directed_edge(u,v,w);\n\
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n#line 2 \"Graph2/StronglyConnectedComponents.cpp\"\
    \n\n// scc.comp[i]    : strongly connected components i belongs \n// scc.group[i]\
    \   : vertice i-th strongly connected component has\n// scc.compressed : compressed\
    \ Graph, DAG\ntemplate<typename T=int>\nstruct StronglyConnectedComponents{\n\
    \    private:\n    Graph<T> g,rg;\n    vector<int> check;\n    void dfs(int cur,vector<int>\
    \ &ord){\n        for(auto &to:g[cur])if(!check[to]){\n            check[to]=true;\n\
    \            dfs(to,ord);\n        }\n        ord.push_back(cur);\n    }\n   \
    \ void rdfs(int cur,int p){\n        for(auto &to:rg[cur])if(comp[to]==-1){\n\
    \            comp[to]=p;\n            rdfs(to,p);\n        }\n    }\n\n    void\
    \ build(){\n        vector<int> ord;\n        for(int i=0;i<(int)g.size();i++)if(!check[i]){\n\
    \            check[i]=true;\n            dfs(i,ord);\n        }\n        int ptr=0;;\n\
    \        for(int i=(int)ord.size()-1;i>=0;i--)if(comp[ord[i]]==-1){\n        \
    \    comp[ord[i]]=ptr;\n            rdfs(ord[i],ptr);ptr++;\n        }\n     \
    \   compressed.resize(ptr);\n        group.resize(ptr);\n        for(int i=0;i<(int)g.size();i++){\n\
    \            int u=comp[i];\n            group[u].push_back(i);\n            for(auto\
    \ &e:g[i]){\n                int v=comp[e];\n                if(u!=v) compressed.add_directed_edge(u,v,e.w);\n\
    \            }\n        }\n        return ;\n    }\n\n    public:\n    vector<int>\
    \ comp;\n    vector<vector<int>> group;\n    Graph<T> compressed;\n    \n    StronglyConnectedComponents(Graph<T>\
    \ &g):g(g),rg(g.size()),check(g.size()),comp(g.size(),-1){\n        for(int i=0;i<(int)g.size();i++)for(auto\
    \ &e:g[i]) rg.add_directed_edge(e.to,e.from,e.w);\n        build();\n    }\n};\n"
  code: "#include \"./GraphTemplate.cpp\"\n\n// scc.comp[i]    : strongly connected\
    \ components i belongs \n// scc.group[i]   : vertice i-th strongly connected component\
    \ has\n// scc.compressed : compressed Graph, DAG\ntemplate<typename T=int>\nstruct\
    \ StronglyConnectedComponents{\n    private:\n    Graph<T> g,rg;\n    vector<int>\
    \ check;\n    void dfs(int cur,vector<int> &ord){\n        for(auto &to:g[cur])if(!check[to]){\n\
    \            check[to]=true;\n            dfs(to,ord);\n        }\n        ord.push_back(cur);\n\
    \    }\n    void rdfs(int cur,int p){\n        for(auto &to:rg[cur])if(comp[to]==-1){\n\
    \            comp[to]=p;\n            rdfs(to,p);\n        }\n    }\n\n    void\
    \ build(){\n        vector<int> ord;\n        for(int i=0;i<(int)g.size();i++)if(!check[i]){\n\
    \            check[i]=true;\n            dfs(i,ord);\n        }\n        int ptr=0;;\n\
    \        for(int i=(int)ord.size()-1;i>=0;i--)if(comp[ord[i]]==-1){\n        \
    \    comp[ord[i]]=ptr;\n            rdfs(ord[i],ptr);ptr++;\n        }\n     \
    \   compressed.resize(ptr);\n        group.resize(ptr);\n        for(int i=0;i<(int)g.size();i++){\n\
    \            int u=comp[i];\n            group[u].push_back(i);\n            for(auto\
    \ &e:g[i]){\n                int v=comp[e];\n                if(u!=v) compressed.add_directed_edge(u,v,e.w);\n\
    \            }\n        }\n        return ;\n    }\n\n    public:\n    vector<int>\
    \ comp;\n    vector<vector<int>> group;\n    Graph<T> compressed;\n    \n    StronglyConnectedComponents(Graph<T>\
    \ &g):g(g),rg(g.size()),check(g.size()),comp(g.size(),-1){\n        for(int i=0;i<(int)g.size();i++)for(auto\
    \ &e:g[i]) rg.add_directed_edge(e.to,e.from,e.w);\n        build();\n    }\n};"
  dependsOn:
  - Graph2/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph2/StronglyConnectedComponents.cpp
  requiredBy: []
  timestamp: '2021-01-23 00:46:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_scc2.test.cpp
documentation_of: Graph2/StronglyConnectedComponents.cpp
layout: document
redirect_from:
- /library/Graph2/StronglyConnectedComponents.cpp
- /library/Graph2/StronglyConnectedComponents.cpp.html
title: Graph2/StronglyConnectedComponents.cpp
---

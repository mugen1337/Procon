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
    \ \"Graph2/DoublingLowestCommonAncestor.hpp\"\n\ntemplate< typename T >\nstruct\
    \ DoublingLowestCommonAncestor{\n    const Graph<T> &g;\n    vector<int> dep;\n\
    \    int LOG;\n    //table[i][j]\u306F\u70B9j\u306E2^i\u500B\u4E0A\u306E\u89AA\
    \u60C5\u5831\n    vector<vector<int>> table;\n\n    DoublingLowestCommonAncestor(const\
    \ Graph< T > &g_) : g(g_), dep(g_.V),LOG(32 - __builtin_clz(g_.V))\n    {\n  \
    \      table.assign(LOG, vector<int>(g_.V, -1));\n    }\n \n    void dfs(int idx,\
    \ int par, int d)\n    {\n        //1\u500B\u4E0A\u306E\u89AA\u306E\u8A18\u9332\
    \n        table[0][idx] = par;\n        dep[idx] = d;\n        for(auto &to :\
    \ g[idx])\n        {\n            if(to!=par) dfs(to, idx, d+1);\n        }\n\
    \    }\n \n    //\u6839\u3068\u3057\u305F\u3044\u70B9\u3092root\n    void build(int\
    \ root){\n        dfs(root, -1, 0);\n        for(int k = 0; k + 1 < LOG; k++)\n\
    \        {\n            for(int i = 0; i < (int)table[k].size(); i++)\n      \
    \      {\n                if(table[k][i]==-1) table[k + 1][i] = -1;\n        \
    \        else                table[k + 1][i] = table[k][table[k][i]];\n      \
    \      }\n        }\n    }\n \n    //u,v\u306Elca\u3092\u6C42\u3081\u308B\n  \
    \  int query(int u, int v)\n    {\n        //dep[u]>dep[v]\u3068\u3057\u3066\u9032\
    \u3081\u308B\n        if(dep[u] > dep[v]) swap(u,v);\n        //\u6DF1\u3055\u3092\
    \u305D\u308D\u3048\u308B\n        for(int i = LOG - 1; i >= 0; i--)\n        {\n\
    \            if(((dep[v]-dep[u])>>i)&1) v=table[i][v];\n        }\n        if(u==v)\
    \ return u;\n        for(int i=LOG-1;i>=0;i--){\n            if(table[i][u]!=table[i][v]){\n\
    \                u=table[i][u];\n                v=table[i][v];\n            }\n\
    \        }\n        return table[0][u];\n    }\n    \n    // \u547C\u3073\u51FA\
    \u3059\u305F\u3073O(logn)\n    int dis(int u,int v){\n        int p=query(u,v);\n\
    \        return dep[u]+dep[v]-2*dep[p];\n    }\n \n    // \u6DF1\u3055\u3092\u8FD4\
    \u3059\n    int operator[](const int &k) const{\n        return dep[k];\n    }\n\
    \ \n    //\u9802\u70B9x\u306Ek\u500B\u4E0A\u306E\u89AA\u3092\u6C42\u3081\u308B\
    \u3002\u7121\u3051\u308C\u3070-1\n    int parent(int x,int k){\n        int ret=x;\n\
    \        for(int i=LOG-1;i>=0 and ret>=0;i--){\n            if((k>>i)&1) ret=table[i][ret];\n\
    \        }\n        return ret;\n    }\n};\n"
  code: "#include \"./GraphTemplate.hpp\"\n\ntemplate< typename T >\nstruct DoublingLowestCommonAncestor{\n\
    \    const Graph<T> &g;\n    vector<int> dep;\n    int LOG;\n    //table[i][j]\u306F\
    \u70B9j\u306E2^i\u500B\u4E0A\u306E\u89AA\u60C5\u5831\n    vector<vector<int>>\
    \ table;\n\n    DoublingLowestCommonAncestor(const Graph< T > &g_) : g(g_), dep(g_.V),LOG(32\
    \ - __builtin_clz(g_.V))\n    {\n        table.assign(LOG, vector<int>(g_.V, -1));\n\
    \    }\n \n    void dfs(int idx, int par, int d)\n    {\n        //1\u500B\u4E0A\
    \u306E\u89AA\u306E\u8A18\u9332\n        table[0][idx] = par;\n        dep[idx]\
    \ = d;\n        for(auto &to : g[idx])\n        {\n            if(to!=par) dfs(to,\
    \ idx, d+1);\n        }\n    }\n \n    //\u6839\u3068\u3057\u305F\u3044\u70B9\u3092\
    root\n    void build(int root){\n        dfs(root, -1, 0);\n        for(int k\
    \ = 0; k + 1 < LOG; k++)\n        {\n            for(int i = 0; i < (int)table[k].size();\
    \ i++)\n            {\n                if(table[k][i]==-1) table[k + 1][i] = -1;\n\
    \                else                table[k + 1][i] = table[k][table[k][i]];\n\
    \            }\n        }\n    }\n \n    //u,v\u306Elca\u3092\u6C42\u3081\u308B\
    \n    int query(int u, int v)\n    {\n        //dep[u]>dep[v]\u3068\u3057\u3066\
    \u9032\u3081\u308B\n        if(dep[u] > dep[v]) swap(u,v);\n        //\u6DF1\u3055\
    \u3092\u305D\u308D\u3048\u308B\n        for(int i = LOG - 1; i >= 0; i--)\n  \
    \      {\n            if(((dep[v]-dep[u])>>i)&1) v=table[i][v];\n        }\n \
    \       if(u==v) return u;\n        for(int i=LOG-1;i>=0;i--){\n            if(table[i][u]!=table[i][v]){\n\
    \                u=table[i][u];\n                v=table[i][v];\n            }\n\
    \        }\n        return table[0][u];\n    }\n    \n    // \u547C\u3073\u51FA\
    \u3059\u305F\u3073O(logn)\n    int dis(int u,int v){\n        int p=query(u,v);\n\
    \        return dep[u]+dep[v]-2*dep[p];\n    }\n \n    // \u6DF1\u3055\u3092\u8FD4\
    \u3059\n    int operator[](const int &k) const{\n        return dep[k];\n    }\n\
    \ \n    //\u9802\u70B9x\u306Ek\u500B\u4E0A\u306E\u89AA\u3092\u6C42\u3081\u308B\
    \u3002\u7121\u3051\u308C\u3070-1\n    int parent(int x,int k){\n        int ret=x;\n\
    \        for(int i=LOG-1;i>=0 and ret>=0;i--){\n            if((k>>i)&1) ret=table[i][ret];\n\
    \        }\n        return ret;\n    }\n};"
  dependsOn:
  - Graph2/GraphTemplate.hpp
  isVerificationFile: false
  path: Graph2/DoublingLowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2023-07-17 18:02:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph2/DoublingLowestCommonAncestor.hpp
layout: document
redirect_from:
- /library/Graph2/DoublingLowestCommonAncestor.hpp
- /library/Graph2/DoublingLowestCommonAncestor.hpp.html
title: Graph2/DoublingLowestCommonAncestor.hpp
---

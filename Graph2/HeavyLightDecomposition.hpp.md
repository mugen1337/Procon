---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph2/GraphTemplate.hpp
    title: Graph2/GraphTemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki1249.test.cpp
    title: test/yuki1249.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.github.io/library/graph/tree/heavy-light-decomposition.hpp
    - https://ferin-tech.hatenablog.com/entry/2019/11/21/HL%E5%88%86%E8%A7%A3%E3%81%AE%E5%AE%9F%E8%A3%85
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n#line 2 \"Graph2/HeavyLightDecomposition.hpp\"\
    \n/*\nref : https://ferin-tech.hatenablog.com/entry/2019/11/21/HL%E5%88%86%E8%A7%A3%E3%81%AE%E5%AE%9F%E8%A3%85\n\
    \      https://ei1333.github.io/library/graph/tree/heavy-light-decomposition.hpp\n\
    \nHLD \n    \u5404\u9802\u70B9\u304B\u3089\u9802\u70B9\u3092\u6271\u3044\u3084\
    \u3059\u3044\u3088\u3046\u306B\u4E26\u3073\u66FF\u3048\u305F\u6642\u306E\u756A\
    \u53F7\u3078\u306E\u5199\u50CF\u3092\u8003\u3048\u308B\n    ! \u8FBA\u5C5E\u6027\
    \u3067\u8003\u3048\u305F\u3044\u5834\u5408\n        \u9802\u70B9i\u304B\u3089\u89AA\
    \u65B9\u5411\u306B\u4F38\u3073\u3066\u3044\u308B\u8FBA\u3092pos[i]\u306BSegment\u6728\
    \u306A\u3069\u306B\u30BB\u30C3\u30C8\u3057\uFF0C\u5404\u30E1\u30BD\u30C3\u30C9\
    \u3092edge=true\u3067\u6271\u3046\n\n    member\n        head[i] : i\u306E\u5148\
    \u982D\n        in[i], out[i] : i\u9802\u70B9\u4EE5\u4E0B\u306E\u90E8\u5206\u6728\
    \u306Ein, out\n\n    method\n        lca(u, v) : least common ancestor\n     \
    \   dist(u, v) : \u8DDD\u96E2\n        get_path(u, v) : \u533A\u9593\u306Evector\u3092\
    \u8FD4\u3059\u306E\u3067\u5404\u533A\u9593\u3067\u30AF\u30A8\u30EA\u3092\u51E6\
    \u7406\u3057\uFF0Cmerge\u3059\u308C\u3070\u3088\u3044\n        get_subtree(u)\
    \ : \u90E8\u5206\u6728\u306B\u3042\u305F\u308B\u533A\u9593\u3092\u8FD4\u3059\n\
    \        pos(u) : \u4E26\u3073\u66FF\u3048\u3092\u3057\u305F\u5F8C\uFF0C\u9802\
    \u70B9u\u304C\u3069\u306E\u5834\u6240\u3078\u79FB\u308B\u304B\u306E\u5C04\u5F71\
    \n*/\ntemplate<typename T>\nstruct HeavyLightDecomposition{\nprivate:\n    void\
    \ dfs1(int pre,int cur){\n        par[cur]=pre;\n        sz[cur]=1;\n        if(!g[cur].empty()\
    \ and g[cur][0]==pre) swap(g[cur][0],g[cur].back());\n        for(auto &e:g[cur])if(e!=pre){\n\
    \            dis[e]+=dis[cur]+e.w;\n            dfs1(cur,e);\n            sz[cur]+=sz[e];\n\
    \            if(sz[g[cur][0]]<sz[e]) swap(g[cur][0],e);\n        }\n    }\n  \
    \  void dfs2(int pre,int cur,int &t){\n        in[cur]=t++;\n        rev[in[cur]]=cur;\n\
    \        for(auto &e:g[cur])if(e!=pre){\n            head[e]=(g[cur][0]==e?head[cur]:e);\n\
    \            dfs2(cur,e,t);\n        }\n        out[cur]=t;\n    }\n\n\npublic:\n\
    \    Graph<T> g;\n    vector<int> sz,in,out,head,rev,par;\n    vector<T> dis;\n\
    \n    HeavyLightDecomposition(Graph<T> g,int root=0):\n    g(g),sz(g.V,0),in(g.V,0),out(g.V,0),head(g.V,0),rev(g.V,0),par(g.V,0),dis(g.V,0){\n\
    \        dfs1(-1,root);\n        int t=0;\n        dfs2(-1,root,t);\n    }\n \
    \   int la(int v,int k){\n        for(;;){\n            int u=head[v];\n     \
    \       if(in[v]-k>=in[u]) return rev[in[v]-k];\n            k-=in[v]-in[u]+1;\n\
    \            v=par[u];\n        }\n    }\n    int lca(int u,int v){\n        for(;;v=par[head[v]]){\n\
    \            // \u6DF1\u3044\u65B9\u304B\u3089\u4E0A\u3052\u3066\u3044\u304F\n\
    \            if(in[u]>in[v]) swap(u,v);\n            if(head[u]==head[v]) return\
    \ u;\n        }\n    }\n    T dist(int u,int v){ return dis[u]+dis[v]-dis[lca(u,v)]*2;\
    \ }\n\n    // return ranges\n    vector<pair<int,int>> get_path(int u,int v,bool\
    \ edge=false){\n        vector<pair<int,int>> ret;\n        for(;;v=par[head[v]]){\n\
    \            if(in[u]>in[v]) swap(u,v);\n            if(head[u]==head[v]) break;\n\
    \            ret.emplace_back(in[head[v]],in[v]+1);\n        }\n        // \u6700\
    \u5F8C\u306E\u533A\u9593\u306E\u59CB\u70B9\u304CLCA\n        ret.emplace_back(in[u]+edge,in[v]+1);\n\
    \        return ret;\n    }\n    // return one range\n    pair<int,int> get_subtree(int\
    \ u,bool edge=false){\n        return {in[u]+edge,out[u]};\n    }\n    int pos(int\
    \ u){\n        return in[u];\n    }\n};\n"
  code: "#include \"./GraphTemplate.hpp\"\n/*\nref : https://ferin-tech.hatenablog.com/entry/2019/11/21/HL%E5%88%86%E8%A7%A3%E3%81%AE%E5%AE%9F%E8%A3%85\n\
    \      https://ei1333.github.io/library/graph/tree/heavy-light-decomposition.hpp\n\
    \nHLD \n    \u5404\u9802\u70B9\u304B\u3089\u9802\u70B9\u3092\u6271\u3044\u3084\
    \u3059\u3044\u3088\u3046\u306B\u4E26\u3073\u66FF\u3048\u305F\u6642\u306E\u756A\
    \u53F7\u3078\u306E\u5199\u50CF\u3092\u8003\u3048\u308B\n    ! \u8FBA\u5C5E\u6027\
    \u3067\u8003\u3048\u305F\u3044\u5834\u5408\n        \u9802\u70B9i\u304B\u3089\u89AA\
    \u65B9\u5411\u306B\u4F38\u3073\u3066\u3044\u308B\u8FBA\u3092pos[i]\u306BSegment\u6728\
    \u306A\u3069\u306B\u30BB\u30C3\u30C8\u3057\uFF0C\u5404\u30E1\u30BD\u30C3\u30C9\
    \u3092edge=true\u3067\u6271\u3046\n\n    member\n        head[i] : i\u306E\u5148\
    \u982D\n        in[i], out[i] : i\u9802\u70B9\u4EE5\u4E0B\u306E\u90E8\u5206\u6728\
    \u306Ein, out\n\n    method\n        lca(u, v) : least common ancestor\n     \
    \   dist(u, v) : \u8DDD\u96E2\n        get_path(u, v) : \u533A\u9593\u306Evector\u3092\
    \u8FD4\u3059\u306E\u3067\u5404\u533A\u9593\u3067\u30AF\u30A8\u30EA\u3092\u51E6\
    \u7406\u3057\uFF0Cmerge\u3059\u308C\u3070\u3088\u3044\n        get_subtree(u)\
    \ : \u90E8\u5206\u6728\u306B\u3042\u305F\u308B\u533A\u9593\u3092\u8FD4\u3059\n\
    \        pos(u) : \u4E26\u3073\u66FF\u3048\u3092\u3057\u305F\u5F8C\uFF0C\u9802\
    \u70B9u\u304C\u3069\u306E\u5834\u6240\u3078\u79FB\u308B\u304B\u306E\u5C04\u5F71\
    \n*/\ntemplate<typename T>\nstruct HeavyLightDecomposition{\nprivate:\n    void\
    \ dfs1(int pre,int cur){\n        par[cur]=pre;\n        sz[cur]=1;\n        if(!g[cur].empty()\
    \ and g[cur][0]==pre) swap(g[cur][0],g[cur].back());\n        for(auto &e:g[cur])if(e!=pre){\n\
    \            dis[e]+=dis[cur]+e.w;\n            dfs1(cur,e);\n            sz[cur]+=sz[e];\n\
    \            if(sz[g[cur][0]]<sz[e]) swap(g[cur][0],e);\n        }\n    }\n  \
    \  void dfs2(int pre,int cur,int &t){\n        in[cur]=t++;\n        rev[in[cur]]=cur;\n\
    \        for(auto &e:g[cur])if(e!=pre){\n            head[e]=(g[cur][0]==e?head[cur]:e);\n\
    \            dfs2(cur,e,t);\n        }\n        out[cur]=t;\n    }\n\n\npublic:\n\
    \    Graph<T> g;\n    vector<int> sz,in,out,head,rev,par;\n    vector<T> dis;\n\
    \n    HeavyLightDecomposition(Graph<T> g,int root=0):\n    g(g),sz(g.V,0),in(g.V,0),out(g.V,0),head(g.V,0),rev(g.V,0),par(g.V,0),dis(g.V,0){\n\
    \        dfs1(-1,root);\n        int t=0;\n        dfs2(-1,root,t);\n    }\n \
    \   int la(int v,int k){\n        for(;;){\n            int u=head[v];\n     \
    \       if(in[v]-k>=in[u]) return rev[in[v]-k];\n            k-=in[v]-in[u]+1;\n\
    \            v=par[u];\n        }\n    }\n    int lca(int u,int v){\n        for(;;v=par[head[v]]){\n\
    \            // \u6DF1\u3044\u65B9\u304B\u3089\u4E0A\u3052\u3066\u3044\u304F\n\
    \            if(in[u]>in[v]) swap(u,v);\n            if(head[u]==head[v]) return\
    \ u;\n        }\n    }\n    T dist(int u,int v){ return dis[u]+dis[v]-dis[lca(u,v)]*2;\
    \ }\n\n    // return ranges\n    vector<pair<int,int>> get_path(int u,int v,bool\
    \ edge=false){\n        vector<pair<int,int>> ret;\n        for(;;v=par[head[v]]){\n\
    \            if(in[u]>in[v]) swap(u,v);\n            if(head[u]==head[v]) break;\n\
    \            ret.emplace_back(in[head[v]],in[v]+1);\n        }\n        // \u6700\
    \u5F8C\u306E\u533A\u9593\u306E\u59CB\u70B9\u304CLCA\n        ret.emplace_back(in[u]+edge,in[v]+1);\n\
    \        return ret;\n    }\n    // return one range\n    pair<int,int> get_subtree(int\
    \ u,bool edge=false){\n        return {in[u]+edge,out[u]};\n    }\n    int pos(int\
    \ u){\n        return in[u];\n    }\n};\n"
  dependsOn:
  - Graph2/GraphTemplate.hpp
  isVerificationFile: false
  path: Graph2/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki1249.test.cpp
documentation_of: Graph2/HeavyLightDecomposition.hpp
layout: document
title: "Heavy Light Decomposition (HL\u5206\u89E3)"
---

# 概要  
HLD

# 仕様  
コードに書いてある  
G[i][0] : iから子へと伸びるHeavy Edge  
となるように並び替えているので， HLD構築時に渡したgとhld.gは構築後に異なる


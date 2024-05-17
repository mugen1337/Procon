---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph2/GraphTemplate.hpp
    title: Graph2/GraphTemplate.hpp
  - icon: ':heavy_check_mark:'
    path: UnionFind/UnionFind.hpp
    title: UnionFind/UnionFind.hpp
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n\n\n#line 1\
    \ \"UnionFind/UnionFind.hpp\"\nstruct UnionFind{\n    private:\n    vector<int>\
    \ par,siz;\n\n    public:\n    int con;\n    UnionFind(int n):par(n),siz(n,1),con(n){\n\
    \        iota(begin(par),end(par),0);\n    }\n    int root(int x){\n        return\
    \ (par[x]==x?x:(par[x]=root(par[x])));\n    }\n    bool sameroot(int x,int y){\n\
    \        return root(x)==root(y);\n    }\n    bool unite(int x,int y){\n     \
    \   x=root(x);y=root(y);\n        if(x==y) return false;\n        if(siz[x]<siz[y])swap(x,y);\n\
    \        siz[x]+=siz[y];\n        par[y]=x;\n        con--;\n        return true;\n\
    \    }\n    int size(int x){\n        return siz[root(x)];\n    }\n};\n#line 3\
    \ \"Graph2/GraphRelabel.hpp\"\n\ntemplate<typename T>\nvector<Graph<T>> GraphRelabel(Graph<T>\
    \ G){\n    UnionFind uf(G.V);\n    for(int i=0;i<G.V;i++)for(auto &e:G[i]) uf.unite(e.from,e.to);\n\
    \    \n    vector<vector<int>> vertice(G.V);\n    for(int i=0;i<G.V;i++) vertice[uf.root(i)].push_back(i);\n\
    \n    vector<Graph<T>> ret;\n    for(auto &w:vertice){\n        if(w.empty())\
    \ continue;\n        Graph<T> subG(w.size());\n        for(int &x:w){\n      \
    \      int u=lower_bound(begin(w),end(w),x)-begin(w);\n            for(auto &e:G[x]){\n\
    \                int v=lower_bound(begin(w),end(w),e.to)-begin(w);\n         \
    \       subG.add_directed_edge(u,v,e.w);\n            }\n        }\n        ret.push_back(subG);\n\
    \    }\n    return ret;\n}\n"
  code: "#include \"./GraphTemplate.hpp\"\n#include \"../UnionFind/UnionFind.hpp\"\
    \n\ntemplate<typename T>\nvector<Graph<T>> GraphRelabel(Graph<T> G){\n    UnionFind\
    \ uf(G.V);\n    for(int i=0;i<G.V;i++)for(auto &e:G[i]) uf.unite(e.from,e.to);\n\
    \    \n    vector<vector<int>> vertice(G.V);\n    for(int i=0;i<G.V;i++) vertice[uf.root(i)].push_back(i);\n\
    \n    vector<Graph<T>> ret;\n    for(auto &w:vertice){\n        if(w.empty())\
    \ continue;\n        Graph<T> subG(w.size());\n        for(int &x:w){\n      \
    \      int u=lower_bound(begin(w),end(w),x)-begin(w);\n            for(auto &e:G[x]){\n\
    \                int v=lower_bound(begin(w),end(w),e.to)-begin(w);\n         \
    \       subG.add_directed_edge(u,v,e.w);\n            }\n        }\n        ret.push_back(subG);\n\
    \    }\n    return ret;\n}"
  dependsOn:
  - Graph2/GraphTemplate.hpp
  - UnionFind/UnionFind.hpp
  isVerificationFile: false
  path: Graph2/GraphRelabel.hpp
  requiredBy: []
  timestamp: '2023-07-17 18:02:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph2/GraphRelabel.hpp
layout: document
redirect_from:
- /library/Graph2/GraphRelabel.hpp
- /library/Graph2/GraphRelabel.hpp.html
title: Graph2/GraphRelabel.hpp
---

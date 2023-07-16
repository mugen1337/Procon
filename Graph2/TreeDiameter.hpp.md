---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph2/GraphTemplate.hpp
    title: Graph2/GraphTemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_TreeDiameter.test.cpp
    title: test/yosupo_TreeDiameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n#line 2 \"Graph2/TreeDiameter.hpp\"\
    \n\ntemplate<typename T>\npair<T,vector<int>> TreeDiameter(const Graph<T> &g){\n\
    \    assert(g.V==g.E+1);\n    vector<T> dis(g.V);\n    vector<int> pre(g.V,-1);\n\
    \    dis[0]=0;\n    function<void(int,int)> dfs=[&g,&dfs,&dis,&pre](int par,int\
    \ cur){\n        for(auto &e:g[cur])if(par!=e.to){\n            dis[e.to]=dis[cur]+e.w;\n\
    \            pre[e.to]=cur;\n            dfs(cur,e.to);\n        }\n    };\n \
    \   dfs(-1,0);\n    int l=max_element(ALL(dis))-begin(dis);\n    dis[l]=0;\n \
    \   pre.assign(g.V,-1);\n    dfs(-1,l);\n    int r=max_element(ALL(dis))-begin(dis);\n\
    \    vector<int> path;\n    for(int i=r;i!=-1;i=pre[i]) path.push_back(i);\n \
    \   return make_pair(dis[r],path);\n}\n"
  code: "#include \"./GraphTemplate.hpp\"\n\ntemplate<typename T>\npair<T,vector<int>>\
    \ TreeDiameter(const Graph<T> &g){\n    assert(g.V==g.E+1);\n    vector<T> dis(g.V);\n\
    \    vector<int> pre(g.V,-1);\n    dis[0]=0;\n    function<void(int,int)> dfs=[&g,&dfs,&dis,&pre](int\
    \ par,int cur){\n        for(auto &e:g[cur])if(par!=e.to){\n            dis[e.to]=dis[cur]+e.w;\n\
    \            pre[e.to]=cur;\n            dfs(cur,e.to);\n        }\n    };\n \
    \   dfs(-1,0);\n    int l=max_element(ALL(dis))-begin(dis);\n    dis[l]=0;\n \
    \   pre.assign(g.V,-1);\n    dfs(-1,l);\n    int r=max_element(ALL(dis))-begin(dis);\n\
    \    vector<int> path;\n    for(int i=r;i!=-1;i=pre[i]) path.push_back(i);\n \
    \   return make_pair(dis[r],path);\n}"
  dependsOn:
  - Graph2/GraphTemplate.hpp
  isVerificationFile: false
  path: Graph2/TreeDiameter.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_TreeDiameter.test.cpp
documentation_of: Graph2/TreeDiameter.hpp
layout: document
redirect_from:
- /library/Graph2/TreeDiameter.hpp
- /library/Graph2/TreeDiameter.hpp.html
title: Graph2/TreeDiameter.hpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph2/GraphTemplate.hpp
    title: Graph2/GraphTemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_CycleDetection2.test.cpp
    title: test/yosupo_CycleDetection2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n#line 2 \"Graph2/CycleDetection.hpp\"\
    \n\ntemplate<typename T>\nvector<int> CycleDetection(Graph<T> &g){\n    int n=(int)g.size();\n\
    \    vector<int> check(n,0),cyc,pre(n,-1);\n\n    function<bool(int)> dfs=[&](int\
    \ cur){\n        check[cur]=1;\n        for(auto &to:g[cur]){\n            if(check[to]==0){\n\
    \                pre[to]=cur;\n                if(dfs(to)) return true;\n    \
    \        }else if(check[to]==1){// detect\n                int v=cur;\n      \
    \          while(v!=to){\n                    cyc.push_back(v);\n            \
    \        v=pre[v];\n                }\n                cyc.push_back(v);\n   \
    \             return true;\n            }\n        }\n        check[cur]=2;\n\
    \        return false;\n    };\n\n    for(int i=0;i<n;i++){\n        if(check[i]==0){\n\
    \            if(dfs(i)){\n                reverse(begin(cyc),end(cyc));\n    \
    \            return cyc;\n            }\n        }\n    }\n    return {};\n}\n"
  code: "#include \"./GraphTemplate.hpp\"\n\ntemplate<typename T>\nvector<int> CycleDetection(Graph<T>\
    \ &g){\n    int n=(int)g.size();\n    vector<int> check(n,0),cyc,pre(n,-1);\n\n\
    \    function<bool(int)> dfs=[&](int cur){\n        check[cur]=1;\n        for(auto\
    \ &to:g[cur]){\n            if(check[to]==0){\n                pre[to]=cur;\n\
    \                if(dfs(to)) return true;\n            }else if(check[to]==1){//\
    \ detect\n                int v=cur;\n                while(v!=to){\n        \
    \            cyc.push_back(v);\n                    v=pre[v];\n              \
    \  }\n                cyc.push_back(v);\n                return true;\n      \
    \      }\n        }\n        check[cur]=2;\n        return false;\n    };\n\n\
    \    for(int i=0;i<n;i++){\n        if(check[i]==0){\n            if(dfs(i)){\n\
    \                reverse(begin(cyc),end(cyc));\n                return cyc;\n\
    \            }\n        }\n    }\n    return {};\n}"
  dependsOn:
  - Graph2/GraphTemplate.hpp
  isVerificationFile: false
  path: Graph2/CycleDetection.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_CycleDetection2.test.cpp
documentation_of: Graph2/CycleDetection.hpp
layout: document
redirect_from:
- /library/Graph2/CycleDetection.hpp
- /library/Graph2/CycleDetection.hpp.html
title: Graph2/CycleDetection.hpp
---

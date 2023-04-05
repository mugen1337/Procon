---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph2/GraphTemplate.hpp
    title: Graph2/GraphTemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yuki4227.test.cpp
    title: test/yuki4227.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://ei1333.github.io/library/graph/shortest-path/k-shortest-path.hpp
    - https://qiita.com/nariaki3551/items/821dc6ffdc552d3d5f22
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n#line 2 \"Graph2/Yen.hpp\"\
    \n\n// \u6709\u5411\u30B0\u30E9\u30D5\u5411\u3051\n// \u7121\u5411\u30B0\u30E9\
    \u30D5\u3067\u3084\u308A\u305F\u3044\u306A\u3089\u8FBA\u306Eidx\u304C\u72EC\u7ACB\
    \u306B\u306A\u308B\u3088\u3046\u306B\u632F\u308A\u306A\u304A\u3059\n// O(KN *\
    \ (N+M)logN)\u306E\u306F\u305A\u3060\u3051\u3069\u3069\u3053\u304B\u60AA\u5316\
    \u3057\u3066\u308B\u304B\u3082\n// vector ( pair(cost, path\u306E\u8FBA\u756A\u53F7\
    \u306E\u30EA\u30B9\u30C8) ), k\u500B\u306A\u3044\u6642\u306B\u6CE8\u610F\n/*\n\
    ref: https://qiita.com/nariaki3551/items/821dc6ffdc552d3d5f22\n     https://ei1333.github.io/library/graph/shortest-path/k-shortest-path.hpp\n\
    */\ntemplate<typename T>\nvector<pair<T,vector<int>>> Yen(Graph<T> g,int s,int\
    \ t,int k){\n    T inf=numeric_limits<T>::max();\n\n    vector<Edge<T>> edge(g.E);\n\
    \    for(int i=0;i<g.V;i++)for(auto &e:g[i]) edge[e.idx]=e;\n\n    unordered_set<int>\
    \ removed_edge;\n    using P=pair<T,int>;\n    auto dijkstra=[&](vector<T> &d,vector<int>\
    \ &from_v,vector<int> &from_e,int st){\n        priority_queue<P,vector<P>,greater<P>>\
    \ que;\n        que.emplace(d[st],st);\n        while(!que.empty()){\n       \
    \     auto p=que.top();que.pop();\n            int cur=p.second;\n           \
    \ if(d[cur]<p.first) continue;\n            for(auto &e:g[cur])if(!removed_edge.count(e.idx)){\n\
    \                if(chmin(d[e.to],d[cur]+e.w)){\n                    from_v[e.to]=cur;\n\
    \                    from_e[e.to]=e.idx;\n                    que.emplace(d[e.to],e.to);\n\
    \                }\n            }\n        }\n    };\n\n    // (s, t)\u3078\u306E\
    \u30D1\u30B9\u306E\u8FBA\u756A\u53F7\u306Evector\n    auto get_path=[&](vector<int>\
    \ &from_v,vector<int> &from_e,int st,int gl){\n        vector<int> e_idx;\n  \
    \      for(;gl!=st;gl=from_v[gl]) e_idx.push_back(from_e[gl]);\n        reverse(begin(e_idx),end(e_idx));\n\
    \        return e_idx;\n    };\n\n    vector<pair<T,vector<int>>> A;\n    set<pair<T,vector<int>>>\
    \ B;\n\n    vector<T> d;\n    vector<int> from_v,from_e;\n    d.assign(g.V,inf);\n\
    \    d[s]=0;\n    from_v.assign(g.V,-1);\n    from_e.assign(g.V,-1);\n    dijkstra(d,from_v,from_e,s);\n\
    \n    if(d[t]==inf) return A;\n\n    A.emplace_back(d[t],get_path(from_v,from_e,s,t));\n\
    \n    for(int i=1;i<k;i++){\n        vector<int> &last_path=A.back().second;\n\
    \        d.assign(g.V,inf);\n        d[s]=0;\n        from_v.assign(g.V,-1);\n\
    \        from_e.assign(g.V,-1);\n\n        vector<int> same_path(i); // last path\u306B\
    \u6CBF\u3063\u305F\u9053\u306E\u30EA\u30B9\u30C8\n        iota(begin(same_path),end(same_path),0);\n\
    \n        // O(N)\n        for(int j=0;j<(int)last_path.size();j++){\n       \
    \     int spur=edge[last_path[j]].from;// spur node\n\n            unordered_set<int>\
    \ removed_edge_new;\n            for(auto &l:same_path)if(j<(int)A[l].second.size())\
    \ removed_edge_new.insert(A[l].second[j]);\n            swap(removed_edge,removed_edge_new);\n\
    \            \n            // spur node\u304B\u3089\u5148\u3092dijkstra\u3059\u308B\
    \n            vector<T> d_t{d};\n            vector<int> from_v_t{from_v},from_e_t{from_e};\n\
    \n            dijkstra(d_t,from_v_t,from_e_t,spur);\n            if(d_t[t]<inf)\
    \ B.emplace(d_t[t],get_path(from_v_t,from_e_t,s,t));\n\n            // last path\u306B\
    \u6CBF\u3063\u30661\u3064\u9032\u3081\u308B\n            auto &spur_root=edge[last_path[j]];\n\
    \            d[spur_root.to]=d[spur_root.from]+spur_root.w;\n            from_e[spur_root.to]=spur_root.idx;\n\
    \            from_v[spur_root.to]=spur_root.from;\n\n            vector<int> tmp;\n\
    \            for(auto l:same_path)if(j<(int)A[l].second.size() and A[l].second[j]==last_path[j])\n\
    \                tmp.push_back(l);\n            swap(tmp,same_path);\n       \
    \ }\n        if(B.empty()) return A;\n\n        A.push_back(*begin(B));\n    \
    \    B.erase(begin(B));\n    }\n    return A;\n}\n"
  code: "#include \"./GraphTemplate.hpp\"\n\n// \u6709\u5411\u30B0\u30E9\u30D5\u5411\
    \u3051\n// \u7121\u5411\u30B0\u30E9\u30D5\u3067\u3084\u308A\u305F\u3044\u306A\u3089\
    \u8FBA\u306Eidx\u304C\u72EC\u7ACB\u306B\u306A\u308B\u3088\u3046\u306B\u632F\u308A\
    \u306A\u304A\u3059\n// O(KN * (N+M)logN)\u306E\u306F\u305A\u3060\u3051\u3069\u3069\
    \u3053\u304B\u60AA\u5316\u3057\u3066\u308B\u304B\u3082\n// vector ( pair(cost,\
    \ path\u306E\u8FBA\u756A\u53F7\u306E\u30EA\u30B9\u30C8) ), k\u500B\u306A\u3044\
    \u6642\u306B\u6CE8\u610F\n/*\nref: https://qiita.com/nariaki3551/items/821dc6ffdc552d3d5f22\n\
    \     https://ei1333.github.io/library/graph/shortest-path/k-shortest-path.hpp\n\
    */\ntemplate<typename T>\nvector<pair<T,vector<int>>> Yen(Graph<T> g,int s,int\
    \ t,int k){\n    T inf=numeric_limits<T>::max();\n\n    vector<Edge<T>> edge(g.E);\n\
    \    for(int i=0;i<g.V;i++)for(auto &e:g[i]) edge[e.idx]=e;\n\n    unordered_set<int>\
    \ removed_edge;\n    using P=pair<T,int>;\n    auto dijkstra=[&](vector<T> &d,vector<int>\
    \ &from_v,vector<int> &from_e,int st){\n        priority_queue<P,vector<P>,greater<P>>\
    \ que;\n        que.emplace(d[st],st);\n        while(!que.empty()){\n       \
    \     auto p=que.top();que.pop();\n            int cur=p.second;\n           \
    \ if(d[cur]<p.first) continue;\n            for(auto &e:g[cur])if(!removed_edge.count(e.idx)){\n\
    \                if(chmin(d[e.to],d[cur]+e.w)){\n                    from_v[e.to]=cur;\n\
    \                    from_e[e.to]=e.idx;\n                    que.emplace(d[e.to],e.to);\n\
    \                }\n            }\n        }\n    };\n\n    // (s, t)\u3078\u306E\
    \u30D1\u30B9\u306E\u8FBA\u756A\u53F7\u306Evector\n    auto get_path=[&](vector<int>\
    \ &from_v,vector<int> &from_e,int st,int gl){\n        vector<int> e_idx;\n  \
    \      for(;gl!=st;gl=from_v[gl]) e_idx.push_back(from_e[gl]);\n        reverse(begin(e_idx),end(e_idx));\n\
    \        return e_idx;\n    };\n\n    vector<pair<T,vector<int>>> A;\n    set<pair<T,vector<int>>>\
    \ B;\n\n    vector<T> d;\n    vector<int> from_v,from_e;\n    d.assign(g.V,inf);\n\
    \    d[s]=0;\n    from_v.assign(g.V,-1);\n    from_e.assign(g.V,-1);\n    dijkstra(d,from_v,from_e,s);\n\
    \n    if(d[t]==inf) return A;\n\n    A.emplace_back(d[t],get_path(from_v,from_e,s,t));\n\
    \n    for(int i=1;i<k;i++){\n        vector<int> &last_path=A.back().second;\n\
    \        d.assign(g.V,inf);\n        d[s]=0;\n        from_v.assign(g.V,-1);\n\
    \        from_e.assign(g.V,-1);\n\n        vector<int> same_path(i); // last path\u306B\
    \u6CBF\u3063\u305F\u9053\u306E\u30EA\u30B9\u30C8\n        iota(begin(same_path),end(same_path),0);\n\
    \n        // O(N)\n        for(int j=0;j<(int)last_path.size();j++){\n       \
    \     int spur=edge[last_path[j]].from;// spur node\n\n            unordered_set<int>\
    \ removed_edge_new;\n            for(auto &l:same_path)if(j<(int)A[l].second.size())\
    \ removed_edge_new.insert(A[l].second[j]);\n            swap(removed_edge,removed_edge_new);\n\
    \            \n            // spur node\u304B\u3089\u5148\u3092dijkstra\u3059\u308B\
    \n            vector<T> d_t{d};\n            vector<int> from_v_t{from_v},from_e_t{from_e};\n\
    \n            dijkstra(d_t,from_v_t,from_e_t,spur);\n            if(d_t[t]<inf)\
    \ B.emplace(d_t[t],get_path(from_v_t,from_e_t,s,t));\n\n            // last path\u306B\
    \u6CBF\u3063\u30661\u3064\u9032\u3081\u308B\n            auto &spur_root=edge[last_path[j]];\n\
    \            d[spur_root.to]=d[spur_root.from]+spur_root.w;\n            from_e[spur_root.to]=spur_root.idx;\n\
    \            from_v[spur_root.to]=spur_root.from;\n\n            vector<int> tmp;\n\
    \            for(auto l:same_path)if(j<(int)A[l].second.size() and A[l].second[j]==last_path[j])\n\
    \                tmp.push_back(l);\n            swap(tmp,same_path);\n       \
    \ }\n        if(B.empty()) return A;\n\n        A.push_back(*begin(B));\n    \
    \    B.erase(begin(B));\n    }\n    return A;\n}"
  dependsOn:
  - Graph2/GraphTemplate.hpp
  isVerificationFile: false
  path: Graph2/Yen.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yuki4227.test.cpp
documentation_of: Graph2/Yen.hpp
layout: document
title: Yen's Algorithm (K-Shortest-Path)
---

## 概要  

Dijkstraをする．  
最短路の途中からそれるのが次の最短路の候補  

A : 返り値  
B : (最短路, path)  
Bから1個最短路を取り出す．Bのパスを進みながら，ある頂点で道をそれることを考える．  
その時，次の辺のうち使えるのは今までの最短路で通ったようなパス以外のパス．
removed_edge : 使えない辺  
それをコイツに入れる．  

## 仕様  
有向グラフのみに使える．  
無向グラフで使いたいなら辺番号を振りなおすこと．  

返り値は(コスト, パスを表す辺番号のリスト)のvector  

## 計算量  
Yen's AlgorithmはO(KV * (最短路の計算量))  
実装はO(KV (V+E) log(V))かO(K^2 V (V+E) log(V))だと思うけどちょっと自信ない．  

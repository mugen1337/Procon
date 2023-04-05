---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph2/GraphTemplate.hpp
    title: Graph2/GraphTemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_KSW.test.cpp
    title: test/yosupo_KSW.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://qiita.com/hotman78/items/42534a01c4bd05ed5e1e
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n#line 2 \"Graph2/Eppstein.hpp\"\
    \n\ntemplate<typename T>\nstruct PersistentLeftistHeapNode{\n    PersistentLeftistHeapNode\
    \ *l,*r;\n    int s;\n    T val;\n    PersistentLeftistHeapNode(T val):l(nullptr),r(nullptr),s(1),val(val){}\n\
    };\n\ntemplate<typename T,bool less=true>\nstruct PersistentLeftistHeap{\n   \
    \ PersistentLeftistHeapNode<T> *root;\n    PersistentLeftistHeap(PersistentLeftistHeapNode<T>\
    \ *t=nullptr):root(t){}\n\n    PersistentLeftistHeapNode<T> *meld(PersistentLeftistHeapNode<T>\
    \ *a,PersistentLeftistHeapNode<T> *b){\n        if(!a or !b) return (a?a:b);\n\
    \        if((a->val>b->val)^(!less)) swap(a,b);\n        a=new PersistentLeftistHeapNode(*a);\n\
    \        a->r=meld(a->r,b);\n        if(!a->l or a->l->s<a->r->s) swap(a->l,a->r);\n\
    \        a->s=(a->r?a->r->s:0)+1;\n        return a;\n    }\n    PersistentLeftistHeap\
    \ meld(PersistentLeftistHeap b){\n        return PersistentLeftistHeap(meld(root,b.root));\n\
    \    }\n    PersistentLeftistHeap push(T x){\n        return PersistentLeftistHeap(meld(root,new\
    \ PersistentLeftistHeapNode(x)));\n    }\n    PersistentLeftistHeap pop(){\n \
    \       assert(root!=nullptr);\n        return PersistentLeftistHeap(meld(root->l,root->r));\n\
    \    }\n    bool empty(){\n        return (root==nullptr);\n    }\n    T top(){\n\
    \        assert(root!=nullptr);\n        return root->val;\n    }\n};\n\n// ref:\
    \ https://qiita.com/hotman78/items/42534a01c4bd05ed5e1e\n// K Shortest Walk\n\
    template<typename T>\nvector<T> Eppstein(Graph<T> &G,int s,int t,int k){\n   \
    \ int N=G.V,M=G.E;\n    T inf=numeric_limits<T>::max();\n\n    Graph<T> rG(N);\n\
    \    vector<Edge<T>> edges(M);\n    for(int i=0;i<N;i++)for(auto &e:G[i]) edges[e.idx]=e;\n\
    \    for(auto &e:edges) rG.add_directed_edge(e.to,e.from,e.w);\n\n    // Dijkstra\
    \ rG, make Tree\n    vector<int> prev_e(N,-1),prev_v(N,-1);\n    vector<T> dis(N,inf);\n\
    \    vector<vector<int>> tree(N);\n    vector<bool> tree_edge(M,false);\n    {\n\
    \        using P=pair<T,int>;\n        priority_queue<P,vector<P>,greater<P>>\
    \ que;\n        dis[t]=0;\n        que.emplace(dis[t],t);\n        while(!que.empty()){\n\
    \            auto [d_cur,cur]=que.top();que.pop();\n            if(dis[cur]<d_cur)\
    \ continue;\n            for(auto &e:rG[cur])if(chmin(dis[e.to],d_cur+e.w)){\n\
    \                prev_e[e.to]=e.idx;\n                prev_v[e.to]=cur;\n    \
    \            que.emplace(dis[e.to],e.to);\n            }\n        }\n\n      \
    \  if(dis[s]>=inf) return {};\n        for(auto &i:prev_e)if(i>=0) tree[edges[i].to].push_back(edges[i].from),tree_edge[i]=true;\n\
    \    }\n\n    // make H_G\n    vector<PersistentLeftistHeap<pair<T,int>>> H_G(N);//\
    \ (potential, edge index)\n    {\n        function<void(int)> dfs=[&](int cur){\n\
    \            if(prev_v[cur]>=0) H_G[cur]=H_G[cur].meld(H_G[prev_v[cur]]);\n  \
    \          for(auto &e:G[cur]){\n                if(e.to!=t and prev_v[e.to]<0)\
    \ continue; // cant reach\n                if(tree_edge[e.idx]) continue;\n  \
    \              H_G[cur]=H_G[cur].push({e.w-dis[cur]+dis[e.to],e.idx});\n     \
    \       }\n            for(auto &to:tree[cur]) dfs(to);\n        };\n        dfs(t);\n\
    \    }\n    \n\n    // return KSP\n    vector<T> ret;\n    {\n        using P_TN=pair<T,PersistentLeftistHeapNode<pair<T,int>>*>;\n\
    \        auto comp=[](const P_TN &x,const P_TN &y){return x.first>y.first;};\n\
    \        priority_queue<P_TN,vector<P_TN>,decltype(comp)> que(comp);\n       \
    \ ret.push_back(dis[s]);\n        if(H_G[s].root) que.emplace(dis[s]+H_G[s].root->val.first,H_G[s].root);\n\
    \        while(!que.empty() and (int)ret.size()<k){\n            auto [cost,cur]=que.top();que.pop();\n\
    \            ret.emplace_back(cost);\n\n            int to=edges[cur->val.second].to;\n\
    \            if(H_G[to].root) que.emplace(cost+H_G[to].root->val.first,H_G[to].root);\n\
    \n            if(cur->l) que.emplace(cost+cur->l->val.first-cur->val.first,cur->l);\n\
    \            if(cur->r) que.emplace(cost+cur->r->val.first-cur->val.first,cur->r);\n\
    \        }\n    }\n    return ret;\n}\n"
  code: "#include \"./GraphTemplate.hpp\"\n\ntemplate<typename T>\nstruct PersistentLeftistHeapNode{\n\
    \    PersistentLeftistHeapNode *l,*r;\n    int s;\n    T val;\n    PersistentLeftistHeapNode(T\
    \ val):l(nullptr),r(nullptr),s(1),val(val){}\n};\n\ntemplate<typename T,bool less=true>\n\
    struct PersistentLeftistHeap{\n    PersistentLeftistHeapNode<T> *root;\n    PersistentLeftistHeap(PersistentLeftistHeapNode<T>\
    \ *t=nullptr):root(t){}\n\n    PersistentLeftistHeapNode<T> *meld(PersistentLeftistHeapNode<T>\
    \ *a,PersistentLeftistHeapNode<T> *b){\n        if(!a or !b) return (a?a:b);\n\
    \        if((a->val>b->val)^(!less)) swap(a,b);\n        a=new PersistentLeftistHeapNode(*a);\n\
    \        a->r=meld(a->r,b);\n        if(!a->l or a->l->s<a->r->s) swap(a->l,a->r);\n\
    \        a->s=(a->r?a->r->s:0)+1;\n        return a;\n    }\n    PersistentLeftistHeap\
    \ meld(PersistentLeftistHeap b){\n        return PersistentLeftistHeap(meld(root,b.root));\n\
    \    }\n    PersistentLeftistHeap push(T x){\n        return PersistentLeftistHeap(meld(root,new\
    \ PersistentLeftistHeapNode(x)));\n    }\n    PersistentLeftistHeap pop(){\n \
    \       assert(root!=nullptr);\n        return PersistentLeftistHeap(meld(root->l,root->r));\n\
    \    }\n    bool empty(){\n        return (root==nullptr);\n    }\n    T top(){\n\
    \        assert(root!=nullptr);\n        return root->val;\n    }\n};\n\n// ref:\
    \ https://qiita.com/hotman78/items/42534a01c4bd05ed5e1e\n// K Shortest Walk\n\
    template<typename T>\nvector<T> Eppstein(Graph<T> &G,int s,int t,int k){\n   \
    \ int N=G.V,M=G.E;\n    T inf=numeric_limits<T>::max();\n\n    Graph<T> rG(N);\n\
    \    vector<Edge<T>> edges(M);\n    for(int i=0;i<N;i++)for(auto &e:G[i]) edges[e.idx]=e;\n\
    \    for(auto &e:edges) rG.add_directed_edge(e.to,e.from,e.w);\n\n    // Dijkstra\
    \ rG, make Tree\n    vector<int> prev_e(N,-1),prev_v(N,-1);\n    vector<T> dis(N,inf);\n\
    \    vector<vector<int>> tree(N);\n    vector<bool> tree_edge(M,false);\n    {\n\
    \        using P=pair<T,int>;\n        priority_queue<P,vector<P>,greater<P>>\
    \ que;\n        dis[t]=0;\n        que.emplace(dis[t],t);\n        while(!que.empty()){\n\
    \            auto [d_cur,cur]=que.top();que.pop();\n            if(dis[cur]<d_cur)\
    \ continue;\n            for(auto &e:rG[cur])if(chmin(dis[e.to],d_cur+e.w)){\n\
    \                prev_e[e.to]=e.idx;\n                prev_v[e.to]=cur;\n    \
    \            que.emplace(dis[e.to],e.to);\n            }\n        }\n\n      \
    \  if(dis[s]>=inf) return {};\n        for(auto &i:prev_e)if(i>=0) tree[edges[i].to].push_back(edges[i].from),tree_edge[i]=true;\n\
    \    }\n\n    // make H_G\n    vector<PersistentLeftistHeap<pair<T,int>>> H_G(N);//\
    \ (potential, edge index)\n    {\n        function<void(int)> dfs=[&](int cur){\n\
    \            if(prev_v[cur]>=0) H_G[cur]=H_G[cur].meld(H_G[prev_v[cur]]);\n  \
    \          for(auto &e:G[cur]){\n                if(e.to!=t and prev_v[e.to]<0)\
    \ continue; // cant reach\n                if(tree_edge[e.idx]) continue;\n  \
    \              H_G[cur]=H_G[cur].push({e.w-dis[cur]+dis[e.to],e.idx});\n     \
    \       }\n            for(auto &to:tree[cur]) dfs(to);\n        };\n        dfs(t);\n\
    \    }\n    \n\n    // return KSP\n    vector<T> ret;\n    {\n        using P_TN=pair<T,PersistentLeftistHeapNode<pair<T,int>>*>;\n\
    \        auto comp=[](const P_TN &x,const P_TN &y){return x.first>y.first;};\n\
    \        priority_queue<P_TN,vector<P_TN>,decltype(comp)> que(comp);\n       \
    \ ret.push_back(dis[s]);\n        if(H_G[s].root) que.emplace(dis[s]+H_G[s].root->val.first,H_G[s].root);\n\
    \        while(!que.empty() and (int)ret.size()<k){\n            auto [cost,cur]=que.top();que.pop();\n\
    \            ret.emplace_back(cost);\n\n            int to=edges[cur->val.second].to;\n\
    \            if(H_G[to].root) que.emplace(cost+H_G[to].root->val.first,H_G[to].root);\n\
    \n            if(cur->l) que.emplace(cost+cur->l->val.first-cur->val.first,cur->l);\n\
    \            if(cur->r) que.emplace(cost+cur->r->val.first-cur->val.first,cur->r);\n\
    \        }\n    }\n    return ret;\n}"
  dependsOn:
  - Graph2/GraphTemplate.hpp
  isVerificationFile: false
  path: Graph2/Eppstein.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_KSW.test.cpp
documentation_of: Graph2/Eppstein.hpp
layout: document
title: Eppstein's Algorithm (K-Shortest-Walk)
---

## 概要  
Eppstein's Algorithmです．  
同じ店を何度通ってもいいようなs-tパスを距離の小さい方からk個列挙します．  

## 仕様  
有向グラフのみに使える．  
無向グラフで使いたいなら辺番号を振りなおすこと．  

## 計算量  
O(M + NlogN + KlogK)  

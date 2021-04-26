---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_2821.test.cpp
    title: test/AOJ_2821.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Tree/TreeHash.cpp\"\n// hash type\nusing ull=unsigned long\
    \ long;\nstruct TreeHasher{\n    using uint128=__uint128_t;\n    static const\
    \ ull Mod=(1ull<<61ull)-1;\n    static inline ull add(ull a,ull b){if((a+=b)>=Mod)a-=Mod;return\
    \ a;}\n    static inline ull mul(ull a,ull b){uint128 c=(uint128)a*b;return add(c>>61,c&Mod);}\n\
    \    vector<ull> R;\n\n\n    // \u6728\u306E\u30B5\u30A4\u30BA\n    TreeHasher(int\
    \ n){\n        R.push_back(1);\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<ull> rand(1,Mod-1);\n        for(int i=1;i<=n;i++)\
    \ R.push_back(rand(mt));\n        // R.resize(n+1);\n        // iota(ALL(R),1);\n\
    \    }\n    inline vector<int> BFS(vector<vector<int>> &g,int st,vector<int> &dis,bool\
    \ memo_parent=false){\n        vector<int> par;\n        if(memo_parent) par.assign(g.size(),-1);\n\
    \        dis.assign(g.size(),-1);\n        dis[st]=0;\n        queue<int> que;\n\
    \        que.push(st);\n        while(!que.empty()){\n            int cur=que.front();que.pop();\n\
    \            for(auto &to:g[cur]){\n                if(dis[to]>=0) continue;\n\
    \                dis[to]=dis[cur]+1;\n                if(memo_parent) par[to]=cur;\n\
    \                que.push(to);\n            }\n        }\n        return par;\n\
    \    }\n\n    // \u6728\u306E\u4E2D\u5FC3(\u76F4\u5F84\u306E\u771F\u3093\u4E2D\
    )\u3092\u8FD4\u3059\n    vector<int> center(vector<vector<int>> &g){\n       \
    \ vector<int> d;\n        BFS(g,0,d);\n        int u=max_element(begin(d),end(d))-begin(d);\n\
    \        \n        auto par=BFS(g,u,d,true);\n        int v=max_element(begin(d),end(d))-begin(d);\n\
    \        int diameter=d[v];\n        for(int i=0;i<diameter/2;i++) v=par[v];\n\
    \        vector<int> ret;\n        ret.push_back(v);\n        if(diameter%2) ret.push_back(par[v]);\n\
    \        return ret;\n    }\n\n    ull RootedTreeHash(vector<vector<int>> &g,int\
    \ root){\n        vector<int> dis(g.size(),-1);\n        vector<ull> h(g.size());\n\
    \        function<void(int,int)> dfs=[&](int par,int cur){\n            int d=-1;\n\
    \            for(auto &to:g[cur])if(par!=to){\n                dfs(cur,to);\n\
    \                chmax(d,dis[to]);\n            }\n            d++;\n        \
    \    dis[cur]=d;\n            ull ret=1;\n            // rng hash\n          \
    \  for(auto &to:g[cur])if(par!=to) ret=mul(ret,add(h[to],R[d]));\n           \
    \ h[cur]=ret;\n        };\n        dfs(-1,root);\n        return h[root];\n  \
    \  }\n    // \u6728\u306E\u4E2D\u5FC3\u304B\u3089hash\u3092\u3068\u308B\uFF0E\u6728\
    \u306E\u4E2D\u5FC3\u306F2\u500B\u3042\u308B\u53EF\u80FD\u6027\u304C\u3042\u308B\
    \n    ull TreeHash(vector<vector<int>> &g){\n        auto centers=center(g);\n\
    \        ull ret=RootedTreeHash(g,centers[0]);\n        if(centers.size()==2)\
    \ ret=min(ret,RootedTreeHash(g,centers[1]));\n        return ret;\n    }\n   \
    \ bool RootedTreeIsomorphic(vector<vector<int>> &g,int g_root,vector<vector<int>>\
    \ &h,int h_root){\n        if(g.size()!=h.size()) return false;\n        return\
    \ (RootedTreeHash(g,g_root)==RootedTreeHash(h,h_root));\n    }\n    bool TreeIsomorphic(vector<vector<int>>\
    \ &g,vector<vector<int>> &h){\n        if(g.size()!=h.size()) return false;\n\
    \        return (TreeHash(g)==TreeHash(h));\n        }\n};\n"
  code: "// hash type\nusing ull=unsigned long long;\nstruct TreeHasher{\n    using\
    \ uint128=__uint128_t;\n    static const ull Mod=(1ull<<61ull)-1;\n    static\
    \ inline ull add(ull a,ull b){if((a+=b)>=Mod)a-=Mod;return a;}\n    static inline\
    \ ull mul(ull a,ull b){uint128 c=(uint128)a*b;return add(c>>61,c&Mod);}\n    vector<ull>\
    \ R;\n\n\n    // \u6728\u306E\u30B5\u30A4\u30BA\n    TreeHasher(int n){\n    \
    \    R.push_back(1);\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<ull> rand(1,Mod-1);\n        for(int i=1;i<=n;i++)\
    \ R.push_back(rand(mt));\n        // R.resize(n+1);\n        // iota(ALL(R),1);\n\
    \    }\n    inline vector<int> BFS(vector<vector<int>> &g,int st,vector<int> &dis,bool\
    \ memo_parent=false){\n        vector<int> par;\n        if(memo_parent) par.assign(g.size(),-1);\n\
    \        dis.assign(g.size(),-1);\n        dis[st]=0;\n        queue<int> que;\n\
    \        que.push(st);\n        while(!que.empty()){\n            int cur=que.front();que.pop();\n\
    \            for(auto &to:g[cur]){\n                if(dis[to]>=0) continue;\n\
    \                dis[to]=dis[cur]+1;\n                if(memo_parent) par[to]=cur;\n\
    \                que.push(to);\n            }\n        }\n        return par;\n\
    \    }\n\n    // \u6728\u306E\u4E2D\u5FC3(\u76F4\u5F84\u306E\u771F\u3093\u4E2D\
    )\u3092\u8FD4\u3059\n    vector<int> center(vector<vector<int>> &g){\n       \
    \ vector<int> d;\n        BFS(g,0,d);\n        int u=max_element(begin(d),end(d))-begin(d);\n\
    \        \n        auto par=BFS(g,u,d,true);\n        int v=max_element(begin(d),end(d))-begin(d);\n\
    \        int diameter=d[v];\n        for(int i=0;i<diameter/2;i++) v=par[v];\n\
    \        vector<int> ret;\n        ret.push_back(v);\n        if(diameter%2) ret.push_back(par[v]);\n\
    \        return ret;\n    }\n\n    ull RootedTreeHash(vector<vector<int>> &g,int\
    \ root){\n        vector<int> dis(g.size(),-1);\n        vector<ull> h(g.size());\n\
    \        function<void(int,int)> dfs=[&](int par,int cur){\n            int d=-1;\n\
    \            for(auto &to:g[cur])if(par!=to){\n                dfs(cur,to);\n\
    \                chmax(d,dis[to]);\n            }\n            d++;\n        \
    \    dis[cur]=d;\n            ull ret=1;\n            // rng hash\n          \
    \  for(auto &to:g[cur])if(par!=to) ret=mul(ret,add(h[to],R[d]));\n           \
    \ h[cur]=ret;\n        };\n        dfs(-1,root);\n        return h[root];\n  \
    \  }\n    // \u6728\u306E\u4E2D\u5FC3\u304B\u3089hash\u3092\u3068\u308B\uFF0E\u6728\
    \u306E\u4E2D\u5FC3\u306F2\u500B\u3042\u308B\u53EF\u80FD\u6027\u304C\u3042\u308B\
    \n    ull TreeHash(vector<vector<int>> &g){\n        auto centers=center(g);\n\
    \        ull ret=RootedTreeHash(g,centers[0]);\n        if(centers.size()==2)\
    \ ret=min(ret,RootedTreeHash(g,centers[1]));\n        return ret;\n    }\n   \
    \ bool RootedTreeIsomorphic(vector<vector<int>> &g,int g_root,vector<vector<int>>\
    \ &h,int h_root){\n        if(g.size()!=h.size()) return false;\n        return\
    \ (RootedTreeHash(g,g_root)==RootedTreeHash(h,h_root));\n    }\n    bool TreeIsomorphic(vector<vector<int>>\
    \ &g,vector<vector<int>> &h){\n        if(g.size()!=h.size()) return false;\n\
    \        return (TreeHash(g)==TreeHash(h));\n        }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Tree/TreeHash.cpp
  requiredBy: []
  timestamp: '2021-04-27 00:15:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_2821.test.cpp
documentation_of: Tree/TreeHash.cpp
layout: document
redirect_from:
- /library/Tree/TreeHash.cpp
- /library/Tree/TreeHash.cpp.html
title: Tree/TreeHash.cpp
---

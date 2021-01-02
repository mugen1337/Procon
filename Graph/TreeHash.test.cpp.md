---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2821
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2821
  bundledCode: "#line 1 \"Graph/TreeHash.test.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int i=0;i<(n);i++)\n\
    #define debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n#define\
    \ mod 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\n\
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};\ntemplate<class T>bool chmax(T &a,const T\
    \ &b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool chmin(T &a,const\
    \ T &b){if(b<a){a=b;return true;}return false;}\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2821\"\
    \n\n// hash type\nusing ull=unsigned long long;\nstruct TreeHasher{\n    using\
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
    \        return (TreeHash(g)==TreeHash(h));\n        }\n};\n\nstruct UnionFind{\n\
    \    int con;\n    vector<int> par,siz;\n    UnionFind(int n):con(n),par(n),siz(n,1){\n\
    \        iota(begin(par),end(par),0);\n    }\n    int root(int x){\n        return\
    \ (par[x]==x?x:(par[x]=root(par[x])));\n    }\n    bool sameroot(int x,int y){\n\
    \        return root(x)==root(y);\n    }\n    bool unite(int x,int y){\n     \
    \   x=root(x);y=root(y);\n        if(x==y) return false;\n        if(siz[x]<siz[y])swap(x,y);\n\
    \        siz[x]+=siz[y];\n        par[y]=x;\n        con--;\n        return true;\n\
    \    }\n    int size(int x){\n        return siz[root(x)];\n    }\n};\n\nsigned\
    \ main(){\n    TreeHasher th(300010);\n\n    int n,m;cin>>n>>m;\n    vector<vector<int>>\
    \ g(n);\n    UnionFind uf(n);\n    rep(i,m){\n        int u,v;cin>>u>>v;u--,v--;\n\
    \        uf.unite(u,v);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n\n    map<int,vector<int>> vertices;\n    rep(i,n) vertices[uf.root(i)].push_back(i);\n\
    \n    // hash\u3054\u3068\u30AB\u30A6\u30F3\u30C8\n    map<ull,int> cnt;\n   \
    \ vector<int> id(n);\n    for(auto &p:vertices){\n        auto &v=p.second;\n\
    \        rep(i,(int)v.size()) id[v[i]]=i;\n        vector<vector<int>> t(v.size());\n\
    \        rep(i,(int)v.size()){\n            for(auto &j:g[v[i]]) t[i].push_back(id[j]);\n\
    \        }\n        cnt[th.TreeHash(t)]++;\n    }\n    \n    cin>>n;\n    vector<vector<int>>\
    \ t(n);\n    rep(i,n-1){\n        int u,v;cin>>u>>v;u--,v--;\n        t[u].push_back(v);\n\
    \        t[v].push_back(u);\n    }\n    cout<<cnt[th.TreeHash(t)]<<endl;\n   \
    \ return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto\
    \ x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\nusing ll=long long;\n\
    const int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2821\"\n\n// hash\
    \ type\nusing ull=unsigned long long;\nstruct TreeHasher{\n    using uint128=__uint128_t;\n\
    \    static const ull Mod=(1ull<<61ull)-1;\n    static inline ull add(ull a,ull\
    \ b){if((a+=b)>=Mod)a-=Mod;return a;}\n    static inline ull mul(ull a,ull b){uint128\
    \ c=(uint128)a*b;return add(c>>61,c&Mod);}\n    vector<ull> R;\n\n\n    // \u6728\
    \u306E\u30B5\u30A4\u30BA\n    TreeHasher(int n){\n        R.push_back(1);\n  \
    \      mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \        return (TreeHash(g)==TreeHash(h));\n        }\n};\n\nstruct UnionFind{\n\
    \    int con;\n    vector<int> par,siz;\n    UnionFind(int n):con(n),par(n),siz(n,1){\n\
    \        iota(begin(par),end(par),0);\n    }\n    int root(int x){\n        return\
    \ (par[x]==x?x:(par[x]=root(par[x])));\n    }\n    bool sameroot(int x,int y){\n\
    \        return root(x)==root(y);\n    }\n    bool unite(int x,int y){\n     \
    \   x=root(x);y=root(y);\n        if(x==y) return false;\n        if(siz[x]<siz[y])swap(x,y);\n\
    \        siz[x]+=siz[y];\n        par[y]=x;\n        con--;\n        return true;\n\
    \    }\n    int size(int x){\n        return siz[root(x)];\n    }\n};\n\nsigned\
    \ main(){\n    TreeHasher th(300010);\n\n    int n,m;cin>>n>>m;\n    vector<vector<int>>\
    \ g(n);\n    UnionFind uf(n);\n    rep(i,m){\n        int u,v;cin>>u>>v;u--,v--;\n\
    \        uf.unite(u,v);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n\n    map<int,vector<int>> vertices;\n    rep(i,n) vertices[uf.root(i)].push_back(i);\n\
    \n    // hash\u3054\u3068\u30AB\u30A6\u30F3\u30C8\n    map<ull,int> cnt;\n   \
    \ vector<int> id(n);\n    for(auto &p:vertices){\n        auto &v=p.second;\n\
    \        rep(i,(int)v.size()) id[v[i]]=i;\n        vector<vector<int>> t(v.size());\n\
    \        rep(i,(int)v.size()){\n            for(auto &j:g[v[i]]) t[i].push_back(id[j]);\n\
    \        }\n        cnt[th.TreeHash(t)]++;\n    }\n    \n    cin>>n;\n    vector<vector<int>>\
    \ t(n);\n    rep(i,n-1){\n        int u,v;cin>>u>>v;u--,v--;\n        t[u].push_back(v);\n\
    \        t[v].push_back(u);\n    }\n    cout<<cnt[th.TreeHash(t)]<<endl;\n   \
    \ return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: Graph/TreeHash.test.cpp
  requiredBy: []
  timestamp: '2021-01-02 03:54:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/TreeHash.test.cpp
layout: document
redirect_from:
- /verify/Graph/TreeHash.test.cpp
- /verify/Graph/TreeHash.test.cpp.html
title: Graph/TreeHash.test.cpp
---
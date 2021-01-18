---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph2/GraphTemplate.cpp
    title: Graph2/GraphTemplate.cpp
  - icon: ':heavy_check_mark:'
    path: Graph2/StronglyConnectedComponents.cpp
    title: Graph2/StronglyConnectedComponents.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo_scc2.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#line 1 \"template.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int i=0;i<(n);i++)\n#define\
    \ debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n#define mod\
    \ 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\n\
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \nstruct IOSetup{\n    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n\
    \        cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/yosupo_scc2.test.cpp\"\n\n#line 1 \"Graph2/GraphTemplate.cpp\"\
    \n// graph template\n// ref : https://ei1333.github.io/library/graph/graph-template.cpp\n\
    template<typename T=int>\nstruct Edge{\n    int from,to;\n    T w;\n    int idx;\n\
    \    Edge()=default;\n    Edge(int from,int to,T w=1,int idx=-1):from(from),to(to),w(w),idx(idx){}\n\
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
    \            comp[to]=p;\n            rdfs(to,p);\n        }\n    }\n\n    public:\n\
    \    vector<int> comp;\n    vector<vector<int>> group;\n    Graph<T> compressed;\n\
    \    \n    StronglyConnectedComponents(Graph<T> &g):g(g),rg(g.size()),check(g.size()),comp(g.size(),-1){\n\
    \        for(int i=0;i<(int)g.size();i++)for(auto &e:g[i]) rg.add_directed_edge(e.to,e.from,e.w);\n\
    \        build();\n    }\n    // return compressed graph\n    void build(){\n\
    \        vector<int> ord;\n        for(int i=0;i<(int)g.size();i++)if(!check[i]){\n\
    \            check[i]=true;\n            dfs(i,ord);\n        }\n        int ptr=0;;\n\
    \        for(int i=(int)ord.size()-1;i>=0;i--)if(comp[ord[i]]==-1){\n        \
    \    comp[ord[i]]=ptr;\n            rdfs(ord[i],ptr);ptr++;\n        }\n     \
    \   compressed.resize(ptr);\n        group.resize(ptr);\n        for(int i=0;i<(int)g.size();i++){\n\
    \            int u=comp[i];\n            group[u].push_back(i);\n            for(auto\
    \ &e:g[i]){\n                int v=comp[e];\n                if(u!=v) compressed.add_directed_edge(u,v,e.w);\n\
    \            }\n        }\n        return ;\n    }\n};\n#line 6 \"test/yosupo_scc2.test.cpp\"\
    \n\nsigned main(){\n    int n,m;cin>>n>>m;\n    Graph g(n);\n    g.read(m,0,false,true);\n\
    \n    StronglyConnectedComponents scc(g);\n\n    cout<<scc.group.size()<<\"\\\
    n\";\n    rep(i,(int)scc.group.size()){\n        cout<<scc.group[i].size();\n\
    \        for(auto x:scc.group[i]) cout<<\" \"<<x;\n        cout<<\"\\n\";\n  \
    \  }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../template.cpp\"\
    \n\n#include \"../Graph2/StronglyConnectedComponents.cpp\"\n\nsigned main(){\n\
    \    int n,m;cin>>n>>m;\n    Graph g(n);\n    g.read(m,0,false,true);\n\n    StronglyConnectedComponents\
    \ scc(g);\n\n    cout<<scc.group.size()<<\"\\n\";\n    rep(i,(int)scc.group.size()){\n\
    \        cout<<scc.group[i].size();\n        for(auto x:scc.group[i]) cout<<\"\
    \ \"<<x;\n        cout<<\"\\n\";\n    }\n    return 0;\n}"
  dependsOn:
  - template.cpp
  - Graph2/StronglyConnectedComponents.cpp
  - Graph2/GraphTemplate.cpp
  isVerificationFile: true
  path: test/yosupo_scc2.test.cpp
  requiredBy: []
  timestamp: '2021-01-18 16:57:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_scc2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_scc2.test.cpp
- /verify/test/yosupo_scc2.test.cpp.html
title: test/yosupo_scc2.test.cpp
---

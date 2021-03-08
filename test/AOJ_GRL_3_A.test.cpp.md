---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph2/GraphTemplate.cpp
    title: Graph2/GraphTemplate.cpp
  - icon: ':heavy_check_mark:'
    path: Graph2/LowLink.cpp
    title: Low Link
  - icon: ':question:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"test/AOJ_GRL_3_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
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
    \   return is;\n}\n\n#line 4 \"test/AOJ_GRL_3_A.test.cpp\"\n\n#line 1 \"Graph2/GraphTemplate.cpp\"\
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n#line 2 \"Graph2/LowLink.cpp\"\
    \n\ntemplate<typename T>\nstruct LowLink{\n    Graph<T> &g;\n    vector<int> ord,low;\n\
    \    vector<int> art;// articulation (true/false)\n    vector<Edge<T>> bridge;\n\
    \n    LowLink(Graph<T> &g):g(g){\n        ord.assign(g.V,-1);\n        low.assign(g.V,-1);\n\
    \        art.resize(g.V);\n\n        int idx=0;\n        function<void(int,int)>\
    \ dfs=[&](int pre,int cur){\n            ord[cur]=idx++;\n            low[cur]=ord[cur];\n\
    \n            int pre_c=0,ch=0;\n            bool art_f=false;\n\n           \
    \ for(auto &e:g[cur]){\n                if(e==pre and pre_c==0){\n           \
    \         pre_c++;\n                    continue;\n                }\n       \
    \         if(ord[e]<0){\n                    ch++;\n                    dfs(cur,e);\n\
    \                    low[cur]=min(low[cur],low[e]);\n                    art_f|=(pre>=0\
    \ and low[e]>=ord[cur]);\n                    if(ord[cur]<low[e]) bridge.push_back(e);\n\
    \                }\n                else{\n                    low[cur]=min(low[cur],ord[e]);\n\
    \                }\n            }\n            if(pre==-1) art_f|=(ch>1);\n  \
    \          art[cur]=art_f;\n            return ;\n        };\n        for(int\
    \ i=0;i<g.V;i++)if(ord[i]<0) dfs(-1,i);\n    }\n};\n#line 6 \"test/AOJ_GRL_3_A.test.cpp\"\
    \n\nsigned main(){\n    int n,m;cin>>n>>m;\n    Graph<int> g(n);\n    g.read(m,0);\n\
    \    LowLink<int> LL(g);\n    vector<int> res;\n    rep(i,n)if(LL.art[i]) res.push_back(i);\n\
    \    for(auto x:res) cout<<x<<endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include \"../template.cpp\"\n\n#include \"../Graph2/LowLink.cpp\"\n\nsigned\
    \ main(){\n    int n,m;cin>>n>>m;\n    Graph<int> g(n);\n    g.read(m,0);\n  \
    \  LowLink<int> LL(g);\n    vector<int> res;\n    rep(i,n)if(LL.art[i]) res.push_back(i);\n\
    \    for(auto x:res) cout<<x<<endl;\n    return 0;\n}\n"
  dependsOn:
  - template.cpp
  - Graph2/LowLink.cpp
  - Graph2/GraphTemplate.cpp
  isVerificationFile: true
  path: test/AOJ_GRL_3_A.test.cpp
  requiredBy: []
  timestamp: '2021-03-03 21:55:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ_GRL_3_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_GRL_3_A.test.cpp
- /verify/test/AOJ_GRL_3_A.test.cpp.html
title: test/AOJ_GRL_3_A.test.cpp
---

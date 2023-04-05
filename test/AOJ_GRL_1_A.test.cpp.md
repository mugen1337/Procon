---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph2/Dijkstra.hpp
    title: Dijkstra
  - icon: ':x:'
    path: Graph2/GraphTemplate.hpp
    title: Graph2/GraphTemplate.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
  bundledCode: "#line 1 \"test/AOJ_GRL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja\"\
    \n\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
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
    \   return is;\n}\n\n#line 4 \"test/AOJ_GRL_1_A.test.cpp\"\n\n#line 1 \"Graph2/GraphTemplate.hpp\"\
    \n// graph template\n// ref : https://ei1333.github.io/library/graph/graph-template.hpp\n\
    template<typename T=int>\nstruct Edge{\n    int from,to;\n    T w;\n    int idx;\n\
    \    Edge()=default;\n    Edge(int from,int to,T w=1,int idx=-1):from(from),to(to),w(w),idx(idx){}\n\
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n#line 2 \"Graph2/Dijkstra.hpp\"\
    \n\ntemplate<typename T>\nstruct Dijkstra{\n    const T inf;\n    Graph<T> g;\n\
    \    vector<T> d;\n    vector<int> prev,eid;\n    \n    Dijkstra(Graph<T> g):inf(numeric_limits<T>::max()/4),g(g){}\n\
    \n    vector<T> build(int st){\n        d.assign(g.V,inf);\n        prev.assign(g.V,-1);\n\
    \        eid.assign(g.V,-1);\n        d[st]=0;\n        priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n        que.emplace(d[st],st);\n        while(!que.empty()){\n       \
    \     auto p=que.top();que.pop();\n            int cur=p.second;\n           \
    \ if(d[cur]<p.first) continue;\n            for(auto &e:g[cur]){\n           \
    \     if(d[e]>d[cur]+e.w){\n                    d[e]=d[cur]+e.w;\n           \
    \         prev[e]=cur;\n                    que.emplace(d[e],e);\n           \
    \     }\n            }\n        }\n        return d;\n    }\n\n    // vertex =\
    \ false :-> edge idx\n    vector<int> get_path(int gl,bool vertex=true){\n   \
    \     vector<int> ret;\n        if(d[gl]==inf) return ret;\n        for(;gl!=-1;gl=prev[gl]){\n\
    \            ret.push_back(vertex?gl:eid[gl]);\n        }\n        reverse(ret.begin(),ret.end());\n\
    \        return ret;\n    }\n};\n#line 6 \"test/AOJ_GRL_1_A.test.cpp\"\n\nsigned\
    \ main(){\n    int n,m,s;cin>>n>>m>>s;\n    Graph<ll> g(n);\n    g.read(m,0,true,true);\n\
    \    Dijkstra dij(g);\n    for(auto x:dij.build(s)){\n        if(x==dij.inf) cout<<\"\
    INF\"<<endl;\n        else cout<<x<<endl;\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja\"\
    \n\n#include \"../template.hpp\"\n\n#include \"../Graph2/Dijkstra.hpp\"\n\nsigned\
    \ main(){\n    int n,m,s;cin>>n>>m>>s;\n    Graph<ll> g(n);\n    g.read(m,0,true,true);\n\
    \    Dijkstra dij(g);\n    for(auto x:dij.build(s)){\n        if(x==dij.inf) cout<<\"\
    INF\"<<endl;\n        else cout<<x<<endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - template.hpp
  - Graph2/Dijkstra.hpp
  - Graph2/GraphTemplate.hpp
  isVerificationFile: true
  path: test/AOJ_GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ_GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_GRL_1_A.test.cpp
- /verify/test/AOJ_GRL_1_A.test.cpp.html
title: test/AOJ_GRL_1_A.test.cpp
---

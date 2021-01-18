---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Dijkstra.cpp
    title: Graph/Dijkstra.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/yosupo_Shortest_Path.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n\n#line 1 \"template.cpp\"\n\
    #include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto\
    \ x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\nusing ll=long long;\n\
    const int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n\
    // ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\ntemplate<class T>bool chmax(T &a,const\
    \ T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool chmin(T\
    \ &a,const T &b){if(b<a){a=b;return true;}return false;}\n\nstruct IOSetup{\n\
    \    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n     \
    \   cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename T>\n\
    ostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/yosupo_Shortest_Path.test.cpp\"\n\n#line 1\
    \ \"Graph/Dijkstra.cpp\"\ntemplate<typename T>\nstruct Dijkstra{\n    const T\
    \ TINF=numeric_limits<T>::max();\n    using P=pair<T,int>;\n    int n;\n    vector<vector<P>>\
    \ G;\n    vector<T> d;\n    vector<int> prev;\n  \n    Dijkstra(int n):n(n),G(vector<vector<P>>(n)){}\n\
    \    void init(){\n        d.assign(n,TINF);\n        prev.assign(n,-1);\n   \
    \ }\n    void add_edge(int s,int t,T cost){\n        G[s].push_back(P(cost,t));\n\
    \    }\n    void build(int s){\n        init();\n        d[s]=0;\n        priority_queue<P,vector<P>,greater<P>>\
    \ q;\n        q.push(P(d[s],s));\n        while(!q.empty()){\n            P p=q.top();q.pop();\n\
    \            int v=p.second;\n            if(d[v]<p.first) continue;\n       \
    \     for(auto e:G[v]){\n                int u=e.second;\n                T cost=e.first;\n\
    \                if(d[u]>d[v]+e.first){\n                    d[u]=d[v]+cost;\n\
    \                    prev[u]=v;\n                    q.push(P(d[u],u));\n    \
    \            }\n            }\n        }\n    }\n \n    T operator[](const int\
    \ &p)const{\n        return d[p];\n    }\n \n    vector<int> get_path(int g){\n\
    \        vector<int> ret;\n        if(d[g]==TINF) return ret;\n        for(;g!=-1;g=prev[g]){\n\
    \            ret.push_back(g);\n        }\n        reverse(ret.begin(),ret.end());\n\
    \        return ret;\n    }\n};\n#line 6 \"test/yosupo_Shortest_Path.test.cpp\"\
    \n\nsigned main(){\n    int n,m,s,t;cin>>n>>m>>s>>t;\n    Dijkstra<ll> d(n);\n\
    \    rep(i,m){\n        int u,v;ll c;cin>>u>>v>>c;\n        d.add_edge(u,v,c);\n\
    \    }\n    d.build(s);\n    auto p=d.get_path(t);\n    if(p.empty()) cout<<-1<<endl;\n\
    \    else{\n        cout<<d[t]<<\" \"<<(int)p.size()-1<<endl;\n        int k=p[0];\n\
    \        for(int i=1;i<(int)p.size();i++){\n            cout<<k<<\" \"<<p[i]<<endl;\n\
    \            k=p[i];\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../template.cpp\"\n\n#include \"../Graph/Dijkstra.cpp\"\n\nsigned main(){\n\
    \    int n,m,s,t;cin>>n>>m>>s>>t;\n    Dijkstra<ll> d(n);\n    rep(i,m){\n   \
    \     int u,v;ll c;cin>>u>>v>>c;\n        d.add_edge(u,v,c);\n    }\n    d.build(s);\n\
    \    auto p=d.get_path(t);\n    if(p.empty()) cout<<-1<<endl;\n    else{\n   \
    \     cout<<d[t]<<\" \"<<(int)p.size()-1<<endl;\n        int k=p[0];\n       \
    \ for(int i=1;i<(int)p.size();i++){\n            cout<<k<<\" \"<<p[i]<<endl;\n\
    \            k=p[i];\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - template.cpp
  - Graph/Dijkstra.cpp
  isVerificationFile: true
  path: test/yosupo_Shortest_Path.test.cpp
  requiredBy: []
  timestamp: '2021-01-09 19:35:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_Shortest_Path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Shortest_Path.test.cpp
- /verify/test/yosupo_Shortest_Path.test.cpp.html
title: test/yosupo_Shortest_Path.test.cpp
---
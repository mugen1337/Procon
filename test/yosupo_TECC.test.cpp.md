---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph2/GraphTemplate.hpp
    title: Graph2/GraphTemplate.hpp
  - icon: ':heavy_check_mark:'
    path: Graph2/LowLink.hpp
    title: Low Link
  - icon: ':heavy_check_mark:'
    path: Graph2/TwoEdgeConnectedComponents.hpp
    title: Graph2/TwoEdgeConnectedComponents.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/yosupo_TECC.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
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
    \   return is;\n}\n\n#line 1 \"Graph2/GraphTemplate.hpp\"\n// graph template\n\
    // ref : https://ei1333.github.io/library/graph/graph-template.hpp\ntemplate<typename\
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n#line 2 \"Graph2/LowLink.hpp\"\
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
    \ i=0;i<g.V;i++)if(ord[i]<0) dfs(-1,i);\n    }\n};\n#line 2 \"Graph2/TwoEdgeConnectedComponents.hpp\"\
    \n\n/*\n\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\u3092\u3057\uFF0C\
    \u9802\u70B9\u3092group\u306B\u5206\u3051\u308B\ngroup[i] : \u30B0\u30EB\u30FC\
    \u30D7i\u304C\u6301\u3064\u9802\u70B9\u756A\u53F7\nbelong[i] : \u9802\u70B9i\u304C\
    \u6240\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u756A\u53F7\n*/\ntemplate<typename\
    \ T>\nstruct TwoEdgeConnectedComponents{\npublic:\n    LowLink<T> LL;\n    void\
    \ dfs(Graph<T> &g,int pre,int cur,int &k){\n        if(pre>=0 and LL.ord[pre]>=LL.low[cur])\
    \ belong[cur]=belong[pre];\n        else                                    belong[cur]=k++;\n\
    \n        for(auto &e:g[cur])if(belong[e]==-1) dfs(g,cur,e,k);\n    }\n\npublic:\n\
    \    vector<int> belong;\n    vector<vector<int>> group;\n    Graph<T> tree;\n\
    \n    TwoEdgeConnectedComponents(Graph<T> &g):LL(g),belong(g.size(),-1){\n   \
    \     int k=0;\n        for(int i=0;i<g.size();i++)if(belong[i]==-1) dfs(g,-1,i,k);\n\
    \        group.resize(k);\n        for(int i=0;i<g.size();i++) group[belong[i]].push_back(i);\n\
    \        tree=Graph<T>(k);\n        for(auto &e:LL.bridge) tree.add_edge(belong[e.from],belong[e.to],e.w);\n\
    \    }\n};\n#line 5 \"test/yosupo_TECC.test.cpp\"\n\nsigned main(){\n    int N,M;cin>>N>>M;\n\
    \    Graph<int> G(N);\n    G.read(M,0);\n\n    TwoEdgeConnectedComponents<int>\
    \ TECC(G);\n    cout<<TECC.group.size()<<\"\\n\";\n    for(auto &w:TECC.group){\n\
    \        cout<<w.size();\n        for(auto &x:w) cout<<\" \"<<x;\n        cout<<\"\
    \\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"../template.hpp\"\n#include \"../Graph2/TwoEdgeConnectedComponents.hpp\"\
    \n\nsigned main(){\n    int N,M;cin>>N>>M;\n    Graph<int> G(N);\n    G.read(M,0);\n\
    \n    TwoEdgeConnectedComponents<int> TECC(G);\n    cout<<TECC.group.size()<<\"\
    \\n\";\n    for(auto &w:TECC.group){\n        cout<<w.size();\n        for(auto\
    \ &x:w) cout<<\" \"<<x;\n        cout<<\"\\n\";\n    }\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - Graph2/TwoEdgeConnectedComponents.hpp
  - Graph2/LowLink.hpp
  - Graph2/GraphTemplate.hpp
  isVerificationFile: true
  path: test/yosupo_TECC.test.cpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_TECC.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_TECC.test.cpp
- /verify/test/yosupo_TECC.test.cpp.html
title: test/yosupo_TECC.test.cpp
---
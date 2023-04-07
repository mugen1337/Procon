---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph2/CycleDetection.hpp
    title: Graph2/CycleDetection.hpp
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"test/yosupo_CycleDetection2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#line 1 \"template.hpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
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
    \   return is;\n}\n\n#line 4 \"test/yosupo_CycleDetection2.test.cpp\"\n\n#line\
    \ 1 \"Graph2/GraphTemplate.hpp\"\n// graph template\n// ref : https://ei1333.github.io/library/graph/graph-template.hpp\n\
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
    \            return cyc;\n            }\n        }\n    }\n    return {};\n}\n\
    #line 6 \"test/yosupo_CycleDetection2.test.cpp\"\n\nsigned main(){\n    int n,m;cin>>n>>m;\n\
    \    Graph g(n);\n    map<pair<int,int>,int> id;\n    rep(i,m){\n        int u,v;cin>>u>>v;\n\
    \        id[{u,v}]=i;\n        g.add_directed_edge(u,v);\n    }\n    auto res=CycleDetection(g);\n\
    \    if(res.empty()){\n        cout<<-1<<endl;\n        return 0;\n    }\n   \
    \ int p=res[0];\n    vector<int> ans;\n    for(int i=1;i<(int)res.size();i++){\n\
    \        ans.push_back(id[{p,res[i]}]);\n        p=res[i];\n    }\n    ans.push_back(id[{p,res[0]}]);\n\
    \    cout<<ans.size()<<\"\\n\";\n    for(auto e:ans) cout<<e<<\"\\n\";\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#include\
    \ \"../template.hpp\"\n\n#include \"../Graph2/CycleDetection.hpp\"\n\nsigned main(){\n\
    \    int n,m;cin>>n>>m;\n    Graph g(n);\n    map<pair<int,int>,int> id;\n   \
    \ rep(i,m){\n        int u,v;cin>>u>>v;\n        id[{u,v}]=i;\n        g.add_directed_edge(u,v);\n\
    \    }\n    auto res=CycleDetection(g);\n    if(res.empty()){\n        cout<<-1<<endl;\n\
    \        return 0;\n    }\n    int p=res[0];\n    vector<int> ans;\n    for(int\
    \ i=1;i<(int)res.size();i++){\n        ans.push_back(id[{p,res[i]}]);\n      \
    \  p=res[i];\n    }\n    ans.push_back(id[{p,res[0]}]);\n    cout<<ans.size()<<\"\
    \\n\";\n    for(auto e:ans) cout<<e<<\"\\n\";\n    return 0;\n}\n"
  dependsOn:
  - template.hpp
  - Graph2/CycleDetection.hpp
  - Graph2/GraphTemplate.hpp
  isVerificationFile: true
  path: test/yosupo_CycleDetection2.test.cpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_CycleDetection2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_CycleDetection2.test.cpp
- /verify/test/yosupo_CycleDetection2.test.cpp.html
title: test/yosupo_CycleDetection2.test.cpp
---

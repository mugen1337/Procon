---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"Graph/StronglyConnectedComponents.test.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int\
    \ i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n\
    #define mod 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst\
    \ ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll\
    \ gcd(ll a,ll b){return b?gcd(b,a%b):a;}\ntemplate<class T>bool chmax(T &a,const\
    \ T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool chmin(T\
    \ &a,const T &b){if(b<a){a=b;return true;}return false;}\n\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/scc\"\n\nstruct StronglyConnectedComponents{\n\
    \    private:\n    vector<vector<int>> g,rg;\n    vector<int> check;\n    void\
    \ dfs(int cur,vector<int> &ord){\n        for(auto &to:g[cur])if(!check[to]){\n\
    \            check[to]=true;\n            dfs(to,ord);\n        }\n        ord.push_back(cur);\n\
    \    }\n    void rdfs(int cur,int p){\n        for(auto &to:rg[cur])if(comp[to]==-1){\n\
    \            comp[to]=p;\n            rdfs(to,p);\n        }\n    }\n\n    public:\n\
    \    vector<int> comp;\n    vector<vector<int>> compressed,group;\n    \n    StronglyConnectedComponents(vector<vector<int>>\
    \ &g):g(g),rg(g.size()),check(g.size()),comp(g.size(),-1){\n        for(int i=0;i<(int)g.size();i++)for(auto\
    \ &j:g[i]) rg[j].push_back(i);\n    }\n    // return compressed graph\n    vector<vector<int>>\
    \ build(){\n        vector<int> ord;\n        for(int i=0;i<(int)g.size();i++)if(!check[i]){\n\
    \            check[i]=true;\n            dfs(i,ord);\n        }\n        int ptr=0;;\n\
    \        for(int i=(int)ord.size()-1;i>=0;i--)if(comp[ord[i]]==-1){\n        \
    \    comp[ord[i]]=ptr;\n            rdfs(ord[i],ptr);ptr++;\n        }\n     \
    \   compressed.resize(ptr);\n        group.resize(ptr);\n        for(int i=0;i<(int)g.size();i++){\n\
    \            int u=comp[i];\n            group[u].push_back(i);\n            for(auto\
    \ &j:g[i]){\n                int v=comp[j];\n                if(u!=v) compressed[u].push_back(v);\n\
    \            }\n        }\n        return compressed;\n    }\n};\n\n\n\nsigned\
    \ main(){\n    int n,m;cin>>n>>m;\n    vector<vector<int>> g(n);\n    rep(i,m){\n\
    \        int u,v;cin>>u>>v;\n        g[u].push_back(v);\n    }\n\n    StronglyConnectedComponents\
    \ scc(g);\n    scc.build();\n    cout<<scc.group.size()<<\"\\n\";\n    rep(i,(int)scc.group.size()){\n\
    \        cout<<scc.group[i].size();\n        for(auto x:scc.group[i]) cout<<\"\
    \ \"<<x;\n        cout<<\"\\n\";\n    }\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto\
    \ x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\nusing ll=long long;\n\
    const int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n\
    // ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\ntemplate<class T>bool chmax(T &a,const\
    \ T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool chmin(T\
    \ &a,const T &b){if(b<a){a=b;return true;}return false;}\n\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/scc\"\n\nstruct StronglyConnectedComponents{\n\
    \    private:\n    vector<vector<int>> g,rg;\n    vector<int> check;\n    void\
    \ dfs(int cur,vector<int> &ord){\n        for(auto &to:g[cur])if(!check[to]){\n\
    \            check[to]=true;\n            dfs(to,ord);\n        }\n        ord.push_back(cur);\n\
    \    }\n    void rdfs(int cur,int p){\n        for(auto &to:rg[cur])if(comp[to]==-1){\n\
    \            comp[to]=p;\n            rdfs(to,p);\n        }\n    }\n\n    public:\n\
    \    vector<int> comp;\n    vector<vector<int>> compressed,group;\n    \n    StronglyConnectedComponents(vector<vector<int>>\
    \ &g):g(g),rg(g.size()),check(g.size()),comp(g.size(),-1){\n        for(int i=0;i<(int)g.size();i++)for(auto\
    \ &j:g[i]) rg[j].push_back(i);\n    }\n    // return compressed graph\n    vector<vector<int>>\
    \ build(){\n        vector<int> ord;\n        for(int i=0;i<(int)g.size();i++)if(!check[i]){\n\
    \            check[i]=true;\n            dfs(i,ord);\n        }\n        int ptr=0;;\n\
    \        for(int i=(int)ord.size()-1;i>=0;i--)if(comp[ord[i]]==-1){\n        \
    \    comp[ord[i]]=ptr;\n            rdfs(ord[i],ptr);ptr++;\n        }\n     \
    \   compressed.resize(ptr);\n        group.resize(ptr);\n        for(int i=0;i<(int)g.size();i++){\n\
    \            int u=comp[i];\n            group[u].push_back(i);\n            for(auto\
    \ &j:g[i]){\n                int v=comp[j];\n                if(u!=v) compressed[u].push_back(v);\n\
    \            }\n        }\n        return compressed;\n    }\n};\n\n\n\nsigned\
    \ main(){\n    int n,m;cin>>n>>m;\n    vector<vector<int>> g(n);\n    rep(i,m){\n\
    \        int u,v;cin>>u>>v;\n        g[u].push_back(v);\n    }\n\n    StronglyConnectedComponents\
    \ scc(g);\n    scc.build();\n    cout<<scc.group.size()<<\"\\n\";\n    rep(i,(int)scc.group.size()){\n\
    \        cout<<scc.group[i].size();\n        for(auto x:scc.group[i]) cout<<\"\
    \ \"<<x;\n        cout<<\"\\n\";\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Graph/StronglyConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2021-01-03 21:55:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/StronglyConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/Graph/StronglyConnectedComponents.test.cpp
- /verify/Graph/StronglyConnectedComponents.test.cpp.html
title: Graph/StronglyConnectedComponents.test.cpp
---

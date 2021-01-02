---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"UnionFind/UnionFindUndo.test.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int\
    \ i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n\
    #define mod 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst\
    \ ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll\
    \ gcd(ll a,ll b){return b?gcd(b,a%b):a;}\ntemplate<class T>bool chmax(T &a,const\
    \ T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool chmin(T\
    \ &a,const T &b){if(b<a){a=b;return true;}return false;}\n\nstruct IOSetup{\n\
    \    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n     \
    \   cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename T>\n\
    ostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n// \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057\uFF0C\u30DE\u30FC\u30B8\u30C6\u30AF\
    \u3067unite\uFF0C\u30AF\u30A8\u30EA\u6BCEO(logN)\nstruct UnionFindUndo{\n    int\
    \ con;\n    vector<int> data;\n    stack<tuple<int,int,bool>> history;\n    UnionFindUndo(int\
    \ sz){\n        con=sz;\n        data.assign(sz,-1);\n    }\n    bool unite(int\
    \ x,int y){\n        x=root(x),y=root(y);\n        \n        if(x==y){\n     \
    \       history.push(make_tuple(x,data[x],false));\n            history.push(make_tuple(y,data[y],false));\n\
    \            return false;\n        }\n        con--;\n        history.push(make_tuple(x,data[x],true));\n\
    \        history.push(make_tuple(y,data[y],false));\n        if(data[x]>data[y])\
    \ swap(x,y);\n        data[x]+=data[y];\n        data[y]=x;\n        return true;\n\
    \    }\n    int root(int k){return (data[k]<0?k:(root(data[k])));}\n    int size(int\
    \ k){return (-data[root(k)]);}\n    bool sameroot(int x,int y){return root(x)==root(y);}\n\
    \    void undo(){\n        {\n            auto [fs,sc,con_flag]=history.top();history.pop();\n\
    \            if(con_flag) con++;\n            data[fs]=sc;\n        }\n      \
    \  {\n            auto [fs,sc,con_flag]=history.top();history.pop();\n       \
    \     if(con_flag) con++;\n            data[fs]=sc;\n        }\n    }\n    void\
    \ snapshot(){while(!history.empty())history.pop();}\n    void rollback(){while(!history.empty())undo();}\n\
    };\n\nsigned main(){\n    int n,q;cin>>n>>q;\n    UnionFindUndo uf(n);\n    while(q--){\n\
    \        int t,u,v;cin>>t>>u>>v;\n        if(t) cout<<uf.sameroot(u,v)<<endl;\n\
    \        else uf.unite(u,v);\n    }\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
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
    \   return is;\n}\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n// \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057\uFF0C\u30DE\u30FC\u30B8\u30C6\u30AF\
    \u3067unite\uFF0C\u30AF\u30A8\u30EA\u6BCEO(logN)\nstruct UnionFindUndo{\n    int\
    \ con;\n    vector<int> data;\n    stack<tuple<int,int,bool>> history;\n    UnionFindUndo(int\
    \ sz){\n        con=sz;\n        data.assign(sz,-1);\n    }\n    bool unite(int\
    \ x,int y){\n        x=root(x),y=root(y);\n        \n        if(x==y){\n     \
    \       history.push(make_tuple(x,data[x],false));\n            history.push(make_tuple(y,data[y],false));\n\
    \            return false;\n        }\n        con--;\n        history.push(make_tuple(x,data[x],true));\n\
    \        history.push(make_tuple(y,data[y],false));\n        if(data[x]>data[y])\
    \ swap(x,y);\n        data[x]+=data[y];\n        data[y]=x;\n        return true;\n\
    \    }\n    int root(int k){return (data[k]<0?k:(root(data[k])));}\n    int size(int\
    \ k){return (-data[root(k)]);}\n    bool sameroot(int x,int y){return root(x)==root(y);}\n\
    \    void undo(){\n        {\n            auto [fs,sc,con_flag]=history.top();history.pop();\n\
    \            if(con_flag) con++;\n            data[fs]=sc;\n        }\n      \
    \  {\n            auto [fs,sc,con_flag]=history.top();history.pop();\n       \
    \     if(con_flag) con++;\n            data[fs]=sc;\n        }\n    }\n    void\
    \ snapshot(){while(!history.empty())history.pop();}\n    void rollback(){while(!history.empty())undo();}\n\
    };\n\nsigned main(){\n    int n,q;cin>>n>>q;\n    UnionFindUndo uf(n);\n    while(q--){\n\
    \        int t,u,v;cin>>t>>u>>v;\n        if(t) cout<<uf.sameroot(u,v)<<endl;\n\
    \        else uf.unite(u,v);\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: UnionFind/UnionFindUndo.test.cpp
  requiredBy: []
  timestamp: '2021-01-02 17:06:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: UnionFind/UnionFindUndo.test.cpp
layout: document
redirect_from:
- /verify/UnionFind/UnionFindUndo.test.cpp
- /verify/UnionFind/UnionFindUndo.test.cpp.html
title: UnionFind/UnionFindUndo.test.cpp
---
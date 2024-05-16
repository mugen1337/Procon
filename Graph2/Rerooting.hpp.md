---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph2/GraphTemplate.hpp
    title: Graph2/GraphTemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yuki5436.test.cpp
    title: test/yuki5436.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph2/GraphTemplate.hpp\"\n\n\n\n// graph template\n//\
    \ ref : https://ei1333.github.io/library/graph/graph-template.hpp\ntemplate<typename\
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
    \            else         add_edge(u,v,w);\n        }\n    }\n};\n\n\n#line 2\
    \ \"Graph2/Rerooting.hpp\"\n\ntemplate<typename T,typename GT=int>\nstruct Rerooting{\n\
    \    using E=function<T(T,Edge<GT>)>;//\u96C6\u5408\uFF0C\u9802\u70B9\u756A\u53F7\
    \n    using M=function<T(T,T)>;\n    using F=function<T(T,int)>;\n    \n    Graph<GT>\
    \ g;\n    // dp_v = fix(merge(f(dp_c1,edge(v,c1)),...,f(dp_ck,edge(v,ck))),v)\n\
    \    E f;    // f(T,Edge)->T  \u8FBA\u60C5\u5831\u3092\u8003\u616E\u3057\uFF0C\
    merge\u524D\u306E\u5F62\n    M merge;// TxT->T\uFF0C\u5B50\u3092\u96C6\u7D04\u3059\
    \u308B\u95A2\u6570\uFF0C\u30E2\u30CE\u30A4\u30C9\n    T e;    // merge\u306E\u5358\
    \u4F4D\u5143\n    F fix;  // TxN->T  \u88DC\u6B63\n    vector<vector<T>> dp;\n\
    \    vector<T> ans;\n    \n    Rerooting(Graph<GT> &g,E f,M merge,T e,F fix=[](T\
    \ a,int b){return a;}):\n    g(g),f(f),merge(merge),e(e),fix(fix),dp(g.size()),ans(g.size(),e){}\n\
    \n    T dfs1(int pre,int now){\n        T ret=e;\n        for(int i=0;i<(int)g[now].size();i++)if(g[now][i]!=pre){\n\
    \            dp[now][i]=dfs1(now,g[now][i]);\n            ret=merge(ret,f(dp[now][i],g[now][i]));\n\
    \        }\n        return fix(ret,now);\n    }\n    void dfs2(int pre,int now,T\
    \ frompar){\n        for(int i=0;i<(int)g[now].size();i++){\n            if(g[now][i]==pre){\n\
    \                dp[now][i]=frompar;\n                break;\n            }\n\
    \        }\n        vector<T> lsum(g[now].size()+1),rsum(g[now].size()+1);//\u89AA\
    \u3082\u6DF7\u305C\u3066\u7D2F\u7A4D\n        lsum[0]=e;rsum[g[now].size()]=e;\n\
    \        for(int i=0;i<(int)g[now].size();i++) lsum[i+1]=merge(lsum[i],f(dp[now][i],g[now][i]));\n\
    \        for(int i=(int)g[now].size();i>0;i--) rsum[i-1]=merge(rsum[i],f(dp[now][i-1],g[now][i-1]));\n\
    \        for(int i=0;i<(int)g[now].size();i++)if(g[now][i]!=pre){\n          \
    \  T fromme=merge(lsum[i],rsum[i+1]);\n            dfs2(now,g[now][i],fix(fromme,now));\n\
    \        }\n    }\n    void build(int root=0){\n        for(int i=0;i<(int)g.size();i++)\
    \ dp[i].resize(g[i].size());\n        dfs1(-1,root);\n        dfs2(-1,root,e);\n\
    \        for(int i=0;i<(int)g.size();i++){\n            for(int j=0;j<(int)g[i].size();j++)\
    \ ans[i]=merge(ans[i],f(dp[i][j],g[i][j]));\n            ans[i]=fix(ans[i],i);\n\
    \        }\n    }\n};\n"
  code: "#include \"./GraphTemplate.hpp\"\n\ntemplate<typename T,typename GT=int>\n\
    struct Rerooting{\n    using E=function<T(T,Edge<GT>)>;//\u96C6\u5408\uFF0C\u9802\
    \u70B9\u756A\u53F7\n    using M=function<T(T,T)>;\n    using F=function<T(T,int)>;\n\
    \    \n    Graph<GT> g;\n    // dp_v = fix(merge(f(dp_c1,edge(v,c1)),...,f(dp_ck,edge(v,ck))),v)\n\
    \    E f;    // f(T,Edge)->T  \u8FBA\u60C5\u5831\u3092\u8003\u616E\u3057\uFF0C\
    merge\u524D\u306E\u5F62\n    M merge;// TxT->T\uFF0C\u5B50\u3092\u96C6\u7D04\u3059\
    \u308B\u95A2\u6570\uFF0C\u30E2\u30CE\u30A4\u30C9\n    T e;    // merge\u306E\u5358\
    \u4F4D\u5143\n    F fix;  // TxN->T  \u88DC\u6B63\n    vector<vector<T>> dp;\n\
    \    vector<T> ans;\n    \n    Rerooting(Graph<GT> &g,E f,M merge,T e,F fix=[](T\
    \ a,int b){return a;}):\n    g(g),f(f),merge(merge),e(e),fix(fix),dp(g.size()),ans(g.size(),e){}\n\
    \n    T dfs1(int pre,int now){\n        T ret=e;\n        for(int i=0;i<(int)g[now].size();i++)if(g[now][i]!=pre){\n\
    \            dp[now][i]=dfs1(now,g[now][i]);\n            ret=merge(ret,f(dp[now][i],g[now][i]));\n\
    \        }\n        return fix(ret,now);\n    }\n    void dfs2(int pre,int now,T\
    \ frompar){\n        for(int i=0;i<(int)g[now].size();i++){\n            if(g[now][i]==pre){\n\
    \                dp[now][i]=frompar;\n                break;\n            }\n\
    \        }\n        vector<T> lsum(g[now].size()+1),rsum(g[now].size()+1);//\u89AA\
    \u3082\u6DF7\u305C\u3066\u7D2F\u7A4D\n        lsum[0]=e;rsum[g[now].size()]=e;\n\
    \        for(int i=0;i<(int)g[now].size();i++) lsum[i+1]=merge(lsum[i],f(dp[now][i],g[now][i]));\n\
    \        for(int i=(int)g[now].size();i>0;i--) rsum[i-1]=merge(rsum[i],f(dp[now][i-1],g[now][i-1]));\n\
    \        for(int i=0;i<(int)g[now].size();i++)if(g[now][i]!=pre){\n          \
    \  T fromme=merge(lsum[i],rsum[i+1]);\n            dfs2(now,g[now][i],fix(fromme,now));\n\
    \        }\n    }\n    void build(int root=0){\n        for(int i=0;i<(int)g.size();i++)\
    \ dp[i].resize(g[i].size());\n        dfs1(-1,root);\n        dfs2(-1,root,e);\n\
    \        for(int i=0;i<(int)g.size();i++){\n            for(int j=0;j<(int)g[i].size();j++)\
    \ ans[i]=merge(ans[i],f(dp[i][j],g[i][j]));\n            ans[i]=fix(ans[i],i);\n\
    \        }\n    }\n};"
  dependsOn:
  - Graph2/GraphTemplate.hpp
  isVerificationFile: false
  path: Graph2/Rerooting.hpp
  requiredBy: []
  timestamp: '2023-07-17 18:02:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yuki5436.test.cpp
documentation_of: Graph2/Rerooting.hpp
layout: document
redirect_from:
- /library/Graph2/Rerooting.hpp
- /library/Graph2/Rerooting.hpp.html
title: Graph2/Rerooting.hpp
---

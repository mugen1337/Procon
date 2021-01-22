---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/gym/100551/submission/103148848
    - https://ei1333.hateblo.jp/entry/2017/12/14/000000
  bundledCode: "#line 1 \"UnionFind/DynamicConnectivityOffline.cpp\"\n// verified\
    \ https://codeforces.com/gym/100551/submission/103148848\n// ref https://ei1333.hateblo.jp/entry/2017/12/14/000000\n\
    struct DynamicConnectivityOffline{\n    private:\n    int sz;\n    using P=pair<int,int>;\n\
    \    vector<vector<P>> seg;\n    vector<pair<P,P>> es;// {{start idx, end idx},\
    \ {u, v}}\n    map<P,int> cnt,prev;\n\n    void add_seg(int a,int b,P &e,int k,int\
    \ l,int r){\n        if(r<=a or b<=l) return ;\n        if(a<=l and r<=b){\n \
    \           seg[k].push_back(e);\n            return ;\n        }\n        add_seg(a,b,e,2*k,l,(l+r)/2);\n\
    \        add_seg(a,b,e,2*k+1,(l+r)/2,r);\n    }\n    \n\n    public:\n    int\
    \ n,q;\n    UnionFindUndo uf;\n\n    DynamicConnectivityOffline(int n,int q):n(n),q(q),uf(n){\n\
    \        sz=1;while(sz<q)sz<<=1;\n        seg.resize(sz*2);\n    }\n\n    // query\u306E\
    index\u9806\u306B\u8FFD\u52A0\n    void add_edge(int query_idx,int u,int v){\n\
    \        if(u>v) swap(u,v);\n        if(cnt[P(u,v)]==0) prev[P(u,v)]=query_idx;\n\
    \        cnt[P(u,v)]++;\n    }\n    void delete_edge(int query_idx,int u,int v){\n\
    \        if(u>v) swap(u,v);\n        assert(cnt[P(u,v)]>0);\n        cnt[P(u,v)]--;\n\
    \        if(cnt[P(u,v)]==0) es.emplace_back(P(prev[P(u,v)],query_idx),P(u,v));\n\
    \    }\n    void build(){\n        for(auto [e,c]:cnt)if(c>0) es.emplace_back(P(prev[e],sz),e);\n\
    \        for(auto [t,e]:es) add_seg(t.first,t.second,e,1,0,sz);\n    }\n    //\
    \ dfs -> segment tree\n    // f(query_idx)\n    void execute(function<void(int)>\
    \ &f,int k=1){\n        for(auto [u,v]:seg[k]) uf.unite(u,v);\n        if(k<sz){\n\
    \            execute(f,2*k);\n            execute(f,2*k+1);\n        }\n     \
    \   else if(k-sz<q) f(k-sz);// query\n        for(auto [u,v]:seg[k]) uf.undo();\n\
    \    }\n};\n"
  code: "// verified https://codeforces.com/gym/100551/submission/103148848\n// ref\
    \ https://ei1333.hateblo.jp/entry/2017/12/14/000000\nstruct DynamicConnectivityOffline{\n\
    \    private:\n    int sz;\n    using P=pair<int,int>;\n    vector<vector<P>>\
    \ seg;\n    vector<pair<P,P>> es;// {{start idx, end idx}, {u, v}}\n    map<P,int>\
    \ cnt,prev;\n\n    void add_seg(int a,int b,P &e,int k,int l,int r){\n       \
    \ if(r<=a or b<=l) return ;\n        if(a<=l and r<=b){\n            seg[k].push_back(e);\n\
    \            return ;\n        }\n        add_seg(a,b,e,2*k,l,(l+r)/2);\n    \
    \    add_seg(a,b,e,2*k+1,(l+r)/2,r);\n    }\n    \n\n    public:\n    int n,q;\n\
    \    UnionFindUndo uf;\n\n    DynamicConnectivityOffline(int n,int q):n(n),q(q),uf(n){\n\
    \        sz=1;while(sz<q)sz<<=1;\n        seg.resize(sz*2);\n    }\n\n    // query\u306E\
    index\u9806\u306B\u8FFD\u52A0\n    void add_edge(int query_idx,int u,int v){\n\
    \        if(u>v) swap(u,v);\n        if(cnt[P(u,v)]==0) prev[P(u,v)]=query_idx;\n\
    \        cnt[P(u,v)]++;\n    }\n    void delete_edge(int query_idx,int u,int v){\n\
    \        if(u>v) swap(u,v);\n        assert(cnt[P(u,v)]>0);\n        cnt[P(u,v)]--;\n\
    \        if(cnt[P(u,v)]==0) es.emplace_back(P(prev[P(u,v)],query_idx),P(u,v));\n\
    \    }\n    void build(){\n        for(auto [e,c]:cnt)if(c>0) es.emplace_back(P(prev[e],sz),e);\n\
    \        for(auto [t,e]:es) add_seg(t.first,t.second,e,1,0,sz);\n    }\n    //\
    \ dfs -> segment tree\n    // f(query_idx)\n    void execute(function<void(int)>\
    \ &f,int k=1){\n        for(auto [u,v]:seg[k]) uf.unite(u,v);\n        if(k<sz){\n\
    \            execute(f,2*k);\n            execute(f,2*k+1);\n        }\n     \
    \   else if(k-sz<q) f(k-sz);// query\n        for(auto [u,v]:seg[k]) uf.undo();\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: UnionFind/DynamicConnectivityOffline.cpp
  requiredBy: []
  timestamp: '2021-01-04 15:59:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: UnionFind/DynamicConnectivityOffline.cpp
layout: document
redirect_from:
- /library/UnionFind/DynamicConnectivityOffline.cpp
- /library/UnionFind/DynamicConnectivityOffline.cpp.html
title: UnionFind/DynamicConnectivityOffline.cpp
---

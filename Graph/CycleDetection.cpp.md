---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_CycleDetection.test.cpp
    title: test/yosupo_CycleDetection.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/CycleDetection.cpp\"\nvector<int> CycleDetection(vector<vector<int>>\
    \ &g){\n    int n=(int)g.size();\n    vector<int> check(n,0),cyc,pre(n,-1);\n\n\
    \    function<bool(int)> dfs=[&](int cur){\n        check[cur]=1;\n        for(auto\
    \ &to:g[cur]){\n            if(check[to]==0){\n                pre[to]=cur;\n\
    \                if(dfs(to)) return true;\n            }else if(check[to]==1){//\
    \ detect\n                int v=cur;\n                while(v!=to){\n        \
    \            cyc.push_back(v);\n                    v=pre[v];\n              \
    \  }\n                cyc.push_back(v);\n                return true;\n      \
    \      }\n        }\n        check[cur]=2;\n        return false;\n    };\n\n\
    \    rep(i,n){\n        if(check[i]==0){\n            if(dfs(i)){\n          \
    \      reverse(begin(cyc),end(cyc));\n                return cyc;\n          \
    \  }\n        }\n    }\n    return {};\n}\n"
  code: "vector<int> CycleDetection(vector<vector<int>> &g){\n    int n=(int)g.size();\n\
    \    vector<int> check(n,0),cyc,pre(n,-1);\n\n    function<bool(int)> dfs=[&](int\
    \ cur){\n        check[cur]=1;\n        for(auto &to:g[cur]){\n            if(check[to]==0){\n\
    \                pre[to]=cur;\n                if(dfs(to)) return true;\n    \
    \        }else if(check[to]==1){// detect\n                int v=cur;\n      \
    \          while(v!=to){\n                    cyc.push_back(v);\n            \
    \        v=pre[v];\n                }\n                cyc.push_back(v);\n   \
    \             return true;\n            }\n        }\n        check[cur]=2;\n\
    \        return false;\n    };\n\n    rep(i,n){\n        if(check[i]==0){\n  \
    \          if(dfs(i)){\n                reverse(begin(cyc),end(cyc));\n      \
    \          return cyc;\n            }\n        }\n    }\n    return {};\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/CycleDetection.cpp
  requiredBy: []
  timestamp: '2021-01-16 20:39:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_CycleDetection.test.cpp
documentation_of: Graph/CycleDetection.cpp
layout: document
redirect_from:
- /library/Graph/CycleDetection.cpp
- /library/Graph/CycleDetection.cpp.html
title: Graph/CycleDetection.cpp
---

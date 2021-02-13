---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki5125.test.cpp
    title: test/yuki5125.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Other/CyclePartition.cpp\"\n// 0-indexed parmutation only\n\
    vector<vector<int>> cycle_partition(const vector<int> &p){\n    int n=p.size();\n\
    \    vector<vector<int>> ret;\n    vector<bool> check(n,false);\n    rep(i,n)if(!check[p[i]]){\n\
    \        vector<int> v;\n        int pos=p[i];\n        v.push_back(i);\n    \
    \    check[i]=true;\n        while(pos!=i){\n            v.push_back(pos);\n \
    \           check[pos]=true;\n            pos=p[pos];\n        }\n        ret.push_back(v);\n\
    \    }\n    return ret;\n}\n"
  code: "// 0-indexed parmutation only\nvector<vector<int>> cycle_partition(const\
    \ vector<int> &p){\n    int n=p.size();\n    vector<vector<int>> ret;\n    vector<bool>\
    \ check(n,false);\n    rep(i,n)if(!check[p[i]]){\n        vector<int> v;\n   \
    \     int pos=p[i];\n        v.push_back(i);\n        check[i]=true;\n       \
    \ while(pos!=i){\n            v.push_back(pos);\n            check[pos]=true;\n\
    \            pos=p[pos];\n        }\n        ret.push_back(v);\n    }\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Other/CyclePartition.cpp
  requiredBy: []
  timestamp: '2021-02-14 02:21:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki5125.test.cpp
documentation_of: Other/CyclePartition.cpp
layout: document
redirect_from:
- /library/Other/CyclePartition.cpp
- /library/Other/CyclePartition.cpp.html
title: Other/CyclePartition.cpp
---

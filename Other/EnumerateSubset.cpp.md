---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_1379.test.cpp
    title: test/AOJ_1379.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Other/EnumerateSubset.cpp\"\nvector<int> enumerate_subset(int\
    \ bit,bool include_bit_empty=false){\n    vector<int> ret;\n    int subset=(bit-1)&bit;\n\
    \    do{\n        ret.push_back(subset);\n        subset=(subset-1)&bit;\n   \
    \ }while(subset!=0);\n    if(include_bit_empty){\n        ret.push_back(0);\n\
    \        if(0!=bit) ret.push_back(bit);\n    }\n    return ret;\n}\n"
  code: "vector<int> enumerate_subset(int bit,bool include_bit_empty=false){\n   \
    \ vector<int> ret;\n    int subset=(bit-1)&bit;\n    do{\n        ret.push_back(subset);\n\
    \        subset=(subset-1)&bit;\n    }while(subset!=0);\n    if(include_bit_empty){\n\
    \        ret.push_back(0);\n        if(0!=bit) ret.push_back(bit);\n    }\n  \
    \  return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Other/EnumerateSubset.cpp
  requiredBy: []
  timestamp: '2021-03-16 21:31:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_1379.test.cpp
documentation_of: Other/EnumerateSubset.cpp
layout: document
redirect_from:
- /library/Other/EnumerateSubset.cpp
- /library/Other/EnumerateSubset.cpp.html
title: Other/EnumerateSubset.cpp
---

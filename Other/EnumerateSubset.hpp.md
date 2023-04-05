---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_1379.test.cpp
    title: test/AOJ_1379.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Other/EnumerateSubset.hpp\"\nvector<int> enumerate_subset(int\
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
  path: Other/EnumerateSubset.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_1379.test.cpp
documentation_of: Other/EnumerateSubset.hpp
layout: document
title: "\u90E8\u5206\u96C6\u5408\u306E\u5217\u6319 (Enumerate Subset)"
---

## 概要  
bitの立っている箇所を集合の要素として，その集合の部分集合を列挙して返す．  
つまり，2進表記でbit=11001と表せるとき，  
返すのは{11001, 11000, 10001, 10000, 01001, 01000, 00001, 00000}である．  

有名な事実として，N個の集合の全ての部分集合において部分集合を列挙，つまり  
for i=0 to (1<<N)-1  
  EnumerateSubset(i)  
をすると，計算量はO(3^N)である．

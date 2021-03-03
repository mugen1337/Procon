---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_ALDS1_5_D.test.cpp
    title: test/AOJ_ALDS1_5_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/InversionNumber.cpp\"\ntemplate<typename T>\nlong long\
    \ InversionNumber(vector<T> v){\n    vector<T> ord=v;\n    sort(begin(ord),end(ord));\n\
    \    ord.erase(unique(begin(ord),end(ord)),end(ord));\n    vector<long long> bit(ord.size()+1,0);\n\
    \    long long ret=0;\n    for(int i=0;i<(int)v.size();i++){\n        int p=lower_bound(begin(ord),end(ord),v[i])-begin(ord)+1;\n\
    \        for(int j=p;j;j-=(j&-j)) ret-=bit[j];\n        for(int j=p;j<=(int)ord.size();j+=(j&-j))\
    \ bit[j]+=1;\n        ret+=i;\n    } \n    return ret;\n}\n"
  code: "template<typename T>\nlong long InversionNumber(vector<T> v){\n    vector<T>\
    \ ord=v;\n    sort(begin(ord),end(ord));\n    ord.erase(unique(begin(ord),end(ord)),end(ord));\n\
    \    vector<long long> bit(ord.size()+1,0);\n    long long ret=0;\n    for(int\
    \ i=0;i<(int)v.size();i++){\n        int p=lower_bound(begin(ord),end(ord),v[i])-begin(ord)+1;\n\
    \        for(int j=p;j;j-=(j&-j)) ret-=bit[j];\n        for(int j=p;j<=(int)ord.size();j+=(j&-j))\
    \ bit[j]+=1;\n        ret+=i;\n    } \n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/InversionNumber.cpp
  requiredBy: []
  timestamp: '2021-02-01 03:28:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_ALDS1_5_D.test.cpp
documentation_of: DP/InversionNumber.cpp
layout: document
title: "Inversion Number (\u8EE2\u5012\u6570)"
---

# 概要  
転倒数を返す  
中でBinary Indexed Treeの処理をしているだけ  
配列の長さをNとしたとき，O(NlogN)  

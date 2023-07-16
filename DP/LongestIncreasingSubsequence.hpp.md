---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki3784.test.cpp
    title: test/yuki3784.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/LongestIncreasingSubsequence.hpp\"\ntemplate<typename\
    \ T>\nint LongestIncreasingSubsequence(vector<T> v,bool strict=true){\n    vector<T>\
    \ lis;\n    for(auto &x:v){\n        typename vector<T>::iterator ite;\n     \
    \   if(strict) ite=lower_bound(begin(lis),end(lis),x);\n        else       ite=upper_bound(begin(lis),end(lis),x);\n\
    \        if(ite==end(lis)) lis.push_back(x);\n        else              *ite=x;\n\
    \    }\n    return int(lis.size());\n}\n"
  code: "template<typename T>\nint LongestIncreasingSubsequence(vector<T> v,bool strict=true){\n\
    \    vector<T> lis;\n    for(auto &x:v){\n        typename vector<T>::iterator\
    \ ite;\n        if(strict) ite=lower_bound(begin(lis),end(lis),x);\n        else\
    \       ite=upper_bound(begin(lis),end(lis),x);\n        if(ite==end(lis)) lis.push_back(x);\n\
    \        else              *ite=x;\n    }\n    return int(lis.size());\n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/LongestIncreasingSubsequence.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki3784.test.cpp
documentation_of: DP/LongestIncreasingSubsequence.hpp
layout: document
title: "Longest Increasing Subsequence (\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\
  )"
---

## 概要  
最長増加列の長さを返す．

## 計算量  
配列の長さをNとすると  
O(NlogN)

## tips  
- 最長増加列の数え上げ : https://yukicoder.me/problems/no/992  

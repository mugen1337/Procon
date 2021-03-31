---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/LongestIncreasingSubsequence.cpp\"\ntemplate<typename\
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
  path: DP/LongestIncreasingSubsequence.cpp
  requiredBy: []
  timestamp: '2021-03-31 19:57:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/LongestIncreasingSubsequence.cpp
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

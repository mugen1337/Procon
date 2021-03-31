---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki3784.test.cpp
    title: test/yuki3784.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki3784.test.cpp
documentation_of: DP/LongestIncreasingSubsequence.cpp
layout: document
redirect_from:
- /library/DP/LongestIncreasingSubsequence.cpp
- /library/DP/LongestIncreasingSubsequence.cpp.html
title: DP/LongestIncreasingSubsequence.cpp
---

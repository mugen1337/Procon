---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_ALDS1_10_c.test.cpp
    title: test/AOJ_ALDS1_10_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/LongestCommonSubsequence.hpp\"\ntemplate<typename S>\n\
    S LongestCommonSubsequence(S a,S b){\n    int n=(int)a.size(),m=(int)b.size();\n\
    \    vector<vector<int>> dp(n+1,vector<int>(m+1,0)),pre(n+1,vector<int>(m+1,-1));\n\
    \    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++){\n        if(i<n and j<m and a[i]==b[j]){\n\
    \            if(chmax(dp[i+1][j+1],dp[i][j]+1)) pre[i+1][j+1]=1;\n        }\n\
    \        if(i<n)if(chmax(dp[i+1][j],dp[i][j])) pre[i+1][j]=2;\n        if(j<m)if(chmax(dp[i][j+1],dp[i][j]))\
    \ pre[i][j+1]=3;\n    }\n\n    S ret;\n    int i=n,j=m;\n    while(i and j and\
    \ pre[i][j]>0){\n        if(pre[i][j]==1){\n            i--,j--;\n           \
    \ ret.push_back(a[i]);\n        }\n        else if(pre[i][j]==2) i--;\n      \
    \  else if(pre[i][j]==3) j--;\n    }\n\n    reverse(begin(ret),end(ret));\n  \
    \  return ret;\n}\n"
  code: "template<typename S>\nS LongestCommonSubsequence(S a,S b){\n    int n=(int)a.size(),m=(int)b.size();\n\
    \    vector<vector<int>> dp(n+1,vector<int>(m+1,0)),pre(n+1,vector<int>(m+1,-1));\n\
    \    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++){\n        if(i<n and j<m and a[i]==b[j]){\n\
    \            if(chmax(dp[i+1][j+1],dp[i][j]+1)) pre[i+1][j+1]=1;\n        }\n\
    \        if(i<n)if(chmax(dp[i+1][j],dp[i][j])) pre[i+1][j]=2;\n        if(j<m)if(chmax(dp[i][j+1],dp[i][j]))\
    \ pre[i][j+1]=3;\n    }\n\n    S ret;\n    int i=n,j=m;\n    while(i and j and\
    \ pre[i][j]>0){\n        if(pre[i][j]==1){\n            i--,j--;\n           \
    \ ret.push_back(a[i]);\n        }\n        else if(pre[i][j]==2) i--;\n      \
    \  else if(pre[i][j]==3) j--;\n    }\n\n    reverse(begin(ret),end(ret));\n  \
    \  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/LongestCommonSubsequence.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_ALDS1_10_c.test.cpp
documentation_of: DP/LongestCommonSubsequence.hpp
layout: document
title: "Longest Common Subsequence (\u6700\u9577\u5171\u901A\u90E8\u5206\u5217)"
---

## 概要  
最長共通部分列を求める．復元して返す．  

## 計算量  
列A, 列Bに対し，O ( |A| * |B| )

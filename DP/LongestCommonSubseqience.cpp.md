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
  bundledCode: "#line 1 \"DP/LongestCommonSubseqience.cpp\"\ntemplate<typename S>\n\
    S LongestCommonSubsecence(S a,S b){\n    int n=(int)a.size(),m=(int)b.size();\n\
    \    vector<vector<int>> dp(n+1,vector<int>(m+1,0)),pre(n+1,vector<int>(m+1,-1));\n\
    \    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++){\n        if(i<n and j<m and a[i]==b[j]){\n\
    \            if(chmax(dp[i+1][j+1],dp[i][j]+1)) pre[i+1][j+1]=1;\n        }\n\
    \        if(i<n)if(chmax(dp[i+1][j],dp[i][j])) pre[i+1][j]=2;\n        if(j<m)if(chmax(dp[i][j+1],dp[i][j]))\
    \ pre[i][j+1]=3;\n    }\n\n    S ret;\n    int i=n,j=m;\n    while(i and j and\
    \ pre[i][j]>0){\n        if(pre[i][j]==1){\n            i--,j--;\n           \
    \ ret.push_back(a[i]);\n        }\n        else if(pre[i][j]==2) i--;\n      \
    \  else if(pre[i][j]==3) j--;\n    }\n\n    reverse(begin(ret),end(ret));\n  \
    \  return ret;\n}\n"
  code: "template<typename S>\nS LongestCommonSubsecence(S a,S b){\n    int n=(int)a.size(),m=(int)b.size();\n\
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
  path: DP/LongestCommonSubseqience.cpp
  requiredBy: []
  timestamp: '2021-03-28 16:18:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/LongestCommonSubseqience.cpp
layout: document
redirect_from:
- /library/DP/LongestCommonSubseqience.cpp
- /library/DP/LongestCommonSubseqience.cpp.html
title: DP/LongestCommonSubseqience.cpp
---

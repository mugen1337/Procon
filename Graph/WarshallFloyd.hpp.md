---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki5764.test.cpp
    title: test/yuki5764.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/WarshallFloyd.hpp\"\ntemplate<typename T>\nvector<vector<T>>\
    \ WarshallFloyd(vector<vector<T>> mat, T inf=1000000100){\n    int n=(int)mat.size();\n\
    \    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)\n    if(mat[i][k]<inf\
    \ and mat[k][j]<inf) mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);\n    return\
    \ mat;\n}\n"
  code: "template<typename T>\nvector<vector<T>> WarshallFloyd(vector<vector<T>> mat,\
    \ T inf=1000000100){\n    int n=(int)mat.size();\n    for(int k=0;k<n;k++)for(int\
    \ i=0;i<n;i++)for(int j=0;j<n;j++)\n    if(mat[i][k]<inf and mat[k][j]<inf) mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);\n\
    \    return mat;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki5764.test.cpp
documentation_of: Graph/WarshallFloyd.hpp
layout: document
redirect_from:
- /library/Graph/WarshallFloyd.hpp
- /library/Graph/WarshallFloyd.hpp.html
title: Graph/WarshallFloyd.hpp
---

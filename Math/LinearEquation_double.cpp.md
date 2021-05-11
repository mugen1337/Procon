---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/PolynomialRestore_double.cpp
    title: Math/PolynomialRestore_double.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/LinearEquation_double.cpp\"\n// solve A * X = Y\n//\
    \ T : floating point\ntemplate<typename T>\nvector<T> LinearEquation(vector<vector<T>>\
    \ A,vector<T> Y,T EPS=1e-6){\n    int n=(int)A.size(),m=(int)A[0].size();\n  \
    \  for(int i=0;i<n;i++) A[i].push_back(Y[i]);\n\n    int rank=0;\n    for(int\
    \ j=0;j<m;j++){\n        int p=-1;\n        T mx=EPS;\n        for(int i=rank;i<n;i++)if(chmax(mx,abs(A[i][j])))\
    \ p=i;\n        if(p==-1) continue;\n\n        swap(A[p],A[rank]);\n        T\
    \ t=A[rank][j];\n        for(int k=0;k<=m;k++) A[rank][k]/=t;\n        for(int\
    \ i=0;i<n;i++){\n            if(i==rank) continue;\n            T s=A[i][j];\n\
    \            for(int k=0;k<=m;k++) A[i][k]-=s*A[rank][k];\n        }\n       \
    \ rank++;\n    }\n\n    vector<T> ret;\n    for(int i=rank;i<n;i++)if(abs(A[i][m])>EPS)\
    \ return ret;\n    ret.assign(m,0);\n    for(int i=0;i<rank;i++) ret[i]=A[i][m];\n\
    \    return ret;\n}\n"
  code: "// solve A * X = Y\n// T : floating point\ntemplate<typename T>\nvector<T>\
    \ LinearEquation(vector<vector<T>> A,vector<T> Y,T EPS=1e-6){\n    int n=(int)A.size(),m=(int)A[0].size();\n\
    \    for(int i=0;i<n;i++) A[i].push_back(Y[i]);\n\n    int rank=0;\n    for(int\
    \ j=0;j<m;j++){\n        int p=-1;\n        T mx=EPS;\n        for(int i=rank;i<n;i++)if(chmax(mx,abs(A[i][j])))\
    \ p=i;\n        if(p==-1) continue;\n\n        swap(A[p],A[rank]);\n        T\
    \ t=A[rank][j];\n        for(int k=0;k<=m;k++) A[rank][k]/=t;\n        for(int\
    \ i=0;i<n;i++){\n            if(i==rank) continue;\n            T s=A[i][j];\n\
    \            for(int k=0;k<=m;k++) A[i][k]-=s*A[rank][k];\n        }\n       \
    \ rank++;\n    }\n\n    vector<T> ret;\n    for(int i=rank;i<n;i++)if(abs(A[i][m])>EPS)\
    \ return ret;\n    ret.assign(m,0);\n    for(int i=0;i<rank;i++) ret[i]=A[i][m];\n\
    \    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/LinearEquation_double.cpp
  requiredBy:
  - Math/PolynomialRestore_double.cpp
  timestamp: '2021-05-11 22:09:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/LinearEquation_double.cpp
layout: document
redirect_from:
- /library/Math/LinearEquation_double.cpp
- /library/Math/LinearEquation_double.cpp.html
title: Math/LinearEquation_double.cpp
---

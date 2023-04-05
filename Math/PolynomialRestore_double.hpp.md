---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/LinearEquation_double.hpp
    title: Math/LinearEquation_double.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/LinearEquation_double.hpp\"\n// solve A * X = Y\n//\
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
    \    return ret;\n}\n#line 2 \"Math/PolynomialRestore_double.hpp\"\n\n// f(x)\
    \ = a_0 + a_1 * x .. .a_d * x^d\n// O(d ^ 3)\ntemplate<typename T>\nvector<T>\
    \ PolynomialRestore(vector<T> x,vector<T> y,int d,T EPS=1e-6){\n    vector<vector<T>>\
    \ M(x.size(),vector<T>(d+1));\n    for(int i=0;i<(int)x.size();i++){\n       \
    \ T p=1;\n        for(int j=0;j<=d;j++){\n            M[i][j]=p;\n           \
    \ p*=x[i];\n        }\n    }\n    auto ret=LinearEquation(M,y,EPS);\n    return\
    \ ret;\n}\n"
  code: "#include \"./LinearEquation_double.hpp\"\n\n// f(x) = a_0 + a_1 * x .. .a_d\
    \ * x^d\n// O(d ^ 3)\ntemplate<typename T>\nvector<T> PolynomialRestore(vector<T>\
    \ x,vector<T> y,int d,T EPS=1e-6){\n    vector<vector<T>> M(x.size(),vector<T>(d+1));\n\
    \    for(int i=0;i<(int)x.size();i++){\n        T p=1;\n        for(int j=0;j<=d;j++){\n\
    \            M[i][j]=p;\n            p*=x[i];\n        }\n    }\n    auto ret=LinearEquation(M,y,EPS);\n\
    \    return ret;\n}\n"
  dependsOn:
  - Math/LinearEquation_double.hpp
  isVerificationFile: false
  path: Math/PolynomialRestore_double.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/PolynomialRestore_double.hpp
layout: document
redirect_from:
- /library/Math/PolynomialRestore_double.hpp
- /library/Math/PolynomialRestore_double.hpp.html
title: Math/PolynomialRestore_double.hpp
---

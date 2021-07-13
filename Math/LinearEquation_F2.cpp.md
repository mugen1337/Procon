---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://drken1215.hatenablog.com/entry/2019/03/20/202800
  bundledCode: "#line 1 \"Math/LinearEquation_F2.cpp\"\n// mat * vec = vec\n// A *\
    \ x = b\n// ans, rank\n// ans is empty if ans doesn't exist\n// https://drken1215.hatenablog.com/entry/2019/03/20/202800\n\
    pair<vector<int>,int> LinearEquationF2(vector<vector<int>> A,vector<int> b){\n\
    \    int rank=0;\n    int H=(int)A.size(),W=(int)A[0].size();\n    for(int j=0;j<W;j++){\n\
    \        int p=-1;\n        for(int i=rank;i<H;i++){\n            if(A[i][j]){\n\
    \                p=i;\n                break;\n            }\n        }\n    \
    \    if(p==-1) continue;\n        swap(A[p],A[rank]);\n        swap(b[p],b[rank]);\n\
    \n        for(int i=0;i<H;i++)if(i!=rank){\n            if(A[i][j]){\n       \
    \         for(int k=0;k<W;k++) A[i][k]^=A[rank][k];\n                b[i]^=b[rank];\n\
    \            }\n        }\n        rank++;\n    }\n\n    for(int i=rank;i<H;i++)\
    \ if(b[i]) return make_pair(vector<int>{},-1);\n\n    return make_pair(b,rank);\n\
    }\n"
  code: "// mat * vec = vec\n// A * x = b\n// ans, rank\n// ans is empty if ans doesn't\
    \ exist\n// https://drken1215.hatenablog.com/entry/2019/03/20/202800\npair<vector<int>,int>\
    \ LinearEquationF2(vector<vector<int>> A,vector<int> b){\n    int rank=0;\n  \
    \  int H=(int)A.size(),W=(int)A[0].size();\n    for(int j=0;j<W;j++){\n      \
    \  int p=-1;\n        for(int i=rank;i<H;i++){\n            if(A[i][j]){\n   \
    \             p=i;\n                break;\n            }\n        }\n       \
    \ if(p==-1) continue;\n        swap(A[p],A[rank]);\n        swap(b[p],b[rank]);\n\
    \n        for(int i=0;i<H;i++)if(i!=rank){\n            if(A[i][j]){\n       \
    \         for(int k=0;k<W;k++) A[i][k]^=A[rank][k];\n                b[i]^=b[rank];\n\
    \            }\n        }\n        rank++;\n    }\n\n    for(int i=rank;i<H;i++)\
    \ if(b[i]) return make_pair(vector<int>{},-1);\n\n    return make_pair(b,rank);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Math/LinearEquation_F2.cpp
  requiredBy: []
  timestamp: '2021-07-13 22:36:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/LinearEquation_F2.cpp
layout: document
redirect_from:
- /library/Math/LinearEquation_F2.cpp
- /library/Math/LinearEquation_F2.cpp.html
title: Math/LinearEquation_F2.cpp
---

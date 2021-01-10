---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Bitwise_And_Convolution.test.cpp
    title: test/yosupo_Bitwise_And_Convolution.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/AndConvolution.cpp\"\n// ret_k = sum a_i * b_j, i&j=k\
    \ \ntemplate<typename T>\nvector<T> AndConvolution(vector<T> a,vector<T> b){\n\
    \    assert(a.size()==b.size());\n    int n=(int)a.size();\n    vector<T> ret(n);\n\
    \    // FWT\n    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n        if((i&j)==0)\
    \ a[j]+=a[j|i],b[j]+=b[j|i];\n    }\n    for(int i=0;i<n;i++) ret[i]=a[i]*b[i];\n\
    \    // IFWT\n    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n        if((i&j)==0)\
    \ ret[j]-=ret[j|i];\n    }\n    return ret;\n}\n"
  code: "// ret_k = sum a_i * b_j, i&j=k \ntemplate<typename T>\nvector<T> AndConvolution(vector<T>\
    \ a,vector<T> b){\n    assert(a.size()==b.size());\n    int n=(int)a.size();\n\
    \    vector<T> ret(n);\n    // FWT\n    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n\
    \        if((i&j)==0) a[j]+=a[j|i],b[j]+=b[j|i];\n    }\n    for(int i=0;i<n;i++)\
    \ ret[i]=a[i]*b[i];\n    // IFWT\n    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n\
    \        if((i&j)==0) ret[j]-=ret[j|i];\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/AndConvolution.cpp
  requiredBy: []
  timestamp: '2021-01-10 13:03:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_Bitwise_And_Convolution.test.cpp
documentation_of: Math/AndConvolution.cpp
layout: document
redirect_from:
- /library/Math/AndConvolution.cpp
- /library/Math/AndConvolution.cpp.html
title: Math/AndConvolution.cpp
---

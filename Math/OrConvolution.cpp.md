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
  bundledCode: "#line 1 \"Math/OrConvolution.cpp\"\n// ret_k = sum a_i * b_j, i|j=k\
    \ \ntemplate<typename T>\nvector<T> OrConvolution(vector<T> a,vector<T> b){\n\
    \    assert(a.size()==b.size());\n    int n=(int)a.size();\n    vector<T> ret(n);\n\
    \    // FWT\n    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n        if((i&j)==0)\
    \ a[i|j]+=a[j],b[i|j]+=b[j];\n    }\n    for(int i=0;i<n;i++) ret[i]=a[i]*b[i];\n\
    \    // IFWT\n    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n        if((i&j)==0)\
    \ ret[j|i]-=ret[j];\n    }\n    return ret;\n}\n"
  code: "// ret_k = sum a_i * b_j, i|j=k \ntemplate<typename T>\nvector<T> OrConvolution(vector<T>\
    \ a,vector<T> b){\n    assert(a.size()==b.size());\n    int n=(int)a.size();\n\
    \    vector<T> ret(n);\n    // FWT\n    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n\
    \        if((i&j)==0) a[i|j]+=a[j],b[i|j]+=b[j];\n    }\n    for(int i=0;i<n;i++)\
    \ ret[i]=a[i]*b[i];\n    // IFWT\n    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n\
    \        if((i&j)==0) ret[j|i]-=ret[j];\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/OrConvolution.cpp
  requiredBy: []
  timestamp: '2021-01-10 13:03:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/OrConvolution.cpp
layout: document
redirect_from:
- /library/Math/OrConvolution.cpp
- /library/Math/OrConvolution.cpp.html
title: Math/OrConvolution.cpp
---

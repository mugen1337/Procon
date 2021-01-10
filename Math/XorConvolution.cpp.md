---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/XorConvolution.cpp\"\n// ret_k = sum a_i * b_j, i^j=k\n\
    template<typename T>\nvector<T> XorConvolution(vector<T> a,vector<T> b){\n   \
    \ assert(a.size()==b.size());\n    int n=(int)a.size();\n    vector<T> ret(n);\n\
    \    // FWT\n    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n        if((i&j)==0){\n\
    \            {\n                T x=a[j],y=a[j|i];\n                a[j]=x+y,a[j|i]=x-y;\n\
    \            }\n            {\n                T x=b[j],y=b[j|i];\n          \
    \      b[j]=x+y,b[j|i]=x-y;\n            }\n        }\n    }\n    for(int i=0;i<n;i++)\
    \ ret[i]=a[i]*b[i];\n    // IFWT\n    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n\
    \        if((i&j)==0){\n            T x=ret[j],y=ret[j|i];\n            ret[j]=(x+y)/2,ret[j|i]=(x-y)/2;\n\
    \        }\n    }\n    return ret;\n}\n"
  code: "// ret_k = sum a_i * b_j, i^j=k\ntemplate<typename T>\nvector<T> XorConvolution(vector<T>\
    \ a,vector<T> b){\n    assert(a.size()==b.size());\n    int n=(int)a.size();\n\
    \    vector<T> ret(n);\n    // FWT\n    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n\
    \        if((i&j)==0){\n            {\n                T x=a[j],y=a[j|i];\n  \
    \              a[j]=x+y,a[j|i]=x-y;\n            }\n            {\n          \
    \      T x=b[j],y=b[j|i];\n                b[j]=x+y,b[j|i]=x-y;\n            }\n\
    \        }\n    }\n    for(int i=0;i<n;i++) ret[i]=a[i]*b[i];\n    // IFWT\n \
    \   for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n        if((i&j)==0){\n     \
    \       T x=ret[j],y=ret[j|i];\n            ret[j]=(x+y)/2,ret[j|i]=(x-y)/2;\n\
    \        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/XorConvolution.cpp
  requiredBy: []
  timestamp: '2021-01-10 12:53:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/XorConvolution.cpp
layout: document
redirect_from:
- /library/Math/XorConvolution.cpp
- /library/Math/XorConvolution.cpp.html
title: Math/XorConvolution.cpp
---

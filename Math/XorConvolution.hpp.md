---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_Bitwise_Xor_Convolution.test.cpp
    title: test/yosupo_Bitwise_Xor_Convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/XorConvolution.hpp\"\n// ret_k = sum a_i * b_j, i^j=k\n\
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
  path: Math/XorConvolution.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_Bitwise_Xor_Convolution.test.cpp
documentation_of: Math/XorConvolution.hpp
layout: document
redirect_from:
- /library/Math/XorConvolution.hpp
- /library/Math/XorConvolution.hpp.html
title: Math/XorConvolution.hpp
---

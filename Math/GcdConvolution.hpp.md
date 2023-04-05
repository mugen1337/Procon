---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://noshi91.hatenablog.com/entry/2019/09/23/002445
  bundledCode: "#line 1 \"Math/GcdConvolution.hpp\"\n// c[k] = sum a[i] * a[j], gcd(i,\
    \ j) == k\n// ref : https://noshi91.hatenablog.com/entry/2019/09/23/002445\ntemplate<typename\
    \ T>\nvector<T> gcd_convolution(vector<T> a,vector<T> b){\n   auto f=[&](vector<T>\
    \ &v){ // in-place\n       int n=(int)v.size();\n       for(int k=1;k<n;k++)for(int\
    \ i=k+k;i<n;i+=k) v[k]+=v[i];\n       return ;\n   };\n   auto f_inv=[&](vector<T>\
    \ &v){ // in-place\n       int n=(int)v.size();\n       for(int k=n-1;k>0;k--)for(int\
    \ i=k+k;i<n;i+=k) v[k]-=v[i];\n   };\n \n   int n=(int)max(a.size(),b.size());\n\
    \   a.resize(n,0);b.resize(n,0);\n   f(a);f(b);\n   vector<T> ret(n,0);\n   rep(i,n)\
    \ ret[i]=a[i]*b[i];\n   f_inv(ret);\n   return ret;\n}\n"
  code: "// c[k] = sum a[i] * a[j], gcd(i, j) == k\n// ref : https://noshi91.hatenablog.com/entry/2019/09/23/002445\n\
    template<typename T>\nvector<T> gcd_convolution(vector<T> a,vector<T> b){\n  \
    \ auto f=[&](vector<T> &v){ // in-place\n       int n=(int)v.size();\n       for(int\
    \ k=1;k<n;k++)for(int i=k+k;i<n;i+=k) v[k]+=v[i];\n       return ;\n   };\n  \
    \ auto f_inv=[&](vector<T> &v){ // in-place\n       int n=(int)v.size();\n   \
    \    for(int k=n-1;k>0;k--)for(int i=k+k;i<n;i+=k) v[k]-=v[i];\n   };\n \n   int\
    \ n=(int)max(a.size(),b.size());\n   a.resize(n,0);b.resize(n,0);\n   f(a);f(b);\n\
    \   vector<T> ret(n,0);\n   rep(i,n) ret[i]=a[i]*b[i];\n   f_inv(ret);\n   return\
    \ ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/GcdConvolution.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/GcdConvolution.hpp
layout: document
redirect_from:
- /library/Math/GcdConvolution.hpp
- /library/Math/GcdConvolution.hpp.html
title: Math/GcdConvolution.hpp
---

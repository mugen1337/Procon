---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/BinaryBasis.hpp\"\ntemplate<typename T=int>\nstruct\
    \ BinaryBasis{\n    vector<T> base;\n    \n    BinaryBasis(){}\n\n    bool add(T\
    \ bit){\n        for(auto &x:base) chmin(bit,bit^x);\n        if(bit){\n     \
    \       base.push_back(bit);\n            return true;\n        }\n        return\
    \ false;\n    }\n\n    T solve(T r){\n        T ret=0;\n        for(auto &x:base)if(chmin(r,r^x))\
    \ ret^=x;\n        if(r) return -1;\n        return ret;\n    }\n\n    void normalize(){\n\
    \        for(int i=(int)base.size()-1;i>=0;i--)\n            for(int j=i-1;j>=0;j--)\
    \ base[i]=min(base[i],base[i]^base[j]);\n    }\n\n    // check normalized this\
    \ and r\n    bool eq(BinaryBasis<T> &r){\n        return base==r.base;\n    }\n\
    \n    int size(){\n        return (int)base.size();\n    }\n};\n"
  code: "template<typename T=int>\nstruct BinaryBasis{\n    vector<T> base;\n    \n\
    \    BinaryBasis(){}\n\n    bool add(T bit){\n        for(auto &x:base) chmin(bit,bit^x);\n\
    \        if(bit){\n            base.push_back(bit);\n            return true;\n\
    \        }\n        return false;\n    }\n\n    T solve(T r){\n        T ret=0;\n\
    \        for(auto &x:base)if(chmin(r,r^x)) ret^=x;\n        if(r) return -1;\n\
    \        return ret;\n    }\n\n    void normalize(){\n        for(int i=(int)base.size()-1;i>=0;i--)\n\
    \            for(int j=i-1;j>=0;j--) base[i]=min(base[i],base[i]^base[j]);\n \
    \   }\n\n    // check normalized this and r\n    bool eq(BinaryBasis<T> &r){\n\
    \        return base==r.base;\n    }\n\n    int size(){\n        return (int)base.size();\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/BinaryBasis.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/BinaryBasis.hpp
layout: document
redirect_from:
- /library/Math/BinaryBasis.hpp
- /library/Math/BinaryBasis.hpp.html
title: Math/BinaryBasis.hpp
---

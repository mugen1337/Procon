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
  bundledCode: "#line 1 \"Math/FactorizeQueries.hpp\"\n// Precomputation : O(M log\
    \ (log M)) (M : MAX)\n// Factorize Query : O(log N) (N<=MAX)\ntemplate<int MAX>\n\
    struct FactorizeQueries{\n    vector<int> min_factor;\n    \n    FactorizeQueries(){\n\
    \        min_factor.resize(MAX+1);\n        iota(begin(min_factor),end(min_factor),0);\n\
    \        for(int i=2;i*i<=MAX;i++){\n            if(min_factor[i]==i)\n      \
    \          for(int j=i+i;j<=MAX;j+=i) min_factor[j]=min(min_factor[j],i);\n  \
    \      }\n    }\n    \n    vector<int> Factorize(int x){\n        assert(x<=MAX);\n\
    \        vector<int> ret;\n        for(;x>1;x/=min_factor[x]) ret.push_back(min_factor[x]);\n\
    \        return ret;\n    }\n};\n"
  code: "// Precomputation : O(M log (log M)) (M : MAX)\n// Factorize Query : O(log\
    \ N) (N<=MAX)\ntemplate<int MAX>\nstruct FactorizeQueries{\n    vector<int> min_factor;\n\
    \    \n    FactorizeQueries(){\n        min_factor.resize(MAX+1);\n        iota(begin(min_factor),end(min_factor),0);\n\
    \        for(int i=2;i*i<=MAX;i++){\n            if(min_factor[i]==i)\n      \
    \          for(int j=i+i;j<=MAX;j+=i) min_factor[j]=min(min_factor[j],i);\n  \
    \      }\n    }\n    \n    vector<int> Factorize(int x){\n        assert(x<=MAX);\n\
    \        vector<int> ret;\n        for(;x>1;x/=min_factor[x]) ret.push_back(min_factor[x]);\n\
    \        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/FactorizeQueries.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/FactorizeQueries.hpp
layout: document
title: "osa_k\u6CD5 (Factorization Queries)"
---

## 概要  
エラトステネスの篩の要領で前処理をしておくと素因数分解を高速にできる場合がある．  


## 計算量  
Mを素因数分解した最大の数とし，Nを素因数分解する時．  
- 前処理 : O(M log(logM))  
- クエリ : O(logN)  

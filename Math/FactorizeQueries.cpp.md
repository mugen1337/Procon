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
  bundledCode: "#line 1 \"Math/FactorizeQueries.cpp\"\n// Precomputation : O(M log\
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
  path: Math/FactorizeQueries.cpp
  requiredBy: []
  timestamp: '2021-04-07 23:11:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/FactorizeQueries.cpp
layout: document
redirect_from:
- /library/Math/FactorizeQueries.cpp
- /library/Math/FactorizeQueries.cpp.html
title: Math/FactorizeQueries.cpp
---

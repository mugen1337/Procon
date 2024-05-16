---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yuki2577.test.cpp
    title: test/yuki2577.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/RectangleUnion.hpp\"\ntemplate<typename T>\n\
    struct RectangleUnion{\n    private:\n    map<T,T> mp;\n\n    public:\n    T S;\n\
    \    \n    RectangleUnion():S(0){\n        const T inf=numeric_limits<T>::max()/2;\n\
    \        mp[0]=inf;\n        mp[inf]=0;\n    }\n\n    void add(T x,T y){\n   \
    \     auto ite=mp.lower_bound(x);\n        if(ite->second>=y) return ;\n     \
    \   T lw=ite->second;\n        S+=(y-lw)*x;\n        ite=prev(ite);\n        while(ite->second<=y){\n\
    \            S-=ite->first*(ite->second-lw);\n            lw=ite->second;\n  \
    \          ite=prev(mp.erase(ite));\n        }\n        S-=(ite->first)*(y-lw);\n\
    \        mp[x]=y;\n    }\n};\n"
  code: "template<typename T>\nstruct RectangleUnion{\n    private:\n    map<T,T>\
    \ mp;\n\n    public:\n    T S;\n    \n    RectangleUnion():S(0){\n        const\
    \ T inf=numeric_limits<T>::max()/2;\n        mp[0]=inf;\n        mp[inf]=0;\n\
    \    }\n\n    void add(T x,T y){\n        auto ite=mp.lower_bound(x);\n      \
    \  if(ite->second>=y) return ;\n        T lw=ite->second;\n        S+=(y-lw)*x;\n\
    \        ite=prev(ite);\n        while(ite->second<=y){\n            S-=ite->first*(ite->second-lw);\n\
    \            lw=ite->second;\n            ite=prev(mp.erase(ite));\n        }\n\
    \        S-=(ite->first)*(y-lw);\n        mp[x]=y;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RectangleUnion.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yuki2577.test.cpp
documentation_of: DataStructure/RectangleUnion.hpp
layout: document
redirect_from:
- /library/DataStructure/RectangleUnion.hpp
- /library/DataStructure/RectangleUnion.hpp.html
title: DataStructure/RectangleUnion.hpp
---

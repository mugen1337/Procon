---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki2577.test.cpp
    title: test/yuki2577.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/RectangleUnion.cpp\"\ntemplate<typename T>\n\
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
  path: DataStructure/RectangleUnion.cpp
  requiredBy: []
  timestamp: '2021-01-24 22:16:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki2577.test.cpp
documentation_of: DataStructure/RectangleUnion.cpp
layout: document
redirect_from:
- /library/DataStructure/RectangleUnion.cpp
- /library/DataStructure/RectangleUnion.cpp.html
title: DataStructure/RectangleUnion.cpp
---

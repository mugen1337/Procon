---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yuki2600.test.cpp
    title: test/yuki2600.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/AbsoluteSum.hpp\"\ntemplate<typename T>\n\
    struct AbsoluteSum{\n    multiset<T> L,R;\n    T min_f;\n    \n    AbsoluteSum():min_f(0){}\n\
    \n    // add |x-a|\n    void insert(T a){\n        if(L.empty() or R.empty()){\n\
    \            L.insert(a);\n            R.insert(a);\n            return ;\n  \
    \      }\n        T pl=*prev(end(L)),pr=*begin(R);\n        L.insert(a);\n   \
    \     R.insert(a);\n        if(pl<=a and a<=pr) return ;\n        // \u7AEF\u3092\
    swap\u3059\u308B\u3060\u3051\u3067\u3044\u3044\n        if(*prev(end(L))>*begin(R)){\n\
    \            T cl=*prev(end(L)),cr=*begin(R);\n            L.erase(L.find(cl));\n\
    \            R.erase(R.find(cr));\n            R.insert(cl);\n            L.insert(cr);\n\
    \        }\n        min_f+=std::min(abs(pl-a),abs(pr-a));\n        return ;\n\
    \    }\n\n    // erase |x-a|\n    void erase(T a){\n        if(L.find(a)!=end(L)\
    \ and R.find(a)!=end(R)){\n            L.erase(L.find(a));\n            R.erase(R.find(a));\n\
    \            return ;\n        }\n        if(L.find(a)!=end(L)){\n           \
    \ L.erase(L.find(a));\n            L.erase(L.find(a));\n            L.insert(*begin(R));\n\
    \            R.erase(begin(R));\n        }else{\n            R.erase(R.find(a));\n\
    \            R.erase(R.find(a));\n            R.insert(*prev(end(L)));\n     \
    \       L.erase(prev(end(L)));\n        }\n        T l=*prev(end(L)),r=*begin(R);\n\
    \        if(l<=a and a<=r) return ;\n        min_f-=std::min(abs(l-a),abs(r-a));\n\
    \        return ;\n    }\n\n    T min(){return min_f;}\n\n    T operator()(T x){\n\
    \        T ret=min_f;\n        for(const auto &a:L) ret+=max(a-x,T(0));\n    \
    \    for(const auto &b:R) ret+=max(x-b,T(0));\n        return ret;\n    }\n};\n"
  code: "template<typename T>\nstruct AbsoluteSum{\n    multiset<T> L,R;\n    T min_f;\n\
    \    \n    AbsoluteSum():min_f(0){}\n\n    // add |x-a|\n    void insert(T a){\n\
    \        if(L.empty() or R.empty()){\n            L.insert(a);\n            R.insert(a);\n\
    \            return ;\n        }\n        T pl=*prev(end(L)),pr=*begin(R);\n \
    \       L.insert(a);\n        R.insert(a);\n        if(pl<=a and a<=pr) return\
    \ ;\n        // \u7AEF\u3092swap\u3059\u308B\u3060\u3051\u3067\u3044\u3044\n \
    \       if(*prev(end(L))>*begin(R)){\n            T cl=*prev(end(L)),cr=*begin(R);\n\
    \            L.erase(L.find(cl));\n            R.erase(R.find(cr));\n        \
    \    R.insert(cl);\n            L.insert(cr);\n        }\n        min_f+=std::min(abs(pl-a),abs(pr-a));\n\
    \        return ;\n    }\n\n    // erase |x-a|\n    void erase(T a){\n       \
    \ if(L.find(a)!=end(L) and R.find(a)!=end(R)){\n            L.erase(L.find(a));\n\
    \            R.erase(R.find(a));\n            return ;\n        }\n        if(L.find(a)!=end(L)){\n\
    \            L.erase(L.find(a));\n            L.erase(L.find(a));\n          \
    \  L.insert(*begin(R));\n            R.erase(begin(R));\n        }else{\n    \
    \        R.erase(R.find(a));\n            R.erase(R.find(a));\n            R.insert(*prev(end(L)));\n\
    \            L.erase(prev(end(L)));\n        }\n        T l=*prev(end(L)),r=*begin(R);\n\
    \        if(l<=a and a<=r) return ;\n        min_f-=std::min(abs(l-a),abs(r-a));\n\
    \        return ;\n    }\n\n    T min(){return min_f;}\n\n    T operator()(T x){\n\
    \        T ret=min_f;\n        for(const auto &a:L) ret+=max(a-x,T(0));\n    \
    \    for(const auto &b:R) ret+=max(x-b,T(0));\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/AbsoluteSum.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yuki2600.test.cpp
documentation_of: DataStructure/AbsoluteSum.hpp
layout: document
redirect_from:
- /library/DataStructure/AbsoluteSum.hpp
- /library/DataStructure/AbsoluteSum.hpp.html
title: DataStructure/AbsoluteSum.hpp
---

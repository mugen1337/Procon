---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_queue_operate_all_composite.test.cpp
    title: test/yosupo_queue_operate_all_composite.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SlidingWindowAgregation.cpp\"\n// Monoid Sliding-Window-AGregation\n\
    template<typename Monoid>\nstruct SWAG{\n    using F=function<Monoid(Monoid,Monoid)>;\n\
    \    const F f;\n    const Monoid e;\n    stack<pair<Monoid,Monoid>> fr,ba;\n\
    \    SWAG(const F f,const Monoid &e):f(f),e(e){}\n    Monoid get(){\n        Monoid\
    \ a=fr.empty()?e:fr.top().second;\n        Monoid b=ba.empty()?e:ba.top().second;\n\
    \        return f(a,b);\n    }\n    void push(Monoid x){\n        if(ba.empty())\
    \ ba.push(make_pair(x,x));\n        else ba.push(make_pair(x,f(ba.top().second,x)));\n\
    \    }\n    void pop(){\n        if(empty()) return ;\n        if(!fr.empty())\
    \ fr.pop();\n        else{\n            while(!ba.empty()){\n                pair<Monoid,Monoid>\
    \ p=ba.top();ba.pop();\n                if(fr.empty()) fr.push(make_pair(p.first,p.first));\n\
    \                else fr.push(make_pair(p.first,f(p.first,fr.top().second)));\n\
    \            }\n            fr.pop();\n        }\n    }\n    size_t size(){\n\
    \        return fr.size()+ba.size();\n    }\n    bool empty(){\n        return\
    \ size()==0;\n    }\n};\n"
  code: "// Monoid Sliding-Window-AGregation\ntemplate<typename Monoid>\nstruct SWAG{\n\
    \    using F=function<Monoid(Monoid,Monoid)>;\n    const F f;\n    const Monoid\
    \ e;\n    stack<pair<Monoid,Monoid>> fr,ba;\n    SWAG(const F f,const Monoid &e):f(f),e(e){}\n\
    \    Monoid get(){\n        Monoid a=fr.empty()?e:fr.top().second;\n        Monoid\
    \ b=ba.empty()?e:ba.top().second;\n        return f(a,b);\n    }\n    void push(Monoid\
    \ x){\n        if(ba.empty()) ba.push(make_pair(x,x));\n        else ba.push(make_pair(x,f(ba.top().second,x)));\n\
    \    }\n    void pop(){\n        if(empty()) return ;\n        if(!fr.empty())\
    \ fr.pop();\n        else{\n            while(!ba.empty()){\n                pair<Monoid,Monoid>\
    \ p=ba.top();ba.pop();\n                if(fr.empty()) fr.push(make_pair(p.first,p.first));\n\
    \                else fr.push(make_pair(p.first,f(p.first,fr.top().second)));\n\
    \            }\n            fr.pop();\n        }\n    }\n    size_t size(){\n\
    \        return fr.size()+ba.size();\n    }\n    bool empty(){\n        return\
    \ size()==0;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SlidingWindowAgregation.cpp
  requiredBy: []
  timestamp: '2021-01-04 13:35:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_queue_operate_all_composite.test.cpp
documentation_of: DataStructure/SlidingWindowAgregation.cpp
layout: document
redirect_from:
- /library/DataStructure/SlidingWindowAgregation.cpp
- /library/DataStructure/SlidingWindowAgregation.cpp.html
title: DataStructure/SlidingWindowAgregation.cpp
---

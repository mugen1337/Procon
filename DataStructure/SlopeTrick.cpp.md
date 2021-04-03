---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
  bundledCode: "#line 1 \"DataStructure/SlopeTrick.cpp\"\n// ref: https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8\n\
    template<typename T>\nstruct SlopeTrick{\n    multiset<T> L,R;\n    T min_f,inf,shift_L,shift_R;\n\
    \n    // queue operation\n    T pop_L(){\n        T ret=*prev(end(L));\n     \
    \   L.erase(prev(end(L)));\n        return ret+shift_L;\n    }\n    T pop_R(){\n\
    \        T ret=*begin(R);\n        R.erase(begin(R));\n        return ret+shift_R;\n\
    \    }\n    T top_L(){ return *prev(end(L))+shift_L; }\n    T top_R(){ return\
    \ *begin(R)+shift_R; }\n    void push_L(T x){ L.insert(x-shift_L); }\n    void\
    \ push_R(T x){ R.insert(x-shift_R); }\n\n    // operations\n    SlopeTrick(T min_f=0):min_f(min_f),inf(numeric_limits<T>::max()/2),shift_L(0),shift_R(0){\n\
    \        push_L(-inf);\n        push_R(inf);\n    }\n    // add a, all\n    void\
    \ add(T a){ min_f+=a; }\n    // add max(0, x-a) ( __/ )\n    void add_xa(T a){\n\
    \        min_f+=max(top_L()-a,T(0));\n        push_L(a);\n        push_R(pop_L());\n\
    \    }\n    // add max(0, a-x) ( \\__ )\n    void add_ax(T a){\n        min_f+=max(a-top_R(),T(0));\n\
    \        push_R(a);\n        push_L(pop_R());\n    }\n    // add |x-a| ( \\/ )\n\
    \    void add_abs(T a){\n        add_xa(a);\n        add_ax(a);\n    }\n    //\
    \ \\/ -> \\__\n    void clear_R(){\n        R.clear();\n        push_R(inf);\n\
    \    }\n    // \\/ -> __/\n    void clear_L(){\n        L.clear();\n        push_L(-inf);\n\
    \    }\n    // f(x) -> f(x-a)\n    void shift(T a){\n        shift_L+=a,shift_R+=a;\n\
    \    }\n    T get_min(){ return min_f; }\n    // O(N)\n    T operator()(T x){\n\
    \        T l0=top_L(),r0=top_R();\n        if(l0<=x and x<=r0) return min_f;\n\
    \        T ret=min_f;\n        if(x<l0) for(auto ite=prev(end(L));x<*ite+shift_L;ite--)\
    \ ret+=*ite+shift_L-x;\n        else     for(auto ite=begin(R);*ite+shift_R<x;ite++)\
    \     ret+=x-*ite-shift_R;\n        return ret;\n    }\n};\n"
  code: "// ref: https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8\ntemplate<typename\
    \ T>\nstruct SlopeTrick{\n    multiset<T> L,R;\n    T min_f,inf,shift_L,shift_R;\n\
    \n    // queue operation\n    T pop_L(){\n        T ret=*prev(end(L));\n     \
    \   L.erase(prev(end(L)));\n        return ret+shift_L;\n    }\n    T pop_R(){\n\
    \        T ret=*begin(R);\n        R.erase(begin(R));\n        return ret+shift_R;\n\
    \    }\n    T top_L(){ return *prev(end(L))+shift_L; }\n    T top_R(){ return\
    \ *begin(R)+shift_R; }\n    void push_L(T x){ L.insert(x-shift_L); }\n    void\
    \ push_R(T x){ R.insert(x-shift_R); }\n\n    // operations\n    SlopeTrick(T min_f=0):min_f(min_f),inf(numeric_limits<T>::max()/2),shift_L(0),shift_R(0){\n\
    \        push_L(-inf);\n        push_R(inf);\n    }\n    // add a, all\n    void\
    \ add(T a){ min_f+=a; }\n    // add max(0, x-a) ( __/ )\n    void add_xa(T a){\n\
    \        min_f+=max(top_L()-a,T(0));\n        push_L(a);\n        push_R(pop_L());\n\
    \    }\n    // add max(0, a-x) ( \\__ )\n    void add_ax(T a){\n        min_f+=max(a-top_R(),T(0));\n\
    \        push_R(a);\n        push_L(pop_R());\n    }\n    // add |x-a| ( \\/ )\n\
    \    void add_abs(T a){\n        add_xa(a);\n        add_ax(a);\n    }\n    //\
    \ \\/ -> \\__\n    void clear_R(){\n        R.clear();\n        push_R(inf);\n\
    \    }\n    // \\/ -> __/\n    void clear_L(){\n        L.clear();\n        push_L(-inf);\n\
    \    }\n    // f(x) -> f(x-a)\n    void shift(T a){\n        shift_L+=a,shift_R+=a;\n\
    \    }\n    T get_min(){ return min_f; }\n    // O(N)\n    T operator()(T x){\n\
    \        T l0=top_L(),r0=top_R();\n        if(l0<=x and x<=r0) return min_f;\n\
    \        T ret=min_f;\n        if(x<l0) for(auto ite=prev(end(L));x<*ite+shift_L;ite--)\
    \ ret+=*ite+shift_L-x;\n        else     for(auto ite=begin(R);*ite+shift_R<x;ite++)\
    \     ret+=x-*ite-shift_R;\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SlopeTrick.cpp
  requiredBy: []
  timestamp: '2021-04-04 02:31:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SlopeTrick.cpp
layout: document
redirect_from:
- /library/DataStructure/SlopeTrick.cpp
- /library/DataStructure/SlopeTrick.cpp.html
title: DataStructure/SlopeTrick.cpp
---

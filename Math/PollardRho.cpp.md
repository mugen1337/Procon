---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_Factorize.test.cpp
    title: test/yosupo_Factorize.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/PollardRho.cpp\"\ntemplate<typename T>\nstruct FastPrime{\n\
    \    private:\n\n    T pow_mod(T a,T n,T m){\n        T ret=1;\n        while(n){\n\
    \            if(n&1) ret=ret*a%m;\n            a=a*a%m;\n            n>>=1;\n\
    \        }\n        return ret;\n    }\n\n    T gcdT(T a,T b){\n        if(a==0)\
    \ return b;\n        if(b==0) return a;\n        return b>0?gcdT(b,a%b):a;\n \
    \   }\n\n    T pollard_rho_single(T n){\n        auto f=[&](T x){return (x*x+1)%n;};\n\
    \        if(miller_rabin(n)) return n;\n        if(!(n&1)) return 2;\n       \
    \ T a=0;\n        while(true){\n            a++;\n            T x=a;\n       \
    \     T y=f(x);\n            while(true){\n                T g=gcdT(y-x+n,n);\n\
    \                if(g==0 or g==n) break;\n                if(g!=1) return g;\n\
    \                x=f(x);\n                y=f(f(y));\n            }\n        }\n\
    \    }\n\n    public:\n    bool miller_rabin(T n){\n        if(n<=1) return false;\n\
    \        if(n==2) return true;\n        if(n%2==0) return false;\n        T d=n-1,s=0;\n\
    \        while(!(d&1))d>>=1,s++;// n-1=2^s*d\n        for(T a:{2,3,5,7,11,13,17,19,23,29,31,37}){\n\
    \            if(n<=a) break;\n            T y=pow_mod(a,d,n);// y=a^d (mod n)\n\
    \            T t;\n            for(t=d;t<n-1 and y!=1 and y!=n-1;t<<=1) y=y*y%n;\n\
    \            if(y!=n-1 and t%2==0) return false;\n        }\n        return true;\n\
    \    }\n\n    vector<T> factorize(T n){\n        if(n==1) return {};\n       \
    \ T x=pollard_rho_single(n);\n        if(x==n) return {x};\n        vector<T>\
    \ l=factorize(x);\n        vector<T> r=factorize(n/x);\n        l.insert(l.end(),r.begin(),r.end());\n\
    \        return l;\n    }\n};\n"
  code: "template<typename T>\nstruct FastPrime{\n    private:\n\n    T pow_mod(T\
    \ a,T n,T m){\n        T ret=1;\n        while(n){\n            if(n&1) ret=ret*a%m;\n\
    \            a=a*a%m;\n            n>>=1;\n        }\n        return ret;\n  \
    \  }\n\n    T gcdT(T a,T b){\n        if(a==0) return b;\n        if(b==0) return\
    \ a;\n        return b>0?gcdT(b,a%b):a;\n    }\n\n    T pollard_rho_single(T n){\n\
    \        auto f=[&](T x){return (x*x+1)%n;};\n        if(miller_rabin(n)) return\
    \ n;\n        if(!(n&1)) return 2;\n        T a=0;\n        while(true){\n   \
    \         a++;\n            T x=a;\n            T y=f(x);\n            while(true){\n\
    \                T g=gcdT(y-x+n,n);\n                if(g==0 or g==n) break;\n\
    \                if(g!=1) return g;\n                x=f(x);\n               \
    \ y=f(f(y));\n            }\n        }\n    }\n\n    public:\n    bool miller_rabin(T\
    \ n){\n        if(n<=1) return false;\n        if(n==2) return true;\n       \
    \ if(n%2==0) return false;\n        T d=n-1,s=0;\n        while(!(d&1))d>>=1,s++;//\
    \ n-1=2^s*d\n        for(T a:{2,3,5,7,11,13,17,19,23,29,31,37}){\n           \
    \ if(n<=a) break;\n            T y=pow_mod(a,d,n);// y=a^d (mod n)\n         \
    \   T t;\n            for(t=d;t<n-1 and y!=1 and y!=n-1;t<<=1) y=y*y%n;\n    \
    \        if(y!=n-1 and t%2==0) return false;\n        }\n        return true;\n\
    \    }\n\n    vector<T> factorize(T n){\n        if(n==1) return {};\n       \
    \ T x=pollard_rho_single(n);\n        if(x==n) return {x};\n        vector<T>\
    \ l=factorize(x);\n        vector<T> r=factorize(n/x);\n        l.insert(l.end(),r.begin(),r.end());\n\
    \        return l;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/PollardRho.cpp
  requiredBy: []
  timestamp: '2021-01-10 13:28:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_Factorize.test.cpp
documentation_of: Math/PollardRho.cpp
layout: document
redirect_from:
- /library/Math/PollardRho.cpp
- /library/Math/PollardRho.cpp.html
title: Math/PollardRho.cpp
---

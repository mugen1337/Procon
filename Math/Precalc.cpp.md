---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki2017.test.cpp
    title: test/yuki2017.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://www.wolframalpha.com/input/?i=sum+combination%28n%2Bx+%2Cx%29%2C+x%3Dl+to+r&lang=ja
  bundledCode: "#line 1 \"Math/Precalc.cpp\"\ntemplate<typename T>\nstruct Precalc{\n\
    \    vector<T> fact,finv,inv;\n    Precalc(int MX):fact(MX),finv(MX),inv(MX){\n\
    \        fact[0]=T(1),fact[1]=T(1),finv[0]=T(1),finv[1]=T(1),inv[1]=T(1);\n  \
    \      for(int i=2;i<MX;i++){\n            fact[i]=fact[i-1]*T(i);\n         \
    \   inv[i]=T(0)-inv[mod%i]*(T(mod/i));\n            finv[i]=finv[i-1]*inv[i];\n\
    \        }\n    }\n    T com(int n,int k){\n        if(n<k) return T(0);\n   \
    \     if(n<0 or k<0) return T(0);\n        return fact[n]*(finv[k]*finv[n-k]);\n\
    \    }\n    T fac(int n){\n        return fact[n];\n    }\n    // \u91CD\u8907\
    \u7D44\u307F\u5408\u308F\u305B:n\u7A2E\u985E\u306E\u7269\u304B\u3089\u91CD\u8907\
    \u3092\u8A31\u3057\uFF0Ck\u500B\u9078\u3076\n    T nHk(int n,int k){\n       \
    \ return com(n+k-1,k);\n    }\n    // \u7389n\u533A\u5225\uFF0C\u7BB1k\u533A\u5225\
    \uFF0C\u5404\u7BB11\u500B\u4EE5\u4E0AO(k)\n    T F12_dis_dis_one(int n,int k){\n\
    \        if(n<k)return T(0);\n        T ret=0;\n        for(int i=0;i<=k;i++){\n\
    \            T add=com(k,i)*(T(i).pow(n));\n            if((k-i)%2) ret-=add;\n\
    \            else        ret+=add;\n        }\n        return ret;\n    }\n  \
    \  /* sum combination(n+x, x), x=l to r\n       https://www.wolframalpha.com/input/?i=sum+combination%28n%2Bx+%2Cx%29%2C+x%3Dl+to+r&lang=ja\
    \ \n       check n+x < [COM_PRECALC_MAX]    */\n    T sum_of_comb(int n,int l,int\
    \ r){\n        if(l>r)return T(0);\n        T ret=T(r+1)*com(n+r+1,r+1)-T(l)*com(l+n,l);\n\
    \        ret/=T(n+1);\n        return ret;\n    }\n};\n"
  code: "template<typename T>\nstruct Precalc{\n    vector<T> fact,finv,inv;\n   \
    \ Precalc(int MX):fact(MX),finv(MX),inv(MX){\n        fact[0]=T(1),fact[1]=T(1),finv[0]=T(1),finv[1]=T(1),inv[1]=T(1);\n\
    \        for(int i=2;i<MX;i++){\n            fact[i]=fact[i-1]*T(i);\n       \
    \     inv[i]=T(0)-inv[mod%i]*(T(mod/i));\n            finv[i]=finv[i-1]*inv[i];\n\
    \        }\n    }\n    T com(int n,int k){\n        if(n<k) return T(0);\n   \
    \     if(n<0 or k<0) return T(0);\n        return fact[n]*(finv[k]*finv[n-k]);\n\
    \    }\n    T fac(int n){\n        return fact[n];\n    }\n    // \u91CD\u8907\
    \u7D44\u307F\u5408\u308F\u305B:n\u7A2E\u985E\u306E\u7269\u304B\u3089\u91CD\u8907\
    \u3092\u8A31\u3057\uFF0Ck\u500B\u9078\u3076\n    T nHk(int n,int k){\n       \
    \ return com(n+k-1,k);\n    }\n    // \u7389n\u533A\u5225\uFF0C\u7BB1k\u533A\u5225\
    \uFF0C\u5404\u7BB11\u500B\u4EE5\u4E0AO(k)\n    T F12_dis_dis_one(int n,int k){\n\
    \        if(n<k)return T(0);\n        T ret=0;\n        for(int i=0;i<=k;i++){\n\
    \            T add=com(k,i)*(T(i).pow(n));\n            if((k-i)%2) ret-=add;\n\
    \            else        ret+=add;\n        }\n        return ret;\n    }\n  \
    \  /* sum combination(n+x, x), x=l to r\n       https://www.wolframalpha.com/input/?i=sum+combination%28n%2Bx+%2Cx%29%2C+x%3Dl+to+r&lang=ja\
    \ \n       check n+x < [COM_PRECALC_MAX]    */\n    T sum_of_comb(int n,int l,int\
    \ r){\n        if(l>r)return T(0);\n        T ret=T(r+1)*com(n+r+1,r+1)-T(l)*com(l+n,l);\n\
    \        ret/=T(n+1);\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/Precalc.cpp
  requiredBy: []
  timestamp: '2021-01-05 02:18:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki2017.test.cpp
documentation_of: Math/Precalc.cpp
layout: document
redirect_from:
- /library/Math/Precalc.cpp
- /library/Math/Precalc.cpp.html
title: Math/Precalc.cpp
---

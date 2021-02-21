---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_5_A.test.cpp
    title: test/AOJ_DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_5_B.test.cpp
    title: test/AOJ_DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_5_C.test.cpp
    title: test/AOJ_DPL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_5_D.test.cpp
    title: test/AOJ_DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_5_E.test.cpp
    title: test/AOJ_DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_5_F.test.cpp
    title: test/AOJ_DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_5_G.test.cpp
    title: test/AOJ_DPL_5_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_5_H.test.cpp
    title: test/AOJ_DPL_5_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_5_I.test.cpp
    title: test/AOJ_DPL_5_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_5_J.test.cpp
    title: test/AOJ_DPL_5_J.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_5_K.test.cpp
    title: test/AOJ_DPL_5_K.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_5_L.test.cpp
    title: test/AOJ_DPL_5_L.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki1917.test.cpp
    title: test/yuki1917.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki2017.test.cpp
    title: test/yuki2017.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki5125.test.cpp
    title: test/yuki5125.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://www.wolframalpha.com/input/?i=sum+combination%28n%2Bx+%2Cx%29%2C+x%3Dl+to+r&lang=ja
  bundledCode: "#line 1 \"Math/Precalc.cpp\"\ntemplate<typename T>\nstruct Precalc{\n\
    \    vector<T> fact,finv,inv;\n    int Mod;\n    Precalc(int MX):fact(MX),finv(MX),inv(MX),Mod(T::get_mod()){\n\
    \        fact[0]=T(1),fact[1]=T(1),finv[0]=T(1),finv[1]=T(1),inv[1]=T(1);\n  \
    \      for(int i=2;i<MX;i++){\n            fact[i]=fact[i-1]*T(i);\n         \
    \   inv[i]=T(0)-inv[Mod%i]*(T(Mod/i));\n            finv[i]=finv[i-1]*inv[i];\n\
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
    \  // \u533A\u5225\u3067\u304D\u308Bn\u4EBA\u3092k\u30C1\u30FC\u30E0\u306B\u308F\
    \u3051\u308B\uFF0C\u30C1\u30FC\u30E0\u306B\u306F\u6700\u4F4E1\u4EBA\u5C5E\u3059\
    \u308B\n    // \u30D9\u30F3\u56F3\u3092\u30A4\u30E1\u30FC\u30B8, \u5305\u9664\n\
    \    // require : T(num).pow(k)\n    T Stirling_number(int n,int k){\n       \
    \ T ret=0;\n        for(int i=0;i<=k;i++) ret+=com(k,i)*T(i).pow(n)*((k-i)%2?(-1):1);\n\
    \        return ret/T(fac(k));\n    }\n    // \u533A\u5225\u3067\u304D\u308Bn\u4EBA\
    \u3092k\u30C1\u30FC\u30E0\u4EE5\u4E0B\u306B\u308F\u3051\u308B\n    T Bell_number(int\
    \ n,int k){\n        T ret=0;\n        for(int i=1;i<=k;i++) ret+=Stirling_number(n,i);\n\
    \        return ret;\n    }\n    T partition_function(int n,int k){\n        auto\
    \ table=partition_function_table(n,k);\n        return table[n][k];\n    }\n \
    \   vector<vector<T>> partition_function_table(int n,int k){\n        vector<vector<T>>\
    \ ret(n+1,vector<T>(k+1,0));\n        ret[0][0]=1;\n        for(int i=0;i<=n;i++)for(int\
    \ j=1;j<=k;j++)if(i or j){\n            ret[i][j]=ret[i][j-1];\n            if(i-j>=0)\
    \ ret[i][j]+=ret[i-j][j];\n        }\n        return ret;\n    }\n    // n = y.size\
    \ - 1\n    // n\u6B21\u306E\u591A\u9805\u5F0Ff, f(0), f(k)\u306E\u5024\u304C\u308F\
    \u304B\u3063\u3066\u3044\u308C\u3070f(t)\u304C\u6C42\u307E\u308B\n    // 1^k +\
    \ ... n^k \u306Fk+1\u6B21\u591A\u9805\u5F0F\uFF0Ck=1\u306A\u3089n(n+1)/2\n   \
    \ T LagrangePolynomial(vector<T> y,long long t){\n        int n=(int)y.size()-1;\n\
    \        if(t<=n) return y[t];\n        T ret=T(0);\n        vector<T> l(n+1,1),r(n+1,1);\n\
    \        for(int i=0;i<n;i++) l[i+1]=l[i]*(t-i);\n        for(int i=n;i>0;i--)\
    \ r[i-1]=r[i]*(t-i);\n        for(int i=0;i<=n;i++){\n            T add=y[i]*l[i]*r[i]*finv[i]*finv[n-i];\n\
    \            ret+=((n-i)%2?-add:add);\n        }\n        return ret;\n    }\n\
    \    /* sum combination(n+x, x), x=l to r\n       https://www.wolframalpha.com/input/?i=sum+combination%28n%2Bx+%2Cx%29%2C+x%3Dl+to+r&lang=ja\
    \ \n       check n+x < [COM_PRECALC_MAX]    */\n    T sum_of_comb(int n,int l,int\
    \ r){\n        if(l>r)return T(0);\n        T ret=T(r+1)*com(n+r+1,r+1)-T(l)*com(l+n,l);\n\
    \        ret/=T(n+1);\n        return ret;\n    }\n};\n"
  code: "template<typename T>\nstruct Precalc{\n    vector<T> fact,finv,inv;\n   \
    \ int Mod;\n    Precalc(int MX):fact(MX),finv(MX),inv(MX),Mod(T::get_mod()){\n\
    \        fact[0]=T(1),fact[1]=T(1),finv[0]=T(1),finv[1]=T(1),inv[1]=T(1);\n  \
    \      for(int i=2;i<MX;i++){\n            fact[i]=fact[i-1]*T(i);\n         \
    \   inv[i]=T(0)-inv[Mod%i]*(T(Mod/i));\n            finv[i]=finv[i-1]*inv[i];\n\
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
    \  // \u533A\u5225\u3067\u304D\u308Bn\u4EBA\u3092k\u30C1\u30FC\u30E0\u306B\u308F\
    \u3051\u308B\uFF0C\u30C1\u30FC\u30E0\u306B\u306F\u6700\u4F4E1\u4EBA\u5C5E\u3059\
    \u308B\n    // \u30D9\u30F3\u56F3\u3092\u30A4\u30E1\u30FC\u30B8, \u5305\u9664\n\
    \    // require : T(num).pow(k)\n    T Stirling_number(int n,int k){\n       \
    \ T ret=0;\n        for(int i=0;i<=k;i++) ret+=com(k,i)*T(i).pow(n)*((k-i)%2?(-1):1);\n\
    \        return ret/T(fac(k));\n    }\n    // \u533A\u5225\u3067\u304D\u308Bn\u4EBA\
    \u3092k\u30C1\u30FC\u30E0\u4EE5\u4E0B\u306B\u308F\u3051\u308B\n    T Bell_number(int\
    \ n,int k){\n        T ret=0;\n        for(int i=1;i<=k;i++) ret+=Stirling_number(n,i);\n\
    \        return ret;\n    }\n    T partition_function(int n,int k){\n        auto\
    \ table=partition_function_table(n,k);\n        return table[n][k];\n    }\n \
    \   vector<vector<T>> partition_function_table(int n,int k){\n        vector<vector<T>>\
    \ ret(n+1,vector<T>(k+1,0));\n        ret[0][0]=1;\n        for(int i=0;i<=n;i++)for(int\
    \ j=1;j<=k;j++)if(i or j){\n            ret[i][j]=ret[i][j-1];\n            if(i-j>=0)\
    \ ret[i][j]+=ret[i-j][j];\n        }\n        return ret;\n    }\n    // n = y.size\
    \ - 1\n    // n\u6B21\u306E\u591A\u9805\u5F0Ff, f(0), f(k)\u306E\u5024\u304C\u308F\
    \u304B\u3063\u3066\u3044\u308C\u3070f(t)\u304C\u6C42\u307E\u308B\n    // 1^k +\
    \ ... n^k \u306Fk+1\u6B21\u591A\u9805\u5F0F\uFF0Ck=1\u306A\u3089n(n+1)/2\n   \
    \ T LagrangePolynomial(vector<T> y,long long t){\n        int n=(int)y.size()-1;\n\
    \        if(t<=n) return y[t];\n        T ret=T(0);\n        vector<T> l(n+1,1),r(n+1,1);\n\
    \        for(int i=0;i<n;i++) l[i+1]=l[i]*(t-i);\n        for(int i=n;i>0;i--)\
    \ r[i-1]=r[i]*(t-i);\n        for(int i=0;i<=n;i++){\n            T add=y[i]*l[i]*r[i]*finv[i]*finv[n-i];\n\
    \            ret+=((n-i)%2?-add:add);\n        }\n        return ret;\n    }\n\
    \    /* sum combination(n+x, x), x=l to r\n       https://www.wolframalpha.com/input/?i=sum+combination%28n%2Bx+%2Cx%29%2C+x%3Dl+to+r&lang=ja\
    \ \n       check n+x < [COM_PRECALC_MAX]    */\n    T sum_of_comb(int n,int l,int\
    \ r){\n        if(l>r)return T(0);\n        T ret=T(r+1)*com(n+r+1,r+1)-T(l)*com(l+n,l);\n\
    \        ret/=T(n+1);\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/Precalc.cpp
  requiredBy: []
  timestamp: '2021-02-21 14:43:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki2017.test.cpp
  - test/AOJ_DPL_5_C.test.cpp
  - test/AOJ_DPL_5_F.test.cpp
  - test/AOJ_DPL_5_J.test.cpp
  - test/AOJ_DPL_5_H.test.cpp
  - test/AOJ_DPL_5_D.test.cpp
  - test/AOJ_DPL_5_B.test.cpp
  - test/AOJ_DPL_5_G.test.cpp
  - test/AOJ_DPL_5_K.test.cpp
  - test/yuki1917.test.cpp
  - test/AOJ_DPL_5_I.test.cpp
  - test/AOJ_DPL_5_L.test.cpp
  - test/AOJ_DPL_5_A.test.cpp
  - test/yuki5125.test.cpp
  - test/AOJ_DPL_5_E.test.cpp
documentation_of: Math/Precalc.cpp
layout: document
title: Precalc (Twelvefold way)
---

## 概要  
Combinationの前計算と，一部，数え上げに関係する関数を持った構造体  
modint以外が渡されることを考えていない．メソッドpowが要求される関数がある  

## 写像12相 (Twelvefold way)  

|                                | 制限無し | 箱ごと1個以下 | 箱ごと1個以上 | 
| ------------------------------ | -------- | ------------- | ------------- | 
| **玉区別，箱区別**             | DPL_5_A  | DPL_5_B       | DPL_5_C       | 
| **玉区別しない，箱区別**       | DPL_5_D  | DPL_5_E       | DPL_5_F       | 
| **玉区別，箱区別しない**       | DPL_5_G  | DPL_5_H       | DPL_5_I       | 
| **玉区別しない，箱区別しない** | DPL_5_J  | DPL_5_K       | DPL_5_L       | 

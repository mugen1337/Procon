---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/ManhattanSquareSum.hpp
    title: Math/ManhattanSquareSum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_2863.test.cpp
    title: test/AOJ_2863.test.cpp
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
    path: test/yosupo_Bitwise_And_Convolution.test.cpp
    title: test/yosupo_Bitwise_And_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Bitwise_Xor_Convolution.test.cpp
    title: test/yosupo_Bitwise_Xor_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
    title: test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_det.test.cpp
    title: test/yosupo_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki1917.test.cpp
    title: test/yuki1917.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki2017.test.cpp
    title: test/yuki2017.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki3784.test.cpp
    title: test/yuki3784.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki473.test.cpp
    title: test/yuki473.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki5125.test.cpp
    title: test/yuki5125.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki5436.test.cpp
    title: test/yuki5436.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"type/modint.hpp\"\ntemplate<ll Mod>\nstruct ModInt{\n  \
    \  long long x;\n    ModInt():x(0){}\n    ModInt(long long y):x(y>=0?y%Mod:(Mod-(-y)%Mod)%Mod){}\n\
    \    ModInt &operator+=(const ModInt &p){\n        if((x+=p.x)>=Mod) x-=Mod;\n\
    \        return *this;\n    }\n    ModInt &operator-=(const ModInt &p){\n    \
    \    if((x+=Mod-p.x)>=Mod)x-=Mod;\n        return *this;\n    }\n    ModInt &operator*=(const\
    \ ModInt &p){\n        x=(int)(1ll*x*p.x%Mod);\n        return *this;\n    }\n\
    \    ModInt &operator/=(const ModInt &p){\n        (*this)*=p.inverse();\n   \
    \     return *this;\n    }\n    ModInt operator-()const{return ModInt(-x);}\n\
    \    ModInt operator+(const ModInt &p)const{return ModInt(*this)+=p;}\n    ModInt\
    \ operator-(const ModInt &p)const{return ModInt(*this)-=p;}\n    ModInt operator*(const\
    \ ModInt &p)const{return ModInt(*this)*=p;}\n    ModInt operator/(const ModInt\
    \ &p)const{return ModInt(*this)/=p;}\n    bool operator==(const ModInt &p)const{return\
    \ x==p.x;}\n    bool operator!=(const ModInt &p)const{return x!=p.x;}\n    ModInt\
    \ inverse()const{\n        int a=x,b=Mod,u=1,v=0,t;\n        while(b>0){\n   \
    \         t=a/b;\n            swap(a-=t*b,b);swap(u-=t*v,v);\n        }\n    \
    \    return ModInt(u);\n    }\n    ModInt pow(long long n)const{\n        ModInt\
    \ ret(1),mul(x);\n        while(n>0){\n            if(n&1) ret*=mul;\n       \
    \     mul*=mul;n>>=1;\n        }\n        return ret;\n    }\n    friend ostream\
    \ &operator<<(ostream &os,const ModInt &p){return os<<p.x;}\n    friend istream\
    \ &operator>>(istream &is,ModInt &a){long long t;is>>t;a=ModInt<Mod>(t);return\
    \ (is);}\n    static int get_mod(){return Mod;}\n};\n"
  code: "template<ll Mod>\nstruct ModInt{\n    long long x;\n    ModInt():x(0){}\n\
    \    ModInt(long long y):x(y>=0?y%Mod:(Mod-(-y)%Mod)%Mod){}\n    ModInt &operator+=(const\
    \ ModInt &p){\n        if((x+=p.x)>=Mod) x-=Mod;\n        return *this;\n    }\n\
    \    ModInt &operator-=(const ModInt &p){\n        if((x+=Mod-p.x)>=Mod)x-=Mod;\n\
    \        return *this;\n    }\n    ModInt &operator*=(const ModInt &p){\n    \
    \    x=(int)(1ll*x*p.x%Mod);\n        return *this;\n    }\n    ModInt &operator/=(const\
    \ ModInt &p){\n        (*this)*=p.inverse();\n        return *this;\n    }\n \
    \   ModInt operator-()const{return ModInt(-x);}\n    ModInt operator+(const ModInt\
    \ &p)const{return ModInt(*this)+=p;}\n    ModInt operator-(const ModInt &p)const{return\
    \ ModInt(*this)-=p;}\n    ModInt operator*(const ModInt &p)const{return ModInt(*this)*=p;}\n\
    \    ModInt operator/(const ModInt &p)const{return ModInt(*this)/=p;}\n    bool\
    \ operator==(const ModInt &p)const{return x==p.x;}\n    bool operator!=(const\
    \ ModInt &p)const{return x!=p.x;}\n    ModInt inverse()const{\n        int a=x,b=Mod,u=1,v=0,t;\n\
    \        while(b>0){\n            t=a/b;\n            swap(a-=t*b,b);swap(u-=t*v,v);\n\
    \        }\n        return ModInt(u);\n    }\n    ModInt pow(long long n)const{\n\
    \        ModInt ret(1),mul(x);\n        while(n>0){\n            if(n&1) ret*=mul;\n\
    \            mul*=mul;n>>=1;\n        }\n        return ret;\n    }\n    friend\
    \ ostream &operator<<(ostream &os,const ModInt &p){return os<<p.x;}\n    friend\
    \ istream &operator>>(istream &is,ModInt &a){long long t;is>>t;a=ModInt<Mod>(t);return\
    \ (is);}\n    static int get_mod(){return Mod;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: type/modint.hpp
  requiredBy:
  - Math/ManhattanSquareSum.hpp
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki3784.test.cpp
  - test/AOJ_DPL_5_A.test.cpp
  - test/yosupo_Bitwise_Xor_Convolution.test.cpp
  - test/AOJ_2863.test.cpp
  - test/yuki473.test.cpp
  - test/AOJ_DPL_5_I.test.cpp
  - test/AOJ_DPL_5_H.test.cpp
  - test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - test/AOJ_DPL_5_C.test.cpp
  - test/AOJ_DPL_5_J.test.cpp
  - test/yuki5125.test.cpp
  - test/AOJ_DPL_5_E.test.cpp
  - test/AOJ_DPL_5_K.test.cpp
  - test/AOJ_DPL_5_B.test.cpp
  - test/AOJ_DPL_5_F.test.cpp
  - test/yuki5436.test.cpp
  - test/AOJ_DPL_5_L.test.cpp
  - test/yuki2017.test.cpp
  - test/yosupo_Bitwise_And_Convolution.test.cpp
  - test/AOJ_DPL_5_G.test.cpp
  - test/AOJ_DPL_5_D.test.cpp
  - test/yuki1917.test.cpp
  - test/yosupo_det.test.cpp
documentation_of: type/modint.hpp
layout: document
redirect_from:
- /library/type/modint.hpp
- /library/type/modint.hpp.html
title: type/modint.hpp
---

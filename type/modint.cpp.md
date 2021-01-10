---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    path: test/yuki2017.test.cpp
    title: test/yuki2017.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"type/modint.cpp\"\ntemplate<ll Mod>\nstruct ModInt{\n  \
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
  path: type/modint.cpp
  requiredBy: []
  timestamp: '2021-01-03 23:50:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_Bitwise_Xor_Convolution.test.cpp
  - test/yuki2017.test.cpp
  - test/yosupo_det.test.cpp
  - test/yosupo_Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
documentation_of: type/modint.cpp
layout: document
redirect_from:
- /library/type/modint.cpp
- /library/type/modint.cpp.html
title: type/modint.cpp
---

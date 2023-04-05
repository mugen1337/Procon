---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"type/Fraction.hpp\"\ntemplate<class INT>\nstruct Fraction{\n\
    \    INT num,den;// numerator / denominator\n    INT Igcd(INT a,INT b){return\
    \ (b?Igcd(b,a%b):a);}\n    void normalize(){\n        INT g=Igcd(num,den);\n \
    \       num/=g;den/=g;\n        if(den<0)num=-num,den=-den;\n    }\n    Fraction(INT\
    \ num=0,INT den=1):num(num),den(den){normalize();}\n    long double to_ld()const{return\
    \ (long double)num/den;}\n    double to_d()const{return (double)num/den;}\n  \
    \  Fraction &operator+=(const Fraction &rhs){\n        num=num*rhs.den+rhs.num*den;\n\
    \        den*=rhs.den;\n        normalize();\n        return *this;\n    }\n \
    \   Fraction &operator-=(const Fraction &rhs){\n        num=num*rhs.den-rhs.num*den;\n\
    \        den*=rhs.den;\n        normalize();\n        return *this;\n    }\n \
    \   Fraction &operator*=(const Fraction &rhs){\n        num*=rhs.num;\n      \
    \  den*=rhs.den;\n        normalize();\n        return *this;\n    }\n    Fraction\
    \ &operator/=(const Fraction &rhs){\n        num*=rhs.den;\n        den*=rhs.num;\n\
    \        normalize();\n        return *this;\n    }\n    Fraction abs(){\n   \
    \     Fraction ret(*this);\n        if(ret<0)ret.first=ret.first*(-1);\n     \
    \   return ret;\n    }\n    Fraction operator-(){(*this).first*=-1;return *this;}\n\
    \    Fraction operator+(const Fraction &rhs)const{return Fraction(*this)+=rhs;}\n\
    \    Fraction operator-(const Fraction &rhs)const{return Fraction(*this)-=rhs;}\n\
    \    Fraction operator*(const Fraction &rhs)const{return Fraction(*this)*=rhs;}\n\
    \    Fraction operator/(const Fraction &rhs)const{return Fraction(*this)/=rhs;}\n\
    \    bool operator==(const Fraction &rhs)const{return num*rhs.den==den*rhs.num;}\n\
    \    bool operator!=(const Fraction &rhs)const{return !(*this==rhs);}\n    bool\
    \ operator>=(const Fraction &rhs)const{return num*rhs.den>=den*rhs.num;}\n   \
    \ bool operator<=(const Fraction &rhs)const{return num*rhs.den<=den*rhs.num;}\n\
    \    bool operator>(const Fraction &rhs)const{return num*rhs.den>den*rhs.num;}\n\
    \    bool operator<(const Fraction &rhs)const{return num*rhs.den<den*rhs.num;}\n\
    \    friend ostream &operator<<(ostream &os,const Fraction &p){return os<<p.num<<\"\
    /\"<<p.den;}\n};\n"
  code: "template<class INT>\nstruct Fraction{\n    INT num,den;// numerator / denominator\n\
    \    INT Igcd(INT a,INT b){return (b?Igcd(b,a%b):a);}\n    void normalize(){\n\
    \        INT g=Igcd(num,den);\n        num/=g;den/=g;\n        if(den<0)num=-num,den=-den;\n\
    \    }\n    Fraction(INT num=0,INT den=1):num(num),den(den){normalize();}\n  \
    \  long double to_ld()const{return (long double)num/den;}\n    double to_d()const{return\
    \ (double)num/den;}\n    Fraction &operator+=(const Fraction &rhs){\n        num=num*rhs.den+rhs.num*den;\n\
    \        den*=rhs.den;\n        normalize();\n        return *this;\n    }\n \
    \   Fraction &operator-=(const Fraction &rhs){\n        num=num*rhs.den-rhs.num*den;\n\
    \        den*=rhs.den;\n        normalize();\n        return *this;\n    }\n \
    \   Fraction &operator*=(const Fraction &rhs){\n        num*=rhs.num;\n      \
    \  den*=rhs.den;\n        normalize();\n        return *this;\n    }\n    Fraction\
    \ &operator/=(const Fraction &rhs){\n        num*=rhs.den;\n        den*=rhs.num;\n\
    \        normalize();\n        return *this;\n    }\n    Fraction abs(){\n   \
    \     Fraction ret(*this);\n        if(ret<0)ret.first=ret.first*(-1);\n     \
    \   return ret;\n    }\n    Fraction operator-(){(*this).first*=-1;return *this;}\n\
    \    Fraction operator+(const Fraction &rhs)const{return Fraction(*this)+=rhs;}\n\
    \    Fraction operator-(const Fraction &rhs)const{return Fraction(*this)-=rhs;}\n\
    \    Fraction operator*(const Fraction &rhs)const{return Fraction(*this)*=rhs;}\n\
    \    Fraction operator/(const Fraction &rhs)const{return Fraction(*this)/=rhs;}\n\
    \    bool operator==(const Fraction &rhs)const{return num*rhs.den==den*rhs.num;}\n\
    \    bool operator!=(const Fraction &rhs)const{return !(*this==rhs);}\n    bool\
    \ operator>=(const Fraction &rhs)const{return num*rhs.den>=den*rhs.num;}\n   \
    \ bool operator<=(const Fraction &rhs)const{return num*rhs.den<=den*rhs.num;}\n\
    \    bool operator>(const Fraction &rhs)const{return num*rhs.den>den*rhs.num;}\n\
    \    bool operator<(const Fraction &rhs)const{return num*rhs.den<den*rhs.num;}\n\
    \    friend ostream &operator<<(ostream &os,const Fraction &p){return os<<p.num<<\"\
    /\"<<p.den;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: type/Fraction.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: type/Fraction.hpp
layout: document
redirect_from:
- /library/type/Fraction.hpp
- /library/type/Fraction.hpp.html
title: type/Fraction.hpp
---

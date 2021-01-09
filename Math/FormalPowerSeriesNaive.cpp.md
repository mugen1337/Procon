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
    - http://q.c.titech.ac.jp/docs/progs/polynomial_division.html
    - https://atcoder.jp/contests/aising2020/submissions/15300636
    - https://qiita.com/hotman78/items/f0e6d2265badd84d429a
  bundledCode: "#line 1 \"Math/FormalPowerSeriesNaive.cpp\"\ntemplate<typename T>\n\
    struct FormalPowerSeriesNaive:vector<T>{\n    using vector<T>::vector;\n    using\
    \ P=FormalPowerSeriesNaive;\n\n    function<P(P,P)> multiply(const P &lhs,const\
    \ P &rhs){\n        auto ret=FPS((int)lhs.size()+rhs.size()-1);\n        for(int\
    \ i=0;i<(int)lhs.size();i++)for(int j=0;j<(int)rhs.size();j++) ret[i+j]+=lhs[i]*rhs[j];\n\
    \        return ret;\n    }\n\n    void shrink(){while(this->size() and this->back()==T(0))\
    \ this->pop_back();}\n    P pre(int sz)const{return P(begin(*this),begin(*this)+min((int)this->size(),sz));}\n\
    \    P operator+(const P &rhs)const{return P(*this)+=rhs;}\n    P operator+(const\
    \ T &rhs)const{return P(*this)+=rhs;}\n    P operator-(const P &rhs)const{return\
    \ P(*this)-=rhs;}\n    P operator-(const T &rhs)const{return P(*this)-=rhs;}\n\
    \    P operator*(const P &rhs)const{return P(*this)*=rhs;}\n    P operator*(const\
    \ T &rhs)const{return P(*this)*=rhs;}\n    P operator/(const P &rhs)const{return\
    \ P(*this)/=rhs;}\n    P operator%(const P &rhs)const{return P(*this)%=rhs;}\n\
    \    P &operator+=(const P &rhs){\n        if(rhs.size()>this->size()) this->resize(rhs.size());\n\
    \        for(int i=0;i<(int)rhs.size();i++) (*this)[i]+=rhs[i];\n        return\
    \ (*this);\n    }\n    P &operator+=(const T &rhs){\n        if(this->empty())\
    \ this->resize(1);\n        (*this)[0]+=rhs;\n        return (*this);\n    }\n\
    \    P &operator-=(const P &rhs){\n        if(rhs.size()>this->size()) this->resize(rhs.size());\n\
    \        for(int i=0;i<(int)rhs.size();i++) (*this)[i]-=rhs[i];\n        shrink();\n\
    \        return (*this);\n    }\n    P &operator-=(const T &rhs){\n        if(this->empty())\
    \ this->resize(1);\n        (*this)[0]-=rhs;\n        shrink();\n        return\
    \ (*this);\n    }\n    P &operator*=(const T &rhs){\n        const int n=(int)this->size();\n\
    \        for(int i=0;i<n;i++) (*this)[i]*=rhs;\n        return (*this);\n    }\n\
    \    P &operator*=(const P &rhs){\n        if(this->empty() or rhs.empty()){\n\
    \            this->clear();\n            return (*this);\n        }\n        return\
    \ (*this)=multiply(*this,rhs);\n    }\n    P &operator%=(const P &rhs){return\
    \ (*this)-=(*this)/rhs*rhs;}\n    P operator-()const{\n        P ret(this->size());\n\
    \        for(int i=0;i<(int)this->size();i++) ret[i]=-(*this)[i];\n        return\
    \ ret;\n    }\n    P &operator/=(const P &rhs){\n        if(this->size()<rhs.size()){\n\
    \            this->clear();\n            return (*this);\n        }\n        int\
    \ n=(int)this->size()-rhs.size()+1;\n        return (*this)=(rev().pre(n)*rhs.rev().inv(n));\n\
    \    }\n    P operator>>(int sz)const{\n        if((int)this->size()<=sz) return\
    \ {};\n        P ret(*this);\n        ret.erase(ret.begin(),ret.begin()+sz);\n\
    \        return ret;\n    }\n    P operator<<(int sz)const{\n        P ret(*this);\n\
    \        ret.insert(ret.begin(),sz,T(0));\n        return ret;\n    }\n    P rev(int\
    \ deg=-1)const{\n        P ret(*this);\n        if(deg!=-1) ret.resize(deg,T(0));\n\
    \        reverse(begin(ret),end(ret));\n        return ret;\n    }\n    // ref\
    \ : https://qiita.com/hotman78/items/f0e6d2265badd84d429a\n    P inv(int deg=-1)const{\n\
    \        assert(((*this)[0])!=T(0));\n        const int n=(int)this->size();\n\
    \        if(deg==-1) deg=n;\n        P ret({T(1)/(*this)[0]});\n        for(int\
    \ i=1;i<deg;i<<=1) ret=(ret+ret-ret*ret*pre(i<<1)).pre(i<<1);\n        return\
    \ ret.pre(deg);\n    }\n    // O(Mult * log k)\n    P pow(ll k,int deg=-1){\n\
    \        if(deg==-1) deg=1000000000;\n        P ret=P{1};\n        P b(*this);\n\
    \        while(k){\n            if(k&1) ret*=b;\n            b=b*b;\n        \
    \    k>>=1;\n            if((int)ret.size()>deg) ret.resize(deg);\n          \
    \  if((int)b.size()>deg) b.resize(deg);\n        }\n        return ret;\n    }\n\
    \    // [l,r) k\u500B\u98DB\u3073\n    P slice(int l,int r,int k=1){\n       \
    \ P ret;\n        for(int i=l;i<r;i+=k) ret.push_back((*this)[i]);\n        return\
    \ ret;\n    }\n    /*\n    ref : https://atcoder.jp/contests/aising2020/submissions/15300636\n\
    \          http://q.c.titech.ac.jp/docs/progs/polynomial_division.html\n \n  \
    \  order :      \n        O(M(d)log(k))  (M(d) -> d\u6B21\u5143\uFF0Cmultiply\u306E\
    \u8A08\u7B97\u91CF)\n \n    return :\n        [x^k] (*this) / q\n    */\n    T\
    \ nth_term(P q,ll k){\n        if(k==0) return (*this)[0]/q[0];\n        P p(*this),q_=q;\n\
    \        for(int i=1;i<(int)q_.size();i+=2) q_[i]*=-1;\n        q*=q_;p*=q_;//\
    \ q\u306F\u5947\u6570\u9805\u304C\u6D88\u3048\u308B\n        return p.slice(k%2,p.size(),2).nth_term(q.slice(0,q.size(),2),k/2);\n\
    \    }\n};\n"
  code: "template<typename T>\nstruct FormalPowerSeriesNaive:vector<T>{\n    using\
    \ vector<T>::vector;\n    using P=FormalPowerSeriesNaive;\n\n    function<P(P,P)>\
    \ multiply(const P &lhs,const P &rhs){\n        auto ret=FPS((int)lhs.size()+rhs.size()-1);\n\
    \        for(int i=0;i<(int)lhs.size();i++)for(int j=0;j<(int)rhs.size();j++)\
    \ ret[i+j]+=lhs[i]*rhs[j];\n        return ret;\n    }\n\n    void shrink(){while(this->size()\
    \ and this->back()==T(0)) this->pop_back();}\n    P pre(int sz)const{return P(begin(*this),begin(*this)+min((int)this->size(),sz));}\n\
    \    P operator+(const P &rhs)const{return P(*this)+=rhs;}\n    P operator+(const\
    \ T &rhs)const{return P(*this)+=rhs;}\n    P operator-(const P &rhs)const{return\
    \ P(*this)-=rhs;}\n    P operator-(const T &rhs)const{return P(*this)-=rhs;}\n\
    \    P operator*(const P &rhs)const{return P(*this)*=rhs;}\n    P operator*(const\
    \ T &rhs)const{return P(*this)*=rhs;}\n    P operator/(const P &rhs)const{return\
    \ P(*this)/=rhs;}\n    P operator%(const P &rhs)const{return P(*this)%=rhs;}\n\
    \    P &operator+=(const P &rhs){\n        if(rhs.size()>this->size()) this->resize(rhs.size());\n\
    \        for(int i=0;i<(int)rhs.size();i++) (*this)[i]+=rhs[i];\n        return\
    \ (*this);\n    }\n    P &operator+=(const T &rhs){\n        if(this->empty())\
    \ this->resize(1);\n        (*this)[0]+=rhs;\n        return (*this);\n    }\n\
    \    P &operator-=(const P &rhs){\n        if(rhs.size()>this->size()) this->resize(rhs.size());\n\
    \        for(int i=0;i<(int)rhs.size();i++) (*this)[i]-=rhs[i];\n        shrink();\n\
    \        return (*this);\n    }\n    P &operator-=(const T &rhs){\n        if(this->empty())\
    \ this->resize(1);\n        (*this)[0]-=rhs;\n        shrink();\n        return\
    \ (*this);\n    }\n    P &operator*=(const T &rhs){\n        const int n=(int)this->size();\n\
    \        for(int i=0;i<n;i++) (*this)[i]*=rhs;\n        return (*this);\n    }\n\
    \    P &operator*=(const P &rhs){\n        if(this->empty() or rhs.empty()){\n\
    \            this->clear();\n            return (*this);\n        }\n        return\
    \ (*this)=multiply(*this,rhs);\n    }\n    P &operator%=(const P &rhs){return\
    \ (*this)-=(*this)/rhs*rhs;}\n    P operator-()const{\n        P ret(this->size());\n\
    \        for(int i=0;i<(int)this->size();i++) ret[i]=-(*this)[i];\n        return\
    \ ret;\n    }\n    P &operator/=(const P &rhs){\n        if(this->size()<rhs.size()){\n\
    \            this->clear();\n            return (*this);\n        }\n        int\
    \ n=(int)this->size()-rhs.size()+1;\n        return (*this)=(rev().pre(n)*rhs.rev().inv(n));\n\
    \    }\n    P operator>>(int sz)const{\n        if((int)this->size()<=sz) return\
    \ {};\n        P ret(*this);\n        ret.erase(ret.begin(),ret.begin()+sz);\n\
    \        return ret;\n    }\n    P operator<<(int sz)const{\n        P ret(*this);\n\
    \        ret.insert(ret.begin(),sz,T(0));\n        return ret;\n    }\n    P rev(int\
    \ deg=-1)const{\n        P ret(*this);\n        if(deg!=-1) ret.resize(deg,T(0));\n\
    \        reverse(begin(ret),end(ret));\n        return ret;\n    }\n    // ref\
    \ : https://qiita.com/hotman78/items/f0e6d2265badd84d429a\n    P inv(int deg=-1)const{\n\
    \        assert(((*this)[0])!=T(0));\n        const int n=(int)this->size();\n\
    \        if(deg==-1) deg=n;\n        P ret({T(1)/(*this)[0]});\n        for(int\
    \ i=1;i<deg;i<<=1) ret=(ret+ret-ret*ret*pre(i<<1)).pre(i<<1);\n        return\
    \ ret.pre(deg);\n    }\n    // O(Mult * log k)\n    P pow(ll k,int deg=-1){\n\
    \        if(deg==-1) deg=1000000000;\n        P ret=P{1};\n        P b(*this);\n\
    \        while(k){\n            if(k&1) ret*=b;\n            b=b*b;\n        \
    \    k>>=1;\n            if((int)ret.size()>deg) ret.resize(deg);\n          \
    \  if((int)b.size()>deg) b.resize(deg);\n        }\n        return ret;\n    }\n\
    \    // [l,r) k\u500B\u98DB\u3073\n    P slice(int l,int r,int k=1){\n       \
    \ P ret;\n        for(int i=l;i<r;i+=k) ret.push_back((*this)[i]);\n        return\
    \ ret;\n    }\n    /*\n    ref : https://atcoder.jp/contests/aising2020/submissions/15300636\n\
    \          http://q.c.titech.ac.jp/docs/progs/polynomial_division.html\n \n  \
    \  order :      \n        O(M(d)log(k))  (M(d) -> d\u6B21\u5143\uFF0Cmultiply\u306E\
    \u8A08\u7B97\u91CF)\n \n    return :\n        [x^k] (*this) / q\n    */\n    T\
    \ nth_term(P q,ll k){\n        if(k==0) return (*this)[0]/q[0];\n        P p(*this),q_=q;\n\
    \        for(int i=1;i<(int)q_.size();i+=2) q_[i]*=-1;\n        q*=q_;p*=q_;//\
    \ q\u306F\u5947\u6570\u9805\u304C\u6D88\u3048\u308B\n        return p.slice(k%2,p.size(),2).nth_term(q.slice(0,q.size(),2),k/2);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/FormalPowerSeriesNaive.cpp
  requiredBy: []
  timestamp: '2021-01-05 02:18:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki2017.test.cpp
documentation_of: Math/FormalPowerSeriesNaive.cpp
layout: document
redirect_from:
- /library/Math/FormalPowerSeriesNaive.cpp
- /library/Math/FormalPowerSeriesNaive.cpp.html
title: Math/FormalPowerSeriesNaive.cpp
---
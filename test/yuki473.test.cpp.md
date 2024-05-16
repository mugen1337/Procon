---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/FormalPowerSeriesNaive.hpp
    title: Math/FormalPowerSeriesNaive.hpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  - icon: ':question:'
    path: type/modint.hpp
    title: type/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/473
    links:
    - https://yukicoder.me/problems/473
  bundledCode: "#line 1 \"test/yuki473.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/473\"\
    \n\n#line 1 \"bits/stdc++.h\"\n// C\n#ifndef _GLIBCXX_NO_ASSERT\n#include <cassert>\n\
    #endif\n#include <cctype>\n#include <cerrno>\n#include <cfloat>\n#include <ciso646>\n\
    #include <climits>\n#include <clocale>\n#include <cmath>\n#include <csetjmp>\n\
    #include <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <ctime>\n\n#if __cplusplus >=\
    \ 201103L\n#include <ccomplex>\n#include <cfenv>\n#include <cinttypes>\n#include\
    \ <cstdalign>\n#include <cstdbool>\n#include <cstdint>\n#include <ctgmath>\n#include\
    \ <cwchar>\n#include <cwctype>\n#endif\n\n// C++\n#include <algorithm>\n#include\
    \ <bitset>\n#include <complex>\n#include <deque>\n#include <exception>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <ios>\n#include\
    \ <iosfwd>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <locale>\n#include <map>\n#include <memory>\n\
    #include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <typeinfo>\n#include <utility>\n#include\
    \ <valarray>\n#include <vector>\n\n#if __cplusplus >= 201103L\n#include <array>\n\
    #include <atomic>\n#include <chrono>\n#include <condition_variable>\n#include\
    \ <forward_list>\n#include <future>\n#include <initializer_list>\n#include <mutex>\n\
    #include <random>\n#include <ratio>\n#include <regex>\n#include <scoped_allocator>\n\
    #include <system_error>\n#include <thread>\n#include <tuple>\n#include <typeindex>\n\
    #include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n#endif\n\
    #line 2 \"template.hpp\"\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto\
    \ x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\nusing ll=long long;\n\
    const int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n\
    // ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\ntemplate<class T>bool chmax(T &a,const\
    \ T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool chmin(T\
    \ &a,const T &b){if(b<a){a=b;return true;}return false;}\n\nstruct IOSetup{\n\
    \    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n     \
    \   cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename T>\n\
    ostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/yuki473.test.cpp\"\n\n#line 1 \"type/modint.hpp\"\
    \ntemplate<int Mod>\nstruct ModInt{\n    int x;\n    ModInt():x(0){}\n    ModInt(int\
    \ y): x (y >= 0 ? y % Mod : (Mod - (-y) % Mod) % Mod){}\n    ModInt(long long\
    \ y){\n        if (y >= 0)\n        {\n            x = (int)(y % (ll)(Mod));\n\
    \        }\n        else\n        {\n            int tmp = (int)((-y) % (ll)Mod);\n\
    \            x = (Mod - tmp) % Mod;\n        }\n    }\n    ModInt &operator+=(const\
    \ ModInt &p){\n        if((x += p.x) >= Mod) x -= Mod;\n        return *this;\n\
    \    }\n    ModInt &operator-=(const ModInt &p){\n        if((x += Mod - p.x)\
    \ >= Mod) x -= Mod;\n        return *this;\n    }\n    ModInt &operator*=(const\
    \ ModInt &p){\n        x = (int)(1ll * x * p.x % Mod);\n        return *this;\n\
    \    }\n    ModInt &operator/=(const ModInt &p){\n        (*this) *= p.inverse();\n\
    \        return *this;\n    }\n    ModInt operator-()const{return ModInt(-x);}\n\
    \    ModInt operator+(const ModInt &p)const{return ModInt(*this)+=p;}\n    ModInt\
    \ operator-(const ModInt &p)const{return ModInt(*this)-=p;}\n    ModInt operator*(const\
    \ ModInt &p)const{return ModInt(*this)*=p;}\n    ModInt operator/(const ModInt\
    \ &p)const{return ModInt(*this)/=p;}\n    bool operator==(const ModInt &p)const{return\
    \ x==p.x;}\n    bool operator!=(const ModInt &p)const{return x!=p.x;}\n    ModInt\
    \ inverse()const{\n        int a = x, b = Mod ,u = 1, v = 0, t;\n        while(b>0){\n\
    \            t=a/b;\n            swap(a-=t*b,b);swap(u-=t*v,v);\n        }\n \
    \       return ModInt(u);\n    }\n    ModInt pow(long long n)const{\n        ModInt\
    \ ret(1),mul(x);\n        while(n>0){\n            if(n&1) ret*=mul;\n       \
    \     mul*=mul;n>>=1;\n        }\n        return ret;\n    }\n    friend ostream\
    \ &operator<<(ostream &os,const ModInt &p){return os<<p.x;}\n    friend istream\
    \ &operator>>(istream &is,ModInt &a){long long t;is>>t;a=ModInt<Mod>(t);return\
    \ (is);}\n    static int get_mod(){return Mod;}\n};\n#line 6 \"test/yuki473.test.cpp\"\
    \n\nusing mint=ModInt<1000000007>;\n\n#line 1 \"Math/FormalPowerSeriesNaive.hpp\"\
    \ntemplate<typename T>\nstruct FormalPowerSeriesNaive:vector<T>{\n    using vector<T>::vector;\n\
    \    using P=FormalPowerSeriesNaive;\n\n    P multiply(const P &lhs,const P &rhs){\n\
    \        auto ret=P((int)lhs.size()+rhs.size()-1);\n        for(int i=0;i<(int)lhs.size();i++)for(int\
    \ j=0;j<(int)rhs.size();j++) ret[i+j]+=lhs[i]*rhs[j];\n        return ret;\n \
    \   }\n\n    void shrink(){while(this->size() and this->back()==T(0)) this->pop_back();}\n\
    \    P pre(int sz)const{return P(begin(*this),begin(*this)+min((int)this->size(),sz));}\n\
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
    \            this->clear();\n            return (*this);\n        }\n        auto\
    \ ret=multiply(*this,rhs);\n        (*this)=ret;\n        return (*this);\n  \
    \  }\n    P &operator%=(const P &rhs){return (*this)-=(*this)/rhs*rhs;}\n    P\
    \ operator-()const{\n        P ret(this->size());\n        for(int i=0;i<(int)this->size();i++)\
    \ ret[i]=-(*this)[i];\n        return ret;\n    }\n    P &operator/=(const P &rhs){\n\
    \        if(this->size()<rhs.size()){\n            this->clear();\n          \
    \  return (*this);\n        }\n        int n=(int)this->size()-rhs.size()+1;\n\
    \        return (*this)=(rev().pre(n)*rhs.rev().inv(n));\n    }\n    P operator>>(int\
    \ sz)const{\n        if((int)this->size()<=sz) return {};\n        P ret(*this);\n\
    \        ret.erase(ret.begin(),ret.begin()+sz);\n        return ret;\n    }\n\
    \    P operator<<(int sz)const{\n        P ret(*this);\n        ret.insert(ret.begin(),sz,T(0));\n\
    \        return ret;\n    }\n    P rev(int deg=-1)const{\n        P ret(*this);\n\
    \        if(deg!=-1) ret.resize(deg,T(0));\n        reverse(begin(ret),end(ret));\n\
    \        return ret;\n    }\n    // ref : https://qiita.com/hotman78/items/f0e6d2265badd84d429a\n\
    \    P inv(int deg=-1)const{\n        assert(((*this)[0])!=T(0));\n        const\
    \ int n=(int)this->size();\n        if(deg==-1) deg=n;\n        P ret({T(1)/(*this)[0]});\n\
    \        for(int i=1;i<deg;i<<=1) ret=(ret+ret-ret*ret*pre(i<<1)).pre(i<<1);\n\
    \        return ret.pre(deg);\n    }\n    // O(Mult * log k)\n    P pow(ll k,int\
    \ deg=-1){\n        if(deg==-1) deg=1000000000;\n        P ret=P{1};\n       \
    \ P b(*this);\n        while(k){\n            if(k&1) ret*=b;\n            b=b*b;\n\
    \            k>>=1;\n            if((int)ret.size()>deg) ret.resize(deg);\n  \
    \          if((int)b.size()>deg) b.resize(deg);\n        }\n        return ret;\n\
    \    }\n    // [l,r) k\u500B\u98DB\u3073\n    P slice(int l,int r,int k=1){\n\
    \        P ret;\n        for(int i=l;i<r;i+=k) ret.push_back((*this)[i]);\n  \
    \      return ret;\n    }\n    /*\n    ref : https://atcoder.jp/contests/aising2020/submissions/15300636\n\
    \          http://q.c.titech.ac.jp/docs/progs/polynomial_division.html\n \n  \
    \  order :      \n        O(M(d)log(k))  (M(d) -> d\u6B21\u5143\uFF0Cmultiply\u306E\
    \u8A08\u7B97\u91CF)\n \n    return :\n        [x^k] (*this) / q\n    */\n    T\
    \ nth_term(P q,ll k){\n        if(k==0) return (*this)[0]/q[0];\n        P p(*this);\n\
    \        P q_=q;\n        for(int i=1;i<(int)q_.size();i+=2) q_[i]*=-1;\n    \
    \    q*=q_;p*=q_;// q\u306F\u5947\u6570\u9805\u304C\u6D88\u3048\u308B\n      \
    \  return p.slice(k%2,p.size(),2).nth_term(q.slice(0,q.size(),2),k/2);\n    }\n\
    \n\n    /*\n    a_i = sum{j=1}^{d} c_j * a_{i-j}\n    return c\n    */\n    P\
    \ berlekamp_massey(){\n        int N=(int)this->size();\n        P b={T(-1)},c={T(-1)};\n\
    \        T y=T(1);\n\n        for(int ed=1;ed<=N;ed++){\n            int l=(int)c.size(),m=(int)b.size();\n\
    \            T x=0;\n            for(int i=0;i<l;i++) x+=c[i]*(*this)[ed-l+i];\n\
    \            b.emplace_back(0);\n            m++;\n            if(x==T(0)) continue;\n\
    \            T freq=x/y;\n            if(l<m){\n                auto tmp=c;\n\
    \                c.insert(begin(c),m-l,T(0));\n                for(int i=0;i<m;i++)\
    \ c[m-1-i]-=freq*b[m-1-i];\n                b=tmp;\n                y=x;\n   \
    \         }else{\n                for(int i=0;i<m;i++) c[l-1-i]-=freq*b[m-1-i];\n\
    \            }\n        }\n        reverse(begin(c),end(c));\n        return c;\n\
    \    }\n\n    // this[0], this[1] ... \n    // linear recurrence\n    // -> return\
    \ Nth term\n    // verified : https://atcoder.jp/contests/kupc2021/submissions/26974136\n\
    \    T nth_linear_recurrence(long long N){\n        auto q=berlekamp_massey();\n\
    \        assert(not q.empty() and q[0]!=T(0));\n        if(N<(int)this->size())\
    \ return (*this)[N];\n        auto p=this->pre((int)q.size()-1)*q;\n        p.resize((int)q.size()-1);\n\
    \        return p.nth_term(q,N);\n    }\n};\n#line 10 \"test/yuki473.test.cpp\"\
    \n\nusing FPS=FormalPowerSeriesNaive<mint>;\n\nsigned main(){\n    int n,s,k;cin>>n>>s>>k;\n\
    \    s-=n*(n-1)/2*k;\n    if(s<0){\n        cout<<0<<endl;\n        return 0;\n\
    \    }\n\n    FPS den{1},num{1};\n    for(int i=1;i<=n;i++) den-=(den<<i);\n \
    \   cout<<num.nth_term(den,s)<<endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/473\"\n\n#include \"../template.hpp\"\
    \n\n#include \"../type/modint.hpp\"\n\nusing mint=ModInt<1000000007>;\n\n#include\
    \ \"../Math/FormalPowerSeriesNaive.hpp\"\n\nusing FPS=FormalPowerSeriesNaive<mint>;\n\
    \nsigned main(){\n    int n,s,k;cin>>n>>s>>k;\n    s-=n*(n-1)/2*k;\n    if(s<0){\n\
    \        cout<<0<<endl;\n        return 0;\n    }\n\n    FPS den{1},num{1};\n\
    \    for(int i=1;i<=n;i++) den-=(den<<i);\n    cout<<num.nth_term(den,s)<<endl;\n\
    \    return 0;\n}"
  dependsOn:
  - template.hpp
  - bits/stdc++.h
  - type/modint.hpp
  - Math/FormalPowerSeriesNaive.hpp
  isVerificationFile: true
  path: test/yuki473.test.cpp
  requiredBy: []
  timestamp: '2024-05-15 18:03:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yuki473.test.cpp
layout: document
redirect_from:
- /verify/test/yuki473.test.cpp
- /verify/test/yuki473.test.cpp.html
title: test/yuki473.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/XorConvolution.hpp
    title: Math/XorConvolution.hpp
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/yosupo_Bitwise_Xor_Convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\n#line\
    \ 1 \"bits/stdc++.h\"\n// C\n#ifndef _GLIBCXX_NO_ASSERT\n#include <cassert>\n\
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
    \   return is;\n}\n\n#line 4 \"test/yosupo_Bitwise_Xor_Convolution.test.cpp\"\n\
    \n#line 1 \"type/modint.hpp\"\ntemplate<int Mod>\nstruct ModInt{\n    int x;\n\
    \    ModInt():x(0){}\n    ModInt(int y): x (y >= 0 ? y % Mod : (Mod - (-y) % Mod)\
    \ % Mod){}\n    ModInt(long long y){\n        if (y >= 0)\n        {\n       \
    \     x = (int)(y % (ll)(Mod));\n        }\n        else\n        {\n        \
    \    int tmp = (int)((-y) % (ll)Mod);\n            x = (Mod - tmp) % Mod;\n  \
    \      }\n    }\n    ModInt &operator+=(const ModInt &p){\n        if((x += p.x)\
    \ >= Mod) x -= Mod;\n        return *this;\n    }\n    ModInt &operator-=(const\
    \ ModInt &p){\n        if((x += Mod - p.x) >= Mod) x -= Mod;\n        return *this;\n\
    \    }\n    ModInt &operator*=(const ModInt &p){\n        x = (int)(1ll * x *\
    \ p.x % Mod);\n        return *this;\n    }\n    ModInt &operator/=(const ModInt\
    \ &p){\n        (*this) *= p.inverse();\n        return *this;\n    }\n    ModInt\
    \ operator-()const{return ModInt(-x);}\n    ModInt operator+(const ModInt &p)const{return\
    \ ModInt(*this)+=p;}\n    ModInt operator-(const ModInt &p)const{return ModInt(*this)-=p;}\n\
    \    ModInt operator*(const ModInt &p)const{return ModInt(*this)*=p;}\n    ModInt\
    \ operator/(const ModInt &p)const{return ModInt(*this)/=p;}\n    bool operator==(const\
    \ ModInt &p)const{return x==p.x;}\n    bool operator!=(const ModInt &p)const{return\
    \ x!=p.x;}\n    ModInt inverse()const{\n        int a = x, b = Mod ,u = 1, v =\
    \ 0, t;\n        while(b>0){\n            t=a/b;\n            swap(a-=t*b,b);swap(u-=t*v,v);\n\
    \        }\n        return ModInt(u);\n    }\n    ModInt pow(long long n)const{\n\
    \        ModInt ret(1),mul(x);\n        while(n>0){\n            if(n&1) ret*=mul;\n\
    \            mul*=mul;n>>=1;\n        }\n        return ret;\n    }\n    friend\
    \ ostream &operator<<(ostream &os,const ModInt &p){return os<<p.x;}\n    friend\
    \ istream &operator>>(istream &is,ModInt &a){long long t;is>>t;a=ModInt<Mod>(t);return\
    \ (is);}\n    static int get_mod(){return Mod;}\n};\n#line 6 \"test/yosupo_Bitwise_Xor_Convolution.test.cpp\"\
    \n\n#line 1 \"Math/XorConvolution.hpp\"\n// ret_k = sum a_i * b_j, i^j=k\ntemplate<typename\
    \ T>\nvector<T> XorConvolution(vector<T> a,vector<T> b){\n    assert(a.size()==b.size());\n\
    \    int n=(int)a.size();\n    vector<T> ret(n);\n    // FWT\n    for(int i=1;i<n;i<<=1)for(int\
    \ j=0;j<n;j++){\n        if((i&j)==0){\n            {\n                T x=a[j],y=a[j|i];\n\
    \                a[j]=x+y,a[j|i]=x-y;\n            }\n            {\n        \
    \        T x=b[j],y=b[j|i];\n                b[j]=x+y,b[j|i]=x-y;\n          \
    \  }\n        }\n    }\n    for(int i=0;i<n;i++) ret[i]=a[i]*b[i];\n    // IFWT\n\
    \    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){\n        if((i&j)==0){\n    \
    \        T x=ret[j],y=ret[j|i];\n            ret[j]=(x+y)/2,ret[j|i]=(x-y)/2;\n\
    \        }\n    }\n    return ret;\n}\n#line 8 \"test/yosupo_Bitwise_Xor_Convolution.test.cpp\"\
    \n\nusing mint=ModInt<998244353>;\n\nsigned main(){\n    int n;cin>>n;\n    vector<mint>\
    \ a(1<<n),b(1<<n);\n    cin>>a>>b;\n    cout<<XorConvolution(a,b)<<endl;\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include \"../template.hpp\"\n\n#include \"../type/modint.hpp\"\n\n#include\
    \ \"../Math/XorConvolution.hpp\"\n\nusing mint=ModInt<998244353>;\n\nsigned main(){\n\
    \    int n;cin>>n;\n    vector<mint> a(1<<n),b(1<<n);\n    cin>>a>>b;\n    cout<<XorConvolution(a,b)<<endl;\n\
    \    return 0;\n}"
  dependsOn:
  - template.hpp
  - bits/stdc++.h
  - type/modint.hpp
  - Math/XorConvolution.hpp
  isVerificationFile: true
  path: test/yosupo_Bitwise_Xor_Convolution.test.cpp
  requiredBy: []
  timestamp: '2024-05-15 18:03:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_Bitwise_Xor_Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Bitwise_Xor_Convolution.test.cpp
- /verify/test/yosupo_Bitwise_Xor_Convolution.test.cpp.html
title: test/yosupo_Bitwise_Xor_Convolution.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/AndConvolution.cpp
    title: Math/AndConvolution.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':heavy_check_mark:'
    path: type/modint.cpp
    title: type/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/yosupo_Bitwise_And_Convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\n#line\
    \ 1 \"template.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x)\
    \ begin(x),end(x)\n#define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\"\
    :\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\nusing ll=long\
    \ long;\nconst int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\nint\
    \ dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \nstruct IOSetup{\n    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n\
    \        cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/yosupo_Bitwise_And_Convolution.test.cpp\"\n\
    \n#line 1 \"type/modint.cpp\"\ntemplate<ll Mod>\nstruct ModInt{\n    long long\
    \ x;\n    ModInt():x(0){}\n    ModInt(long long y):x(y>=0?y%Mod:(Mod-(-y)%Mod)%Mod){}\n\
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
    \ (is);}\n    static int get_mod(){return Mod;}\n};\n#line 6 \"test/yosupo_Bitwise_And_Convolution.test.cpp\"\
    \n\n#line 1 \"Math/AndConvolution.cpp\"\n// ret_k = sum a_i * b_j, i&j=k \ntemplate<typename\
    \ T>\nvector<T> AndConvolution(vector<T> a,vector<T> b){\n    assert(a.size()==b.size());\n\
    \    int n=(int)a.size();\n    vector<T> ret(n);\n    // FWT\n    for(int i=1;i<n;i<<=1)for(int\
    \ j=0;j<n;j++){\n        if((i&j)==0) a[j]+=a[j|i],b[j]+=b[j|i];\n    }\n    for(int\
    \ i=0;i<n;i++) ret[i]=a[i]*b[i];\n    // IFWT\n    for(int i=1;i<n;i<<=1)for(int\
    \ j=0;j<n;j++){\n        if((i&j)==0) ret[j]-=ret[j|i];\n    }\n    return ret;\n\
    }\n#line 8 \"test/yosupo_Bitwise_And_Convolution.test.cpp\"\n\nusing mint=ModInt<998244353>;\n\
    \nsigned main(){\n    int n;cin>>n;\n    vector<mint> a(1<<n),b(1<<n);\n    cin>>a>>b;\n\
    \    cout<<AndConvolution(a,b)<<endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n\n#include \"../template.cpp\"\n\n#include \"../type/modint.cpp\"\n\n#include\
    \ \"../Math/AndConvolution.cpp\"\n\nusing mint=ModInt<998244353>;\n\nsigned main(){\n\
    \    int n;cin>>n;\n    vector<mint> a(1<<n),b(1<<n);\n    cin>>a>>b;\n    cout<<AndConvolution(a,b)<<endl;\n\
    \    return 0;\n}"
  dependsOn:
  - template.cpp
  - type/modint.cpp
  - Math/AndConvolution.cpp
  isVerificationFile: true
  path: test/yosupo_Bitwise_And_Convolution.test.cpp
  requiredBy: []
  timestamp: '2021-01-10 13:03:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_Bitwise_And_Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Bitwise_And_Convolution.test.cpp
- /verify/test/yosupo_Bitwise_And_Convolution.test.cpp.html
title: test/yosupo_Bitwise_And_Convolution.test.cpp
---

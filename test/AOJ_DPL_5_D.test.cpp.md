---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Precalc.cpp
    title: Precalc (Twelvefold way)
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':heavy_check_mark:'
    path: type/modint.cpp
    title: type/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D
  bundledCode: "#line 1 \"test/AOJ_DPL_5_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D\"\
    \n\n#line 1 \"template.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int i=0;i<(n);i++)\n#define\
    \ debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n#define mod\
    \ 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\n\
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \nstruct IOSetup{\n    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n\
    \        cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/AOJ_DPL_5_D.test.cpp\"\n\n#line 1 \"type/modint.cpp\"\
    \ntemplate<ll Mod>\nstruct ModInt{\n    long long x;\n    ModInt():x(0){}\n  \
    \  ModInt(long long y):x(y>=0?y%Mod:(Mod-(-y)%Mod)%Mod){}\n    ModInt &operator+=(const\
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
    \ (is);}\n    static int get_mod(){return Mod;}\n};\n#line 6 \"test/AOJ_DPL_5_D.test.cpp\"\
    \n\n#line 1 \"Math/Precalc.cpp\"\ntemplate<typename T>\nstruct Precalc{\n    vector<T>\
    \ fact,finv,inv;\n    Precalc(int MX):fact(MX),finv(MX),inv(MX){\n        fact[0]=T(1),fact[1]=T(1),finv[0]=T(1),finv[1]=T(1),inv[1]=T(1);\n\
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
    \ ret[i][j]+=ret[i-j][j];\n        }\n        return ret;\n    }\n    /* sum combination(n+x,\
    \ x), x=l to r\n       https://www.wolframalpha.com/input/?i=sum+combination%28n%2Bx+%2Cx%29%2C+x%3Dl+to+r&lang=ja\
    \ \n       check n+x < [COM_PRECALC_MAX]    */\n    T sum_of_comb(int n,int l,int\
    \ r){\n        if(l>r)return T(0);\n        T ret=T(r+1)*com(n+r+1,r+1)-T(l)*com(l+n,l);\n\
    \        ret/=T(n+1);\n        return ret;\n    }\n};\n#line 8 \"test/AOJ_DPL_5_D.test.cpp\"\
    \n\nusing mint=ModInt<1000000007>;\n\nPrecalc<mint> F(500000);\n\n/*\n\u7389:\
    \ \u533A\u5225\u3057\u306A\u3044\n\u7BB1: \u533A\u5225\n\u5165\u308C\u65B9: \u5236\
    \u9650\u306A\u3057\n*/\n\nsigned main(){\n    int n,k;cin>>n>>k;\n    cout<<F.com(n+k-1,k-1)<<endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D\"\
    \n\n#include \"../template.cpp\"\n\n#include \"../type/modint.cpp\"\n\n#include\
    \ \"../Math/Precalc.cpp\"\n\nusing mint=ModInt<1000000007>;\n\nPrecalc<mint> F(500000);\n\
    \n/*\n\u7389: \u533A\u5225\u3057\u306A\u3044\n\u7BB1: \u533A\u5225\n\u5165\u308C\
    \u65B9: \u5236\u9650\u306A\u3057\n*/\n\nsigned main(){\n    int n,k;cin>>n>>k;\n\
    \    cout<<F.com(n+k-1,k-1)<<endl;\n    return 0;\n}"
  dependsOn:
  - template.cpp
  - type/modint.cpp
  - Math/Precalc.cpp
  isVerificationFile: true
  path: test/AOJ_DPL_5_D.test.cpp
  requiredBy: []
  timestamp: '2021-01-10 16:25:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ_DPL_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_DPL_5_D.test.cpp
- /verify/test/AOJ_DPL_5_D.test.cpp.html
title: test/AOJ_DPL_5_D.test.cpp
---

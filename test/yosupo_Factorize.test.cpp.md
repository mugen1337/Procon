---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/PollardRho.cpp
    title: Math/PollardRho.cpp
  - icon: ':question:'
    path: template.cpp
    title: template.cpp
  - icon: ':x:'
    path: type/int128.cpp
    title: type/int128.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/yosupo_Factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
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
    \   return is;\n}\n\n#line 4 \"test/yosupo_Factorize.test.cpp\"\n\n#line 1 \"\
    type/int128.cpp\"\n// 2^127 = 170141183460469231731687303715884105728 ~ 10^38\n\
    \ \nostream &operator<<(ostream &os,const __int128 n){\n    if(n==0){\n      \
    \  os<<0;\n        return os;\n    }\n    __int128 num=n;\n    bool neg=false;\n\
    \    if(num<0)neg=true,num=-num;\n    string res=\"\";\n    while(num>0){\n  \
    \      res.push_back('0'+num%10);\n        num/=10;\n    }\n    if(neg) res.push_back('-');\n\
    \    reverse(begin(res),end(res));\n    os<<res;\n    return os;\n}\n \nistream\
    \ &operator>>(istream &is,__int128 &n){\n    string s;\n    is>>s;\n    int idx=0;\n\
    \    bool neg=false;\n    if(s[0]=='-')neg=true,idx++;\n    n=0;\n    for(;idx<(int)s.size();idx++){\n\
    \        n=10*n+s[idx]-'0';\n    }\n    if(neg) n=-n;\n    return is;\n}\n\n__int128\
    \ abs128(__int128 x){\n    return x<0?-x:x;\n}\n \n__int128 gcd128(__int128 a,__int128\
    \ b){\n    if(a==0) return b;\n    if(b==0) return a;\n    return b>0?gcd128(b,a%b):a;\n\
    }\nusing int128=__int128;\n#line 6 \"test/yosupo_Factorize.test.cpp\"\n\n#line\
    \ 1 \"Math/PollardRho.cpp\"\ntemplate<typename T>\nstruct FastPrime{\n    private:\n\
    \n    T pow_mod(T a,T n,T m){\n        T ret=1;\n        while(n){\n         \
    \   if(n&1) ret=ret*a%m;\n            a=a*a%m;\n            n>>=1;\n        }\n\
    \        return ret;\n    }\n\n    T gcdT(T a,T b){\n        if(a==0) return b;\n\
    \        if(b==0) return a;\n        return b>0?gcdT(b,a%b):a;\n    }\n\n    T\
    \ pollard_rho_single(T n){\n        auto f=[&](T x){return (x*x+1)%n;};\n    \
    \    if(miller_rabin(n)) return n;\n        if(!(n&1)) return 2;\n        T a=0;\n\
    \        while(true){\n            a++;\n            T x=a;\n            T y=f(x);\n\
    \            while(true){\n                T g=gcdT(y-x+n,n);\n              \
    \  if(g==0 or g==n) break;\n                if(g!=1) return g;\n             \
    \   x=f(x);\n                y=f(f(y));\n            }\n        }\n    }\n\n \
    \   public:\n    bool miller_rabin(T n){\n        if(n<=1) return false;\n   \
    \     if(n==2) return true;\n        if(n%2==0) return false;\n        T d=n-1,s=0;\n\
    \        while(!(d&1))d>>=1,s++;// n-1=2^s*d\n        for(T a:{2,3,5,7,11,13,17,19,23,29,31,37}){\n\
    \            if(n<=a) break;\n            T y=pow_mod(a,d,n);// y=a^d (mod n)\n\
    \            T t;\n            for(t=d;t<n-1 and y!=1 and y!=n-1;t<<=1) y=y*y%n;\n\
    \            if(y!=n-1 and t%2==0) return false;\n        }\n        return true;\n\
    \    }\n\n    vector<T> factorize(T n){\n        if(n==1) return {};\n       \
    \ T x=pollard_rho_single(n);\n        if(x==n) return {x};\n        vector<T>\
    \ l=factorize(x);\n        vector<T> r=factorize(n/x);\n        l.insert(l.end(),r.begin(),r.end());\n\
    \        return l;\n    }\n};\n#line 8 \"test/yosupo_Factorize.test.cpp\"\n\n\
    signed main(){\n    FastPrime<int128> F;\n\n    int q;cin>>q;\n    while(q--){\n\
    \        int128 x;cin>>x;\n        auto res=F.factorize(x);\n        sort(ALL(res));\n\
    \        cout<<res.size()<<\" \"<<res<<\"\\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ \"../template.cpp\"\n\n#include \"../type/int128.cpp\"\n\n#include \"../Math/PollardRho.cpp\"\
    \n\nsigned main(){\n    FastPrime<int128> F;\n\n    int q;cin>>q;\n    while(q--){\n\
    \        int128 x;cin>>x;\n        auto res=F.factorize(x);\n        sort(ALL(res));\n\
    \        cout<<res.size()<<\" \"<<res<<\"\\n\";\n    }\n    return 0;\n}\n"
  dependsOn:
  - template.cpp
  - type/int128.cpp
  - Math/PollardRho.cpp
  isVerificationFile: true
  path: test/yosupo_Factorize.test.cpp
  requiredBy: []
  timestamp: '2021-01-10 13:28:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_Factorize.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Factorize.test.cpp
- /verify/test/yosupo_Factorize.test.cpp.html
title: test/yosupo_Factorize.test.cpp
---

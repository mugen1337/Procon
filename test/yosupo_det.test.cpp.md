---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':heavy_check_mark:'
    path: type/Matrix.cpp
    title: type/Matrix.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo_det.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\
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
    \   return is;\n}\n\n#line 4 \"test/yosupo_det.test.cpp\"\n\n#line 1 \"type/modint.cpp\"\
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
    \ (is);}\n    static int get_mod(){return Mod;}\n};\n#line 6 \"test/yosupo_det.test.cpp\"\
    \nusing mint=ModInt<998244353>;\n\n#line 1 \"type/Matrix.cpp\"\ntemplate<typename\
    \ T>\nstruct Matrix{\n    vector<vector<T>> a;\n\n    Matrix(){}\n    Matrix(int\
    \ n):a(n,vector<T>(n,0)){}\n    Matrix(int h,int w):a(h,vector<T>(w,0)){}\n\n\
    \    int h(){return (int)a.size();}\n    int w(){return (int)a[0].size();}\n\n\
    \    const vector<T> &operator[](int k)const{\n        return a.at(k);// reference\
    \   \n    }\n    vector<T> &operator[](int k){\n        return a.at(k);\n    }\n\
    \n    Matrix id(int n){\n        Matrix ret(n);\n        for(int i=0;i<n;i++)\
    \ ret[i][i]=1;\n        return ret;\n    }\n\n    Matrix &operator+=(const Matrix\
    \ &rhs){\n        assert(h()==rhs.h() and w()==rhs.w());\n        for(int i=0;i<h();i++)for(int\
    \ j=0;j<w();j++) (*this)[i][j]+=rhs[i][j];\n        return (*this);\n    }\n \
    \   Matrix &operator-=(const Matrix &rhs){\n        assert(h()==rhs.h() and w()==rhs.w());\n\
    \        for(int i=0;i<h();i++)for(int j=0;j<w();j++) (*this)[i][j]-=rhs[i][j];\n\
    \        return (*this);\n    }\n    Matrix &operator*=(const Matrix &rhs){\n\
    \        assert(w()==rhs.h());\n        vector<vector<T>> res(h(),vector<T>(rhs.w()));\n\
    \        for(int i=0;i<h();i++)for(int j=0;j<rhs.w();j++)for(int k=0;k<w();k++)\n\
    \            res[i][j]=res[i][j]+(*this)[i][k]*rhs[k][j];\n        swap(a,res);\n\
    \        return (*this);\n    }\n    Matrix operator+(const Matrix &rhs)const{return\
    \ Matrix(*this)+=rhs;}\n    Matrix operator-(const Matrix &rhs)const{return Matrix(*this)-=rhs;}\n\
    \    Matrix operator*(const Matrix &rhs)const{return Matrix(*this)*=rhs;}\n\n\
    \    Matrix pow(long long k){\n        Matrix ret=Matrix::id(h());\n        Matrix\
    \ b=Matrix(*this);\n        while(k){\n            if(k&1) ret*=(*this);\n   \
    \         b*=b;\n            k>>=1;\n        }\n        return ret;\n    }\n\n\
    \    T det(){\n        assert(h()==w());\n        Matrix x(*this);\n        T\
    \ ret=1;\n        for(int i=0;i<w();i++){\n            int idx=-1;\n         \
    \   for(int j=i;j<w();j++)if(x[j][i]!=0) idx=j;\n            if(idx==-1) return\
    \ 0;// \u4E09\u89D2\u884C\u5217\u306E\u5BFE\u89D2\u6210\u5206\u306E1\u3064\u304C\
    0\n            if(i!=idx){\n                ret*=-1;\n                swap(x[i],x[idx]);\n\
    \            }\n            T b=x[i][i];\n            ret*=b;\n            for(int\
    \ j=0;j<w();j++) x[i][j]/=b;\n            for(int j=i+1;j<w();j++){\n        \
    \        T t=x[j][i];\n                for(int k=0;k<w();k++) x[j][k]-=x[i][k]*t;\n\
    \            }\n        }\n        return ret;\n    }\n};\n#line 9 \"test/yosupo_det.test.cpp\"\
    \n\nsigned main(){\n    int n;cin>>n;\n    Matrix<mint> mat(n);\n    rep(i,n)rep(j,n)\
    \ cin>>mat[i][j];\n    cout<<mat.det()<<endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ \"../template.cpp\"\n\n#include \"../type/modint.cpp\"\nusing mint=ModInt<998244353>;\n\
    \n#include \"../type/Matrix.cpp\"\n\nsigned main(){\n    int n;cin>>n;\n    Matrix<mint>\
    \ mat(n);\n    rep(i,n)rep(j,n) cin>>mat[i][j];\n    cout<<mat.det()<<endl;\n\
    \    return 0;\n}\n"
  dependsOn:
  - template.cpp
  - type/modint.cpp
  - type/Matrix.cpp
  isVerificationFile: true
  path: test/yosupo_det.test.cpp
  requiredBy: []
  timestamp: '2021-01-06 01:30:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_det.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_det.test.cpp
- /verify/test/yosupo_det.test.cpp.html
title: test/yosupo_det.test.cpp
---

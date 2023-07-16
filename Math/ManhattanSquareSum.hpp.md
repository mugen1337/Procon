---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/SegmentTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: type/modint.hpp
    title: type/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://yukicoder.me/problems/no/1649
  bundledCode: "#line 1 \"type/modint.hpp\"\ntemplate<int Mod>\nstruct ModInt{\n \
    \   int x;\n    ModInt():x(0){}\n    ModInt(int y): x (y >= 0 ? y % Mod : (Mod\
    \ - (-y) % Mod) % Mod){}\n    ModInt(long long y){\n        if (y >= 0)\n    \
    \    {\n            x = (int)(y % (ll)(Mod));\n        }\n        else\n     \
    \   {\n            int tmp = (int)((-y) % (ll)Mod);\n            x = (Mod - tmp)\
    \ % Mod;\n        }\n    }\n    ModInt &operator+=(const ModInt &p){\n       \
    \ if((x += p.x) >= Mod) x -= Mod;\n        return *this;\n    }\n    ModInt &operator-=(const\
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
    \ (is);}\n    static int get_mod(){return Mod;}\n};\n#line 1 \"SegmentTree/SegmentTree.hpp\"\
    \ntemplate<typename Monoid>\nstruct SegmentTree{\n    using F=function<Monoid(Monoid,Monoid)>;\n\
    \n    private:\n    int sz;\n    vector<Monoid> seg;\n\n    Monoid query(int a,int\
    \ b,int k,int l,int r){\n        if(a<=l and r<=b)   return seg[k];\n        if(b<=l\
    \ or r<=a)    return M0;\n        Monoid L=query(a,b,2*k,l,(l+r)/2);\n       \
    \ Monoid R=query(a,b,2*k+1,(l+r)/2,r);\n        return f(L,R);\n    }\n    template<typename\
    \ C>\n    int find_first(int a,const C &check,Monoid &acc,int k,int l,int r){\n\
    \        if(k>=sz){\n            acc=f(acc,seg[k]);\n            if(check(acc))\
    \  return -1;\n            else            return k-sz;\n        }\n        int\
    \ m=(l+r)/2;\n        if(m<=a) return find_first(a,check,acc,2*k+1,m,r);\n   \
    \     if(a<=l and check(f(acc,seg[k]))){\n            acc=f(acc,seg[k]);\n   \
    \         return -1;\n        }\n        int x=find_first(a,check,acc,2*k+0,l,m);\n\
    \        if(x>=0) return x;\n        return find_first(a,check,acc,2*k+1,m,r);\n\
    \    }\n    template<typename C>\n    int find_last(int b,const C &check,Monoid\
    \ &acc,int k,int l,int r){\n        if(k>=sz){\n            acc=f(acc,seg[k]);\n\
    \            if(check(acc))  return -1;\n            else            return k-sz+1;//\u3053\
    \u3053\u306Ffalse, +1\u3057\u305F\u4F4D\u7F6E\u306Ftrue\n        }\n        int\
    \ m=(l+r)/2;\n        if(b<=m) return find_last(b,check,acc,2*k,l,m);\n      \
    \  if(r<=b and check(f(acc,seg[k]))){\n            acc=f(acc,seg[k]);\n      \
    \      return -1;\n        }\n        int x=find_last(b,check,acc,2*k+1,m,r);\n\
    \        if(x>=0) return x;\n        return find_last(b,check,acc,2*k,l,m);\n\
    \    }\n\n    public:\n\n    F f;\n    Monoid M0;// \u30E2\u30CE\u30A4\u30C9\u306E\
    \u5143\n    SegmentTree(int n,F f,Monoid M0):f(f),M0(M0){\n        sz=1;\n   \
    \     while(sz<n)sz<<=1;\n        seg.assign(2*sz,M0);\n    }\n    void set(int\
    \ k,Monoid x){\n        seg[k+sz]=x;\n    }\n    void build(){\n        for(int\
    \ k=sz-1;k>0;k--) seg[k]=f(seg[2*k],seg[2*k+1]);\n    }\n    void update(int k,Monoid\
    \ x){\n        k+=sz;\n        seg[k]=x;\n        k>>=1;\n        for(;k;k>>=1)\
    \ seg[k]=f(seg[2*k],seg[2*k+1]);\n    }\n    Monoid query(int a,int b){\n    \
    \    return query(a,b,1,0,sz);\n    }\n    Monoid operator[](const int &k)const{\n\
    \        return seg[k+sz];\n    }\n\n    // http://codeforces.com/contest/914/submission/107505449\n\
    \    // max x, check(query(a, x)) = true \n    template<typename C>\n    int find_first(int\
    \ a,const C &check){\n        Monoid val=M0;\n        return find_first(a,check,val,1,0,sz);\n\
    \    }\n    // http://codeforces.com/contest/914/submission/107505582\n    //\
    \ min x, check(query(x, b)) = true\n    template<typename C>\n    int find_last(int\
    \ b,C &check){\n        Monoid val=M0;\n        return find_last(b,check,val,1,0,sz);\n\
    \    }\n};\n#line 3 \"Math/ManhattanSquareSum.hpp\"\n\nusing mint=ModInt<998244353>;\n\
    \n/*\n https://yukicoder.me/problems/no/1649\n \u5F0F\u5909\u5F62\u3057\u3066\u5C55\
    \u958B\u3059\u308B\u3068\uFF0Csum(sum(|x_i - x_j| |y_i - y_j|))\u304C\u8A08\u7B97\
    \u3067\u304D\u308C\u3070\u3088\u3044\u3068\u308F\u304B\u308B\uFF0E\n \u3053\u308C\
    \u306Fx\u304C\u5927\u304D\u3044\u9806\u304B\u3089\u51E6\u7406\u3059\u308B\u3053\
    \u3068\u3067x\u5074\u306E\u7D76\u5BFE\u5024\u3092\u5916\u3057\uFF0Cy\u5074\u3092\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3067\u7BA1\u7406\u3057\n \u5E73\u9762\u8D70\
    \u67FB\u306E\u3088\u3046\u306A\u611F\u3058\u3067\u89E3\u3051\u308B\n*/\nmint ManhattanSquareSum(vector<ll>\
    \ x,vector<ll> y){\n    int N=(int)x.size();\n    mint ret=0;\n    {\n       \
    \ mint sx=0,sy=0,sxx=0,syy=0;\n        for(int i=0;i<N;i++){\n            ret+=(mint)x[i]*x[i]*i+sxx-sx*x[i]*2;\n\
    \            ret+=(mint)y[i]*y[i]*i+syy-sy*y[i]*2;\n            sx+=x[i],sy+=y[i];\n\
    \            sxx+=(mint)x[i]*x[i];\n            syy+=(mint)y[i]*y[i];\n      \
    \  }\n    }\n\n    {\n        vector<int> idx(N);\n        iota(begin(idx),end(idx),0);\n\
    \        sort(begin(idx),end(idx),[&](int i,int j){return x[i]>x[j];});\n    \
    \    auto nx=x,ny=y;\n        for(int i=0;i<N;i++) nx[i]=x[idx[i]],ny[i]=y[idx[i]];\n\
    \        swap(x,nx);\n        swap(y,ny);\n    }\n\n    {\n        vector<int>\
    \ yid(N),yp(N);\n        iota(begin(yid),end(yid),0);\n        sort(begin(yid),end(yid),[&](int\
    \ i,int j){return y[i]<y[j];});\n        for(int i=0;i<N;i++) yp[yid[i]]=i;\n\n\
    \        using P=pair<mint,mint>;\n        auto segf=[&](P a,P b){\n         \
    \   a.first+=b.first;\n            a.second+=b.second;\n            return a;\n\
    \        };\n        SegmentTree<P> sega(N,segf,P(0,0)),segb(N,segf,P(0,0));\n\
    \        for(int i=0;i<N;i++){\n            sega.set(yp[i],P(y[i],1));\n     \
    \       segb.set(i,P(0,0));\n        }\n        sega.build();\n        segb.build();\n\
    \n        for(int i=0;i<N;i++){\n            int j=yp[i];\n            auto l=sega.query(0,j);\n\
    \            auto r=sega.query(j+1,N);\n            mint add=mint(y[i])*l.second-l.first+r.first-mint(y[i])*r.second;\n\
    \n            l=segb.query(0,j);\n            r=segb.query(j+1,N);\n         \
    \   mint sub=mint(y[i])*l.second-l.first+r.first-mint(y[i])*r.second;\n      \
    \      ret+=(add-sub)*x[i]*2;\n            sega.update(j,P(0,0));\n          \
    \  segb.update(j,P(y[i],1));\n        }\n    }\n    return ret;\n}\n"
  code: "#include \"../type/modint.hpp\"\n#include \"../SegmentTree/SegmentTree.hpp\"\
    \n\nusing mint=ModInt<998244353>;\n\n/*\n https://yukicoder.me/problems/no/1649\n\
    \ \u5F0F\u5909\u5F62\u3057\u3066\u5C55\u958B\u3059\u308B\u3068\uFF0Csum(sum(|x_i\
    \ - x_j| |y_i - y_j|))\u304C\u8A08\u7B97\u3067\u304D\u308C\u3070\u3088\u3044\u3068\
    \u308F\u304B\u308B\uFF0E\n \u3053\u308C\u306Fx\u304C\u5927\u304D\u3044\u9806\u304B\
    \u3089\u51E6\u7406\u3059\u308B\u3053\u3068\u3067x\u5074\u306E\u7D76\u5BFE\u5024\
    \u3092\u5916\u3057\uFF0Cy\u5074\u3092\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3067\
    \u7BA1\u7406\u3057\n \u5E73\u9762\u8D70\u67FB\u306E\u3088\u3046\u306A\u611F\u3058\
    \u3067\u89E3\u3051\u308B\n*/\nmint ManhattanSquareSum(vector<ll> x,vector<ll>\
    \ y){\n    int N=(int)x.size();\n    mint ret=0;\n    {\n        mint sx=0,sy=0,sxx=0,syy=0;\n\
    \        for(int i=0;i<N;i++){\n            ret+=(mint)x[i]*x[i]*i+sxx-sx*x[i]*2;\n\
    \            ret+=(mint)y[i]*y[i]*i+syy-sy*y[i]*2;\n            sx+=x[i],sy+=y[i];\n\
    \            sxx+=(mint)x[i]*x[i];\n            syy+=(mint)y[i]*y[i];\n      \
    \  }\n    }\n\n    {\n        vector<int> idx(N);\n        iota(begin(idx),end(idx),0);\n\
    \        sort(begin(idx),end(idx),[&](int i,int j){return x[i]>x[j];});\n    \
    \    auto nx=x,ny=y;\n        for(int i=0;i<N;i++) nx[i]=x[idx[i]],ny[i]=y[idx[i]];\n\
    \        swap(x,nx);\n        swap(y,ny);\n    }\n\n    {\n        vector<int>\
    \ yid(N),yp(N);\n        iota(begin(yid),end(yid),0);\n        sort(begin(yid),end(yid),[&](int\
    \ i,int j){return y[i]<y[j];});\n        for(int i=0;i<N;i++) yp[yid[i]]=i;\n\n\
    \        using P=pair<mint,mint>;\n        auto segf=[&](P a,P b){\n         \
    \   a.first+=b.first;\n            a.second+=b.second;\n            return a;\n\
    \        };\n        SegmentTree<P> sega(N,segf,P(0,0)),segb(N,segf,P(0,0));\n\
    \        for(int i=0;i<N;i++){\n            sega.set(yp[i],P(y[i],1));\n     \
    \       segb.set(i,P(0,0));\n        }\n        sega.build();\n        segb.build();\n\
    \n        for(int i=0;i<N;i++){\n            int j=yp[i];\n            auto l=sega.query(0,j);\n\
    \            auto r=sega.query(j+1,N);\n            mint add=mint(y[i])*l.second-l.first+r.first-mint(y[i])*r.second;\n\
    \n            l=segb.query(0,j);\n            r=segb.query(j+1,N);\n         \
    \   mint sub=mint(y[i])*l.second-l.first+r.first-mint(y[i])*r.second;\n      \
    \      ret+=(add-sub)*x[i]*2;\n            sega.update(j,P(0,0));\n          \
    \  segb.update(j,P(y[i],1));\n        }\n    }\n    return ret;\n}"
  dependsOn:
  - type/modint.hpp
  - SegmentTree/SegmentTree.hpp
  isVerificationFile: false
  path: Math/ManhattanSquareSum.hpp
  requiredBy: []
  timestamp: '2023-07-16 21:56:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/ManhattanSquareSum.hpp
layout: document
redirect_from:
- /library/Math/ManhattanSquareSum.hpp
- /library/Math/ManhattanSquareSum.hpp.html
title: Math/ManhattanSquareSum.hpp
---

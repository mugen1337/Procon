---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/NTTmodint.cpp\"\ntemplate<typename Mint>\nstruct NTTmodint{\n\
    \    vector<Mint> dw,idw;\n    int max_base,Mod;\n    Mint root;\n \n    NTTmodint():Mod(Mint::get_mod()){\n\
    \        ll tmp=Mod-1;\n        max_base=0;\n        while(tmp%2==0) tmp>>=1,max_base++;\n\
    \        root=2;\n        while(root.pow((Mod-1)>>1).x==1) root+=1;\n        dw.resize(max_base);idw.resize(max_base);\n\
    \        for(int i=0;i<max_base;i++){\n            dw[i]=-root.pow((Mod-1)>>(i+2));\n\
    \            idw[i]=Mint(1)/dw[i];\n        }\n    }\n    void ntt(vector<Mint>\
    \ &a){\n        int n=(int)a.size();\n        for(int m=n;m>>=1;){\n         \
    \   Mint w=1;\n            for(int s=0,k=0;s<n;s+=2*m){\n                for(int\
    \ i=s,j=s+m;i<s+m;i++,j++){\n                    auto x=a[i],y=a[j]*w;\n     \
    \               a[i]=x+y,a[j]=x-y;\n                }\n                w*=dw[__builtin_ctz(++k)];\n\
    \            }\n        }\n    }\n    void intt(vector<Mint> &a,bool f=true){\n\
    \        int n=(int)a.size();\n        for(int m=1;m<n;m*=2){\n            Mint\
    \ w=1;\n            for(int s=0,k=0;s<n;s+=2*m){\n                for(int i=s,j=s+m;i<s+m;i++,j++){\n\
    \                    auto x=a[i],y=a[j];\n                    a[i]=x+y,a[j]=(x-y)*w;\n\
    \                }\n                w*=idw[__builtin_ctz(++k)];\n            }\n\
    \        }\n        if(f){\n            Mint inv_sz=Mint(1)/n;\n            for(int\
    \ i=0;i<n;i++) a[i]*=inv_sz;\n        }\n    }\n    vector<Mint> multiply(vector<Mint>\
    \ a,vector<Mint> b){\n        int need=(int)a.size()+b.size()-1;\n        int\
    \ nbase=1;\n        while((1<<nbase)<need) nbase++;\n        int sz=1<<nbase;\n\
    \        a.resize(sz,0);b.resize(sz,0);\n        ntt(a);ntt(b);\n        Mint\
    \ inv_sz=Mint(1)/sz;\n        for(int i=0;i<sz;i++) a[i]*=b[i]*inv_sz;\n     \
    \   intt(a,false);\n        a.resize(need);\n        return a;\n    }\n};\n"
  code: "template<typename Mint>\nstruct NTTmodint{\n    vector<Mint> dw,idw;\n  \
    \  int max_base,Mod;\n    Mint root;\n \n    NTTmodint():Mod(Mint::get_mod()){\n\
    \        ll tmp=Mod-1;\n        max_base=0;\n        while(tmp%2==0) tmp>>=1,max_base++;\n\
    \        root=2;\n        while(root.pow((Mod-1)>>1).x==1) root+=1;\n        dw.resize(max_base);idw.resize(max_base);\n\
    \        for(int i=0;i<max_base;i++){\n            dw[i]=-root.pow((Mod-1)>>(i+2));\n\
    \            idw[i]=Mint(1)/dw[i];\n        }\n    }\n    void ntt(vector<Mint>\
    \ &a){\n        int n=(int)a.size();\n        for(int m=n;m>>=1;){\n         \
    \   Mint w=1;\n            for(int s=0,k=0;s<n;s+=2*m){\n                for(int\
    \ i=s,j=s+m;i<s+m;i++,j++){\n                    auto x=a[i],y=a[j]*w;\n     \
    \               a[i]=x+y,a[j]=x-y;\n                }\n                w*=dw[__builtin_ctz(++k)];\n\
    \            }\n        }\n    }\n    void intt(vector<Mint> &a,bool f=true){\n\
    \        int n=(int)a.size();\n        for(int m=1;m<n;m*=2){\n            Mint\
    \ w=1;\n            for(int s=0,k=0;s<n;s+=2*m){\n                for(int i=s,j=s+m;i<s+m;i++,j++){\n\
    \                    auto x=a[i],y=a[j];\n                    a[i]=x+y,a[j]=(x-y)*w;\n\
    \                }\n                w*=idw[__builtin_ctz(++k)];\n            }\n\
    \        }\n        if(f){\n            Mint inv_sz=Mint(1)/n;\n            for(int\
    \ i=0;i<n;i++) a[i]*=inv_sz;\n        }\n    }\n    vector<Mint> multiply(vector<Mint>\
    \ a,vector<Mint> b){\n        int need=(int)a.size()+b.size()-1;\n        int\
    \ nbase=1;\n        while((1<<nbase)<need) nbase++;\n        int sz=1<<nbase;\n\
    \        a.resize(sz,0);b.resize(sz,0);\n        ntt(a);ntt(b);\n        Mint\
    \ inv_sz=Mint(1)/sz;\n        for(int i=0;i<sz;i++) a[i]*=b[i]*inv_sz;\n     \
    \   intt(a,false);\n        a.resize(need);\n        return a;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/NTTmodint.cpp
  requiredBy: []
  timestamp: '2021-07-06 20:59:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/NTTmodint.cpp
layout: document
redirect_from:
- /library/Math/NTTmodint.cpp
- /library/Math/NTTmodint.cpp.html
title: Math/NTTmodint.cpp
---

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
  bundledCode: "#line 1 \"Graph2/ChromaticNumber.cpp\"\ntemplate<typename T>\nint\
    \ chromatic_number(Graph<T> G){\n    int N=G.size();\n    assert(N<28);\n\n  \
    \  vector<int> E(N,0);\n    for(int i=0;i<N;i++){\n        E[i]|=(1<<i);\n   \
    \     for(auto &e:G[i]) E[i]|=(1<<e.to);\n    }\n\n    // I[S] := S\u306E\u90E8\
    \u5206\u96C6\u5408\u306B\u3042\u308B\u72EC\u7ACB\u96C6\u5408\u306E\u500B\u6570\
    \n    vector<int> I(1<<N,0);\n    I[0]=1;\n    for(int S=1;S<(1<<N);S++){\n  \
    \      int v=__builtin_ctz(S);// \u4EE3\u8868\u70B9\n        I[S]=I[S&~(1<<v)]+I[S&~E[v]];\n\
    \    }\n\n    auto Pow=[](ll a,int k,ll p){\n        ll ret=1;\n        for(;k;k>>=1){\n\
    \            if(k&1) ret=ret*a%p;\n            a=a*a%p;\n        }\n        return\
    \ ret;\n    };\n\n    for(int k=1;k<=N;k++){\n        // g[S] := S\u3092\u3061\
    \u3087\u3046\u3069\u30AB\u30D0\u30FC\u3059\u308Bk\u500B\u306E\u72EC\u7ACB\u96C6\
    \u5408\u306E\u7D44\u306E\u500B\u6570\n        // f[S] := S\u306E\u90E8\u5206\u96C6\
    \u5408\u304B\u3089k\u500B\u91CD\u8907\u3092\u8A31\u3057\u3066\u9078\u3076\u500B\
    \u6570\n        //  -> F[S] = I[S]^k {(a or b .. ) * (a or b ...)...}\n      \
    \  //  -> f[S] = sum_{T in S} g[T]\n        //  -> g[S] = sum_{T in S} (-1)^(|S|-|T|)\
    \ f[T]\n        for(ll p:{1000000007,1000000021}){\n            ll g=0;\n    \
    \        for(int S=0;S<(1<<N);S++){\n                if((N-__builtin_popcount(S))&1)\
    \ g-=Pow(I[S],k,p);\n                else                            g+=Pow(I[S],k,p);\n\
    \                g=(g+p)%p;\n            }\n            if(g>0) return k;\n  \
    \      }\n    }\n    return 0;\n}\n"
  code: "template<typename T>\nint chromatic_number(Graph<T> G){\n    int N=G.size();\n\
    \    assert(N<28);\n\n    vector<int> E(N,0);\n    for(int i=0;i<N;i++){\n   \
    \     E[i]|=(1<<i);\n        for(auto &e:G[i]) E[i]|=(1<<e.to);\n    }\n\n   \
    \ // I[S] := S\u306E\u90E8\u5206\u96C6\u5408\u306B\u3042\u308B\u72EC\u7ACB\u96C6\
    \u5408\u306E\u500B\u6570\n    vector<int> I(1<<N,0);\n    I[0]=1;\n    for(int\
    \ S=1;S<(1<<N);S++){\n        int v=__builtin_ctz(S);// \u4EE3\u8868\u70B9\n \
    \       I[S]=I[S&~(1<<v)]+I[S&~E[v]];\n    }\n\n    auto Pow=[](ll a,int k,ll\
    \ p){\n        ll ret=1;\n        for(;k;k>>=1){\n            if(k&1) ret=ret*a%p;\n\
    \            a=a*a%p;\n        }\n        return ret;\n    };\n\n    for(int k=1;k<=N;k++){\n\
    \        // g[S] := S\u3092\u3061\u3087\u3046\u3069\u30AB\u30D0\u30FC\u3059\u308B\
    k\u500B\u306E\u72EC\u7ACB\u96C6\u5408\u306E\u7D44\u306E\u500B\u6570\n        //\
    \ f[S] := S\u306E\u90E8\u5206\u96C6\u5408\u304B\u3089k\u500B\u91CD\u8907\u3092\
    \u8A31\u3057\u3066\u9078\u3076\u500B\u6570\n        //  -> F[S] = I[S]^k {(a or\
    \ b .. ) * (a or b ...)...}\n        //  -> f[S] = sum_{T in S} g[T]\n       \
    \ //  -> g[S] = sum_{T in S} (-1)^(|S|-|T|) f[T]\n        for(ll p:{1000000007,1000000021}){\n\
    \            ll g=0;\n            for(int S=0;S<(1<<N);S++){\n               \
    \ if((N-__builtin_popcount(S))&1) g-=Pow(I[S],k,p);\n                else    \
    \                        g+=Pow(I[S],k,p);\n                g=(g+p)%p;\n     \
    \       }\n            if(g>0) return k;\n        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph2/ChromaticNumber.cpp
  requiredBy: []
  timestamp: '2021-07-31 01:33:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph2/ChromaticNumber.cpp
layout: document
redirect_from:
- /library/Graph2/ChromaticNumber.cpp
- /library/Graph2/ChromaticNumber.cpp.html
title: Graph2/ChromaticNumber.cpp
---

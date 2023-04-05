---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://www.ioi-jp.org/camp/2018/2018-sp-tasks/day4/candies.pdf
  bundledCode: "#line 1 \"tips/JOI-Candies.hpp\"\n// https://www.ioi-jp.org/camp/2018/2018-sp-tasks/day4/candies.pdf\n\
    /*\n\u5404 k (0 <= k <= ceil(|A| / 2))\u306B\u95A2\u3057\uFF0CA\u304B\u3089\u96A3\
    \u308A\u5408\u308F\u306A\u3044\u3088\u3046\u306Bk\u500B\u8981\u7D20\u3092\u9078\
    \u3093\u3060\u6642\n\u7DCF\u548C\u306E\u6700\u5927\u5024\u3092\u6C42\u3081\u308B\
    \n\ninput  : A\noutput : ret[i] := (k=i)\u306E\u6642\u306E\u7B54\u3048\n*/\ntemplate<typename\
    \ T>\nvector<T> JOI_Candies(vector<T> A){\n    T inf=numeric_limits<T>::max()/4;\n\
    \    int N=(int)A.size();\n    int K=(N+1)/2;\n    vector<T> ret(K+1,0);\n   \
    \ T res=0;\n\n    vector<int> L(N),R(N);\n    using P=pair<T,int>;\n    priority_queue<P>\
    \ que;\n    for(int i=0;i<N;i++){\n        L[i]=i-1;\n        R[i]=i+1;\n    \
    \    que.emplace(A[i],i);\n    }\n\n    ret[0]=0;\n    for(int k=1;k<=K;k++){\n\
    \        T x;int i;\n        do{\n            tie(x,i)=que.top();\n          \
    \  que.pop();\n        }while(A[i]!=x);\n\n        ret[k]=(res+=x);\n        \n\
    \        bool f=(L[i]>=0 and R[i]<N);\n        A[i]*=-1;\n        if(L[i]>=0){\n\
    \            A[i]+=A[L[i]];\n            A[L[i]]=-inf;\n            L[i]=L[L[i]];\n\
    \            if(L[i]>=0) R[L[i]]=i;\n        }\n        if(R[i]<N){\n        \
    \    A[i]+=A[R[i]];\n            A[R[i]]=-inf;\n            R[i]=R[R[i]];\n  \
    \          if(R[i]<N) L[R[i]]=i;\n        }\n\n        if(f) que.emplace(A[i],i);\n\
    \        else  A[i]=-inf;\n    }\n    return ret;\n}\n"
  code: "// https://www.ioi-jp.org/camp/2018/2018-sp-tasks/day4/candies.pdf\n/*\n\u5404\
    \ k (0 <= k <= ceil(|A| / 2))\u306B\u95A2\u3057\uFF0CA\u304B\u3089\u96A3\u308A\
    \u5408\u308F\u306A\u3044\u3088\u3046\u306Bk\u500B\u8981\u7D20\u3092\u9078\u3093\
    \u3060\u6642\n\u7DCF\u548C\u306E\u6700\u5927\u5024\u3092\u6C42\u3081\u308B\n\n\
    input  : A\noutput : ret[i] := (k=i)\u306E\u6642\u306E\u7B54\u3048\n*/\ntemplate<typename\
    \ T>\nvector<T> JOI_Candies(vector<T> A){\n    T inf=numeric_limits<T>::max()/4;\n\
    \    int N=(int)A.size();\n    int K=(N+1)/2;\n    vector<T> ret(K+1,0);\n   \
    \ T res=0;\n\n    vector<int> L(N),R(N);\n    using P=pair<T,int>;\n    priority_queue<P>\
    \ que;\n    for(int i=0;i<N;i++){\n        L[i]=i-1;\n        R[i]=i+1;\n    \
    \    que.emplace(A[i],i);\n    }\n\n    ret[0]=0;\n    for(int k=1;k<=K;k++){\n\
    \        T x;int i;\n        do{\n            tie(x,i)=que.top();\n          \
    \  que.pop();\n        }while(A[i]!=x);\n\n        ret[k]=(res+=x);\n        \n\
    \        bool f=(L[i]>=0 and R[i]<N);\n        A[i]*=-1;\n        if(L[i]>=0){\n\
    \            A[i]+=A[L[i]];\n            A[L[i]]=-inf;\n            L[i]=L[L[i]];\n\
    \            if(L[i]>=0) R[L[i]]=i;\n        }\n        if(R[i]<N){\n        \
    \    A[i]+=A[R[i]];\n            A[R[i]]=-inf;\n            R[i]=R[R[i]];\n  \
    \          if(R[i]<N) L[R[i]]=i;\n        }\n\n        if(f) que.emplace(A[i],i);\n\
    \        else  A[i]=-inf;\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: tips/JOI-Candies.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tips/JOI-Candies.hpp
layout: document
title: "JOI \u98F4"
---

# 概要  

配列からk個，隣り合わないように要素を選び，総和の最大化．

# 応用

https://atcoder.jp/contests/abc218/tasks/abc218_h

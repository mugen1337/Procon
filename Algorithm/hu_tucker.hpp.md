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
    - https://atcoder.jp/contests/atc002/submissions/26006416
  bundledCode: "#line 1 \"Algorithm/hu_tucker.hpp\"\n// verify : https://atcoder.jp/contests/atc002/submissions/26006416\n\
    template<typename T>\nT hu_tucker(vector<T> V){\n    T inf=numeric_limits<T>::max()/4;\n\
    \    int N=(int)V.size();\n    vector<LeftistHeap<T>> heaps(N+1);\n    vector<T>\
    \ A(N+2,inf),B(N+1);\n    vector<int> L(N+2),R(N+1);\n    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n\n    for(int i=0;i<N;i++) A[i+1]=V[i];\n    for(int i=0;i<N+1;i++){\n\
    \        L[i]=i-1,R[i]=i+1;\n        B[i]=A[i]+A[i+1];\n        que.emplace(B[i],i);\n\
    \    }\n\n    // heaps[l] <- heaps[r]\n    auto merge=[&](int l,int r){\n    \
    \    heaps[l].meld(heaps[r]);\n        R[l]=R[r],L[R[r]]=l,B[r]=inf+inf;\n   \
    \     return l;\n    };\n\n    T ret=0;\n    for(int fuga=N-1;fuga;fuga--){\n\
    \        T c;int i;\n        do{ tie(c,i)=que.top();que.pop(); }while(B[i]!=c);\n\
    \        ret+=c;\n\n        bool fl=false,fr=false;\n        if(A[i]+A[R[i]]==c)\
    \                fl=true,fr=true;// leaves\n        else if(heaps[i].top()+A[R[i]]==c)\
    \ fr=true,heaps[i].pop();\n        else if(A[i]+heaps[i].top()==c)    fl=true,heaps[i].pop();\n\
    \        else                               heaps[i].pop(),heaps[i].pop();// in\
    \ group\n        heaps[i].push(c);\n        if(fl) i=merge(L[i],i);\n        if(fr)\
    \ i=merge(i,R[i]);\n\n        T nw=A[i]+A[R[i]];\n        chmin(nw,min(A[i],A[R[i]])+heaps[i].top());\n\
    \        {\n            T fs=inf,sc=inf;\n            fs=heaps[i].pop();\n   \
    \         if(!heaps[i].empty()) sc=heaps[i].top();\n            heaps[i].push(fs);\n\
    \            chmin(nw,fs+sc);\n        }\n        que.emplace(B[i]=nw,i);\n  \
    \  }\n    return ret;\n}\n"
  code: "// verify : https://atcoder.jp/contests/atc002/submissions/26006416\ntemplate<typename\
    \ T>\nT hu_tucker(vector<T> V){\n    T inf=numeric_limits<T>::max()/4;\n    int\
    \ N=(int)V.size();\n    vector<LeftistHeap<T>> heaps(N+1);\n    vector<T> A(N+2,inf),B(N+1);\n\
    \    vector<int> L(N+2),R(N+1);\n    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n\n    for(int i=0;i<N;i++) A[i+1]=V[i];\n    for(int i=0;i<N+1;i++){\n\
    \        L[i]=i-1,R[i]=i+1;\n        B[i]=A[i]+A[i+1];\n        que.emplace(B[i],i);\n\
    \    }\n\n    // heaps[l] <- heaps[r]\n    auto merge=[&](int l,int r){\n    \
    \    heaps[l].meld(heaps[r]);\n        R[l]=R[r],L[R[r]]=l,B[r]=inf+inf;\n   \
    \     return l;\n    };\n\n    T ret=0;\n    for(int fuga=N-1;fuga;fuga--){\n\
    \        T c;int i;\n        do{ tie(c,i)=que.top();que.pop(); }while(B[i]!=c);\n\
    \        ret+=c;\n\n        bool fl=false,fr=false;\n        if(A[i]+A[R[i]]==c)\
    \                fl=true,fr=true;// leaves\n        else if(heaps[i].top()+A[R[i]]==c)\
    \ fr=true,heaps[i].pop();\n        else if(A[i]+heaps[i].top()==c)    fl=true,heaps[i].pop();\n\
    \        else                               heaps[i].pop(),heaps[i].pop();// in\
    \ group\n        heaps[i].push(c);\n        if(fl) i=merge(L[i],i);\n        if(fr)\
    \ i=merge(i,R[i]);\n\n        T nw=A[i]+A[R[i]];\n        chmin(nw,min(A[i],A[R[i]])+heaps[i].top());\n\
    \        {\n            T fs=inf,sc=inf;\n            fs=heaps[i].pop();\n   \
    \         if(!heaps[i].empty()) sc=heaps[i].top();\n            heaps[i].push(fs);\n\
    \            chmin(nw,fs+sc);\n        }\n        que.emplace(B[i]=nw,i);\n  \
    \  }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/hu_tucker.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/hu_tucker.hpp
layout: document
redirect_from:
- /library/Algorithm/hu_tucker.hpp
- /library/Algorithm/hu_tucker.hpp.html
title: Algorithm/hu_tucker.hpp
---

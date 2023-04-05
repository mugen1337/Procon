---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_Static_Range_Inversions_Query.test.cpp
    title: test/yosupo_Static_Range_Inversions_Query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/BinaryIndexedTree.hpp\"\ntemplate<typename\
    \ T>\nstruct BinaryIndexedTree{\n    vector<T> data;\n    BinaryIndexedTree()=default;\n\
    \    BinaryIndexedTree(int sz):data(sz+1,0){}\n    BinaryIndexedTree(const vector<T>\
    \ &a):data(a.size()+1,0){\n        for(int i=0;i<(int)a.size();i++)data[i+1]=a[i];\n\
    \        for(int i=1;i<(int)data.size();i++){\n            int j=i+(i&-i);\n \
    \           if(j<(int)data.size()) data[j]+=data[i];\n        }\n    }\n    void\
    \ add(int k,const T &x){for(++k;k<(int)data.size();k+=(k&-k)) data[k]+=x;}\n \
    \   // sum [0,k)\n    T sum(int k){\n        T ret=T();\n        for(;k>0;k-=(k&-k))ret+=data[k];\n\
    \        return ret;\n    }\n    // sum [l,r)\n    T query(int l,int r){\n   \
    \     return sum(r)-sum(l);\n    }\n    T operator[](const int &k){return query(k,k+1);}\n\
    \    // sum[0,i)>=x\u3068\u306A\u308B\u6700\u5C0F\u306Ei\n    int lower_bound(T\
    \ x){\n        int r=1,i=0;\n        while(r<(int)data.size())r<<=1;\n       \
    \ for(;r>0;r>>=1)if(i+r<(int)data.size() and data[i+r]<x){\n            x-=data[i+r];i+=r;\n\
    \        }\n        return i+1;\n    }\n};\n"
  code: "template<typename T>\nstruct BinaryIndexedTree{\n    vector<T> data;\n  \
    \  BinaryIndexedTree()=default;\n    BinaryIndexedTree(int sz):data(sz+1,0){}\n\
    \    BinaryIndexedTree(const vector<T> &a):data(a.size()+1,0){\n        for(int\
    \ i=0;i<(int)a.size();i++)data[i+1]=a[i];\n        for(int i=1;i<(int)data.size();i++){\n\
    \            int j=i+(i&-i);\n            if(j<(int)data.size()) data[j]+=data[i];\n\
    \        }\n    }\n    void add(int k,const T &x){for(++k;k<(int)data.size();k+=(k&-k))\
    \ data[k]+=x;}\n    // sum [0,k)\n    T sum(int k){\n        T ret=T();\n    \
    \    for(;k>0;k-=(k&-k))ret+=data[k];\n        return ret;\n    }\n    // sum\
    \ [l,r)\n    T query(int l,int r){\n        return sum(r)-sum(l);\n    }\n   \
    \ T operator[](const int &k){return query(k,k+1);}\n    // sum[0,i)>=x\u3068\u306A\
    \u308B\u6700\u5C0F\u306Ei\n    int lower_bound(T x){\n        int r=1,i=0;\n \
    \       while(r<(int)data.size())r<<=1;\n        for(;r>0;r>>=1)if(i+r<(int)data.size()\
    \ and data[i+r]<x){\n            x-=data[i+r];i+=r;\n        }\n        return\
    \ i+1;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_Static_Range_Inversions_Query.test.cpp
documentation_of: DataStructure/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/DataStructure/BinaryIndexedTree.hpp
- /library/DataStructure/BinaryIndexedTree.hpp.html
title: DataStructure/BinaryIndexedTree.hpp
---

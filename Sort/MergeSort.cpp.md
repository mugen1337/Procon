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
  bundledCode: "#line 1 \"Sort/MergeSort.cpp\"\n// [L, R)\ntemplate<typename T>\n\
    void mergesort(vector<T> &v,int L=0,int R=-1){\n    if(R<0) R=(int)v.size();\n\
    \    function<void(int,int)> split_merge=[&](int l,int r){\n        if(l>=r) return\
    \ ;\n        bool f=true;\n        for(int i=l;i<r-1;i++)if(v[i]>v[i+1]) f=false;\n\
    \        if(f) return ;\n        int m=(l+r)/2;\n        split_merge(l,m);\n \
    \       split_merge(m,r);\n        vector<T> rpl;\n        for(int i=l,j=m;i<m\
    \ or j<r;){\n            if(j>=r or (i<m and v[i]<=v[j])) rpl.push_back(v[i++]);\n\
    \            else                             rpl.push_back(v[j++]);\n       \
    \ }\n        for(int i=0;i<r-l;i++) v[l+i]=rpl[i];\n    };\n    split_merge(L,R);\n\
    \    return ;\n}\n"
  code: "// [L, R)\ntemplate<typename T>\nvoid mergesort(vector<T> &v,int L=0,int\
    \ R=-1){\n    if(R<0) R=(int)v.size();\n    function<void(int,int)> split_merge=[&](int\
    \ l,int r){\n        if(l>=r) return ;\n        bool f=true;\n        for(int\
    \ i=l;i<r-1;i++)if(v[i]>v[i+1]) f=false;\n        if(f) return ;\n        int\
    \ m=(l+r)/2;\n        split_merge(l,m);\n        split_merge(m,r);\n        vector<T>\
    \ rpl;\n        for(int i=l,j=m;i<m or j<r;){\n            if(j>=r or (i<m and\
    \ v[i]<=v[j])) rpl.push_back(v[i++]);\n            else                      \
    \       rpl.push_back(v[j++]);\n        }\n        for(int i=0;i<r-l;i++) v[l+i]=rpl[i];\n\
    \    };\n    split_merge(L,R);\n    return ;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Sort/MergeSort.cpp
  requiredBy: []
  timestamp: '2021-02-01 11:45:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Sort/MergeSort.cpp
layout: document
redirect_from:
- /library/Sort/MergeSort.cpp
- /library/Sort/MergeSort.cpp.html
title: Sort/MergeSort.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_3_c.test.cpp
    title: test/AOJ_DPL_3_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/LargestRectangle.hpp\"\ntemplate<typename INT>\nINT LargestRectangle(vector<INT>\
    \ v){\n    int n=(int)v.size();\n    INT inf=numeric_limits<INT>::max()/2;\n \
    \   stack<pair<INT,INT>> st;\n    st.emplace(-inf,-1);// \u3070\u3093\u307A\u3044\
    \u3093\n    INT ret=0;\n    for(int i=0;i<n;i++){\n        while(v[i]<st.top().first){\n\
    \            auto p=st.top();st.pop();\n            ret=max(ret,(i-st.top().second-1)*p.first);\n\
    \        }\n        st.emplace(v[i],i);\n    }\n    while(!st.empty()){\n    \
    \    auto p=st.top();st.pop();\n        if(p.first==-inf) continue;\n        ret=max(ret,(n-st.top().second-1)*p.first);\n\
    \    }\n    return ret;\n}\n"
  code: "template<typename INT>\nINT LargestRectangle(vector<INT> v){\n    int n=(int)v.size();\n\
    \    INT inf=numeric_limits<INT>::max()/2;\n    stack<pair<INT,INT>> st;\n   \
    \ st.emplace(-inf,-1);// \u3070\u3093\u307A\u3044\u3093\n    INT ret=0;\n    for(int\
    \ i=0;i<n;i++){\n        while(v[i]<st.top().first){\n            auto p=st.top();st.pop();\n\
    \            ret=max(ret,(i-st.top().second-1)*p.first);\n        }\n        st.emplace(v[i],i);\n\
    \    }\n    while(!st.empty()){\n        auto p=st.top();st.pop();\n        if(p.first==-inf)\
    \ continue;\n        ret=max(ret,(n-st.top().second-1)*p.first);\n    }\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/LargestRectangle.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_DPL_3_c.test.cpp
documentation_of: DP/LargestRectangle.hpp
layout: document
title: "Largest Rectangle (\u6700\u5927\u9577\u65B9\u5F62)"
---

## 概要  
ヒストグラムH内に存在する最大長方形を求める．  

## 計算量  
O(|H|)

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DPL_3_c.test.cpp
    title: test/AOJ_DPL_3_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/LargestRectangle.cpp\"\ntemplate<typename INT>\nINT LargestRectangle(vector<INT>\
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
  path: DP/LargestRectangle.cpp
  requiredBy: []
  timestamp: '2021-01-24 02:17:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_DPL_3_c.test.cpp
documentation_of: DP/LargestRectangle.cpp
layout: document
redirect_from:
- /library/DP/LargestRectangle.cpp
- /library/DP/LargestRectangle.cpp.html
title: DP/LargestRectangle.cpp
---

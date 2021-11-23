---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc223/submissions/26660184
  bundledCode: "#line 1 \"DataStructure/StaticRangeSpanQuery.cpp\"\n/*\n * ref : https://atcoder.jp/contests/abc223/submissions/26660184\n\
    \ * verified : https://atcoder.jp/contests/abc223/submissions/26660184\n * \n\
    \ * b[j] := (1<<j) \u304C\u6700\u5927\u3067\u7ACB\u3063\u3066\u3044\u308B\u57FA\
    \u5E95\n *         \u540C\u6642\u306B\uFF0C\u305D\u306E\u57FA\u5E95\u306E\u53F3\
    \u7AEF\u306Eindex\u3082\u6301\u3064\n * A[i]\u3092\u898B\u308B\u6642\uFF0C\u3044\
    \u3044\u611F\u3058\u306B\u57FA\u5E95\u3092\u5165\u308C\u66FF\u3048\u308B\n*/\n\
    template<typename INT,int B>\nstruct StaticRangeSpanQuery{\n    vector<INT> A;\n\
    \    vector<tuple<int,int,INT,int>> query;\n\n    StaticRangeSpanQuery(vector<INT>\
    \ &A):A(A){}\n\n    // X \u2208 span({A[L,R)}) ?\n    void add_query(int L,int\
    \ R,INT X,int idx=-1){\n        if(idx<0) idx=(int)query.size();\n        query.emplace_back(L,R,X,idx);\n\
    \    }\n\n    vector<bool> build(){\n        vector<vector<tuple<int,INT,int>>>\
    \ Qs(A.size()+1);\n        vector<bool> ans(query.size(),false);\n        for(auto\
    \ [L,R,X,idx]:query) Qs[R].emplace_back(L,X,idx);\n\n        vector<pair<INT,int>>\
    \ b(B);// \u6700\u3082\u53F3\u306E\u57FA\u5E95\n        for(int i=0;i<B;i++) b[i]={INT(1)<<i,-1};\n\
    \n        for(int i=0;i<(int)A.size();i++){\n            pair<INT,int> cur={A[i],i};\n\
    \            for(int j=B-1;j>=0;j--){\n                if((cur.first>>j)&1){\n\
    \                    if(cur.second>b[j].second) swap(cur,b[j]);\n\n          \
    \          cur.first^=b[j].first;\n                }\n            }\n\n      \
    \      for(auto [L,X,idx]:Qs[i+1]){\n                for(int j=B-1;j>=0;j--)if((X>>j)&1\
    \ and b[j].second>=L) X^=b[j].first;\n                ans[idx]=bool(X==0);\n \
    \           }\n        }\n        return ans;\n    }\n};\n"
  code: "/*\n * ref : https://atcoder.jp/contests/abc223/submissions/26660184\n *\
    \ verified : https://atcoder.jp/contests/abc223/submissions/26660184\n * \n *\
    \ b[j] := (1<<j) \u304C\u6700\u5927\u3067\u7ACB\u3063\u3066\u3044\u308B\u57FA\u5E95\
    \n *         \u540C\u6642\u306B\uFF0C\u305D\u306E\u57FA\u5E95\u306E\u53F3\u7AEF\
    \u306Eindex\u3082\u6301\u3064\n * A[i]\u3092\u898B\u308B\u6642\uFF0C\u3044\u3044\
    \u611F\u3058\u306B\u57FA\u5E95\u3092\u5165\u308C\u66FF\u3048\u308B\n*/\ntemplate<typename\
    \ INT,int B>\nstruct StaticRangeSpanQuery{\n    vector<INT> A;\n    vector<tuple<int,int,INT,int>>\
    \ query;\n\n    StaticRangeSpanQuery(vector<INT> &A):A(A){}\n\n    // X \u2208\
    \ span({A[L,R)}) ?\n    void add_query(int L,int R,INT X,int idx=-1){\n      \
    \  if(idx<0) idx=(int)query.size();\n        query.emplace_back(L,R,X,idx);\n\
    \    }\n\n    vector<bool> build(){\n        vector<vector<tuple<int,INT,int>>>\
    \ Qs(A.size()+1);\n        vector<bool> ans(query.size(),false);\n        for(auto\
    \ [L,R,X,idx]:query) Qs[R].emplace_back(L,X,idx);\n\n        vector<pair<INT,int>>\
    \ b(B);// \u6700\u3082\u53F3\u306E\u57FA\u5E95\n        for(int i=0;i<B;i++) b[i]={INT(1)<<i,-1};\n\
    \n        for(int i=0;i<(int)A.size();i++){\n            pair<INT,int> cur={A[i],i};\n\
    \            for(int j=B-1;j>=0;j--){\n                if((cur.first>>j)&1){\n\
    \                    if(cur.second>b[j].second) swap(cur,b[j]);\n\n          \
    \          cur.first^=b[j].first;\n                }\n            }\n\n      \
    \      for(auto [L,X,idx]:Qs[i+1]){\n                for(int j=B-1;j>=0;j--)if((X>>j)&1\
    \ and b[j].second>=L) X^=b[j].first;\n                ans[idx]=bool(X==0);\n \
    \           }\n        }\n        return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/StaticRangeSpanQuery.cpp
  requiredBy: []
  timestamp: '2021-11-23 20:02:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/StaticRangeSpanQuery.cpp
layout: document
redirect_from:
- /library/DataStructure/StaticRangeSpanQuery.cpp
- /library/DataStructure/StaticRangeSpanQuery.cpp.html
title: DataStructure/StaticRangeSpanQuery.cpp
---

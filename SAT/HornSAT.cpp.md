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
  bundledCode: "#line 1 \"SAT/HornSAT.cpp\"\n/*\nHorn SAT\n\u548C\u7A4D\u6A19\u6E96\
    \u5F62\u306B\u76F4\u3057\u305F\u6642\uFF0C\u7BC0\u306E\u4E2D\u306Bpositive\u306A\
    literal\u304C1\u500B\u307E\u3067\u306E\u6642\n\u7DDA\u5F62\u6642\u9593\u3067SAT\u304C\
    \u89E3\u3051\u308B\n\u9006\u306Bnegative\u306Aliteral\u304C1\u500B\u307E\u3067\
    \u306E\u5834\u5408\u306F\u5168\u90E8literal\u306Epos/neg\u9006\u8EE2\u3057\u3066\
    \u89E3\u304F\n*/\nstruct HornSAT{\n    int N,n_clause;\n    vector<vector<int>>\
    \ neg,literal_to_clause;\n    vector<int> pos,n_neg,res;\n\n    HornSAT(int N):N(N),n_clause(0),literal_to_clause(N),res(N,-1){}\n\
    \    \n    // (prev) -> (prev)*(not(neg_literal[0])+...+pos_literal)\n    void\
    \ add_clause(vector<int> neg_literal, int pos_literal=-1){\n        n_neg.push_back(neg_literal.size());\n\
    \        neg.push_back(neg_literal);\n        pos.push_back(pos_literal);\n  \
    \      for(int &t:neg_literal) literal_to_clause[t].push_back(n_clause);\n   \
    \     n_clause++;\n    }\n\n    vector<int> build(){\n        queue<int> confirmed_clause;\n\
    \        for(int i=0;i<n_clause;i++)if(n_neg[i]==0 and pos[i]>=0) confirmed_clause.push(i);\n\
    \        \n        while(!confirmed_clause.empty()){\n            int cur=confirmed_clause.front();confirmed_clause.pop();\n\
    \            int r=pos[cur];\n            if(r>=0 and res[r]<0){\n           \
    \     res[r]=1;\n                for(int &x:literal_to_clause[r]){\n         \
    \           n_neg[x]--;\n                    if(n_neg[x]==0) confirmed_clause.push(x);\n\
    \                }\n            }\n        }\n        for(int i=0;i<N;i++)if(res[i]==-1)\
    \ res[i]=0;\n\n        // verify\n        for(int i=0;i<n_clause;i++){\n     \
    \       int T=0;\n            for(int &x:neg[i])if(res[x]==0)  T++;\n        \
    \    if(pos[i]>=0 and res[pos[i]]==1) T++;\n\n            if(T==0) return {};\n\
    \        }\n        return res;\n    }\n};\n"
  code: "/*\nHorn SAT\n\u548C\u7A4D\u6A19\u6E96\u5F62\u306B\u76F4\u3057\u305F\u6642\
    \uFF0C\u7BC0\u306E\u4E2D\u306Bpositive\u306Aliteral\u304C1\u500B\u307E\u3067\u306E\
    \u6642\n\u7DDA\u5F62\u6642\u9593\u3067SAT\u304C\u89E3\u3051\u308B\n\u9006\u306B\
    negative\u306Aliteral\u304C1\u500B\u307E\u3067\u306E\u5834\u5408\u306F\u5168\u90E8\
    literal\u306Epos/neg\u9006\u8EE2\u3057\u3066\u89E3\u304F\n*/\nstruct HornSAT{\n\
    \    int N,n_clause;\n    vector<vector<int>> neg,literal_to_clause;\n    vector<int>\
    \ pos,n_neg,res;\n\n    HornSAT(int N):N(N),n_clause(0),literal_to_clause(N),res(N,-1){}\n\
    \    \n    // (prev) -> (prev)*(not(neg_literal[0])+...+pos_literal)\n    void\
    \ add_clause(vector<int> neg_literal, int pos_literal=-1){\n        n_neg.push_back(neg_literal.size());\n\
    \        neg.push_back(neg_literal);\n        pos.push_back(pos_literal);\n  \
    \      for(int &t:neg_literal) literal_to_clause[t].push_back(n_clause);\n   \
    \     n_clause++;\n    }\n\n    vector<int> build(){\n        queue<int> confirmed_clause;\n\
    \        for(int i=0;i<n_clause;i++)if(n_neg[i]==0 and pos[i]>=0) confirmed_clause.push(i);\n\
    \        \n        while(!confirmed_clause.empty()){\n            int cur=confirmed_clause.front();confirmed_clause.pop();\n\
    \            int r=pos[cur];\n            if(r>=0 and res[r]<0){\n           \
    \     res[r]=1;\n                for(int &x:literal_to_clause[r]){\n         \
    \           n_neg[x]--;\n                    if(n_neg[x]==0) confirmed_clause.push(x);\n\
    \                }\n            }\n        }\n        for(int i=0;i<N;i++)if(res[i]==-1)\
    \ res[i]=0;\n\n        // verify\n        for(int i=0;i<n_clause;i++){\n     \
    \       int T=0;\n            for(int &x:neg[i])if(res[x]==0)  T++;\n        \
    \    if(pos[i]>=0 and res[pos[i]]==1) T++;\n\n            if(T==0) return {};\n\
    \        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: SAT/HornSAT.cpp
  requiredBy: []
  timestamp: '2021-08-16 23:56:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SAT/HornSAT.cpp
layout: document
redirect_from:
- /library/SAT/HornSAT.cpp
- /library/SAT/HornSAT.cpp.html
title: SAT/HornSAT.cpp
---

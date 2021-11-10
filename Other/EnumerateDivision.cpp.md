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
    - https://atcoder.jp/contests/abc226/submissions/27125989
  bundledCode: "#line 1 \"Other/EnumerateDivision.cpp\"\n/*\nN\u306E\u5206\u5272\u65B9\
    \u6CD5\u306E\u5217\u6319\nN=50 -> 200000 \u7A0B\u5EA6\nverified : https://atcoder.jp/contests/abc226/submissions/27125989\n\
    */\nvector<vector<int>> enumerate_division(int N){\n    vector<vector<int>> ret;\n\
    \ \n    function<void(vector<int>,int,int)> rec=[&](vector<int> v,int S,int K){\n\
    \        if(S==0){\n            ret.push_back(v);\n            return ;\n    \
    \    }\n \n        for(int t=min(S,K);t>0;t--){\n            v.push_back(t);\n\
    \            rec(v,S-t,t);\n            v.pop_back();\n        }\n    };\n   \
    \ rec({},N,N);\n    return ret;\n}\n"
  code: "/*\nN\u306E\u5206\u5272\u65B9\u6CD5\u306E\u5217\u6319\nN=50 -> 200000 \u7A0B\
    \u5EA6\nverified : https://atcoder.jp/contests/abc226/submissions/27125989\n*/\n\
    vector<vector<int>> enumerate_division(int N){\n    vector<vector<int>> ret;\n\
    \ \n    function<void(vector<int>,int,int)> rec=[&](vector<int> v,int S,int K){\n\
    \        if(S==0){\n            ret.push_back(v);\n            return ;\n    \
    \    }\n \n        for(int t=min(S,K);t>0;t--){\n            v.push_back(t);\n\
    \            rec(v,S-t,t);\n            v.pop_back();\n        }\n    };\n   \
    \ rec({},N,N);\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Other/EnumerateDivision.cpp
  requiredBy: []
  timestamp: '2021-11-10 12:15:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Other/EnumerateDivision.cpp
layout: document
redirect_from:
- /library/Other/EnumerateDivision.cpp
- /library/Other/EnumerateDivision.cpp.html
title: Other/EnumerateDivision.cpp
---

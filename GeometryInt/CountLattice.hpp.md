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
    - https://atcoder.jp/contests/typical90/submissions/24194520
  bundledCode: "#line 1 \"GeometryInt/CountLattice.hpp\"\n// \u51F8\u591A\u89D2\u5F62\
    \u5185\u90E8\u3068\u5916\u5468\u4E0A\u306E\u70B9\u3092\u30AB\u30A6\u30F3\u30C8\
    \n// \u51F8\u591A\u89D2\u5F62\u4EE5\u5916\u3092\u4E0E\u3048\u3066\u826F\u3044\n\
    // \u30D4\u30C3\u30AF\u306E\u5B9A\u7406\uFF0C\u591A\u89D2\u5F62\u306E\u9802\u70B9\
    \u304C\u3059\u3079\u3066\u683C\u5B50\u70B9\u4E0A\u306B\u5B58\u5728\u3059\u308B\
    \u306A\u3089\u6210\u7ACB\n// S = i + b / 2 - 1\n// (S : \u591A\u89D2\u5F62\u306E\
    \u9762\u7A4D, i : \u683C\u5B50\u70B9\u6570, b : \u8FBA\u4E0A\u306E\u683C\u5B50\
    \u70B9\u6570)\n// https://atcoder.jp/contests/typical90/submissions/24194520\n\
    Int CountLattice(vector<P> poly){\n    int N=(int)poly.size();\n \n    Int b=0;\n\
    \    for(int i=0;i<N;i++){\n        Int x=poly[(i+1)%N].first-poly[i].first,y=poly[(i+1)%N].second-poly[i].second;\n\
    \        x=abs(x),y=abs(y);\n        b+=gcd(x,y);\n    }\n \n    Int S=Area2(poly);\n\
    \ \n    return (S+b)/2+1;\n}\n"
  code: "// \u51F8\u591A\u89D2\u5F62\u5185\u90E8\u3068\u5916\u5468\u4E0A\u306E\u70B9\
    \u3092\u30AB\u30A6\u30F3\u30C8\n// \u51F8\u591A\u89D2\u5F62\u4EE5\u5916\u3092\u4E0E\
    \u3048\u3066\u826F\u3044\n// \u30D4\u30C3\u30AF\u306E\u5B9A\u7406\uFF0C\u591A\u89D2\
    \u5F62\u306E\u9802\u70B9\u304C\u3059\u3079\u3066\u683C\u5B50\u70B9\u4E0A\u306B\
    \u5B58\u5728\u3059\u308B\u306A\u3089\u6210\u7ACB\n// S = i + b / 2 - 1\n// (S\
    \ : \u591A\u89D2\u5F62\u306E\u9762\u7A4D, i : \u683C\u5B50\u70B9\u6570, b : \u8FBA\
    \u4E0A\u306E\u683C\u5B50\u70B9\u6570)\n// https://atcoder.jp/contests/typical90/submissions/24194520\n\
    Int CountLattice(vector<P> poly){\n    int N=(int)poly.size();\n \n    Int b=0;\n\
    \    for(int i=0;i<N;i++){\n        Int x=poly[(i+1)%N].first-poly[i].first,y=poly[(i+1)%N].second-poly[i].second;\n\
    \        x=abs(x),y=abs(y);\n        b+=gcd(x,y);\n    }\n \n    Int S=Area2(poly);\n\
    \ \n    return (S+b)/2+1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: GeometryInt/CountLattice.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: GeometryInt/CountLattice.hpp
layout: document
redirect_from:
- /library/GeometryInt/CountLattice.hpp
- /library/GeometryInt/CountLattice.hpp.html
title: GeometryInt/CountLattice.hpp
---

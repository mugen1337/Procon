---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"GeometryInt/Area2.hpp\"\n// \u3050\u308B\u3063\u3068\u5916\
    \u7A4D\u3068\u308B\u3068\u6253\u3061\u6D88\u3055\u308C\u3068\u304B\u3092\u8003\
    \u3048\u3066\u9762\u7A4D\u306E\uFF12\u500D\u304C\u624B\u306B\u5165\u308B\nInt\
    \ Area2(vector<P> poly){\n    int N=(int)poly.size();\n    Int S=0;\n    for(int\
    \ i=0;i<N;i++) S+=poly[i].first*poly[(i+1)%N].second-poly[i].second*poly[(i+1)%N].first;\n\
    \    return S;\n}\n"
  code: "// \u3050\u308B\u3063\u3068\u5916\u7A4D\u3068\u308B\u3068\u6253\u3061\u6D88\
    \u3055\u308C\u3068\u304B\u3092\u8003\u3048\u3066\u9762\u7A4D\u306E\uFF12\u500D\
    \u304C\u624B\u306B\u5165\u308B\nInt Area2(vector<P> poly){\n    int N=(int)poly.size();\n\
    \    Int S=0;\n    for(int i=0;i<N;i++) S+=poly[i].first*poly[(i+1)%N].second-poly[i].second*poly[(i+1)%N].first;\n\
    \    return S;\n}"
  dependsOn: []
  isVerificationFile: false
  path: GeometryInt/Area2.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: GeometryInt/Area2.hpp
layout: document
redirect_from:
- /library/GeometryInt/Area2.hpp
- /library/GeometryInt/Area2.hpp.html
title: GeometryInt/Area2.hpp
---

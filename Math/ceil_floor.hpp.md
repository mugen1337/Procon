---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yuki4459.test.cpp
    title: test/yuki4459.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/ceil_floor.hpp\"\n// round for +inf\ntemplate<typename\
    \ INT>\ninline INT div_ceil(INT x,INT y){\n    return (x<0?x/y:(x+y-1)/y);\n}\n\
    \n// round for -inf\ntemplate<typename INT>\ninline INT div_floor(INT x,INT y){\n\
    \    return (x>0?x/y:(x-y+1)/y);\n}\n"
  code: "// round for +inf\ntemplate<typename INT>\ninline INT div_ceil(INT x,INT\
    \ y){\n    return (x<0?x/y:(x+y-1)/y);\n}\n\n// round for -inf\ntemplate<typename\
    \ INT>\ninline INT div_floor(INT x,INT y){\n    return (x>0?x/y:(x-y+1)/y);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/ceil_floor.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yuki4459.test.cpp
documentation_of: Math/ceil_floor.hpp
layout: document
redirect_from:
- /library/Math/ceil_floor.hpp
- /library/Math/ceil_floor.hpp.html
title: Math/ceil_floor.hpp
---

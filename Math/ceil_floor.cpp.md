---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki4459.test.cpp
    title: test/yuki4459.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/ceil_floor.cpp\"\n// round for +inf\ntemplate<typename\
    \ INT>\ninline INT div_ceil(INT x,INT y){\n    return (x<0?x/y:(x+y-1)/y);\n}\n\
    \n// round for -inf\ntemplate<typename INT>\ninline INT div_floor(INT x,INT y){\n\
    \    return (x>0?x/y:(x-y+1)/y);\n}\n"
  code: "// round for +inf\ntemplate<typename INT>\ninline INT div_ceil(INT x,INT\
    \ y){\n    return (x<0?x/y:(x+y-1)/y);\n}\n\n// round for -inf\ntemplate<typename\
    \ INT>\ninline INT div_floor(INT x,INT y){\n    return (x>0?x/y:(x-y+1)/y);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/ceil_floor.cpp
  requiredBy: []
  timestamp: '2021-01-23 00:46:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki4459.test.cpp
documentation_of: Math/ceil_floor.cpp
layout: document
redirect_from:
- /library/Math/ceil_floor.cpp
- /library/Math/ceil_floor.cpp.html
title: Math/ceil_floor.cpp
---

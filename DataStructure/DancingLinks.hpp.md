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
    - https://atcoder.jp/contests/arc039/submissions/26243031
  bundledCode: "#line 1 \"DataStructure/DancingLinks.hpp\"\n/*\nverify : https://atcoder.jp/contests/arc039/submissions/26243031\n\
    \nT -> int or long long\n(x, y) : current position\n\nmove(['L', 'R', 'U', 'D'])\n\
    \    \u305D\u306E\u65B9\u5411\u306B\u9032\u307F\uFF0C\u307E\u3060\u8A2A\u554F\u3057\
    \u3066\u3044\u306A\u3044\u5730\u70B9\u306B\u5230\u9054\u3057\u305F\u3089\u79FB\
    \u52D5\u7D42\u4E86\n*/\ntemplate<typename T>\nstruct DancingLinks{\npublic:\n\
    \    T x,y;\n    map<tuple<T,T,char>,T> mp;\n    DancingLinks(T sx=0,T sy=0):x(sx),y(sy){\n\
    \        update();\n    }\n    // R,L,U,D(r,l,u,d) = (x++,x--,y++,y--)\n    void\
    \ move(char dir){\n        if(dir=='R' or dir=='r') x=mp[{x,y,'R'}];\n       \
    \ if(dir=='L' or dir=='l') x=mp[{x,y,'L'}];\n        if(dir=='U' or dir=='u')\
    \ y=mp[{x,y,'U'}];\n        if(dir=='D' or dir=='d') y=mp[{x,y,'D'}];\n      \
    \  update();\n    }\n\nprivate:\n    void update(){\n        if(!mp.count({x,y,'R'}))\
    \ mp[{x,y,'R'}]=x+1;\n        if(!mp.count({x,y,'L'})) mp[{x,y,'L'}]=x-1;\n  \
    \      if(!mp.count({x,y,'U'})) mp[{x,y,'U'}]=y+1;\n        if(!mp.count({x,y,'D'}))\
    \ mp[{x,y,'D'}]=y-1;\n \n        mp[{mp[{x,y,'R'}],y,'L'}]=mp[{x,y,'L'}];\n  \
    \      mp[{mp[{x,y,'L'}],y,'R'}]=mp[{x,y,'R'}];\n        mp[{x,mp[{x,y,'U'}],'D'}]=mp[{x,y,'D'}];\n\
    \        mp[{x,mp[{x,y,'D'}],'U'}]=mp[{x,y,'U'}];\n    }\n};\n"
  code: "/*\nverify : https://atcoder.jp/contests/arc039/submissions/26243031\n\n\
    T -> int or long long\n(x, y) : current position\n\nmove(['L', 'R', 'U', 'D'])\n\
    \    \u305D\u306E\u65B9\u5411\u306B\u9032\u307F\uFF0C\u307E\u3060\u8A2A\u554F\u3057\
    \u3066\u3044\u306A\u3044\u5730\u70B9\u306B\u5230\u9054\u3057\u305F\u3089\u79FB\
    \u52D5\u7D42\u4E86\n*/\ntemplate<typename T>\nstruct DancingLinks{\npublic:\n\
    \    T x,y;\n    map<tuple<T,T,char>,T> mp;\n    DancingLinks(T sx=0,T sy=0):x(sx),y(sy){\n\
    \        update();\n    }\n    // R,L,U,D(r,l,u,d) = (x++,x--,y++,y--)\n    void\
    \ move(char dir){\n        if(dir=='R' or dir=='r') x=mp[{x,y,'R'}];\n       \
    \ if(dir=='L' or dir=='l') x=mp[{x,y,'L'}];\n        if(dir=='U' or dir=='u')\
    \ y=mp[{x,y,'U'}];\n        if(dir=='D' or dir=='d') y=mp[{x,y,'D'}];\n      \
    \  update();\n    }\n\nprivate:\n    void update(){\n        if(!mp.count({x,y,'R'}))\
    \ mp[{x,y,'R'}]=x+1;\n        if(!mp.count({x,y,'L'})) mp[{x,y,'L'}]=x-1;\n  \
    \      if(!mp.count({x,y,'U'})) mp[{x,y,'U'}]=y+1;\n        if(!mp.count({x,y,'D'}))\
    \ mp[{x,y,'D'}]=y-1;\n \n        mp[{mp[{x,y,'R'}],y,'L'}]=mp[{x,y,'L'}];\n  \
    \      mp[{mp[{x,y,'L'}],y,'R'}]=mp[{x,y,'R'}];\n        mp[{x,mp[{x,y,'U'}],'D'}]=mp[{x,y,'D'}];\n\
    \        mp[{x,mp[{x,y,'D'}],'U'}]=mp[{x,y,'U'}];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DancingLinks.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/DancingLinks.hpp
layout: document
redirect_from:
- /library/DataStructure/DancingLinks.hpp
- /library/DataStructure/DancingLinks.hpp.html
title: DataStructure/DancingLinks.hpp
---

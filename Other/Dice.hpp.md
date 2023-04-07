---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_ITP_Dice_III.test.cpp
    title: test/AOJ_ITP_Dice_III.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Other/Dice.hpp\"\ntemplate<typename T>\nstruct Dice{\n \
    \   //left, right, front, back, down, up\n    T l,r,f,b,d,u;\n\n    void RollF(){\
    \ // y-- (next, d <- f)\n        int tmp=d; d=f; f=u; u=b; b=tmp;\n    }\n\n \
    \   void RollB(){ // y++ (next, d <- b)\n        int tmp=d; d=b; b=u; u=f; f=tmp;\n\
    \    }\n\n    void RollL(){ // x-- (next, d <- l)\n        int tmp=d; d=l; l=u;\
    \ u=r; r=tmp;\n    }\n\n    void RollR(){ // x++ (next, d <- r)\n        int tmp=d;\
    \ d=r; r=u; u=l; l=tmp;\n    }\n};\n\ntemplate<typename T>\nbool same_dice_same_state(Dice<T>\
    \ a,Dice<T> b){\n    return (a.b==b.b and a.f==b.f and a.l==b.l and a.r==b.r and\
    \ a.u==b.u and a.d==b.d);\n}\n\ntemplate<typename T>\nbool same_dice(Dice<T> a,Dice<T>\
    \ b){\n    for(int i=0;i<4;i++){\n        a.RollL();\n        for(int j=0;j<4;j++){\n\
    \            a.RollB();\n            for(int k=0;k<4;k++){\n                a.RollL();\n\
    \                if(same_dice_same_state(a,b)) return true;\n            }\n \
    \       }\n    }\n    return false;\n}\n"
  code: "template<typename T>\nstruct Dice{\n    //left, right, front, back, down,\
    \ up\n    T l,r,f,b,d,u;\n\n    void RollF(){ // y-- (next, d <- f)\n        int\
    \ tmp=d; d=f; f=u; u=b; b=tmp;\n    }\n\n    void RollB(){ // y++ (next, d <-\
    \ b)\n        int tmp=d; d=b; b=u; u=f; f=tmp;\n    }\n\n    void RollL(){ //\
    \ x-- (next, d <- l)\n        int tmp=d; d=l; l=u; u=r; r=tmp;\n    }\n\n    void\
    \ RollR(){ // x++ (next, d <- r)\n        int tmp=d; d=r; r=u; u=l; l=tmp;\n \
    \   }\n};\n\ntemplate<typename T>\nbool same_dice_same_state(Dice<T> a,Dice<T>\
    \ b){\n    return (a.b==b.b and a.f==b.f and a.l==b.l and a.r==b.r and a.u==b.u\
    \ and a.d==b.d);\n}\n\ntemplate<typename T>\nbool same_dice(Dice<T> a,Dice<T>\
    \ b){\n    for(int i=0;i<4;i++){\n        a.RollL();\n        for(int j=0;j<4;j++){\n\
    \            a.RollB();\n            for(int k=0;k<4;k++){\n                a.RollL();\n\
    \                if(same_dice_same_state(a,b)) return true;\n            }\n \
    \       }\n    }\n    return false;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Other/Dice.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_ITP_Dice_III.test.cpp
documentation_of: Other/Dice.hpp
layout: document
redirect_from:
- /library/Other/Dice.hpp
- /library/Other/Dice.hpp.html
title: Other/Dice.hpp
---

---
title: Precalc (Twelvefold way)
documentation_of: //Math/Precalc.cpp
---

## 概要  
Combinationの前計算と，一部，数え上げに関係する関数を持った構造体  
modint以外が渡されることを考えていない．メソッドpowが要求される関数がある  

## 写像12相 (Twelvefold way)  

|                                | 制限無し | 箱ごと1個以下 | 箱ごと1個以上 | 
| ------------------------------ | -------- | ------------- | ------------- | 
| **玉区別，箱区別**             | DPL_5_A  | DPL_5_B       | DPL_5_C       | 
| **玉区別しない，箱区別**       | DPL_5_D  | DPL_5_E       | DPL_5_F       | 
| **玉区別，箱区別しない**       | DPL_5_G  | DPL_5_H       | DPL_5_I       | 
| **玉区別しない，箱区別しない** | DPL_5_J  | DPL_5_K       | DPL_5_L       | 

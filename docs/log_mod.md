---
title: 離散対数 (log mod)
documentation_of: //Math/log_mod.cpp
---

## 概要  
離散対数問題  
わかりやすさを重視して実装しているので，定数倍が重い．  


## 解説  
X^k = Y (mod M)を解く  
gcd(X,M) = g = 1 ならX^(-1)が存在するのでBSGS  
存在しない場合  
X = X' * g, Y = Y' * g, M = M' * g  
とする．Yがgの倍数でないなら不可能  
元の式を考えると，ある整数nが存在し，(g * X') ^ k - g * Y' = n * g * M'  
変形, X' * (g * X') ^ (k-1) - Y' = n * M'  
これより，X, X' ^ (-1) * Y', M' でまた再帰的に同じ問題を解けばよくなる  

## Ref  
https://qiita.com/suisen_cp/items/d597c8ec576ae32ee2d7  


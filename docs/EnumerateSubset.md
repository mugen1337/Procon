---
title: Inversion Number (転倒数)
documentation_of: //Other/EnumerateSubset.cpp
---

## 概要  
bitの立っている箇所を集合の要素として，その集合の部分集合を列挙して返す．  
つまり，2進表記でbit=11001と表せるとき，  
返すのは{11001, 11000, 10001, 10000, 01001, 01000, 00001, 00000}である．  

有名な事実として，N個の集合の全ての部分集合において部分集合を列挙，つまり  
for i=0 to (1<<N)-1  
  EnumerateSubset(i)  
をすると，計算量はO(3^N)である．

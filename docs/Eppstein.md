---
title: Eppstein's Algorithm (K-Shortest-Walk)
documentation_of: //Graph2/Eppstein.cpp
---

## 概要  
Eppstein's Algorithmです．  
同じ店を何度通ってもいいようなs-tパスを距離の小さい方からk個列挙します．  

## 仕様  
有向グラフのみに使える．  
無向グラフで使いたいなら辺番号を振りなおすこと．  

## 計算量  
O(M + NlogN + KlogK)  

---
title: Yen's Algorithm (K-Shortest-Path)
documentation_of: //Graph2/Yen.cpp
---

## 概要  

Dijkstraをする．  
最短路の途中からそれるのが次の最短路の候補  

## 仕様  
有向グラフのみに使える．  
無向グラフで使いたいなら辺番号を振りなおすこと．  

返り値は(コスト, パスを表す辺番号のリスト)のvector  

## 計算量  
Yen's AlgorithmはO(KV * (最短路の計算量))  
実装はO(KV (V+E) log(V))かO(KV (V+E) log(V))だと思うけどちょっと自信ない．  

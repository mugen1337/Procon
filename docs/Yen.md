---
title: Yen's Algorithm (K-Shortest-Path)
documentation_of: //Graph2/Yen.cpp
---

## 概要  

Dijkstraをする．  
最短路の途中からそれるのが次の最短路の候補  

A : 返り値  
B : (最短路, path)  
Bから1個最短路を取り出す．Bのパスを進みながら，ある頂点で道をそれることを考える．  
その時，次の辺のうち使えるのは今までの最短路で通ったようなパス以外のパス．
removed_edge : 使えない辺  
それをコイツに入れる．  

## 仕様  
有向グラフのみに使える．  
無向グラフで使いたいなら辺番号を振りなおすこと．  

返り値は(コスト, パスを表す辺番号のリスト)のvector  

## 計算量  
Yen's AlgorithmはO(KV * (最短路の計算量))  
実装はO(KV (V+E) log(V))かO(K^2 V (V+E) log(V))だと思うけどちょっと自信ない．  

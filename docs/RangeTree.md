---
title: Range Tree (領域木)
documentation_of: //DataStructure/RangeTree.hpp
---

## 概要  
2次元空間に点の追加，長方形領域のクエリを処理する．  

## 仕様  
- build(vector<X,Y,V>)  構築, (X,Y)の頂点がV個  
- build(vector<X,Y>)    構築, (X,Y)の頂点が1個  
- query(x1, y1, x2, y2) カウントクエリ [x1, x2) * [y1, y2)  


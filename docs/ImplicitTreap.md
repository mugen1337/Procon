---
title: Implicit Treap
documentation_of: //BinarySearchTree/ImplicitTreap.cpp
---

## 概要  
vectorのようなインターフェースを提供する二分探索木  
内部はTreap

## 仕様  
- operator[] : ランダムアクセス
- insert(k, x) : a[k]<-x, 後ろを1個ずつずらす
- erase(k) : a[x]を消す, 後ろを1個ずつ詰める
- reverse(l, r) : a[l] ~ a[r]をreverseする
- rotate(l, m, r) : a[l]がa[m]になるまでrotateする
- split(k) : [0, k) [k, n) で分けたTreapを返す．これを使うと，thisは死ぬ．
- merge(l, r) : mergeする．mergeをするとl, rは死ぬ．
- push_back, push_front, pop_back, pop_front : はい



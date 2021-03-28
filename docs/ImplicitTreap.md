---
title: Implicit Treap
documentation_of: //BinarySearchTree/ImplicitTreap.cpp
---

## 概要  
あたかも遅延セグメント木か配列かのようなインターフェースのTreap.  

## 仕様  
- build(v) : 配列 v で初期化してbuild
- insert(k, x) : v[k]=xにして後ろを1個ずつずらす
- query(l, r) : 遅延セグメント木みたいなクエリ
- update(l, r, x) : 遅延セグメント木みたいなアップデート
- erase(l, r) : v[l] ~ v[r-1]を消して間を詰める
- reverse(l, r) : v[l] ~ v[r-1]を反転する
- rotate(l, m, r) : v[l]がv[m]になるまでrotateする

buildはO(NlogN), それ以外はO(logN)

## Ref  
https://xuzijian629.hatenablog.com/entry/2018/12/08/000452

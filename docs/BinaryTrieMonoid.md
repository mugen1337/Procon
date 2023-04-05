---
title: Binary Trie Monoid (必要なところだけ作るセグメント木)
documentation_of: //DataStructure/BinaryTrieMonoid.hpp
---

## 概要  
Binary Trieの容量でMonoidを管理すると必要な所だけ作るセグメント木が書ける   


## 仕様  
構築する際二分木の深さ，MAXLOGを指定する必要がある．  
[0, 1<<MAXLOG)の大きさの配列を扱えるようになる，とイメージすればよい．  

- f : Monoidをfoldする関数  
- query(l,r) : [l,r)のMonoidをfでfold, 値を入れていないところは自動で元eで補う  
- update(bit,x) : bitの位置をxに変更  


## 計算量  
- query : O(MAXLOG)  
- update : O(MAXLOG)  


## 参照  
イメージ https://www.slideshare.net/iwiwi/2-12188757


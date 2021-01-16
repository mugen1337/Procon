---
title: オフライン 削除可能 Convex Hull Trick  
documentation_of: //DataStructure/DeletableLiChaoTreeOffline.cpp
---

## 概要  
Dynamic Connectivityをセグメント木で解くのとほとんど一緒．  
LiChaoTreeをUndo可能に編集して実装しているのでlogが2個ついてしまっている．  
LiChaoTreeを永続化させるとlog1個落ちるんじゃないだろうか．永続化についてあまり知らないのでちょっとよくわかってない．  

verify問題，コドフォ以外にないかな  

## 使い方  
queryのインデックス順に直線追加，直線削除をぶち込む．　　
buildをして，execute.  

buildを忘れない  

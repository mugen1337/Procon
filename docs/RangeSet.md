---
title: 区間をセットで管理するやつ
documentation_of: //DataStructure/RangeSet.hpp
---

## 概要  
https://mugen1337.hatenablog.com/entry/2020/10/14/134022  

## なんか  
int, ll以外の使用を想定していない．  

## できること  
全ての操作が存在している区間数をnとしてO(logn)．(一部ならしでO(logn))
- covered -- 与えた区間か点がカバーされているかどうか  
- covered_by -- 与えた区間か点がカバーされているならカバーされている区間を返す  
- insert -- 区間，点をinsertする．区間の増加量を返す．  
- erase -- 区間，点をeraseする．区間の減少量を返す  
- size -- 区間の数を返す  
- mex -- x以上で最も小さい，区間に含まれない数を返す  
- output -- debugに使えます  
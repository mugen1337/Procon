---
title: Low Link
documentation_of: //Graph2/LowLink.cpp
---

## 概要  
https://kagamiz.hatenablog.com/entry/2013/10/05/005213  
dfs木作る．  
ord[u] : dfsの訪問順  
low[u] : uから後退辺を1度だけ使って一番できる根側の頂点  

u->vの辺がある時，ord[u]<low[v]なら橋  

関節点の判定も可能．  
- 根なら子が2個以上あるか  
- そうでなければ，橋が生えているか  

## 仕様  
- art[i] : trueなら頂点iは関節点  
- bridge : 橋一覧  

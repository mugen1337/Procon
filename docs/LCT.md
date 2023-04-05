---
title: Link Cut Tree
documentation_of: //Graph2/LinkCutTree.hpp
---

# 概要  
Link Cut Tree

# 仕様  
各操作で根が変わったり変わらなかったりする  
- evert(v) : vをrootに
- link(u, v) : u-v辺をはる
- cut(v) : vとvの親を切る
- cut(u, v) : u-v辺を切る．あるかチェックもする
- query(u, v) : path query
- get_root(u) : 今のrootを返す
- lca(u, v) : u, vのLeast Common Ancestor
- deppth(v) : 今の木のrootからみたvの深さ
- distance(u, v) : 今の木のu-vの距離
大体どれもならしlogNらしい  
オリジナルでつけたのでdepth, distanceはまだverifyできていない．

# ref
https://www.slideshare.net/iwiwi/2-12188845
https://ei1333.hateblo.jp/entry/2018/05/29/011140
https://sotanishy.github.io/competitive-programming-library/tree/link_cut_tree.hpp

# todo
部分木クエリについての理解

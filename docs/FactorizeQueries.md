---
title: osa_k法 (Factorization Queries)
documentation_of: //Math/FactorizeQueries.hpp
---

## 概要  
エラトステネスの篩の要領で前処理をしておくと素因数分解を高速にできる場合がある．  


## 計算量  
Mを素因数分解した最大の数とし，Nを素因数分解する時．  
- 前処理 : O(M log(logM))  
- クエリ : O(logN)  

---
title: Strongly Connected Components
documentation_of: //Graph2/StronglyConnectedComponents.hpp
---

## 概要  
SCC  
belong[i] : iが属するSCC  
group[i] : SCC_iに入っている頂点たち  
compressed : SCCごと分解したグラフが入る．DAGだけど，元グラフが連結じゃないなら連結ではないところに注意．また，多重辺が生える実装になっている.  

もしトポソ順が欲しいのであれば，  
rep(i,(int)scc.compressed.size())  
for(auto j:scc.group[i]) ord.push_back(j);  
とかやるとよい．


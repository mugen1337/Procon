---
title: Alien DP
documentation_of: //tips/AlienDP.cpp
---

## 概要  
yosupoさん「何かをK回使ってコストを最小化してください，で，dp[pos][使った回数]だと遅すぎるときに，K回使う代わりに1回使うとx円罰金，にすればdp[pos]に出来る(こともある)テク(xで二分探索)」  

## ECR79F - New Year and Handle Change  
幅lで文字をすべて大文字か小文字にできる，minimize min(大文字の数，小文字の数)  

大文字に寄せる，小文字に寄せる，をそれぞれ解く.  
1の数-ペナルティの最大化をdpで解く  
dp[i]=(1の数-ペナルティ, 操作した回数)  
dp[n]のk回分のペナルティを消して終わり  

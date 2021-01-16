---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DSL_2_A.test.cpp
    title: test/AOJ_DSL_2_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/BinaryTrieMonoid.cpp\"\ntemplate<typename\
    \ BitType,int MAXLOG,typename Monoid>\nstruct BinaryTrieMonoid{\n    private:\n\
    \    struct Node{\n        Node *nxt[2];\n        Monoid val;\n        Node(Monoid\
    \ val):nxt{nullptr,nullptr},val(val){}\n    };\n\n    Node *root;\n\n    using\
    \ F=function<Monoid(Monoid,Monoid)>;\n    F f;\n    const Monoid e;\n\n    Monoid\
    \ query(BitType a,BitType b,Node *cur,BitType l,BitType r,int dep,BitType xor_val){\n\
    \        if(a<=l and r<=b) return (cur?cur->val:e);\n        if(dep<0 or b<=l\
    \ or r<=a or !cur) return e;\n        bool x0=(xor_val>>dep)&1;\n        Monoid\
    \ L=query(a,b,cur->nxt[x0],l,(l+r)/2,dep-1,xor_val);\n        Monoid R=query(a,b,cur->nxt[x0^1],(l+r)/2,r,dep-1,xor_val);\n\
    \        return f(L,R);\n    }\n    void update(Node *cur,Monoid x,BitType bit,int\
    \ dep){\n        if(dep==-1){\n            cur->val=x;\n            return ;\n\
    \        }\n        bool go_to=(bit>>dep)&1;\n        if(!cur->nxt[go_to]) cur->nxt[go_to]=new\
    \ Node(e);\n        update(cur->nxt[go_to],x,bit,dep-1);\n        cur->val=f(cur->nxt[0]?cur->nxt[0]->val:e,cur->nxt[1]?cur->nxt[1]->val:e);\n\
    \        return ;\n    }\n\n    public:\n    BinaryTrieMonoid(F f,const Monoid\
    \ &e):root(new Node(e)),f(f),e(e){}\n\n    // fold [l,r)\n    // xor_val\u3092\
    \u6307\u5B9A\u3057\u305F\u3068\u304D\uFF0C\u53EF\u63DB\u3058\u3083\u306A\u3044\
    \u6F14\u7B97\u3060\u3068\u58CA\u308C\u308B\u3068\u601D\u3044\u307E\u3059\uFF0E\
    \u591A\u5206\n    Monoid query(BitType l,BitType r,BitType xor_val=0){\n     \
    \   return query(l,r,root,0,BitType(1)<<MAXLOG,MAXLOG-1,xor_val);\n    }\n   \
    \ void update(BitType bit,Monoid x){\n        update(root,x,bit,MAXLOG-1);\n \
    \   }\n    Monoid operator[](const BitType &k){\n        return query(k,k+1);\n\
    \    }\n};\n"
  code: "template<typename BitType,int MAXLOG,typename Monoid>\nstruct BinaryTrieMonoid{\n\
    \    private:\n    struct Node{\n        Node *nxt[2];\n        Monoid val;\n\
    \        Node(Monoid val):nxt{nullptr,nullptr},val(val){}\n    };\n\n    Node\
    \ *root;\n\n    using F=function<Monoid(Monoid,Monoid)>;\n    F f;\n    const\
    \ Monoid e;\n\n    Monoid query(BitType a,BitType b,Node *cur,BitType l,BitType\
    \ r,int dep,BitType xor_val){\n        if(a<=l and r<=b) return (cur?cur->val:e);\n\
    \        if(dep<0 or b<=l or r<=a or !cur) return e;\n        bool x0=(xor_val>>dep)&1;\n\
    \        Monoid L=query(a,b,cur->nxt[x0],l,(l+r)/2,dep-1,xor_val);\n        Monoid\
    \ R=query(a,b,cur->nxt[x0^1],(l+r)/2,r,dep-1,xor_val);\n        return f(L,R);\n\
    \    }\n    void update(Node *cur,Monoid x,BitType bit,int dep){\n        if(dep==-1){\n\
    \            cur->val=x;\n            return ;\n        }\n        bool go_to=(bit>>dep)&1;\n\
    \        if(!cur->nxt[go_to]) cur->nxt[go_to]=new Node(e);\n        update(cur->nxt[go_to],x,bit,dep-1);\n\
    \        cur->val=f(cur->nxt[0]?cur->nxt[0]->val:e,cur->nxt[1]?cur->nxt[1]->val:e);\n\
    \        return ;\n    }\n\n    public:\n    BinaryTrieMonoid(F f,const Monoid\
    \ &e):root(new Node(e)),f(f),e(e){}\n\n    // fold [l,r)\n    // xor_val\u3092\
    \u6307\u5B9A\u3057\u305F\u3068\u304D\uFF0C\u53EF\u63DB\u3058\u3083\u306A\u3044\
    \u6F14\u7B97\u3060\u3068\u58CA\u308C\u308B\u3068\u601D\u3044\u307E\u3059\uFF0E\
    \u591A\u5206\n    Monoid query(BitType l,BitType r,BitType xor_val=0){\n     \
    \   return query(l,r,root,0,BitType(1)<<MAXLOG,MAXLOG-1,xor_val);\n    }\n   \
    \ void update(BitType bit,Monoid x){\n        update(root,x,bit,MAXLOG-1);\n \
    \   }\n    Monoid operator[](const BitType &k){\n        return query(k,k+1);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryTrieMonoid.cpp
  requiredBy: []
  timestamp: '2021-01-16 17:21:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_DSL_2_A.test.cpp
documentation_of: DataStructure/BinaryTrieMonoid.cpp
layout: document
title: "Binary Trie Monoid (\u5FC5\u8981\u306A\u3068\u3053\u308D\u3060\u3051\u4F5C\
  \u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---

## 概要  
Binary Trieの容量でMonoidを管理すると必要な所だけ作るセグメント木が書ける  
ここら辺を参照すると必要な所だけ作るセグメント木のイメージがわかる https://www.slideshare.net/iwiwi/2-12188757  


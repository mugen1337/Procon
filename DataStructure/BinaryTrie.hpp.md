---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_DSL_2_B.test.cpp
    title: test/AOJ_DSL_2_B.test.cpp
  - icon: ':x:'
    path: test/yosupo_Set_Xor_Min.test.cpp
    title: test/yosupo_Set_Xor_Min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/BinaryTrie.hpp\"\ntemplate<typename BitType,int\
    \ MAXLOG,typename C=int>\nstruct BinaryTrie{\n    private:\n    struct Node{\n\
    \        Node *nxt[2];\n        C cnt;\n        Node():nxt{nullptr,nullptr},cnt(0){}\n\
    \    };\n\n    Node *root;\n\n    Node *find(BitType bit,BitType xor_val=0){\n\
    \        Node *cur=root;\n        for(int i=MAXLOG-1;i>=0;i--){\n            bool\
    \ target=(xor_val>>i)&1;\n            bool go_to=target^((bit>>i)&1);\n      \
    \      if(!cur->nxt[go_to]) return nullptr;\n            cur=cur->nxt[go_to];\n\
    \        }\n        return cur;\n    }\n\n    public:\n    BinaryTrie():root(new\
    \ Node()){}\n\n    void add(BitType bit,C c=1,BitType xor_val=0){\n        Node\
    \ *cur=root;\n        for(int i=MAXLOG-1;i>=0;i--){\n            bool target=(xor_val>>i)&1;\n\
    \            bool go_to=target^((bit>>i)&1);\n            if(!cur->nxt[go_to])\
    \ cur->nxt[go_to]=new Node();\n            cur->cnt+=c;\n            cur=cur->nxt[go_to];\n\
    \        }\n        cur->cnt+=c;\n        return ;\n    }\n    void erase(BitType\
    \ bit,C c=1,BitType xor_val=0){\n        add(bit,-c,xor_val);\n    }\n    BitType\
    \ kth_element(C k,BitType xor_val=0){\n        assert(0<=k and k<root->cnt);\n\
    \        C ret=0;\n        Node *cur=root;\n        for(int i=MAXLOG-1;i>=0;i--){\n\
    \            bool xored_0=(xor_val>>i)&1;\n            if(!cur->nxt[xored_0] or\
    \  cur->nxt[xored_0]->cnt<=k){\n                k-=(cur->nxt[xored_0]?cur->nxt[xored_0]->cnt:0);\n\
    \                cur=cur->nxt[xored_0^1];\n                ret+=(BitType(1)<<i);\n\
    \            }else{\n                cur=cur->nxt[xored_0];\n            }\n \
    \       }\n        return ret;\n    }\n    BitType min_element(BitType xor_val=0){\n\
    \        return kth_element(0,xor_val);\n    }\n    BitType max_element(BitType\
    \ xor_val=0){\n        return kth_element(root->cnt-1,xor_val);\n    }\n    C\
    \ count(BitType bit,BitType xor_val=0){\n        auto target=find(bit,xor_val);\n\
    \        return target?target->cnt:0;\n    }\n    C count_less(BitType bit,BitType\
    \ xor_val=0){\n        C ret=0;\n        Node *cur=root;\n        for(int i=MAXLOG-1;i>=0;i--){\n\
    \            if(!cur) break;\n            bool xored_0=(xor_val>>i)&1;\n     \
    \       if((bit>>i)&1 and cur->nxt[xored_0]) ret+=cur->nxt[xored_0]->cnt;\n  \
    \          cur=cur->nxt[xored_0^((bit>>i)&1)];\n        }\n        return ret;\n\
    \    }\n};\n"
  code: "template<typename BitType,int MAXLOG,typename C=int>\nstruct BinaryTrie{\n\
    \    private:\n    struct Node{\n        Node *nxt[2];\n        C cnt;\n     \
    \   Node():nxt{nullptr,nullptr},cnt(0){}\n    };\n\n    Node *root;\n\n    Node\
    \ *find(BitType bit,BitType xor_val=0){\n        Node *cur=root;\n        for(int\
    \ i=MAXLOG-1;i>=0;i--){\n            bool target=(xor_val>>i)&1;\n           \
    \ bool go_to=target^((bit>>i)&1);\n            if(!cur->nxt[go_to]) return nullptr;\n\
    \            cur=cur->nxt[go_to];\n        }\n        return cur;\n    }\n\n \
    \   public:\n    BinaryTrie():root(new Node()){}\n\n    void add(BitType bit,C\
    \ c=1,BitType xor_val=0){\n        Node *cur=root;\n        for(int i=MAXLOG-1;i>=0;i--){\n\
    \            bool target=(xor_val>>i)&1;\n            bool go_to=target^((bit>>i)&1);\n\
    \            if(!cur->nxt[go_to]) cur->nxt[go_to]=new Node();\n            cur->cnt+=c;\n\
    \            cur=cur->nxt[go_to];\n        }\n        cur->cnt+=c;\n        return\
    \ ;\n    }\n    void erase(BitType bit,C c=1,BitType xor_val=0){\n        add(bit,-c,xor_val);\n\
    \    }\n    BitType kth_element(C k,BitType xor_val=0){\n        assert(0<=k and\
    \ k<root->cnt);\n        C ret=0;\n        Node *cur=root;\n        for(int i=MAXLOG-1;i>=0;i--){\n\
    \            bool xored_0=(xor_val>>i)&1;\n            if(!cur->nxt[xored_0] or\
    \  cur->nxt[xored_0]->cnt<=k){\n                k-=(cur->nxt[xored_0]?cur->nxt[xored_0]->cnt:0);\n\
    \                cur=cur->nxt[xored_0^1];\n                ret+=(BitType(1)<<i);\n\
    \            }else{\n                cur=cur->nxt[xored_0];\n            }\n \
    \       }\n        return ret;\n    }\n    BitType min_element(BitType xor_val=0){\n\
    \        return kth_element(0,xor_val);\n    }\n    BitType max_element(BitType\
    \ xor_val=0){\n        return kth_element(root->cnt-1,xor_val);\n    }\n    C\
    \ count(BitType bit,BitType xor_val=0){\n        auto target=find(bit,xor_val);\n\
    \        return target?target->cnt:0;\n    }\n    C count_less(BitType bit,BitType\
    \ xor_val=0){\n        C ret=0;\n        Node *cur=root;\n        for(int i=MAXLOG-1;i>=0;i--){\n\
    \            if(!cur) break;\n            bool xored_0=(xor_val>>i)&1;\n     \
    \       if((bit>>i)&1 and cur->nxt[xored_0]) ret+=cur->nxt[xored_0]->cnt;\n  \
    \          cur=cur->nxt[xored_0^((bit>>i)&1)];\n        }\n        return ret;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo_Set_Xor_Min.test.cpp
  - test/AOJ_DSL_2_B.test.cpp
documentation_of: DataStructure/BinaryTrie.hpp
layout: document
title: Binary Trie
---

## 概要  
Binary Trie  
add, erase, count_less, count, kth_element - O(MAXLOG)  

## ref  
https://ei1333.github.io/library/structure/trie/binary-trie.hpp  
https://kopricky.github.io/code/DataStructure_Basic/binary_trie.html  

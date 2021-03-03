---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_ALDS1_9_C.test.cpp
    title: test/AOJ_ALDS1_9_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Heap/LeftistHeap.cpp\"\ntemplate<typename T,bool less=true>\n\
    struct LeftistHeap{\n    struct Node{\n        Node *l,*r;\n        int s;\n \
    \       T val;\n        Node(T val):l(nullptr),r(nullptr),s(1),val(val){}\n  \
    \  };\n    Node *root;\n    LeftistHeap(Node *t=nullptr):root(t){}\n\n    virtual\
    \ Node *clone(Node *t){\n        return t;\n    }\n\n    Node *meld(Node *a,Node\
    \ *b){\n        if(!a or !b) return (a?a:b);\n        a=clone(a);\n        if((a->val>b->val)^(!less))\
    \ swap(a,b);\n        a->r=meld(a->r,b);\n        if(!a->l or a->l->s<a->r->s)\
    \ swap(a->l,a->r);\n        a->s=(a->r?a->r->s:0)+1;\n        return a;\n    }\n\
    \    void meld(LeftistHeap b){\n        root=meld(root,b.root);\n    }\n    void\
    \ push(T x){\n        root=meld(root,new Node(x));\n    }\n    T pop(){\n    \
    \    assert(root!=nullptr);\n        T ret=root->val;\n        root=meld(root->l,root->r);\n\
    \        return ret;\n    }\n    T top(){\n        assert(root!=nullptr);\n  \
    \      return root->val;\n    }\n};\n"
  code: "template<typename T,bool less=true>\nstruct LeftistHeap{\n    struct Node{\n\
    \        Node *l,*r;\n        int s;\n        T val;\n        Node(T val):l(nullptr),r(nullptr),s(1),val(val){}\n\
    \    };\n    Node *root;\n    LeftistHeap(Node *t=nullptr):root(t){}\n\n    virtual\
    \ Node *clone(Node *t){\n        return t;\n    }\n\n    Node *meld(Node *a,Node\
    \ *b){\n        if(!a or !b) return (a?a:b);\n        a=clone(a);\n        if((a->val>b->val)^(!less))\
    \ swap(a,b);\n        a->r=meld(a->r,b);\n        if(!a->l or a->l->s<a->r->s)\
    \ swap(a->l,a->r);\n        a->s=(a->r?a->r->s:0)+1;\n        return a;\n    }\n\
    \    void meld(LeftistHeap b){\n        root=meld(root,b.root);\n    }\n    void\
    \ push(T x){\n        root=meld(root,new Node(x));\n    }\n    T pop(){\n    \
    \    assert(root!=nullptr);\n        T ret=root->val;\n        root=meld(root->l,root->r);\n\
    \        return ret;\n    }\n    T top(){\n        assert(root!=nullptr);\n  \
    \      return root->val;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Heap/LeftistHeap.cpp
  requiredBy: []
  timestamp: '2021-03-03 23:39:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_ALDS1_9_C.test.cpp
documentation_of: Heap/LeftistHeap.cpp
layout: document
title: Leftist Heap
---

## 概要  
http://hos.ac/blog/#blog0001  

heapの併合，meldが可能

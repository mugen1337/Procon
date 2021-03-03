---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Heap/PersistentLeftistHeap.cpp\"\ntemplate<typename T,bool\
    \ less=true>\nstruct PersistentLeftistHeap{\n    struct Node{\n        Node *l,*r;\n\
    \        int s;\n        T val;\n        Node(T val):l(nullptr),r(nullptr),s(1),val(val){}\n\
    \    };\n    Node *root;\n    PersistentLeftistHeap(Node *t=nullptr):root(t){}\n\
    \n    Node *meld(Node *a,Node *b){\n        if(!a or !b) return (a?a:b);\n   \
    \     if((a->val>b->val)^(!less)) swap(a,b);\n        a=new Node(*a);b=new Node(*b);\n\
    \        a->r=meld(a->r,b);\n        if(!a->l or a->l->s<a->r->s) swap(a->l,a->r);\n\
    \        a->s=(a->r?a->r->s:0)+1;\n        return a;\n    }\n    PersistentLeftistHeap\
    \ meld(PersistentLeftistHeap b){\n        return PersistentLeftistHeap(meld(root,b.root));\n\
    \    }\n    PersistentLeftistHeap push(T x){\n        return PersistentLeftistHeap(meld(root,new\
    \ Node(x)));\n    }\n    PersistentLeftistHeap pop(){\n        assert(root!=nullptr);\n\
    \        return PersistentLeftistHeap(meld(root->l,root->r));\n    }\n    T top(){\n\
    \        assert(root!=nullptr);\n        return root->val;\n    }\n};\n"
  code: "template<typename T,bool less=true>\nstruct PersistentLeftistHeap{\n    struct\
    \ Node{\n        Node *l,*r;\n        int s;\n        T val;\n        Node(T val):l(nullptr),r(nullptr),s(1),val(val){}\n\
    \    };\n    Node *root;\n    PersistentLeftistHeap(Node *t=nullptr):root(t){}\n\
    \n    Node *meld(Node *a,Node *b){\n        if(!a or !b) return (a?a:b);\n   \
    \     if((a->val>b->val)^(!less)) swap(a,b);\n        a=new Node(*a);b=new Node(*b);\n\
    \        a->r=meld(a->r,b);\n        if(!a->l or a->l->s<a->r->s) swap(a->l,a->r);\n\
    \        a->s=(a->r?a->r->s:0)+1;\n        return a;\n    }\n    PersistentLeftistHeap\
    \ meld(PersistentLeftistHeap b){\n        return PersistentLeftistHeap(meld(root,b.root));\n\
    \    }\n    PersistentLeftistHeap push(T x){\n        return PersistentLeftistHeap(meld(root,new\
    \ Node(x)));\n    }\n    PersistentLeftistHeap pop(){\n        assert(root!=nullptr);\n\
    \        return PersistentLeftistHeap(meld(root->l,root->r));\n    }\n    T top(){\n\
    \        assert(root!=nullptr);\n        return root->val;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Heap/PersistentLeftistHeap.cpp
  requiredBy: []
  timestamp: '2021-03-04 00:08:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Heap/PersistentLeftistHeap.cpp
layout: document
redirect_from:
- /library/Heap/PersistentLeftistHeap.cpp
- /library/Heap/PersistentLeftistHeap.cpp.html
title: Heap/PersistentLeftistHeap.cpp
---

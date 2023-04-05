---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/KDTree.hpp\"\ntemplate<typename T>\nstruct\
    \ KDTree{\n    private:\n    using P=pair<T,T>;\n    struct Node{\n        Node\
    \ *l, *r;\n        P p;\n        Node(Node *l,Node *r,P p):l(l),r(r),p(p){}\n\
    \    };\n    Node *root;\n    Node *dfs(int l,int r,int dep,vector<P> &v){\n \
    \       if(r<=l) return nullptr;\n        int m=(l+r)/2;\n        if(dep) sort(begin(v)+l,begin(v)+r,[](P\
    \ lhs,P rhs){return lhs.first<rhs.first;});\n        else    sort(begin(v)+l,begin(v)+r,[](P\
    \ lhs,P rhs){return lhs.second<rhs.second;});\n        return (new Node(dfs(l,m,dep^1,v),dfs(m+1,r,dep^1,v),v[m]));\n\
    \    }\n    pair<T,P> find_nearest(Node *cur,T x,T y,int dep,T d,P cur_best){\n\
    \        if(!cur) return pair<T,P>(d,cur_best);\n        ll nd=dis(cur->p,P(x,y));\n\
    \        if(nd<d) d=nd,cur_best=cur->p;\n\n        if(dep){\n            if(cur->l\
    \ and x-d<=cur->p.first) tie(d,cur_best)=find_nearest(cur->l,x,y,dep^1,d,cur_best);\n\
    \            if(cur->r and cur->p.first<=x+d) tie(d,cur_best)=find_nearest(cur->r,x,y,dep^1,d,cur_best);\n\
    \        }else{\n            if(cur->l and y-d<=cur->p.second) tie(d,cur_best)=find_nearest(cur->l,x,y,dep^1,d,cur_best);\n\
    \            if(cur->r and cur->p.second<=y+d) tie(d,cur_best)=find_nearest(cur->r,x,y,dep^1,d,cur_best);\n\
    \        }\n        return pair<T,P>(d,cur_best);\n    }\n\n\n    public:\n  \
    \  KDTree(vector<P> v){\n        root=dfs(0,(int)v.size(),0,v);\n    }\n    inline\
    \ T dis(P lhs,P rhs){\n        return (lhs.first-rhs.first)*(lhs.first-rhs.first)+(lhs.second-rhs.second)*(lhs.second-rhs.second);\n\
    \    }\n    // return  pair(dis, pair(x, y))\n    pair<T,P> find_nearest(T x,T\
    \ y){\n        return find_nearest(root,x,y,0,numeric_limits<T>::max()/2,P(0,0));\n\
    \    }\n};\n"
  code: "template<typename T>\nstruct KDTree{\n    private:\n    using P=pair<T,T>;\n\
    \    struct Node{\n        Node *l, *r;\n        P p;\n        Node(Node *l,Node\
    \ *r,P p):l(l),r(r),p(p){}\n    };\n    Node *root;\n    Node *dfs(int l,int r,int\
    \ dep,vector<P> &v){\n        if(r<=l) return nullptr;\n        int m=(l+r)/2;\n\
    \        if(dep) sort(begin(v)+l,begin(v)+r,[](P lhs,P rhs){return lhs.first<rhs.first;});\n\
    \        else    sort(begin(v)+l,begin(v)+r,[](P lhs,P rhs){return lhs.second<rhs.second;});\n\
    \        return (new Node(dfs(l,m,dep^1,v),dfs(m+1,r,dep^1,v),v[m]));\n    }\n\
    \    pair<T,P> find_nearest(Node *cur,T x,T y,int dep,T d,P cur_best){\n     \
    \   if(!cur) return pair<T,P>(d,cur_best);\n        ll nd=dis(cur->p,P(x,y));\n\
    \        if(nd<d) d=nd,cur_best=cur->p;\n\n        if(dep){\n            if(cur->l\
    \ and x-d<=cur->p.first) tie(d,cur_best)=find_nearest(cur->l,x,y,dep^1,d,cur_best);\n\
    \            if(cur->r and cur->p.first<=x+d) tie(d,cur_best)=find_nearest(cur->r,x,y,dep^1,d,cur_best);\n\
    \        }else{\n            if(cur->l and y-d<=cur->p.second) tie(d,cur_best)=find_nearest(cur->l,x,y,dep^1,d,cur_best);\n\
    \            if(cur->r and cur->p.second<=y+d) tie(d,cur_best)=find_nearest(cur->r,x,y,dep^1,d,cur_best);\n\
    \        }\n        return pair<T,P>(d,cur_best);\n    }\n\n\n    public:\n  \
    \  KDTree(vector<P> v){\n        root=dfs(0,(int)v.size(),0,v);\n    }\n    inline\
    \ T dis(P lhs,P rhs){\n        return (lhs.first-rhs.first)*(lhs.first-rhs.first)+(lhs.second-rhs.second)*(lhs.second-rhs.second);\n\
    \    }\n    // return  pair(dis, pair(x, y))\n    pair<T,P> find_nearest(T x,T\
    \ y){\n        return find_nearest(root,x,y,0,numeric_limits<T>::max()/2,P(0,0));\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/KDTree.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/KDTree.hpp
layout: document
redirect_from:
- /library/DataStructure/KDTree.hpp
- /library/DataStructure/KDTree.hpp.html
title: DataStructure/KDTree.hpp
---

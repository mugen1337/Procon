---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/yosupo_Unionfind_undo.cpp
    title: test/yosupo_Unionfind_undo.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"UnionFind/UnionFindUndo.cpp\"\n// \u7D4C\u8DEF\u5727\u7E2E\
    \u306A\u3057\uFF0C\u30DE\u30FC\u30B8\u30C6\u30AF\u3067unite\uFF0C\u30AF\u30A8\u30EA\
    \u6BCEO(logN)\nstruct UnionFindUndo{\n    int con;\n    vector<int> data;\n  \
    \  stack<tuple<int,int,bool>> history;\n    UnionFindUndo(int sz){\n        con=sz;\n\
    \        data.assign(sz,-1);\n    }\n    bool unite(int x,int y){\n        x=root(x),y=root(y);\n\
    \        \n        if(x==y){\n            history.push(make_tuple(x,data[x],false));\n\
    \            history.push(make_tuple(y,data[y],false));\n            return false;\n\
    \        }\n        con--;\n        history.push(make_tuple(x,data[x],true));\n\
    \        history.push(make_tuple(y,data[y],false));\n        if(data[x]>data[y])\
    \ swap(x,y);\n        data[x]+=data[y];\n        data[y]=x;\n        return true;\n\
    \    }\n    int root(int k){return (data[k]<0?k:(root(data[k])));}\n    int size(int\
    \ k){return (-data[root(k)]);}\n    bool sameroot(int x,int y){return root(x)==root(y);}\n\
    \    void undo(){\n        {\n            auto [fs,sc,con_flag]=history.top();history.pop();\n\
    \            if(con_flag) con++;\n            data[fs]=sc;\n        }\n      \
    \  {\n            auto [fs,sc,con_flag]=history.top();history.pop();\n       \
    \     if(con_flag) con++;\n            data[fs]=sc;\n        }\n    }\n    void\
    \ snapshot(){while(!history.empty())history.pop();}\n    void rollback(){while(!history.empty())undo();}\n\
    };\n"
  code: "// \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057\uFF0C\u30DE\u30FC\u30B8\u30C6\u30AF\
    \u3067unite\uFF0C\u30AF\u30A8\u30EA\u6BCEO(logN)\nstruct UnionFindUndo{\n    int\
    \ con;\n    vector<int> data;\n    stack<tuple<int,int,bool>> history;\n    UnionFindUndo(int\
    \ sz){\n        con=sz;\n        data.assign(sz,-1);\n    }\n    bool unite(int\
    \ x,int y){\n        x=root(x),y=root(y);\n        \n        if(x==y){\n     \
    \       history.push(make_tuple(x,data[x],false));\n            history.push(make_tuple(y,data[y],false));\n\
    \            return false;\n        }\n        con--;\n        history.push(make_tuple(x,data[x],true));\n\
    \        history.push(make_tuple(y,data[y],false));\n        if(data[x]>data[y])\
    \ swap(x,y);\n        data[x]+=data[y];\n        data[y]=x;\n        return true;\n\
    \    }\n    int root(int k){return (data[k]<0?k:(root(data[k])));}\n    int size(int\
    \ k){return (-data[root(k)]);}\n    bool sameroot(int x,int y){return root(x)==root(y);}\n\
    \    void undo(){\n        {\n            auto [fs,sc,con_flag]=history.top();history.pop();\n\
    \            if(con_flag) con++;\n            data[fs]=sc;\n        }\n      \
    \  {\n            auto [fs,sc,con_flag]=history.top();history.pop();\n       \
    \     if(con_flag) con++;\n            data[fs]=sc;\n        }\n    }\n    void\
    \ snapshot(){while(!history.empty())history.pop();}\n    void rollback(){while(!history.empty())undo();}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: UnionFind/UnionFindUndo.cpp
  requiredBy:
  - test/yosupo_Unionfind_undo.cpp
  timestamp: '2021-01-04 00:35:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: UnionFind/UnionFindUndo.cpp
layout: document
redirect_from:
- /library/UnionFind/UnionFindUndo.cpp
- /library/UnionFind/UnionFindUndo.cpp.html
title: UnionFind/UnionFindUndo.cpp
---

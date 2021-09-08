---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ_2863.test.cpp
    title: test/AOJ_2863.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/Trie.cpp\"\ntemplate<int sz>\nstruct Trie{\nprivate:\n\
    \    struct Node{\n        int nxt[sz],cnt;\n        vector<int> accept;\n   \
    \     Node():cnt(0){memset(nxt,-1,sizeof(nxt));}\n    };\n\n    function<int(char)>\
    \ conv;\n    vector<Node> nodes;\n    int root;\n\n    void add(const string &s,int\
    \ id,int s_idx=0,int node_idx=0){\n        if(s_idx==(int)s.size()){\n       \
    \     nodes[node_idx].accept.push_back(id);\n            return ;\n        }\n\
    \        int k=conv(s[s_idx]);\n        if(nodes[node_idx].nxt[k]==-1){\n    \
    \        nodes[node_idx].nxt[k]=(int)nodes.size();\n            nodes.push_back(Node());\n\
    \        }\n        add(s,id,s_idx+1,nodes[node_idx].nxt[k]);\n        nodes[node_idx].cnt++;\n\
    \    }\n    void query(const string &s,const function<void(int)> &f,int s_idx=0,int\
    \ node_idx=0){\n        for(auto &idx:nodes[node_idx].accept)f(idx);\n       \
    \ if(s_idx==(int)s.size()) return ;\n        else {\n            int k=conv(s[s_idx]);\n\
    \            if(nodes[node_idx].nxt[k]==-1) return;\n            query(s,f,s_idx+1,nodes[node_idx].nxt[k]);\n\
    \        }\n    }\n\npublic:\n \n    Trie(function<int(char)> conv):conv(conv),root(0){nodes.push_back(Node());}\n\
    \    void add(const string &s,int idx=0){ add(s,idx,0,0); }\n    // f(k) := \u6587\
    \u5B57\u5217\u306Eidx\u3092\u901A\u904E\u3059\u308B\u306E\u3067\u305D\u308C\u306B\
    \u5BFE\u3059\u308B\u51E6\u7406, s[s_idx]\u304B\u3089\u8AAD\u307F\u59CB\u3081\u308B\
    \n    void query(const string &s,const function<void(int)> &f,int s_idx=0){ query(s,f,s_idx,0);\
    \ }\n\n    bool search(const string &s){\n        int node_idx=0;\n        for(int\
    \ i=0;i<(int)s.size();i++){\n            int k=conv(s[i]);\n            if(nodes[node_idx].nxt[k]==-1)\
    \ return false;\n            node_idx=nodes[node_idx].nxt[k];\n        }\n   \
    \     return !nodes[node_idx].empty();\n    }\n    int count(){\n        return\
    \ nodes[0].cnt;\n    }\n    int size(){\n        return (int)nodes.size();\n \
    \   }\n};\n// // converter, lower_case alphabet -> int\n// int conv(char x){return\
    \ x-'a';}\n"
  code: "template<int sz>\nstruct Trie{\nprivate:\n    struct Node{\n        int nxt[sz],cnt;\n\
    \        vector<int> accept;\n        Node():cnt(0){memset(nxt,-1,sizeof(nxt));}\n\
    \    };\n\n    function<int(char)> conv;\n    vector<Node> nodes;\n    int root;\n\
    \n    void add(const string &s,int id,int s_idx=0,int node_idx=0){\n        if(s_idx==(int)s.size()){\n\
    \            nodes[node_idx].accept.push_back(id);\n            return ;\n   \
    \     }\n        int k=conv(s[s_idx]);\n        if(nodes[node_idx].nxt[k]==-1){\n\
    \            nodes[node_idx].nxt[k]=(int)nodes.size();\n            nodes.push_back(Node());\n\
    \        }\n        add(s,id,s_idx+1,nodes[node_idx].nxt[k]);\n        nodes[node_idx].cnt++;\n\
    \    }\n    void query(const string &s,const function<void(int)> &f,int s_idx=0,int\
    \ node_idx=0){\n        for(auto &idx:nodes[node_idx].accept)f(idx);\n       \
    \ if(s_idx==(int)s.size()) return ;\n        else {\n            int k=conv(s[s_idx]);\n\
    \            if(nodes[node_idx].nxt[k]==-1) return;\n            query(s,f,s_idx+1,nodes[node_idx].nxt[k]);\n\
    \        }\n    }\n\npublic:\n \n    Trie(function<int(char)> conv):conv(conv),root(0){nodes.push_back(Node());}\n\
    \    void add(const string &s,int idx=0){ add(s,idx,0,0); }\n    // f(k) := \u6587\
    \u5B57\u5217\u306Eidx\u3092\u901A\u904E\u3059\u308B\u306E\u3067\u305D\u308C\u306B\
    \u5BFE\u3059\u308B\u51E6\u7406, s[s_idx]\u304B\u3089\u8AAD\u307F\u59CB\u3081\u308B\
    \n    void query(const string &s,const function<void(int)> &f,int s_idx=0){ query(s,f,s_idx,0);\
    \ }\n\n    bool search(const string &s){\n        int node_idx=0;\n        for(int\
    \ i=0;i<(int)s.size();i++){\n            int k=conv(s[i]);\n            if(nodes[node_idx].nxt[k]==-1)\
    \ return false;\n            node_idx=nodes[node_idx].nxt[k];\n        }\n   \
    \     return !nodes[node_idx].empty();\n    }\n    int count(){\n        return\
    \ nodes[0].cnt;\n    }\n    int size(){\n        return (int)nodes.size();\n \
    \   }\n};\n// // converter, lower_case alphabet -> int\n// int conv(char x){return\
    \ x-'a';}"
  dependsOn: []
  isVerificationFile: false
  path: String/Trie.cpp
  requiredBy: []
  timestamp: '2021-09-04 00:46:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ_2863.test.cpp
documentation_of: String/Trie.cpp
layout: document
redirect_from:
- /library/String/Trie.cpp
- /library/String/Trie.cpp.html
title: String/Trie.cpp
---

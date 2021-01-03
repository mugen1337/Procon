---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_2292.test.cpp
    title: test/AOJ_2292.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/PalindromicTree.cpp\"\n// \u6587\u5B57\u7A2Ea\u306B\
    \u5BFE\u3057\uFF0Cbuild O(na)\nstruct PalindromicTree{\n    struct node{\n   \
    \     map<char,int> link;// link aba -> xabax\n        int len,cnt,idx;// idx:\u3053\
    \u306E\u56DE\u6587\u306E1\u3064\u306E\u5DE6\u7AEF, RH\u306A\u3069\u306E\u305F\u3081\
    \n        int suffix_link;\n        node(){}\n        node(int len,int cnt,int\
    \ idx,int suffix_link):len(len),cnt(cnt),idx(idx),suffix_link(suffix_link){}\n\
    \    };\n\n    vector<node> v;// 0:(-1), 1: (0)\n    int n,ptr;\n\n    PalindromicTree(){}\n\
    \    PalindromicTree(const string &s):v(2),n(2),ptr(1){\n        v[0]=node(-1,0,-1,0);v[1]=node(0,0,-1,0);\n\
    \        for(int i=0;i<(int)s.size();i++) process(s,i);\n        build_freq();\n\
    \    }\n\n    bool process(const string &s,int pos){\n        int cur=ptr;// link\
    \ parent\n        while(true){\n            int rev=pos-v[cur].len-1;\n      \
    \      if(rev>=0 and s[rev]==s[pos]) break;\n            cur=v[cur].suffix_link;\n\
    \        }\n        if(v[cur].link.count(s[pos])){\n            ptr=v[cur].link[s[pos]];\n\
    \            v[ptr].cnt++;\n            return false;\n        }\n        ptr=n++;\n\
    \n        v.emplace_back(v[cur].len+2,1,pos-v[cur].len-1,-1);\n        v[cur].link[s[pos]]=ptr;//\
    \ link\n        if(v[ptr].len==1){\n            v[ptr].suffix_link=1;\n      \
    \      return true;\n        }\n\n        while(true){\n            cur=v[cur].suffix_link;\n\
    \            int rev=pos-v[cur].len-1;\n            if(rev>=0 and s[rev]==s[pos]){\n\
    \                v[ptr].suffix_link=v[cur].link[s[pos]];\n                break;\n\
    \            }\n        }\n        return true;\n    }\n    // DAG\u3092\u30C8\
    \u30DD\u30BD\n    vector<int> calc_ord(){\n        vector<int> ret;\n        ret.emplace_back(0);\n\
    \        ret.emplace_back(1);\n        for(int i=0;i<(int)ret.size();i++)for(auto\
    \ &p:v[ret[i]].link) ret.emplace_back(p.second);\n        return ret;\n    }\n\
    \    void build_freq(){\n        auto ord=calc_ord();\n        // \u4E00\u756A\
    \u9577\u3044\u56DE\u6587\u306B\u3057\u304Bcnt+=1\u3092\u3057\u3066\u3044\u306A\
    \u3044\u306E\u3067\uFF0Clink\u3067\u96C6\u7D04\u3059\u308B\n        for(int i=(int)ord.size()-1;i>=0;i--)\
    \ v[v[ord[i]].suffix_link].cnt+=v[ord[i]].cnt;\n    }\n    int count_unique(){return\
    \ n-2;}\n    int size(){return n;}\n    node operator[](const int &k){return v[k];}\n\
    };\n"
  code: "// \u6587\u5B57\u7A2Ea\u306B\u5BFE\u3057\uFF0Cbuild O(na)\nstruct PalindromicTree{\n\
    \    struct node{\n        map<char,int> link;// link aba -> xabax\n        int\
    \ len,cnt,idx;// idx:\u3053\u306E\u56DE\u6587\u306E1\u3064\u306E\u5DE6\u7AEF,\
    \ RH\u306A\u3069\u306E\u305F\u3081\n        int suffix_link;\n        node(){}\n\
    \        node(int len,int cnt,int idx,int suffix_link):len(len),cnt(cnt),idx(idx),suffix_link(suffix_link){}\n\
    \    };\n\n    vector<node> v;// 0:(-1), 1: (0)\n    int n,ptr;\n\n    PalindromicTree(){}\n\
    \    PalindromicTree(const string &s):v(2),n(2),ptr(1){\n        v[0]=node(-1,0,-1,0);v[1]=node(0,0,-1,0);\n\
    \        for(int i=0;i<(int)s.size();i++) process(s,i);\n        build_freq();\n\
    \    }\n\n    bool process(const string &s,int pos){\n        int cur=ptr;// link\
    \ parent\n        while(true){\n            int rev=pos-v[cur].len-1;\n      \
    \      if(rev>=0 and s[rev]==s[pos]) break;\n            cur=v[cur].suffix_link;\n\
    \        }\n        if(v[cur].link.count(s[pos])){\n            ptr=v[cur].link[s[pos]];\n\
    \            v[ptr].cnt++;\n            return false;\n        }\n        ptr=n++;\n\
    \n        v.emplace_back(v[cur].len+2,1,pos-v[cur].len-1,-1);\n        v[cur].link[s[pos]]=ptr;//\
    \ link\n        if(v[ptr].len==1){\n            v[ptr].suffix_link=1;\n      \
    \      return true;\n        }\n\n        while(true){\n            cur=v[cur].suffix_link;\n\
    \            int rev=pos-v[cur].len-1;\n            if(rev>=0 and s[rev]==s[pos]){\n\
    \                v[ptr].suffix_link=v[cur].link[s[pos]];\n                break;\n\
    \            }\n        }\n        return true;\n    }\n    // DAG\u3092\u30C8\
    \u30DD\u30BD\n    vector<int> calc_ord(){\n        vector<int> ret;\n        ret.emplace_back(0);\n\
    \        ret.emplace_back(1);\n        for(int i=0;i<(int)ret.size();i++)for(auto\
    \ &p:v[ret[i]].link) ret.emplace_back(p.second);\n        return ret;\n    }\n\
    \    void build_freq(){\n        auto ord=calc_ord();\n        // \u4E00\u756A\
    \u9577\u3044\u56DE\u6587\u306B\u3057\u304Bcnt+=1\u3092\u3057\u3066\u3044\u306A\
    \u3044\u306E\u3067\uFF0Clink\u3067\u96C6\u7D04\u3059\u308B\n        for(int i=(int)ord.size()-1;i>=0;i--)\
    \ v[v[ord[i]].suffix_link].cnt+=v[ord[i]].cnt;\n    }\n    int count_unique(){return\
    \ n-2;}\n    int size(){return n;}\n    node operator[](const int &k){return v[k];}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: String/PalindromicTree.cpp
  requiredBy: []
  timestamp: '2021-01-04 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_2292.test.cpp
documentation_of: String/PalindromicTree.cpp
layout: document
redirect_from:
- /library/String/PalindromicTree.cpp
- /library/String/PalindromicTree.cpp.html
title: String/PalindromicTree.cpp
---

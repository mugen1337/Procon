---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Static_Range_Inversions_Query.test.cpp
    title: test/yosupo_Static_Range_Inversions_Query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://beet-aizu.github.io/library/algorithm/mo.hpp
    - https://ei1333.github.io/library/other/mo.hpp
  bundledCode: "#line 1 \"Algorithm/Mo.hpp\"\n/*\nrefs : https://beet-aizu.github.io/library/algorithm/mo.hpp\n\
    \       https://ei1333.github.io/library/other/mo.hpp\n*/\nstruct Mo{\n    using\
    \ F=function<void(int)>;\n    int n,idx,ql,qr;\n    vector<pair<int,int>> query;\n\
    \    vector<int> ord;\n    // [l,r) \n    // add_left  : l-1\u3092\u8DB3\u3059\
    , add_right : r\u3092\u8DB3\u3059\n    // erase_left: l\u3092\u6D88\u3059,  erase_right:\
    \ r-1\u3092\u6D88\u3059\n    F add_left,add_right,erase_left,erase_right;\n \n\
    \    Mo(int n,F add_left,F add_right,F erase_left,F erase_right):\n    n(n),idx(0),ql(0),qr(0),\n\
    \    add_left(add_left),add_right(add_right),erase_left(erase_left),erase_right(erase_right)\n\
    \    {}\n \n    void add(int l,int r){\n        query.emplace_back(l,r);\n   \
    \ }\n \n    void build(){\n        int q=(int)query.size();\n        int bs=n/min(n,int(sqrt(q)));\n\
    \        // \u5DE6\u7AEF\u306E\u30D6\u30ED\u30C3\u30AF\u3067\u30BD\u30FC\u30C8\
    \n        // \u5DE6\u7AEF\u306E\u30D6\u30ED\u30C3\u30AF\u304C\u540C\u3058\u306A\
    \u3089\u53F3\u7AEF\u3067\u30BD\u30FC\u30C8\n        ord.resize(q);\n        iota(begin(ord),end(ord),0);\n\
    \        sort(begin(ord),end(ord),[&](int a,int b){\n            int al=query[a].first/bs,bl=query[b].first/bs;\n\
    \            if(al!=bl) return al<bl;\n            // \u5076\u5947\u3067\u59CB\
    \u70B9\u3092\u5DE6\u53F3\u306B\u632F\u308B\u3068\u52D5\u304D\u306B\u7121\u99C4\
    \u304C\u306A\u3044\n            if(al&1) return query[a].second>query[b].second;\n\
    \            return query[a].second<query[b].second;\n        });\n    }\n \n\
    \    // 1\u500B\u30AF\u30A8\u30EA\u3092\u9032\u3081\uFF0C\u51E6\u7406\u3057\u305F\
    \u30AF\u30A8\u30EA\u306Eindex\u3092\u8FD4\u3059\n    // process\u304C\u7D42\u308F\
    \u3063\u3066\u304B\u3089\u7D50\u679C\u3092\u683C\u7D0D\u3059\u308B\u3053\u3068\
    \n    // ans[process()]=res; \u306F\u3067\u304D\u306A\u3044\n    int process(){\n\
    \        if(idx>=(int)ord.size()) return -1;\n        int cur=ord[idx++];\n  \
    \      while(ql>query[cur].first)  add_left(--ql);\n        while(qr<query[cur].second)\
    \ add_right(qr++);\n        while(ql<query[cur].first)  erase_left(ql++);\n  \
    \      while(qr>query[cur].second) erase_right(--qr);\n        return cur;\n \
    \   }\n};\n"
  code: "/*\nrefs : https://beet-aizu.github.io/library/algorithm/mo.hpp\n       https://ei1333.github.io/library/other/mo.hpp\n\
    */\nstruct Mo{\n    using F=function<void(int)>;\n    int n,idx,ql,qr;\n    vector<pair<int,int>>\
    \ query;\n    vector<int> ord;\n    // [l,r) \n    // add_left  : l-1\u3092\u8DB3\
    \u3059, add_right : r\u3092\u8DB3\u3059\n    // erase_left: l\u3092\u6D88\u3059\
    ,  erase_right: r-1\u3092\u6D88\u3059\n    F add_left,add_right,erase_left,erase_right;\n\
    \ \n    Mo(int n,F add_left,F add_right,F erase_left,F erase_right):\n    n(n),idx(0),ql(0),qr(0),\n\
    \    add_left(add_left),add_right(add_right),erase_left(erase_left),erase_right(erase_right)\n\
    \    {}\n \n    void add(int l,int r){\n        query.emplace_back(l,r);\n   \
    \ }\n \n    void build(){\n        int q=(int)query.size();\n        int bs=n/min(n,int(sqrt(q)));\n\
    \        // \u5DE6\u7AEF\u306E\u30D6\u30ED\u30C3\u30AF\u3067\u30BD\u30FC\u30C8\
    \n        // \u5DE6\u7AEF\u306E\u30D6\u30ED\u30C3\u30AF\u304C\u540C\u3058\u306A\
    \u3089\u53F3\u7AEF\u3067\u30BD\u30FC\u30C8\n        ord.resize(q);\n        iota(begin(ord),end(ord),0);\n\
    \        sort(begin(ord),end(ord),[&](int a,int b){\n            int al=query[a].first/bs,bl=query[b].first/bs;\n\
    \            if(al!=bl) return al<bl;\n            // \u5076\u5947\u3067\u59CB\
    \u70B9\u3092\u5DE6\u53F3\u306B\u632F\u308B\u3068\u52D5\u304D\u306B\u7121\u99C4\
    \u304C\u306A\u3044\n            if(al&1) return query[a].second>query[b].second;\n\
    \            return query[a].second<query[b].second;\n        });\n    }\n \n\
    \    // 1\u500B\u30AF\u30A8\u30EA\u3092\u9032\u3081\uFF0C\u51E6\u7406\u3057\u305F\
    \u30AF\u30A8\u30EA\u306Eindex\u3092\u8FD4\u3059\n    // process\u304C\u7D42\u308F\
    \u3063\u3066\u304B\u3089\u7D50\u679C\u3092\u683C\u7D0D\u3059\u308B\u3053\u3068\
    \n    // ans[process()]=res; \u306F\u3067\u304D\u306A\u3044\n    int process(){\n\
    \        if(idx>=(int)ord.size()) return -1;\n        int cur=ord[idx++];\n  \
    \      while(ql>query[cur].first)  add_left(--ql);\n        while(qr<query[cur].second)\
    \ add_right(qr++);\n        while(ql<query[cur].first)  erase_left(ql++);\n  \
    \      while(qr>query[cur].second) erase_right(--qr);\n        return cur;\n \
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/Mo.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_Static_Range_Inversions_Query.test.cpp
documentation_of: Algorithm/Mo.hpp
layout: document
redirect_from:
- /library/Algorithm/Mo.hpp
- /library/Algorithm/Mo.hpp.html
title: Algorithm/Mo.hpp
---

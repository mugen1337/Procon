---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_0109.test.cpp
    title: test/AOJ_0109.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Other/Parser.cpp\"\n// \u69CB\u6587\u89E3\u6790\ntemplate<typename\
    \ T>\nstruct Parser{\n    bool error;// \u30E4\u30D0\u30A4\u6642true\u306B\n \
    \   Parser():error(false){}\n\n    // \u56DB\u5247\u6F14\u7B97\n    T expression(string\
    \ s,int &p){\n        T res=term(s,p);\n        while(p<(int)s.size()){\n    \
    \        if(s[p]=='+'){\n                p++;\n                res+=term(s,p);\n\
    \                continue;\n            }\n            if(s[p]=='-'){\n      \
    \          p++;\n                res-=term(s,p);\n                continue;\n\
    \            }\n            break;\n        }\n        return res;\n    }\n\n\
    \    // \u4E57\u9664\n    T term(string s,int &p){\n        T res=factor(s,p);\n\
    \        while(p<(int)s.size()){\n            if(s[p]=='*'){\n               \
    \ p++;\n                res*=factor(s,p);\n                continue;\n       \
    \     }\n            if(s[p]=='/'){\n                p++;\n                T d=factor(s,p);\n\
    \                if(d==T(0)){\n                    error=true;\n             \
    \       break;\n                }\n                res/=d;\n                continue;\n\
    \            }\n            break;\n        }\n        return res;\n    }\n\n\
    \    // \u30AB\u30C3\u30B3\uFF0C\u6570\n    T factor(string &s,int &p){\n    \
    \    T res;\n        if(s[p]=='('){\n            p++;\n            res=expression(s,p);\n\
    \            p++;\n        }else{\n            res=number(s,p);\n        }\n \
    \       return res;\n    }\n\n    // \u6570\uFF0Cint\u306E\u307F\u306A\u3089\u3053\
    \u308C\u3067\u3044\u3044\uFF0E\n    // int\u4EE5\u5916\u306E\u6570\u3092\u53D7\
    \u3051\u53D6\u308B\u5834\u5408\u306F\u9069\u5B9C\u7DE8\u96C6\u3059\u308B\u3053\
    \u3068\n    T number(string s,int &p){\n        T res=0;\n        while(p<(int)s.size()\
    \ and isdigit(s[p])) res=res*10+s[p++]-'0';\n        return res;\n    }\n\n\n\
    \    T execute(string s){\n        int p=0;\n        error=false;\n        return\
    \ expression(s,p);\n    }\n};\n"
  code: "// \u69CB\u6587\u89E3\u6790\ntemplate<typename T>\nstruct Parser{\n    bool\
    \ error;// \u30E4\u30D0\u30A4\u6642true\u306B\n    Parser():error(false){}\n\n\
    \    // \u56DB\u5247\u6F14\u7B97\n    T expression(string s,int &p){\n       \
    \ T res=term(s,p);\n        while(p<(int)s.size()){\n            if(s[p]=='+'){\n\
    \                p++;\n                res+=term(s,p);\n                continue;\n\
    \            }\n            if(s[p]=='-'){\n                p++;\n           \
    \     res-=term(s,p);\n                continue;\n            }\n            break;\n\
    \        }\n        return res;\n    }\n\n    // \u4E57\u9664\n    T term(string\
    \ s,int &p){\n        T res=factor(s,p);\n        while(p<(int)s.size()){\n  \
    \          if(s[p]=='*'){\n                p++;\n                res*=factor(s,p);\n\
    \                continue;\n            }\n            if(s[p]=='/'){\n      \
    \          p++;\n                T d=factor(s,p);\n                if(d==T(0)){\n\
    \                    error=true;\n                    break;\n               \
    \ }\n                res/=d;\n                continue;\n            }\n     \
    \       break;\n        }\n        return res;\n    }\n\n    // \u30AB\u30C3\u30B3\
    \uFF0C\u6570\n    T factor(string &s,int &p){\n        T res;\n        if(s[p]=='('){\n\
    \            p++;\n            res=expression(s,p);\n            p++;\n      \
    \  }else{\n            res=number(s,p);\n        }\n        return res;\n    }\n\
    \n    // \u6570\uFF0Cint\u306E\u307F\u306A\u3089\u3053\u308C\u3067\u3044\u3044\
    \uFF0E\n    // int\u4EE5\u5916\u306E\u6570\u3092\u53D7\u3051\u53D6\u308B\u5834\
    \u5408\u306F\u9069\u5B9C\u7DE8\u96C6\u3059\u308B\u3053\u3068\n    T number(string\
    \ s,int &p){\n        T res=0;\n        while(p<(int)s.size() and isdigit(s[p]))\
    \ res=res*10+s[p++]-'0';\n        return res;\n    }\n\n\n    T execute(string\
    \ s){\n        int p=0;\n        error=false;\n        return expression(s,p);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Other/Parser.cpp
  requiredBy: []
  timestamp: '2021-01-04 13:35:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_0109.test.cpp
documentation_of: Other/Parser.cpp
layout: document
redirect_from:
- /library/Other/Parser.cpp
- /library/Other/Parser.cpp.html
title: Other/Parser.cpp
---

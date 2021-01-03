---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/0109
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/0109
  bundledCode: "#line 1 \"Other/Parser.test.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int i=0;i<(n);i++)\n\
    #define debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n#define\
    \ mod 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\n\
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \nstruct IOSetup{\n    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n\
    \        cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0109\"\
    \n\n\n// \u69CB\u6587\u89E3\u6790\ntemplate<typename T>\nstruct Parser{\n    bool\
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
    \    }\n};\n\nParser<int> parse;\n\nvoid solve(){\n    string s;cin>>s;\n    s.pop_back();\n\
    \    cout<<parse.execute(s)<<endl;\n}\n\nsigned main(){\n    int q;cin>>q;\n \
    \   while(q--) solve();\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto\
    \ x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\nusing ll=long long;\n\
    const int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n\
    // ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\ntemplate<class T>bool chmax(T &a,const\
    \ T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool chmin(T\
    \ &a,const T &b){if(b<a){a=b;return true;}return false;}\n\nstruct IOSetup{\n\
    \    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n     \
    \   cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename T>\n\
    ostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0109\"\
    \n\n\n// \u69CB\u6587\u89E3\u6790\ntemplate<typename T>\nstruct Parser{\n    bool\
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
    \    }\n};\n\nParser<int> parse;\n\nvoid solve(){\n    string s;cin>>s;\n    s.pop_back();\n\
    \    cout<<parse.execute(s)<<endl;\n}\n\nsigned main(){\n    int q;cin>>q;\n \
    \   while(q--) solve();\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: Other/Parser.test.cpp
  requiredBy: []
  timestamp: '2021-01-02 17:11:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Other/Parser.test.cpp
layout: document
redirect_from:
- /verify/Other/Parser.test.cpp
- /verify/Other/Parser.test.cpp.html
title: Other/Parser.test.cpp
---
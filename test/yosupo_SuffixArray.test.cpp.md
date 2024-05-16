---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/SuffixArray.hpp
    title: String/SuffixArray.hpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"test/yosupo_SuffixArray.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \n\n#line 1 \"bits/stdc++.h\"\n// C\n#ifndef _GLIBCXX_NO_ASSERT\n#include <cassert>\n\
    #endif\n#include <cctype>\n#include <cerrno>\n#include <cfloat>\n#include <ciso646>\n\
    #include <climits>\n#include <clocale>\n#include <cmath>\n#include <csetjmp>\n\
    #include <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <ctime>\n\n#if __cplusplus >=\
    \ 201103L\n#include <ccomplex>\n#include <cfenv>\n#include <cinttypes>\n#include\
    \ <cstdalign>\n#include <cstdbool>\n#include <cstdint>\n#include <ctgmath>\n#include\
    \ <cwchar>\n#include <cwctype>\n#endif\n\n// C++\n#include <algorithm>\n#include\
    \ <bitset>\n#include <complex>\n#include <deque>\n#include <exception>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <ios>\n#include\
    \ <iosfwd>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <locale>\n#include <map>\n#include <memory>\n\
    #include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <typeinfo>\n#include <utility>\n#include\
    \ <valarray>\n#include <vector>\n\n#if __cplusplus >= 201103L\n#include <array>\n\
    #include <atomic>\n#include <chrono>\n#include <condition_variable>\n#include\
    \ <forward_list>\n#include <future>\n#include <initializer_list>\n#include <mutex>\n\
    #include <random>\n#include <ratio>\n#include <regex>\n#include <scoped_allocator>\n\
    #include <system_error>\n#include <thread>\n#include <tuple>\n#include <typeindex>\n\
    #include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n#endif\n\
    #line 2 \"template.hpp\"\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
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
    \   return is;\n}\n\n#line 4 \"test/yosupo_SuffixArray.test.cpp\"\n\n#line 1 \"\
    String/SuffixArray.hpp\"\n/*\nhttps://ei1333.github.io/library/string/suffix-array.hpp\n\
    SA[i] := S[i ~ |S|)\n*/\nstruct SuffixArray{\n    vector<int> SA;\n    const string\
    \ s;\n\n    SuffixArray(const string &s):s(s){\n        SA.resize(s.size());\n\
    \        iota(begin(SA),end(SA),0);\n        sort(begin(SA),end(SA),[&](int i,int\
    \ j){\n            return s[i]==s[j]?i>j:s[i]<s[j];\n        });\n        vector<int>\
    \ cl(s.size()),c(s.begin(),s.end()),cnt(s.size());\n        for(int len=1;len<(int)s.size();len<<=1){\n\
    \            for(int i=0;i<(int)s.size();i++){\n                if(i>0 and c[SA[i-1]]==c[SA[i]]\
    \ and SA[i-1]+len<(int)s.size() and c[SA[i-1]+len/2]==c[SA[i]+len/2])\n      \
    \               cl[SA[i]]=cl[SA[i-1]];\n                else cl[SA[i]]=i;\n  \
    \          }\n            iota(begin(cnt),end(cnt),0);\n            copy(begin(SA),end(SA),begin(c));\n\
    \            for(int i=0;i<(int)s.size();i++){\n                int tmp=c[i]-len;\n\
    \                if(tmp>=0) SA[cnt[cl[tmp]]++]=tmp;\n            }\n         \
    \   swap(c,cl);\n        }\n    }\n\n    int operator[](int idx)const{ return\
    \ SA[idx]; }\n\n    int size()const{return (int)s.size();}\n\n    bool lt_substr(const\
    \ string &t,int si,int ti){\n        int sn=(int)s.size(),tn=(int)t.size();\n\
    \        while(si<sn and ti<tn){\n            if(s[si]<t[ti]) return true;\n \
    \           if(s[si]>t[ti]) return false;\n            si++,ti++;\n        }\n\
    \        return si>=sn and ti<tn;\n    }\n\n    int lower_bound(const string &t){\n\
    \        int lw=-1,hi=(int)SA.size();\n        while(hi-lw>1){\n            int\
    \ mid=(lw+hi)/2;\n            if(lt_substr(t,SA[mid],0)) lw=mid;\n           \
    \ else                       hi=mid;\n        }\n        return hi;\n    }\n\n\
    \    pair<int,int> lower_upper_bound(string &t){\n        int lower=lower_bound(t);\n\
    \        int lw=lower-1,hi=(int)SA.size();\n        t.back()++;\n        while(hi-lw>1){\n\
    \            int mid=(lw+hi)/2;\n            if(lt_substr(t,SA[mid],0)) lw=mid;\n\
    \            else                       hi=mid; \n        }\n        t.back()--;\n\
    \        return {lower,hi};\n    }\n\n    // \u672Averify\n    vector<int> LongestCommonPrefixArray(bool\
    \ output=false){\n        vector<int> rank(size()),LCP(size());\n        for(int\
    \ i=0;i<size();i++) rank[SA[i]]=i;\n        for(int i=0,h=0;i<size();i++){\n \
    \           if(rank[i]+1<size()){\n                for(int j=SA[rank[i]+1];max(i,j)+h<size()\
    \ and s[i+h]==s[j+h];++h) ;\n                LCP[rank[i]+1]=h;\n             \
    \   if(h>0) h--;\n            }\n        }\n        if(output){\n            for(int\
    \ i=0;i<size();i++) cout<<i<<\" : lcp = \"<<LCP[i]<<\" : \"<<s.substr(SA[i])<<endl;\n\
    \        }\n        return LCP;\n    }\n\n    void out(){\n        for(int i=0;i<size();i++)\
    \ cout<<i<<\" : \"<<s.substr(SA[i])<<endl;\n    }\n};\n#line 6 \"test/yosupo_SuffixArray.test.cpp\"\
    \n\nsigned main(){\n    string s;cin>>s;\n    SuffixArray SA(s);\n    rep(i,(int)s.size())\
    \ cout<<SA[i]<<(i+1==(int)s.size()?\"\\n\":\" \");\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"../template.hpp\"\n\n#include \"../String/SuffixArray.hpp\"\n\nsigned main(){\n\
    \    string s;cin>>s;\n    SuffixArray SA(s);\n    rep(i,(int)s.size()) cout<<SA[i]<<(i+1==(int)s.size()?\"\
    \\n\":\" \");\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - bits/stdc++.h
  - String/SuffixArray.hpp
  isVerificationFile: true
  path: test/yosupo_SuffixArray.test.cpp
  requiredBy: []
  timestamp: '2024-05-15 18:03:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_SuffixArray.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_SuffixArray.test.cpp
- /verify/test/yosupo_SuffixArray.test.cpp.html
title: test/yosupo_SuffixArray.test.cpp
---

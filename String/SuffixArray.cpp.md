---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_SuffixArray.test.cpp
    title: test/yosupo_SuffixArray.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.github.io/library/string/suffix-array.cpp
  bundledCode: "#line 1 \"String/SuffixArray.cpp\"\n/*\nhttps://ei1333.github.io/library/string/suffix-array.cpp\n\
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
    \ cout<<i<<\" : \"<<s.substr(SA[i])<<endl;\n    }\n};\n"
  code: "/*\nhttps://ei1333.github.io/library/string/suffix-array.cpp\nSA[i] := S[i\
    \ ~ |S|)\n*/\nstruct SuffixArray{\n    vector<int> SA;\n    const string s;\n\n\
    \    SuffixArray(const string &s):s(s){\n        SA.resize(s.size());\n      \
    \  iota(begin(SA),end(SA),0);\n        sort(begin(SA),end(SA),[&](int i,int j){\n\
    \            return s[i]==s[j]?i>j:s[i]<s[j];\n        });\n        vector<int>\
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
    \ cout<<i<<\" : \"<<s.substr(SA[i])<<endl;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: String/SuffixArray.cpp
  requiredBy: []
  timestamp: '2021-09-08 19:40:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_SuffixArray.test.cpp
documentation_of: String/SuffixArray.cpp
layout: document
redirect_from:
- /library/String/SuffixArray.cpp
- /library/String/SuffixArray.cpp.html
title: String/SuffixArray.cpp
---

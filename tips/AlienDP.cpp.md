---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1279/problem/F
    - https://codeforces.com/contest/1279/submission/105194010
  bundledCode: "#line 1 \"tips/AlienDP.cpp\"\n// PROBLEM : https://codeforces.com/contest/1279/problem/F\n\
    // SUBMIT  : https://codeforces.com/contest/1279/submission/105194010\n\n// v\u306F\
    0 or 1\n// \u5E45l\u3092\u5168\u30661\u306B\u3067\u304D\u308B\uFF0E\u3068\u3044\
    \u3046\u64CD\u4F5C\u3092k\u56DE\u307E\u3067\u884C\u3048\u308B\uFF0E\n// 1\u306E\
    \u6570\u3092\u6700\u5927\u5316\u3059\u308B\uFF0E\nint solve(vector<int> v,int\
    \ l,int k){\n    using P=pair<int,int>;\n\n    int n=(int)v.size();\n\n    //\
    \ 1\u306E\u6570\u306E\u6700\u5927\u5316, \u64CD\u4F5C1\u56DE\u3067\u30DA\u30CA\
    \n    auto f=[&](int pena){\n        vector<P> dp(n+1,P(-INF,0));\n        dp[0]=P(0,0);\n\
    \        rep(i,n){\n            int nxt=min(i+l,n);\n            chmax(dp[nxt],P(dp[i].first+(nxt-i)-pena,dp[i].second+1));\n\
    \            chmax(dp[i+1],P(dp[i].first+v[i],dp[i].second));\n        }\n   \
    \     return dp[n];\n    };\n\n    // \u64CD\u4F5Ck\u56DE\u4EE5\u4E0A\uFF0C\u6700\
    \u5C0F\n    int lw=0,hi=n+2,pena=0;\n    while(lw<=hi){\n        int m=(lw+hi)/2;\n\
    \        P x=f(m);\n        if(x.second>=k){\n            pena=m;\n          \
    \  lw=m+1;\n        }else{\n            hi=m-1;\n        }\n    }\n\n    auto\
    \ ans=f(pena);\n    // k\u500B\u307E\u3067\u306Fok\u306A\u306E\u3067\u30DA\u30CA\
    \u3092\u5E33\u6D88\u3057\n    // \u3053\u306E\u6642\uFF0Cdp\u3067\u306Fk\u56DE\
    \u4EE5\u4E0A\u3072\u3063\u304F\u308A\u8FD4\u3057\u3066\u3044\u308B\u304B\u3082\
    \u3057\u308C\u306A\u3044\u304C\uFF0C\n    // \u3072\u3063\u304F\u308A\u8FD4\u3059\
    \u5229\u5F97\u3068\u6255\u3046\u30DA\u30CA\u304C\u91E3\u308A\u5408\u3063\u3066\
    \u3044\u308B\u306E\u3067k\u56DE\u5206\u30C1\u30E3\u30E9\u306B\u3059\u308B\u3060\
    \u3051\u3067\u3088\u3044\n    int ret=ans.first+pena*k;\n    return ret;\n}\n\n\
    /*\n\u5E45l\u306E\u6587\u5B57\u5168\u3066\u3092\u5927\u6587\u5B57\u3078\uFF0C\u5C0F\
    \u6587\u5B57\u3078\uFF0C\u304C\u3067\u304D\u308B\nmin(\u5927\u6587\u5B57\u306E\
    \u6570\uFF0C\u5C0F\u6587\u5B57\u306E\u6570)\u306E\u6700\u5C0F\u5316\n*/\nvoid\
    \ ECR79F(){\n    int n,k,l;cin>>n>>k>>l;\n    string s;cin>>s;\n    vector<int>\
    \ v(n);\n    rep(i,n) v[i]=('a'<=s[i] and s[i]<='z');\n\n    int res=INF;\n  \
    \  chmin(res,n-solve(v,l,k));\n    for(auto &x:v) x^=1;\n    chmin(res,n-solve(v,l,k));\n\
    \    cout<<res<<endl;\n}\n"
  code: "// PROBLEM : https://codeforces.com/contest/1279/problem/F\n// SUBMIT  :\
    \ https://codeforces.com/contest/1279/submission/105194010\n\n// v\u306F0 or 1\n\
    // \u5E45l\u3092\u5168\u30661\u306B\u3067\u304D\u308B\uFF0E\u3068\u3044\u3046\u64CD\
    \u4F5C\u3092k\u56DE\u307E\u3067\u884C\u3048\u308B\uFF0E\n// 1\u306E\u6570\u3092\
    \u6700\u5927\u5316\u3059\u308B\uFF0E\nint solve(vector<int> v,int l,int k){\n\
    \    using P=pair<int,int>;\n\n    int n=(int)v.size();\n\n    // 1\u306E\u6570\
    \u306E\u6700\u5927\u5316, \u64CD\u4F5C1\u56DE\u3067\u30DA\u30CA\n    auto f=[&](int\
    \ pena){\n        vector<P> dp(n+1,P(-INF,0));\n        dp[0]=P(0,0);\n      \
    \  rep(i,n){\n            int nxt=min(i+l,n);\n            chmax(dp[nxt],P(dp[i].first+(nxt-i)-pena,dp[i].second+1));\n\
    \            chmax(dp[i+1],P(dp[i].first+v[i],dp[i].second));\n        }\n   \
    \     return dp[n];\n    };\n\n    // \u64CD\u4F5Ck\u56DE\u4EE5\u4E0A\uFF0C\u6700\
    \u5C0F\n    int lw=0,hi=n+2,pena=0;\n    while(lw<=hi){\n        int m=(lw+hi)/2;\n\
    \        P x=f(m);\n        if(x.second>=k){\n            pena=m;\n          \
    \  lw=m+1;\n        }else{\n            hi=m-1;\n        }\n    }\n\n    auto\
    \ ans=f(pena);\n    // k\u500B\u307E\u3067\u306Fok\u306A\u306E\u3067\u30DA\u30CA\
    \u3092\u5E33\u6D88\u3057\n    // \u3053\u306E\u6642\uFF0Cdp\u3067\u306Fk\u56DE\
    \u4EE5\u4E0A\u3072\u3063\u304F\u308A\u8FD4\u3057\u3066\u3044\u308B\u304B\u3082\
    \u3057\u308C\u306A\u3044\u304C\uFF0C\n    // \u3072\u3063\u304F\u308A\u8FD4\u3059\
    \u5229\u5F97\u3068\u6255\u3046\u30DA\u30CA\u304C\u91E3\u308A\u5408\u3063\u3066\
    \u3044\u308B\u306E\u3067k\u56DE\u5206\u30C1\u30E3\u30E9\u306B\u3059\u308B\u3060\
    \u3051\u3067\u3088\u3044\n    int ret=ans.first+pena*k;\n    return ret;\n}\n\n\
    /*\n\u5E45l\u306E\u6587\u5B57\u5168\u3066\u3092\u5927\u6587\u5B57\u3078\uFF0C\u5C0F\
    \u6587\u5B57\u3078\uFF0C\u304C\u3067\u304D\u308B\nmin(\u5927\u6587\u5B57\u306E\
    \u6570\uFF0C\u5C0F\u6587\u5B57\u306E\u6570)\u306E\u6700\u5C0F\u5316\n*/\nvoid\
    \ ECR79F(){\n    int n,k,l;cin>>n>>k>>l;\n    string s;cin>>s;\n    vector<int>\
    \ v(n);\n    rep(i,n) v[i]=('a'<=s[i] and s[i]<='z');\n\n    int res=INF;\n  \
    \  chmin(res,n-solve(v,l,k));\n    for(auto &x:v) x^=1;\n    chmin(res,n-solve(v,l,k));\n\
    \    cout<<res<<endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: tips/AlienDP.cpp
  requiredBy: []
  timestamp: '2021-01-24 13:24:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tips/AlienDP.cpp
layout: document
redirect_from:
- /library/tips/AlienDP.cpp
- /library/tips/AlienDP.cpp.html
title: tips/AlienDP.cpp
---

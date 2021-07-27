---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/LongestCommonSubsequence.cpp
    title: "Longest Common Subsequence (\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\
      )"
  - icon: ':question:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
  bundledCode: "#line 1 \"test/AOJ_ALDS1_10_c.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n\n#line 1 \"template.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int i=0;i<(n);i++)\n#define\
    \ debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n#define mod\
    \ 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\n\
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \nstruct IOSetup{\n    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n\
    \        cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/AOJ_ALDS1_10_c.test.cpp\"\n\n#line 1 \"DP/LongestCommonSubsequence.cpp\"\
    \ntemplate<typename S>\nS LongestCommonSubsequence(S a,S b){\n    int n=(int)a.size(),m=(int)b.size();\n\
    \    vector<vector<int>> dp(n+1,vector<int>(m+1,0)),pre(n+1,vector<int>(m+1,-1));\n\
    \    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++){\n        if(i<n and j<m and a[i]==b[j]){\n\
    \            if(chmax(dp[i+1][j+1],dp[i][j]+1)) pre[i+1][j+1]=1;\n        }\n\
    \        if(i<n)if(chmax(dp[i+1][j],dp[i][j])) pre[i+1][j]=2;\n        if(j<m)if(chmax(dp[i][j+1],dp[i][j]))\
    \ pre[i][j+1]=3;\n    }\n\n    S ret;\n    int i=n,j=m;\n    while(i and j and\
    \ pre[i][j]>0){\n        if(pre[i][j]==1){\n            i--,j--;\n           \
    \ ret.push_back(a[i]);\n        }\n        else if(pre[i][j]==2) i--;\n      \
    \  else if(pre[i][j]==3) j--;\n    }\n\n    reverse(begin(ret),end(ret));\n  \
    \  return ret;\n}\n#line 6 \"test/AOJ_ALDS1_10_c.test.cpp\"\n\nvoid solve(){\n\
    \    string a,b;cin>>a>>b;\n    auto res=LongestCommonSubsequence(a,b);\n    //\
    \ cout<<res<<endl;\n    cout<<res.size()<<endl;\n}\n\nsigned main(){\n    int\
    \ q;cin>>q;\n    while(q--) solve();\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n\n#include \"../template.cpp\"\n\n#include \"../DP/LongestCommonSubsequence.cpp\"\
    \n\nvoid solve(){\n    string a,b;cin>>a>>b;\n    auto res=LongestCommonSubsequence(a,b);\n\
    \    // cout<<res<<endl;\n    cout<<res.size()<<endl;\n}\n\nsigned main(){\n \
    \   int q;cin>>q;\n    while(q--) solve();\n    return 0;\n}\n"
  dependsOn:
  - template.cpp
  - DP/LongestCommonSubsequence.cpp
  isVerificationFile: true
  path: test/AOJ_ALDS1_10_c.test.cpp
  requiredBy: []
  timestamp: '2021-03-28 16:19:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ_ALDS1_10_c.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_ALDS1_10_c.test.cpp
- /verify/test/AOJ_ALDS1_10_c.test.cpp.html
title: test/AOJ_ALDS1_10_c.test.cpp
---

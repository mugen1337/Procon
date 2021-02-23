---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/InversionNumber.cpp
    title: DP/InversionNumber.cpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"test/AOJ_ALDS1_5_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
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
    \   return is;\n}\n\n#line 4 \"test/AOJ_ALDS1_5_D.test.cpp\"\n\n#line 1 \"DP/InversionNumber.cpp\"\
    \ntemplate<typename T>\nlong long InversionNumber(vector<T> v){\n    vector<T>\
    \ ord=v;\n    sort(begin(ord),end(ord));\n    ord.erase(unique(begin(ord),end(ord)),end(ord));\n\
    \    vector<long long> bit(ord.size()+1,0);\n    long long ret=0;\n    for(int\
    \ i=0;i<(int)v.size();i++){\n        int p=lower_bound(begin(ord),end(ord),v[i])-begin(ord)+1;\n\
    \        for(int j=p;j;j-=(j&-j)) ret-=bit[j];\n        for(int j=p;j<=(int)ord.size();j+=(j&-j))\
    \ bit[j]+=1;\n        ret+=i;\n    } \n    return ret;\n}\n#line 6 \"test/AOJ_ALDS1_5_D.test.cpp\"\
    \n\nsigned main(){\n    int n;cin>>n;\n    vector<int> a(n);\n    cin>>a;\n  \
    \  cout<<InversionNumber(a)<<endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include \"../template.cpp\"\n\n#include \"../DP/InversionNumber.cpp\"\n\n\
    signed main(){\n    int n;cin>>n;\n    vector<int> a(n);\n    cin>>a;\n    cout<<InversionNumber(a)<<endl;\n\
    \    return 0;\n}\n"
  dependsOn:
  - template.cpp
  - DP/InversionNumber.cpp
  isVerificationFile: true
  path: test/AOJ_ALDS1_5_D.test.cpp
  requiredBy: []
  timestamp: '2021-02-01 03:28:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ_ALDS1_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_ALDS1_5_D.test.cpp
- /verify/test/AOJ_ALDS1_5_D.test.cpp.html
title: test/AOJ_ALDS1_5_D.test.cpp
---

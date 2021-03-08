---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/LargestRectangle.cpp
    title: DP/LargestRectangle.cpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=ja
  bundledCode: "#line 1 \"test/AOJ_DPL_3_c.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=ja\"\
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
    \   return is;\n}\n\n#line 4 \"test/AOJ_DPL_3_c.test.cpp\"\n\n#line 1 \"DP/LargestRectangle.cpp\"\
    \ntemplate<typename INT>\nINT LargestRectangle(vector<INT> v){\n    int n=(int)v.size();\n\
    \    INT inf=numeric_limits<INT>::max()/2;\n    stack<pair<INT,INT>> st;\n   \
    \ st.emplace(-inf,-1);// \u3070\u3093\u307A\u3044\u3093\n    INT ret=0;\n    for(int\
    \ i=0;i<n;i++){\n        while(v[i]<st.top().first){\n            auto p=st.top();st.pop();\n\
    \            ret=max(ret,(i-st.top().second-1)*p.first);\n        }\n        st.emplace(v[i],i);\n\
    \    }\n    while(!st.empty()){\n        auto p=st.top();st.pop();\n        if(p.first==-inf)\
    \ continue;\n        ret=max(ret,(n-st.top().second-1)*p.first);\n    }\n    return\
    \ ret;\n}\n#line 6 \"test/AOJ_DPL_3_c.test.cpp\"\n\nsigned main(){\n    int n;cin>>n;\n\
    \    vector<ll> v(n);\n    cin>>v;\n    cout<<LargestRectangle(v)<<endl;\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=ja\"\
    \n\n#include \"../template.cpp\"\n\n#include \"../DP/LargestRectangle.cpp\"\n\n\
    signed main(){\n    int n;cin>>n;\n    vector<ll> v(n);\n    cin>>v;\n    cout<<LargestRectangle(v)<<endl;\n\
    \    return 0;\n}\n"
  dependsOn:
  - template.cpp
  - DP/LargestRectangle.cpp
  isVerificationFile: true
  path: test/AOJ_DPL_3_c.test.cpp
  requiredBy: []
  timestamp: '2021-01-24 02:17:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ_DPL_3_c.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_DPL_3_c.test.cpp
- /verify/test/AOJ_DPL_3_c.test.cpp.html
title: test/AOJ_DPL_3_c.test.cpp
---

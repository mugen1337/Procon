---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Other/Dice.hpp
    title: Other/Dice.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_C
  bundledCode: "#line 1 \"test/AOJ_ITP_Dice_III.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_C\"\
    \n\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
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
    \   return is;\n}\n\n#line 4 \"test/AOJ_ITP_Dice_III.test.cpp\"\n\n#line 1 \"\
    Other/Dice.hpp\"\ntemplate<typename T>\nstruct Dice{\n    //left, right, front,\
    \ back, down, up\n    T l,r,f,b,d,u;\n\n    void RollF(){ // y-- (next, d <- f)\n\
    \        int tmp=d; d=f; f=u; u=b; b=tmp;\n    }\n\n    void RollB(){ // y++ (next,\
    \ d <- b)\n        int tmp=d; d=b; b=u; u=f; f=tmp;\n    }\n\n    void RollL(){\
    \ // x-- (next, d <- l)\n        int tmp=d; d=l; l=u; u=r; r=tmp;\n    }\n\n \
    \   void RollR(){ // x++ (next, d <- r)\n        int tmp=d; d=r; r=u; u=l; l=tmp;\n\
    \    }\n};\n\ntemplate<typename T>\nbool same_dice_same_state(Dice<T> a,Dice<T>\
    \ b){\n    return (a.b==b.b and a.f==b.f and a.l==b.l and a.r==b.r and a.u==b.u\
    \ and a.d==b.d);\n}\n\ntemplate<typename T>\nbool same_dice(Dice<T> a,Dice<T>\
    \ b){\n    for(int i=0;i<4;i++){\n        a.RollL();\n        for(int j=0;j<4;j++){\n\
    \            a.RollB();\n            for(int k=0;k<4;k++){\n                a.RollL();\n\
    \                if(same_dice_same_state(a,b)) return true;\n            }\n \
    \       }\n    }\n    return false;\n}\n#line 6 \"test/AOJ_ITP_Dice_III.test.cpp\"\
    \n\nsigned main(){\n    Dice<int> A,B;\n    cin>>A.u>>A.f>>A.r>>A.l>>A.b>>A.d;\n\
    \    cin>>B.u>>B.f>>B.r>>B.l>>B.b>>B.d;\n    cout<<(same_dice(A,B)?\"Yes\":\"\
    No\")<<endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_C\"\
    \n\n#include \"../template.hpp\"\n\n#include \"../Other/Dice.hpp\"\n\nsigned main(){\n\
    \    Dice<int> A,B;\n    cin>>A.u>>A.f>>A.r>>A.l>>A.b>>A.d;\n    cin>>B.u>>B.f>>B.r>>B.l>>B.b>>B.d;\n\
    \    cout<<(same_dice(A,B)?\"Yes\":\"No\")<<endl;\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - Other/Dice.hpp
  isVerificationFile: true
  path: test/AOJ_ITP_Dice_III.test.cpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ_ITP_Dice_III.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_ITP_Dice_III.test.cpp
- /verify/test/AOJ_ITP_Dice_III.test.cpp.html
title: test/AOJ_ITP_Dice_III.test.cpp
---

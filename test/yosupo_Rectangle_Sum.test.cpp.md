---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RangeTree.cpp
    title: DataStructure/RangeTree.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/yosupo_Rectangle_Sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#line 1 \"template.cpp\"\n\
    #include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
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
    \   return is;\n}\n\n#line 4 \"test/yosupo_Rectangle_Sum.test.cpp\"\n\n#line 1\
    \ \"DataStructure/RangeTree.cpp\"\n// Range Tree (Weighted)\ntemplate<typename\
    \ Tx,typename Ty,typename VAL=int>\nstruct RangeTree{\n    private:\n    vector<vector<Ty>>\
    \ seg;\n    vector<vector<VAL>> sum;\n    vector<Tx> x;\n    int sz;\n\n    void\
    \ build(vector<tuple<Tx,Ty,VAL>> &v){\n        sort(begin(v),end(v));\n      \
    \  for(int i=0;i<(int)v.size();i++) x.push_back(get<0>(v[i]));\n        x.erase(unique(begin(x),end(x)),end(x));\n\
    \        sz=1;\n        while((int)x.size()>sz) sz<<=1;\n        while((int)x.size()<sz)\
    \ x.push_back(numeric_limits<Tx>::max()/2);\n        seg.resize(sz*2);\n     \
    \   sum.resize(sz*2);\n        int idx=0;\n        for(auto [x_,y_,val]:v){\n\
    \            if(x[idx]!=x_) idx++;\n            seg[idx+sz].push_back(y_);\n \
    \           sum[idx+sz].push_back(val);\n        }\n        for(int i=sz-1;i>0;i--){\n\
    \            int l=0,r=0;\n            while(l<(int)seg[2*i].size() or r<(int)seg[2*i+1].size()){\n\
    \                bool f;\n                if(r>=(int)seg[2*i+1].size()) f=true;\n\
    \                else if(l>=(int)seg[2*i].size()) f=false;\n                else\
    \ if(seg[2*i][l]<seg[2*i+1][r]) f=true;\n                else f=false;\n     \
    \           if(f){\n                    seg[i].push_back(seg[2*i][l]);\n     \
    \               sum[i].push_back(sum[2*i][l]);\n                    l++;\n   \
    \             }else{\n                    seg[i].push_back(seg[2*i+1][r]);\n \
    \                   sum[i].push_back(sum[2*i+1][r]);\n                    r++;\n\
    \                }\n            }\n        }\n        for(int i=1;i<2*sz;i++){\n\
    \            vector<VAL> replace(1,0);\n            for(auto val:sum[i]) replace.push_back(replace.back()+val);\n\
    \            swap(sum[i],replace);\n        }\n    }\n    \n    public:\n    RangeTree(vector<pair<Tx,Ty>>\
    \ a){\n        vector<tuple<Tx,Ty,VAL>> v;\n        for(auto p:a) v.emplace_back(p.first,p.second,1);\n\
    \        build(v);\n    }\n    RangeTree(vector<tuple<Tx,Ty,VAL>> a){\n      \
    \  build(a);\n    }\n    // sum : [x1,x2),[y1,y2)\n    VAL query(Tx x1,Ty y1,Tx\
    \ x2,Ty y2){\n        int l=lower_bound(begin(x),end(x),x1)-begin(x),r=lower_bound(begin(x),end(x),x2)-begin(x);\n\
    \        l+=sz,r+=sz;\n        VAL ret=0;\n        for(;l<r;l>>=1,r>>=1){\n  \
    \          if(l&1){\n                int hi=lower_bound(begin(seg[l]),end(seg[l]),y2)-begin(seg[l]);\n\
    \                int lw=lower_bound(begin(seg[l]),end(seg[l]),y1)-begin(seg[l]);\n\
    \                ret+=sum[l][hi]-sum[l][lw];\n                l++;\n         \
    \   }\n            if(r&1){\n                r--;\n                int hi=lower_bound(begin(seg[r]),end(seg[r]),y2)-begin(seg[r]);\n\
    \                int lw=lower_bound(begin(seg[r]),end(seg[r]),y1)-begin(seg[r]);\n\
    \                ret+=sum[r][hi]-sum[r][lw];\n            }\n        }\n     \
    \   return ret;\n    }\n};\n#line 6 \"test/yosupo_Rectangle_Sum.test.cpp\"\n\n\
    signed main(){\n    int n,q;cin>>n>>q;\n    vector<tuple<int,int,ll>> v;\n   \
    \ rep(i,n){\n        int x,y;ll w;cin>>x>>y>>w;\n        v.emplace_back(x,y,w);\n\
    \    }\n\n    RangeTree<int,int,ll> seg(v);\n\n\n    while(q--){\n        int\
    \ x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;\n        cout<<seg.query(x1,y1,x2,y2)<<\"\\\
    n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../template.cpp\"\n\n#include \"../DataStructure/RangeTree.cpp\"\n\nsigned\
    \ main(){\n    int n,q;cin>>n>>q;\n    vector<tuple<int,int,ll>> v;\n    rep(i,n){\n\
    \        int x,y;ll w;cin>>x>>y>>w;\n        v.emplace_back(x,y,w);\n    }\n\n\
    \    RangeTree<int,int,ll> seg(v);\n\n\n    while(q--){\n        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;\n\
    \        cout<<seg.query(x1,y1,x2,y2)<<\"\\n\";\n    }\n\n    return 0;\n}"
  dependsOn:
  - template.cpp
  - DataStructure/RangeTree.cpp
  isVerificationFile: true
  path: test/yosupo_Rectangle_Sum.test.cpp
  requiredBy: []
  timestamp: '2021-01-12 16:43:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_Rectangle_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Rectangle_Sum.test.cpp
- /verify/test/yosupo_Rectangle_Sum.test.cpp.html
title: test/yosupo_Rectangle_Sum.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/Mo.hpp
    title: Algorithm/Mo.hpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree.hpp
    title: DataStructure/BinaryIndexedTree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo_Static_Range_Inversions_Query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\n\n\
    #line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ ALL(x) begin(x),end(x)\n#define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v)\
    \ cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\n\
    using ll=long long;\nconst int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\n\
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \nstruct IOSetup{\n    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n\
    \        cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/yosupo_Static_Range_Inversions_Query.test.cpp\"\
    \n\n#line 1 \"Algorithm/Mo.hpp\"\n/*\nrefs : https://beet-aizu.github.io/library/algorithm/mo.hpp\n\
    \       https://ei1333.github.io/library/other/mo.hpp\n*/\nstruct Mo{\n    using\
    \ F=function<void(int)>;\n    int n,idx,ql,qr;\n    vector<pair<int,int>> query;\n\
    \    vector<int> ord;\n    // [l,r) \n    // add_left  : l-1\u3092\u8DB3\u3059\
    , add_right : r\u3092\u8DB3\u3059\n    // erase_left: l\u3092\u6D88\u3059,  erase_right:\
    \ r-1\u3092\u6D88\u3059\n    F add_left,add_right,erase_left,erase_right;\n \n\
    \    Mo(int n,F add_left,F add_right,F erase_left,F erase_right):\n    n(n),idx(0),ql(0),qr(0),\n\
    \    add_left(add_left),add_right(add_right),erase_left(erase_left),erase_right(erase_right)\n\
    \    {}\n \n    void add(int l,int r){\n        query.emplace_back(l,r);\n   \
    \ }\n \n    void build(){\n        int q=(int)query.size();\n        int bs=n/min(n,int(sqrt(q)));\n\
    \        // \u5DE6\u7AEF\u306E\u30D6\u30ED\u30C3\u30AF\u3067\u30BD\u30FC\u30C8\
    \n        // \u5DE6\u7AEF\u306E\u30D6\u30ED\u30C3\u30AF\u304C\u540C\u3058\u306A\
    \u3089\u53F3\u7AEF\u3067\u30BD\u30FC\u30C8\n        ord.resize(q);\n        iota(begin(ord),end(ord),0);\n\
    \        sort(begin(ord),end(ord),[&](int a,int b){\n            int al=query[a].first/bs,bl=query[b].first/bs;\n\
    \            if(al!=bl) return al<bl;\n            // \u5076\u5947\u3067\u59CB\
    \u70B9\u3092\u5DE6\u53F3\u306B\u632F\u308B\u3068\u52D5\u304D\u306B\u7121\u99C4\
    \u304C\u306A\u3044\n            if(al&1) return query[a].second>query[b].second;\n\
    \            return query[a].second<query[b].second;\n        });\n    }\n \n\
    \    // 1\u500B\u30AF\u30A8\u30EA\u3092\u9032\u3081\uFF0C\u51E6\u7406\u3057\u305F\
    \u30AF\u30A8\u30EA\u306Eindex\u3092\u8FD4\u3059\n    // process\u304C\u7D42\u308F\
    \u3063\u3066\u304B\u3089\u7D50\u679C\u3092\u683C\u7D0D\u3059\u308B\u3053\u3068\
    \n    // ans[process()]=res; \u306F\u3067\u304D\u306A\u3044\n    int process(){\n\
    \        if(idx>=(int)ord.size()) return -1;\n        int cur=ord[idx++];\n  \
    \      while(ql>query[cur].first)  add_left(--ql);\n        while(qr<query[cur].second)\
    \ add_right(qr++);\n        while(ql<query[cur].first)  erase_left(ql++);\n  \
    \      while(qr>query[cur].second) erase_right(--qr);\n        return cur;\n \
    \   }\n};\n#line 6 \"test/yosupo_Static_Range_Inversions_Query.test.cpp\"\n\n\
    #line 1 \"DataStructure/BinaryIndexedTree.hpp\"\ntemplate<typename T>\nstruct\
    \ BinaryIndexedTree{\n    vector<T> data;\n    BinaryIndexedTree()=default;\n\
    \    BinaryIndexedTree(int sz):data(sz+1,0){}\n    BinaryIndexedTree(const vector<T>\
    \ &a):data(a.size()+1,0){\n        for(int i=0;i<(int)a.size();i++)data[i+1]=a[i];\n\
    \        for(int i=1;i<(int)data.size();i++){\n            int j=i+(i&-i);\n \
    \           if(j<(int)data.size()) data[j]+=data[i];\n        }\n    }\n    void\
    \ add(int k,const T &x){for(++k;k<(int)data.size();k+=(k&-k)) data[k]+=x;}\n \
    \   // sum [0,k)\n    T sum(int k){\n        T ret=T();\n        for(;k>0;k-=(k&-k))ret+=data[k];\n\
    \        return ret;\n    }\n    // sum [l,r)\n    T query(int l,int r){\n   \
    \     return sum(r)-sum(l);\n    }\n    T operator[](const int &k){return query(k,k+1);}\n\
    \    // sum[0,i)>=x\u3068\u306A\u308B\u6700\u5C0F\u306Ei\n    int lower_bound(T\
    \ x){\n        int r=1,i=0;\n        while(r<(int)data.size())r<<=1;\n       \
    \ for(;r>0;r>>=1)if(i+r<(int)data.size() and data[i+r]<x){\n            x-=data[i+r];i+=r;\n\
    \        }\n        return i+1;\n    }\n};\n#line 8 \"test/yosupo_Static_Range_Inversions_Query.test.cpp\"\
    \n\n\nsigned main(){\n    int n,q;cin>>n>>q;\n    vector<int> a(n);\n    cin>>a;\n\
    \n    auto comp=a;\n    sort(ALL(comp));\n    comp.erase(unique(ALL(comp)),end(comp));\n\
    \    rep(i,n) a[i]=lower_bound(ALL(comp),a[i])-begin(comp);\n\n    BinaryIndexedTree<ll>\
    \ seg(n+10);\n    \n    ll res=0;\n    auto add_left=[&](int x){\n        res+=seg.query(0,a[x]);\n\
    \        seg.add(a[x],1);\n    };\n    auto add_right=[&](int x){\n        res+=seg.query(a[x]+1,n+5);\n\
    \        seg.add(a[x],1);\n    };\n    auto erase_left=[&](int x){\n        res-=seg.query(0,a[x]);\n\
    \        seg.add(a[x],-1);\n    };\n    auto erase_right=[&](int x){\n       \
    \ res-=seg.query(a[x]+1,n+5);\n        seg.add(a[x],-1);\n    };\n\n    Mo mo(n,add_left,add_right,erase_left,erase_right);\n\
    \n    rep(i,q){\n        int l,r;cin>>l>>r;\n        mo.add(l,r);\n    }\n   \
    \ mo.build();\n\n    vector<ll> ans(q);\n    rep(i,q){\n        int j=mo.process();\n\
    \        ans[j]=res;\n    }\n\n    for(auto &x:ans) cout<<x<<\"\\n\";\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include \"../template.hpp\"\n\n#include \"../Algorithm/Mo.hpp\"\n\n#include\
    \ \"../DataStructure/BinaryIndexedTree.hpp\"\n\n\nsigned main(){\n    int n,q;cin>>n>>q;\n\
    \    vector<int> a(n);\n    cin>>a;\n\n    auto comp=a;\n    sort(ALL(comp));\n\
    \    comp.erase(unique(ALL(comp)),end(comp));\n    rep(i,n) a[i]=lower_bound(ALL(comp),a[i])-begin(comp);\n\
    \n    BinaryIndexedTree<ll> seg(n+10);\n    \n    ll res=0;\n    auto add_left=[&](int\
    \ x){\n        res+=seg.query(0,a[x]);\n        seg.add(a[x],1);\n    };\n   \
    \ auto add_right=[&](int x){\n        res+=seg.query(a[x]+1,n+5);\n        seg.add(a[x],1);\n\
    \    };\n    auto erase_left=[&](int x){\n        res-=seg.query(0,a[x]);\n  \
    \      seg.add(a[x],-1);\n    };\n    auto erase_right=[&](int x){\n        res-=seg.query(a[x]+1,n+5);\n\
    \        seg.add(a[x],-1);\n    };\n\n    Mo mo(n,add_left,add_right,erase_left,erase_right);\n\
    \n    rep(i,q){\n        int l,r;cin>>l>>r;\n        mo.add(l,r);\n    }\n   \
    \ mo.build();\n\n    vector<ll> ans(q);\n    rep(i,q){\n        int j=mo.process();\n\
    \        ans[j]=res;\n    }\n\n    for(auto &x:ans) cout<<x<<\"\\n\";\n    return\
    \ 0;\n}\n"
  dependsOn:
  - template.hpp
  - Algorithm/Mo.hpp
  - DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: test/yosupo_Static_Range_Inversions_Query.test.cpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_Static_Range_Inversions_Query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Static_Range_Inversions_Query.test.cpp
- /verify/test/yosupo_Static_Range_Inversions_Query.test.cpp.html
title: test/yosupo_Static_Range_Inversions_Query.test.cpp
---

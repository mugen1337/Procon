---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/BinaryTrieMonoid.hpp
    title: "Binary Trie Monoid (\u5FC5\u8981\u306A\u3068\u3053\u308D\u3060\u3051\u4F5C\
      \u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/AOJ_DSL_2_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
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
    \   return is;\n}\n\n#line 4 \"test/AOJ_DSL_2_A.test.cpp\"\n\n#line 1 \"DataStructure/BinaryTrieMonoid.hpp\"\
    \ntemplate<typename BitType,int MAXLOG,typename Monoid>\nstruct BinaryTrieMonoid{\n\
    \    private:\n    struct Node{\n        Node *nxt[2];\n        Monoid val;\n\
    \        Node(Monoid val):nxt{nullptr,nullptr},val(val){}\n    };\n\n    Node\
    \ *root;\n\n    using F=function<Monoid(Monoid,Monoid)>;\n    F f;\n    const\
    \ Monoid e;\n\n    Monoid query(BitType a,BitType b,Node *cur,BitType l,BitType\
    \ r,int dep,BitType xor_val){\n        if(a<=l and r<=b) return (cur?cur->val:e);\n\
    \        if(dep<0 or b<=l or r<=a or !cur) return e;\n        bool x0=(xor_val>>dep)&1;\n\
    \        Monoid L=query(a,b,cur->nxt[x0],l,(l+r)/2,dep-1,xor_val);\n        Monoid\
    \ R=query(a,b,cur->nxt[x0^1],(l+r)/2,r,dep-1,xor_val);\n        return f(L,R);\n\
    \    }\n    void update(Node *cur,Monoid x,BitType bit,int dep){\n        if(dep==-1){\n\
    \            cur->val=x;\n            return ;\n        }\n        bool go_to=(bit>>dep)&1;\n\
    \        if(!cur->nxt[go_to]) cur->nxt[go_to]=new Node(e);\n        update(cur->nxt[go_to],x,bit,dep-1);\n\
    \        cur->val=f(cur->nxt[0]?cur->nxt[0]->val:e,cur->nxt[1]?cur->nxt[1]->val:e);\n\
    \        return ;\n    }\n\n    public:\n    BinaryTrieMonoid(F f,const Monoid\
    \ &e):root(new Node(e)),f(f),e(e){}\n\n    // fold [l,r)\n    // xor_val\u3092\
    \u6307\u5B9A\u3057\u305F\u3068\u304D\uFF0C\u53EF\u63DB\u3058\u3083\u306A\u3044\
    \u6F14\u7B97\u3060\u3068\u58CA\u308C\u308B\u3068\u601D\u3044\u307E\u3059\uFF0E\
    \u591A\u5206\n    Monoid query(BitType l,BitType r,BitType xor_val=0){\n     \
    \   return query(l,r,root,0,BitType(1)<<MAXLOG,MAXLOG-1,xor_val);\n    }\n   \
    \ void update(BitType bit,Monoid x){\n        update(root,x,bit,MAXLOG-1);\n \
    \   }\n    Monoid operator[](const BitType &k){\n        return query(k,k+1);\n\
    \    }\n};\n#line 6 \"test/AOJ_DSL_2_A.test.cpp\"\n\nsigned main(){\n    int n,q;cin>>n>>q;\n\
    \    BinaryTrieMonoid<int,18,ll> trie([&](ll a,ll b){return (a<b?a:b);},(1ll<<31)-1);\n\
    \    while(q--){\n        int c;ll x,y;cin>>c>>x>>y;\n        if(c==0) trie.update(x,y);\n\
    \        if(c==1) cout<<trie.query(x,y+1)<<endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include \"../template.hpp\"\n\n#include \"../DataStructure/BinaryTrieMonoid.hpp\"\
    \n\nsigned main(){\n    int n,q;cin>>n>>q;\n    BinaryTrieMonoid<int,18,ll> trie([&](ll\
    \ a,ll b){return (a<b?a:b);},(1ll<<31)-1);\n    while(q--){\n        int c;ll\
    \ x,y;cin>>c>>x>>y;\n        if(c==0) trie.update(x,y);\n        if(c==1) cout<<trie.query(x,y+1)<<endl;\n\
    \    }\n\n    return 0;\n}\n"
  dependsOn:
  - template.hpp
  - DataStructure/BinaryTrieMonoid.hpp
  isVerificationFile: true
  path: test/AOJ_DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2024-05-17 14:55:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ_DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_DSL_2_A.test.cpp
- /verify/test/AOJ_DSL_2_A.test.cpp.html
title: test/AOJ_DSL_2_A.test.cpp
---

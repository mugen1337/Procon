---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Heap/LeftistHeap.cpp
    title: Leftist Heap
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
  bundledCode: "#line 1 \"test/AOJ_ALDS1_9_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
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
    \   return is;\n}\n\n#line 4 \"test/AOJ_ALDS1_9_C.test.cpp\"\n\n#line 1 \"Heap/LeftistHeap.cpp\"\
    \ntemplate<typename T,bool less=true>\nstruct LeftistHeap{\n    struct Node{\n\
    \        Node *l,*r;\n        int s;\n        T val;\n        Node(T val):l(nullptr),r(nullptr),s(1),val(val){}\n\
    \    };\n    Node *root;\n    LeftistHeap(Node *t=nullptr):root(t){}\n\n    Node\
    \ *meld(Node *a,Node *b){\n        if(!a or !b) return (a?a:b);\n        if((a->val>b->val)^(!less))\
    \ swap(a,b);\n        a->r=meld(a->r,b);\n        if(!a->l or a->l->s<a->r->s)\
    \ swap(a->l,a->r);\n        a->s=(a->r?a->r->s:0)+1;\n        return a;\n    }\n\
    \    void meld(LeftistHeap b){\n        root=meld(root,b.root);\n    }\n    void\
    \ push(T x){\n        root=meld(root,new Node(x));\n    }\n    T pop(){\n    \
    \    assert(root!=nullptr);\n        T ret=root->val;\n        root=meld(root->l,root->r);\n\
    \        return ret;\n    }\n    T top(){\n        assert(root!=nullptr);\n  \
    \      return root->val;\n    }\n};\n#line 6 \"test/AOJ_ALDS1_9_C.test.cpp\"\n\
    \n\nsigned main(){\n    LeftistHeap<int,false> que;\n\n    string s;\n    while(cin>>s,s!=\"\
    end\"){\n        if(s==\"insert\"){\n            int x;cin>>x;\n            que.push(x);\n\
    \        }else{\n            cout<<que.pop()<<endl;\n        }\n    }\n    return\
    \ 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n\n#include \"../template.cpp\"\n\n#include \"../Heap/LeftistHeap.cpp\"\n\n\n\
    signed main(){\n    LeftistHeap<int,false> que;\n\n    string s;\n    while(cin>>s,s!=\"\
    end\"){\n        if(s==\"insert\"){\n            int x;cin>>x;\n            que.push(x);\n\
    \        }else{\n            cout<<que.pop()<<endl;\n        }\n    }\n    return\
    \ 0;\n}\n\n"
  dependsOn:
  - template.cpp
  - Heap/LeftistHeap.cpp
  isVerificationFile: true
  path: test/AOJ_ALDS1_9_C.test.cpp
  requiredBy: []
  timestamp: '2021-03-04 00:00:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ_ALDS1_9_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_ALDS1_9_C.test.cpp
- /verify/test/AOJ_ALDS1_9_C.test.cpp.html
title: test/AOJ_ALDS1_9_C.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/BinaryTrie.hpp
    title: Binary Trie
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/yosupo_Set_Xor_Min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
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
    \   return is;\n}\n\n#line 4 \"test/yosupo_Set_Xor_Min.test.cpp\"\n\n#line 1 \"\
    DataStructure/BinaryTrie.hpp\"\ntemplate<typename BitType,int MAXLOG,typename\
    \ C=int>\nstruct BinaryTrie{\n    private:\n    struct Node{\n        Node *nxt[2];\n\
    \        C cnt;\n        Node():nxt{nullptr,nullptr},cnt(0){}\n    };\n\n    Node\
    \ *root;\n\n    Node *find(BitType bit,BitType xor_val=0){\n        Node *cur=root;\n\
    \        for(int i=MAXLOG-1;i>=0;i--){\n            bool target=(xor_val>>i)&1;\n\
    \            bool go_to=target^((bit>>i)&1);\n            if(!cur->nxt[go_to])\
    \ return nullptr;\n            cur=cur->nxt[go_to];\n        }\n        return\
    \ cur;\n    }\n\n    public:\n    BinaryTrie():root(new Node()){}\n\n    void\
    \ add(BitType bit,C c=1,BitType xor_val=0){\n        Node *cur=root;\n       \
    \ for(int i=MAXLOG-1;i>=0;i--){\n            bool target=(xor_val>>i)&1;\n   \
    \         bool go_to=target^((bit>>i)&1);\n            if(!cur->nxt[go_to]) cur->nxt[go_to]=new\
    \ Node();\n            cur->cnt+=c;\n            cur=cur->nxt[go_to];\n      \
    \  }\n        cur->cnt+=c;\n        return ;\n    }\n    void erase(BitType bit,C\
    \ c=1,BitType xor_val=0){\n        add(bit,-c,xor_val);\n    }\n    BitType kth_element(C\
    \ k,BitType xor_val=0){\n        assert(0<=k and k<root->cnt);\n        C ret=0;\n\
    \        Node *cur=root;\n        for(int i=MAXLOG-1;i>=0;i--){\n            bool\
    \ xored_0=(xor_val>>i)&1;\n            if(!cur->nxt[xored_0] or  cur->nxt[xored_0]->cnt<=k){\n\
    \                k-=(cur->nxt[xored_0]?cur->nxt[xored_0]->cnt:0);\n          \
    \      cur=cur->nxt[xored_0^1];\n                ret+=(BitType(1)<<i);\n     \
    \       }else{\n                cur=cur->nxt[xored_0];\n            }\n      \
    \  }\n        return ret;\n    }\n    BitType min_element(BitType xor_val=0){\n\
    \        return kth_element(0,xor_val);\n    }\n    BitType max_element(BitType\
    \ xor_val=0){\n        return kth_element(root->cnt-1,xor_val);\n    }\n    C\
    \ count(BitType bit,BitType xor_val=0){\n        auto target=find(bit,xor_val);\n\
    \        return target?target->cnt:0;\n    }\n    C count_less(BitType bit,BitType\
    \ xor_val=0){\n        C ret=0;\n        Node *cur=root;\n        for(int i=MAXLOG-1;i>=0;i--){\n\
    \            if(!cur) break;\n            bool xored_0=(xor_val>>i)&1;\n     \
    \       if((bit>>i)&1 and cur->nxt[xored_0]) ret+=cur->nxt[xored_0]->cnt;\n  \
    \          cur=cur->nxt[xored_0^((bit>>i)&1)];\n        }\n        return ret;\n\
    \    }\n};\n#line 6 \"test/yosupo_Set_Xor_Min.test.cpp\"\n\nsigned main(){\n \
    \   BinaryTrie<int,31> trie;\n    int q;cin>>q;\n    while(q--){\n        int\
    \ t,x;cin>>t>>x;\n        if(t==0){\n            if(trie.count(x)==0) trie.add(x);\n\
    \        }else if(t==1){\n            if(trie.count(x)) trie.erase(x,1);\n   \
    \     }else{\n            cout<<trie.min_element(x)<<\"\\n\";\n        }\n   \
    \ }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../template.hpp\"\n\n#include \"../DataStructure/BinaryTrie.hpp\"\n\nsigned\
    \ main(){\n    BinaryTrie<int,31> trie;\n    int q;cin>>q;\n    while(q--){\n\
    \        int t,x;cin>>t>>x;\n        if(t==0){\n            if(trie.count(x)==0)\
    \ trie.add(x);\n        }else if(t==1){\n            if(trie.count(x)) trie.erase(x,1);\n\
    \        }else{\n            cout<<trie.min_element(x)<<\"\\n\";\n        }\n\
    \    }\n    return 0;\n}\n"
  dependsOn:
  - template.hpp
  - DataStructure/BinaryTrie.hpp
  isVerificationFile: true
  path: test/yosupo_Set_Xor_Min.test.cpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_Set_Xor_Min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Set_Xor_Min.test.cpp
- /verify/test/yosupo_Set_Xor_Min.test.cpp.html
title: test/yosupo_Set_Xor_Min.test.cpp
---

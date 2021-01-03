---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2292
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2292
  bundledCode: "#line 1 \"String/PalindromicTree.test.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int\
    \ i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n\
    #define mod 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst\
    \ ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll\
    \ gcd(ll a,ll b){return b?gcd(b,a%b):a;}\ntemplate<class T>bool chmax(T &a,const\
    \ T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool chmin(T\
    \ &a,const T &b){if(b<a){a=b;return true;}return false;}\n\n\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/2292\"\n\n\n// \u6587\u5B57\u7A2E\
    a\u306B\u5BFE\u3057\uFF0Cbuild O(na)\nstruct PalindromicTree{\n    struct node{\n\
    \        map<char,int> link;// link aba -> xabax\n        int len,cnt,idx;// idx:\u3053\
    \u306E\u56DE\u6587\u306E1\u3064\u306E\u5DE6\u7AEF, RH\u306A\u3069\u306E\u305F\u3081\
    \n        int suffix_link;\n        node(){}\n        node(int len,int cnt,int\
    \ idx,int suffix_link):len(len),cnt(cnt),idx(idx),suffix_link(suffix_link){}\n\
    \    };\n\n    vector<node> v;// 0:(-1), 1: (0)\n    int n,ptr;\n\n    PalindromicTree(){}\n\
    \    PalindromicTree(const string &s):v(2),n(2),ptr(1){\n        v[0]=node(-1,0,-1,0);v[1]=node(0,0,-1,0);\n\
    \        for(int i=0;i<(int)s.size();i++) process(s,i);\n        build_freq();\n\
    \    }\n\n    bool process(const string &s,int pos){\n        int cur=ptr;// link\
    \ parent\n        while(true){\n            int rev=pos-v[cur].len-1;\n      \
    \      if(rev>=0 and s[rev]==s[pos]) break;\n            cur=v[cur].suffix_link;\n\
    \        }\n        if(v[cur].link.count(s[pos])){\n            ptr=v[cur].link[s[pos]];\n\
    \            v[ptr].cnt++;\n            return false;\n        }\n        ptr=n++;\n\
    \n        v.emplace_back(v[cur].len+2,1,pos-v[cur].len-1,-1);\n        v[cur].link[s[pos]]=ptr;//\
    \ link\n        if(v[ptr].len==1){\n            v[ptr].suffix_link=1;\n      \
    \      return true;\n        }\n\n        while(true){\n            cur=v[cur].suffix_link;\n\
    \            int rev=pos-v[cur].len-1;\n            if(rev>=0 and s[rev]==s[pos]){\n\
    \                v[ptr].suffix_link=v[cur].link[s[pos]];\n                break;\n\
    \            }\n        }\n        return true;\n    }\n    // DAG\u3092\u30C8\
    \u30DD\u30BD\n    vector<int> calc_ord(){\n        vector<int> ret;\n        ret.emplace_back(0);\n\
    \        ret.emplace_back(1);\n        for(int i=0;i<(int)ret.size();i++)for(auto\
    \ &p:v[ret[i]].link) ret.emplace_back(p.second);\n        return ret;\n    }\n\
    \    void build_freq(){\n        auto ord=calc_ord();\n        // \u4E00\u756A\
    \u9577\u3044\u56DE\u6587\u306B\u3057\u304Bcnt+=1\u3092\u3057\u3066\u3044\u306A\
    \u3044\u306E\u3067\uFF0Clink\u3067\u96C6\u7D04\u3059\u308B\n        for(int i=(int)ord.size()-1;i>=0;i--)\
    \ v[v[ord[i]].suffix_link].cnt+=v[ord[i]].cnt;\n    }\n    int count_unique(){return\
    \ n-2;}\n    int size(){return n;}\n    node operator[](const int &k){return v[k];}\n\
    };\n\n\n// hash type\nusing ull=unsigned long long;\nstruct RollingHash{\n   \
    \ using ull=unsigned long long;\n    using uint128=__uint128_t;\n    static const\
    \ ull MOD=(1ull<<61ull)-1;\n    vector<ull>hashed,power;\n    const ull base;\n\
    \ \n    static inline ull add(ull a,ull b){if((a+=b)>=MOD)a-=MOD;return a;}\n\
    \    static inline ull mul(ull a,ull b){uint128 c=(uint128)a*b;return add(c>>61,c&MOD);}\n\
    \    static inline ull generate_base(){\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<ull>rand(1,RollingHash::MOD-1);\n        return\
    \ rand(mt);\n    }\n    RollingHash()=default;\n    RollingHash(const string &s,ull\
    \ base):base(base){\n        int sz=(int)s.size();\n        hashed.assign(sz+1,0);\n\
    \        power.assign(sz+1,0);\n        power[0]=1;\n        for(int i=0;i<sz;i++){\n\
    \            power[i+1]=mul(power[i],base);\n            hashed[i+1]=add(mul(hashed[i],base),s[i]);\n\
    \        }\n    }\n    template<typename T>\n    RollingHash(const vector<T>&s,ull\
    \ base):base(base){\n        int sz=(int)s.size();\n        hashed.assign(sz+1,0);\n\
    \        power.assign(sz+1,0);\n        power[0]=1;\n        for(int i=0;i<sz;i++){\n\
    \            power[i+1]=mul(power[i],base);\n            hashed[i+1]=add(mul(hashed[i],base),s[i]);\n\
    \        }\n    }\n    // hash[l,r)\n    ull get(int l,int r)const{\n        return\
    \ add(hashed[r],MOD-mul(hashed[l],power[r-l]));\n    }\n    ull concat(ull hash1,ull\
    \ hash2,int hash2len)const{\n        return add(mul(hash1,power[hash2len]),hash2);\n\
    \    }\n    int lcp(const RollingHash &b,int l1,int r1,int l2,int r2)const{\n\
    \        assert(b.base==base);\n        int len=min(r1-l1,r2-l2);\n        int\
    \ lw=0,hi=len+1;\n        while(hi-lw>1){\n            int mid=(lw+hi)/2;\n  \
    \          if(get(l1,l1+mid)==b.get(l2,l2+mid))lw=mid;\n            else hi=mid;\n\
    \        }\n        return lw;\n    }\n};\n\n\nsigned main(){\n    string s,t;cin>>s>>t;\n\
    \n    PalindromicTree pts(s),ptt(t);\n    ull base=RollingHash::generate_base();\n\
    \    RollingHash rhs(s,base),rht(t,base);\n    map<ull,ll> cnt;\n    for(int i=2;i<pts.size();i++){\n\
    \        cnt[rhs.get(pts[i].idx,pts[i].idx+pts[i].len)]+=pts[i].cnt;\n    }\n\
    \    ll res=0;\n    for(int i=2;i<ptt.size();i++){\n        ull hash=rht.get(ptt[i].idx,ptt[i].idx+ptt[i].len);\n\
    \        if(cnt.count(hash)) res+=ptt[i].cnt*cnt[hash];\n    }\n    cout<<res<<endl;\n\
    \    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto\
    \ x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\nusing ll=long long;\n\
    const int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n\
    // ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\ntemplate<class T>bool chmax(T &a,const\
    \ T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool chmin(T\
    \ &a,const T &b){if(b<a){a=b;return true;}return false;}\n\n\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/2292\"\n\n\n// \u6587\u5B57\u7A2E\
    a\u306B\u5BFE\u3057\uFF0Cbuild O(na)\nstruct PalindromicTree{\n    struct node{\n\
    \        map<char,int> link;// link aba -> xabax\n        int len,cnt,idx;// idx:\u3053\
    \u306E\u56DE\u6587\u306E1\u3064\u306E\u5DE6\u7AEF, RH\u306A\u3069\u306E\u305F\u3081\
    \n        int suffix_link;\n        node(){}\n        node(int len,int cnt,int\
    \ idx,int suffix_link):len(len),cnt(cnt),idx(idx),suffix_link(suffix_link){}\n\
    \    };\n\n    vector<node> v;// 0:(-1), 1: (0)\n    int n,ptr;\n\n    PalindromicTree(){}\n\
    \    PalindromicTree(const string &s):v(2),n(2),ptr(1){\n        v[0]=node(-1,0,-1,0);v[1]=node(0,0,-1,0);\n\
    \        for(int i=0;i<(int)s.size();i++) process(s,i);\n        build_freq();\n\
    \    }\n\n    bool process(const string &s,int pos){\n        int cur=ptr;// link\
    \ parent\n        while(true){\n            int rev=pos-v[cur].len-1;\n      \
    \      if(rev>=0 and s[rev]==s[pos]) break;\n            cur=v[cur].suffix_link;\n\
    \        }\n        if(v[cur].link.count(s[pos])){\n            ptr=v[cur].link[s[pos]];\n\
    \            v[ptr].cnt++;\n            return false;\n        }\n        ptr=n++;\n\
    \n        v.emplace_back(v[cur].len+2,1,pos-v[cur].len-1,-1);\n        v[cur].link[s[pos]]=ptr;//\
    \ link\n        if(v[ptr].len==1){\n            v[ptr].suffix_link=1;\n      \
    \      return true;\n        }\n\n        while(true){\n            cur=v[cur].suffix_link;\n\
    \            int rev=pos-v[cur].len-1;\n            if(rev>=0 and s[rev]==s[pos]){\n\
    \                v[ptr].suffix_link=v[cur].link[s[pos]];\n                break;\n\
    \            }\n        }\n        return true;\n    }\n    // DAG\u3092\u30C8\
    \u30DD\u30BD\n    vector<int> calc_ord(){\n        vector<int> ret;\n        ret.emplace_back(0);\n\
    \        ret.emplace_back(1);\n        for(int i=0;i<(int)ret.size();i++)for(auto\
    \ &p:v[ret[i]].link) ret.emplace_back(p.second);\n        return ret;\n    }\n\
    \    void build_freq(){\n        auto ord=calc_ord();\n        // \u4E00\u756A\
    \u9577\u3044\u56DE\u6587\u306B\u3057\u304Bcnt+=1\u3092\u3057\u3066\u3044\u306A\
    \u3044\u306E\u3067\uFF0Clink\u3067\u96C6\u7D04\u3059\u308B\n        for(int i=(int)ord.size()-1;i>=0;i--)\
    \ v[v[ord[i]].suffix_link].cnt+=v[ord[i]].cnt;\n    }\n    int count_unique(){return\
    \ n-2;}\n    int size(){return n;}\n    node operator[](const int &k){return v[k];}\n\
    };\n\n\n// hash type\nusing ull=unsigned long long;\nstruct RollingHash{\n   \
    \ using ull=unsigned long long;\n    using uint128=__uint128_t;\n    static const\
    \ ull MOD=(1ull<<61ull)-1;\n    vector<ull>hashed,power;\n    const ull base;\n\
    \ \n    static inline ull add(ull a,ull b){if((a+=b)>=MOD)a-=MOD;return a;}\n\
    \    static inline ull mul(ull a,ull b){uint128 c=(uint128)a*b;return add(c>>61,c&MOD);}\n\
    \    static inline ull generate_base(){\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<ull>rand(1,RollingHash::MOD-1);\n        return\
    \ rand(mt);\n    }\n    RollingHash()=default;\n    RollingHash(const string &s,ull\
    \ base):base(base){\n        int sz=(int)s.size();\n        hashed.assign(sz+1,0);\n\
    \        power.assign(sz+1,0);\n        power[0]=1;\n        for(int i=0;i<sz;i++){\n\
    \            power[i+1]=mul(power[i],base);\n            hashed[i+1]=add(mul(hashed[i],base),s[i]);\n\
    \        }\n    }\n    template<typename T>\n    RollingHash(const vector<T>&s,ull\
    \ base):base(base){\n        int sz=(int)s.size();\n        hashed.assign(sz+1,0);\n\
    \        power.assign(sz+1,0);\n        power[0]=1;\n        for(int i=0;i<sz;i++){\n\
    \            power[i+1]=mul(power[i],base);\n            hashed[i+1]=add(mul(hashed[i],base),s[i]);\n\
    \        }\n    }\n    // hash[l,r)\n    ull get(int l,int r)const{\n        return\
    \ add(hashed[r],MOD-mul(hashed[l],power[r-l]));\n    }\n    ull concat(ull hash1,ull\
    \ hash2,int hash2len)const{\n        return add(mul(hash1,power[hash2len]),hash2);\n\
    \    }\n    int lcp(const RollingHash &b,int l1,int r1,int l2,int r2)const{\n\
    \        assert(b.base==base);\n        int len=min(r1-l1,r2-l2);\n        int\
    \ lw=0,hi=len+1;\n        while(hi-lw>1){\n            int mid=(lw+hi)/2;\n  \
    \          if(get(l1,l1+mid)==b.get(l2,l2+mid))lw=mid;\n            else hi=mid;\n\
    \        }\n        return lw;\n    }\n};\n\n\nsigned main(){\n    string s,t;cin>>s>>t;\n\
    \n    PalindromicTree pts(s),ptt(t);\n    ull base=RollingHash::generate_base();\n\
    \    RollingHash rhs(s,base),rht(t,base);\n    map<ull,ll> cnt;\n    for(int i=2;i<pts.size();i++){\n\
    \        cnt[rhs.get(pts[i].idx,pts[i].idx+pts[i].len)]+=pts[i].cnt;\n    }\n\
    \    ll res=0;\n    for(int i=2;i<ptt.size();i++){\n        ull hash=rht.get(ptt[i].idx,ptt[i].idx+ptt[i].len);\n\
    \        if(cnt.count(hash)) res+=ptt[i].cnt*cnt[hash];\n    }\n    cout<<res<<endl;\n\
    \    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: String/PalindromicTree.test.cpp
  requiredBy: []
  timestamp: '2021-01-02 18:33:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: String/PalindromicTree.test.cpp
layout: document
redirect_from:
- /verify/String/PalindromicTree.test.cpp
- /verify/String/PalindromicTree.test.cpp.html
title: String/PalindromicTree.test.cpp
---
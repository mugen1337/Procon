---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ_2292.test.cpp
    title: test/AOJ_2292.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ_2863.test.cpp
    title: test/AOJ_2863.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/RollingHash.cpp\"\n// hash type\nusing ull=unsigned\
    \ long long;\nstruct RollingHash{\n    using ull=unsigned long long;\n    using\
    \ uint128=__uint128_t;\n    static const ull MOD=(1ull<<61ull)-1;\n    vector<ull>hashed,power;\n\
    \    const ull base;\n \n    static inline ull add(ull a,ull b){if((a+=b)>=MOD)a-=MOD;return\
    \ a;}\n    static inline ull mul(ull a,ull b){uint128 c=(uint128)a*b;return add(c>>61,c&MOD);}\n\
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
    \        }\n        return lw;\n    }\n};\n"
  code: "// hash type\nusing ull=unsigned long long;\nstruct RollingHash{\n    using\
    \ ull=unsigned long long;\n    using uint128=__uint128_t;\n    static const ull\
    \ MOD=(1ull<<61ull)-1;\n    vector<ull>hashed,power;\n    const ull base;\n \n\
    \    static inline ull add(ull a,ull b){if((a+=b)>=MOD)a-=MOD;return a;}\n   \
    \ static inline ull mul(ull a,ull b){uint128 c=(uint128)a*b;return add(c>>61,c&MOD);}\n\
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
    \        }\n        return lw;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: String/RollingHash.cpp
  requiredBy: []
  timestamp: '2021-01-04 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ_2863.test.cpp
  - test/AOJ_2292.test.cpp
documentation_of: String/RollingHash.cpp
layout: document
redirect_from:
- /library/String/RollingHash.cpp
- /library/String/RollingHash.cpp.html
title: String/RollingHash.cpp
---

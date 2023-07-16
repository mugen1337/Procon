---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki1601.test.cpp
    title: test/yuki1601.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/RangeSet.hpp\"\n// \u9589\u533A\u9593\u306E\
    \u7BC4\u56F2\u3092\u7BA1\u7406\ntemplate<typename T>\nstruct RangeSet{\n    set<pair<T,T>>\
    \ st;\n    T TINF;\n \n    RangeSet(){\n        TINF=numeric_limits<T>::max()/2;\n\
    \        st.emplace(TINF,TINF);\n        st.emplace(-TINF,-TINF);\n    }\n   \
    \ // [l,r] covered?\n    bool covered(T l,T r){\n        assert(l<=r);\n     \
    \   auto ite=prev(st.lower_bound({l+1,l+1}));\n        return ite->first<=l and\
    \ r<=ite->second;\n    }\n    bool covered(T x){\n        return covered(x,x);\n\
    \    }\n    // [l, r]\u304C\u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\u308B\u306A\
    \u3089\uFF0C\u305D\u306E\u533A\u9593\u3092\u8FD4\u3059. \u3055\u308C\u3066\u3044\
    \u306A\u3044\u306A\u3089[-TINF,-TINF]\u3092\u8FD4\u3059\n    pair<T,T> covered_by(T\
    \ l,T r){\n        assert(l<=r);\n        auto ite=prev(st.lower_bound({l+1,l+1}));\n\
    \        if(ite->first<=l and r<=ite->second) return *ite;\n        return make_pair(-TINF,-TINF);\n\
    \    }\n    pair<T,T> covered_by(T x){\n        return covered_by(x,x);\n    }\n\
    \    // insert[l,r], \u5897\u52A0\u91CF\u3092\u8FD4\u3059\n    T insert(T l,T\
    \ r){\n        assert(l<=r);\n        auto ite=prev(st.lower_bound({l+1,l+1}));\n\
    \        if(ite->first<=l and r<=ite->second) return T(0);\n        T sum_erased=T(0);\n\
    \        if(ite->first<=l and l<=ite->second+1){\n            l=ite->first;\n\
    \            sum_erased+=ite->second-ite->first+1;\n            ite=st.erase(ite);\n\
    \        }else ite=next(ite);\n        while(r>ite->second){\n            sum_erased+=ite->second-ite->first+1;\n\
    \            ite=st.erase(ite);\n        }\n        if(ite->first-1<=r and r<=ite->second){\n\
    \            sum_erased+=ite->second-ite->first+1;\n            r=ite->second;\n\
    \            st.erase(ite);\n        }\n        st.emplace(l,r);\n        return\
    \ r-l+1-sum_erased;\n    }\n    T insert(T x){\n        return insert(x,x);\n\
    \    }\n    // erase [l,r], \u6E1B\u5C11\u91CF\u3092\u8FD4\u3059\n    T erase(T\
    \ l,T r){\n        assert(l<=r);\n        auto ite=prev(st.lower_bound({l+1,l+1}));\n\
    \        if(ite->first<=l and r<=ite->second){\n            // \u5B8C\u5168\u306B\
    1\u3064\u306E\u533A\u9593\u306B\u5305\u542B\u3055\u308C\u3066\u3044\u308B\n  \
    \          if(ite->first<l)  st.emplace(ite->first,l-1);\n            if(r<ite->second)\
    \ st.emplace(r+1,ite->second);\n            st.erase(ite);\n            return\
    \ r-l+1;\n        }\n \n        T ret=T(0);\n        if(ite->first<=l and l<=ite->second){\n\
    \            ret+=ite->second-l+1;// \u6D88\u3048\u305F\n            if(ite->first<l)\
    \ st.emplace(ite->first,l-1);\n            ite=st.erase(ite);// \u6B21\u3078\n\
    \        }else ite=next(ite);\n        while(ite->second<=r){\n            ret+=ite->second-ite->first+1;\n\
    \            ite=st.erase(ite);\n        }\n        // \u53F3\u7AEF\u304C\u533A\
    \u9593\u306E\u9593\u306B\u3042\u308B\u304B\n        if(ite->first<=r and r<=ite->second){\n\
    \            ret+=r-ite->first+1;\n            if(r<ite->second) st.emplace(r+1,ite->second);\n\
    \            st.erase(ite);\n        }\n        return ret;\n    }\n    T erase(T\
    \ x){\n        return erase(x,x);\n    }\n    // number of range\n    int size(){\n\
    \        return (int)st.size()-2;\n    }\n    // mex [x,~)\n    T mex(T x=0){\n\
    \        auto ite=prev(st.lower_bound({x+1,x+1}));\n        if(ite->first<=x and\
    \ x<=ite->second) return ite->second+1;\n        else return x;\n    }\n    void\
    \ output(){\n        cout<<\"RangeSet : \";\n        for(auto &p:st){\n      \
    \      if(p.first==-TINF or p.second==TINF) continue;\n            cout<<\"[\"\
    <<p.first<<\", \"<<p.second<<\"] \";\n        }\n        cout<<\"\\n\";\n    }\n\
    };\n"
  code: "// \u9589\u533A\u9593\u306E\u7BC4\u56F2\u3092\u7BA1\u7406\ntemplate<typename\
    \ T>\nstruct RangeSet{\n    set<pair<T,T>> st;\n    T TINF;\n \n    RangeSet(){\n\
    \        TINF=numeric_limits<T>::max()/2;\n        st.emplace(TINF,TINF);\n  \
    \      st.emplace(-TINF,-TINF);\n    }\n    // [l,r] covered?\n    bool covered(T\
    \ l,T r){\n        assert(l<=r);\n        auto ite=prev(st.lower_bound({l+1,l+1}));\n\
    \        return ite->first<=l and r<=ite->second;\n    }\n    bool covered(T x){\n\
    \        return covered(x,x);\n    }\n    // [l, r]\u304C\u30AB\u30D0\u30FC\u3055\
    \u308C\u3066\u3044\u308B\u306A\u3089\uFF0C\u305D\u306E\u533A\u9593\u3092\u8FD4\
    \u3059. \u3055\u308C\u3066\u3044\u306A\u3044\u306A\u3089[-TINF,-TINF]\u3092\u8FD4\
    \u3059\n    pair<T,T> covered_by(T l,T r){\n        assert(l<=r);\n        auto\
    \ ite=prev(st.lower_bound({l+1,l+1}));\n        if(ite->first<=l and r<=ite->second)\
    \ return *ite;\n        return make_pair(-TINF,-TINF);\n    }\n    pair<T,T> covered_by(T\
    \ x){\n        return covered_by(x,x);\n    }\n    // insert[l,r], \u5897\u52A0\
    \u91CF\u3092\u8FD4\u3059\n    T insert(T l,T r){\n        assert(l<=r);\n    \
    \    auto ite=prev(st.lower_bound({l+1,l+1}));\n        if(ite->first<=l and r<=ite->second)\
    \ return T(0);\n        T sum_erased=T(0);\n        if(ite->first<=l and l<=ite->second+1){\n\
    \            l=ite->first;\n            sum_erased+=ite->second-ite->first+1;\n\
    \            ite=st.erase(ite);\n        }else ite=next(ite);\n        while(r>ite->second){\n\
    \            sum_erased+=ite->second-ite->first+1;\n            ite=st.erase(ite);\n\
    \        }\n        if(ite->first-1<=r and r<=ite->second){\n            sum_erased+=ite->second-ite->first+1;\n\
    \            r=ite->second;\n            st.erase(ite);\n        }\n        st.emplace(l,r);\n\
    \        return r-l+1-sum_erased;\n    }\n    T insert(T x){\n        return insert(x,x);\n\
    \    }\n    // erase [l,r], \u6E1B\u5C11\u91CF\u3092\u8FD4\u3059\n    T erase(T\
    \ l,T r){\n        assert(l<=r);\n        auto ite=prev(st.lower_bound({l+1,l+1}));\n\
    \        if(ite->first<=l and r<=ite->second){\n            // \u5B8C\u5168\u306B\
    1\u3064\u306E\u533A\u9593\u306B\u5305\u542B\u3055\u308C\u3066\u3044\u308B\n  \
    \          if(ite->first<l)  st.emplace(ite->first,l-1);\n            if(r<ite->second)\
    \ st.emplace(r+1,ite->second);\n            st.erase(ite);\n            return\
    \ r-l+1;\n        }\n \n        T ret=T(0);\n        if(ite->first<=l and l<=ite->second){\n\
    \            ret+=ite->second-l+1;// \u6D88\u3048\u305F\n            if(ite->first<l)\
    \ st.emplace(ite->first,l-1);\n            ite=st.erase(ite);// \u6B21\u3078\n\
    \        }else ite=next(ite);\n        while(ite->second<=r){\n            ret+=ite->second-ite->first+1;\n\
    \            ite=st.erase(ite);\n        }\n        // \u53F3\u7AEF\u304C\u533A\
    \u9593\u306E\u9593\u306B\u3042\u308B\u304B\n        if(ite->first<=r and r<=ite->second){\n\
    \            ret+=r-ite->first+1;\n            if(r<ite->second) st.emplace(r+1,ite->second);\n\
    \            st.erase(ite);\n        }\n        return ret;\n    }\n    T erase(T\
    \ x){\n        return erase(x,x);\n    }\n    // number of range\n    int size(){\n\
    \        return (int)st.size()-2;\n    }\n    // mex [x,~)\n    T mex(T x=0){\n\
    \        auto ite=prev(st.lower_bound({x+1,x+1}));\n        if(ite->first<=x and\
    \ x<=ite->second) return ite->second+1;\n        else return x;\n    }\n    void\
    \ output(){\n        cout<<\"RangeSet : \";\n        for(auto &p:st){\n      \
    \      if(p.first==-TINF or p.second==TINF) continue;\n            cout<<\"[\"\
    <<p.first<<\", \"<<p.second<<\"] \";\n        }\n        cout<<\"\\n\";\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RangeSet.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki1601.test.cpp
documentation_of: DataStructure/RangeSet.hpp
layout: document
title: "\u533A\u9593\u3092\u30BB\u30C3\u30C8\u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
---

## 概要  
https://mugen1337.hatenablog.com/entry/2020/10/14/134022  

## なんか  
int, ll以外の使用を想定していない．  

## できること  
全ての操作が存在している区間数をnとしてO(logn)．(一部ならしでO(logn))
- covered -- 与えた区間か点がカバーされているかどうか  
- covered_by -- 与えた区間か点がカバーされているならカバーされている区間を返す  
- insert -- 区間，点をinsertする．区間の増加量を返す．  
- erase -- 区間，点をeraseする．区間の減少量を返す  
- size -- 区間の数を返す  
- mex -- x以上で最も小さい，区間に含まれない数を返す  
- output -- debugに使えます  
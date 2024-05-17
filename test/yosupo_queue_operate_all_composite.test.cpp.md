---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SlidingWindowAgregation.hpp
    title: DataStructure/SlidingWindowAgregation.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo_queue_operate_all_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\n\n\
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
    \   return is;\n}\n\n#line 4 \"test/yosupo_queue_operate_all_composite.test.cpp\"\
    \n\n#line 1 \"DataStructure/SlidingWindowAgregation.hpp\"\n// Monoid Sliding-Window-AGregation\n\
    template<typename Monoid>\nstruct SWAG{\n    using F=function<Monoid(Monoid,Monoid)>;\n\
    \    const F f;\n    const Monoid e;\n    stack<pair<Monoid,Monoid>> fr,ba;\n\
    \    SWAG(const F f,const Monoid &e):f(f),e(e){}\n    Monoid get(){\n        Monoid\
    \ a=fr.empty()?e:fr.top().second;\n        Monoid b=ba.empty()?e:ba.top().second;\n\
    \        return f(a,b);\n    }\n    void push(Monoid x){\n        if(ba.empty())\
    \ ba.push(make_pair(x,x));\n        else ba.push(make_pair(x,f(ba.top().second,x)));\n\
    \    }\n    void pop(){\n        if(empty()) return ;\n        if(!fr.empty())\
    \ fr.pop();\n        else{\n            while(!ba.empty()){\n                pair<Monoid,Monoid>\
    \ p=ba.top();ba.pop();\n                if(fr.empty()) fr.push(make_pair(p.first,p.first));\n\
    \                else fr.push(make_pair(p.first,f(p.first,fr.top().second)));\n\
    \            }\n            fr.pop();\n        }\n    }\n    size_t size(){\n\
    \        return fr.size()+ba.size();\n    }\n    bool empty(){\n        return\
    \ size()==0;\n    }\n};\n#line 6 \"test/yosupo_queue_operate_all_composite.test.cpp\"\
    \n\n\nsigned main(){    \n    auto swagfunc=[](pair<ll,ll> p1,pair<ll,ll> p2){\n\
    \        return make_pair(p1.first*p2.first%998244353,(p2.first*p1.second%998244353+p2.second)%998244353);\n\
    \    };\n\n    SWAG<pair<ll,ll>> que(swagfunc,make_pair(1ll,0ll));\n\n    int\
    \ q;cin>>q;\n    while(q--){\n        int t;cin>>t;\n        if(t==0){\n     \
    \       ll a,b;cin>>a>>b;\n            que.push(make_pair(a,b));\n        }else\
    \ if(t==1){\n            que.pop();\n        }else{\n            ll x;cin>>x;\n\
    \            auto p=que.get();\n            cout<<(p.first*x%998244353+p.second)%998244353<<endl;\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../template.hpp\"\n\n#include \"../DataStructure/SlidingWindowAgregation.hpp\"\
    \n\n\nsigned main(){    \n    auto swagfunc=[](pair<ll,ll> p1,pair<ll,ll> p2){\n\
    \        return make_pair(p1.first*p2.first%998244353,(p2.first*p1.second%998244353+p2.second)%998244353);\n\
    \    };\n\n    SWAG<pair<ll,ll>> que(swagfunc,make_pair(1ll,0ll));\n\n    int\
    \ q;cin>>q;\n    while(q--){\n        int t;cin>>t;\n        if(t==0){\n     \
    \       ll a,b;cin>>a>>b;\n            que.push(make_pair(a,b));\n        }else\
    \ if(t==1){\n            que.pop();\n        }else{\n            ll x;cin>>x;\n\
    \            auto p=que.get();\n            cout<<(p.first*x%998244353+p.second)%998244353<<endl;\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - DataStructure/SlidingWindowAgregation.hpp
  isVerificationFile: true
  path: test/yosupo_queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2024-05-17 14:55:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_queue_operate_all_composite.test.cpp
- /verify/test/yosupo_queue_operate_all_composite.test.cpp.html
title: test/yosupo_queue_operate_all_composite.test.cpp
---

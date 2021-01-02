---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"DataStructure/SlidingWindowAgregation.test.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#define ALL(x) x.begin(),x.end()\n#define rep(i,n) for(int\
    \ i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n\
    #define INF 1000000000\n#define mod 998244353\nusing ll=long long;\nconst ll LINF=1001002003004005006ll;\n\
    int dx[]={1,0,-1,0};\nint dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n// Monoid Sliding-Window-AGregation\ntemplate<typename Monoid>\nstruct SWAG{\n\
    \    using F=function<Monoid(Monoid,Monoid)>;\n    const F f;\n    const Monoid\
    \ e;\n    stack<pair<Monoid,Monoid>> fr,ba;\n    SWAG(const F f,const Monoid &e):f(f),e(e){}\n\
    \    Monoid get(){\n        Monoid a=fr.empty()?e:fr.top().second;\n        Monoid\
    \ b=ba.empty()?e:ba.top().second;\n        return f(a,b);\n    }\n    void push(Monoid\
    \ x){\n        if(ba.empty()) ba.push(make_pair(x,x));\n        else ba.push(make_pair(x,f(ba.top().second,x)));\n\
    \    }\n    void pop(){\n        if(empty()) return ;\n        if(!fr.empty())\
    \ fr.pop();\n        else{\n            while(!ba.empty()){\n                pair<Monoid,Monoid>\
    \ p=ba.top();ba.pop();\n                if(fr.empty()) fr.push(make_pair(p.first,p.first));\n\
    \                else fr.push(make_pair(p.first,f(p.first,fr.top().second)));\n\
    \            }\n            fr.pop();\n        }\n    }\n    size_t size(){\n\
    \        return fr.size()+ba.size();\n    }\n    bool empty(){\n        return\
    \ size()==0;\n    }\n};\n\nsigned main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    \n    auto swagfunc=[](pair<ll,ll> p1,pair<ll,ll> p2){\n        return make_pair(p1.first*p2.first%mod,(p2.first*p1.second%mod+p2.second)%mod);\n\
    \    };\n\n    SWAG<pair<ll,ll>> que(swagfunc,make_pair(1ll,0ll));\n\n    int\
    \ q;cin>>q;\n    while(q--){\n        int t;cin>>t;\n        if(t==0){\n     \
    \       ll a,b;cin>>a>>b;\n            que.push(make_pair(a,b));\n        }else\
    \ if(t==1){\n            que.pop();\n        }else{\n            ll x;cin>>x;\n\
    \            auto p=que.get();\n            cout<<(p.first*x%mod+p.second)%mod<<endl;\n\
    \        }\n    }\n\n\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) x.begin(),x.end()\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto\
    \ x:v){cout<<x<<' ';}cout<<endl;\n#define INF 1000000000\n#define mod 998244353\n\
    using ll=long long;\nconst ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0};\n\
    int dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\ntemplate<class\
    \ T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class\
    \ T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\n\n\
    // Monoid Sliding-Window-AGregation\ntemplate<typename Monoid>\nstruct SWAG{\n\
    \    using F=function<Monoid(Monoid,Monoid)>;\n    const F f;\n    const Monoid\
    \ e;\n    stack<pair<Monoid,Monoid>> fr,ba;\n    SWAG(const F f,const Monoid &e):f(f),e(e){}\n\
    \    Monoid get(){\n        Monoid a=fr.empty()?e:fr.top().second;\n        Monoid\
    \ b=ba.empty()?e:ba.top().second;\n        return f(a,b);\n    }\n    void push(Monoid\
    \ x){\n        if(ba.empty()) ba.push(make_pair(x,x));\n        else ba.push(make_pair(x,f(ba.top().second,x)));\n\
    \    }\n    void pop(){\n        if(empty()) return ;\n        if(!fr.empty())\
    \ fr.pop();\n        else{\n            while(!ba.empty()){\n                pair<Monoid,Monoid>\
    \ p=ba.top();ba.pop();\n                if(fr.empty()) fr.push(make_pair(p.first,p.first));\n\
    \                else fr.push(make_pair(p.first,f(p.first,fr.top().second)));\n\
    \            }\n            fr.pop();\n        }\n    }\n    size_t size(){\n\
    \        return fr.size()+ba.size();\n    }\n    bool empty(){\n        return\
    \ size()==0;\n    }\n};\n\nsigned main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    \n    auto swagfunc=[](pair<ll,ll> p1,pair<ll,ll> p2){\n        return make_pair(p1.first*p2.first%mod,(p2.first*p1.second%mod+p2.second)%mod);\n\
    \    };\n\n    SWAG<pair<ll,ll>> que(swagfunc,make_pair(1ll,0ll));\n\n    int\
    \ q;cin>>q;\n    while(q--){\n        int t;cin>>t;\n        if(t==0){\n     \
    \       ll a,b;cin>>a>>b;\n            que.push(make_pair(a,b));\n        }else\
    \ if(t==1){\n            que.pop();\n        }else{\n            ll x;cin>>x;\n\
    \            auto p=que.get();\n            cout<<(p.first*x%mod+p.second)%mod<<endl;\n\
    \        }\n    }\n\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: DataStructure/SlidingWindowAgregation.test.cpp
  requiredBy: []
  timestamp: '2021-01-02 17:06:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/SlidingWindowAgregation.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/SlidingWindowAgregation.test.cpp
- /verify/DataStructure/SlidingWindowAgregation.test.cpp.html
title: DataStructure/SlidingWindowAgregation.test.cpp
---

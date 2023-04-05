---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yuki5061.test.cpp
    title: test/yuki5061.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://ei1333.github.io/library/structure/others/slope-queue.hpp
    - https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
    - https://yukicoder.me/submissions/644671
  bundledCode: "#line 1 \"DataStructure/Slope.hpp\"\n// https://yukicoder.me/submissions/644671\n\
    // https://ei1333.github.io/library/structure/others/slope-queue.hpp\n// https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8\n\
    // ex)\n// f(x) <- min_{y<=x+k} f(y)\n//      1. f.shift(k)\n//      2. f.apply_cumulative_min()\n\
    template<typename T>\nstruct Slope{\n// private:\n    using P=pair<T,T>;\n   \
    \ priority_queue<P,vector<P>,less<P>>    L;\n    priority_queue<P,vector<P>,greater<P>>\
    \ R;\n    T add_L,add_R,min_f;\n    void push_R(T a,T cnt){if(cnt>0) R.emplace(a-add_R,cnt);}\n\
    \    void push_L(T a,T cnt){if(cnt>0) L.emplace(a-add_L,cnt);}\n    P top_R(){return\
    \ P(R.top().first+add_R,R.top().second);}\n    P top_L(){return P(L.top().first+add_L,L.top().second);}\n\
    \    P pop_R(){\n        P ret=top_R();\n        R.pop();\n        return ret;\n\
    \    }\n    P pop_L(){\n        P ret=top_L();\n        L.pop();\n        return\
    \ ret;\n    }\n\npublic:\n    Slope():add_L(0),add_R(0),min_f(0){}\n    void add_all(T\
    \ a){min_f+=a;}\n    void add_x_minus_a(T a,T cnt=1){\n        while(cnt>0 and\
    \ !L.empty() and a<top_L().first){\n            auto [pos,num]=pop_L();\n    \
    \        T mv=std::min(cnt,num);\n            push_R(pos,mv);\n            push_L(pos,num-mv);\n\
    \            push_L(a,mv);\n            min_f+=(pos-a)*mv;\n            cnt-=mv;\n\
    \        }\n        push_R(a,cnt);\n    }\n    void add_a_minus_x(T a,T cnt=1){\n\
    \        while(cnt>0 and !R.empty() and a>top_R().first){\n            auto [pos,num]=pop_R();\n\
    \            T mv=std::min(cnt,num);\n            push_L(pos,mv);\n          \
    \  push_R(pos,num-mv);\n            push_R(a,mv);\n            min_f+=(a-pos)*mv;\n\
    \            cnt-=mv;\n        }\n        push_L(a,cnt);\n    }\n    void add_abs(T\
    \ a,T cnt=1){\n        add_a_minus_x(a,cnt);\n        add_x_minus_a(a,cnt);\n\
    \    }\n    void clear_right(){while(!R.empty()) R.pop();}\n    void clear_left(){\
    \ while(!L.empty()) L.pop();}\n    // f <- min{x-b<=y<=x-a} f(y)\n    void shift(T\
    \ a,T b){\n        assert(a<=b);\n        add_L+=a,add_R+=b;\n    }\n    // f(x)\
    \ <- f(x-a)\n    void shift(T a){shift(a,a);}\n    // get value O(N)\n    T operator()(T\
    \ x){\n        T ret=min_f;\n        auto vec=[](auto pq,T shift){\n         \
    \   vector<P> v;\n            while(!pq.empty()){\n                v.emplace_back(pq.top().first+shift,pq.top().second);\n\
    \                pq.pop();\n            }\n            return v;\n        };\n\
    \        for(auto [pos,num]:vec(L,add_L)) ret+=max(pos-x,T(0))*num;\n        for(auto\
    \ [pos,num]:vec(R,add_R)) ret+=max(x-pos,T(0))*num;\n        return ret;\n   \
    \ }\n    T min(){return min_f;}\n    pair<T,T> argmin(){return make_pair(P(top_L().first,top_R().first));}\n\
    };\n"
  code: "// https://yukicoder.me/submissions/644671\n// https://ei1333.github.io/library/structure/others/slope-queue.hpp\n\
    // https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8\n// ex)\n// f(x)\
    \ <- min_{y<=x+k} f(y)\n//      1. f.shift(k)\n//      2. f.apply_cumulative_min()\n\
    template<typename T>\nstruct Slope{\n// private:\n    using P=pair<T,T>;\n   \
    \ priority_queue<P,vector<P>,less<P>>    L;\n    priority_queue<P,vector<P>,greater<P>>\
    \ R;\n    T add_L,add_R,min_f;\n    void push_R(T a,T cnt){if(cnt>0) R.emplace(a-add_R,cnt);}\n\
    \    void push_L(T a,T cnt){if(cnt>0) L.emplace(a-add_L,cnt);}\n    P top_R(){return\
    \ P(R.top().first+add_R,R.top().second);}\n    P top_L(){return P(L.top().first+add_L,L.top().second);}\n\
    \    P pop_R(){\n        P ret=top_R();\n        R.pop();\n        return ret;\n\
    \    }\n    P pop_L(){\n        P ret=top_L();\n        L.pop();\n        return\
    \ ret;\n    }\n\npublic:\n    Slope():add_L(0),add_R(0),min_f(0){}\n    void add_all(T\
    \ a){min_f+=a;}\n    void add_x_minus_a(T a,T cnt=1){\n        while(cnt>0 and\
    \ !L.empty() and a<top_L().first){\n            auto [pos,num]=pop_L();\n    \
    \        T mv=std::min(cnt,num);\n            push_R(pos,mv);\n            push_L(pos,num-mv);\n\
    \            push_L(a,mv);\n            min_f+=(pos-a)*mv;\n            cnt-=mv;\n\
    \        }\n        push_R(a,cnt);\n    }\n    void add_a_minus_x(T a,T cnt=1){\n\
    \        while(cnt>0 and !R.empty() and a>top_R().first){\n            auto [pos,num]=pop_R();\n\
    \            T mv=std::min(cnt,num);\n            push_L(pos,mv);\n          \
    \  push_R(pos,num-mv);\n            push_R(a,mv);\n            min_f+=(a-pos)*mv;\n\
    \            cnt-=mv;\n        }\n        push_L(a,cnt);\n    }\n    void add_abs(T\
    \ a,T cnt=1){\n        add_a_minus_x(a,cnt);\n        add_x_minus_a(a,cnt);\n\
    \    }\n    void clear_right(){while(!R.empty()) R.pop();}\n    void clear_left(){\
    \ while(!L.empty()) L.pop();}\n    // f <- min{x-b<=y<=x-a} f(y)\n    void shift(T\
    \ a,T b){\n        assert(a<=b);\n        add_L+=a,add_R+=b;\n    }\n    // f(x)\
    \ <- f(x-a)\n    void shift(T a){shift(a,a);}\n    // get value O(N)\n    T operator()(T\
    \ x){\n        T ret=min_f;\n        auto vec=[](auto pq,T shift){\n         \
    \   vector<P> v;\n            while(!pq.empty()){\n                v.emplace_back(pq.top().first+shift,pq.top().second);\n\
    \                pq.pop();\n            }\n            return v;\n        };\n\
    \        for(auto [pos,num]:vec(L,add_L)) ret+=max(pos-x,T(0))*num;\n        for(auto\
    \ [pos,num]:vec(R,add_R)) ret+=max(x-pos,T(0))*num;\n        return ret;\n   \
    \ }\n    T min(){return min_f;}\n    pair<T,T> argmin(){return make_pair(P(top_L().first,top_R().first));}\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Slope.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yuki5061.test.cpp
documentation_of: DataStructure/Slope.hpp
layout: document
title: Slope
---

## 概要  
- add_all(a) : f(x) <- f(x) + a
- add_x_minus_a(a, cnt) : f(x) <- f(x) + max(x-a, 0) * cnt
- add_a_minus_x(a, cnt) : f(x) <- f(x) + max(a-x, 0) * cnt
- add_abs(a, cnt) : f(x) <- f(x) + abs(x-a) * cnt
- clear_left : f(x) <- min{y>=x} f(y) (右から累積minに相当)
- clear_right : f(x) <- min{y<=x} f(y) (左から累積minに相当)
- shift(a, b) : f(x) <- min{x-b <= y <= x-a} f(y)
- shift(a) : f(x) <- f(x-a)
- operator(a) : f(a)
- min : min{x} f(x)
- argmin : min を与えるxの左端，右端をペアで返す

## 計算量  
operator(a)はO(N)なので注意

## ref  
https://yukicoder.me/submissions/644671  
https://ei1333.github.io/library/structure/others/slope-queue.hpp  
https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8  

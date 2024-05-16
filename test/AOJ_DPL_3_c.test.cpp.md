---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/LargestRectangle.hpp
    title: "Largest Rectangle (\u6700\u5927\u9577\u65B9\u5F62)"
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=ja
  bundledCode: "#line 1 \"test/AOJ_DPL_3_c.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=ja\"\
    \n\n#line 1 \"bits/stdc++.h\"\n// C\n#ifndef _GLIBCXX_NO_ASSERT\n#include <cassert>\n\
    #endif\n#include <cctype>\n#include <cerrno>\n#include <cfloat>\n#include <ciso646>\n\
    #include <climits>\n#include <clocale>\n#include <cmath>\n#include <csetjmp>\n\
    #include <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <ctime>\n\n#if __cplusplus >=\
    \ 201103L\n#include <ccomplex>\n#include <cfenv>\n#include <cinttypes>\n#include\
    \ <cstdalign>\n#include <cstdbool>\n#include <cstdint>\n#include <ctgmath>\n#include\
    \ <cwchar>\n#include <cwctype>\n#endif\n\n// C++\n#include <algorithm>\n#include\
    \ <bitset>\n#include <complex>\n#include <deque>\n#include <exception>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <ios>\n#include\
    \ <iosfwd>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <locale>\n#include <map>\n#include <memory>\n\
    #include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <typeinfo>\n#include <utility>\n#include\
    \ <valarray>\n#include <vector>\n\n#if __cplusplus >= 201103L\n#include <array>\n\
    #include <atomic>\n#include <chrono>\n#include <condition_variable>\n#include\
    \ <forward_list>\n#include <future>\n#include <initializer_list>\n#include <mutex>\n\
    #include <random>\n#include <ratio>\n#include <regex>\n#include <scoped_allocator>\n\
    #include <system_error>\n#include <thread>\n#include <tuple>\n#include <typeindex>\n\
    #include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n#endif\n\
    #line 2 \"template.hpp\"\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
    #define rep(i,n) for(int i=0;i<(n);i++)\n#define debug(v) cout<<#v<<\":\";for(auto\
    \ x:v){cout<<x<<' ';}cout<<endl;\n#define mod 1000000007\nusing ll=long long;\n\
    const int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\nint dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n\
    // ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\ntemplate<class T>bool chmax(T &a,const\
    \ T &b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool chmin(T\
    \ &a,const T &b){if(b<a){a=b;return true;}return false;}\n\nstruct IOSetup{\n\
    \    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n     \
    \   cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename T>\n\
    ostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/AOJ_DPL_3_c.test.cpp\"\n\n#line 1 \"DP/LargestRectangle.hpp\"\
    \ntemplate<typename INT>\nINT LargestRectangle(vector<INT> v){\n    int n=(int)v.size();\n\
    \    INT inf=numeric_limits<INT>::max()/2;\n    stack<pair<INT,INT>> st;\n   \
    \ st.emplace(-inf,-1);// \u3070\u3093\u307A\u3044\u3093\n    INT ret=0;\n    for(int\
    \ i=0;i<n;i++){\n        while(v[i]<st.top().first){\n            auto p=st.top();st.pop();\n\
    \            ret=max(ret,(i-st.top().second-1)*p.first);\n        }\n        st.emplace(v[i],i);\n\
    \    }\n    while(!st.empty()){\n        auto p=st.top();st.pop();\n        if(p.first==-inf)\
    \ continue;\n        ret=max(ret,(n-st.top().second-1)*p.first);\n    }\n    return\
    \ ret;\n}\n#line 6 \"test/AOJ_DPL_3_c.test.cpp\"\n\nsigned main(){\n    int n;cin>>n;\n\
    \    vector<ll> v(n);\n    cin>>v;\n    cout<<LargestRectangle(v)<<endl;\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=ja\"\
    \n\n#include \"../template.hpp\"\n\n#include \"../DP/LargestRectangle.hpp\"\n\n\
    signed main(){\n    int n;cin>>n;\n    vector<ll> v(n);\n    cin>>v;\n    cout<<LargestRectangle(v)<<endl;\n\
    \    return 0;\n}\n"
  dependsOn:
  - template.hpp
  - bits/stdc++.h
  - DP/LargestRectangle.hpp
  isVerificationFile: true
  path: test/AOJ_DPL_3_c.test.cpp
  requiredBy: []
  timestamp: '2024-05-15 18:03:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ_DPL_3_c.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_DPL_3_c.test.cpp
- /verify/test/AOJ_DPL_3_c.test.cpp.html
title: test/AOJ_DPL_3_c.test.cpp
---

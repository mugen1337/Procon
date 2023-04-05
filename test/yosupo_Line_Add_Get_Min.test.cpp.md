---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/KineticSegmentTree.cpp
    title: SegmentTree/KineticSegmentTree.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/yosupo_Line_Add_Get_Min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#line 1 \"template.cpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define ALL(x) begin(x),end(x)\n\
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
    \   return is;\n}\n\n#line 4 \"test/yosupo_Line_Add_Get_Min.test.cpp\"\n\n#line\
    \ 1 \"SegmentTree/KineticSegmentTree.cpp\"\n/*\nupdate(i, a, b)\n    set A[i]\
    \ = a and B[i] = b\n    O(log N)\nquery(l, r)\n    return min{l <= i < r} A[i]\
    \ * T + B[i]\n    O(log N)\nheaten(new_T)\n    set T = new_temp (! current_T <\
    \ new_T)\n    O((log N) ^ 2) Amortized\n\nRef : \nhttps://codeforces.com/blog/entry/82094\n\
    https://koosaga.com/307\n*/\ntemplate<typename T>\nstruct KineticSegmentTree{\n\
    private:\n    const T TINF = numeric_limits<T>::max() / 2;\n    using Line = pair<T,\
    \ T>;\n\n    int sz;\n    T temp;             // temperature\n    vector<Line>\
    \ lines; // min line\n    vector<T> melt;     // melting temperature of each subtree\n\
    \n    inline T f(const Line &L, T x) const {\n        return L.first * x + L.second;\n\
    \    }\n\n    // f(lhs, temp) < f(rhs, temp) ?\n    inline bool le(const Line\
    \ &lhs, const Line &rhs) const {\n        T flhs = f(lhs, temp), frhs = f(rhs,\
    \ temp);\n        if(flhs != frhs) return flhs < frhs;\n        return lhs.first\
    \ < rhs.first; // (!) temp < x : lhs < rhs\n    }\n\n    // return x, temp < x\
    \ && f(A, x) == f(B, x)\n    T intersect(Line A, Line B) const {\n        if(A.first\
    \ == B.first) return TINF;\n        if(A.first < B.first) swap(A, B);\n      \
    \  T delta = f(B, temp) - f(A, temp);\n        T delta_slope = A.first - B.first;\n\
    \        T ret = temp + (delta - 1) / delta_slope + 1;\n        return ret > temp\
    \ ? ret : TINF;\n    }\n\n    void recalc(int k){\n        if(k >= sz)       \
    \ return ; \n        if(melt[k] > temp) return ; // (!) nothing to update\n  \
    \      // update\u5F8C\u306Erecalc\u3067\u306F\uFF0C\u95A2\u4FC2\u306A\u3044\u30CE\
    \u30FC\u30C9\u306F\u3053\u3053\u3067\u6B62\u307E\u308B\n\n        recalc(2 * k);\n\
    \        recalc(2 * k + 1);\n\n        auto L = lines[2 * k], R = lines[2 * k\
    \ + 1];\n        if(le(L, R)) lines[k] = L;\n        else         lines[k] = R;\n\
    \n        melt[k] = min(melt[2 * k], melt[2 * k + 1]);\n        if(L != R){\n\
    \            T t = intersect(L, R);\n            melt[k] = min(melt[k], t);\n\
    \        }\n        return ;\n    }\n\n    T query(int l, int r, int k, int a,\
    \ int b){\n        if(b <= l or r <= a) return TINF;\n        if(l <= a and b\
    \ <= r) return f(lines[k], temp);\n        int m = (a + b) / 2;\n        return\
    \ min(query(l, r, 2 * k, a, m), query(l, r, 2 * k + 1, m, b));\n    }\n\npublic:\n\
    \    KineticSegmentTree(int N, T temp_ = T(0)) : temp(temp_){\n        sz = 1;\n\
    \        while(sz < N) sz <<= 1;\n        lines.assign(sz * 2, {0, TINF});\n \
    \       melt.assign(sz * 2, TINF);\n    }\n\n    // O(log N)\n    void update(int\
    \ idx, T a, T b){\n        int k = idx + sz;\n        lines[k] = {a, b};\n   \
    \     k >>= 1;\n        for(; k; k >>= 1){\n            melt[k] = -TINF; // re-set\
    \ in recalc\u2193\n            recalc(k);\n        }\n    }\n\n    // O(log N)\n\
    \    T query(int l, int r){\n        return query(l, r, 1, 0, sz);\n    }\n\n\
    \    // Amortized O((log N) ^ 2)\n    void heaten(T new_temp){\n        assert(new_temp\
    \ >= temp);\n        temp = new_temp;\n        recalc(1);\n    }\n};\n#line 6\
    \ \"test/yosupo_Line_Add_Get_Min.test.cpp\"\n\nsigned main(){\n    int N, Q; cin\
    \ >> N >> Q;\n\n    KineticSegmentTree<ll> KST(N + Q, -2e9);\n    rep(i, N){\n\
    \        ll a, b; cin >> a >> b;\n        KST.update(i, a, b);\n    }\n\n    int\
    \ R = N, qs = 0;\n    vector<tuple<int, ll, int>> query; // query idx, x, R\n\
    \    rep(i, Q){\n        int type; cin >> type;\n        if(type == 0){\n    \
    \        ll a, b; cin >> a >> b;\n            KST.update(R++, a, b);\n       \
    \ }else{\n            ll p; cin >> p;\n            query.emplace_back(qs++, p,\
    \ R);\n        }\n    }\n\n    vector<ll> ans(qs);\n\n    sort(begin(query), end(query),\
    \ \n    [](tuple<int, ll, int> &lhs, tuple<int, ll, int> &rhs){\n        return\
    \ get<1>(lhs) < get<1>(rhs);\n    });\n\n    for(auto &[qidx, x, r] : query){\n\
    \        KST.heaten(x);\n        ans[qidx] = KST.query(0, r);\n    }\n\n    for(ll\
    \ &x : ans) cout << x << \"\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"../template.cpp\"\n\n#include \"../SegmentTree/KineticSegmentTree.cpp\"\
    \n\nsigned main(){\n    int N, Q; cin >> N >> Q;\n\n    KineticSegmentTree<ll>\
    \ KST(N + Q, -2e9);\n    rep(i, N){\n        ll a, b; cin >> a >> b;\n       \
    \ KST.update(i, a, b);\n    }\n\n    int R = N, qs = 0;\n    vector<tuple<int,\
    \ ll, int>> query; // query idx, x, R\n    rep(i, Q){\n        int type; cin >>\
    \ type;\n        if(type == 0){\n            ll a, b; cin >> a >> b;\n       \
    \     KST.update(R++, a, b);\n        }else{\n            ll p; cin >> p;\n  \
    \          query.emplace_back(qs++, p, R);\n        }\n    }\n\n    vector<ll>\
    \ ans(qs);\n\n    sort(begin(query), end(query), \n    [](tuple<int, ll, int>\
    \ &lhs, tuple<int, ll, int> &rhs){\n        return get<1>(lhs) < get<1>(rhs);\n\
    \    });\n\n    for(auto &[qidx, x, r] : query){\n        KST.heaten(x);\n   \
    \     ans[qidx] = KST.query(0, r);\n    }\n\n    for(ll &x : ans) cout << x <<\
    \ \"\\n\";\n    return 0;\n}"
  dependsOn:
  - template.cpp
  - SegmentTree/KineticSegmentTree.cpp
  isVerificationFile: true
  path: test/yosupo_Line_Add_Get_Min.test.cpp
  requiredBy: []
  timestamp: '2023-01-04 01:04:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_Line_Add_Get_Min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Line_Add_Get_Min.test.cpp
- /verify/test/yosupo_Line_Add_Get_Min.test.cpp.html
title: test/yosupo_Line_Add_Get_Min.test.cpp
---

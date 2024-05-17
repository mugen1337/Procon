---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_Line_Add_Get_Min.test.cpp
    title: test/yosupo_Line_Add_Get_Min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/82094
    - https://koosaga.com/307
  bundledCode: "#line 1 \"SegmentTree/KineticSegmentTree.hpp\"\n/*\nupdate(i, a, b)\n\
    \    set A[i] = a and B[i] = b\n    O(log N)\nquery(l, r)\n    return min{l <=\
    \ i < r} A[i] * T + B[i]\n    O(log N)\nheaten(new_T)\n    set T = new_temp (!\
    \ current_T < new_T)\n    O((log N) ^ 2) Amortized\n\nRef : \nhttps://codeforces.com/blog/entry/82094\n\
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
    \ >= temp);\n        temp = new_temp;\n        recalc(1);\n    }\n};\n"
  code: "/*\nupdate(i, a, b)\n    set A[i] = a and B[i] = b\n    O(log N)\nquery(l,\
    \ r)\n    return min{l <= i < r} A[i] * T + B[i]\n    O(log N)\nheaten(new_T)\n\
    \    set T = new_temp (! current_T < new_T)\n    O((log N) ^ 2) Amortized\n\n\
    Ref : \nhttps://codeforces.com/blog/entry/82094\nhttps://koosaga.com/307\n*/\n\
    template<typename T>\nstruct KineticSegmentTree{\nprivate:\n    const T TINF =\
    \ numeric_limits<T>::max() / 2;\n    using Line = pair<T, T>;\n\n    int sz;\n\
    \    T temp;             // temperature\n    vector<Line> lines; // min line\n\
    \    vector<T> melt;     // melting temperature of each subtree\n\n    inline\
    \ T f(const Line &L, T x) const {\n        return L.first * x + L.second;\n  \
    \  }\n\n    // f(lhs, temp) < f(rhs, temp) ?\n    inline bool le(const Line &lhs,\
    \ const Line &rhs) const {\n        T flhs = f(lhs, temp), frhs = f(rhs, temp);\n\
    \        if(flhs != frhs) return flhs < frhs;\n        return lhs.first < rhs.first;\
    \ // (!) temp < x : lhs < rhs\n    }\n\n    // return x, temp < x && f(A, x) ==\
    \ f(B, x)\n    T intersect(Line A, Line B) const {\n        if(A.first == B.first)\
    \ return TINF;\n        if(A.first < B.first) swap(A, B);\n        T delta = f(B,\
    \ temp) - f(A, temp);\n        T delta_slope = A.first - B.first;\n        T ret\
    \ = temp + (delta - 1) / delta_slope + 1;\n        return ret > temp ? ret : TINF;\n\
    \    }\n\n    void recalc(int k){\n        if(k >= sz)        return ; \n    \
    \    if(melt[k] > temp) return ; // (!) nothing to update\n        // update\u5F8C\
    \u306Erecalc\u3067\u306F\uFF0C\u95A2\u4FC2\u306A\u3044\u30CE\u30FC\u30C9\u306F\
    \u3053\u3053\u3067\u6B62\u307E\u308B\n\n        recalc(2 * k);\n        recalc(2\
    \ * k + 1);\n\n        auto L = lines[2 * k], R = lines[2 * k + 1];\n        if(le(L,\
    \ R)) lines[k] = L;\n        else         lines[k] = R;\n\n        melt[k] = min(melt[2\
    \ * k], melt[2 * k + 1]);\n        if(L != R){\n            T t = intersect(L,\
    \ R);\n            melt[k] = min(melt[k], t);\n        }\n        return ;\n \
    \   }\n\n    T query(int l, int r, int k, int a, int b){\n        if(b <= l or\
    \ r <= a) return TINF;\n        if(l <= a and b <= r) return f(lines[k], temp);\n\
    \        int m = (a + b) / 2;\n        return min(query(l, r, 2 * k, a, m), query(l,\
    \ r, 2 * k + 1, m, b));\n    }\n\npublic:\n    KineticSegmentTree(int N, T temp_\
    \ = T(0)) : temp(temp_){\n        sz = 1;\n        while(sz < N) sz <<= 1;\n \
    \       lines.assign(sz * 2, {0, TINF});\n        melt.assign(sz * 2, TINF);\n\
    \    }\n\n    // O(log N)\n    void update(int idx, T a, T b){\n        int k\
    \ = idx + sz;\n        lines[k] = {a, b};\n        k >>= 1;\n        for(; k;\
    \ k >>= 1){\n            melt[k] = -TINF; // re-set in recalc\u2193\n        \
    \    recalc(k);\n        }\n    }\n\n    // O(log N)\n    T query(int l, int r){\n\
    \        return query(l, r, 1, 0, sz);\n    }\n\n    // Amortized O((log N) ^\
    \ 2)\n    void heaten(T new_temp){\n        assert(new_temp >= temp);\n      \
    \  temp = new_temp;\n        recalc(1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/KineticSegmentTree.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_Line_Add_Get_Min.test.cpp
documentation_of: SegmentTree/KineticSegmentTree.hpp
layout: document
redirect_from:
- /library/SegmentTree/KineticSegmentTree.hpp
- /library/SegmentTree/KineticSegmentTree.hpp.html
title: SegmentTree/KineticSegmentTree.hpp
---

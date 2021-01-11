---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki1948.test.cpp
    title: test/yuki1948.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/LiChaoTree.cpp\"\n// min\ntemplate<typename\
    \ T>\nstruct LiChaoTree{\n    private:\n    struct Line{\n        T a,b;\n   \
    \     Line(T a,T b):a(a),b(b){}\n        T operator()(T x){return a*x+b;}\n  \
    \  };\n    \n    void add(Line &li,int k,int l,int r){\n        int m=(l+r)/2;\n\
    \        // replace flag\n        bool cl=li(xs[l])<seg[k](xs[l]),cm=li(xs[m])<seg[k](xs[m]);\n\
    \        if(cm) swap(seg[k],li);// ! \u307F\u3066\u308B\u533A\u9593\u306B\u304A\
    \u3044\u3066\u307F\u3066\u308B\u76F4\u7DDA\u3092\u5207\u308A\u66FF\u3048\u308B\
    \n        if(l+1>=r) return ;\n        // \u3069\u3061\u3089\u304B\u306B\u3057\
    \u304B\u964D\u308A\u306A\u3044\u306E\u3067\u8A08\u7B97\u91CF\u304Clog\n      \
    \  if(cl!=cm) add(li,2*k,l,m);\n        else add(li,2*k+1,m,r);\n        return\
    \ ;\n    }\n\n    vector<T> xs;\n    vector<Line> seg;\n    int sz;\n\n    public:\n\
    \    LiChaoTree(const vector<T> &x,T TINF):xs(x){\n        sort(begin(xs),end(xs));\n\
    \        xs.erase(unique(begin(xs),end(xs)),end(xs));\n        sz=1;\n       \
    \ while(sz<(int)xs.size()) sz<<=1;\n        while((int)xs.size()<sz) xs.push_back(xs.back()+1);\n\
    \        seg.assign(2*sz,Line(0,TINF));\n    }\n\n    // add ax+b\n    void add(T\
    \ a,T b){\n        Line l(a,b);\n        add(l,1,0,sz);\n    }\n\n    T query(T\
    \ val){\n        int k=lower_bound(begin(xs),end(xs),val)-begin(xs);\n       \
    \ assert(xs[k]==val);\n        k+=sz;\n        T ret=seg[k](val);\n        for(;k;k>>=1)\
    \ ret=min(ret,seg[k](val));\n        return ret;\n    }\n};\n"
  code: "// min\ntemplate<typename T>\nstruct LiChaoTree{\n    private:\n    struct\
    \ Line{\n        T a,b;\n        Line(T a,T b):a(a),b(b){}\n        T operator()(T\
    \ x){return a*x+b;}\n    };\n    \n    void add(Line &li,int k,int l,int r){\n\
    \        int m=(l+r)/2;\n        // replace flag\n        bool cl=li(xs[l])<seg[k](xs[l]),cm=li(xs[m])<seg[k](xs[m]);\n\
    \        if(cm) swap(seg[k],li);// ! \u307F\u3066\u308B\u533A\u9593\u306B\u304A\
    \u3044\u3066\u307F\u3066\u308B\u76F4\u7DDA\u3092\u5207\u308A\u66FF\u3048\u308B\
    \n        if(l+1>=r) return ;\n        // \u3069\u3061\u3089\u304B\u306B\u3057\
    \u304B\u964D\u308A\u306A\u3044\u306E\u3067\u8A08\u7B97\u91CF\u304Clog\n      \
    \  if(cl!=cm) add(li,2*k,l,m);\n        else add(li,2*k+1,m,r);\n        return\
    \ ;\n    }\n\n    vector<T> xs;\n    vector<Line> seg;\n    int sz;\n\n    public:\n\
    \    LiChaoTree(const vector<T> &x,T TINF):xs(x){\n        sort(begin(xs),end(xs));\n\
    \        xs.erase(unique(begin(xs),end(xs)),end(xs));\n        sz=1;\n       \
    \ while(sz<(int)xs.size()) sz<<=1;\n        while((int)xs.size()<sz) xs.push_back(xs.back()+1);\n\
    \        seg.assign(2*sz,Line(0,TINF));\n    }\n\n    // add ax+b\n    void add(T\
    \ a,T b){\n        Line l(a,b);\n        add(l,1,0,sz);\n    }\n\n    T query(T\
    \ val){\n        int k=lower_bound(begin(xs),end(xs),val)-begin(xs);\n       \
    \ assert(xs[k]==val);\n        k+=sz;\n        T ret=seg[k](val);\n        for(;k;k>>=1)\
    \ ret=min(ret,seg[k](val));\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LiChaoTree.cpp
  requiredBy: []
  timestamp: '2021-01-11 22:15:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki1948.test.cpp
documentation_of: DataStructure/LiChaoTree.cpp
layout: document
redirect_from:
- /library/DataStructure/LiChaoTree.cpp
- /library/DataStructure/LiChaoTree.cpp.html
title: DataStructure/LiChaoTree.cpp
---

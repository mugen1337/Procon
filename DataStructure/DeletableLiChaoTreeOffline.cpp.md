---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/678/problem/F
    - https://codeforces.com/contest/678/submission/104541023
  bundledCode: "#line 1 \"DataStructure/DeletableLiChaoTreeOffline.cpp\"\n// verify\n\
    // https://codeforces.com/contest/678/problem/F\n// https://codeforces.com/contest/678/submission/104541023\n\
    \n// min\ntemplate<typename T>\nstruct LiChaoTreeUndo{\n    struct Line{\n   \
    \     T a,b;\n        Line(T a,T b):a(a),b(b){}\n        T operator()(T x){return\
    \ a*x+b;}\n    };\n\n    vector<T> xs;\n    vector<Line> seg;\n    int sz;\n \
    \   stack<vector<pair<int,Line>>> history;\n    \n    void add(Line &li,int k,int\
    \ l,int r,vector<pair<int,Line>> &h){\n        int m=(l+r)/2;\n        // replace\
    \ flag\n        bool cl=li(xs[l])<seg[k](xs[l]),cm=li(xs[m])<seg[k](xs[m]);\n\
    \        if(cm){\n            h.emplace_back(k,seg[k]);\n            swap(seg[k],li);\n\
    \        }\n        if(l+1>=r) return ;\n        if(cl!=cm) add(li,2*k,l,m,h);\n\
    \        else add(li,2*k+1,m,r,h);\n        return ;\n    }\n\n    LiChaoTreeUndo(const\
    \ vector<T> &x,T TINF):xs(x){\n        sort(begin(xs),end(xs));\n        xs.erase(unique(begin(xs),end(xs)),end(xs));\n\
    \        sz=1;\n        while(sz<(int)xs.size()) sz<<=1;\n        while((int)xs.size()<sz)\
    \ xs.push_back(xs.back()+1);\n        seg.assign(2*sz,Line(0,TINF));\n    }\n\n\
    \    // add ax+b\n    void add(T a,T b){\n        vector<pair<int,Line>> h;\n\
    \        Line l(a,b);\n        add(l,1,0,sz,h);\n        history.push(h);\n  \
    \  }\n\n    void undo(){\n        for(auto [k,val]:history.top()) seg[k]=val;\n\
    \        history.pop();\n    }\n\n    T query(T val){\n        int k=lower_bound(begin(xs),end(xs),val)-begin(xs);\n\
    \        assert(xs[k]==val);\n        k+=sz;\n        T ret=seg[k](val);\n   \
    \     while(k>0){\n            k>>=1;\n            ret=min(ret,seg[k](val));\n\
    \        }\n        return ret;\n    }\n};\n\ntemplate<typename T>\nstruct DeletableConvexHullTrickOffline{\n\
    \    using P=pair<T,T>;\n    \n    int sz;\n    vector<vector<P>> seg;\n    vector<pair<pair<int,int>,P>>\
    \ es;// {{start, end}, P}\n    LiChaoTreeUndo<T> lct;\n    map<P,int> cnt,prev;\n\
    \n    void add_seg(int a,int b,P &li,int k,int l,int r){\n        if(r<=a or b<=l)\
    \ return ;\n        if(a<=l and r<=b){\n            seg[k].push_back(li);\n  \
    \          return ;\n        }\n        add_seg(a,b,li,2*k,l,(l+r)/2);\n     \
    \   add_seg(a,b,li,2*k+1,(l+r)/2,r);\n    }\n\n    int query_size;\n    DeletableConvexHullTrickOffline(int\
    \ query_size,vector<T> xs,T TINF):lct(xs,TINF),query_size(query_size){\n     \
    \   sz=1;\n        while(sz<query_size) sz<<=1;\n        seg.resize(2*sz);\n \
    \   }\n\n    // query\u306Eindex\u9806\u306B\u8FFD\u52A0, y=ax+b\n    void add_line(int\
    \ query_idx,T a,T b){\n        if(cnt[P(a,b)]==0) prev[P(a,b)]=query_idx;\n  \
    \      cnt[P(a,b)]++;\n    }\n    void delete_line(int query_idx,T a,T b){\n \
    \       // assert(cnt[{a,b}]>0);\n        cnt[P(a,b)]--;\n        if(cnt[P(a,b)]==0)\
    \ es.emplace_back(make_pair(prev[P(a,b)],query_idx),P(a,b));\n    }\n    void\
    \ build(){\n        for(auto [li,c]:cnt)if(c>0) es.emplace_back(make_pair(prev[li],sz),li);\n\
    \        for(auto [t,li]:es) add_seg(t.first,t.second,li,1,0,sz);\n    }\n   \
    \ void execute(function<void(int)> &f,int k=1){\n        for(auto li:seg[k]){\n\
    \            lct.add(li.first,li.second);\n        }\n        if(k<sz){\n    \
    \        execute(f,2*k);\n            execute(f,2*k+1);\n        }\n        else\
    \ if(k-sz<query_size){\n            f(k-sz);\n        }\n        for(auto li:seg[k]){\n\
    \            assert(!lct.history.empty());\n            lct.undo();\n        }\n\
    \    }\n};\n"
  code: "// verify\n// https://codeforces.com/contest/678/problem/F\n// https://codeforces.com/contest/678/submission/104541023\n\
    \n// min\ntemplate<typename T>\nstruct LiChaoTreeUndo{\n    struct Line{\n   \
    \     T a,b;\n        Line(T a,T b):a(a),b(b){}\n        T operator()(T x){return\
    \ a*x+b;}\n    };\n\n    vector<T> xs;\n    vector<Line> seg;\n    int sz;\n \
    \   stack<vector<pair<int,Line>>> history;\n    \n    void add(Line &li,int k,int\
    \ l,int r,vector<pair<int,Line>> &h){\n        int m=(l+r)/2;\n        // replace\
    \ flag\n        bool cl=li(xs[l])<seg[k](xs[l]),cm=li(xs[m])<seg[k](xs[m]);\n\
    \        if(cm){\n            h.emplace_back(k,seg[k]);\n            swap(seg[k],li);\n\
    \        }\n        if(l+1>=r) return ;\n        if(cl!=cm) add(li,2*k,l,m,h);\n\
    \        else add(li,2*k+1,m,r,h);\n        return ;\n    }\n\n    LiChaoTreeUndo(const\
    \ vector<T> &x,T TINF):xs(x){\n        sort(begin(xs),end(xs));\n        xs.erase(unique(begin(xs),end(xs)),end(xs));\n\
    \        sz=1;\n        while(sz<(int)xs.size()) sz<<=1;\n        while((int)xs.size()<sz)\
    \ xs.push_back(xs.back()+1);\n        seg.assign(2*sz,Line(0,TINF));\n    }\n\n\
    \    // add ax+b\n    void add(T a,T b){\n        vector<pair<int,Line>> h;\n\
    \        Line l(a,b);\n        add(l,1,0,sz,h);\n        history.push(h);\n  \
    \  }\n\n    void undo(){\n        for(auto [k,val]:history.top()) seg[k]=val;\n\
    \        history.pop();\n    }\n\n    T query(T val){\n        int k=lower_bound(begin(xs),end(xs),val)-begin(xs);\n\
    \        assert(xs[k]==val);\n        k+=sz;\n        T ret=seg[k](val);\n   \
    \     while(k>0){\n            k>>=1;\n            ret=min(ret,seg[k](val));\n\
    \        }\n        return ret;\n    }\n};\n\ntemplate<typename T>\nstruct DeletableConvexHullTrickOffline{\n\
    \    using P=pair<T,T>;\n    \n    int sz;\n    vector<vector<P>> seg;\n    vector<pair<pair<int,int>,P>>\
    \ es;// {{start, end}, P}\n    LiChaoTreeUndo<T> lct;\n    map<P,int> cnt,prev;\n\
    \n    void add_seg(int a,int b,P &li,int k,int l,int r){\n        if(r<=a or b<=l)\
    \ return ;\n        if(a<=l and r<=b){\n            seg[k].push_back(li);\n  \
    \          return ;\n        }\n        add_seg(a,b,li,2*k,l,(l+r)/2);\n     \
    \   add_seg(a,b,li,2*k+1,(l+r)/2,r);\n    }\n\n    int query_size;\n    DeletableConvexHullTrickOffline(int\
    \ query_size,vector<T> xs,T TINF):lct(xs,TINF),query_size(query_size){\n     \
    \   sz=1;\n        while(sz<query_size) sz<<=1;\n        seg.resize(2*sz);\n \
    \   }\n\n    // query\u306Eindex\u9806\u306B\u8FFD\u52A0, y=ax+b\n    void add_line(int\
    \ query_idx,T a,T b){\n        if(cnt[P(a,b)]==0) prev[P(a,b)]=query_idx;\n  \
    \      cnt[P(a,b)]++;\n    }\n    void delete_line(int query_idx,T a,T b){\n \
    \       // assert(cnt[{a,b}]>0);\n        cnt[P(a,b)]--;\n        if(cnt[P(a,b)]==0)\
    \ es.emplace_back(make_pair(prev[P(a,b)],query_idx),P(a,b));\n    }\n    void\
    \ build(){\n        for(auto [li,c]:cnt)if(c>0) es.emplace_back(make_pair(prev[li],sz),li);\n\
    \        for(auto [t,li]:es) add_seg(t.first,t.second,li,1,0,sz);\n    }\n   \
    \ void execute(function<void(int)> &f,int k=1){\n        for(auto li:seg[k]){\n\
    \            lct.add(li.first,li.second);\n        }\n        if(k<sz){\n    \
    \        execute(f,2*k);\n            execute(f,2*k+1);\n        }\n        else\
    \ if(k-sz<query_size){\n            f(k-sz);\n        }\n        for(auto li:seg[k]){\n\
    \            assert(!lct.history.empty());\n            lct.undo();\n        }\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DeletableLiChaoTreeOffline.cpp
  requiredBy: []
  timestamp: '2021-01-17 06:04:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/DeletableLiChaoTreeOffline.cpp
layout: document
redirect_from:
- /library/DataStructure/DeletableLiChaoTreeOffline.cpp
- /library/DataStructure/DeletableLiChaoTreeOffline.cpp.html
title: DataStructure/DeletableLiChaoTreeOffline.cpp
---

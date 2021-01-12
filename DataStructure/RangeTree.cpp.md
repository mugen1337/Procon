---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/RangeTree.cpp\"\n// Range Tree (Weighted)\n\
    template<typename Tx,typename Ty,typename VAL=int>\nstruct RangeTree{\n    private:\n\
    \    vector<vector<Ty>> seg;\n    vector<vector<VAL>> sum;\n    vector<Tx> x;\n\
    \    int sz;\n\n    void build(vector<tuple<Tx,Ty,VAL>> &v){\n        sort(begin(v),end(v));\n\
    \        for(int i=0;i<(int)v.size();i++) x.push_back(get<0>(v[i]));\n       \
    \ x.erase(unique(begin(x),end(x)),end(x));\n        sz=1;\n        while((int)x.size()>sz)\
    \ sz<<=1;\n        while((int)x.size()<sz) x.push_back(numeric_limits<Tx>::max()/2);\n\
    \        seg.resize(sz*2);\n        sum.resize(sz*2);\n        int idx=0;\n  \
    \      for(auto [x_,y_,val]:v){\n            if(x[idx]!=x_) idx++;\n         \
    \   seg[idx+sz].push_back(y_);\n            sum[idx+sz].push_back(val);\n    \
    \    }\n        for(int i=sz-1;i>0;i--){\n            int l=0,r=0;\n         \
    \   while(l<(int)seg[2*i].size() or r<(int)seg[2*i+1].size()){\n             \
    \   bool f;\n                if(r>=(int)seg[2*i+1].size()) f=true;\n         \
    \       else if(l>=(int)seg[2*i].size()) f=false;\n                else if(seg[2*i][l]<seg[2*i+1][r])\
    \ f=true;\n                else f=false;\n                if(f){\n           \
    \         seg[i].push_back(seg[2*i][l]);\n                    sum[i].push_back(sum[2*i][l]);\n\
    \                    l++;\n                }else{\n                    seg[i].push_back(seg[2*i+1][r]);\n\
    \                    sum[i].push_back(sum[2*i+1][r]);\n                    r++;\n\
    \                }\n            }\n        }\n        for(int i=1;i<2*sz;i++){\n\
    \            vector<VAL> replace(1,0);\n            for(auto val:sum[i]) replace.push_back(replace.back()+val);\n\
    \            swap(sum[i],replace);\n        }\n    }\n    \n    public:\n    RangeTree(vector<pair<Tx,Ty>>\
    \ a){\n        vector<tuple<Tx,Ty,VAL>> v;\n        for(auto p:a) v.emplace_back(p.first,p.second,1);\n\
    \        build(v);\n    }\n    RangeTree(vector<tuple<Tx,Ty,VAL>> a){\n      \
    \  build(a);\n    }\n    // sum : [x1,x2),[y1,y2)\n    VAL query(Tx x1,Ty y1,Tx\
    \ x2,Ty y2){\n        int l=lower_bound(begin(x),end(x),x1)-begin(x),r=lower_bound(begin(x),end(x),x2)-begin(x);\n\
    \        l+=sz,r+=sz;\n        VAL ret=0;\n        for(;l<r;l>>=1,r>>=1){\n  \
    \          if(l&1){\n                int hi=lower_bound(begin(seg[l]),end(seg[l]),y2)-begin(seg[l]);\n\
    \                int lw=lower_bound(begin(seg[l]),end(seg[l]),y1)-begin(seg[l]);\n\
    \                ret+=sum[l][hi]-sum[l][lw];\n                l++;\n         \
    \   }\n            if(r&1){\n                r--;\n                int hi=lower_bound(begin(seg[r]),end(seg[r]),y2)-begin(seg[r]);\n\
    \                int lw=lower_bound(begin(seg[r]),end(seg[r]),y1)-begin(seg[r]);\n\
    \                ret+=sum[r][hi]-sum[r][lw];\n            }\n        }\n     \
    \   return ret;\n    }\n};\n"
  code: "// Range Tree (Weighted)\ntemplate<typename Tx,typename Ty,typename VAL=int>\n\
    struct RangeTree{\n    private:\n    vector<vector<Ty>> seg;\n    vector<vector<VAL>>\
    \ sum;\n    vector<Tx> x;\n    int sz;\n\n    void build(vector<tuple<Tx,Ty,VAL>>\
    \ &v){\n        sort(begin(v),end(v));\n        for(int i=0;i<(int)v.size();i++)\
    \ x.push_back(get<0>(v[i]));\n        x.erase(unique(begin(x),end(x)),end(x));\n\
    \        sz=1;\n        while((int)x.size()>sz) sz<<=1;\n        while((int)x.size()<sz)\
    \ x.push_back(numeric_limits<Tx>::max()/2);\n        seg.resize(sz*2);\n     \
    \   sum.resize(sz*2);\n        int idx=0;\n        for(auto [x_,y_,val]:v){\n\
    \            if(x[idx]!=x_) idx++;\n            seg[idx+sz].push_back(y_);\n \
    \           sum[idx+sz].push_back(val);\n        }\n        for(int i=sz-1;i>0;i--){\n\
    \            int l=0,r=0;\n            while(l<(int)seg[2*i].size() or r<(int)seg[2*i+1].size()){\n\
    \                bool f;\n                if(r>=(int)seg[2*i+1].size()) f=true;\n\
    \                else if(l>=(int)seg[2*i].size()) f=false;\n                else\
    \ if(seg[2*i][l]<seg[2*i+1][r]) f=true;\n                else f=false;\n     \
    \           if(f){\n                    seg[i].push_back(seg[2*i][l]);\n     \
    \               sum[i].push_back(sum[2*i][l]);\n                    l++;\n   \
    \             }else{\n                    seg[i].push_back(seg[2*i+1][r]);\n \
    \                   sum[i].push_back(sum[2*i+1][r]);\n                    r++;\n\
    \                }\n            }\n        }\n        for(int i=1;i<2*sz;i++){\n\
    \            vector<VAL> replace(1,0);\n            for(auto val:sum[i]) replace.push_back(replace.back()+val);\n\
    \            swap(sum[i],replace);\n        }\n    }\n    \n    public:\n    RangeTree(vector<pair<Tx,Ty>>\
    \ a){\n        vector<tuple<Tx,Ty,VAL>> v;\n        for(auto p:a) v.emplace_back(p.first,p.second,1);\n\
    \        build(v);\n    }\n    RangeTree(vector<tuple<Tx,Ty,VAL>> a){\n      \
    \  build(a);\n    }\n    // sum : [x1,x2),[y1,y2)\n    VAL query(Tx x1,Ty y1,Tx\
    \ x2,Ty y2){\n        int l=lower_bound(begin(x),end(x),x1)-begin(x),r=lower_bound(begin(x),end(x),x2)-begin(x);\n\
    \        l+=sz,r+=sz;\n        VAL ret=0;\n        for(;l<r;l>>=1,r>>=1){\n  \
    \          if(l&1){\n                int hi=lower_bound(begin(seg[l]),end(seg[l]),y2)-begin(seg[l]);\n\
    \                int lw=lower_bound(begin(seg[l]),end(seg[l]),y1)-begin(seg[l]);\n\
    \                ret+=sum[l][hi]-sum[l][lw];\n                l++;\n         \
    \   }\n            if(r&1){\n                r--;\n                int hi=lower_bound(begin(seg[r]),end(seg[r]),y2)-begin(seg[r]);\n\
    \                int lw=lower_bound(begin(seg[r]),end(seg[r]),y1)-begin(seg[r]);\n\
    \                ret+=sum[r][hi]-sum[r][lw];\n            }\n        }\n     \
    \   return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RangeTree.cpp
  requiredBy: []
  timestamp: '2021-01-12 16:40:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/RangeTree.cpp
layout: document
redirect_from:
- /library/DataStructure/RangeTree.cpp
- /library/DataStructure/RangeTree.cpp.html
title: DataStructure/RangeTree.cpp
---

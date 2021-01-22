---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp
    title: test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SegmentTree/SegmentTreeBeats.cpp\"\ntemplate<typename T>\n\
    struct SegmentTreeBeats{\n    private:\n\n    const T inf=numeric_limits<T>::max()/4;\n\
    \    vector<T> mx,smx,mxc,mi,smi,mic,sum,lval,ladd;\n    int sz;\n    // smx[k]<x<mx[k]\u306E\
    \u90E8\u5206\u306E\u66F4\u65B0\n    void update_node_max(int k,T x){\n       \
    \ sum[k]+=(x-mx[k])*mxc[k];\n        if(mx[k]==mi[k]) mx[k]=x,mi[k]=x;\n     \
    \   else if(mx[k]==smi[k]) mx[k]=x,smi[k]=x;\n        else mx[k]=x;\n        if(lval[k]!=inf\
    \ and x<lval[k]) lval[k]=x;\n    }\n    void update_node_min(int k,T x){\n   \
    \     sum[k]+=(x-mi[k])*mic[k];\n        if(mx[k]==mi[k]) mx[k]=x,mi[k]=x;\n \
    \       else if(smx[k]==mi[k]) smx[k]=x,mi[k]=x;\n        else mi[k]=x;\n    \
    \    if(lval[k]!=inf and lval[k]<x) lval[k]=x;\n    }\n    void update_node_add(int\
    \ k,int len,T x){\n        mx[k]+=x;\n        if(smx[k]!=-inf)smx[k]+=x;\n   \
    \     mi[k]+=x;\n        if(smi[k]!=inf) smi[k]+=x;\n        sum[k]+=x*T(len);\n\
    \        if(lval[k]!=inf)lval[k]+=x;\n        else            ladd[k]+=x;\n  \
    \  }\n    // \u9045\u5EF6\u5206\u3092\u51E6\u7406\uFF0Cnode-k\u306F\u4ECA\u306E\
    \u5024\uFF0C\u5B50\u306F\u53E4\u3044\u5024\u304B\u3082\u3057\u308C\u306A\u3044\
    \n    void push(int k,int len){\n        if(k>=sz) return ;\n        if(lval[k]!=inf){\n\
    \            update_all(2*k,len/2,lval[k]);\n            update_all(2*k+1,len/2,lval[k]);\n\
    \            lval[k]=inf;\n            return ;\n        }\n        if(ladd[k]!=0){\n\
    \            update_node_add(2*k,len/2,ladd[k]);\n            update_node_add(2*k+1,len/2,ladd[k]);\n\
    \            ladd[k]=0;\n        }\n        // \u5B50\u304C\u53E4\u3044\u5024\u306A\
    \u3089\u66F4\u65B0\uFF0E\u3053\u3053\u304C\u30DD\u30A4\u30F3\u30C8\n        if(mx[2*k]>mx[k])\
    \  update_node_max(2*k,mx[k]);\n        if(mx[2*k+1]>mx[k])update_node_max(2*k+1,mx[k]);\n\
    \        if(mi[2*k]<mi[k])  update_node_min(2*k,mi[k]);\n        if(mi[2*k+1]<mi[k])update_node_min(2*k+1,mi[k]);\n\
    \    }\n    // \u5B50\u304B\u3089node-k\u306E\u66F4\u65B0\n    void update_from_children(int\
    \ k){\n        sum[k]=sum[2*k]+sum[2*k+1];\n        if(mx[2*k]<mx[2*k+1]){\n \
    \           mx[k]=mx[2*k+1];mxc[k]=mxc[2*k+1];\n            smx[k]=max(mx[2*k],smx[2*k+1]);\n\
    \        }else if(mx[2*k]>mx[2*k+1]){\n            mx[k]=mx[2*k];mxc[k]=mxc[2*k];\n\
    \            smx[k]=max(smx[2*k],mx[2*k+1]);\n        }else{\n            mx[k]=mx[2*k];mxc[k]=mxc[2*k]+mxc[2*k+1];\n\
    \            smx[k]=max(smx[2*k],smx[2*k+1]);\n        }\n        if(mi[2*k]<mi[2*k+1]){\n\
    \            mi[k]=mi[2*k];mic[k]=mic[2*k];\n            smi[k]=min(smi[2*k],mi[2*k+1]);\n\
    \        }else if(mi[2*k]>mi[2*k+1]){\n            mi[k]=mi[2*k+1];mic[k]=mic[2*k+1];\n\
    \            smi[k]=min(mi[2*k],smi[2*k+1]);\n        }else{\n            mi[k]=mi[2*k];mic[k]=mic[2*k]+mic[2*k+1];\n\
    \            smi[k]=min(smi[2*k],smi[2*k+1]);\n        }\n    }\n    void update_all(int\
    \ k,int len,T x){\n        mx[k]=x,smx[k]=-inf,mi[k]=x,smi[k]=inf;\n        mxc[k]=len,mic[k]=len;\n\
    \        sum[k]=x*len;\n        lval[k]=x,ladd[k]=0;\n    }\n    \n    public:\n\
    \n    SegmentTreeBeats(int n){\n        sz=1;\n        while(sz<n)sz<<=1;\n  \
    \      mx.resize(2*sz,-inf);smx.resize(2*sz,-inf);mxc.resize(2*sz,0);\n      \
    \  mi.resize(2*sz,inf);smi.resize(2*sz,inf);mic.resize(2*sz,0);\n        sum.resize(2*sz,0);ladd.resize(2*sz,0);lval.resize(2*sz,inf);\n\
    \    }\n    void set(int k,T x){\n        mx[k+sz]=x;mxc[k+sz]=1;\n        mi[k+sz]=x;mic[k+sz]=1;\n\
    \        sum[k+sz]=x;\n    }\n    void build(){\n        for(int i=sz-1;i;i--)\
    \ update_from_children(i);\n    }\n    // [a,b)\u3092\u66F4\u65B0\uFF0C[l,r)\u63A2\
    \u7D22\u533A\u9593\uFF0Ck-node\n    void chmin(int a,int b,T x,int k=1,int l=0,int\
    \ r=-1){\n        if(r==-1) r=sz;\n        if(r<=a or b<=l or mx[k]<=x) return\
    \ ;\n        if(a<=l and r<=b and smx[k]<x){\n            update_node_max(k,x);\n\
    \            return ;\n        }\n        push(k,r-l);\n        chmin(a,b,x,2*k,l,(l+r)/2);\n\
    \        chmin(a,b,x,2*k+1,(l+r)/2,r);\n        update_from_children(k);\n   \
    \ }\n    void chmax(int a,int b,T x,int k=1,int l=0,int r=-1){\n        if(r==-1)\
    \ r=sz;\n        if(r<=a or b<=l or mi[k]>=x) return ;\n        if(a<=l and r<=b\
    \ and smi[k]>x){\n            update_node_min(k,x);\n            return ;\n  \
    \      }\n        push(k,r-l);\n        chmax(a,b,x,2*k,l,(l+r)/2);\n        chmax(a,b,x,2*k+1,(l+r)/2,r);\n\
    \        update_from_children(k);\n    }\n    void add(int a,int b,T x,int k=1,int\
    \ l=0,int r=-1){\n        if(r==-1) r=sz;\n        if(r<=a or b<=l) return ;\n\
    \        if(a<=l and r<=b){\n            update_node_add(k,r-l,x);\n         \
    \   return ;\n        }\n        push(k,r-l);\n        add(a,b,x,2*k,l,(l+r)/2);\n\
    \        add(a,b,x,2*k+1,(l+r)/2,r);\n        update_from_children(k);\n    }\n\
    \    void update(int a,int b,T x,int k=1,int l=0,int r=-1){\n        if(r==-1)r=sz;\n\
    \        if(r<=a or b<=l) return ;\n        if(a<=l and r<=b){\n            update_all(k,r-l,x);\n\
    \            return ;\n        }\n        push(k,r-l);\n        update(a,b,x,2*k,l,(l+r)/2);\n\
    \        update(a,b,x,2*k+1,(l+r)/2,r);\n        update_from_children(k);\n  \
    \  }\n    T query_sum(int a,int b,int k=1,int l=0,int r=-1){\n        if(r==-1)r=sz;\n\
    \        if(r<=a or b<=l)return 0;\n        if(a<=l and r<=b) return sum[k];\n\
    \        push(k,r-l);\n        T lsum=query_sum(a,b,2*k,l,(l+r)/2);\n        T\
    \ rsum=query_sum(a,b,2*k+1,(l+r)/2,r);\n        return lsum+rsum;\n    }\n   \
    \ T query_min(int a,int b,int k=1,int l=0,int r=-1){\n        if(r==-1)r=sz;\n\
    \        if(b<=l or r<=a) return inf;\n        if(a<=l and r<=b) return mi[k];\n\
    \        push(k,r-l);\n        T lmin=query_min(a,b,2*k,l,(l+r)/2);\n        T\
    \ rmin=query_min(a,b,2*k+1,(l+r)/2,r);\n        return min(lmin,rmin);\n    }\n\
    \    T query_max(int a,int b,int k=1,int l=0,int r=-1){\n        if(r==-1)r=sz;\n\
    \        if(b<=l or r<=a) return -inf;\n        if(a<=l and r<=b) return mx[k];\n\
    \        push(k,r-l);\n        T lmax=query_max(a,b,2*k,l,(l+r)/2);\n        T\
    \ rmax=query_max(a,b,2*k+1,(l+r)/2,r);\n        return max(lmax,rmax);\n    }\n\
    };\n"
  code: "template<typename T>\nstruct SegmentTreeBeats{\n    private:\n\n    const\
    \ T inf=numeric_limits<T>::max()/4;\n    vector<T> mx,smx,mxc,mi,smi,mic,sum,lval,ladd;\n\
    \    int sz;\n    // smx[k]<x<mx[k]\u306E\u90E8\u5206\u306E\u66F4\u65B0\n    void\
    \ update_node_max(int k,T x){\n        sum[k]+=(x-mx[k])*mxc[k];\n        if(mx[k]==mi[k])\
    \ mx[k]=x,mi[k]=x;\n        else if(mx[k]==smi[k]) mx[k]=x,smi[k]=x;\n       \
    \ else mx[k]=x;\n        if(lval[k]!=inf and x<lval[k]) lval[k]=x;\n    }\n  \
    \  void update_node_min(int k,T x){\n        sum[k]+=(x-mi[k])*mic[k];\n     \
    \   if(mx[k]==mi[k]) mx[k]=x,mi[k]=x;\n        else if(smx[k]==mi[k]) smx[k]=x,mi[k]=x;\n\
    \        else mi[k]=x;\n        if(lval[k]!=inf and lval[k]<x) lval[k]=x;\n  \
    \  }\n    void update_node_add(int k,int len,T x){\n        mx[k]+=x;\n      \
    \  if(smx[k]!=-inf)smx[k]+=x;\n        mi[k]+=x;\n        if(smi[k]!=inf) smi[k]+=x;\n\
    \        sum[k]+=x*T(len);\n        if(lval[k]!=inf)lval[k]+=x;\n        else\
    \            ladd[k]+=x;\n    }\n    // \u9045\u5EF6\u5206\u3092\u51E6\u7406\uFF0C\
    node-k\u306F\u4ECA\u306E\u5024\uFF0C\u5B50\u306F\u53E4\u3044\u5024\u304B\u3082\
    \u3057\u308C\u306A\u3044\n    void push(int k,int len){\n        if(k>=sz) return\
    \ ;\n        if(lval[k]!=inf){\n            update_all(2*k,len/2,lval[k]);\n \
    \           update_all(2*k+1,len/2,lval[k]);\n            lval[k]=inf;\n     \
    \       return ;\n        }\n        if(ladd[k]!=0){\n            update_node_add(2*k,len/2,ladd[k]);\n\
    \            update_node_add(2*k+1,len/2,ladd[k]);\n            ladd[k]=0;\n \
    \       }\n        // \u5B50\u304C\u53E4\u3044\u5024\u306A\u3089\u66F4\u65B0\uFF0E\
    \u3053\u3053\u304C\u30DD\u30A4\u30F3\u30C8\n        if(mx[2*k]>mx[k])  update_node_max(2*k,mx[k]);\n\
    \        if(mx[2*k+1]>mx[k])update_node_max(2*k+1,mx[k]);\n        if(mi[2*k]<mi[k])\
    \  update_node_min(2*k,mi[k]);\n        if(mi[2*k+1]<mi[k])update_node_min(2*k+1,mi[k]);\n\
    \    }\n    // \u5B50\u304B\u3089node-k\u306E\u66F4\u65B0\n    void update_from_children(int\
    \ k){\n        sum[k]=sum[2*k]+sum[2*k+1];\n        if(mx[2*k]<mx[2*k+1]){\n \
    \           mx[k]=mx[2*k+1];mxc[k]=mxc[2*k+1];\n            smx[k]=max(mx[2*k],smx[2*k+1]);\n\
    \        }else if(mx[2*k]>mx[2*k+1]){\n            mx[k]=mx[2*k];mxc[k]=mxc[2*k];\n\
    \            smx[k]=max(smx[2*k],mx[2*k+1]);\n        }else{\n            mx[k]=mx[2*k];mxc[k]=mxc[2*k]+mxc[2*k+1];\n\
    \            smx[k]=max(smx[2*k],smx[2*k+1]);\n        }\n        if(mi[2*k]<mi[2*k+1]){\n\
    \            mi[k]=mi[2*k];mic[k]=mic[2*k];\n            smi[k]=min(smi[2*k],mi[2*k+1]);\n\
    \        }else if(mi[2*k]>mi[2*k+1]){\n            mi[k]=mi[2*k+1];mic[k]=mic[2*k+1];\n\
    \            smi[k]=min(mi[2*k],smi[2*k+1]);\n        }else{\n            mi[k]=mi[2*k];mic[k]=mic[2*k]+mic[2*k+1];\n\
    \            smi[k]=min(smi[2*k],smi[2*k+1]);\n        }\n    }\n    void update_all(int\
    \ k,int len,T x){\n        mx[k]=x,smx[k]=-inf,mi[k]=x,smi[k]=inf;\n        mxc[k]=len,mic[k]=len;\n\
    \        sum[k]=x*len;\n        lval[k]=x,ladd[k]=0;\n    }\n    \n    public:\n\
    \n    SegmentTreeBeats(int n){\n        sz=1;\n        while(sz<n)sz<<=1;\n  \
    \      mx.resize(2*sz,-inf);smx.resize(2*sz,-inf);mxc.resize(2*sz,0);\n      \
    \  mi.resize(2*sz,inf);smi.resize(2*sz,inf);mic.resize(2*sz,0);\n        sum.resize(2*sz,0);ladd.resize(2*sz,0);lval.resize(2*sz,inf);\n\
    \    }\n    void set(int k,T x){\n        mx[k+sz]=x;mxc[k+sz]=1;\n        mi[k+sz]=x;mic[k+sz]=1;\n\
    \        sum[k+sz]=x;\n    }\n    void build(){\n        for(int i=sz-1;i;i--)\
    \ update_from_children(i);\n    }\n    // [a,b)\u3092\u66F4\u65B0\uFF0C[l,r)\u63A2\
    \u7D22\u533A\u9593\uFF0Ck-node\n    void chmin(int a,int b,T x,int k=1,int l=0,int\
    \ r=-1){\n        if(r==-1) r=sz;\n        if(r<=a or b<=l or mx[k]<=x) return\
    \ ;\n        if(a<=l and r<=b and smx[k]<x){\n            update_node_max(k,x);\n\
    \            return ;\n        }\n        push(k,r-l);\n        chmin(a,b,x,2*k,l,(l+r)/2);\n\
    \        chmin(a,b,x,2*k+1,(l+r)/2,r);\n        update_from_children(k);\n   \
    \ }\n    void chmax(int a,int b,T x,int k=1,int l=0,int r=-1){\n        if(r==-1)\
    \ r=sz;\n        if(r<=a or b<=l or mi[k]>=x) return ;\n        if(a<=l and r<=b\
    \ and smi[k]>x){\n            update_node_min(k,x);\n            return ;\n  \
    \      }\n        push(k,r-l);\n        chmax(a,b,x,2*k,l,(l+r)/2);\n        chmax(a,b,x,2*k+1,(l+r)/2,r);\n\
    \        update_from_children(k);\n    }\n    void add(int a,int b,T x,int k=1,int\
    \ l=0,int r=-1){\n        if(r==-1) r=sz;\n        if(r<=a or b<=l) return ;\n\
    \        if(a<=l and r<=b){\n            update_node_add(k,r-l,x);\n         \
    \   return ;\n        }\n        push(k,r-l);\n        add(a,b,x,2*k,l,(l+r)/2);\n\
    \        add(a,b,x,2*k+1,(l+r)/2,r);\n        update_from_children(k);\n    }\n\
    \    void update(int a,int b,T x,int k=1,int l=0,int r=-1){\n        if(r==-1)r=sz;\n\
    \        if(r<=a or b<=l) return ;\n        if(a<=l and r<=b){\n            update_all(k,r-l,x);\n\
    \            return ;\n        }\n        push(k,r-l);\n        update(a,b,x,2*k,l,(l+r)/2);\n\
    \        update(a,b,x,2*k+1,(l+r)/2,r);\n        update_from_children(k);\n  \
    \  }\n    T query_sum(int a,int b,int k=1,int l=0,int r=-1){\n        if(r==-1)r=sz;\n\
    \        if(r<=a or b<=l)return 0;\n        if(a<=l and r<=b) return sum[k];\n\
    \        push(k,r-l);\n        T lsum=query_sum(a,b,2*k,l,(l+r)/2);\n        T\
    \ rsum=query_sum(a,b,2*k+1,(l+r)/2,r);\n        return lsum+rsum;\n    }\n   \
    \ T query_min(int a,int b,int k=1,int l=0,int r=-1){\n        if(r==-1)r=sz;\n\
    \        if(b<=l or r<=a) return inf;\n        if(a<=l and r<=b) return mi[k];\n\
    \        push(k,r-l);\n        T lmin=query_min(a,b,2*k,l,(l+r)/2);\n        T\
    \ rmin=query_min(a,b,2*k+1,(l+r)/2,r);\n        return min(lmin,rmin);\n    }\n\
    \    T query_max(int a,int b,int k=1,int l=0,int r=-1){\n        if(r==-1)r=sz;\n\
    \        if(b<=l or r<=a) return -inf;\n        if(a<=l and r<=b) return mx[k];\n\
    \        push(k,r-l);\n        T lmax=query_max(a,b,2*k,l,(l+r)/2);\n        T\
    \ rmax=query_max(a,b,2*k+1,(l+r)/2,r);\n        return max(lmax,rmax);\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/SegmentTreeBeats.cpp
  requiredBy: []
  timestamp: '2021-01-03 23:38:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp
documentation_of: SegmentTree/SegmentTreeBeats.cpp
layout: document
redirect_from:
- /library/SegmentTree/SegmentTreeBeats.cpp
- /library/SegmentTree/SegmentTreeBeats.cpp.html
title: SegmentTree/SegmentTreeBeats.cpp
---

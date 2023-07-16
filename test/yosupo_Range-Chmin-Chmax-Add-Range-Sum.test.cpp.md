---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/SegmentTreeBeats.hpp
    title: Segment Tree Beats
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define ALL(x) begin(x),end(x)\n#define rep(i,n) for(int i=0;i<(n);i++)\n#define\
    \ debug(v) cout<<#v<<\":\";for(auto x:v){cout<<x<<' ';}cout<<endl;\n#define mod\
    \ 1000000007\nusing ll=long long;\nconst int INF=1000000000;\nconst ll LINF=1001002003004005006ll;\n\
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1};\n// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}\n\
    template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}\n\
    template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}\n\
    \nstruct IOSetup{\n    IOSetup(){\n        cin.tie(0);\n        ios::sync_with_stdio(0);\n\
    \        cout<<fixed<<setprecision(12);\n    }\n} iosetup;\n \ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const vector<T>&v){\n    for(int i=0;i<(int)v.size();i++)\
    \ os<<v[i]<<(i+1==(int)v.size()?\"\":\" \");\n    return os;\n}\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is,vector<T>&v){\n    for(T &x:v)is>>x;\n \
    \   return is;\n}\n\n#line 4 \"test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp\"\
    \n\n#line 1 \"SegmentTree/SegmentTreeBeats.hpp\"\ntemplate<typename T>\nstruct\
    \ SegmentTreeBeats{\n    private:\n\n    const T inf=numeric_limits<T>::max()/4;\n\
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
    };\n#line 6 \"test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp\"\n\nsigned\
    \ main(){\n    int n,q;cin>>n>>q;\n    SegmentTreeBeats<ll> seg(n);\n    rep(i,n){\n\
    \        ll a;cin>>a;seg.set(i,a);\n    }\n    seg.build();\n    while(q--){\n\
    \        int t,l,r;cin>>t>>l>>r;\n        if(t==0){\n            ll b;cin>>b;\n\
    \            seg.chmin(l,r,b);\n        }else if(t==1){\n            ll b;cin>>b;\n\
    \            seg.chmax(l,r,b);\n        }else if(t==2){\n            ll b;cin>>b;\n\
    \            seg.add(l,r,b);\n        }else{\n            cout<<seg.query_sum(l,r)<<endl;\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include \"../template.hpp\"\n\n#include \"../SegmentTree/SegmentTreeBeats.hpp\"\
    \n\nsigned main(){\n    int n,q;cin>>n>>q;\n    SegmentTreeBeats<ll> seg(n);\n\
    \    rep(i,n){\n        ll a;cin>>a;seg.set(i,a);\n    }\n    seg.build();\n \
    \   while(q--){\n        int t,l,r;cin>>t>>l>>r;\n        if(t==0){\n        \
    \    ll b;cin>>b;\n            seg.chmin(l,r,b);\n        }else if(t==1){\n  \
    \          ll b;cin>>b;\n            seg.chmax(l,r,b);\n        }else if(t==2){\n\
    \            ll b;cin>>b;\n            seg.add(l,r,b);\n        }else{\n     \
    \       cout<<seg.query_sum(l,r)<<endl;\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - SegmentTree/SegmentTreeBeats.hpp
  isVerificationFile: true
  path: test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp
- /verify/test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp.html
title: test/yosupo_Range-Chmin-Chmax-Add-Range-Sum.test.cpp
---

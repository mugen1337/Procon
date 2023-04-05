#define PROBLEM "https://yukicoder.me/problems/899"

#include "../template.hpp"

#include "../SegmentTree/LazySegmentTree.hpp"

// range set range min
using M=ll;
using OM=ll;
const M M1=LINF;
const OM OM0=-LINF;
M segf(M a,M b){
    return (a<b?a:b);
}
M segg(M a,OM b){
    return (b==OM0?a:b);
}
OM segh(OM a,OM b){
    return (b==OM0?a:b);
}

signed main(){
    int n;cin>>n;
    map<int,int> l,r;
    set<int> st;
    
    rep(i,n){
        int x;cin>>x;
        st.insert(x);
        if(!l.count(x)) l[x]=i;
        else l[x]=min(l[x],i);
        if(!r.count(x)) r[x]=i;
        else r[x]=max(r[x],i);
    }

    LazySegmentTree<M,OM> seg(n,segf,segg,segh,M1,OM0);
    seg.build();
    for(auto x:st) seg.update(l[x],r[x]+1,x);
    rep(i,n)cout<<seg[i]<<(i+1==n?"\n":" ");
    return 0;
}
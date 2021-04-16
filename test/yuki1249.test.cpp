#define PROBLEM "https://yukicoder.me/problems/1249"

#include "../template.cpp"

#include "../Graph2/HeavyLightDecomposition.cpp"

#include "../SegmentTree/LazySegmentTree.cpp"

using M=pair<ll,ll>;
using OM=ll;
const M M1=M(0,0);
const OM OM0=0;
M segf(M a,M b){
    return M(a.first+b.first,a.second+b.second);
}
M segg(M a,OM b){
    return M(a.first+a.second*b,a.second);
}
ll segh(ll a,ll b){
    return a+b;
}


signed main(){
    int n;cin>>n;
    Graph<int> g(n);
    rep(i,n-1){
        int u,v;cin>>u>>v;u--,v--;
        g.add_edge(u,v);
    }
    HeavyLightDecomposition<int> hld(g);
    LazySegmentTree<M,OM> seg(n,segf,segg,segh,M1,OM0);
    rep(i,n) seg.set(i,{0,1});
    seg.build();
    
    int q;cin>>q;
    ll res=0;
    while(q--){
        int u,v;cin>>u>>v;u--,v--;
        for(auto [l,r]:hld.get_path(u,v)){
            seg.update(l,r,1);
            res+=seg.query(l,r).first;
        }
    }
    cout<<res<<endl;
    return 0;
}

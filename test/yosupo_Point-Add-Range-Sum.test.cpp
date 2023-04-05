#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../template.hpp"

#include "../SegmentTree/SegmentTree.hpp"

signed main(){
    int n,q;cin>>n>>q;

    auto segfunc=[](ll a,ll b){
        return a+b;
    };
    
    SegmentTree<ll> seg(n,segfunc,0);
    rep(i,n){
        ll a;cin>>a;
        seg.set(i,a);
    }
    seg.build();

    for(;q--;){
        int type;cin>>type;
        if(type==0){
            int p;ll x;cin>>p>>x;
            seg.update(p,seg.query(p,p+1)+x);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<seg.query(l,r)<<endl;
        }
    }
    return 0;
}
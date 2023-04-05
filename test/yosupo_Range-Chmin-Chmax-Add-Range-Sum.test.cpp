#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "../template.hpp"

#include "../SegmentTree/SegmentTreeBeats.hpp"

signed main(){
    int n,q;cin>>n>>q;
    SegmentTreeBeats<ll> seg(n);
    rep(i,n){
        ll a;cin>>a;seg.set(i,a);
    }
    seg.build();
    while(q--){
        int t,l,r;cin>>t>>l>>r;
        if(t==0){
            ll b;cin>>b;
            seg.chmin(l,r,b);
        }else if(t==1){
            ll b;cin>>b;
            seg.chmax(l,r,b);
        }else if(t==2){
            ll b;cin>>b;
            seg.add(l,r,b);
        }else{
            cout<<seg.query_sum(l,r)<<endl;
        }
    }
    return 0;
}
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../template.hpp"

#include "../DataStructure/RangeTree.hpp"

signed main(){
    int n,q;cin>>n>>q;
    vector<tuple<int,int,ll>> v;
    rep(i,n){
        int x,y;ll w;cin>>x>>y>>w;
        v.emplace_back(x,y,w);
    }

    RangeTree<int,int,ll> seg(v);


    while(q--){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        cout<<seg.query(x1,y1,x2,y2)<<"\n";
    }

    return 0;
}
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "../template.cpp"

#include "../BinarySearchTree/ImplicitTreap.cpp"

#include "../type/modint.cpp"
using mint=ModInt<mod>;

using M=pair<mint,mint>;
using OM=pair<mint,mint>;
const M M1=M(0,0);
const OM OM0=OM(1,0);
M segf(M a,M b){
    return M(a.first+b.first,a.second+b.second);
}
M segg(M a,OM b){
    return M(a.first*b.first+a.second*b.second,a.second);
}
OM segh(OM a,OM b){
    return OM(a.first*b.first,a.second*b.first+b.second);
}

signed main(){
    int n,q;cin>>n>>q;
    vector<mint> a(n);
    cin>>a;
    ImplicitTreap<M,OM> seg(segf,segg,segh,M1,OM0);
    reverse(ALL(a));
    for(auto x:a) seg.insert(0,{x,1});

    while(q--){
        int t;cin>>t;
        if(t==0){
            int i;mint x;cin>>i>>x;
            seg.insert(i,{x,1});
        }else if(t==1){
            int i;cin>>i;
            seg.erase(i);
        }else if(t==2){
            int l,r;cin>>l>>r;
            seg.reverse(l,r);
        }else if(t==3){
            int l,r;mint b,c;cin>>l>>r>>b>>c;
            seg.update(l,r,{b,c});
        }else{
            int l,r;cin>>l>>r;
            cout<<seg.query(l,r).first<<endl;
        }
    }
    return 0;
}
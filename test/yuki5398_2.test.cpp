#define PROBLEM "https://yukicoder.me/problems/5398"

#include "../template.hpp"

#include "../BinarySearchTree/SplayTree.hpp"

signed main(){
    int n,q;cin>>n>>q;
    SplayTree<ll> splay([](ll a,ll b){return a+b;},0);

    vector<ll> a(n);
    cin>>a;

    auto t=splay.build(a);

    while(q--){
        int type;cin>>type;
        if(type==1){
            int l,r;cin>>l>>r;
            l--;
            ll sum=splay.query(t,l,r);
            auto x=splay.split(t,l);
            auto y=splay.split(x.second,r-l);
            x.first=splay.push_back(x.first,sum);
            t=splay.merge(x.first,y.second);
        }else{
            int l,r;cin>>l>>r;l--;
            cout<<splay.query(t,l,r)<<endl;
        }
    }
    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "../template.hpp"

#include "../DataStructure/SlidingWindowAgregation.hpp"


signed main(){    
    auto swagfunc=[](pair<ll,ll> p1,pair<ll,ll> p2){
        return make_pair(p1.first*p2.first%998244353,(p2.first*p1.second%998244353+p2.second)%998244353);
    };

    SWAG<pair<ll,ll>> que(swagfunc,make_pair(1ll,0ll));

    int q;cin>>q;
    while(q--){
        int t;cin>>t;
        if(t==0){
            ll a,b;cin>>a>>b;
            que.push(make_pair(a,b));
        }else if(t==1){
            que.pop();
        }else{
            ll x;cin>>x;
            auto p=que.get();
            cout<<(p.first*x%998244353+p.second)%998244353<<endl;
        }
    }
    return 0;
}
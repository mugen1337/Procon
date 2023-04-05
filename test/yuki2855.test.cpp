#define PROBLEM "https://yukicoder.me/problems/2855"

#include "../template.hpp"

#include "../Math/Sieve.hpp"

signed main(){
    int n;cin>>n;
    auto isp=sieve(n);
    vector<ll> ps;
    for(int i=2;i<=n;i++)if(isp[i])ps.push_back(i);
    set<ll> r2;
    rep(i,(int)ps.size()) r2.insert(ps[i]*ps[i]);
    int ans=0;
    for(auto x:ps){
        if(r2.count(2+x)){
            ans+=2;
            if(x==2) ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}

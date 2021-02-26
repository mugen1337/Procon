#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include "./template.cpp"

#include "../Math/log_mod.cpp"

void solve(){
    ll a,b,m;cin>>a>>b>>m;
    ll k=log_mod(a,b,m);
    cout<<k<<endl;
    // cout<<"a^res "<<pow_mod(a,k,m)<<" =? "<<b<<endl;
}

signed main(){
    int q;cin>>q;
    while(q--) solve();
    return 0;
}
#define PROBLEM "https://yukicoder.me/problems/447"

#include "../Math/Garner.cpp"

signed main(){

    vector<ll> r(3),m(3);
    rep(i,3) cin>>r[i]>>m[i];

    auto p=Garner(r,m);
    if(p.second==0) cout<<-1<<endl;
    else if(p.first==0) cout<<p.second<<endl;
    else cout<<p.first<<endl;
    return 0;
}

#define PROBLEM "https://yukicoder.me/problems/2600"

#include "../template.hpp"

#include "../DataStructure/AbsoluteSum.hpp"


signed main(){
    int n;cin>>n;
    vector<ll> v(n);
    cin>>v;

    sort(ALL(v));

    if(v[0]==v.back()){
        cout<<1<<endl;
        return 0;
    }

    AbsoluteSum<ll> f;

    vector<ll> dp(n,0);
    rep(i,n){
        f.insert(v[i]);
        dp[i]=f.min();
    }

    rep(i,n){
        f.erase(v[i]);
        dp[i]+=f.min();
    }
    cout<<*min_element(ALL(dp))<<endl;
    return 0;
}

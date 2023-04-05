#define PROBLEM "https://yukicoder.me/problems/1948"

#include "../template.hpp"

#include "../DataStructure/LiChaoTree.hpp"

signed main(){
    int n;cin>>n;
    vector<ll> a(n),x(n),y(n);
    cin>>a>>x>>y;


    vector<ll> dp(n+1,0);
    dp[0]=0;

    LiChaoTree<ll> seg(a,LINF);
    seg.add(-2*x[0],dp[0]+x[0]*x[0]+y[0]*y[0]);

    rep(i,n){
        dp[i+1]=seg.query(a[i])+a[i]*a[i];
        if(i<n-1)seg.add(-2*x[i+1],dp[i+1]+x[i+1]*x[i+1]+y[i+1]*y[i+1]);
    }
    cout<<dp[n]<<endl;
    return 0;
}

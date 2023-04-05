#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1379"

#include "../template.hpp"

#include "../Other/EnumerateSubset.hpp"

signed main(){
    int n;cin>>n;
    vector<int> x(n),y(n);
    rep(i,n) cin>>x[i]>>y[i];

    auto isParallel=[&](int li,int lj,int ri,int rj){
        int xl=x[li]-x[lj],yl=y[li]-y[lj];
        int xr=x[ri]-x[rj],yr=y[ri]-y[rj];
        return xl*yr==xr*yl;
    };
    auto func_c=[&](int t){
        return t*(t-1)/2;
    };

    vector<ll> dp(1<<n,0);
    for(int bit=0;bit<(1<<n);bit++)if(__builtin_popcount(bit)%2==0){
        bool f=false;
        rep(a,n)if((bit>>a)&1 and !f){
            for(int b=a+1;b<n;b++)if((bit>>b)&1){
                vector<bool> check(n,true);
                check[a]=false;check[b]=false;
                for(int c=0;c<n;c++)if(((bit>>c)&1) and check[c]){
                    for(int d=c+1;d<n;d++)if(((bit>>d)&1) and check[d]){
                        if(isParallel(a,b,c,d)){
                            check[c]=false;
                            check[d]=false;
                        }
                    }
                }
                bool tmp=true;
                rep(i,n)if((bit>>i)&1)if(check[i]) tmp=false;
                if(tmp) f=true;
            }
        }
        if(f) dp[bit]=func_c(__builtin_popcount(bit)/2);
    }

    for(int bit=0;bit<(1<<n);bit++){
        for(auto x:enumerate_subset(bit)) chmax(dp[bit],dp[x]+dp[bit^x]);
    }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}

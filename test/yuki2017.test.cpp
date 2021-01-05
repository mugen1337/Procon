#define PROBLEM "https://yukicoder.me/problems/2017"

#include "../template.cpp"

#include "../type/modint.cpp"
#include "../Math/Precalc.cpp"
#include "../Math/FormalPowerSeriesNaive.cpp"

using mint=ModInt<1000000007>;
Precalc<mint> F(500000);
using FPS=FormalPowerSeriesNaive<mint>;

signed main(){
    int n,k;cin>>n>>k;
    rep(i,n){int a;cin>>a;}

    FPS p{1};
    rep(i,n) p-=(p<<(i+1));

    mint res=0;
    rep(i,k+1) res+=p[i]*F.com(k+n-i,n);
    cout<<res<<endl;
    return 0;
}
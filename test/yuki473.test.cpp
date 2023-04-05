#define PROBLEM "https://yukicoder.me/problems/473"

#include "../template.hpp"

#include "../type/modint.hpp"

using mint=ModInt<1000000007>;

#include "../Math/FormalPowerSeriesNaive.hpp"

using FPS=FormalPowerSeriesNaive<mint>;

signed main(){
    int n,s,k;cin>>n>>s>>k;
    s-=n*(n-1)/2*k;
    if(s<0){
        cout<<0<<endl;
        return 0;
    }

    FPS den{1},num{1};
    for(int i=1;i<=n;i++) den-=(den<<i);
    cout<<num.nth_term(den,s)<<endl;
    return 0;
}
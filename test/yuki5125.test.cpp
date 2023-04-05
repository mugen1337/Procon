#define PROBLEM "https://yukicoder.me/problems/5125"

#include "../template.hpp"

#include "../Other/CyclePartition.hpp"

#include "../type/modint.hpp"

#include "../Math/Precalc.hpp"

using mint=ModInt<998244353>;
Precalc<mint> F(500000);

signed main(){
    int n,m;cin>>n>>m;
    vector<int> p(n);
    cin>>p;
    for(auto &x:p) x--;
    auto cyc=cycle_partition(p);
    vector<int> v;
    for(auto &w:cyc) v.emplace_back(w.size());

    // x色以下を使う, dp[i]:=i個の玉を使った数珠の作り方
    auto f=[&](int x){
        vector<mint> a(n+1,0),b(n+1,0),ret(n+1,0);
        b[1]=x;
        for(int i=1;i<n;i++){
            a[i+1]=a[i]*(x-2)+b[i]*(x-1);
            b[i+1]=a[i];
        }
        return a;
    };

    mint res=0;
    for(int i=m;i>=1;i--){
        auto w=f(i);
        mint add=F.com(m,i);
        for(auto sz:v) add*=w[sz];
        if((m-i)%2) res-=add;
        else        res+=add;
    }
    cout<<res/F.fac(m)<<endl;
    return 0;
}
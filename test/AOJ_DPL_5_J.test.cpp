#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J"

#include "../template.hpp"

#include "../type/modint.hpp"

#include "../Math/Precalc.hpp"

using mint=ModInt<1000000007>;

Precalc<mint> F(500000);

/*
玉: 区別しない
箱: 区別しない
入れ方: 制限なし

分割数: https://ja.wikipedia.org/wiki/%E5%88%86%E5%89%B2%E6%95%B0
P(n,n) -> O(n sqrt(n)) : http://degwer.hatenablog.com/entries/2017/08/29
*/

signed main(){
    int n,k;cin>>n>>k;
    // auto table=F.partition_function_table(n,k);
    // rep(i,n+1){
    //     rep(j,k+1){
    //         cout<<table[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<F.partition_function(n,k)<<endl;
    return 0;
}
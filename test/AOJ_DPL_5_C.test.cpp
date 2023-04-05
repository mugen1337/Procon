#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_C"

#include "../template.hpp"

#include "../type/modint.hpp"

#include "../Math/Precalc.hpp"

using mint=ModInt<1000000007>;

Precalc<mint> F(500000);

/*
玉: 区別
箱: 区別
入れ方: 箱ごと1個以下
*/

signed main(){
    int n,k;cin>>n>>k;
    if(n<k) cout<<0<<endl;
    else cout<<F.F12_dis_dis_one(n,k)<<endl;
    return 0;
}
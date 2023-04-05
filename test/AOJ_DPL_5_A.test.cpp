#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A"

#include "../template.hpp"

#include "../type/modint.hpp"

#include "../Math/Precalc.hpp"

using mint=ModInt<1000000007>;

Precalc<mint> F(500000);

/*
玉: 区別
箱: 区別
入れ方: 制限無し
*/

signed main(){
    int n,k;cin>>n>>k;
    cout<<mint(k).pow(n)<<endl;
    return 0;
}
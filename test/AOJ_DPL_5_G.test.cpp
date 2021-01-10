#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G"

#include "../template.cpp"

#include "../type/modint.cpp"

#include "../Math/Precalc.cpp"

using mint=ModInt<1000000007>;

Precalc<mint> F(500000);

/*
玉: 区別する
箱: 区別しない
入れ方: 制限なし

ベル数
https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E6%95%B0
*/

signed main(){
    int n,k;cin>>n>>k;
    cout<<F.Bell_number(n,k)<<endl;
    return 0;
}
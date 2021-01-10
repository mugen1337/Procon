#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D"

#include "../template.cpp"

#include "../type/modint.cpp"

#include "../Math/Precalc.cpp"

using mint=ModInt<1000000007>;

Precalc<mint> F(500000);

/*
玉: 区別しない
箱: 区別
入れ方: 制限なし
*/

signed main(){
    int n,k;cin>>n>>k;
    cout<<F.com(n+k-1,k-1)<<endl;
    return 0;
}
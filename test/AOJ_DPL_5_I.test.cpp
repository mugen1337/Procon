#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I"

#include "../template.cpp"

#include "../type/modint.cpp"

#include "../Math/Precalc.cpp"

using mint=ModInt<1000000007>;

Precalc<mint> F(500000);

/*
玉: 区別する
箱: 区別しない
入れ方: 箱ごと1つ以上
*/

signed main(){
    int n,k;cin>>n>>k;
    cout<<F.Stirling_number(n,k)<<endl;
    return 0;
}
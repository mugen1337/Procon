#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_K"

#include "../template.cpp"

#include "../type/modint.cpp"

#include "../Math/Precalc.cpp"

using mint=ModInt<1000000007>;

Precalc<mint> F(500000);

/*
玉: 区別しない
箱: 区別しない
入れ方: 箱ごと1個以下
*/

signed main(){
    int n,k;cin>>n>>k;
    cout<<(n<=k)<<endl;
    return 0;
}
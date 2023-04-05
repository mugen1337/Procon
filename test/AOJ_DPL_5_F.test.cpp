#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_F"

#include "../template.hpp"

#include "../type/modint.hpp"

#include "../Math/Precalc.hpp"

using mint=ModInt<1000000007>;

Precalc<mint> F(500000);

/*
玉: 区別しない
箱: 区別
入れ方: 箱ごと1個以上

箱に最初1個ずつ入れて，入れ方制限無しを解く
*/

signed main(){
    int n,k;cin>>n>>k;
    cout<<F.com(n-k+k-1,k-1)<<endl;
    return 0;
}
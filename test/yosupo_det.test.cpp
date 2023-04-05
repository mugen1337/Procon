#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../template.hpp"

#include "../type/modint.hpp"
using mint=ModInt<998244353>;

#include "../type/Matrix.hpp"

signed main(){
    int n;cin>>n;
    Matrix<mint> mat(n);
    rep(i,n)rep(j,n) cin>>mat[i][j];
    cout<<mat.det()<<endl;
    return 0;
}

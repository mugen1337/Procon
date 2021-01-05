#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../template.cpp"

#include "../type/modint.cpp"
using mint=ModInt<998244353>;

#include "../type/Matrix.cpp"

signed main(){
    int n;cin>>n;
    Matrix<mint> mat(n);
    rep(i,n)rep(j,n) cin>>mat[i][j];
    cout<<mat.det()<<endl;
    return 0;
}

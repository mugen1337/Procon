#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include "../template.cpp"

#include "../type/modint.cpp"

#include "../Math/XorConvolution.cpp"

using mint=ModInt<998244353>;

signed main(){
    int n;cin>>n;
    vector<mint> a(1<<n),b(1<<n);
    cin>>a>>b;
    cout<<XorConvolution(a,b)<<endl;
    return 0;
}
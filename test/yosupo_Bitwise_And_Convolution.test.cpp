#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "../template.cpp"

#include "../type/modint.cpp"

#include "../Math/AndConvolution.cpp"

using mint=ModInt<998244353>;

signed main(){
    int n;cin>>n;
    vector<mint> a(1<<n),b(1<<n);
    cin>>a>>b;
    cout<<AndConvolution(a,b)<<endl;
    return 0;
}
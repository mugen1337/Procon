#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "../template.hpp"

#include "../type/modint.hpp"

#include "../Math/AndConvolution.hpp"

using mint=ModInt<998244353>;

signed main(){
    int n;cin>>n;
    vector<mint> a(1<<n),b(1<<n);
    cin>>a>>b;
    cout<<AndConvolution(a,b)<<endl;
    return 0;
}
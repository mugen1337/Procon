#define PROBLEM "https://yukicoder.me/problems/1917"

#include "../template.cpp"

#include "../type/modint.cpp"

using mint=ModInt<1000000007>;

#include "../Math/Precalc.cpp"

Precalc<mint> F(1000010);

signed main(){
    ll n,k;cin>>n>>k;
    // f(i) = 1^k + 2^k + ... + i^k
    vector<mint> f;
    f.push_back(0);
    for(int i=1;i<=k+1;i++) f.push_back(f.back()+mint(i).pow(k));

    cout<<F.LagrangePolynomial(f,n)<<endl;
    return 0;
}

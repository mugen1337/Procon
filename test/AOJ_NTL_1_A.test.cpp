#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=jp"

#include "../template.cpp"

#include "../Math/Factorize.cpp"

signed main(){
    ll x;cin>>x;
    cout<<x<<": "<<Factorize(x)<<endl;
    return 0;
}

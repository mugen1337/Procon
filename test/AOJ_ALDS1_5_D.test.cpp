#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include "../template.hpp"

#include "../DP/InversionNumber.hpp"

signed main(){
    int n;cin>>n;
    vector<int> a(n);
    cin>>a;
    cout<<InversionNumber(a)<<endl;
    return 0;
}

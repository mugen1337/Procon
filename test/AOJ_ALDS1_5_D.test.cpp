#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include "../template.cpp"

#include "../DP/InversionNumber.cpp"

signed main(){
    int n;cin>>n;
    vector<int> a(n);
    cin>>a;
    cout<<InversionNumber(a)<<endl;
    return 0;
}

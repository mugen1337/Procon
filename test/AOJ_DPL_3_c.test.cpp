#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=ja"

#include "../template.cpp"

#include "../DP/LargestRectangle.cpp"

signed main(){
    int n;cin>>n;
    vector<ll> v(n);
    cin>>v;
    cout<<LargestRectangle(v)<<endl;
    return 0;
}

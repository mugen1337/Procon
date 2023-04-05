#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include "../template.hpp"

#include "../DP/LongestCommonSubsequence.hpp"

void solve(){
    string a,b;cin>>a>>b;
    auto res=LongestCommonSubsequence(a,b);
    // cout<<res<<endl;
    cout<<res.size()<<endl;
}

signed main(){
    int q;cin>>q;
    while(q--) solve();
    return 0;
}

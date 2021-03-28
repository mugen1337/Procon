#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include "../template.cpp"

#include "../DP/LongestCommonSubstring.cpp"

void solve(){
    string a,b;cin>>a>>b;
    auto res=LongestCommonSubsecence(a,b);
    // cout<<res<<endl;
    cout<<res.size()<<endl;
}

signed main(){
    int q;cin>>q;
    while(q--) solve();
    return 0;
}

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0109"

#include "../template.hpp"

#include "../Other/Parser.hpp"

Parser<int> parse;

void solve(){
    string s;cin>>s;
    s.pop_back();
    cout<<parse.execute(s)<<endl;
}

signed main(){
    int q;cin>>q;
    while(q--) solve();
    return 0;
}
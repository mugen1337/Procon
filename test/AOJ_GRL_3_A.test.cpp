#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include "../template.hpp"

#include "../Graph2/LowLink.hpp"

signed main(){
    int n,m;cin>>n>>m;
    Graph<int> g(n);
    g.read(m,0);
    LowLink<int> LL(g);
    vector<int> res;
    rep(i,n)if(LL.art[i]) res.push_back(i);
    for(auto x:res) cout<<x<<endl;
    return 0;
}

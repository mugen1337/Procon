#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../template.hpp"

#include "../Graph2/StronglyConnectedComponents.hpp"

signed main(){
    int n,m;cin>>n>>m;
    Graph g(n);
    g.read(m,0,false,true);

    StronglyConnectedComponents scc(g);

    cout<<scc.group.size()<<"\n";
    rep(i,(int)scc.group.size()){
        cout<<scc.group[i].size();
        for(auto x:scc.group[i]) cout<<" "<<x;
        cout<<"\n";
    }
    return 0;
}
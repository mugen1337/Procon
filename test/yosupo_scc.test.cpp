#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../template.hpp"

#include "../Graph/StronglyConnectedComponents.hpp"

signed main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> g(n);
    rep(i,m){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }

    StronglyConnectedComponents scc(g);
    scc.build();
    cout<<scc.group.size()<<"\n";
    rep(i,(int)scc.group.size()){
        cout<<scc.group[i].size();
        for(auto x:scc.group[i]) cout<<" "<<x;
        cout<<"\n";
    }
    return 0;
}
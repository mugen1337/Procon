#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../template.cpp"

#include "../Graph2/StronglyConnectedComponents.cpp"

signed main(){
    int n,m;cin>>n>>m;
    Graph g(n);
    g.read(m,0,false,true);

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
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../template.hpp"

#include "../Graph/Dijkstra.hpp"

signed main(){
    int n,m,s,t;cin>>n>>m>>s>>t;
    Dijkstra<ll> d(n);
    rep(i,m){
        int u,v;ll c;cin>>u>>v>>c;
        d.add_edge(u,v,c);
    }
    d.build(s);
    auto p=d.get_path(t);
    if(p.empty()) cout<<-1<<endl;
    else{
        cout<<d[t]<<" "<<(int)p.size()-1<<endl;
        int k=p[0];
        for(int i=1;i<(int)p.size();i++){
            cout<<k<<" "<<p[i]<<endl;
            k=p[i];
        }
    }
    return 0;
}

#define ERROR 1e-4
#define PROBLEM "https://yukicoder.me/problems/4227"

#include "../template.cpp"

#include "../Graph2/Yen.cpp"

signed main(){
    int n,m,k;cin>>n>>m>>k;
    int s,t;cin>>s>>t;s--,t--;
    vector<double> p(n),q(n);
    rep(i,n) cin>>p[i]>>q[i];

    Graph<double> g(n);
    rep(i,m){
        int u,v;cin>>u>>v;u--,v--;
        double c=hypot(p[u]-p[v],q[u]-q[v]);
        g.add_directed_edge(u,v,c);
        g.add_directed_edge(v,u,c);
    }
    auto res=Yen(g,s,t,k);
    rep(i,k){
        if(i<(int)res.size()) cout<<res[i].first<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}

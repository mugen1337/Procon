#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja"

#include "../template.cpp"

#include "../Graph2/Dijkstra.cpp"

signed main(){
    int n,m,s;cin>>n>>m>>s;
    Graph<ll> g(n);
    g.read(m,0,true,true);
    Dijkstra dij(g);
    for(auto x:dij.build(s)){
        if(x==dij.inf) cout<<"INF"<<endl;
        else cout<<x<<endl;
    }
    return 0;
}

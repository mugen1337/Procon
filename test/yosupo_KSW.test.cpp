#define PROBLEM "https://judge.yosupo.jp/problem/k_shortest_walk"

#include "../template.cpp"

#include "../Graph2/Eppstein.cpp"

signed main(){
    int n,m,s,t,k;cin>>n>>m>>s>>t>>k;
    Graph<ll> g(n);
    g.read(m,0,true,true);
    auto res=Eppstein(g,s,t,k);
    rep(i,k){
        if(i<(int)res.size())   cout<<res[i]<<endl;
        else                    cout<<-1<<endl;
    }
    return 0;
}

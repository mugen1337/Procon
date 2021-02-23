#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2313"

#include "../template.cpp"

#include "../Flow/Dinic.cpp"


signed main(){
    int n,m,q;cin>>n>>m>>q;
    Dinic<int> flow(n);
    set<pair<int,int>> st;
    rep(i,m){
        int u,v;cin>>u>>v;u--,v--;
        flow.add_edge(u,v,1);
        flow.add_edge(v,u,1);
        st.insert({u,v});
        st.insert({v,u});
    }

    using T=tuple<int,int,int>;
    vector<T> qs;
    rep(i,q){
        int m,a,b;cin>>m>>a>>b;a--,b--;
        qs.push_back({m,a,b});
        if(st.count({a,b})) continue;
        flow.add_edge(a,b,0);
        flow.add_edge(b,a,0);
    }

    int res=flow.max_flow(0,n-1);
    for(auto [m,a,b]:qs){
        if(m==1){
            res+=flow.add(0,n-1,a,b,1);
            res+=flow.add(0,n-1,b,a,1);
        }else{
            res-=flow.cut(0,n-1,a,b);
            res-=flow.cut(0,n-1,b,a);
        }
        cout<<res<<endl;
    }
    return 0;
}
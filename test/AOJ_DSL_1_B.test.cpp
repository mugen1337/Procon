#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"

#include "../template.hpp"

#include "../UnionFind/WeightedUnionFind.hpp"

signed main(){
    int n,q;cin>>n>>q;
    WeightedUnionFind<int> uf(n);
    while(q--){
        int t;cin>>t;
        if(t){
            int x,y;cin>>x>>y;
            if(!uf.sameroot(x,y)) cout<<"?"<<endl;
            else cout<<-uf.diff(x,y)<<endl;
        }else{
            int u,v,w;cin>>u>>v>>w;
            uf.unite(u,v,w);
        }
    }
    return 0;
}
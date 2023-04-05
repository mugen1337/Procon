#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2821"

#include "../template.hpp"

#include "../Tree/TreeHash.hpp"
#include "../UnionFind/UnionFind.hpp"

signed main(){
    TreeHasher th(300010);

    int n,m;cin>>n>>m;
    vector<vector<int>> g(n);
    UnionFind uf(n);
    rep(i,m){
        int u,v;cin>>u>>v;u--,v--;
        uf.unite(u,v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    map<int,vector<int>> vertices;
    rep(i,n) vertices[uf.root(i)].push_back(i);

    // hashごとカウント
    map<ull,int> cnt;
    vector<int> id(n);
    for(auto &p:vertices){
        auto &v=p.second;
        rep(i,(int)v.size()) id[v[i]]=i;
        vector<vector<int>> t(v.size());
        rep(i,(int)v.size()){
            for(auto &j:g[v[i]]) t[i].push_back(id[j]);
        }
        cnt[th.TreeHash(t)]++;
    }
    
    cin>>n;
    vector<vector<int>> t(n);
    rep(i,n-1){
        int u,v;cin>>u>>v;u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    cout<<cnt[th.TreeHash(t)]<<endl;
    return 0;
}

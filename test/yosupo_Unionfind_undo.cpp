#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../template.cpp"

#include "../UnionFind/UnionFindUndo.cpp"

signed main(){
    int n,q;cin>>n>>q;
    UnionFindUndo uf(n);
    while(q--){
        int t,u,v;cin>>t>>u>>v;
        if(t) cout<<uf.sameroot(u,v)<<endl;
        else uf.unite(u,v);
    }
    return 0;
}
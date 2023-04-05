#define PROBLEM "https://yukicoder.me/problems/5764"

#include "../template.hpp"

#include "../Graph/WarshallFloyd.hpp"

signed main(){
    int n,m;cin>>n>>m;
    vector<vector<ll>> mat(n,vector<ll>(n,LINF));
    rep(i,n) mat[i][i]=0;

    rep(i,m){
        int u,v;ll w;cin>>u>>v>>w;u--,v--;
        chmin(mat[u][v],w);
    }

    mat=WarshallFloyd(mat,LINF);
    rep(i,n){
        ll res=0;
        rep(j,n) if(mat[i][j]<LINF) res+=mat[i][j];
        cout<<res<<endl;
    }
    return 0;
}

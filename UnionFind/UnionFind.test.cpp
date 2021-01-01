#include<bits/stdc++.h>
using namespace std;
#define ALL(x) begin(x),end(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define mod 1000000007
using ll=long long;
const int INF=1000000000;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

struct UnionFind{
    int con;
    vector<int> par,siz;
    UnionFind(int n):con(n),par(n),siz(n,1){
        iota(begin(par),end(par),0);
    }
    int root(int x){
        return (par[x]==x?x:(par[x]=root(par[x])));
    }
    bool sameroot(int x,int y){
        return root(x)==root(y);
    }
    bool unite(int x,int y){
        x=root(x);y=root(y);
        if(x==y) return false;
        if(siz[x]<siz[y])swap(x,y);
        siz[x]+=siz[y];
        par[y]=x;
        con--;
        return true;
    }
    int size(int x){
        return siz[root(x)];
    }
};


signed main(){
    int n,q;cin>>n>>q;
    UnionFind uf(n);
    while(q--){
        int t,u,v;cin>>t>>u>>v;
        if(t) cout<<uf.sameroot(u,v)<<endl;
        else  uf.unite(u,v);
    }
    return 0;
}

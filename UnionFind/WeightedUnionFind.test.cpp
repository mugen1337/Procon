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

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"


template<typename T>
struct WeightedUnionFind{
    int con;
    vector<int> par,siz;
    vector<T> h;// height, h[root]=0
    WeightedUnionFind(int n):con(n),par(n),siz(n,1),h(n,T(0)){
        iota(begin(par),end(par),0);
    }
    int root(int x){
        if(x==par[x]) return x;
        int r=root(par[x]);
        h[x]+=h[par[x]];
        return par[x]=r;
    }
    bool sameroot(int x,int y){
        return root(x)==root(y);
    }
    // yはxよりdiff_h高い, h[y]=h[x]+diff_h, x->y (diff_h)
    bool unite(int x,int y,T diff_h){
        int root_x=root(x),root_y=root(y);
        if(root_x==root_y){
            // // x and y are already in same group
            // assert(false);
            return false;
        }
        diff_h=-h[x]+diff_h+h[y];
        if(siz[root_x]>siz[root_y]) swap(root_x,root_y),diff_h=-diff_h; 
        siz[root_y]+=siz[root_x];
        par[root_x]=root_y;
        h[root_x]=diff_h;
        con--;
        return true;
    }
    // h[y]-h[x]
    T diff(int x,int y){
        assert(sameroot(x,y));
        return h[y]-h[x];
    }
    int size(int x){
        return siz[root(x)];
    }
};


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
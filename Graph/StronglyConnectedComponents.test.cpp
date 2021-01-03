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
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

#define PROBLEM "https://judge.yosupo.jp/problem/scc"

struct StronglyConnectedComponents{
    private:
    vector<vector<int>> g,rg;
    vector<int> check;
    void dfs(int cur,vector<int> &ord){
        for(auto &to:g[cur])if(!check[to]){
            check[to]=true;
            dfs(to,ord);
        }
        ord.push_back(cur);
    }
    void rdfs(int cur,int p){
        for(auto &to:rg[cur])if(comp[to]==-1){
            comp[to]=p;
            rdfs(to,p);
        }
    }

    public:
    vector<int> comp;
    vector<vector<int>> compressed,group;
    
    StronglyConnectedComponents(vector<vector<int>> &g):g(g),rg(g.size()),check(g.size()),comp(g.size(),-1){
        for(int i=0;i<(int)g.size();i++)for(auto &j:g[i]) rg[j].push_back(i);
    }
    // return compressed graph
    vector<vector<int>> build(){
        vector<int> ord;
        for(int i=0;i<(int)g.size();i++)if(!check[i]){
            check[i]=true;
            dfs(i,ord);
        }
        int ptr=0;;
        for(int i=(int)ord.size()-1;i>=0;i--)if(comp[ord[i]]==-1){
            comp[ord[i]]=ptr;
            rdfs(ord[i],ptr);ptr++;
        }
        compressed.resize(ptr);
        group.resize(ptr);
        for(int i=0;i<(int)g.size();i++){
            int u=comp[i];
            group[u].push_back(i);
            for(auto &j:g[i]){
                int v=comp[j];
                if(u!=v) compressed[u].push_back(v);
            }
        }
        return compressed;
    }
};



signed main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> g(n);
    rep(i,m){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }

    StronglyConnectedComponents scc(g);
    scc.build();
    cout<<scc.group.size()<<"\n";
    rep(i,(int)scc.group.size()){
        cout<<scc.group[i].size();
        for(auto x:scc.group[i]) cout<<" "<<x;
        cout<<"\n";
    }
    return 0;
}

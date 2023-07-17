#include "./GraphTemplate.hpp"

template< typename T >
struct DoublingLowestCommonAncestor{
    const Graph<T> &g;
    vector<int> dep;
    int LOG;
    //table[i][j]は点jの2^i個上の親情報
    vector<vector<int>> table;

    DoublingLowestCommonAncestor(const Graph< T > &g_) : g(g_), dep(g_.V),LOG(32 - __builtin_clz(g_.V))
    {
        table.assign(LOG, vector<int>(g_.V, -1));
    }
 
    void dfs(int idx, int par, int d)
    {
        //1個上の親の記録
        table[0][idx] = par;
        dep[idx] = d;
        for(auto &to : g[idx])
        {
            if(to!=par) dfs(to, idx, d+1);
        }
    }
 
    //根としたい点をroot
    void build(int root){
        dfs(root, -1, 0);
        for(int k = 0; k + 1 < LOG; k++)
        {
            for(int i = 0; i < (int)table[k].size(); i++)
            {
                if(table[k][i]==-1) table[k + 1][i] = -1;
                else                table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }
 
    //u,vのlcaを求める
    int query(int u, int v)
    {
        //dep[u]>dep[v]として進める
        if(dep[u] > dep[v]) swap(u,v);
        //深さをそろえる
        for(int i = LOG - 1; i >= 0; i--)
        {
            if(((dep[v]-dep[u])>>i)&1) v=table[i][v];
        }
        if(u==v) return u;
        for(int i=LOG-1;i>=0;i--){
            if(table[i][u]!=table[i][v]){
                u=table[i][u];
                v=table[i][v];
            }
        }
        return table[0][u];
    }
    
    // 呼び出すたびO(logn)
    int dis(int u,int v){
        int p=query(u,v);
        return dep[u]+dep[v]-2*dep[p];
    }
 
    // 深さを返す
    int operator[](const int &k) const{
        return dep[k];
    }
 
    //頂点xのk個上の親を求める。無ければ-1
    int parent(int x,int k){
        int ret=x;
        for(int i=LOG-1;i>=0 and ret>=0;i--){
            if((k>>i)&1) ret=table[i][ret];
        }
        return ret;
    }
};
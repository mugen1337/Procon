#include "./GraphTemplate.cpp"

/*
ref : https://ferin-tech.hatenablog.com/entry/2019/11/21/HL%E5%88%86%E8%A7%A3%E3%81%AE%E5%AE%9F%E8%A3%85
      https://ei1333.github.io/library/graph/tree/heavy-light-decomposition.cpp

HLD 
    各頂点から頂点を扱いやすいように並び替えた時の番号への写像を考える
    ! 辺属性で考えたい場合
        頂点iから親方向に伸びている辺をpos[i]にSegment木などにセットし，各メソッドをedge=trueで扱う

    member
        head[i] : iの先頭
        in[i], out[i] : i頂点以下の部分木のin, out

    method
        lca(u, v) : least common ancestor
        dist(u, v) : 距離
        get_path(u, v) : 区間のvectorを返すので各区間でクエリを処理し，mergeすればよい
        get_subtree(u) : 部分木にあたる区間を返す
        pos(u) : 並び替えをした後，頂点uがどの場所へ移るかの射影
*/
template<typename T>
struct HeavyLightDecomposition{
private:
    void dfs1(int pre,int cur){
        par[cur]=pre;
        sz[cur]=1;
        if(!g[cur].empty() and g[cur][0]==pre) swap(g[cur][0],g[cur].back());
        for(auto &e:g[cur])if(e!=pre){
            dfs1(cur,e);
            sz[cur]+=sz[e];
            dis[e]+=dis[cur]+e.w;
            if(sz[g[cur][0]]<sz[e]) swap(g[cur][0],e);
        }
    }
    void dfs2(int pre,int cur,int &t){
        in[cur]=t++;
        rev[in[cur]]=cur;
        for(auto &e:g[cur])if(e!=pre){
            head[e]=(g[cur][0]==e?head[cur]:e);
            dfs2(cur,e,t);
        }
        out[cur]=t;
    }


public:
    Graph<T> g;
    vector<int> sz,in,out,head,rev,par;
    vector<T> dis;

    HeavyLightDecomposition(Graph<T> g,int root=0):
    g(g),sz(g.V,0),in(g.V,0),out(g.V,0),head(g.V,0),rev(g.V,0),par(g.V,0),dis(g.V,0){
        dfs1(-1,root);
        int t=0;
        dfs2(-1,root,t);
    }
    int la(int v,int k){
        for(;;){
            int u=head[v];
            if(in[v]-k>=in[u]) return rev[in[v]-k];
            k-=in[v]-in[u]+1;
            v=par[u];
        }
    }
    int lca(int u,int v){
        for(;;v=par[head[v]]){
            // 深い方から上げていく
            if(in[u]>in[v]) swap(u,v);
            if(head[u]==head[v]) return u;
        }
    }
    T dist(int u,int v){ return dis[u]+dis[v]-dis[lca(u,v)]*2; }

    // return ranges
    vector<pair<int,int>> get_path(int u,int v,bool edge=false){
        vector<pair<int,int>> ret;
        for(;;v=par[head[v]]){
            if(in[u]>in[v]) swap(u,v);
            if(head[u]==head[v]) break;
            ret.emplace_back(in[head[v]],in[v]+1);
        }
        // 最後の区間の始点がLCA
        ret.emplace_back(in[u]+edge,in[v]+1);
        return ret;
    }
    // return one range
    pair<int,int> get_subtree(int u,bool edge=false){
        return {in[u]+edge,out[u]};
    }
    int pos(int u){
        return in[u];
    }
};

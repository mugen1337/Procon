#include "./LowLink.hpp"

/*
二重辺連結成分分解をし，頂点をgroupに分ける
group[i] : グループiが持つ頂点番号
belong[i] : 頂点iが所属するグループ番号
*/
template<typename T>
struct TwoEdgeConnectedComponents{
public:
    LowLink<T> LL;
    void dfs(Graph<T> &g,int pre,int cur,int &k){
        if(pre>=0 and LL.ord[pre]>=LL.low[cur]) belong[cur]=belong[pre];
        else                                    belong[cur]=k++;

        for(auto &e:g[cur])if(belong[e]==-1) dfs(g,cur,e,k);
    }

public:
    vector<int> belong;
    vector<vector<int>> group;
    Graph<T> tree;

    TwoEdgeConnectedComponents(Graph<T> &g):LL(g),belong(g.size(),-1){
        int k=0;
        for(int i=0;i<g.size();i++)if(belong[i]==-1) dfs(g,-1,i,k);
        group.resize(k);
        for(int i=0;i<g.size();i++) group[belong[i]].push_back(i);
        tree=Graph<T>(k);
        for(auto &e:LL.bridge) tree.add_edge(belong[e.from],belong[e.to],e.w);
    }
};

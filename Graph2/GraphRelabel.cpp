#include "./GraphTemplate.cpp"
#include "../UnionFind/UnionFind.cpp"

template<typename T>
vector<Graph<T>> GraphRelabel(Graph<T> G){
    UnionFind uf(G.V);
    for(int i=0;i<G.V;i++)for(auto &e:G[i]) uf.unite(e.from,e.to);
    
    vector<vector<int>> vertice(G.V);
    for(int i=0;i<G.V;i++) vertice[uf.root(i)].push_back(i);

    vector<Graph<T>> ret;
    for(auto &w:vertice){
        if(w.empty()) continue;
        Graph<T> subG(w.size());
        for(int &x:w){
            int u=lower_bound(begin(w),end(w),x)-begin(w);
            for(auto &e:G[x]){
                int v=lower_bound(begin(w),end(w),e.to)-begin(w);
                subG.add_directed_edge(u,v,e.w);
            }
        }
        ret.push_back(subG);
    }
    return ret;
}
#include "./GraphTemplate.cpp"

// 有向グラフ向け
// 無向グラフでやりたいなら辺のidxが独立になるように振りなおす
// O(KN * (N+M)logN)のはずだけどどこか悪化してるかも
// vector ( pair(cost, pathの辺番号のリスト) ), k個ない時に注意
/*
ref: https://qiita.com/nariaki3551/items/821dc6ffdc552d3d5f22
     https://ei1333.github.io/library/graph/shortest-path/k-shortest-path.cpp
*/
template<typename T>
vector<pair<T,vector<int>>> Yen(Graph<T> g,int s,int t,int k){
    T inf=numeric_limits<T>::max();

    vector<Edge<T>> edge(g.E);
    for(int i=0;i<g.V;i++)for(auto &e:g[i]) edge[e.idx]=e;

    unordered_set<int> removed_edge;
    using P=pair<T,int>;
    auto dijkstra=[&](vector<T> &d,vector<int> &from_v,vector<int> &from_e,int st){
        priority_queue<P,vector<P>,greater<P>> que;
        que.emplace(d[st],st);
        while(!que.empty()){
            auto p=que.top();que.pop();
            int cur=p.second;
            if(d[cur]<p.first) continue;
            for(auto &e:g[cur])if(!removed_edge.count(e.idx)){
                if(chmin(d[e.to],d[cur]+e.w)){
                    from_v[e.to]=cur;
                    from_e[e.to]=e.idx;
                    que.emplace(d[e.to],e.to);
                }
            }
        }
    };

    // (s, t)へのパスの辺番号のvector
    auto get_path=[&](vector<int> &from_v,vector<int> &from_e,int st,int gl){
        vector<int> e_idx;
        for(;gl!=st;gl=from_v[gl]) e_idx.push_back(from_e[gl]);
        reverse(begin(e_idx),end(e_idx));
        return e_idx;
    };

    vector<pair<T,vector<int>>> A;
    set<pair<T,vector<int>>> B;

    vector<T> d;
    vector<int> from_v,from_e;
    d.assign(g.V,inf);
    d[s]=0;
    from_v.assign(g.V,-1);
    from_e.assign(g.V,-1);
    dijkstra(d,from_v,from_e,s);

    if(d[t]==inf) return A;

    A.emplace_back(d[t],get_path(from_v,from_e,s,t));

    for(int i=1;i<k;i++){
        vector<int> &last_path=A.back().second;
        d.assign(g.V,inf);
        d[s]=0;
        from_v.assign(g.V,-1);
        from_e.assign(g.V,-1);

        vector<int> same_path(i); // last pathに沿った道のリスト
        iota(begin(same_path),end(same_path),0);

        // O(N)
        for(int j=0;j<(int)last_path.size();j++){
            int spur=edge[last_path[j]].from;// spur node

            unordered_set<int> removed_edge_new;
            for(auto &l:same_path)if(j<(int)A[l].second.size()) removed_edge_new.insert(A[l].second[j]);
            swap(removed_edge,removed_edge_new);
            
            // spur nodeから先をdijkstraする
            vector<T> d_t{d};
            vector<int> from_v_t{from_v},from_e_t{from_e};

            dijkstra(d_t,from_v_t,from_e_t,spur);
            if(d_t[t]<inf) B.emplace(d_t[t],get_path(from_v_t,from_e_t,s,t));

            // last pathに沿って1つ進める
            auto &spur_root=edge[last_path[j]];
            d[spur_root.to]=d[spur_root.from]+spur_root.w;
            from_e[spur_root.to]=spur_root.idx;
            from_v[spur_root.to]=spur_root.from;

            vector<int> tmp;
            for(auto l:same_path)if(j<(int)A[l].second.size() and A[l].second[j]==last_path[j])
                tmp.push_back(l);
            swap(tmp,same_path);
        }
        if(B.empty()) return A;

        A.push_back(*begin(B));
        B.erase(begin(B));
    }
    return A;
}
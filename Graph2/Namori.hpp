/*
Namori Graph

loop_vertex[i] - loop_edge[i] loop_vertex[i+1]
forest : loop_vertexからぶら下がる木
         loop_vertexをroot, 0としてidふり直し
*/
template<typename T>
struct Namori{
    Graph<T> G;
    vector<int> loop_vertex;
    vector<Edge<T>> loop_edge;
    vector<Graph<int>> forest;

    Namori(Graph<T> G):G(G){
        int N=G.size();

        // loop 取り出し
        vector<bool> used(N, false);
        {
            vector<int> deg(N);
            queue<int> que;
            for(int i=0;i<N;i++){
                deg[i]=G[i].size();
                if(deg[i]==1){
                    que.push(i);
                    used[i]=true;
                }
            }

            while(not que.empty()){
                int cur=que.front();que.pop();

                for(auto &e:G[cur])if(not used[e]){
                    deg[e]--;
                    if(deg[e]==1){
                        que.push(e);
                        used[e]=true;
                    }
                }
            }
        }

        // loop順序
        {
            queue<int> que;
            vector<bool> visited(N, false);
            for(int i=0;i<N;i++){
                if(not used[i]){
                    que.push(i);
                    visited[i]=true;
                    loop_vertex.push_back(i);
                    break;
                }
            }
            while(not que.empty()){
                int cur=que.front();que.pop();
                for(auto &e:G[cur])if((not used[e]) and (not visited[e])){
                    visited[e]=true;
                    que.push(e);
                    loop_vertex.push_back(e);
                    loop_edge.emplace_back(e.from, e.to, e.w, e.idx);
                    break;
                }
            }
            for(auto &e:G[loop_vertex.back()])
                if(minmax(e.from, e.to)==minmax(loop_vertex[0], loop_vertex.back()))
                    loop_edge.push_back(e);
        }
        


        // forest 構築
        {
            vector<int> id(N, -1);
            for(int root:loop_vertex){
                vector<Edge<T>> es;
                int V=0;
                function<void(int,int)> dfs=[&](int par, int cur){
                    for(auto &e:G[cur])if(par!=e and (used[e])){
                        if(id[e]==-1) id[e]=V++;
                        es.emplace_back(id[cur], id[e], e.w, e.idx);
                        dfs(cur, e);
                    }
                };
                id[root]=V++;
                dfs(-1, root);

                Graph<T> g(V);
                for(auto &e:es) g.add_edge(e.from, e.to, e.w);
                forest.push_back(g);
            }
        }
    }
};

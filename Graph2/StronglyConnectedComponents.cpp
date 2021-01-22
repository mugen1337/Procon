#include "./GraphTemplate.cpp"
// scc.belong[i]    : strongly connected belongonents i belongs 
// scc.group[i]   : vertice i-th strongly connected belongonent has
// scc.compressed : compressed Graph, DAG
template<typename T=int>
struct StronglyConnectedbelongonents{
    private:
    Graph<T> g,rg;
    vector<int> check;
    void dfs(int cur,vector<int> &ord){
        for(auto &to:g[cur])if(!check[to]){
            check[to]=true;
            dfs(to,ord);
        }
        ord.push_back(cur);
    }
    void rdfs(int cur,int p){
        for(auto &to:rg[cur])if(belong[to]==-1){
            belong[to]=p;
            rdfs(to,p);
        }
    }

    void build(){
        vector<int> ord;
        for(int i=0;i<(int)g.size();i++)if(!check[i]){
            check[i]=true;
            dfs(i,ord);
        }
        int ptr=0;;
        for(int i=(int)ord.size()-1;i>=0;i--)if(belong[ord[i]]==-1){
            belong[ord[i]]=ptr;
            rdfs(ord[i],ptr);ptr++;
        }
        compressed.resize(ptr);
        group.resize(ptr);
        for(int i=0;i<(int)g.size();i++){
            int u=belong[i];
            group[u].push_back(i);
            for(auto &e:g[i]){
                int v=belong[e];
                if(u!=v) compressed.add_directed_edge(u,v,e.w);
            }
        }
        return ;
    }

    public:
    vector<int> belong;
    vector<vector<int>> group;
    Graph<T> compressed;
    
    StronglyConnectedbelongonents(Graph<T> &g):g(g),rg(g.size()),check(g.size()),belong(g.size(),-1){
        for(int i=0;i<(int)g.size();i++)for(auto &e:g[i]) rg.add_directed_edge(e.to,e.from,e.w);
        build();
    }
};
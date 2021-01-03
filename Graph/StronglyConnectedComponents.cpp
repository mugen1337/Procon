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
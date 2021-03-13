struct PartiallyPersistentUnionFind{
    private:
    vector<int> ch,par;
    vector<vector<pair<int,int>>> siz;

    public:
    int time;
    PartiallyPersistentUnionFind(int n):ch(n,1000000000),par(n,-1),siz(n),time(-1){
        for(int i=0;i<n;i++) siz[i].emplace_back(-1,-1);
    }
    int root(int t,int x){
        if(ch[x]>t) return x;
        return root(t,par[x]);
    }
    bool sameroot(int t,int x,int y){
        return root(t,x)==root(t,y);
    }
    bool unite(int x,int y){
        time++;
        x=root(time,x);
        y=root(time,y);
        if(x==y) return false;
        if(par[x]>par[y]) swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        ch[y]=time;
        siz[x].emplace_back(time,par[x]);
        return true;
    }
    int size(int t,int x){
        x=root(t,x);
        return -prev(lower_bound(begin(siz[x]),end(siz[x]),make_pair(t,0)))->second;
    }
};
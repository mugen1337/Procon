struct UnionFind{
    int con;
    vector<int> par,siz;
    UnionFind(int n):con(n),par(n),siz(n,1){
        iota(begin(par),end(par),0);
    }
    int root(int x){
        return (par[x]==x?x:(par[x]=root(par[x])));
    }
    bool sameroot(int x,int y){
        return root(x)==root(y);
    }
    bool unite(int x,int y){
        x=root(x);y=root(y);
        if(x==y) return false;
        if(siz[x]<siz[y])swap(x,y);
        siz[x]+=siz[y];
        par[y]=x;
        con--;
        return true;
    }
    int size(int x){
        return siz[root(x)];
    }
};
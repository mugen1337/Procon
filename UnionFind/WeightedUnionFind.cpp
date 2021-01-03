template<typename T>
struct WeightedUnionFind{
    int con;
    vector<int> par,siz;
    vector<T> h;// height, h[root]=0
    WeightedUnionFind(int n):con(n),par(n),siz(n,1),h(n,T(0)){
        iota(begin(par),end(par),0);
    }
    int root(int x){
        if(x==par[x]) return x;
        int r=root(par[x]);
        h[x]+=h[par[x]];
        return par[x]=r;
    }
    bool sameroot(int x,int y){
        return root(x)==root(y);
    }
    // yはxよりdiff_h高い, h[y]=h[x]+diff_h, x->y (diff_h)
    bool unite(int x,int y,T diff_h){
        int root_x=root(x),root_y=root(y);
        if(root_x==root_y){
            // // x and y are already in same group
            // assert(false);
            return false;
        }
        diff_h=-h[x]+diff_h+h[y];
        if(siz[root_x]>siz[root_y]) swap(root_x,root_y),diff_h=-diff_h; 
        siz[root_y]+=siz[root_x];
        par[root_x]=root_y;
        h[root_x]=diff_h;
        con--;
        return true;
    }
    // h[y]-h[x]
    T diff(int x,int y){
        assert(sameroot(x,y));
        return h[y]-h[x];
    }
    int size(int x){
        return siz[root(x)];
    }
};
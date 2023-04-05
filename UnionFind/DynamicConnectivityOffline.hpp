// verified https://codeforces.com/gym/100551/submission/103148848
// ref https://ei1333.hateblo.jp/entry/2017/12/14/000000
struct DynamicConnectivityOffline{
    private:
    int sz;
    using P=pair<int,int>;
    vector<vector<P>> seg;
    vector<pair<P,P>> es;// {{start idx, end idx}, {u, v}}
    map<P,int> cnt,prev;

    void add_seg(int a,int b,P &e,int k,int l,int r){
        if(r<=a or b<=l) return ;
        if(a<=l and r<=b){
            seg[k].push_back(e);
            return ;
        }
        add_seg(a,b,e,2*k,l,(l+r)/2);
        add_seg(a,b,e,2*k+1,(l+r)/2,r);
    }
    

    public:
    int n,q;
    UnionFindUndo uf;

    DynamicConnectivityOffline(int n,int q):n(n),q(q),uf(n){
        sz=1;while(sz<q)sz<<=1;
        seg.resize(sz*2);
    }

    // queryのindex順に追加
    void add_edge(int query_idx,int u,int v){
        if(u>v) swap(u,v);
        if(cnt[P(u,v)]==0) prev[P(u,v)]=query_idx;
        cnt[P(u,v)]++;
    }
    void delete_edge(int query_idx,int u,int v){
        if(u>v) swap(u,v);
        assert(cnt[P(u,v)]>0);
        cnt[P(u,v)]--;
        if(cnt[P(u,v)]==0) es.emplace_back(P(prev[P(u,v)],query_idx),P(u,v));
    }
    void build(){
        for(auto [e,c]:cnt)if(c>0) es.emplace_back(P(prev[e],sz),e);
        for(auto [t,e]:es) add_seg(t.first,t.second,e,1,0,sz);
    }
    // dfs -> segment tree
    // f(query_idx)
    void execute(function<void(int)> &f,int k=1){
        for(auto [u,v]:seg[k]) uf.unite(u,v);
        if(k<sz){
            execute(f,2*k);
            execute(f,2*k+1);
        }
        else if(k-sz<q) f(k-sz);// query
        for(auto [u,v]:seg[k]) uf.undo();
    }
};
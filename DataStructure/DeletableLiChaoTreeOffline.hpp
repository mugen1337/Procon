// verify
// https://codeforces.com/contest/678/problem/F
// https://codeforces.com/contest/678/submission/104541023

// min
template<typename T>
struct LiChaoTreeUndo{
    private:
    struct Line{
        T a,b;
        Line(T a,T b):a(a),b(b){}
        T operator()(T x){return a*x+b;}
    };

    vector<T> xs;
    vector<Line> seg;
    int sz;
    stack<vector<pair<int,Line>>> history;
    
    void add(Line &li,int k,int l,int r,vector<pair<int,Line>> &h){
        int m=(l+r)/2;
        // replace flag
        bool cl=li(xs[l])<seg[k](xs[l]),cm=li(xs[m])<seg[k](xs[m]);
        if(cm){
            h.emplace_back(k,seg[k]);
            swap(seg[k],li);
        }
        if(l+1>=r) return ;
        if(cl!=cm) add(li,2*k,l,m,h);
        else add(li,2*k+1,m,r,h);
        return ;
    }

    public:

    LiChaoTreeUndo(const vector<T> &x,T TINF):xs(x){
        sort(begin(xs),end(xs));
        xs.erase(unique(begin(xs),end(xs)),end(xs));
        sz=1;
        while(sz<(int)xs.size()) sz<<=1;
        while((int)xs.size()<sz) xs.push_back(xs.back()+1);
        seg.assign(2*sz,Line(0,TINF));
    }

    // add ax+b
    void add(T a,T b){
        vector<pair<int,Line>> h;
        Line l(a,b);
        add(l,1,0,sz,h);
        history.push(h);
    }

    void undo(){
        for(auto [k,val]:history.top()) seg[k]=val;
        history.pop();
    }

    T query(T val){
        int k=lower_bound(begin(xs),end(xs),val)-begin(xs);
        assert(xs[k]==val);
        k+=sz;
        T ret=seg[k](val);
        while(k>0){
            k>>=1;
            ret=min(ret,seg[k](val));
        }
        return ret;
    }
};

template<typename T>
struct DeletableConvexHullTrickOffline{
    using P=pair<T,T>;
    
    int sz;
    vector<vector<P>> seg;
    vector<pair<pair<int,int>,P>> es;// {{start, end}, P}
    LiChaoTreeUndo<T> lct;
    map<P,int> cnt,prev;

    void add_seg(int a,int b,P &li,int k,int l,int r){
        if(r<=a or b<=l) return ;
        if(a<=l and r<=b){
            seg[k].push_back(li);
            return ;
        }
        add_seg(a,b,li,2*k,l,(l+r)/2);
        add_seg(a,b,li,2*k+1,(l+r)/2,r);
    }

    int query_size;
    DeletableConvexHullTrickOffline(int query_size,vector<T> xs,T TINF):lct(xs,TINF),query_size(query_size){
        sz=1;
        while(sz<query_size) sz<<=1;
        seg.resize(2*sz);
    }

    // queryのindex順に追加, y=ax+b
    void add_line(int query_idx,T a,T b){
        if(cnt[P(a,b)]==0) prev[P(a,b)]=query_idx;
        cnt[P(a,b)]++;
    }
    void delete_line(int query_idx,T a,T b){
        // assert(cnt[{a,b}]>0);
        cnt[P(a,b)]--;
        if(cnt[P(a,b)]==0) es.emplace_back(make_pair(prev[P(a,b)],query_idx),P(a,b));
    }
    void build(){
        for(auto [li,c]:cnt)if(c>0) es.emplace_back(make_pair(prev[li],sz),li);
        for(auto [t,li]:es) add_seg(t.first,t.second,li,1,0,sz);
    }
    void execute(function<void(int)> &f,int k=1){
        for(auto li:seg[k]) lct.add(li.first,li.second);
        if(k<sz){
            execute(f,2*k);
            execute(f,2*k+1);
        }
        else if(k-sz<query_size) f(k-sz);
        for(auto li:seg[k]) lct.undo();
    }
};
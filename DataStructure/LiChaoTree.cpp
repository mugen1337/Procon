// min
template<typename T>
struct LiChaoTree{
    private:
    struct Line{
        T a,b;
        Line(T a,T b):a(a),b(b){}
        T operator()(T x){return a*x+b;}
    };
    
    void add(Line &li,int k,int l,int r){
        int m=(l+r)/2;
        // replace flag
        bool cl=li(xs[l])<seg[k](xs[l]),cm=li(xs[m])<seg[k](xs[m]);
        if(cm) swap(seg[k],li);// ! みてる区間においてみてる直線を切り替える
        if(l+1>=r) return ;
        // どちらかにしか降りないので計算量がlog
        if(cl!=cm) add(li,2*k,l,m);
        else add(li,2*k+1,m,r);
        return ;
    }

    vector<T> xs;
    vector<Line> seg;
    int sz;

    public:
    LiChaoTree(const vector<T> &x,T TINF):xs(x){
        sort(begin(xs),end(xs));
        xs.erase(unique(begin(xs),end(xs)),end(xs));
        sz=1;
        while(sz<(int)xs.size()) sz<<=1;
        while((int)xs.size()<sz) xs.push_back(xs.back()+1);
        seg.assign(2*sz,Line(0,TINF));
    }

    // add ax+b
    void add(T a,T b){
        Line l(a,b);
        add(l,1,0,sz);
    }

    T query(T val){
        int k=lower_bound(begin(xs),end(xs),val)-begin(xs);
        assert(xs[k]==val);
        k+=sz;
        T ret=seg[k](val);
        for(;k;k>>=1) ret=min(ret,seg[k](val));
        return ret;
    }
};
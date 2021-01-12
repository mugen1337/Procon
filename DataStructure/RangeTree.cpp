// Range Tree (Weighted)
template<typename Tx,typename Ty,typename VAL=int>
struct RangeTree{
    private:
    vector<vector<Ty>> seg;
    vector<vector<VAL>> sum;
    vector<Tx> x;
    int sz;

    void build(vector<tuple<Tx,Ty,VAL>> &v){
        sort(begin(v),end(v));
        for(int i=0;i<(int)v.size();i++) x.push_back(get<0>(v[i]));
        x.erase(unique(begin(x),end(x)),end(x));
        sz=1;
        while((int)x.size()>sz) sz<<=1;
        while((int)x.size()<sz) x.push_back(numeric_limits<Tx>::max()/2);
        seg.resize(sz*2);
        sum.resize(sz*2);
        int idx=0;
        for(auto [x_,y_,val]:v){
            if(x[idx]!=x_) idx++;
            seg[idx+sz].push_back(y_);
            sum[idx+sz].push_back(val);
        }
        for(int i=sz-1;i>0;i--){
            int l=0,r=0;
            while(l<(int)seg[2*i].size() or r<(int)seg[2*i+1].size()){
                bool f;
                if(r>=(int)seg[2*i+1].size()) f=true;
                else if(l>=(int)seg[2*i].size()) f=false;
                else if(seg[2*i][l]<seg[2*i+1][r]) f=true;
                else f=false;
                if(f){
                    seg[i].push_back(seg[2*i][l]);
                    sum[i].push_back(sum[2*i][l]);
                    l++;
                }else{
                    seg[i].push_back(seg[2*i+1][r]);
                    sum[i].push_back(sum[2*i+1][r]);
                    r++;
                }
            }
        }
        for(int i=1;i<2*sz;i++){
            vector<VAL> replace(1,0);
            for(auto val:sum[i]) replace.push_back(replace.back()+val);
            swap(sum[i],replace);
        }
    }
    
    public:
    RangeTree(vector<pair<Tx,Ty>> a){
        vector<tuple<Tx,Ty,VAL>> v;
        for(auto p:a) v.emplace_back(p.first,p.second,1);
        build(v);
    }
    RangeTree(vector<tuple<Tx,Ty,VAL>> a){
        build(a);
    }
    // sum : [x1,x2),[y1,y2)
    VAL query(Tx x1,Ty y1,Tx x2,Ty y2){
        int l=lower_bound(begin(x),end(x),x1)-begin(x),r=lower_bound(begin(x),end(x),x2)-begin(x);
        l+=sz,r+=sz;
        VAL ret=0;
        for(;l<r;l>>=1,r>>=1){
            if(l&1){
                int hi=lower_bound(begin(seg[l]),end(seg[l]),y2)-begin(seg[l]);
                int lw=lower_bound(begin(seg[l]),end(seg[l]),y1)-begin(seg[l]);
                ret+=sum[l][hi]-sum[l][lw];
                l++;
            }
            if(r&1){
                r--;
                int hi=lower_bound(begin(seg[r]),end(seg[r]),y2)-begin(seg[r]);
                int lw=lower_bound(begin(seg[r]),end(seg[r]),y1)-begin(seg[r]);
                ret+=sum[r][hi]-sum[r][lw];
            }
        }
        return ret;
    }
};
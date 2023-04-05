// [L, R)
template<typename T>
void mergesort(vector<T> &v,int L=0,int R=-1){
    if(R<0) R=(int)v.size();
    function<void(int,int)> split_merge=[&](int l,int r){
        if(l>=r) return ;
        bool f=true;
        for(int i=l;i<r-1;i++)if(v[i]>v[i+1]) f=false;
        if(f) return ;
        int m=(l+r)/2;
        split_merge(l,m);
        split_merge(m,r);
        vector<T> rpl;
        for(int i=l,j=m;i<m or j<r;){
            if(j>=r or (i<m and v[i]<=v[j])) rpl.push_back(v[i++]);
            else                             rpl.push_back(v[j++]);
        }
        for(int i=0;i<r-l;i++) v[l+i]=rpl[i];
    };
    split_merge(L,R);
    return ;
}
template<typename T>
struct SegmentTreeBeats{
    private:

    const T inf=numeric_limits<T>::max()/4;
    vector<T> mx,smx,mxc,mi,smi,mic,sum,lval,ladd;
    int sz;
    // smx[k]<x<mx[k]の部分の更新
    void update_node_max(int k,T x){
        sum[k]+=(x-mx[k])*mxc[k];
        if(mx[k]==mi[k]) mx[k]=x,mi[k]=x;
        else if(mx[k]==smi[k]) mx[k]=x,smi[k]=x;
        else mx[k]=x;
        if(lval[k]!=inf and x<lval[k]) lval[k]=x;
    }
    void update_node_min(int k,T x){
        sum[k]+=(x-mi[k])*mic[k];
        if(mx[k]==mi[k]) mx[k]=x,mi[k]=x;
        else if(smx[k]==mi[k]) smx[k]=x,mi[k]=x;
        else mi[k]=x;
        if(lval[k]!=inf and lval[k]<x) lval[k]=x;
    }
    void update_node_add(int k,int len,T x){
        mx[k]+=x;
        if(smx[k]!=-inf)smx[k]+=x;
        mi[k]+=x;
        if(smi[k]!=inf) smi[k]+=x;
        sum[k]+=x*T(len);
        if(lval[k]!=inf)lval[k]+=x;
        else            ladd[k]+=x;
    }
    // 遅延分を処理，node-kは今の値，子は古い値かもしれない
    void push(int k,int len){
        if(k>=sz) return ;
        if(lval[k]!=inf){
            update_all(2*k,len/2,lval[k]);
            update_all(2*k+1,len/2,lval[k]);
            lval[k]=inf;
            return ;
        }
        if(ladd[k]!=0){
            update_node_add(2*k,len/2,ladd[k]);
            update_node_add(2*k+1,len/2,ladd[k]);
            ladd[k]=0;
        }
        // 子が古い値なら更新．ここがポイント
        if(mx[2*k]>mx[k])  update_node_max(2*k,mx[k]);
        if(mx[2*k+1]>mx[k])update_node_max(2*k+1,mx[k]);
        if(mi[2*k]<mi[k])  update_node_min(2*k,mi[k]);
        if(mi[2*k+1]<mi[k])update_node_min(2*k+1,mi[k]);
    }
    // 子からnode-kの更新
    void update_from_children(int k){
        sum[k]=sum[2*k]+sum[2*k+1];
        if(mx[2*k]<mx[2*k+1]){
            mx[k]=mx[2*k+1];mxc[k]=mxc[2*k+1];
            smx[k]=max(mx[2*k],smx[2*k+1]);
        }else if(mx[2*k]>mx[2*k+1]){
            mx[k]=mx[2*k];mxc[k]=mxc[2*k];
            smx[k]=max(smx[2*k],mx[2*k+1]);
        }else{
            mx[k]=mx[2*k];mxc[k]=mxc[2*k]+mxc[2*k+1];
            smx[k]=max(smx[2*k],smx[2*k+1]);
        }
        if(mi[2*k]<mi[2*k+1]){
            mi[k]=mi[2*k];mic[k]=mic[2*k];
            smi[k]=min(smi[2*k],mi[2*k+1]);
        }else if(mi[2*k]>mi[2*k+1]){
            mi[k]=mi[2*k+1];mic[k]=mic[2*k+1];
            smi[k]=min(mi[2*k],smi[2*k+1]);
        }else{
            mi[k]=mi[2*k];mic[k]=mic[2*k]+mic[2*k+1];
            smi[k]=min(smi[2*k],smi[2*k+1]);
        }
    }
    void update_all(int k,int len,T x){
        mx[k]=x,smx[k]=-inf,mi[k]=x,smi[k]=inf;
        mxc[k]=len,mic[k]=len;
        sum[k]=x*len;
        lval[k]=x,ladd[k]=0;
    }
    
    public:

    SegmentTreeBeats(int n){
        sz=1;
        while(sz<n)sz<<=1;
        mx.resize(2*sz,-inf);smx.resize(2*sz,-inf);mxc.resize(2*sz,0);
        mi.resize(2*sz,inf);smi.resize(2*sz,inf);mic.resize(2*sz,0);
        sum.resize(2*sz,0);ladd.resize(2*sz,0);lval.resize(2*sz,inf);
    }
    void set(int k,T x){
        mx[k+sz]=x;mxc[k+sz]=1;
        mi[k+sz]=x;mic[k+sz]=1;
        sum[k+sz]=x;
    }
    void build(){
        for(int i=sz-1;i;i--) update_from_children(i);
    }
    // [a,b)を更新，[l,r)探索区間，k-node
    void chmin(int a,int b,T x,int k=1,int l=0,int r=-1){
        if(r==-1) r=sz;
        if(r<=a or b<=l or mx[k]<=x) return ;
        if(a<=l and r<=b and smx[k]<x){
            update_node_max(k,x);
            return ;
        }
        push(k,r-l);
        chmin(a,b,x,2*k,l,(l+r)/2);
        chmin(a,b,x,2*k+1,(l+r)/2,r);
        update_from_children(k);
    }
    void chmax(int a,int b,T x,int k=1,int l=0,int r=-1){
        if(r==-1) r=sz;
        if(r<=a or b<=l or mi[k]>=x) return ;
        if(a<=l and r<=b and smi[k]>x){
            update_node_min(k,x);
            return ;
        }
        push(k,r-l);
        chmax(a,b,x,2*k,l,(l+r)/2);
        chmax(a,b,x,2*k+1,(l+r)/2,r);
        update_from_children(k);
    }
    void add(int a,int b,T x,int k=1,int l=0,int r=-1){
        if(r==-1) r=sz;
        if(r<=a or b<=l) return ;
        if(a<=l and r<=b){
            update_node_add(k,r-l,x);
            return ;
        }
        push(k,r-l);
        add(a,b,x,2*k,l,(l+r)/2);
        add(a,b,x,2*k+1,(l+r)/2,r);
        update_from_children(k);
    }
    void update(int a,int b,T x,int k=1,int l=0,int r=-1){
        if(r==-1)r=sz;
        if(r<=a or b<=l) return ;
        if(a<=l and r<=b){
            update_all(k,r-l,x);
            return ;
        }
        push(k,r-l);
        update(a,b,x,2*k,l,(l+r)/2);
        update(a,b,x,2*k+1,(l+r)/2,r);
        update_from_children(k);
    }
    T query_sum(int a,int b,int k=1,int l=0,int r=-1){
        if(r==-1)r=sz;
        if(r<=a or b<=l)return 0;
        if(a<=l and r<=b) return sum[k];
        push(k,r-l);
        T lsum=query_sum(a,b,2*k,l,(l+r)/2);
        T rsum=query_sum(a,b,2*k+1,(l+r)/2,r);
        return lsum+rsum;
    }
    T query_min(int a,int b,int k=1,int l=0,int r=-1){
        if(r==-1)r=sz;
        if(b<=l or r<=a) return inf;
        if(a<=l and r<=b) return mi[k];
        push(k,r-l);
        T lmin=query_min(a,b,2*k,l,(l+r)/2);
        T rmin=query_min(a,b,2*k+1,(l+r)/2,r);
        return min(lmin,rmin);
    }
    T query_max(int a,int b,int k=1,int l=0,int r=-1){
        if(r==-1)r=sz;
        if(b<=l or r<=a) return -inf;
        if(a<=l and r<=b) return mx[k];
        push(k,r-l);
        T lmax=query_max(a,b,2*k,l,(l+r)/2);
        T rmax=query_max(a,b,2*k+1,(l+r)/2,r);
        return max(lmax,rmax);
    }
};

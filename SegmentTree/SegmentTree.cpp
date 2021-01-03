template<typename Monoid>
struct SegmentTree{
    int sz;
    vector<Monoid> seg;
    Monoid M0;// モノイドの元
    using F=function<Monoid(Monoid,Monoid)>;
    F f;
    SegmentTree(int n,Monoid M0,F f):M0(M0),f(f){
        sz=1;
        while(sz<n)sz<<=1;
        seg.assign(2*sz,M0);
    }
    void set(int k,Monoid x){
        seg[k+sz]=x;
    }
    void build(){
        for(int k=sz-1;k>0;k--) seg[k]=f(seg[2*k],seg[2*k+1]);
    }
    void update(int k,Monoid x){
        k+=sz;
        seg[k]=x;
        k>>=1;
        for(;k;k>>=1) seg[k]=f(seg[2*k],seg[2*k+1]);
    }
    Monoid query(int a,int b,int k=1,int l=0,int r=-1){
        if(r==-1) r=sz;
        if(a<=l and r<=b)   return seg[k];
        if(b<=l or r<=a)    return M0;
        Monoid L=query(a,b,2*k,l,(l+r)/2);
        Monoid R=query(a,b,2*k+1,(l+r)/2,r);
        return f(L,R);
    }
};
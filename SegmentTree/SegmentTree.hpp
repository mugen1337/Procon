template<typename Monoid>
struct SegmentTree{
    using F=function<Monoid(Monoid,Monoid)>;

    private:
    int sz;
    vector<Monoid> seg;

    Monoid query(int a,int b,int k,int l,int r){
        if(a<=l and r<=b)   return seg[k];
        if(b<=l or r<=a)    return M0;
        Monoid L=query(a,b,2*k,l,(l+r)/2);
        Monoid R=query(a,b,2*k+1,(l+r)/2,r);
        return f(L,R);
    }
    template<typename C>
    int find_first(int a,const C &check,Monoid &acc,int k,int l,int r){
        if(k>=sz){
            acc=f(acc,seg[k]);
            if(check(acc))  return -1;
            else            return k-sz;
        }
        int m=(l+r)/2;
        if(m<=a) return find_first(a,check,acc,2*k+1,m,r);
        if(a<=l and check(f(acc,seg[k]))){
            acc=f(acc,seg[k]);
            return -1;
        }
        int x=find_first(a,check,acc,2*k+0,l,m);
        if(x>=0) return x;
        return find_first(a,check,acc,2*k+1,m,r);
    }
    template<typename C>
    int find_last(int b,const C &check,Monoid &acc,int k,int l,int r){
        if(k>=sz){
            acc=f(acc,seg[k]);
            if(check(acc))  return -1;
            else            return k-sz+1;//ここはfalse, +1した位置はtrue
        }
        int m=(l+r)/2;
        if(b<=m) return find_last(b,check,acc,2*k,l,m);
        if(r<=b and check(f(acc,seg[k]))){
            acc=f(acc,seg[k]);
            return -1;
        }
        int x=find_last(b,check,acc,2*k+1,m,r);
        if(x>=0) return x;
        return find_last(b,check,acc,2*k,l,m);
    }

    public:

    F f;
    Monoid M0;// モノイドの元
    SegmentTree(int n, F f_, Monoid M0_) : f(f_), M0(M0_)
    {
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
    Monoid query(int a,int b){
        return query(a,b,1,0,sz);
    }
    Monoid operator[](const int &k)const{
        return seg[k+sz];
    }

    // http://codeforces.com/contest/914/submission/107505449
    // max x, check(query(a, x)) = true 
    template<typename C>
    int find_first(int a,const C &check){
        Monoid val=M0;
        return find_first(a,check,val,1,0,sz);
    }
    // http://codeforces.com/contest/914/submission/107505582
    // min x, check(query(x, b)) = true
    template<typename C>
    int find_last(int b,C &check){
        Monoid val=M0;
        return find_last(b,check,val,1,0,sz);
    }
};
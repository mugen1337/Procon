template<typename Monoid, typename OperatorMonoid=Monoid>
struct LazySegmentTree{
    using F=function<Monoid(Monoid,Monoid)>;
    using G=function<Monoid(Monoid,OperatorMonoid)>;
    using H=function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;
 
    private:
 
    int sz,height;
    vector<Monoid> data;
    vector<OperatorMonoid> lazy;
    // propagate lazy value -> data (node k)
    inline void propagate(int k){
        if(lazy[k]!=OM0){
            if(k<sz){
                lazy[2*k+0]=h(lazy[2*k+0],lazy[k]);
                lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);
            }
            data[k]=g(data[k],lazy[k]);
            lazy[k]=OM0;
        }
    }
 
    void update(int a,int b,const OperatorMonoid &x,int k,int l,int r){
        propagate(k);
        if(b<=l or r<=a) return ;
        if(a<=l and r<=b){
            lazy[k]=h(lazy[k],x);
            propagate(k);
        }else{
            update(a,b,x,2*k,l,(l+r)/2);
            update(a,b,x,2*k+1,(l+r)/2,r);
            data[k]=f(data[2*k],data[2*k+1]);
        }
    }
 
    Monoid query(int a,int b,int k,int l,int r){
        if(b<=l or r<=a) return M1;
 
        propagate(k);
        if(a<=l and r<=b) return data[k];
 
        Monoid L=query(a,b,2*k+0,l,(l+r)/2);
        Monoid R=query(a,b,2*k+1,(l+r)/2,r);
        return f(L,R);
    }
 
    public:
 
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;
 
    LazySegmentTree(int n,const F f,const G g,const H h,const Monoid &M1,const OperatorMonoid OM0)
    : f(f),g(g),h(h),M1(M1),OM0(OM0) {
        sz=1;height=0;
        while(sz<n) sz<<=1,height++;
        data.assign(2*sz,M1);lazy.assign(2*sz,OM0);
    }
 
    void set(int k,const Monoid &x){
        data[k+sz]=x;
    }
    void build(){
        for(int k=sz-1;k>0;k--) data[k]=f(data[2*k+0],data[2*k+1]);
    }
    void update(int a,int b,const OperatorMonoid &x){
        update(a,b,x,1,0,sz);
    }
    Monoid query(int a,int b){
        return query(a,b,1,0,sz);
    }
    Monoid operator[](const int &k){
        return query(k,k+1);
    }
}; 

// // range set range min
// using M=ll;
// using OM=ll;
// const M M1=LINF;
// const OM OM0=-LINF;
// M segf(M a,M b){
//     return (a<b?a:b);
// }
// M segg(M a,OM b){
//     return (b==OM0?a:b);
// }
// OM segh(OM a,OM b){
//     return (b==OM0?a:b);
// }
 
// // range set range max
// using M=ll;
// using OM=ll;
// const M M1=-LINF;
// const OM OM0=-LINF;
// M segf(M a,M b){
//     return (a>b?a:b);
// }
// M segg(M a,OM b){
//     return (b==OM0?a:b);
// }
// OM segh(OM a,OM b){
//     return (b==OM0?a:b);
// }
 
// // range add range min
// using M=ll;
// using OM=ll;
// const M M1=LINF;
// const OM OM0=0;
// M segf(M a,M b){
//     return (a<b?a:b);
// }
// M segg(M a,OM b){
//     return a+b;
// }
// OM segh(OM a,OM b){
//     return a+b;
// }
 
// // range add range max
// using M=ll;
// using OM=ll;
// const M M1=-LINF;
// const OM OM0=0;
// M segf(M a,M b){
//     return (a>b?a:b);
// }
// M segg(M a,OM b){
//     return a+b;
// }
// OM segh(OM a,OM b){
//     return a+b;
// }
 
// // range set range sum (sum, count)
// using M=pair<ll,ll>;
// using OM=ll;
// const M M1=M(0,0);
// const OM OM0=-LINF;
// M segf(M a,M b){
//     return M(a.first+b.first,a.second+b.second);
// }
// M segg(M a,OM b){
//     return M(a.second*b,a.second);
// }
// OM segh(OM a,OM b){
//     return (b==OM0?a:b);
// }

// // range add range sum (sum, count)
// using M=pair<ll,ll>;
// using OM=ll;
// const M M1=M(0,0);
// const OM OM0=0;
// M segf(M a,M b){
//     return M(a.first+b.first,a.second+b.second);
// }
// M segg(M a,OM b){
//     return M(a.first+a.second*b,a.second);
// }
// OM segh(OM a,OM b){
//     return a+b;
// }

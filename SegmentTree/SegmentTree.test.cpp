#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define mod 1000000007
using ll=long long;
const int INF=1000000000;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}
 
struct IOSetup{
    IOSetup(){
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout<<fixed<<setprecision(12);
    }
} iosetup;

template<typename T>
ostream &operator<<(ostream &os,const vector<T>&v){
    for(int i=0;i<(int)v.size();i++) os<<v[i]<<(i+1==(int)v.size()?"":" ");
    return os;
}

template<typename T>
istream &operator>>(istream &is,vector<T>&v){
    for(T &x:v)is>>x;
    return is;
}


#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

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

void solve(){
    int n,q;cin>>n>>q;

    auto segfunc=[](ll a,ll b){
        return a+b;
    };
    SegmentTree<ll> seg(n,0,segfunc);
    rep(i,n){
        ll a;cin>>a;
        seg.set(i,a);
    }
    seg.build();

    for(;q--;){
        int type;cin>>type;
        if(type==0){
            int p;ll x;cin>>p>>x;
            seg.update(p,seg.query(p,p+1)+x);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<seg.query(l,r)<<endl;
        }
    }

}

signed main(){
    solve();
    return 0;
}

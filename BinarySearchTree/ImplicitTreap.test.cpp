#include<bits/stdc++.h>
using namespace std;
#define ALL(x) begin(x),end(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define mod 998244353
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

//////  ↑ template  //////

#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
// ref: https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
// ref: https://ei1333.github.io/library/structure/bbst/randomized-binary-search-tree-lazy.cpp

template<typename Monoid,typename OperatorMonoid>
struct ImplicitTreap{

    private:

    inline int xorshift(){
        static int x=122312555;
        static int y=336261662;
        static int z=558127122;
        static int w=917277772;
        int t;
        t=x^(x<<11);
        x=y;y=z;z=w;
        return w=(w^(w>>19))^(t^(t>>8));
    }

    using F=function<Monoid(Monoid,Monoid)>;
    using G=function<Monoid(Monoid,OperatorMonoid)>;
    using H=function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;

    struct Node{
        Node *l,*r;
        int cnt,priority;
        Monoid val,acc;
        OperatorMonoid lazy;
        bool rev;
        Node()=default;
        Node(const Monoid &val,const OperatorMonoid &lazy,int priority):
        l(nullptr),r(nullptr),cnt(1),priority(priority),val(val),acc(val),lazy(lazy),rev(false){}
    } *root=nullptr;

    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;

    int count(const Node *t){return t?t->cnt:0;}
    Monoid acc(const Node *t){return t?t->acc:M1;}

    Node *update(Node *t){
        t->cnt=count(t->l)+count(t->r)+1;
        t->acc=f(f(acc(t->l),t->val),acc(t->r));
        return t;
    }
    Node *propagate(Node *t){
        if(t and t->rev){
            t->rev=false;
            swap(t->l,t->r);
            if(t->l) t->l->rev^=1;
            if(t->r) t->r->rev^=1;
        }
        if(t and t->lazy!=OM0){
            t->val=g(t->val,t->lazy);
            if(t->l){
                t->l->lazy=h(t->l->lazy,t->lazy);
                t->l->acc=g(t->l->acc,t->lazy);
            }
            if(t->r){
                t->r->lazy=h(t->r->lazy,t->lazy);
                t->r->acc=g(t->r->acc,t->lazy);
            }
            t->lazy=OM0;
        }
        return update(t);
    }

    Node *merge(Node *l,Node *r){
        if(!l or !r) return l?l:r;
        if(l->priority>r->priority){
            l=propagate(l);
            l->r=merge(l->r,r);
            return update(l);
        }else{
            r=propagate(r);
            r->l=merge(l,r->l);
            return update(r);
        }
    }
    pair<Node *,Node *> split(Node *t,int k){
        if(!t) return {nullptr,nullptr};
        t=propagate(t);
        if(k<=count(t->l)){
            auto s=split(t->l,k);
            t->l=s.second;
            return {s.first,update(t)};
        }else{
            auto s=split(t->r,k-count(t->l)-1);
            t->r=s.first;
            return {update(t),s.second};
        }
    }

    void insert(Node *&t,int k,const Monoid &x){
        auto s=split(t,k);
        t=merge(merge(s.first,new Node(x,OM0,xorshift())),s.second);
    }
    void erase(Node *&t,int k){
        auto s=split(t,k);
        t=merge(s.first,split(s.second,1).second);
    }

    Monoid query(Node *&t,int a,int b){
        if(a>b) return M1;
        auto x=split(t,a);
        auto y=split(x.second,b-a);
        auto ret=acc(y.first);
        t=merge(x.first,merge(y.first,y.second));
        return ret;
    }
    void update(Node *&t,int a,int b,const OperatorMonoid &o){
        if(a>b) return ;
        auto x=split(t,a);
        auto y=split(x.second,b-a);
        y.first->lazy=h(y.first->lazy,o);
        t=merge(x.first,merge(propagate(y.first),y.second));
    }
    void reverse(Node *&t,int a,int b){
        if(a>b) return ;
        auto x=split(t,a);
        auto y=split(x.second,b-a);
        y.first->rev^=1;
        t=merge(x.first,merge(y.first,y.second));
    }
    // [l,r)の先頭がmになるまで左シフト
    void rotate(Node *&t,int l,int m,int r){
        reverse(t,l,r);
        reverse(t,l,l+r-m);
        reverse(t,l+r-m,r);   
    }
    void dump(Node *t,typename vector<Monoid>::iterator &ite){
        if(!t) return ;
        t=propagate(t);
        dump(t->l,ite);
        *ite=t->val;
        dump(t->r,++ite);
    }

    public:

    ImplicitTreap(const F &f,const G &g,const H &h,const Monoid &M1,const OperatorMonoid &OM0):
        f(f),g(g),h(h),M1(M1),OM0(OM0){}

    int size(){return count(root);}
    bool empty(){return !root;}

    void build(const vector<Monoid> &v){
        if(v.empty()) return ;
        for(int i=(int)v.size()-1;i>=0;i--) insert(0,v[i]);
    }

    void insert(int k,const Monoid &x){insert(root,k,x);}
    void erase(int k){erase(root,k);}
    void reverse(int l,int r){reverse(root,l,r);}
    Monoid query(int l,int r){return query(root,l,r);}
    void update(int l,int r,const OperatorMonoid &x){update(root,l,r,x);}
    vector<Monoid> dump(){
        vector<Monoid> ret(size());
        auto ite=begin(ret);
        dump(root,ite);
        return ret;
    }

    Monoid operator[](int idx){return query(idx,idx+1);}
};

template<ll Mod>
struct ModInt{
    long long x;
    ModInt():x(0){}
    ModInt(long long y):x(y>=0?y%Mod:(Mod-(-y)%Mod)%Mod){}
    ModInt &operator+=(const ModInt &p){
        if((x+=p.x)>=Mod) x-=Mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p){
        if((x+=Mod-p.x)>=Mod)x-=Mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p){
        x=(int)(1ll*x*p.x%Mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p){
        (*this)*=p.inverse();
        return *this;
    }
    ModInt operator-()const{return ModInt(-x);}
    ModInt operator+(const ModInt &p)const{return ModInt(*this)+=p;}
    ModInt operator-(const ModInt &p)const{return ModInt(*this)-=p;}
    ModInt operator*(const ModInt &p)const{return ModInt(*this)*=p;}
    ModInt operator/(const ModInt &p)const{return ModInt(*this)/=p;}
    bool operator==(const ModInt &p)const{return x==p.x;}
    bool operator!=(const ModInt &p)const{return x!=p.x;}
    ModInt inverse()const{
        int a=x,b=Mod,u=1,v=0,t;
        while(b>0){
            t=a/b;
            swap(a-=t*b,b);swap(u-=t*v,v);
        }
        return ModInt(u);
    }
    ModInt pow(long long n)const{
        ModInt ret(1),mul(x);
        while(n>0){
            if(n&1) ret*=mul;
            mul*=mul;n>>=1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os,const ModInt &p){return os<<p.x;}
    friend istream &operator>>(istream &is,ModInt &a){long long t;is>>t;a=ModInt<Mod>(t);return (is);}
    static int get_mod(){return Mod;}
};
using mint=ModInt<mod>;

using M=pair<mint,mint>;
using OM=pair<mint,mint>;
const M M1=M(0,0);
const OM OM0=OM(1,0);
M segf(M a,M b){
    return M(a.first+b.first,a.second+b.second);
}
M segg(M a,OM b){
    return M(a.first*b.first+a.second*b.second,a.second);
}
OM segh(OM a,OM b){
    return OM(a.first*b.first,a.second*b.first+b.second);
}

signed main(){
    int n,q;cin>>n>>q;
    vector<mint> a(n);
    cin>>a;
    ImplicitTreap<M,OM> seg(segf,segg,segh,M1,OM0);
    reverse(ALL(a));
    for(auto x:a) seg.insert(0,{x,1});

    while(q--){
        int t;cin>>t;
        if(t==0){
            int i;mint x;cin>>i>>x;
            seg.insert(i,{x,1});
        }else if(t==1){
            int i;cin>>i;
            seg.erase(i);
        }else if(t==2){
            int l,r;cin>>l>>r;
            seg.reverse(l,r);
        }else if(t==3){
            int l,r;mint b,c;cin>>l>>r>>b>>c;
            seg.update(l,r,{b,c});
        }else{
            int l,r;cin>>l>>r;
            cout<<seg.query(l,r).first<<endl;
        }
    }
    return 0;
}
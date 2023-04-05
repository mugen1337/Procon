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
    void erase(int l,int r){
        auto x=split(root,l);
        auto y=split(x.second,r-l);
        root=merge(x.first,y.second);
    }
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
template<typename T>
struct Treap{

private:

    inline int xorshift() const {
        static int x=122312555;
        static int y=336261662;
        static int z=558127122;
        static int w=917277772;
        int t;
        t=x^(x<<11);
        x=y;y=z;z=w;
        return w=(w^(w>>19))^(t^(t>>8));
    }

    struct Node;
    using Ptr=unique_ptr<Node>;

    struct Node{
        Ptr l,r;
        int sz,pri;// priority
        T val;
        bool rev;
        Node()=default;
        Node(const T &val,int pri):
        l(nullptr),r(nullptr),sz(1),pri(pri),val(val),rev(false){}
    };
    Ptr root;

    explicit Treap(Ptr root):root(move(root)){}
    int size(Ptr &t)const{return (t?t->sz:0);}
    Ptr merge(Ptr l,Ptr r){
        if(!l) return move(r);
        if(!r) return move(l);
        push(l);push(r);
        if(l->pri>r->pri){
            l->r=merge(move(l->r),move(r));
            l->sz=size(l->l)+1+size(l->r);
            return move(l);
        }else{
            r->l=merge(move(l),move(r->l));
            r->sz=size(r->l)+1+size(r->r);
            return move(r);
        }
    }
    pair<Ptr,Ptr> split(Ptr t,int k){
        if(!t) return {nullptr,nullptr};
        push(t);
        if(k<=size(t->l)){
            auto x=split(move(t->l),k);
            t->l=move(x.second);
            t->sz=size(t->l)+1+size(t->r);
            return {move(x.first),move(t)};
        }else{
            auto x=split(move(t->r),k-size(t->l)-1);
            t->r=move(x.first);
            t->sz=size(t->l)+1+size(t->r);
            return {move(t),move(x.second)};
        }
    }
    T &access(Ptr &cur,int k){
        assert(cur);
        push(cur);
        if(k==size(cur->l)) return cur->val;
        if(k<size(cur->l))  return access(cur->l,k);
        else                return access(cur->r,k-1-size(cur->l));
    }
    void push(Ptr &t){
        if(t->rev){
            swap(t->l,t->r);
            if(t->l) t->l->rev^=true;
            if(t->r) t->r->rev^=true;
            t->rev=false;
        }
    }

public:

    Treap():root(nullptr){}

    void insert(int k,const T &x){
        auto s=split(move(root),k);
        Ptr i(new Node(x,xorshift()));
        root=merge(merge(move(s.first),move(i)),move(s.second));
    }

    void erase(int k){
        auto l=split(move(root),k);
        auto r=split(move(l.second),1);
        root=merge(move(l.first),move(r.second));
    }

    T &operator[](int k){ return access(root,k); }

    int size(){ return size(root); }

    void push_back(T x){
        Ptr b(new Node(x,xorshift()));
        root=merge(move(root),move(b));
    }
    void push_front(T x){
        Ptr f(new Node(x,xorshift()));
        root=merge(move(f),move(root));
    }
    void pop_back(){ root=split(move(root),1).second; }
    void pop_front(){ root=split(move(root),size()-1).second; }

    void reverse(int l,int r){
        auto x=split(move(root),l);
        auto y=split(move(x.second),r-l);
        y.first->rev^=true;
        root=merge(merge(move(x.first),move(y.first)),move(y.second));
    }

    void rotate(int l,int m,int r){
        reverse(l,r);
        reverse(l,l+r-m);
        reverse(l+r-m,r);
    }
    // [0, k) and [k, size)
    // cant use this after split
    pair<Treap<T>,Treap<T>> split(int k){
        auto x=split(move(root),k);
        return {Treap<T>(move(x.first)),Treap<T>(move(x.second))};
    }  
    // usage : auto new=l.merge(l, r);
    // cant use l and r after merge
    Treap<T> merge(Treap<T> &l,Treap<T> &r){
        return Treap<T>(merge(move(l.root),move(r.root)));
    }
};
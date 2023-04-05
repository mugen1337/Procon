template<typename Monoid>
struct SplayTree{
public:
    using F=function<Monoid(Monoid,Monoid)>;

    struct Node{
        Node *l,*r,*p;
        Monoid val,sum;
        int sz;
        bool rev;

        bool is_root(){ return !p; }

        Node(const Monoid &val):l(nullptr),r(nullptr),p(nullptr),
                                val(val),sum(val),sz(1),rev(false){}
    };

    const F f;
    const Monoid e;

    SplayTree(F f,Monoid e):f(f),e(e){}

    int size(Node *t){return t?t->sz:0;}
    Monoid sum(Node *t){return t?t->sum:e;}

    Node *build(const vector<Monoid> &v){
        return build(0,(int)v.size(),v);
    }

    Node *build(){
        return nullptr;
    }

    pair<Node *,Node *> split(Node *t,int k){
        if(!t) return {nullptr,nullptr};
        push(t);
        if(k<=size(t->l)){
            auto x=split(t->l,k);
            t->l=x.second;
            t->p=nullptr;
            if(x.second) x.second->p=t;
            return {x.first,update(t)};
        }else{
            auto x=split(t->r,k-size(t->l)-1);
            t->r=x.first;
            t->p=nullptr;
            if(x.first) x.first->p=t;
            return {update(t),x.second};
        }
    }
    
    Node *merge(Node *l,Node *r){
        if(!l and !r) return nullptr;
        if(!l){
            splay(r);
            return r;
        }
        if(!r){
            splay(l);
            return l;
        }
        splay(l);
        splay(r);
        l=get_right(l);
        splay(l);
        l->r=r;
        r->p=l;
        update(l);
        return l;
    }

    Node *insert(Node *&t,int k,Monoid val){
        assert(k<=size(t));
        if(!t){
            t=new Node(val);
            return t;
        }
        splay(t);
        auto x=split(t,k);
        t=merge(merge(x.first,new Node(val)),x.second);
        return t;
    }

    Node *erase(Node *&t,int k){
        splay(t);
        auto x=split(t,k);
        auto y=split(x.second,1);
        delete y.first;
        t=merge(x.first,y.second);
        return t;
    }

    // [a,b)
    Monoid query(Node *&t,int a,int b){
        splay(t);
        auto x=split(t,a);
        auto y=split(x.second,b-a);
        auto res=sum(y.first);
        t=merge(merge(x.first,y.first),y.second);
        return res;
    }

    Node *push_front(Node *t,Monoid x){
        if(!t){
            t=new Node(x);
            return t;
        }
        splay(t);
        Node *cur=get_left(t),*add=new Node(x);
        splay(cur);
        add->p=cur;
        cur->l=add;
        splay(add);
        return add;
    }

    Node *push_back(Node *t,Monoid x){
        if(!t){
            t=new Node(x);
            return t;
        }
        Node *cur=get_right(t),*add=new Node(x);
        splay(cur);
        add->p=cur;
        cur->r=add;
        splay(add);
        return add;
    }

    Node *reverse(Node *t,int a,int b){
        splay(t);
        auto x=split(t,a);
        auto y=split(x.second,b-a);
        y.first->rev^=true;
        t=merge(merge(x.first,y.first),y.second);
        return t;
    }

private:

    Node *build(int l,int r,const vector<Monoid> &v){
        // if(l>=r) return nullptr;
        if(l+1==r) return new Node(v[l]);
        int m=(l+r)/2;
        return merge(build(l,m,v),build(m,r,v));
    }
    Node *get_left(Node *cur)const{
        while(cur->l) cur=cur->l;
        return cur;
    }
    Node *get_right(Node *cur)const{
        while(cur->r) cur=cur->r;
        return cur;
    }
    // tを1個上に，右回転
    void rotr(Node *cur){
        auto *par=cur->p;
        auto *parpar=par->p;
        // A < cur < B < par < C 
        // ((A) - cur - (B)) - par - (C) 
        auto *B=cur->r;
        par->l=B;
        if(B) B->p=par;
        cur->r=par;
        par->p=cur;
        update(par);// parがcurの右子に変わった
        update(cur);
        cur->p=parpar;
        if(parpar){
            if(parpar->l==par) parpar->l=cur;
            if(parpar->r==par) parpar->r=cur;
            update(parpar);
        }
    }
    // tを1個上に，左回転
    void rotl(Node *cur){
        auto *par=cur->p;
        auto *parpar=par->p;
        // (C) - par - ((B) - cur - (A))
        // C < par < B < cur < A
        auto *B=cur->l;
        par->r=B;
        if(B) B->p=par;
        cur->l=par;
        par->p=cur;
        update(par);// parがcurの右子に変わった
        update(cur);
        cur->p=parpar;
        if(parpar){
            if(parpar->l==par) parpar->l=cur;
            if(parpar->r==par) parpar->r=cur;
            update(parpar);
        }
    }
    // 子から集約
    Node *update(Node *t){
        t->sz=1;
        t->sum=t->val;
        if(t->l) t->sz+=t->l->sz,t->sum=f(t->l->sum,t->sum);
        if(t->r) t->sz+=t->r->sz,t->sum=f(t->sum,t->r->sum);
        return t;
    }

    void push(Node *t){
        if(t->rev){
            if(t->l) toggle(t->l);
            if(t->r) toggle(t->r);
            t->rev=false;
        }
    }

    void toggle(Node *t){
        swap(t->l,t->r);
        t->rev^=true;
    }
    void splay(Node *cur){
        push(cur);
        while(!cur->is_root()){
            auto *par=cur->p;
            if(par->is_root()){// zig
                push(par);
                push(cur);
                if(par->l==cur) rotr(cur);
                else            rotl(cur);
            }else{// zig-zig, zig-zag
                auto *parpar=par->p;
                push(parpar);
                push(par);
                push(cur);
                if(parpar->l==par){
                    if(par->l==cur){// /
                        rotr(par);
                        rotr(cur);
                    }else{// く
                        rotl(cur);
                        rotr(cur);
                    }
                }else{
                    if(par->r==cur){
                        rotl(par);
                        rotl(cur);
                    }else{
                        rotr(cur);
                        rotl(cur);
                    }
                }
            }
        }
    }
};
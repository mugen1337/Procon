template<typename Monoid,typename OperatorMonoid=Monoid>
struct LazyLinkCutTree{

    using F=function<Monoid(Monoid,Monoid)>;
    using G=function<Monoid(Monoid,OperatorMonoid)>;
    using H=function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;
    using Flip=function<Monoid(Monoid)>;

    LazyLinkCutTree(int n,F f,G g,H h,Monoid e,OperatorMonoid oe,Flip flip=nullptr)
    :f(f),g(g),h(h),e(e),oe(oe),flip(flip){
        for(int i=0;i<n;i++) nodes.push_back(new Node(e,oe,i));
    }

    LazyLinkCutTree(const vector<Monoid> &v,F f,G g,H h,Monoid e,OperatorMonoid oe,Flip flip=nullptr)
    :f(f),g(g),h(h),e(e),oe(oe),flip(flip){
        for(int i=0;i<(int)v.size();i++) nodes.push_back(new Node(v[i],oe,i));
    }

    // v を root に
    void evert(int v){
        expose(nodes[v]);
        reverse(nodes[v]);
    }

    // link
    void link(int ch,int par){
        evert(ch);
        expose(nodes[par]);
        nodes[ch]->p=nodes[par];
        nodes[par]->r=nodes[ch];
        recalc(nodes[par]);
    }

    // cut v-(v->p)
    void cut(int v){
        expose(nodes[v]);
        nodes[v]->l->p=nullptr;
        nodes[v]->l=nullptr;
        recalc(nodes[v]);
    }
    // check u-v in E, cut u-v
    void cut(int u,int v){
        evert(u);
        expose(nodes[v]);
        assert(nodes[u]==nodes[v]->l);
        nodes[v]->l->p=nullptr;
        nodes[v]->l=nullptr;
        recalc(nodes[v]);
    }


    Monoid query(int u,int v){
        evert(u);
        expose(nodes[v]);

        return nodes[v]->sum;
    }

    void update(int u,int v,OperatorMonoid x){
        evert(u);
        expose(nodes[v]);
        propagate(nodes[v],x);
        push(nodes[v]);
    }
    
    int get_root(int v){
        Node *cur=nodes[v];
        expose(cur);
        while(cur->l){
            push(cur);
            cur=cur->l;
        }
        splay(cur);
        return cur->idx;
    }
    
    // not connected -> return -1
    int lca(int u,int v){
        if(!is_connected(u,v)) return -1;
        expose(nodes[u]);
        return expose(nodes[v]);
    }

    // faster than get_root(u)==get_root(v)
    bool is_connected(int u,int v){
        if(u==v) return true;
        expose(nodes[u]);
        expose(nodes[v]);
        return bool(nodes[u]->p);
    }

    // 未verify
    int depth(int v){
        expose(nodes[v]);
        return size(nodes[v])-1;
    }
    // 未verify
    // ヤバかったらpath queryで各頂点1をのせろ
    int distance(int u,int v){
        int p=lca(u,v);
        if(p<0) return -1;
        return depth(u)+depth(v)-depth(p)*2;
    }
    
private:
    struct Node{
        Node *l,*r,*p;
        Monoid val,sum;
        OperatorMonoid lazy;
        int sz,idx;
        bool rev;
        bool is_root()const{
            return (!p or (p->l!=(this) and p->r!=(this)));
        }
        Node(const Monoid &x,const OperatorMonoid &y,int idx)
            :l(nullptr),r(nullptr),p(nullptr),
            val(x),sum(x),lazy(y),sz(1),idx(idx),rev(false){}
    };

    const F f;
    const G g;
    const H h;
    const Monoid e;
    const OperatorMonoid oe;
    const Flip flip;
    vector<Node *> nodes;

    int expose(Node *t){
        Node *pre=nullptr;
        for(Node *cur=t;cur;cur=cur->p){
            splay(cur);
            cur->r=pre;
            recalc(cur);
            pre=cur;
        }
        splay(t);
        return pre->idx;
    }
    void rotr(Node *t){
        auto *x=t->p,*y=x->p;
        if((x->l=t->r)) t->r->p=x;
        t->r=x,x->p=t;
        recalc(x);
        recalc(t);
        if((t->p=y)){
            if(y->l==x) y->l=t;
            if(y->r==x) y->r=t;
            recalc(y);
        }
    }
    void rotl(Node *t){
        auto *x=t->p,*y=x->p;
        if((x->r=t->l))t->l->p=x;
        t->l=x,x->p=t;
        recalc(x);
        recalc(t);
        if((t->p=y)){
            if(y->l==x) y->l=t;
            if(y->r==x) y->r=t;
            recalc(y);
        }
    }

    int size(Node *t) const { return (t?t->sz:0); }

    void recalc(Node *t){
        t->sum=t->val;
        if(t->l) t->sum=f(t->l->sum,t->sum);
        if(t->r) t->sum=f(t->sum,t->r->sum);
    }

    void propagate(Node *t,OperatorMonoid x){
        t->lazy=h(t->lazy,x);
        t->val=g(t->val,x);
        t->sum=g(t->sum,x);
    }

    void push(Node *t){
        if(t->lazy!=oe){
            if(t->l) propagate(t->l,t->lazy);
            if(t->r) propagate(t->r,t->lazy);
            t->lazy=oe;
        }

        if(t->rev){
            if(t->l) reverse(t->l);
            if(t->r) reverse(t->r);
            t->rev=false;
        }
    }

    void reverse(Node *t){
        swap(t->l,t->r);
        if(flip) t->sum=flip(t->sum);
        t->rev^=true;
    }
    
    void splay(Node *cur){
        push(cur);
        while(!cur->is_root()){
            Node *par=cur->p;
            if(par->is_root()){// zig
                push(par);
                push(cur);
                if(par->l==cur) rotr(cur);
                else            rotl(cur);
            }else{// zig-zig, zig-zag
                Node *parpar=par->p;
                push(parpar);
                push(par);
                push(cur);
                if(parpar->l==par){
                    if(par->l==cur){rotr(par);rotr(cur);}
                    else           {rotl(cur);rotr(cur);}
                }else{
                    if(par->r==cur){rotl(par);rotl(cur);}
                    else           {rotr(cur);rotl(cur);}
                }
            }
        }
    }
};
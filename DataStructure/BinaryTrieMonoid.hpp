template<typename BitType,int MAXLOG,typename Monoid>
struct BinaryTrieMonoid{
    private:
    struct Node{
        Node *nxt[2];
        Monoid val;
        Node(Monoid val):nxt{nullptr,nullptr},val(val){}
    };

    Node *root;

    using F=function<Monoid(Monoid,Monoid)>;
    F f;
    const Monoid e;

    Monoid query(BitType a,BitType b,Node *cur,BitType l,BitType r,int dep,BitType xor_val){
        if(a<=l and r<=b) return (cur?cur->val:e);
        if(dep<0 or b<=l or r<=a or !cur) return e;
        bool x0=(xor_val>>dep)&1;
        Monoid L=query(a,b,cur->nxt[x0],l,(l+r)/2,dep-1,xor_val);
        Monoid R=query(a,b,cur->nxt[x0^1],(l+r)/2,r,dep-1,xor_val);
        return f(L,R);
    }
    void update(Node *cur,Monoid x,BitType bit,int dep){
        if(dep==-1){
            cur->val=x;
            return ;
        }
        bool go_to=(bit>>dep)&1;
        if(!cur->nxt[go_to]) cur->nxt[go_to]=new Node(e);
        update(cur->nxt[go_to],x,bit,dep-1);
        cur->val=f(cur->nxt[0]?cur->nxt[0]->val:e,cur->nxt[1]?cur->nxt[1]->val:e);
        return ;
    }

    public:
    BinaryTrieMonoid(F f,const Monoid &e):root(new Node(e)),f(f),e(e){}

    // fold [l,r)
    // xor_valを指定したとき，可換じゃない演算だと壊れると思います．多分
    Monoid query(BitType l,BitType r,BitType xor_val=0){
        return query(l,r,root,0,BitType(1)<<MAXLOG,MAXLOG-1,xor_val);
    }
    void update(BitType bit,Monoid x){
        update(root,x,bit,MAXLOG-1);
    }
    Monoid operator[](const BitType &k){
        return query(k,k+1);
    }
};
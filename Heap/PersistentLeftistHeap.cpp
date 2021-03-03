template<typename T,bool less=true>
struct PersistentLeftistHeap{
    struct Node{
        Node *l,*r;
        int s;
        T val;
        Node(T val):l(nullptr),r(nullptr),s(1),val(val){}
    };
    Node *root;
    PersistentLeftistHeap(Node *t=nullptr):root(t){}

    Node *meld(Node *a,Node *b){
        if(!a or !b) return (a?a:b);
        if((a->val>b->val)^(!less)) swap(a,b);
        a=new Node(*a);b=new Node(*b);
        a->r=meld(a->r,b);
        if(!a->l or a->l->s<a->r->s) swap(a->l,a->r);
        a->s=(a->r?a->r->s:0)+1;
        return a;
    }
    PersistentLeftistHeap meld(PersistentLeftistHeap b){
        return PersistentLeftistHeap(meld(root,b.root));
    }
    PersistentLeftistHeap push(T x){
        return PersistentLeftistHeap(meld(root,new Node(x)));
    }
    PersistentLeftistHeap pop(){
        assert(root!=nullptr);
        return PersistentLeftistHeap(meld(root->l,root->r));
    }
    T top(){
        assert(root!=nullptr);
        return root->val;
    }
};
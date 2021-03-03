template<typename T,bool less=true>
struct LeftistHeap{
    struct Node{
        Node *l,*r;
        int s;
        T val;
        Node(T val):l(nullptr),r(nullptr),s(1),val(val){}
    };
    Node *root;
    LeftistHeap(Node *t=nullptr):root(t){}

    virtual Node *clone(Node *t){
        return t;
    }

    Node *meld(Node *a,Node *b){
        if(!a or !b) return (a?a:b);
        a=clone(a);
        if((a->val>b->val)^(!less)) swap(a,b);
        a->r=meld(a->r,b);
        if(!a->l or a->l->s<a->r->s) swap(a->l,a->r);
        a->s=(a->r?a->r->s:0)+1;
        return a;
    }
    void meld(LeftistHeap b){
        root=meld(root,b.root);
    }
    void push(T x){
        root=meld(root,new Node(x));
    }
    T pop(){
        assert(root!=nullptr);
        T ret=root->val;
        root=meld(root->l,root->r);
        return ret;
    }
    T top(){
        assert(root!=nullptr);
        return root->val;
    }
};
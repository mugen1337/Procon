template<typename BitType,int MAXLOG,typename C=int>
struct BinaryTrie{
    private:
    struct Node{
        Node *nxt[2];
        C cnt;
        Node():nxt{nullptr,nullptr},cnt(0){}
    };

    Node *root;

    Node *find(BitType bit,BitType xor_val=0){
        Node *cur=root;
        for(int i=MAXLOG-1;i>=0;i--){
            bool target=(xor_val>>i)&1;
            bool go_to=target^((bit>>i)&1);
            if(!cur->nxt[go_to]) return nullptr;
            cur=cur->nxt[go_to];
        }
        return cur;
    }

    public:
    BinaryTrie():root(new Node()){}

    void add(BitType bit,C c=1,BitType xor_val=0){
        Node *cur=root;
        for(int i=MAXLOG-1;i>=0;i--){
            bool target=(xor_val>>i)&1;
            bool go_to=target^((bit>>i)&1);
            if(!cur->nxt[go_to]) cur->nxt[go_to]=new Node();
            cur->cnt+=c;
            cur=cur->nxt[go_to];
        }
        cur->cnt+=c;
        return ;
    }
    void erase(BitType bit,C c=1,BitType xor_val=0){
        add(bit,-c,xor_val);
    }
    BitType kth_element(C k,BitType xor_val=0){
        assert(0<=k and k<root->cnt);
        C ret=0;
        Node *cur=root;
        for(int i=MAXLOG-1;i>=0;i--){
            bool xored_0=(xor_val>>i)&1;
            if(!cur->nxt[xored_0] or  cur->nxt[xored_0]->cnt<=k){
                k-=(cur->nxt[xored_0]?cur->nxt[xored_0]->cnt:0);
                cur=cur->nxt[xored_0^1];
                ret+=(BitType(1)<<i);
            }else{
                cur=cur->nxt[xored_0];
            }
        }
        return ret;
    }
    BitType min_element(BitType xor_val=0){
        return kth_element(0,xor_val);
    }
    BitType max_element(BitType xor_val=0){
        return kth_element(root->cnt-1,xor_val);
    }
    C count(BitType bit,BitType xor_val=0){
        auto target=find(bit,xor_val);
        return target?target->cnt:0;
    }
    C count_less(BitType bit,BitType xor_val=0){
        C ret=0;
        Node *cur=root;
        for(int i=MAXLOG-1;i>=0;i--){
            if(!cur) break;
            bool xored_0=(xor_val>>i)&1;
            if((bit>>i)&1 and cur->nxt[xored_0]) ret+=cur->nxt[xored_0]->cnt;
            cur=cur->nxt[xored_0^((bit>>i)&1)];
        }
        return ret;
    }
};
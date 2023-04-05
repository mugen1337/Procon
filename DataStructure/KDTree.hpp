template<typename T>
struct KDTree{
    private:
    using P=pair<T,T>;
    struct Node{
        Node *l, *r;
        P p;
        Node(Node *l,Node *r,P p):l(l),r(r),p(p){}
    };
    Node *root;
    Node *dfs(int l,int r,int dep,vector<P> &v){
        if(r<=l) return nullptr;
        int m=(l+r)/2;
        if(dep) sort(begin(v)+l,begin(v)+r,[](P lhs,P rhs){return lhs.first<rhs.first;});
        else    sort(begin(v)+l,begin(v)+r,[](P lhs,P rhs){return lhs.second<rhs.second;});
        return (new Node(dfs(l,m,dep^1,v),dfs(m+1,r,dep^1,v),v[m]));
    }
    pair<T,P> find_nearest(Node *cur,T x,T y,int dep,T d,P cur_best){
        if(!cur) return pair<T,P>(d,cur_best);
        ll nd=dis(cur->p,P(x,y));
        if(nd<d) d=nd,cur_best=cur->p;

        if(dep){
            if(cur->l and x-d<=cur->p.first) tie(d,cur_best)=find_nearest(cur->l,x,y,dep^1,d,cur_best);
            if(cur->r and cur->p.first<=x+d) tie(d,cur_best)=find_nearest(cur->r,x,y,dep^1,d,cur_best);
        }else{
            if(cur->l and y-d<=cur->p.second) tie(d,cur_best)=find_nearest(cur->l,x,y,dep^1,d,cur_best);
            if(cur->r and cur->p.second<=y+d) tie(d,cur_best)=find_nearest(cur->r,x,y,dep^1,d,cur_best);
        }
        return pair<T,P>(d,cur_best);
    }


    public:
    KDTree(vector<P> v){
        root=dfs(0,(int)v.size(),0,v);
    }
    inline T dis(P lhs,P rhs){
        return (lhs.first-rhs.first)*(lhs.first-rhs.first)+(lhs.second-rhs.second)*(lhs.second-rhs.second);
    }
    // return  pair(dis, pair(x, y))
    pair<T,P> find_nearest(T x,T y){
        return find_nearest(root,x,y,0,numeric_limits<T>::max()/2,P(0,0));
    }
};

#include "./GraphTemplate.cpp"

template<typename T>
struct PersistentLeftistHeapNode{
    PersistentLeftistHeapNode *l,*r;
    int s;
    T val;
    PersistentLeftistHeapNode(T val):l(nullptr),r(nullptr),s(1),val(val){}
};

template<typename T,bool less=true>
struct PersistentLeftistHeap{
    PersistentLeftistHeapNode<T> *root;
    PersistentLeftistHeap(PersistentLeftistHeapNode<T> *t=nullptr):root(t){}

    PersistentLeftistHeapNode<T> *meld(PersistentLeftistHeapNode<T> *a,PersistentLeftistHeapNode<T> *b){
        if(!a or !b) return (a?a:b);
        if((a->val>b->val)^(!less)) swap(a,b);
        a=new PersistentLeftistHeapNode(*a);
        a->r=meld(a->r,b);
        if(!a->l or a->l->s<a->r->s) swap(a->l,a->r);
        a->s=(a->r?a->r->s:0)+1;
        return a;
    }
    PersistentLeftistHeap meld(PersistentLeftistHeap b){
        return PersistentLeftistHeap(meld(root,b.root));
    }
    PersistentLeftistHeap push(T x){
        return PersistentLeftistHeap(meld(root,new PersistentLeftistHeapNode(x)));
    }
    PersistentLeftistHeap pop(){
        assert(root!=nullptr);
        return PersistentLeftistHeap(meld(root->l,root->r));
    }
    bool empty(){
        return (root==nullptr);
    }
    T top(){
        assert(root!=nullptr);
        return root->val;
    }
};

// ref: https://qiita.com/hotman78/items/42534a01c4bd05ed5e1e
// K Shortest Walk
template<typename T>
vector<T> Eppstein(Graph<T> &G,int s,int t,int k){
    int N=G.V,M=G.E;
    T inf=numeric_limits<T>::max();

    Graph<T> rG(N);
    vector<Edge<T>> edges(M);
    for(int i=0;i<N;i++)for(auto &e:G[i]) edges[e.idx]=e;
    for(auto &e:edges) rG.add_directed_edge(e.to,e.from,e.w);

    // Dijkstra rG, make Tree
    vector<int> prev_e(N,-1),prev_v(N,-1);
    vector<T> dis(N,inf);
    vector<vector<int>> tree(N);
    vector<bool> tree_edge(M,false);
    {
        using P=pair<T,int>;
        priority_queue<P,vector<P>,greater<P>> que;
        dis[t]=0;
        que.emplace(dis[t],t);
        while(!que.empty()){
            auto [d_cur,cur]=que.top();que.pop();
            if(dis[cur]<d_cur) continue;
            for(auto &e:rG[cur])if(chmin(dis[e.to],d_cur+e.w)){
                prev_e[e.to]=e.idx;
                prev_v[e.to]=cur;
                que.emplace(dis[e.to],e.to);
            }
        }

        if(dis[s]>=inf) return {};
        for(auto &i:prev_e)if(i>=0) tree[edges[i].to].push_back(edges[i].from),tree_edge[i]=true;
    }

    // make H_G
    vector<PersistentLeftistHeap<pair<T,int>>> H_G(N);// (potential, edge index)
    {
        function<void(int)> dfs=[&](int cur){
            if(prev_v[cur]>=0) H_G[cur]=H_G[cur].meld(H_G[prev_v[cur]]);
            for(auto &e:G[cur]){
                if(e.to!=t and prev_v[e.to]<0) continue; // cant reach
                if(tree_edge[e.idx]) continue;
                H_G[cur]=H_G[cur].push({e.w-dis[cur]+dis[e.to],e.idx});
            }
            for(auto &to:tree[cur]) dfs(to);
        };
        dfs(t);
    }
    

    // return KSP
    vector<T> ret;
    {
        using P_TN=pair<T,PersistentLeftistHeapNode<pair<T,int>>*>;
        auto comp=[](const P_TN &x,const P_TN &y){return x.first>y.first;};
        priority_queue<P_TN,vector<P_TN>,decltype(comp)> que(comp);
        ret.push_back(dis[s]);
        if(H_G[s].root) que.emplace(dis[s]+H_G[s].root->val.first,H_G[s].root);
        while(!que.empty() and (int)ret.size()<k){
            auto [cost,cur]=que.top();que.pop();
            ret.emplace_back(cost);

            int to=edges[cur->val.second].to;
            if(H_G[to].root) que.emplace(cost+H_G[to].root->val.first,H_G[to].root);

            if(cur->l) que.emplace(cost+cur->l->val.first-cur->val.first,cur->l);
            if(cur->r) que.emplace(cost+cur->r->val.first-cur->val.first,cur->r);
        }
    }
    return ret;
}
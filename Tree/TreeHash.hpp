// hash type
using ull=unsigned long long;
struct TreeHasher{
    using uint128=__uint128_t;
    static const ull Mod=(1ull<<61ull)-1;
    static inline ull add(ull a,ull b){if((a+=b)>=Mod)a-=Mod;return a;}
    static inline ull mul(ull a,ull b){uint128 c=(uint128)a*b;return add(c>>61,c&Mod);}
    vector<ull> R;


    // 木のサイズ
    TreeHasher(int n){
        R.push_back(1);
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<ull> rand(1,Mod-1);
        for(int i=1;i<=n;i++) R.push_back(rand(mt));
        // R.resize(n+1);
        // iota(ALL(R),1);
    }
    inline vector<int> BFS(vector<vector<int>> &g,int st,vector<int> &dis,bool memo_parent=false){
        vector<int> par;
        if(memo_parent) par.assign(g.size(),-1);
        dis.assign(g.size(),-1);
        dis[st]=0;
        queue<int> que;
        que.push(st);
        while(!que.empty()){
            int cur=que.front();que.pop();
            for(auto &to:g[cur]){
                if(dis[to]>=0) continue;
                dis[to]=dis[cur]+1;
                if(memo_parent) par[to]=cur;
                que.push(to);
            }
        }
        return par;
    }

    // 木の中心(直径の真ん中)を返す
    vector<int> center(vector<vector<int>> &g){
        vector<int> d;
        BFS(g,0,d);
        int u=max_element(begin(d),end(d))-begin(d);
        
        auto par=BFS(g,u,d,true);
        int v=max_element(begin(d),end(d))-begin(d);
        int diameter=d[v];
        for(int i=0;i<diameter/2;i++) v=par[v];
        vector<int> ret;
        ret.push_back(v);
        if(diameter%2) ret.push_back(par[v]);
        return ret;
    }

    ull RootedTreeHash(vector<vector<int>> &g,int root){
        vector<int> dis(g.size(),-1);
        vector<ull> h(g.size());
        function<void(int,int)> dfs=[&](int par,int cur){
            int d=-1;
            for(auto &to:g[cur])if(par!=to){
                dfs(cur,to);
                chmax(d,dis[to]);
            }
            d++;
            dis[cur]=d;
            ull ret=1;
            // rng hash
            for(auto &to:g[cur])if(par!=to) ret=mul(ret,add(h[to],R[d]));
            h[cur]=ret;
        };
        dfs(-1,root);
        return h[root];
    }
    // 木の中心からhashをとる．木の中心は2個ある可能性がある
    ull TreeHash(vector<vector<int>> &g){
        auto centers=center(g);
        ull ret=RootedTreeHash(g,centers[0]);
        if(centers.size()==2) ret=min(ret,RootedTreeHash(g,centers[1]));
        return ret;
    }
    bool RootedTreeIsomorphic(vector<vector<int>> &g,int g_root,vector<vector<int>> &h,int h_root){
        if(g.size()!=h.size()) return false;
        return (RootedTreeHash(g,g_root)==RootedTreeHash(h,h_root));
    }
    bool TreeIsomorphic(vector<vector<int>> &g,vector<vector<int>> &h){
        if(g.size()!=h.size()) return false;
        return (TreeHash(g)==TreeHash(h));
        }
};
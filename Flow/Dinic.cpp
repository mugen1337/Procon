template<typename T>
struct Dinic{
    private:
    vector<int> lv,iter;
    // 増加道
    bool bfs(int s,int t){
        lv.assign(g.size(),-1);
        queue<int> que;
        lv[s]=0;
        que.push(s);
        while(!que.empty() and lv[t]==-1){
            int p=que.front();que.pop();
            for(auto &e:g[p]){
                if(e.cap>0 and lv[e.to]==-1){
                    lv[e.to]=lv[p]+1;
                    que.push(e.to);
                }
            }
        }
        return lv[t]!=-1;
    }
    T dfs(int cur,int t,T flow){
        if(cur==t) return flow;
        for(int &i=iter[cur];i<(int)g[cur].size();i++){
            edge &e=g[cur][i];
            if(e.cap>0 and lv[cur]<lv[e.to]){
                T d=dfs(e.to,t,min(flow,e.cap));
                if(d>0){
                    e.cap-=d;
                    g[e.to][e.rev].cap+=d;
                    return d;
                }
            }
        }
        return 0;
    }

    public:
    const T inf;
    struct edge{
        int to;
        T cap;
        int rev;
        bool isrev;
        int idx;
        edge(int to,T cap,int rev,bool isrev,int idx)
        :to(to),cap(cap),rev(rev),isrev(isrev),idx(idx){}
        edge(){}
    };
    vector<vector<edge>> g;

    Dinic(int V):inf(numeric_limits<T>::max()/2),g(V){}

    void add_edge(int from,int to,T cap,int idx=-1){
        g[from].emplace_back(to,cap,(int)g[to].size(),false,idx);
        g[to].emplace_back(from,0,(int)g[from].size()-1,true,idx);
    }

    T max_flow(int s,int t,T lim){
        T ret=0;
        while(lim>0 and bfs(s,t)){
            iter.assign(g.size(),0);
            while(true){
                T f=dfs(s,t,lim);
                if(f==0) break;
                ret+=f;
                lim-=f;
            }
        }
        return ret;
    }
    T max_flow(int s,int t){
        return max_flow(s,t,inf);
    }

    // g[u][u_idx]を切る
    // idx>=0 ならindex指定して切る．
    // idx<0  なら全部切る
    T cut(int s,int t,int u,int v,int idx=-1){
        T cr=0;
        for(auto &e:g[u])if(e.to==v and !e.isrev){
            if(idx<0 or idx==e.idx){
                cr+=g[v][e.rev].cap;
                e.cap=0;
                g[v][e.rev].cap=0;
            }
        }
        if(cr==0) return 0;
        // 迂回して流しなおす
        T cap=cr-max_flow(u,v,cr);
        // 流せなかった分を補正する
        if(u!=s and cap!=0) max_flow(u,s,cap);
        if(v!=t and cap!=0) max_flow(t,v,cap);
        return cap;
    }
    // u -> vの容量をfだけ増やす
    T add(int s,int t,int u,int v,T f,int idx=-1){
        add_edge(u,v,f,idx);
        return max_flow(s,t,f);
    }
};
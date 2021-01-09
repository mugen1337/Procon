template<typename T>
struct Dijkstra{
    const T TINF=numeric_limits<T>::max();
    using P=pair<T,int>;
    int n;
    vector<vector<P>> G;
    vector<T> d;
    vector<int> prev;
  
    Dijkstra(int n):n(n),G(vector<vector<P>>(n)){}
    void init(){
        d.assign(n,TINF);
        prev.assign(n,-1);
    }
    void add_edge(int s,int t,T cost){
        G[s].push_back(P(cost,t));
    }
    void build(int s){
        init();
        d[s]=0;
        priority_queue<P,vector<P>,greater<P>> q;
        q.push(P(d[s],s));
        while(!q.empty()){
            P p=q.top();q.pop();
            int v=p.second;
            if(d[v]<p.first) continue;
            for(auto e:G[v]){
                int u=e.second;
                T cost=e.first;
                if(d[u]>d[v]+e.first){
                    d[u]=d[v]+cost;
                    prev[u]=v;
                    q.push(P(d[u],u));
                }
            }
        }
    }
 
    T operator[](const int &p)const{
        return d[p];
    }
 
    vector<int> get_path(int g){
        vector<int> ret;
        if(d[g]==TINF) return ret;
        for(;g!=-1;g=prev[g]){
            ret.push_back(g);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
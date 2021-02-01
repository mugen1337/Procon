#include "./GraphTemplate.cpp"

template<typename T>
struct Dijkstra{
    const T inf;
    Graph<T> g;
    vector<T> d;
    vector<int> prev;
    
    Dijkstra(Graph<T> g):inf(numeric_limits<T>::max()/2),g(g){}

    vector<T> build(int st){
        d.assign(g.V,inf);
        prev.assign(g.V,-1);
        d[st]=0;
        priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;
        que.emplace(d[st],st);
        while(!que.empty()){
            auto p=que.top();que.pop();
            int cur=p.second;
            if(d[cur]<p.first) continue;
            for(auto &e:g[cur]){
                if(d[e]>d[cur]+e.w){
                    d[e]=d[cur]+e.w;
                    prev[e]=cur;
                    que.emplace(d[e],e);
                }
            }
        }
        return d;
    }
    
    vector<int> get_path(int gl){
        vector<int> ret;
        if(d[g]==inf) return ret;
        for(;g!=-1;g=prev[g]) ret.push_back(g);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
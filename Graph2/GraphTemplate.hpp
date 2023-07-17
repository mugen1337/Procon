#ifndef GRAPH_TEMPLATE_
#define GRAPH_TEMPLATE_

// graph template
// ref : https://ei1333.github.io/library/graph/graph-template.hpp
template<typename T=int>
struct Edge{
    int from,to;
    T w;
    int idx;
    Edge()=default;
    Edge(int from,int to,T w=1,int idx=-1):from(from),to(to),w(w),idx(idx){}
    operator int() const{return to;}
};

template<typename T=int>
struct Graph{
    vector<vector<Edge<T>>> g;
    int V,E;
    Graph()=default;
    Graph(int n):g(n),V(n),E(0){}

    int size(){
        return (int)g.size();
    }
    void resize(int k){
        g.resize(k);
        V=k;
    }
    inline const vector<Edge<T>> &operator[](int k)const{
        return (g.at(k));
    }
    inline vector<Edge<T>> &operator[](int k){
        return (g.at(k));
    }
    void add_directed_edge(int from,int to,T cost=1){
        g[from].emplace_back(from,to,cost,E++);
    }
    void add_edge(int from,int to,T cost=1){
        g[from].emplace_back(from,to,cost,E);
        g[to].emplace_back(to,from,cost,E++);
    }
    void read(int m,int pad=-1,bool weighted=false,bool directed=false){
        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            u+=pad,v+=pad;
            T w=T(1);
            if(weighted) cin>>w;
            if(directed) add_directed_edge(u,v,w);
            else         add_edge(u,v,w);
        }
    }
};

#endif /* GRAPH_TEMPLATE_ */

#include "./GraphTemplate.hpp"

/*
verified : https://codeforces.com/contest/786/submission/131901643

vertex -> [sz, sz*2)
map [sz * 3, sz * 4) -> [sz, sz*2)
 
他のグラフライブラリに適用させたい場合
    RangeEdgeGraph.Gを他のライブラリに渡す．
    元グラフの頂点uの結果を得たい場合はRangeEdgeGraph[u]が
    RangeEdgeGraph.Gの頂点に対応するのでとれる．
*/
template<typename T>
struct RangeEdgeGraph{
public:
    int N,M,sz;
    Graph<T> G;
 
    RangeEdgeGraph(int N,int M):N(N),M(M){
        sz=1,p=0;
        while(sz<N) sz<<=1;
        G=Graph<T>(sz*3+M);
 
        for(int i=1;i<sz;i++){
            G.add_directed_edge(i,i*2,  0);
            G.add_directed_edge(i,i*2+1,0);
 
            G.add_directed_edge(fix(i*2+sz*2),  i+sz*2,0);
            G.add_directed_edge(fix(i*2+1+sz*2),i+sz*2,0);
        }
    }
 
    void add_edge(int from_l,int from_r,int to_l,int to_r,T w=1){
        assert(p<M);
        int t=(p++)+sz*3;
        for(from_l+=sz,from_r+=sz;from_l<from_r;from_l>>=1,from_r>>=1){
            if(from_l&1) G.add_directed_edge(fix((from_l++)+sz*2),t,0);
            if(from_r&1) G.add_directed_edge(fix((--from_r)+sz*2),t,0);
        }
        for(to_l+=sz,to_r+=sz;to_l<to_r;to_l>>=1,to_r>>=1){
            if(to_l&1) G.add_directed_edge(t,(to_l++),w);
            if(to_r&1) G.add_directed_edge(t,(--to_r),w);
        }
    }
 
    int get(const int &u) const { return u+sz; }
    int operator[](const int &k) const {return get(k);}
 
private:
    int p;
    int fix(int u){
        if(u>=3*sz) return u-=2*sz;
        return u;
    }
};
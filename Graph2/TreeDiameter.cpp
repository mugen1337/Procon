#include "./GraphTemplate.cpp"

template<typename T>
pair<T,vector<int>> TreeDiameter(const Graph<T> &g){
    assert(g.V==g.E+1);
    vector<T> dis(g.V);
    vector<int> pre(g.V,-1);
    dis[0]=0;
    function<void(int,int)> dfs=[&g,&dfs,&dis,&pre](int par,int cur){
        for(auto &e:g[cur])if(par!=e.to){
            dis[e.to]=dis[cur]+e.w;
            pre[e.to]=cur;
            dfs(cur,e.to);
        }
    };
    dfs(-1,0);
    int l=max_element(ALL(dis))-begin(dis);
    dis[l]=0;
    pre.assign(g.V,-1);
    dfs(-1,l);
    int r=max_element(ALL(dis))-begin(dis);
    vector<int> path;
    for(int i=r;i!=-1;i=pre[i]) path.push_back(i);
    return make_pair(dis[r],path);
}
#include "./GraphTemplate.cpp"

template<typename T>
struct LowLink{
    Graph<T> &g;
    vector<int> ord,low;
    vector<int> art;// articulation (true/false)
    vector<Edge<T>> bridge;

    LowLink(Graph<T> &g):g(g){
        ord.assign(g.V,-1);
        low.assign(g.V,-1);
        art.resize(g.V);

        int idx=0;
        function<void(int,int)> dfs=[&](int pre,int cur){
            ord[cur]=idx++;
            low[cur]=ord[cur];

            int pre_c=0,ch=0;
            bool art_f=false;

            for(auto &e:g[cur]){
                if(e==pre and pre_c==0){
                    pre_c++;
                    continue;
                }
                if(ord[e]<0){
                    ch++;
                    dfs(cur,e);
                    low[cur]=min(low[cur],low[e]);
                    art_f|=(pre>=0 and low[e]>=ord[cur]);
                    if(ord[cur]<low[e]) bridge.push_back(e);
                }
                else{
                    low[cur]=min(low[cur],ord[e]);
                }
            }
            if(pre==-1) art_f|=(ch>1);
            art[cur]=art_f;
            return ;
        };
        for(int i=0;i<g.V;i++)if(ord[i]<0) dfs(-1,i);
    }
};
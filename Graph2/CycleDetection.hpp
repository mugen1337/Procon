#include "./GraphTemplate.hpp"

template<typename T>
vector<int> CycleDetection(Graph<T> &g){
    int n=(int)g.size();
    vector<int> check(n,0),cyc,pre(n,-1);

    function<bool(int)> dfs=[&](int cur){
        check[cur]=1;
        for(auto &to:g[cur]){
            if(check[to]==0){
                pre[to]=cur;
                if(dfs(to)) return true;
            }else if(check[to]==1){// detect
                int v=cur;
                while(v!=to){
                    cyc.push_back(v);
                    v=pre[v];
                }
                cyc.push_back(v);
                return true;
            }
        }
        check[cur]=2;
        return false;
    };

    for(int i=0;i<n;i++){
        if(check[i]==0){
            if(dfs(i)){
                reverse(begin(cyc),end(cyc));
                return cyc;
            }
        }
    }
    return {};
}
#include "./GraphTemplate.hpp"

template<typename T,typename GT=int>
struct Rerooting{
    using E=function<T(T,Edge<GT>)>;//集合，頂点番号
    using M=function<T(T,T)>;
    using F=function<T(T,int)>;
    
    Graph<GT> g;
    // dp_v = fix(merge(f(dp_c1,edge(v,c1)),...,f(dp_ck,edge(v,ck))),v)
    E f;    // f(T,Edge)->T  辺情報を考慮し，merge前の形
    M merge;// TxT->T，子を集約する関数，モノイド
    T e;    // mergeの単位元
    F fix;  // TxN->T  補正
    vector<vector<T>> dp;
    vector<T> ans;
    
    Rerooting(Graph<GT> &g,E f,M merge,T e,F fix=[](T a,int b){return a;}):
    g(g),f(f),merge(merge),e(e),fix(fix),dp(g.size()),ans(g.size(),e){}

    T dfs1(int pre,int now){
        T ret=e;
        for(int i=0;i<(int)g[now].size();i++)if(g[now][i]!=pre){
            dp[now][i]=dfs1(now,g[now][i]);
            ret=merge(ret,f(dp[now][i],g[now][i]));
        }
        return fix(ret,now);
    }
    void dfs2(int pre,int now,T frompar){
        for(int i=0;i<(int)g[now].size();i++){
            if(g[now][i]==pre){
                dp[now][i]=frompar;
                break;
            }
        }
        vector<T> lsum(g[now].size()+1),rsum(g[now].size()+1);//親も混ぜて累積
        lsum[0]=e;rsum[g[now].size()]=e;
        for(int i=0;i<(int)g[now].size();i++) lsum[i+1]=merge(lsum[i],f(dp[now][i],g[now][i]));
        for(int i=(int)g[now].size();i>0;i--) rsum[i-1]=merge(rsum[i],f(dp[now][i-1],g[now][i-1]));
        for(int i=0;i<(int)g[now].size();i++)if(g[now][i]!=pre){
            T fromme=merge(lsum[i],rsum[i+1]);
            dfs2(now,g[now][i],fix(fromme,now));
        }
    }
    void build(int root=0){
        for(int i=0;i<(int)g.size();i++) dp[i].resize(g[i].size());
        dfs1(-1,root);
        dfs2(-1,root,e);
        for(int i=0;i<(int)g.size();i++){
            for(int j=0;j<(int)g[i].size();j++) ans[i]=merge(ans[i],f(dp[i][j],g[i][j]));
            ans[i]=fix(ans[i],i);
        }
    }
};
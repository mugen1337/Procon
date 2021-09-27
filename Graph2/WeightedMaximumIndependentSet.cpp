#include "./GraphTemplate.cpp"

/*
verify: https://onlinejudge.u-aizu.ac.jp/beta/review.html#ACPC2021Day2/5917572
頂点をグループA, Bに分ける．
Bでは
dp_B[S]:= (Sの部分集合のうち，重みの和が最大になる独立集合)
を求めておく．
A側で全探索し，とれる集合を求め，最大値を求める．
*/
template<typename T,typename GT=int>
T WeightedMaximumIndependentSet(Graph<GT> G,vector<T> W){
    assert(G.size()==(int)W.size());
    assert(W.size()<=50);

    int N=(int)W.size();
    int M=N/2;
    int K=N-M;
    vector<int> E_AtoB(M,0),E_AtoA(M,0),E_BtoB(K,0);
    for(int i=0;i<N;i++){
        for(auto &e:G[i]){
            if(e==i) continue;
            if(i<M and e<M)   E_AtoA[i]|=(1<<e);
            if(i<M and e>=M)  E_AtoB[i]|=(1<<(e-M));
            if(i>=M and e>=M) E_BtoB[i-M]|=(1<<(e-M));
        }
    }

    vector<T> dp_B(1<<K,0);
    for(int bit=0;bit<(1<<K);bit++){
        T S=0;
        int to=0;
        for(int i=0;i<K;i++)if((bit>>i)&1){
            to|=E_BtoB[i];
            S+=W[M+i];
        }

        if((to&bit)==0) dp_B[bit]=max(dp_B[bit],S);

        for(int i=0;i<K;i++)if(!((bit>>i)&1)) dp_B[bit|(1<<i)]=max(dp_B[bit|(1<<i)],dp_B[bit]);
    }

    T ret=0;
    int mask=(1<<K)-1;
    for(int bit=0;bit<(1<<M);bit++){
        T S=0;
        int to=0,toB=0;
        for(int i=0;i<M;i++)if((bit>>i)&1){
            to|=E_AtoA[i];
            toB|=E_AtoB[i];
            S+=W[i];
        }
        if((to&bit)==0) ret=max(ret,S+dp_B[mask^toB]);
    }
    return ret;
}
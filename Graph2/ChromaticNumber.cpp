template<typename T>
int chromatic_number(Graph<T> G){
    int N=G.size();
    assert(N<28);

    vector<int> E(N,0);
    for(int i=0;i<N;i++){
        E[i]|=(1<<i);
        for(auto &e:G[i]) E[i]|=(1<<e.to);
    }

    // I[S] := Sの部分集合にある独立集合の個数
    vector<int> I(1<<N,0);
    I[0]=1;
    for(int S=1;S<(1<<N);S++){
        int v=__builtin_ctz(S);// 代表点
        I[S]=I[S&~(1<<v)]+I[S&~E[v]];
    }

    auto Pow=[](ll a,int k,ll p){
        ll ret=1;
        for(;k;k>>=1){
            if(k&1) ret=ret*a%p;
            a=a*a%p;
        }
        return ret;
    };

    for(int k=1;k<=N;k++){
        // g[S] := Sをちょうどカバーするk個の独立集合の組の個数
        // f[S] := Sの部分集合からk個重複を許して選ぶ個数
        //  -> F[S] = I[S]^k {(a or b .. ) * (a or b ...)...}
        //  -> f[S] = sum_{T in S} g[T]
        //  -> g[S] = sum_{T in S} (-1)^(|S|-|T|) f[T]
        for(ll p:{1000000007,1000000021}){
            ll g=0;
            for(int S=0;S<(1<<N);S++){
                if((N-__builtin_popcount(S))&1) g-=Pow(I[S],k,p);
                else                            g+=Pow(I[S],k,p);
                g=(g+p)%p;
            }
            if(g>0) return k;
        }
    }
    return 0;
}
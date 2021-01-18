#define PROBLEM "https://yukicoder.me/problems/5436"

#include "../template.cpp"

#include "../Graph2/Rerooting.cpp"

#include "../type/modint.cpp"

using mint=ModInt<1000000007>;

signed main(){
    int n;cin>>n;
    Graph<mint> g(n);
    g.read(n-1,-1,true,false);

    using T=tuple<mint,mint,mint>;
    function<T(T,Edge<mint>)> f=[&](T dpch,Edge<mint> e){
        auto [a2,a1,cnt]=dpch;
        return T(a1*2*e.w+a2+e.w*e.w*(cnt+1),a1+e.w*(cnt+1),cnt+1);
    };
    function<T(T,T)> merge=[&](T l,T r){
        return T(get<0>(l)+get<0>(r),get<1>(l)+get<1>(r),get<2>(l)+get<2>(r));
    };

    Rerooting<T,mint> R(g,f,merge,T(0,0,0));
    R.build();
    mint res=0;
    rep(i,n) res+=get<0>(R.ans[i]);
    cout<<res/2<<endl;
    return 0;
}

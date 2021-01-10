#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../template.cpp"

#include "../type/int128.cpp"

#include "../Math/PollardRho.cpp"

signed main(){
    FastPrime<int128> F;

    int q;cin>>q;
    while(q--){
        int128 x;cin>>x;
        auto res=F.factorize(x);
        sort(ALL(res));
        cout<<res.size()<<" "<<res<<"\n";
    }
    return 0;
}

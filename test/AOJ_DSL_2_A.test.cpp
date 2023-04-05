#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include "../template.hpp"

#include "../DataStructure/BinaryTrieMonoid.hpp"

signed main(){
    int n,q;cin>>n>>q;
    BinaryTrieMonoid<int,18,ll> trie([&](ll a,ll b){return (a<b?a:b);},(1ll<<31)-1);
    while(q--){
        int c;ll x,y;cin>>c>>x>>y;
        if(c==0) trie.update(x,y);
        if(c==1) cout<<trie.query(x,y+1)<<endl;
    }

    return 0;
}

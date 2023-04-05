#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../template.hpp"

#include "../DataStructure/BinaryTrie.hpp"

signed main(){
    BinaryTrie<int,18> trie;
    int n,q;cin>>n>>q;
    while(q--){
        int c,x,y;cin>>c>>x>>y;
        if(c==0) trie.add(x,y);
        else cout<<trie.count_less(y+1)-trie.count_less(x)<<endl;
    }
    return 0;
}

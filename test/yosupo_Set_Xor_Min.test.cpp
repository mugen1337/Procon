#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../template.cpp"

#include "../DataStructure/BinaryTrie.cpp"

signed main(){
    BinaryTrie<int,31> trie;
    int q;cin>>q;
    while(q--){
        int t,x;cin>>t>>x;
        if(t==0){
            if(trie.count(x)==0) trie.add(x);
        }else if(t==1){
            if(trie.count(x)) trie.erase(x,1);
        }else{
            cout<<trie.min_element(x)<<"\n";
        }
    }
    return 0;
}

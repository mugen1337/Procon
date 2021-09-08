#include "../template.cpp"

#include "../type/modint.cpp"

#include "../String/Trie.cpp"

#include "../String/RollingHash.cpp"

using mint=ModInt<1000000007>;

const int sz=26;
int converter(char x){return x-'a';}

const int sq=(1<<9);


signed main(){
    int N;cin>>N;
    vector<string> S(N);
    cin>>S;
    string T;cin>>T;

    Trie<sz> trie(converter);
    vector<int> add_sz;

    ull base=RollingHash::generate_base();
    vector<ull> Sh;
    vector<int> Sh_sz;
    RollingHash Th(T, base);

    rep(i,N){
        if(S[i].size()>sq){
            RollingHash tmp(S[i], base);
            Sh.push_back(tmp.get(0,S[i].size()));
            Sh_sz.push_back(S[i].size());
        }else{
            trie.add(S[i]);
            add_sz.push_back(S[i].size());
        }
    }

    vector<mint> dp(T.size()+1, 0);
    dp[0]=1;

    rep(i,(int)T.size()){
        rep(j,(int)Sh.size()){
            if(i+Sh_sz[j]<=(int)T.size() and Th.get(i,i+Sh_sz[j])==Sh[j]){
                dp[i+Sh_sz[j]]+=dp[i];
            }
        }
        function<void(int)> f=[&](int k){
            dp[i+add_sz[k]]+=dp[i];
            return ;
        };
        trie.query(T,f,i);
    }
    cout<<dp.back()<<endl;
    return 0;
}
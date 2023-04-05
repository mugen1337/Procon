// https://codeforces.com/problemset/problem/1175/F

#include "../template.hpp"

#include "../Other/RandomNumberGenerator.hpp"

// 1-indexed permutation
ll Subpermutations(vector<int> v){
    int n=(int)v.size();

    RandomNumberGenerator rng;
    vector<ll> hash(n+1),hash_s(n+2,0);
    for(int i=1;i<=n;i++){
        hash[i]=rng(0,1<<31);
        hash_s[i]=hash_s[i-1]^hash[i];
    }
    ll res=0;
    // 1の右に最大値がある場合, 1の左に最大値がある場合で解く
    rep(_,2){
        vector<ll> hash_vs(n+1,0);
        rep(i,n){
            hash_vs[i+1]=hash_vs[i]^hash[v[i]];
        }

        rep(i,n)if(v[i]==1){
            if(_) res++;
            int mx=0;
            for(int j=i+1;j<n;j++){
                if(v[j]==1) break;
                chmax(mx,v[j]);
                if(j+1-mx>=0 and ((hash_vs[j+1]^hash_vs[j+1-mx])==hash_s[mx])) res++;
            }
        }
        reverse(ALL(v));
    }

    return res;
}

signed main(){
    int n;cin>>n;
    vector<int> a(n);
    cin>>a;
    cout<<Subpermutations(a)<<endl;
    return 0;
}

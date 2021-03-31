#define PROBLEM "https://yukicoder.me/problems/3784"

#include "../template.cpp"

#include "../DP/LongestIncreasingSubsequence.cpp"

#include "../type/modint.cpp"

using mint=ModInt<1000000007>;

#include "../DataStructure/BinaryTrieMonoid.cpp"

#include "../SegmentTree/SegmentTree.cpp"

int f(int a,int b){
    return max(a,b);
}

mint g(mint a,mint b){
    return a+b;
}

signed main(){
    int n;cin>>n;
    vector<int> a(n);
    cin>>a;

    int M=LongestIncreasingSubsequence(a);

    {
        vector<int> v=a;
        sort(ALL(v));
        v.erase(unique(ALL(v)),end(v));
        for(auto &x:a) x=lower_bound(ALL(v),x)-begin(v);
    }

    
    vector<int> l(n),r(n);
    {
        SegmentTree<int> seg(n,f,0);
        rep(i,n){
            l[i]=seg.query(0,a[i])+1;
            if(seg.query(a[i],a[i]+1)<l[i]) seg.update(a[i],l[i]);
        }
    }
    {
        SegmentTree<int> seg(n,f,0);
        for(int i=n-1;i>=0;i--){
            r[i]=seg.query(a[i]+1,n)+1;
            if(seg.query(a[i],a[i]+1)<r[i]) seg.update(a[i],r[i]);
        }
    }

    vector<int> idx(n,-1);
    rep(i,n)if(l[i]+r[i]-1==M) idx[i]=l[i]-1;

    vector<BinaryTrieMonoid<int,18,mint> > segs;
    rep(i,M){
        BinaryTrieMonoid<int,18,mint> tmp(g,0);
        segs.push_back(tmp);
    }

    vector<mint> dp(n,0);
    rep(i,n){
        if(idx[i]<0) continue;
        if(idx[i]==0) dp[i]=1;
        else dp[i]=segs[idx[i]-1].query(0,a[i]);

        mint t=segs[idx[i]].query(a[i],a[i]+1);
        segs[idx[i]].update(a[i],t+dp[i]);
    }
    cout<<segs[M-1].query(0,1<<18)<<endl;
    return 0;
}

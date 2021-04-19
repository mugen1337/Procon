#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "../template.cpp"

#include "../Algorithm/Mo.cpp"

#include "../DataStructure/BinaryIndexedTree.cpp"


signed main(){
    int n,q;cin>>n>>q;
    vector<int> a(n);
    cin>>a;

    auto comp=a;
    sort(ALL(comp));
    comp.erase(unique(ALL(comp)),end(comp));
    rep(i,n) a[i]=lower_bound(ALL(comp),a[i])-begin(comp);

    BinaryIndexedTree<ll> seg(n+10);
    
    ll res=0;
    auto add_left=[&](int x){
        res+=seg.query(0,a[x]);
        seg.add(a[x],1);
    };
    auto add_right=[&](int x){
        res+=seg.query(a[x]+1,n+5);
        seg.add(a[x],1);
    };
    auto erase_left=[&](int x){
        res-=seg.query(0,a[x]);
        seg.add(a[x],-1);
    };
    auto erase_right=[&](int x){
        res-=seg.query(a[x]+1,n+5);
        seg.add(a[x],-1);
    };

    Mo mo(n,add_left,add_right,erase_left,erase_right);

    rep(i,q){
        int l,r;cin>>l>>r;
        mo.add(l,r);
    }
    mo.build();

    vector<ll> ans(q);
    rep(i,q){
        int j=mo.process();
        ans[j]=res;
    }

    for(auto &x:ans) cout<<x<<"\n";
    return 0;
}

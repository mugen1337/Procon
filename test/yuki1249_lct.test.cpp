#define PROBLEM "https://yukicoder.me/problems/1249"

#include "../template.cpp"

#include "../Tree/LazyLinkCutTree.cpp"

signed main(){
    int n;cin>>n;

    auto f=[&](pair<ll,ll> a,pair<ll,ll> b){
        return make_pair(a.first+b.first,a.second+b.second);
    };
    auto g=[&](pair<ll,ll> a,ll b){
        return make_pair(a.first+a.second*b,a.second);
    };
    auto h=[&](ll a,ll b){
        return a+b;
    };

    vector<pair<ll,ll>> ones(n,{1,1});
    LazyLinkCutTree<pair<ll,ll>,ll> lct(ones,f,g,h,{0,0},0);

    rep(i,n-1){
        int u,v;cin>>u>>v;u--,v--;
        lct.link(u,v);
    }

    int q;cin>>q;
    ll ans=0;
    while(q--){
        int a,b;cin>>a>>b;a--,b--;
        ans+=lct.query(a,b).first;
        lct.update(a,b,1);
    }
    cout<<ans<<endl;
    return 0;
}
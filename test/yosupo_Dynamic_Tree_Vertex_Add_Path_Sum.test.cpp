#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include "../template.cpp"

#include "../Graph2/LinkCutTree.cpp"

signed main(){
    int n,q;cin>>n>>q;
    vector<ll> v(n);
    cin>>v;

    LinkCutTree<ll> lct(v,[](ll a,ll b){return a+b;},0);

    rep(i,n-1){
        int u,v;cin>>u>>v;
        lct.link(u,v);
    }

    while(q--){
        int type;cin>>type;
        if(type==0){
            int a,b,c,d;cin>>a>>b>>c>>d;
            lct.cut(a,b);
            lct.link(c,d);
        }else if(type==1){
            int p;ll x;cin>>p>>x;
            lct.update(p,lct.get(p)+x);
        }else{
            int u,v;cin>>u>>v;
            cout<<lct.query(u,v)<<endl;
        }
    }
    return 0;
}
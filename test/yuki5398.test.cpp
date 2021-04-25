#define PROBLEM "https://yukicoder.me/problems/5398"

#include "../template.cpp"

#include "../BinarySearchTree/ImplicitTreapWithLazy.cpp"

ll f(ll a,ll b){
    return a+b;
}

signed main(){
    int n,q;cin>>n>>q;
    vector<ll> a(n);
    cin>>a;

    ImplicitTreap<ll,ll> v(f,f,f,0,0);
    v.build(a);
    
    while(q--){
        int t,l,r;cin>>t>>l>>r;l--;
        if(t==1){
            ll s=v.query(l,r);
            v.erase(l,r);
            v.insert(l,s);
        }else{
            cout<<v.query(l,r)<<"\n";
        }
    }
    return 0;
}

#define PROBLEM "https://yukicoder.me/problems/4374"

#include "../template.cpp"

#include "../SegmentTree/LazySegmentTree.cpp"

using tp=tuple<ll,ll,ll>;

tp f(tp a,tp b){
    return tp(get<0>(a)+get<0>(b),get<1>(a)+get<1>(b),get<2>(a)+get<2>(b));
}

tp g(tp a,ll b){
    ll x2,x,cnt;
    tie(x2,x,cnt)=a;
    return tp(x2+b*b*cnt+2*x*b,x+cnt*b,cnt);
}

ll h(ll a,ll b){
    return a+b;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;cin>>n;
    LazySegmentTree<tp,ll> seg(n,f,g,h,tp(0,0,0),0);
    rep(i,n){
        ll a;cin>>a;
        seg.set(i,tp(a*a,a,1));
    }
    seg.build();
    int q;cin>>q;
    while(q--){
        int t;cin>>t;
        if(t==1){
            int l,r;ll x;cin>>l>>r>>x;l--;
            seg.update(l,r,x);
        }else{
            int l,r;cin>>l>>r;l--;
            cout<<(get<0>(seg.query(l,r)))<<endl;
        }
    }

    return 0;
}

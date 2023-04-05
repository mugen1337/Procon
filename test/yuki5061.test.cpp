#define PROBLEM "https://yukicoder.me/problems/5061"

#include "../template.hpp"

#include "../DataStructure/Slope.hpp"
             
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

signed main(){
    int m,n;cin>>m>>n;
    vector<ll> a(m),b(n);
    cin>>a>>b;

    struct E{
        ll val;
        bool a;
        E(ll val,bool a):val(val),a(a){}
    };

    vector<E> v;
    rep(i,m) v.emplace_back(a[i],true);
    rep(i,n) v.emplace_back(b[i],false);

    sort(ALL(v),[](E l,E r){return l.val<r.val;});

    for(int k=1;k<=m;k++){
        Slope<ll> f;
        f.add_x_minus_a(0,1000000000);
        f.add_a_minus_x(0,1000000000);

        ll pre=-100000;
        for(int i=0;i<(int)v.size();i++){
            if(v[i].a) f.shift(1);
            else       f.shift(-k);
            
            f.clear_right();
            if(i+1<(int)v.size()){
                ll d=v[i+1].val-v[i].val;
                f.add_abs(0,d);
            }
        }
        cout<<f(0)<<endl;
    }
    return 0;
}

#define PROBLEM "https://yukicoder.me/problems/1601"

#include "../template.hpp"

#include "../DataStructure/RangeSet.hpp"

signed main(){
    ll d,q;cin>>d>>q;
    RangeSet<ll> st;
    ll res=0;
    while(q--){
        ll l,r;cin>>l>>r;
        st.insert(l,r);
        auto p=st.covered_by(l);
        chmax(res,p.second-p.first+1);
        cout<<res<<"\n";
    }
    return 0;
}
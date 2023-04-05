#include "./inv_mod.hpp"
#include "./pow_mod.hpp"

// https://qiita.com/suisen_cp/items/d597c8ec576ae32ee2d7
// 最小の非負整数xを返す
// a ^ x = b mod m
ll log_mod(ll a,ll b,ll m){
    auto BSGS=[](ll a,ll b,ll m){
        ll sq_m=sqrt(m)+1;

        // baby-step
        unordered_map<ll,ll> bs;
        ll bab=1;
        for(int i=0;i<sq_m;i++,bab=bab*a%m)if(!bs.count(bab)) bs[bab]=i;

        // giant-step
        ll a_m=pow_mod(inv_mod(a,m),sq_m,m);
        ll gia=b;
        for(int i=0;i<=sq_m;i++,gia=gia*a_m%m)if(bs.count(gia)) return sq_m*i+bs[gia];
        return -1ll;
    };

    function<ll(ll,ll,ll)> decomp_BSGS=[&decomp_BSGS, &BSGS](ll a,ll b,ll m){
        a%=m,b%=m;
        
        if(m==1) return 0ll;
        if(b==1) return 0ll;

        ll g=gcd(a,m);
        if(g==1) return BSGS(a,b,m);

        if(b%g) return -1ll;
        m/=g;
        b=(b/g)*inv_mod(a/g,m);
        ll res=decomp_BSGS(a,b,m);
        if(res<0) return -1ll;
        return res+1;
    };
    return decomp_BSGS(a,b,m);
}
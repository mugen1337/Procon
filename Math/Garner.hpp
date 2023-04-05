// (val, mod)
pair<ll,ll> Garner(const vector<ll> &rems,const vector<ll> &mods){
    // {g, x}, g=gcd(a,b), xa = g (mod b)
    function<pair<ll,ll>(ll,ll)> gcd_inv=[](ll a,ll b){
        a%=b;
        if(a<0) a+=b;
        if(a==0) return make_pair(b,0ll);
        ll s=b,t=a,m0=0,m1=1;
        while(t){
            ll u=s/t;
            s-=t*u,m0-=m1*u;
            swap(s,t);
            swap(m0,m1);
        }
        if(m0<0) m0+=b/s;
        return make_pair(s,m0);
    };

    ll R=0,M=1;
    for(int i=0;i<(int)rems.size();i++){
        ll r=rems[i],m=mods[i];
        r%=m;if(r<0) r+=m;
        if(m>M) swap(m,M),swap(r,R);
        if(M%m==0){
            if(R%m!=r) return {0,0};
            continue;
        }
        auto [g,iM]=gcd_inv(M,m);
        ll u=m/g;
        if((r-R)%g) return {0,0};
        ll x=(r-R)/g%u*iM%u;
        R+=x*M;
        M*=u;
        if(R<0) R+=M;
    }
    return {R,M};
}
// a^n (mod m)
ll pow_mod(ll a,ll n,ll m){
    ll ret=1;
    while(n){
        if(n&1) ret=ret*a%m;
        a=(a*a)%m;
        n/=2;
    }
    return ret;
}
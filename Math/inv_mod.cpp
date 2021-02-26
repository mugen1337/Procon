ll inv_mod(ll a,ll m){
    ll b=m,u=1,v=0,t;
    while(b){
        t=a/b;
        swap(a-=t*b,b);swap(u-=t*v,v);
    }
    u%=m;
    if(u<0) u+=m;
    return u;
}
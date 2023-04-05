#define PROBLEM "https://yukicoder.me/problems/4459"

#include "../template.hpp"

#include "../Math/ceil_floor.hpp"


template< typename T >
inline T extgcd(T a, T b, T &x, T &y) {
  T d = a;
  if(b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

vector<ll> ve(3);

void solve(){
    cin>>ve;
    ll y;cin>>y;
    sort(ALL(ve));
    ll a,b,c;
    a=ve[2],b=ve[1],c=ve[0];

    ll res=0;

    ll g=gcd(b,c);
    ll j,k;
    ll u=b/g,v=c/g;

    ll gg=extgcd(u,v,j,k);


    for(ll i=0;i<=y;i+=a){
        ll t=y-i;
        if(t%g) continue;
        t/=g;

        ll w=t/gg; // t=g*w
        
        // g=j*u+k*v;
        ll jj=j*w,kk=k*w;

        // j=j' + x * v
        // k=k' - x * u

        jj*=-1;
        ll dw=div_ceil(jj,v);
        ll up=div_floor(kk,u);
        // cout<<up<<" ~ "<<dw<<endl;
        res+=max(0ll,(up-dw+1));
        if(res>=mod) res%=1000000007ll;
    }
    cout<<res<<"\n";
}


signed main(){
    int q;cin>>q;
    while(q--) solve();
    return 0;
}

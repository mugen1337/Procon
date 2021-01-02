#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 998244353
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

// Monoid Sliding-Window-AGregation
template<typename Monoid>
struct SWAG{
    using F=function<Monoid(Monoid,Monoid)>;
    const F f;
    const Monoid e;
    stack<pair<Monoid,Monoid>> fr,ba;
    SWAG(const F f,const Monoid &e):f(f),e(e){}
    Monoid get(){
        Monoid a=fr.empty()?e:fr.top().second;
        Monoid b=ba.empty()?e:ba.top().second;
        return f(a,b);
    }
    void push(Monoid x){
        if(ba.empty()) ba.push(make_pair(x,x));
        else ba.push(make_pair(x,f(ba.top().second,x)));
    }
    void pop(){
        if(empty()) return ;
        if(!fr.empty()) fr.pop();
        else{
            while(!ba.empty()){
                pair<Monoid,Monoid> p=ba.top();ba.pop();
                if(fr.empty()) fr.push(make_pair(p.first,p.first));
                else fr.push(make_pair(p.first,f(p.first,fr.top().second)));
            }
            fr.pop();
        }
    }
    size_t size(){
        return fr.size()+ba.size();
    }
    bool empty(){
        return size()==0;
    }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    auto swagfunc=[](pair<ll,ll> p1,pair<ll,ll> p2){
        return make_pair(p1.first*p2.first%mod,(p2.first*p1.second%mod+p2.second)%mod);
    };

    SWAG<pair<ll,ll>> que(swagfunc,make_pair(1ll,0ll));

    int q;cin>>q;
    while(q--){
        int t;cin>>t;
        if(t==0){
            ll a,b;cin>>a>>b;
            que.push(make_pair(a,b));
        }else if(t==1){
            que.pop();
        }else{
            ll x;cin>>x;
            auto p=que.get();
            cout<<(p.first*x%mod+p.second)%mod<<endl;
        }
    }


    return 0;
}

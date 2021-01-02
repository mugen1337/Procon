#include<bits/stdc++.h>
using namespace std;
#define ALL(x) begin(x),end(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define mod 1000000007
using ll=long long;
const int INF=1000000000;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}


#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2292"


// 文字種aに対し，build O(na)
struct PalindromicTree{
    struct node{
        map<char,int> link;// link aba -> xabax
        int len,cnt,idx;// idx:この回文の1つの左端, RHなどのため
        int suffix_link;
        node(){}
        node(int len,int cnt,int idx,int suffix_link):len(len),cnt(cnt),idx(idx),suffix_link(suffix_link){}
    };

    vector<node> v;// 0:(-1), 1: (0)
    int n,ptr;

    PalindromicTree(){}
    PalindromicTree(const string &s):v(2),n(2),ptr(1){
        v[0]=node(-1,0,-1,0);v[1]=node(0,0,-1,0);
        for(int i=0;i<(int)s.size();i++) process(s,i);
        build_freq();
    }

    bool process(const string &s,int pos){
        int cur=ptr;// link parent
        while(true){
            int rev=pos-v[cur].len-1;
            if(rev>=0 and s[rev]==s[pos]) break;
            cur=v[cur].suffix_link;
        }
        if(v[cur].link.count(s[pos])){
            ptr=v[cur].link[s[pos]];
            v[ptr].cnt++;
            return false;
        }
        ptr=n++;

        v.emplace_back(v[cur].len+2,1,pos-v[cur].len-1,-1);
        v[cur].link[s[pos]]=ptr;// link
        if(v[ptr].len==1){
            v[ptr].suffix_link=1;
            return true;
        }

        while(true){
            cur=v[cur].suffix_link;
            int rev=pos-v[cur].len-1;
            if(rev>=0 and s[rev]==s[pos]){
                v[ptr].suffix_link=v[cur].link[s[pos]];
                break;
            }
        }
        return true;
    }
    // DAGをトポソ
    vector<int> calc_ord(){
        vector<int> ret;
        ret.emplace_back(0);
        ret.emplace_back(1);
        for(int i=0;i<(int)ret.size();i++)for(auto &p:v[ret[i]].link) ret.emplace_back(p.second);
        return ret;
    }
    void build_freq(){
        auto ord=calc_ord();
        // 一番長い回文にしかcnt+=1をしていないので，linkで集約する
        for(int i=(int)ord.size()-1;i>=0;i--) v[v[ord[i]].suffix_link].cnt+=v[ord[i]].cnt;
    }
    int count_unique(){return n-2;}
    int size(){return n;}
    node operator[](const int &k){return v[k];}
};


// hash type
using ull=unsigned long long;
struct RollingHash{
    using ull=unsigned long long;
    using uint128=__uint128_t;
    static const ull MOD=(1ull<<61ull)-1;
    vector<ull>hashed,power;
    const ull base;
 
    static inline ull add(ull a,ull b){if((a+=b)>=MOD)a-=MOD;return a;}
    static inline ull mul(ull a,ull b){uint128 c=(uint128)a*b;return add(c>>61,c&MOD);}
    static inline ull generate_base(){
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<ull>rand(1,RollingHash::MOD-1);
        return rand(mt);
    }
    RollingHash()=default;
    RollingHash(const string &s,ull base):base(base){
        int sz=(int)s.size();
        hashed.assign(sz+1,0);
        power.assign(sz+1,0);
        power[0]=1;
        for(int i=0;i<sz;i++){
            power[i+1]=mul(power[i],base);
            hashed[i+1]=add(mul(hashed[i],base),s[i]);
        }
    }
    template<typename T>
    RollingHash(const vector<T>&s,ull base):base(base){
        int sz=(int)s.size();
        hashed.assign(sz+1,0);
        power.assign(sz+1,0);
        power[0]=1;
        for(int i=0;i<sz;i++){
            power[i+1]=mul(power[i],base);
            hashed[i+1]=add(mul(hashed[i],base),s[i]);
        }
    }
    // hash[l,r)
    ull get(int l,int r)const{
        return add(hashed[r],MOD-mul(hashed[l],power[r-l]));
    }
    ull concat(ull hash1,ull hash2,int hash2len)const{
        return add(mul(hash1,power[hash2len]),hash2);
    }
    int lcp(const RollingHash &b,int l1,int r1,int l2,int r2)const{
        assert(b.base==base);
        int len=min(r1-l1,r2-l2);
        int lw=0,hi=len+1;
        while(hi-lw>1){
            int mid=(lw+hi)/2;
            if(get(l1,l1+mid)==b.get(l2,l2+mid))lw=mid;
            else hi=mid;
        }
        return lw;
    }
};


signed main(){
    string s,t;cin>>s>>t;

    PalindromicTree pts(s),ptt(t);
    ull base=RollingHash::generate_base();
    RollingHash rhs(s,base),rht(t,base);
    map<ull,ll> cnt;
    for(int i=2;i<pts.size();i++){
        cnt[rhs.get(pts[i].idx,pts[i].idx+pts[i].len)]+=pts[i].cnt;
    }
    ll res=0;
    for(int i=2;i<ptt.size();i++){
        ull hash=rht.get(ptt[i].idx,ptt[i].idx+ptt[i].len);
        if(cnt.count(hash)) res+=ptt[i].cnt*cnt[hash];
    }
    cout<<res<<endl;
    return 0;
}
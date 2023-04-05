#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2292"

#include "../template.hpp"

#include "../String/RollingHash.hpp"
#include "../String/PalindromicTree.hpp"

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
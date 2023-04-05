#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "../template.hpp"

#include "../SegmentTree/KineticSegmentTree.hpp"

signed main(){
    int N, Q; cin >> N >> Q;

    KineticSegmentTree<ll> KST(N + Q, -2e9);
    rep(i, N){
        ll a, b; cin >> a >> b;
        KST.update(i, a, b);
    }

    int R = N, qs = 0;
    vector<tuple<int, ll, int>> query; // query idx, x, R
    rep(i, Q){
        int type; cin >> type;
        if(type == 0){
            ll a, b; cin >> a >> b;
            KST.update(R++, a, b);
        }else{
            ll p; cin >> p;
            query.emplace_back(qs++, p, R);
        }
    }

    vector<ll> ans(qs);

    sort(begin(query), end(query), 
    [](tuple<int, ll, int> &lhs, tuple<int, ll, int> &rhs){
        return get<1>(lhs) < get<1>(rhs);
    });

    for(auto &[qidx, x, r] : query){
        KST.heaten(x);
        ans[qidx] = KST.query(0, r);
    }

    for(ll &x : ans) cout << x << "\n";
    return 0;
}
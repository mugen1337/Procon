#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2173"
#define ERROR 0.0000001

#include "../template.cpp"

#include "../Geometry/include.cpp"

int n;
Real w;

void solve(){
    vector<Polygon> poly;
    poly.emplace_back(Polygon{Point(0,-INF),Point(0,INF),Point(-1,INF),Point(-1,-INF)});   // Wall left
    poly.emplace_back(Polygon{Point(w,-INF),Point(w,INF),Point(w+1,INF),Point(w+1,-INF)}); // Wall right

    rep(i,n){
        int m;cin>>m;
        Polygon cur(m);
        cin>>cur;
        poly.push_back(cur);
    }

    n+=2;
    vector<vector<Real>> d(n,vector<Real>(n));
    rep(i,n)rep(j,n) d[i][j]=dis(poly[i],poly[j]);
    rep(k,n)rep(i,n)rep(j,n) chmin(d[i][j],d[i][k]+d[k][j]);
    cout<<d[0][1]<<endl;
}

signed main(){
    while(cin>>w>>n,w) solve();
    return 0;
}

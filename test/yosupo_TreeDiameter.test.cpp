#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../template.cpp"

#include "../Graph2/TreeDiameter.cpp"

signed main(){
    int n;cin>>n;
    Graph<ll> g(n);
    g.read(n-1,0,true,false);
    auto [D,P]=TreeDiameter(g);
    cout<<D<<" "<<P.size()<<endl;
    cout<<P<<endl;
    return 0;
}

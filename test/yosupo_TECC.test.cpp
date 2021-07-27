#include "../template.cpp"
#include "../Graph2/TwoEdgeConnectedComponents.cpp"

signed main(){
    int N,M;cin>>N>>M;
    Graph<int> G(N);
    G.read(M,0);

    TwoEdgeConnectedComponents<int> TECC(G);
    cout<<TECC.group.size()<<"\n";
    for(auto &w:TECC.group){
        cout<<w.size();
        for(auto &x:w) cout<<" "<<x;
        cout<<"\n";
    }
    return 0;
}
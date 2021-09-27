#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/beta/room.html#ACPC2021Day2/problems/I"

#include "../template.cpp"

#include "../Graph2/WeightedMaximumIndependentSet.cpp"

signed main(){
    int M,N;cin>>M>>N;
    vector<vector<int>> P(N);
    vector<int> W(M);
    rep(i,M){
        cin>>W[i];
        rep(j,W[i]){
            int p;cin>>p;p--;
            P[p].push_back(i);
        }
    }

    Graph<int> G(M);
    for(auto &v:P){
        int n=(int)v.size();
        rep(i,n)rep(j,i) G.add_edge(v[i],v[j]);
    }

    int S=0;
    for(auto &w:W) S+=w;
    cout<<S-WeightedMaximumIndependentSet(G,W)<<endl;
    return 0;
}
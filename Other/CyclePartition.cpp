// 0-indexed parmutation only
vector<vector<int>> cycle_partition(const vector<int> &p){
    int n=p.size();
    vector<vector<int>> ret;
    vector<bool> check(n,false);
    rep(i,n)if(!check[p[i]]){
        vector<int> v;
        int pos=p[i];
        v.push_back(i);
        check[i]=true;
        while(pos!=i){
            v.push_back(pos);
            check[pos]=true;
            pos=p[pos];
        }
        ret.push_back(v);
    }
    return ret;
}
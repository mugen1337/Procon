/*
Nの分割方法の列挙
N=5 -> 200000 程度
verified : https://atcoder.jp/contests/abc226/submissions/27125989
*/
vector<vector<int>> enumerate_division(int N){
    vector<vector<int>> ret;
 
    function<void(vector<int>,int,int)> rec=[&](vector<int> v,int S,int K){
        if(S==0){
            ret.push_back(v);
            return ;
        }
 
        for(int t=min(S,K);t>0;t--){
            v.push_back(t);
            rec(v,S-t,t);
            v.pop_back();
        }
    };
    rec({},N,N);
    return ret;
}
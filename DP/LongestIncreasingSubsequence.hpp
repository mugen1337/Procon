template<typename T>
int LongestIncreasingSubsequence(vector<T> v,bool strict=true){
    vector<T> lis;
    for(auto &x:v){
        typename vector<T>::iterator ite;
        if(strict) ite=lower_bound(begin(lis),end(lis),x);
        else       ite=upper_bound(begin(lis),end(lis),x);
        if(ite==end(lis)) lis.push_back(x);
        else              *ite=x;
    }
    return int(lis.size());
}
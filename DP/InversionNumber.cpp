template<typename T>
long long InversionNumber(vector<T> v){
    vector<T> ord=v;
    sort(begin(ord),end(ord));
    ord.erase(unique(begin(ord),end(ord)),end(ord));
    vector<T> bit(ord.size()+1,0);
    long long ret=0;
    for(int i=0;i<(int)v.size();i++){
        int p=lower_bound(begin(ord),end(ord),v[i])-begin(ord)+1;
        for(int j=p;j;j-=(j&-j)) ret-=bit[j];
        for(int j=p;j<=(int)ord.size();j+=(j&-j)) bit[j]+=1;
        ret+=i;
    } 
    return ret;
}
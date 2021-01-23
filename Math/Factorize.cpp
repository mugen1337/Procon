template<typename INT>
vector<INT> Factorize(INT x){
    vector<INT> ret;
    for(INT i=2;i*i<=x;i++){
        while(x%i==0){
            ret.push_back(i);
            x/=i;
        }
    }
    if(x!=1) ret.push_back(x);
    sort(begin(ret),end(ret));
    return ret;
}
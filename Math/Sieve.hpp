vector<bool> sieve(int n){
    vector<bool> ret(n+1,true);
    ret[0]=false;
    if(n>0) ret[1]=false;
    for(int i=2;i*i<=n;i++){
        if(!ret[i]) continue;
        for(int j=i*2;j<=n;j+=i) ret[j]=false;
    }
    return ret;
}
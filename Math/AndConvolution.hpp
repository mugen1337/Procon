// ret_k = sum a_i * b_j, i&j=k 
template<typename T>
vector<T> AndConvolution(vector<T> a,vector<T> b){
    assert(a.size()==b.size());
    int n=(int)a.size();
    vector<T> ret(n);
    // FWT
    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){
        if((i&j)==0) a[j]+=a[j|i],b[j]+=b[j|i];
    }
    for(int i=0;i<n;i++) ret[i]=a[i]*b[i];
    // IFWT
    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){
        if((i&j)==0) ret[j]-=ret[j|i];
    }
    return ret;
}
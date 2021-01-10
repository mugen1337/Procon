// ret_k = sum a_i * b_j, i^j=k
template<typename T>
vector<T> XorConvolution(vector<T> a,vector<T> b){
    assert(a.size()==b.size());
    int n=(int)a.size();
    vector<T> ret(n);
    // FWT
    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){
        if((i&j)==0){
            {
                T x=a[j],y=a[j|i];
                a[j]=x+y,a[j|i]=x-y;
            }
            {
                T x=b[j],y=b[j|i];
                b[j]=x+y,b[j|i]=x-y;
            }
        }
    }
    for(int i=0;i<n;i++) ret[i]=a[i]*b[i];
    // IFWT
    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j++){
        if((i&j)==0){
            T x=ret[j],y=ret[j|i];
            ret[j]=(x+y)/2,ret[j|i]=(x-y)/2;
        }
    }
    return ret;
}
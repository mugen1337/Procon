// c[k] = sum a[i] * a[j], gcd(i, j) == k
// ref : https://noshi91.hatenablog.com/entry/2019/09/23/002445
template<typename T>
vector<T> gcd_convolution(vector<T> a,vector<T> b){
   auto f=[&](vector<T> &v){ // in-place
       int n=(int)v.size();
       for(int k=1;k<n;k++)for(int i=k+k;i<n;i+=k) v[k]+=v[i];
       return ;
   };
   auto f_inv=[&](vector<T> &v){ // in-place
       int n=(int)v.size();
       for(int k=n-1;k>0;k--)for(int i=k+k;i<n;i+=k) v[k]-=v[i];
   };
 
   int n=(int)max(a.size(),b.size());
   a.resize(n,0);b.resize(n,0);
   f(a);f(b);
   vector<T> ret(n,0);
   rep(i,n) ret[i]=a[i]*b[i];
   f_inv(ret);
   return ret;
}

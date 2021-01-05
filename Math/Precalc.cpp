template<typename T>
struct Precalc{
    vector<T> fact,finv,inv;
    Precalc(int MX):fact(MX),finv(MX),inv(MX){
        fact[0]=T(1),fact[1]=T(1),finv[0]=T(1),finv[1]=T(1),inv[1]=T(1);
        for(int i=2;i<MX;i++){
            fact[i]=fact[i-1]*T(i);
            inv[i]=T(0)-inv[mod%i]*(T(mod/i));
            finv[i]=finv[i-1]*inv[i];
        }
    }
    T com(int n,int k){
        if(n<k) return T(0);
        if(n<0 or k<0) return T(0);
        return fact[n]*(finv[k]*finv[n-k]);
    }
    T fac(int n){
        return fact[n];
    }
    // 重複組み合わせ:n種類の物から重複を許し，k個選ぶ
    T nHk(int n,int k){
        return com(n+k-1,k);
    }
    // 玉n区別，箱k区別，各箱1個以上O(k)
    T F12_dis_dis_one(int n,int k){
        if(n<k)return T(0);
        T ret=0;
        for(int i=0;i<=k;i++){
            T add=com(k,i)*(T(i).pow(n));
            if((k-i)%2) ret-=add;
            else        ret+=add;
        }
        return ret;
    }
    /* sum combination(n+x, x), x=l to r
       https://www.wolframalpha.com/input/?i=sum+combination%28n%2Bx+%2Cx%29%2C+x%3Dl+to+r&lang=ja 
       check n+x < [COM_PRECALC_MAX]    */
    T sum_of_comb(int n,int l,int r){
        if(l>r)return T(0);
        T ret=T(r+1)*com(n+r+1,r+1)-T(l)*com(l+n,l);
        ret/=T(n+1);
        return ret;
    }
};
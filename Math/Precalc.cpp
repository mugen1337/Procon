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
    // 区別できるn人をkチームにわける，チームには最低1人属する
    // ベン図をイメージ, 包除
    // require : T(num).pow(k)
    T Stirling_number(int n,int k){
        T ret=0;
        for(int i=0;i<=k;i++) ret+=com(k,i)*T(i).pow(n)*((k-i)%2?(-1):1);
        return ret/T(fac(k));
    }
    // 区別できるn人をkチーム以下にわける
    T Bell_number(int n,int k){
        T ret=0;
        for(int i=1;i<=k;i++) ret+=Stirling_number(n,i);
        return ret;
    }
    T partition_function(int n,int k){
        auto table=partition_function_table(n,k);
        return table[n][k];
    }
    vector<vector<T>> partition_function_table(int n,int k){
        vector<vector<T>> ret(n+1,vector<T>(k+1,0));
        ret[0][0]=1;
        for(int i=0;i<=n;i++)for(int j=1;j<=k;j++)if(i or j){
            ret[i][j]=ret[i][j-1];
            if(i-j>=0) ret[i][j]+=ret[i-j][j];
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
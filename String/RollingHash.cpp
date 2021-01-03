// hash type
using ull=unsigned long long;
struct RollingHash{
    using ull=unsigned long long;
    using uint128=__uint128_t;
    static const ull MOD=(1ull<<61ull)-1;
    vector<ull>hashed,power;
    const ull base;
 
    static inline ull add(ull a,ull b){if((a+=b)>=MOD)a-=MOD;return a;}
    static inline ull mul(ull a,ull b){uint128 c=(uint128)a*b;return add(c>>61,c&MOD);}
    static inline ull generate_base(){
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<ull>rand(1,RollingHash::MOD-1);
        return rand(mt);
    }
    RollingHash()=default;
    RollingHash(const string &s,ull base):base(base){
        int sz=(int)s.size();
        hashed.assign(sz+1,0);
        power.assign(sz+1,0);
        power[0]=1;
        for(int i=0;i<sz;i++){
            power[i+1]=mul(power[i],base);
            hashed[i+1]=add(mul(hashed[i],base),s[i]);
        }
    }
    template<typename T>
    RollingHash(const vector<T>&s,ull base):base(base){
        int sz=(int)s.size();
        hashed.assign(sz+1,0);
        power.assign(sz+1,0);
        power[0]=1;
        for(int i=0;i<sz;i++){
            power[i+1]=mul(power[i],base);
            hashed[i+1]=add(mul(hashed[i],base),s[i]);
        }
    }
    // hash[l,r)
    ull get(int l,int r)const{
        return add(hashed[r],MOD-mul(hashed[l],power[r-l]));
    }
    ull concat(ull hash1,ull hash2,int hash2len)const{
        return add(mul(hash1,power[hash2len]),hash2);
    }
    int lcp(const RollingHash &b,int l1,int r1,int l2,int r2)const{
        assert(b.base==base);
        int len=min(r1-l1,r2-l2);
        int lw=0,hi=len+1;
        while(hi-lw>1){
            int mid=(lw+hi)/2;
            if(get(l1,l1+mid)==b.get(l2,l2+mid))lw=mid;
            else hi=mid;
        }
        return lw;
    }
};
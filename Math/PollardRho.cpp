template<typename T>
struct FastPrime{
    private:

    T pow_mod(T a,T n,T m){
        T ret=1;
        while(n){
            if(n&1) ret=ret*a%m;
            a=a*a%m;
            n>>=1;
        }
        return ret;
    }

    T gcdT(T a,T b){
        if(a==0) return b;
        if(b==0) return a;
        return b>0?gcdT(b,a%b):a;
    }

    T pollard_rho_single(T n){
        auto f=[&](T x){return (x*x+1)%n;};
        if(miller_rabin(n)) return n;
        if(!(n&1)) return 2;
        T a=0;
        while(true){
            a++;
            T x=a;
            T y=f(x);
            while(true){
                T g=gcdT(y-x+n,n);
                if(g==0 or g==n) break;
                if(g!=1) return g;
                x=f(x);
                y=f(f(y));
            }
        }
    }

    public:
    bool miller_rabin(T n){
        if(n<=1) return false;
        if(n==2) return true;
        if(n%2==0) return false;
        T d=n-1,s=0;
        while(!(d&1))d>>=1,s++;// n-1=2^s*d
        for(T a:{2,3,5,7,11,13,17,19,23,29,31,37}){
            if(n<=a) break;
            T y=pow_mod(a,d,n);// y=a^d (mod n)
            T t;
            for(t=d;t<n-1 and y!=1 and y!=n-1;t<<=1) y=y*y%n;
            if(y!=n-1 and t%2==0) return false;
        }
        return true;
    }

    vector<T> factorize(T n){
        if(n==1) return {};
        T x=pollard_rho_single(n);
        if(x==n) return {x};
        vector<T> l=factorize(x);
        vector<T> r=factorize(n/x);
        l.insert(l.end(),r.begin(),r.end());
        return l;
    }
};
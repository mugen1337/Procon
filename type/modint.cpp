template<ll Mod>
struct ModInt{
    long long x;
    ModInt():x(0){}
    ModInt(long long y):x(y>=0?y%Mod:(Mod-(-y)%Mod)%Mod){}
    ModInt &operator+=(const ModInt &p){
        if((x+=p.x)>=Mod) x-=Mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p){
        if((x+=Mod-p.x)>=Mod)x-=Mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p){
        x=(int)(1ll*x*p.x%Mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p){
        (*this)*=p.inverse();
        return *this;
    }
    ModInt operator-()const{return ModInt(-x);}
    ModInt operator+(const ModInt &p)const{return ModInt(*this)+=p;}
    ModInt operator-(const ModInt &p)const{return ModInt(*this)-=p;}
    ModInt operator*(const ModInt &p)const{return ModInt(*this)*=p;}
    ModInt operator/(const ModInt &p)const{return ModInt(*this)/=p;}
    bool operator==(const ModInt &p)const{return x==p.x;}
    bool operator!=(const ModInt &p)const{return x!=p.x;}
    ModInt inverse()const{
        int a=x,b=Mod,u=1,v=0,t;
        while(b>0){
            t=a/b;
            swap(a-=t*b,b);swap(u-=t*v,v);
        }
        return ModInt(u);
    }
    ModInt pow(long long n)const{
        ModInt ret(1),mul(x);
        while(n>0){
            if(n&1) ret*=mul;
            mul*=mul;n>>=1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os,const ModInt &p){return os<<p.x;}
    friend istream &operator>>(istream &is,ModInt &a){long long t;is>>t;a=ModInt<Mod>(t);return (is);}
    static int get_mod(){return Mod;}
};
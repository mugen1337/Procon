template<class INT>
struct Fraction{
    INT num,den;// numerator / denominator
    INT Igcd(INT a,INT b){return (b?Igcd(b,a%b):a);}
    void normalize(){
        INT g=Igcd(num,den);
        num/=g;den/=g;
        if(den<0)num=-num,den=-den;
    }
    Fraction(INT num=0,INT den=1):num(num),den(den){normalize();}
    long double to_ld()const{return (long double)num/den;}
    double to_d()const{return (double)num/den;}
    Fraction &operator+=(const Fraction &rhs){
        num=num*rhs.den+rhs.num*den;
        den*=rhs.den;
        normalize();
        return *this;
    }
    Fraction &operator-=(const Fraction &rhs){
        num=num*rhs.den-rhs.num*den;
        den*=rhs.den;
        normalize();
        return *this;
    }
    Fraction &operator*=(const Fraction &rhs){
        num*=rhs.num;
        den*=rhs.den;
        normalize();
        return *this;
    }
    Fraction &operator/=(const Fraction &rhs){
        num*=rhs.den;
        den*=rhs.num;
        normalize();
        return *this;
    }
    Fraction abs(){
        Fraction ret(*this);
        if(ret<0)ret.first=ret.first*(-1);
        return ret;
    }
    Fraction operator-(){(*this).first*=-1;return *this;}
    Fraction operator+(const Fraction &rhs)const{return Fraction(*this)+=rhs;}
    Fraction operator-(const Fraction &rhs)const{return Fraction(*this)-=rhs;}
    Fraction operator*(const Fraction &rhs)const{return Fraction(*this)*=rhs;}
    Fraction operator/(const Fraction &rhs)const{return Fraction(*this)/=rhs;}
    bool operator==(const Fraction &rhs)const{return num*rhs.den==den*rhs.num;}
    bool operator!=(const Fraction &rhs)const{return !(*this==rhs);}
    bool operator>=(const Fraction &rhs)const{return num*rhs.den>=den*rhs.num;}
    bool operator<=(const Fraction &rhs)const{return num*rhs.den<=den*rhs.num;}
    bool operator>(const Fraction &rhs)const{return num*rhs.den>den*rhs.num;}
    bool operator<(const Fraction &rhs)const{return num*rhs.den<den*rhs.num;}
    friend ostream &operator<<(ostream &os,const Fraction &p){return os<<p.num<<"/"<<p.den;}
};

template<typename T>
struct FormalPowerSeriesNaive:vector<T>{
    using vector<T>::vector;
    using P=FormalPowerSeriesNaive;

    P multiply(const P &lhs,const P &rhs){
        auto ret=P((int)lhs.size()+rhs.size()-1);
        for(int i=0;i<(int)lhs.size();i++)for(int j=0;j<(int)rhs.size();j++) ret[i+j]+=lhs[i]*rhs[j];
        return ret;
    }

    void shrink(){while(this->size() and this->back()==T(0)) this->pop_back();}
    P pre(int sz)const{return P(begin(*this),begin(*this)+min((int)this->size(),sz));}
    P operator+(const P &rhs)const{return P(*this)+=rhs;}
    P operator+(const T &rhs)const{return P(*this)+=rhs;}
    P operator-(const P &rhs)const{return P(*this)-=rhs;}
    P operator-(const T &rhs)const{return P(*this)-=rhs;}
    P operator*(const P &rhs)const{return P(*this)*=rhs;}
    P operator*(const T &rhs)const{return P(*this)*=rhs;}
    P operator/(const P &rhs)const{return P(*this)/=rhs;}
    P operator%(const P &rhs)const{return P(*this)%=rhs;}
    P &operator+=(const P &rhs){
        if(rhs.size()>this->size()) this->resize(rhs.size());
        for(int i=0;i<(int)rhs.size();i++) (*this)[i]+=rhs[i];
        return (*this);
    }
    P &operator+=(const T &rhs){
        if(this->empty()) this->resize(1);
        (*this)[0]+=rhs;
        return (*this);
    }
    P &operator-=(const P &rhs){
        if(rhs.size()>this->size()) this->resize(rhs.size());
        for(int i=0;i<(int)rhs.size();i++) (*this)[i]-=rhs[i];
        shrink();
        return (*this);
    }
    P &operator-=(const T &rhs){
        if(this->empty()) this->resize(1);
        (*this)[0]-=rhs;
        shrink();
        return (*this);
    }
    P &operator*=(const T &rhs){
        const int n=(int)this->size();
        for(int i=0;i<n;i++) (*this)[i]*=rhs;
        return (*this);
    }
    P &operator*=(const P &rhs){
        if(this->empty() or rhs.empty()){
            this->clear();
            return (*this);
        }
        auto ret=multiply(*this,rhs);
        (*this)=ret;
        return (*this);
    }
    P &operator%=(const P &rhs){return (*this)-=(*this)/rhs*rhs;}
    P operator-()const{
        P ret(this->size());
        for(int i=0;i<(int)this->size();i++) ret[i]=-(*this)[i];
        return ret;
    }
    P &operator/=(const P &rhs){
        if(this->size()<rhs.size()){
            this->clear();
            return (*this);
        }
        int n=(int)this->size()-rhs.size()+1;
        return (*this)=(rev().pre(n)*rhs.rev().inv(n));
    }
    P operator>>(int sz)const{
        if((int)this->size()<=sz) return {};
        P ret(*this);
        ret.erase(ret.begin(),ret.begin()+sz);
        return ret;
    }
    P operator<<(int sz)const{
        P ret(*this);
        ret.insert(ret.begin(),sz,T(0));
        return ret;
    }
    P rev(int deg=-1)const{
        P ret(*this);
        if(deg!=-1) ret.resize(deg,T(0));
        reverse(begin(ret),end(ret));
        return ret;
    }
    // ref : https://qiita.com/hotman78/items/f0e6d2265badd84d429a
    P inv(int deg=-1)const{
        assert(((*this)[0])!=T(0));
        const int n=(int)this->size();
        if(deg==-1) deg=n;
        P ret({T(1)/(*this)[0]});
        for(int i=1;i<deg;i<<=1) ret=(ret+ret-ret*ret*pre(i<<1)).pre(i<<1);
        return ret.pre(deg);
    }
    // O(Mult * log k)
    P pow(ll k,int deg=-1){
        if(deg==-1) deg=1000000000;
        P ret=P{1};
        P b(*this);
        while(k){
            if(k&1) ret*=b;
            b=b*b;
            k>>=1;
            if((int)ret.size()>deg) ret.resize(deg);
            if((int)b.size()>deg) b.resize(deg);
        }
        return ret;
    }
    // [l,r) k個飛び
    P slice(int l,int r,int k=1){
        P ret;
        for(int i=l;i<r;i+=k) ret.push_back((*this)[i]);
        return ret;
    }
    /*
    ref : https://atcoder.jp/contests/aising2020/submissions/15300636
          http://q.c.titech.ac.jp/docs/progs/polynomial_division.html
 
    order :      
        O(M(d)log(k))  (M(d) -> d次元，multiplyの計算量)
 
    return :
        [x^k] (*this) / q
    */
    T nth_term(P q,ll k){
        if(k==0) return (*this)[0]/q[0];
        P p(*this);
        P q_=q;
        for(int i=1;i<(int)q_.size();i+=2) q_[i]*=-1;
        q*=q_;p*=q_;// qは奇数項が消える
        return p.slice(k%2,p.size(),2).nth_term(q.slice(0,q.size(),2),k/2);
    }
};
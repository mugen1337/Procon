template<typename T=int>
struct BinaryBasis{
    vector<T> base;
    
    BinaryBasis(){}

    bool add(T bit){
        for(auto &x:base) chmin(bit,bit^x);
        if(bit){
            base.push_back(bit);
            return true;
        }
        return false;
    }

    T solve(T r){
        T ret=0;
        for(auto &x:base)if(chmin(r,r^x)) ret^=x;
        if(r) return -1;
        return ret;
    }

    void normalize(){
        for(int i=(int)base.size()-1;i>=0;i--)
            for(int j=i-1;j>=0;j--) base[i]=min(base[i],base[i]^base[j]);
    }

    // check normalized this and r
    bool eq(BinaryBasis<T> &r){
        return base==r.base;
    }

    int size(){
        return (int)base.size();
    }
};

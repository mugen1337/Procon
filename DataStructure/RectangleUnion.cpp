template<typename T>
struct RectangleUnion{
    private:
    map<T,T> mp;

    public:
    T S;
    
    RectangleUnion():S(0){
        const T inf=numeric_limits<T>::max()/2;
        mp[0]=inf;
        mp[inf]=0;
    }

    void add(T x,T y){
        auto ite=mp.lower_bound(x);
        if(ite->second>=y) return ;
        T lw=ite->second;
        S+=(y-lw)*x;
        ite=prev(ite);
        while(ite->second<=y){
            S-=ite->first*(ite->second-lw);
            lw=ite->second;
            ite=prev(mp.erase(ite));
        }
        S-=(ite->first)*(y-lw);
        mp[x]=y;
    }
};
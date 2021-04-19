template<typename T>
struct AbsoluteSum{
    multiset<T> L,R;
    T min_f;
    
    AbsoluteSum():min_f(0){}

    // add |x-a|
    void insert(T a){
        if(L.empty() or R.empty()){
            L.insert(a);
            R.insert(a);
            return ;
        }
        T pl=*prev(end(L)),pr=*begin(R);
        L.insert(a);
        R.insert(a);
        if(pl<=a and a<=pr) return ;
        // 端をswapするだけでいい
        if(*prev(end(L))>*begin(R)){
            T cl=*prev(end(L)),cr=*begin(R);
            L.erase(L.find(cl));
            R.erase(R.find(cr));
            R.insert(cl);
            L.insert(cr);
        }
        min_f+=std::min(abs(pl-a),abs(pr-a));
        return ;
    }

    // erase |x-a|
    void erase(T a){
        if(L.find(a)!=end(L) and R.find(a)!=end(R)){
            L.erase(L.find(a));
            R.erase(R.find(a));
            return ;
        }
        if(L.find(a)!=end(L)){
            L.erase(L.find(a));
            L.erase(L.find(a));
            L.insert(*begin(R));
            R.erase(begin(R));
        }else{
            R.erase(R.find(a));
            R.erase(R.find(a));
            R.insert(*prev(end(L)));
            L.erase(prev(end(L)));
        }
        T l=*prev(end(L)),r=*begin(R);
        if(l<=a and a<=r) return ;
        min_f-=std::min(abs(l-a),abs(r-a));
        return ;
    }

    T min(){return min_f;}

    T operator()(T x){
        T ret=min_f;
        for(const auto &a:L) ret+=max(a-x,T(0));
        for(const auto &b:R) ret+=max(x-b,T(0));
        return ret;
    }
};
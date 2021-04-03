// ref: https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
template<typename T>
struct SlopeTrick{
    multiset<T> L,R;
    T min_f,inf,shift_L,shift_R;

    // queue operation
    T pop_L(){
        T ret=*prev(end(L));
        L.erase(prev(end(L)));
        return ret+shift_L;
    }
    T pop_R(){
        T ret=*begin(R);
        R.erase(begin(R));
        return ret+shift_R;
    }
    T top_L(){ return *prev(end(L))+shift_L; }
    T top_R(){ return *begin(R)+shift_R; }
    void push_L(T x){ L.insert(x-shift_L); }
    void push_R(T x){ R.insert(x-shift_R); }

    // operations
    SlopeTrick(T min_f=0):min_f(min_f),inf(numeric_limits<T>::max()/2),shift_L(0),shift_R(0){
        push_L(-inf);
        push_R(inf);
    }
    // add a, all
    void add(T a){ min_f+=a; }
    // add max(0, x-a) ( __/ )
    void add_xa(T a){
        min_f+=max(top_L()-a,T(0));
        push_L(a);
        push_R(pop_L());
    }
    // add max(0, a-x) ( \__ )
    void add_ax(T a){
        min_f+=max(a-top_R(),T(0));
        push_R(a);
        push_L(pop_R());
    }
    // add |x-a| ( \/ )
    void add_abs(T a){
        add_xa(a);
        add_ax(a);
    }
    // \/ -> \__
    void clear_R(){
        R.clear();
        push_R(inf);
    }
    // \/ -> __/
    void clear_L(){
        L.clear();
        push_L(-inf);
    }
    // f(x) -> f(x-a)
    void shift(T a){
        shift_L+=a,shift_R+=a;
    }
    T get_min(){ return min_f; }
    // O(N)
    T operator()(T x){
        T l0=top_L(),r0=top_R();
        if(l0<=x and x<=r0) return min_f;
        T ret=min_f;
        if(x<l0) for(auto ite=prev(end(L));x<*ite+shift_L;ite--) ret+=*ite+shift_L-x;
        else     for(auto ite=begin(R);*ite+shift_R<x;ite++)     ret+=x-*ite-shift_R;
        return ret;
    }
};
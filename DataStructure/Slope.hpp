// https://yukicoder.me/submissions/644671
// https://ei1333.github.io/library/structure/others/slope-queue.hpp
// https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
// ex)
// f(x) <- min_{y<=x+k} f(y)
//      1. f.shift(k)
//      2. f.apply_cumulative_min()
template<typename T>
struct Slope{
// private:
    using P=pair<T,T>;
    priority_queue<P,vector<P>,less<P>>    L;
    priority_queue<P,vector<P>,greater<P>> R;
    T add_L,add_R,min_f;
    void push_R(T a,T cnt){if(cnt>0) R.emplace(a-add_R,cnt);}
    void push_L(T a,T cnt){if(cnt>0) L.emplace(a-add_L,cnt);}
    P top_R(){return P(R.top().first+add_R,R.top().second);}
    P top_L(){return P(L.top().first+add_L,L.top().second);}
    P pop_R(){
        P ret=top_R();
        R.pop();
        return ret;
    }
    P pop_L(){
        P ret=top_L();
        L.pop();
        return ret;
    }

public:
    Slope():add_L(0),add_R(0),min_f(0){}
    void add_all(T a){min_f+=a;}
    void add_x_minus_a(T a,T cnt=1){
        while(cnt>0 and !L.empty() and a<top_L().first){
            auto [pos,num]=pop_L();
            T mv=std::min(cnt,num);
            push_R(pos,mv);
            push_L(pos,num-mv);
            push_L(a,mv);
            min_f+=(pos-a)*mv;
            cnt-=mv;
        }
        push_R(a,cnt);
    }
    void add_a_minus_x(T a,T cnt=1){
        while(cnt>0 and !R.empty() and a>top_R().first){
            auto [pos,num]=pop_R();
            T mv=std::min(cnt,num);
            push_L(pos,mv);
            push_R(pos,num-mv);
            push_R(a,mv);
            min_f+=(a-pos)*mv;
            cnt-=mv;
        }
        push_L(a,cnt);
    }
    void add_abs(T a,T cnt=1){
        add_a_minus_x(a,cnt);
        add_x_minus_a(a,cnt);
    }
    void clear_right(){while(!R.empty()) R.pop();}
    void clear_left(){ while(!L.empty()) L.pop();}
    // f <- min{x-b<=y<=x-a} f(y)
    void shift(T a,T b){
        assert(a<=b);
        add_L+=a,add_R+=b;
    }
    // f(x) <- f(x-a)
    void shift(T a){shift(a,a);}
    // get value O(N)
    T operator()(T x){
        T ret=min_f;
        auto vec=[](auto pq,T shift){
            vector<P> v;
            while(!pq.empty()){
                v.emplace_back(pq.top().first+shift,pq.top().second);
                pq.pop();
            }
            return v;
        };
        for(auto [pos,num]:vec(L,add_L)) ret+=max(pos-x,T(0))*num;
        for(auto [pos,num]:vec(R,add_R)) ret+=max(x-pos,T(0))*num;
        return ret;
    }
    T min(){return min_f;}
    pair<T,T> argmin(){return make_pair(P(top_L().first,top_R().first));}
};

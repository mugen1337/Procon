// Monoid Sliding-Window-AGregation
template<typename Monoid>
struct SWAG{
    using F=function<Monoid(Monoid,Monoid)>;
    const F f;
    const Monoid e;
    stack<pair<Monoid,Monoid>> fr,ba;
    SWAG(const F f,const Monoid &e):f(f),e(e){}
    Monoid get(){
        Monoid a=fr.empty()?e:fr.top().second;
        Monoid b=ba.empty()?e:ba.top().second;
        return f(a,b);
    }
    void push(Monoid x){
        if(ba.empty()) ba.push(make_pair(x,x));
        else ba.push(make_pair(x,f(ba.top().second,x)));
    }
    void pop(){
        if(empty()) return ;
        if(!fr.empty()) fr.pop();
        else{
            while(!ba.empty()){
                pair<Monoid,Monoid> p=ba.top();ba.pop();
                if(fr.empty()) fr.push(make_pair(p.first,p.first));
                else fr.push(make_pair(p.first,f(p.first,fr.top().second)));
            }
            fr.pop();
        }
    }
    size_t size(){
        return fr.size()+ba.size();
    }
    bool empty(){
        return size()==0;
    }
};
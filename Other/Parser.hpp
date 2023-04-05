// 構文解析
template<typename T>
struct Parser{
    bool error;// ヤバイ時trueに
    Parser():error(false){}

    // 四則演算
    T expression(string s,int &p){
        T res=term(s,p);
        while(p<(int)s.size()){
            if(s[p]=='+'){
                p++;
                res+=term(s,p);
                continue;
            }
            if(s[p]=='-'){
                p++;
                res-=term(s,p);
                continue;
            }
            break;
        }
        return res;
    }

    // 乗除
    T term(string s,int &p){
        T res=factor(s,p);
        while(p<(int)s.size()){
            if(s[p]=='*'){
                p++;
                res*=factor(s,p);
                continue;
            }
            if(s[p]=='/'){
                p++;
                T d=factor(s,p);
                if(d==T(0)){
                    error=true;
                    break;
                }
                res/=d;
                continue;
            }
            break;
        }
        return res;
    }

    // カッコ，数
    T factor(string &s,int &p){
        T res;
        if(s[p]=='('){
            p++;
            res=expression(s,p);
            p++;
        }else{
            res=number(s,p);
        }
        return res;
    }

    // 数，intのみならこれでいい．
    // int以外の数を受け取る場合は適宜編集すること
    T number(string s,int &p){
        T res=0;
        while(p<(int)s.size() and isdigit(s[p])) res=res*10+s[p++]-'0';
        return res;
    }


    T execute(string s){
        int p=0;
        error=false;
        return expression(s,p);
    }
};
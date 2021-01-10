// 2^127 = 170141183460469231731687303715884105728 ~ 10^38
 
ostream &operator<<(ostream &os,const __int128 n){
    if(n==0){
        os<<0;
        return os;
    }
    __int128 num=n;
    bool neg=false;
    if(num<0)neg=true,num=-num;
    string res="";
    while(num>0){
        res.push_back('0'+num%10);
        num/=10;
    }
    if(neg) res.push_back('-');
    reverse(begin(res),end(res));
    os<<res;
    return os;
}
 
istream &operator>>(istream &is,__int128 &n){
    string s;
    is>>s;
    int idx=0;
    bool neg=false;
    if(s[0]=='-')neg=true,idx++;
    n=0;
    for(;idx<(int)s.size();idx++){
        n=10*n+s[idx]-'0';
    }
    if(neg) n=-n;
    return is;
}

__int128 abs128(__int128 x){
    return x<0?-x:x;
}
 
__int128 gcd128(__int128 a,__int128 b){
    if(a==0) return b;
    if(b==0) return a;
    return b>0?gcd128(b,a%b):a;
}
using int128=__int128;
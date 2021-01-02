#include<bits/stdc++.h>
using namespace std;
#define ALL(x) begin(x),end(x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define mod 1000000007
using ll=long long;
const int INF=1000000000;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

struct IOSetup{
    IOSetup(){
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout<<fixed<<setprecision(12);
    }
} iosetup;
 
template<typename T>
ostream &operator<<(ostream &os,const vector<T>&v){
    for(int i=0;i<(int)v.size();i++) os<<v[i]<<(i+1==(int)v.size()?"":" ");
    return os;
}
template<typename T>
istream &operator>>(istream &is,vector<T>&v){
    for(T &x:v)is>>x;
    return is;
}

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0109"


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

Parser<int> parse;

void solve(){
    string s;cin>>s;
    s.pop_back();
    cout<<parse.execute(s)<<endl;
}

signed main(){
    int q;cin>>q;
    while(q--) solve();
    return 0;
}
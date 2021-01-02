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

#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

// 経路圧縮なし，マージテクでunite，クエリ毎O(logN)
struct UnionFindUndo{
    int con;
    vector<int> data;
    stack<tuple<int,int,bool>> history;
    UnionFindUndo(int sz){
        con=sz;
        data.assign(sz,-1);
    }
    bool unite(int x,int y){
        x=root(x),y=root(y);
        
        if(x==y){
            history.push(make_tuple(x,data[x],false));
            history.push(make_tuple(y,data[y],false));
            return false;
        }
        con--;
        history.push(make_tuple(x,data[x],true));
        history.push(make_tuple(y,data[y],false));
        if(data[x]>data[y]) swap(x,y);
        data[x]+=data[y];
        data[y]=x;
        return true;
    }
    int root(int k){return (data[k]<0?k:(root(data[k])));}
    int size(int k){return (-data[root(k)]);}
    bool sameroot(int x,int y){return root(x)==root(y);}
    void undo(){
        {
            auto [fs,sc,con_flag]=history.top();history.pop();
            if(con_flag) con++;
            data[fs]=sc;
        }
        {
            auto [fs,sc,con_flag]=history.top();history.pop();
            if(con_flag) con++;
            data[fs]=sc;
        }
    }
    void snapshot(){while(!history.empty())history.pop();}
    void rollback(){while(!history.empty())undo();}
};

signed main(){
    int n,q;cin>>n>>q;
    UnionFindUndo uf(n);
    while(q--){
        int t,u,v;cin>>t>>u>>v;
        if(t) cout<<uf.sameroot(u,v)<<endl;
        else uf.unite(u,v);
    }
    return 0;
}

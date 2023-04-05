// PROBLEM : https://codeforces.com/contest/1279/problem/F
// SUBMIT  : https://codeforces.com/contest/1279/submission/105194010

// vは0 or 1
// 幅lを全て1にできる．という操作をk回まで行える．
// 1の数を最大化する．
int solve(vector<int> v,int l,int k){
    using P=pair<int,int>;

    int n=(int)v.size();

    // 1の数の最大化, 操作1回でペナ
    auto f=[&](int pena){
        vector<P> dp(n+1,P(-INF,0));
        dp[0]=P(0,0);
        rep(i,n){
            int nxt=min(i+l,n);
            chmax(dp[nxt],P(dp[i].first+(nxt-i)-pena,dp[i].second+1));
            chmax(dp[i+1],P(dp[i].first+v[i],dp[i].second));
        }
        return dp[n];
    };

    // 操作k回以上，最小
    int lw=0,hi=n+2,pena=0;
    while(lw<=hi){
        int m=(lw+hi)/2;
        P x=f(m);
        if(x.second>=k){
            pena=m;
            lw=m+1;
        }else{
            hi=m-1;
        }
    }

    auto ans=f(pena);
    // k個まではokなのでペナを帳消し
    // この時，dpではk回以上ひっくり返しているかもしれないが，
    // ひっくり返す利得と払うペナが釣り合っているのでk回分チャラにするだけでよい
    int ret=ans.first+pena*k;
    return ret;
}

/*
幅lの文字全てを大文字へ，小文字へ，ができる
min(大文字の数，小文字の数)の最小化
*/
void ECR79F(){
    int n,k,l;cin>>n>>k>>l;
    string s;cin>>s;
    vector<int> v(n);
    rep(i,n) v[i]=('a'<=s[i] and s[i]<='z');

    int res=INF;
    chmin(res,n-solve(v,l,k));
    for(auto &x:v) x^=1;
    chmin(res,n-solve(v,l,k));
    cout<<res<<endl;
}
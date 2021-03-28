template<typename S>
S LongestCommonSubsecence(S a,S b){
    int n=(int)a.size(),m=(int)b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)),pre(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++){
        if(i<n and j<m and a[i]==b[j]){
            if(chmax(dp[i+1][j+1],dp[i][j]+1)) pre[i+1][j+1]=1;
        }
        if(i<n)if(chmax(dp[i+1][j],dp[i][j])) pre[i+1][j]=2;
        if(j<m)if(chmax(dp[i][j+1],dp[i][j])) pre[i][j+1]=3;
    }

    S ret;
    int i=n,j=m;
    while(i and j and pre[i][j]>0){
        if(pre[i][j]==1){
            i--,j--;
            ret.push_back(a[i]);
        }
        else if(pre[i][j]==2) i--;
        else if(pre[i][j]==3) j--;
    }

    reverse(begin(ret),end(ret));
    return ret;
}

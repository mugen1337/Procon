// solve A * X = Y
// T : floating point
template<typename T>
vector<T> LinearEquation(vector<vector<T>> A,vector<T> Y,T EPS=1e-6){
    int n=(int)A.size(),m=(int)A[0].size();
    for(int i=0;i<n;i++) A[i].push_back(Y[i]);

    int rank=0;
    for(int j=0;j<m;j++){
        int p=-1;
        T mx=EPS;
        for(int i=rank;i<n;i++)if(chmax(mx,abs(A[i][j]))) p=i;
        if(p==-1) continue;

        swap(A[p],A[rank]);
        T t=A[rank][j];
        for(int k=0;k<=m;k++) A[rank][k]/=t;
        for(int i=0;i<n;i++){
            if(i==rank) continue;
            T s=A[i][j];
            for(int k=0;k<=m;k++) A[i][k]-=s*A[rank][k];
        }
        rank++;
    }

    vector<T> ret;
    for(int i=rank;i<n;i++)if(abs(A[i][m])>EPS) return ret;
    ret.assign(m,0);
    for(int i=0;i<rank;i++) ret[i]=A[i][m];
    return ret;
}

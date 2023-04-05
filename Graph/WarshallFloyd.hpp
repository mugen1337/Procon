template<typename T>
vector<vector<T>> WarshallFloyd(vector<vector<T>> mat, T inf=1000000100){
    int n=(int)mat.size();
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)
    if(mat[i][k]<inf and mat[k][j]<inf) mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
    return mat;
}
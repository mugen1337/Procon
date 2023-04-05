// mat * vec = vec
// A * x = b
// ans, rank
// ans is empty if ans doesn't exist
// https://drken1215.hatenablog.com/entry/2019/03/20/202800
pair<vector<int>,int> LinearEquationF2(vector<vector<int>> A,vector<int> b){
    int rank=0;
    int H=(int)A.size(),W=(int)A[0].size();
    for(int j=0;j<W;j++){
        int p=-1;
        for(int i=rank;i<H;i++){
            if(A[i][j]){
                p=i;
                break;
            }
        }
        if(p==-1) continue;
        swap(A[p],A[rank]);
        swap(b[p],b[rank]);

        for(int i=0;i<H;i++)if(i!=rank){
            if(A[i][j]){
                for(int k=0;k<W;k++) A[i][k]^=A[rank][k];
                b[i]^=b[rank];
            }
        }
        rank++;
    }

    for(int i=rank;i<H;i++) if(b[i]) return make_pair(vector<int>{},-1);

    return make_pair(b,rank);
}
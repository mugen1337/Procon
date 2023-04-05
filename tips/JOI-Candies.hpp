// https://www.ioi-jp.org/camp/2018/2018-sp-tasks/day4/candies.pdf
/*
各 k (0 <= k <= ceil(|A| / 2))に関し，Aから隣り合わないようにk個要素を選んだ時
総和の最大値を求める

input  : A
output : ret[i] := (k=i)の時の答え
*/
template<typename T>
vector<T> JOI_Candies(vector<T> A){
    T inf=numeric_limits<T>::max()/4;
    int N=(int)A.size();
    int K=(N+1)/2;
    vector<T> ret(K+1,0);
    T res=0;

    vector<int> L(N),R(N);
    using P=pair<T,int>;
    priority_queue<P> que;
    for(int i=0;i<N;i++){
        L[i]=i-1;
        R[i]=i+1;
        que.emplace(A[i],i);
    }

    ret[0]=0;
    for(int k=1;k<=K;k++){
        T x;int i;
        do{
            tie(x,i)=que.top();
            que.pop();
        }while(A[i]!=x);

        ret[k]=(res+=x);
        
        bool f=(L[i]>=0 and R[i]<N);
        A[i]*=-1;
        if(L[i]>=0){
            A[i]+=A[L[i]];
            A[L[i]]=-inf;
            L[i]=L[L[i]];
            if(L[i]>=0) R[L[i]]=i;
        }
        if(R[i]<N){
            A[i]+=A[R[i]];
            A[R[i]]=-inf;
            R[i]=R[R[i]];
            if(R[i]<N) L[R[i]]=i;
        }

        if(f) que.emplace(A[i],i);
        else  A[i]=-inf;
    }
    return ret;
}
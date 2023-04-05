// verify : https://atcoder.jp/contests/atc002/submissions/26006416
template<typename T>
T hu_tucker(vector<T> V){
    T inf=numeric_limits<T>::max()/4;
    int N=(int)V.size();
    vector<LeftistHeap<T>> heaps(N+1);
    vector<T> A(N+2,inf),B(N+1);
    vector<int> L(N+2),R(N+1);
    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;

    for(int i=0;i<N;i++) A[i+1]=V[i];
    for(int i=0;i<N+1;i++){
        L[i]=i-1,R[i]=i+1;
        B[i]=A[i]+A[i+1];
        que.emplace(B[i],i);
    }

    // heaps[l] <- heaps[r]
    auto merge=[&](int l,int r){
        heaps[l].meld(heaps[r]);
        R[l]=R[r],L[R[r]]=l,B[r]=inf+inf;
        return l;
    };

    T ret=0;
    for(int fuga=N-1;fuga;fuga--){
        T c;int i;
        do{ tie(c,i)=que.top();que.pop(); }while(B[i]!=c);
        ret+=c;

        bool fl=false,fr=false;
        if(A[i]+A[R[i]]==c)                fl=true,fr=true;// leaves
        else if(heaps[i].top()+A[R[i]]==c) fr=true,heaps[i].pop();
        else if(A[i]+heaps[i].top()==c)    fl=true,heaps[i].pop();
        else                               heaps[i].pop(),heaps[i].pop();// in group
        heaps[i].push(c);
        if(fl) i=merge(L[i],i);
        if(fr) i=merge(i,R[i]);

        T nw=A[i]+A[R[i]];
        chmin(nw,min(A[i],A[R[i]])+heaps[i].top());
        {
            T fs=inf,sc=inf;
            fs=heaps[i].pop();
            if(!heaps[i].empty()) sc=heaps[i].top();
            heaps[i].push(fs);
            chmin(nw,fs+sc);
        }
        que.emplace(B[i]=nw,i);
    }
    return ret;
}
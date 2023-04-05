/*
 * ref : https://atcoder.jp/contests/abc223/submissions/26660184
 * verified : https://atcoder.jp/contests/abc223/submissions/26660184
 * 
 * b[j] := (1<<j) が最大で立っている基底
 *         同時に，その基底の右端のindexも持つ
 * A[i]を見る時，いい感じに基底を入れ替える
*/
template<typename INT,int B>
struct StaticRangeSpanQuery{
    vector<INT> A;
    vector<tuple<int,int,INT,int>> query;

    StaticRangeSpanQuery(vector<INT> &A):A(A){}

    // X ∈ span({A[L,R)}) ?
    void add_query(int L,int R,INT X,int idx=-1){
        if(idx<0) idx=(int)query.size();
        query.emplace_back(L,R,X,idx);
    }

    vector<bool> build(){
        vector<vector<tuple<int,INT,int>>> Qs(A.size()+1);
        vector<bool> ans(query.size(),false);
        for(auto [L,R,X,idx]:query) Qs[R].emplace_back(L,X,idx);

        vector<pair<INT,int>> b(B);// 最も右の基底
        for(int i=0;i<B;i++) b[i]={INT(1)<<i,-1};

        for(int i=0;i<(int)A.size();i++){
            pair<INT,int> cur={A[i],i};
            for(int j=B-1;j>=0;j--){
                if((cur.first>>j)&1){
                    if(cur.second>b[j].second) swap(cur,b[j]);

                    cur.first^=b[j].first;
                }
            }

            for(auto [L,X,idx]:Qs[i+1]){
                for(int j=B-1;j>=0;j--)if((X>>j)&1 and b[j].second>=L) X^=b[j].first;
                ans[idx]=bool(X==0);
            }
        }
        return ans;
    }
};
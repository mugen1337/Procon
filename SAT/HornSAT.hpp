/*
Horn SAT
和積標準形に直した時，節の中にpositiveなliteralが1個までの時
線形時間でSATが解ける
逆にnegativeなliteralが1個までの場合は全部literalのpos/neg逆転して解く
*/
struct HornSAT{
    int N,n_clause;
    vector<vector<int>> neg,literal_to_clause;
    vector<int> pos,n_neg,res;

    HornSAT(int N):N(N),n_clause(0),literal_to_clause(N),res(N,-1){}
    
    // (prev) -> (prev)*(not(neg_literal[0])+...+pos_literal)
    void add_clause(vector<int> neg_literal, int pos_literal=-1){
        n_neg.push_back(neg_literal.size());
        neg.push_back(neg_literal);
        pos.push_back(pos_literal);
        for(int &t:neg_literal) literal_to_clause[t].push_back(n_clause);
        n_clause++;
    }

    vector<int> build(){
        queue<int> confirmed_clause;
        for(int i=0;i<n_clause;i++)if(n_neg[i]==0 and pos[i]>=0) confirmed_clause.push(i);
        
        while(!confirmed_clause.empty()){
            int cur=confirmed_clause.front();confirmed_clause.pop();
            int r=pos[cur];
            if(r>=0 and res[r]<0){
                res[r]=1;
                for(int &x:literal_to_clause[r]){
                    n_neg[x]--;
                    if(n_neg[x]==0) confirmed_clause.push(x);
                }
            }
        }
        for(int i=0;i<N;i++)if(res[i]==-1) res[i]=0;

        // verify
        for(int i=0;i<n_clause;i++){
            int T=0;
            for(int &x:neg[i])if(res[x]==0)  T++;
            if(pos[i]>=0 and res[pos[i]]==1) T++;

            if(T==0) return {};
        }
        return res;
    }
};
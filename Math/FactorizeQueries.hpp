// Precomputation : O(M log (log M)) (M : MAX)
// Factorize Query : O(log N) (N<=MAX)
template<int MAX>
struct FactorizeQueries{
    vector<int> min_factor;
    
    FactorizeQueries(){
        min_factor.resize(MAX+1);
        iota(begin(min_factor),end(min_factor),0);
        for(int i=2;i*i<=MAX;i++){
            if(min_factor[i]==i)
                for(int j=i+i;j<=MAX;j+=i) min_factor[j]=min(min_factor[j],i);
        }
    }
    
    vector<int> Factorize(int x){
        assert(x<=MAX);
        vector<int> ret;
        for(;x>1;x/=min_factor[x]) ret.push_back(min_factor[x]);
        return ret;
    }
};
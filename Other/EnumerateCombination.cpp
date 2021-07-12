vector<int> enumerate_combination(int n, int k){
    int comb = (1<<k) - 1;
    vector<int> ret;
    while(comb < (1<<n)){
        ret.push_back(comb);
        int x = comb & (-comb),y = comb + x;
        comb = ((comb&~y) / x>>1) | y;
    }
    return ret;
}
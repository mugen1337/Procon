struct RandomNumberGenerator{
    mt19937 mt;
    RandomNumberGenerator():mt(chrono::steady_clock::now().time_since_epoch().count()){}
    // [a,b)
    int operator()(int a,int b){
        uniform_int_distribution<int> d(a,b-1);
        return d(mt);
    }
};

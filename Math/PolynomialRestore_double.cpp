#include "./LinearEquation_double.cpp"

// f(x) = a_0 + a_1 * x .. .a_d * x^d
// O(d ^ 3)
template<typename T>
vector<T> PolynomialRestore(vector<T> x,vector<T> y,int d,T EPS=1e-6){
    vector<vector<T>> M(x.size(),vector<T>(d+1));
    for(int i=0;i<(int)x.size();i++){
        T p=1;
        for(int j=0;j<=d;j++){
            M[i][j]=p;
            p*=x[i];
        }
    }
    auto ret=LinearEquation(M,y,EPS);
    return ret;
}

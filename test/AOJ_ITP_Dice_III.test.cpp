#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_C"

#include "../template.hpp"

#include "../Other/Dice.hpp"

signed main(){
    Dice<int> A,B;
    cin>>A.u>>A.f>>A.r>>A.l>>A.b>>A.d;
    cin>>B.u>>B.f>>B.r>>B.l>>B.b>>B.d;
    cout<<(same_dice(A,B)?"Yes":"No")<<endl;
    return 0;
}
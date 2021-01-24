#define PROBLEM "https://yukicoder.me/problems/2577"

#include "../template.cpp"

#include "../DataStructure/RectangleUnion.cpp"

signed main(){
    int n;cin>>n;
    RectangleUnion<ll> ur,ul,dr,dl;
    ll pre=0;
    while(n--){
        ll xp,yp,xm,ym;cin>>xm>>ym>>xp>>yp;
        ur.add(xp,yp);
        ul.add(-xm,yp);
        dr.add(xp,-ym);
        dl.add(-xm,-ym);
        ll sum=ur.S+ul.S+dr.S+dl.S;
        cout<<sum-pre<<endl;
        pre=sum;
    }
    return 0;
}

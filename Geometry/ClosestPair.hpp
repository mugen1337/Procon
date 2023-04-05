// 最近点対
// O(NlogN)
Real closest_pair(vector<Point> ps){
    sort(ALL(ps),[&](Point a,Point b){
        return real(a)<real(b);
    });
    function<Real(int,int)> rec=[&](int l,int r){
        if(r-l<=1) return (Real)1e18;
        int m=(l+r)/2;
        Real x=real(ps[m]);
        Real ret=min(rec(l,m),rec(m,r));
        inplace_merge(begin(ps)+l,begin(ps)+m,begin(ps)+r,[&](Point a,Point b){
            return imag(a)<imag(b);
        });
        // 分割を跨いで最小距離があるか調べる
        vector<Point> b;
        for(int i=l;i<r;i++){
            if(abs(real(ps[i])-x)>=ret) continue;
            for(int j=(int)b.size()-1;j>=0;j--){
                if(abs(imag(ps[i]-b[j]))>=ret) break;
                ret=min(ret,abs(ps[i]-b[j]));
            }
            b.push_back(ps[i]);
        }
        return ret;
    };
    return rec(0,(int)ps.size());
}

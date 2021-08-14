#include "../type/modint.cpp"
#include "../SegmentTree/SegmentTree.cpp"

using mint=ModInt<998244353>;

/*
 https://yukicoder.me/problems/no/1649
 式変形して展開すると，sum(sum(|x_i - x_j| |y_i - y_j|))が計算できればよいとわかる．
 これはxが大きい順から処理することでx側の絶対値を外し，y側をセグメント木で管理し
 平面走査のような感じで解ける
*/
mint ManhattanSquareSum(vector<ll> x,vector<ll> y){
    int N=(int)x.size();
    mint ret=0;
    {
        mint sx=0,sy=0,sxx=0,syy=0;
        for(int i=0;i<N;i++){
            ret+=(mint)x[i]*x[i]*i+sxx-sx*x[i]*2;
            ret+=(mint)y[i]*y[i]*i+syy-sy*y[i]*2;
            sx+=x[i],sy+=y[i];
            sxx+=(mint)x[i]*x[i];
            syy+=(mint)y[i]*y[i];
        }
    }

    {
        vector<int> idx(N);
        iota(begin(idx),end(idx),0);
        sort(begin(idx),end(idx),[&](int i,int j){return x[i]>x[j];});
        auto nx=x,ny=y;
        for(int i=0;i<N;i++) nx[i]=x[idx[i]],ny[i]=y[idx[i]];
        swap(x,nx);
        swap(y,ny);
    }

    {
        vector<int> yid(N),yp(N);
        iota(begin(yid),end(yid),0);
        sort(begin(yid),end(yid),[&](int i,int j){return y[i]<y[j];});
        for(int i=0;i<N;i++) yp[yid[i]]=i;

        using P=pair<mint,mint>;
        auto segf=[&](P a,P b){
            a.first+=b.first;
            a.second+=b.second;
            return a;
        };
        SegmentTree<P> sega(N,segf,P(0,0)),segb(N,segf,P(0,0));
        for(int i=0;i<N;i++){
            sega.set(yp[i],P(y[i],1));
            segb.set(i,P(0,0));
        }
        sega.build();
        segb.build();

        for(int i=0;i<N;i++){
            int j=yp[i];
            auto l=sega.query(0,j);
            auto r=sega.query(j+1,N);
            mint add=mint(y[i])*l.second-l.first+r.first-mint(y[i])*r.second;

            l=segb.query(0,j);
            r=segb.query(j+1,N);
            mint sub=mint(y[i])*l.second-l.first+r.first-mint(y[i])*r.second;
            ret+=(add-sub)*x[i]*2;
            sega.update(j,P(0,0));
            segb.update(j,P(y[i],1));
        }
    }
    return ret;
}
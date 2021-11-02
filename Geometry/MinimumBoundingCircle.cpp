//最小包含円を返す　計算量は期待値O(n)
Circle MinimumBoundingCircle(vector<Point> v){
    int n=v.size();
    //ランダムシャッフル．いぢわるされたくないもんだ
    mt19937 mt(time(0));
    shuffle(v.begin(),v.end(),mt);
    Circle ret(0,0);

    auto make_circle2=[&](Point a,Point b){
        return Circle((a+b)*0.5,dis(a,b)/2);
    };

    auto make_circle3=[&](Point A,Point B,Point C){
        Point cent=circumscribed_circle(A,B,C).center;
        return Circle(cent,dis(cent,A));
    };

    auto isIn=[&](Point a){
        return dis(ret.center,a)<ret.r+EPS;
    };

    ret=make_circle2(v[0],v[1]);
    for(int i=2;i<n;i++){
        //v[i]が円に入っていないなら
        if(!isIn(v[i])){
            //円内にないなら点v[i]は必ず円周上に来る
            ret=make_circle2(v[0],v[i]);
            for(int j=1;j<i;j++){
                if(!isIn(v[j])){
                    //この時iとjが円周上を考える
                    ret=make_circle2(v[i],v[j]);
                    //最後の1点の決定
                    for(int k=0;k<j;k++)if(!isIn(v[k])) ret=make_circle3(v[i],v[j],v[k]);
                }
            }
        }
    }
    return ret;
}

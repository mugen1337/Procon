// 凸多角形内部と外周上の点をカウント
// 凸多角形以外を与えて良い
// ピックの定理，多角形の頂点がすべて格子点上に存在するなら成立
// S = i + b / 2 - 1
// (S : 多角形の面積, i : 格子点数, b : 辺上の格子点数)
// https://atcoder.jp/contests/typical90/submissions/24194520
Int CountLattice(vector<P> poly){
    int N=(int)poly.size();
 
    Int b=0;
    for(int i=0;i<N;i++){
        Int x=poly[(i+1)%N].first-poly[i].first,y=poly[(i+1)%N].second-poly[i].second;
        x=abs(x),y=abs(y);
        b+=gcd(x,y);
    }
 
    Int S=Area2(poly);
 
    return (S+b)/2+1;
}
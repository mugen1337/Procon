// Intersect (Requires : ccw, Dots, Cross, Projection)
bool intersect(Line l,Point p){
    return abs(ccw(l.p1,l.p2,p))!=1;
}
//直線の交差判定，外積
bool intersect(Line l1,Line l2){
    return abs(cross(l1.p2-l1.p1,l2.p2-l2.p1))>EPS or abs(cross(l1.p2-l1.p1,l2.p2-l1.p1))<EPS;
}
//線分に点が乗るかの判定，ccw
bool intersect(Segment s,Point p){
    return ccw(s.p1,s.p2,p)==0;
}
//直線と線分の交差判定
bool intersect(Line l,Segment s){
    return cross(l.p2-l.p1,s.p1-l.p1)*cross(l.p2-l.p1,s.p2-l.p1)<EPS;
}
//円と直線の交差判定
bool intersect(Circle c,Line l){
    return abs(c.center-projection(l,c.center))<=c.r+EPS;
}
//円上かどうか，内部かどうかではない
bool intersect(Circle c,Point p){
    return abs(abs(p-c.center)-c.r)<EPS;
}
//線分と線分の交差判定
bool intersect(Segment s,Segment t){
    return ccw(s.p1,s.p2,t.p1)*ccw(s.p1,s.p2,t.p2) <=0 and ccw(t.p1,t.p2,s.p1)*ccw(t.p1,t.p2,s.p2)<=0;
}
//線分と円の交差判定，交点の個数を返す
int intersect(Circle c,Segment l){
    Point h=projection(l,c.center);
    //直線まるっと円の外側
    if(norm(h-c.center)-c.r*c.r>EPS)    return 0;
    Real d1=abs(c.center-l.p1),d2=abs(c.center-l.p2);
    //線分が円内
    if(d1<c.r+EPS and d2<c.r+EPS) return 0;
    if((d1<c.r-EPS and d2>c.r+EPS) or (d2<c.r-EPS and d1>c.r+EPS)) return 1;
    //円の外部にまるまるはみ出ていないか
    if(dot(l.p1-h,l.p2-h)<0) return 2;
    return 0;
}
//円と円の位置関係，共通接線の個数を返す
int intersect(Circle c1,Circle c2){
    if(c1.r<c2.r) swap(c1,c2);
    Real d=abs(c1.center-c2.center);
    //2円が離れている
    if(c1.r+c2.r<d)     return 4;
    //2円が外接する
    if(eq(c1.r+c2.r,d)) return 3;
    //2円が交わる
    if(c1.r-c2.r<d)     return 2;
    //円が内接する
    if(eq(c1.r-c2.r,d)) return 1;
    //内包
                        return 0;
}
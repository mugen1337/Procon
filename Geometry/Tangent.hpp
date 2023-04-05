//v
//点pから引いた円cの接線の接点を返す
vector<Point> tangent(Circle c,Point p){
    return crosspoint(c,Circle(p,sqrt(norm(c.center-p)-c.r*c.r)));
}
//v
//二円の共通接線，Lineの2点は接点を表す
vector<Line> tangent(Circle c1,Circle c2){
    vector<Line> ret;
    if(c1.r<c2.r) swap(c1,c2);
    Real g=norm(c1.center-c2.center);
    if(eq(g,0)) return ret;
    Point u=(c2.center-c1.center)/sqrt(g);
    Point v=rotate(pi*0.5,u);
    for(int s:{-1,1}){
        Real h=(c1.r+s*c2.r)/sqrt(g);
        if(eq(1-h*h,0)){
            ret.push_back(Line(c1.center+u*c1.r,c1.center+(u+v)*c1.r));
        }
        else if(1-h*h>0){
            Point uu=u*h,vv=v*sqrt(1-h*h);
            ret.push_back(Line(c1.center+(uu+vv)*c1.r,c2.center-(uu+vv)*c2.r*s));
            ret.push_back(Line(c1.center+(uu-vv)*c1.r,c2.center-(uu-vv)*c2.r*s));
        }
    }
    return ret;
}
// Distance (Requires: Projection, Intersect)
Real dis(Point a,Point b){
    return abs(a-b);
}
Real dis(Line l,Point p){
    return abs(p-projection(l,p));
}
Real dis(Segment s,Point p){
    Point r=projection(s,p);
    if(intersect(s,r)) return abs(r-p);
    return min(abs(s.p1-p),abs(s.p2-p));
}
Real dis(Segment a,Segment b){
    if(intersect(a,b)) return 0;
    return min({dis(a,b.p1),dis(a,b.p2),dis(b,a.p1),dis(b,a.p2)});
}
Real dis(Polygon a,Polygon b){
    Real ret=-10;
    int n=(int)a.size(),m=(int)b.size();
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        Real d=dis(Segment(a[i],a[(i+1)%n]),Segment(b[j],b[(j+1)%m]));
        if(ret<0) ret=d;
        else      ret=min(ret,d);
    }
    return ret;
}
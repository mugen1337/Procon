// Projection (Requires: dot)
Point projection(Line l,Point p){
    // ベクトルl乗に点pからおろした垂線の足
    Real k=dot(l.p1-l.p2,p-l.p1)/norm(l.p1-l.p2);
    return l.p1+(l.p1-l.p2)*k;
}
Point projection(Segment l,Point p){
    Real k=dot(l.p1-l.p2,p-l.p1)/norm(l.p1-l.p2);
    return l.p1+(l.p1-l.p2)*k;
}
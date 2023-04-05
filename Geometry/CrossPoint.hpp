//intersectをチェックすること
//v
Point crosspoint(Line l,Line m){
   Real A=cross(m.p2-m.p1,m.p1-l.p1);
   Real B=cross(m.p2-m.p1,l.p2-l.p1);
   if(eq(A,0) and eq(B,0)) return l.p1;
   if(eq(B,0))             throw "NAI";
   return l.p1+A/B*(l.p2-l.p1);   
}
Point crosspoint(Segment l,Segment m){
   return crosspoint(Line(l),Line(m));
}
vector<Point> crosspoint(Circle c,Line l){
   vector<Point> ret;
   Point h=projection(l,c.center);
   Real d=sqrt(c.r*c.r-norm(h-c.center));
   Point e=(l.p2-l.p1)*(1/abs(l.p2-l.p1));
   if(c.r*c.r+EPS<norm(h-c.center)) return ret;
   if(eq(dis(l,c.center),c.r)){
       ret.push_back(h);
       return ret;
   }
   ret.push_back(h+e*d);ret.push_back(h-e*d);
   return ret;
}
//要verify，
vector<Point> crosspoint(Circle c,Segment s){
   Line l=Line(s.p1,s.p2);
   int ko=intersect(c,s);
   if(ko==2) return crosspoint(c,l);
   vector<Point> ret;
   if(ko==0) return ret;
   ret=crosspoint(c,l);
   if(ret.size()==1) return ret;
   vector<Point> rret;
   //交点で挟める方を返す
   if(dot(s.p1-ret[0],s.p2-ret[0])<0)  rret.push_back(ret[0]);
   else                                rret.push_back(ret[1]);
   return rret;
}
//v
vector<Point> crosspoint(Circle c1,Circle c2){
   vector<Point> ret;
   int isec=intersect(c1,c2);
   if(isec==0 or isec==4) return ret;
   Real d=abs(c1.center-c2.center);
   Real a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
   Real t=atan2(c2.center.imag()-c1.center.imag(),c2.center.real()-c1.center.real());
   ret.push_back(c1.center+Point(cos(t+a)*c1.r,sin(t+a)*c1.r));
   ret.push_back(c1.center+Point(cos(t-a)*c1.r,sin(t-a)*c1.r));
   return ret;
}
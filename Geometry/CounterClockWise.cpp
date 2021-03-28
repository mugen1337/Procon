// ccw (counter clockwise) (Requires: cross, dot)
//https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C
int ccw(Point a,Point b,Point c){
   b-=a;c-=a;
   if(cross(b,c)>EPS)       return  1;//COUNTER CLOCKWISE
   else if(cross(b,c)<-EPS) return -1;//CLOCKWISE
   else if(dot(b,c)<0)      return  2;//c--a--b ONLINE BACK
   else if(norm(b)<norm(c)) return -2;//a--b--c ONLINE FRONT
   else                     return  0;//a--c--b ON SEGMENT
}
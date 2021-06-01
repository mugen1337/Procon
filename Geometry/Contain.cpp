// out 0, on 1, in 2
int contains(Polygon poly,Point p){
    int res=0;
    int n=(int)poly.size();
    for(int i=0;i<n;i++){
        Point a=poly[i]-p,b=poly[(i+1)%n]-p;
        if(imag(a)>imag(b)) swap(a,b);
        if(imag(a)<=0 and 0<imag(b) and cross(a,b)<0) res^=1;
        if(eq(cross(a,b),0) and (dot(a,b)<0 or eq(dot(a,b),0))) return 1;
    }
    if(res) res=2;
    return res;
}

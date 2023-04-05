// 凸多角形系統
// 凸多角形の頂点は反時計周りに訪れる順序
// v
// 頂点は反時計周りに訪れる順序，時計回りとなるような3点があるとfalse
bool is_convex(const vector<Point> &ps){
    int n=(int)ps.size();
    for(int i=0;i<n;i++)if(ccw(ps[(i+n-1)%n],ps[i],ps[(i+1)%n])==-1)return false;
    return true;
}

// 凸包，あんまりよくわかってない．直線状に頂点をのせない場合(↑)，のせる場合(↓)
vector<Point> convex_hull(vector<Point> p){
    int n=(int)p.size(),k=0;
    if(n<=2)return p;
    sort(begin(p),end(p),[](Point a,Point b){
        return real(a)!=real(b)?real(a)<real(b):imag(a)<imag(b);
    });
    vector<Point>ch(2*n);
    for(int i=0;i<n;ch[k++]=p[i++]){
        // while(k>=2 and cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<EPS)k--;
        while(k>=2 and cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<0)k--;
    }
    for(int i=n-2,t=k+1;i>=0;ch[k++]=p[i--]){
        // while(k>=t and cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<EPS)k--;
        while(k>=t and cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<0)k--;
    }
    ch.resize(k-1);
    return ch;
}

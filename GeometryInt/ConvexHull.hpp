// v 整数で凸法
vector<P> convex_hull(vector<P> p){
    int n=(int)p.size(),k=0;
    if(n<=2)return p;
    sort(begin(p),end(p));
    vector<P> ch(2*n);
    auto crf=[&](P u,P v){return u.first*v.second-u.second*v.first;};
    auto dff=[&](P u,P v){return make_pair(u.first-v.first,u.second-v.second);};
    for(int i=0;i<n;ch[k++]=p[i++]){
        while(k>=2 and crf(dff(ch[k-1],ch[k-2]),dff(p[i],ch[k-1]))<0)k--;
        // while(k>=2 and crf(dff(ch[k-1],ch[k-2]),dff(p[i],ch[k-1]))<=0)k--;
    }
    for(int i=n-2,t=k+1;i>=0;ch[k++]=p[i--]){
        while(k>=t and crf(dff(ch[k-1],ch[k-2]),dff(p[i],ch[k-1]))<0)k--;
        // while(k>=t and crf(dff(ch[k-1],ch[k-2]),dff(p[i],ch[k-1]))<=0)k--;
    }
    ch.resize(k-1);
    return ch;
}
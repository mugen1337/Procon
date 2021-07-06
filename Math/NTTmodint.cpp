template<typename Mint>
struct NTTmodint{
    vector<Mint> dw,idw;
    int max_base,Mod;
    Mint root;
 
    NTTmodint():Mod(Mint::get_mod()){
        ll tmp=Mod-1;
        max_base=0;
        while(tmp%2==0) tmp>>=1,max_base++;
        root=2;
        while(root.pow((Mod-1)>>1).x==1) root+=1;
        dw.resize(max_base);idw.resize(max_base);
        for(int i=0;i<max_base;i++){
            dw[i]=-root.pow((Mod-1)>>(i+2));
            idw[i]=Mint(1)/dw[i];
        }
    }
    void ntt(vector<Mint> &a){
        int n=(int)a.size();
        for(int m=n;m>>=1;){
            Mint w=1;
            for(int s=0,k=0;s<n;s+=2*m){
                for(int i=s,j=s+m;i<s+m;i++,j++){
                    auto x=a[i],y=a[j]*w;
                    a[i]=x+y,a[j]=x-y;
                }
                w*=dw[__builtin_ctz(++k)];
            }
        }
    }
    void intt(vector<Mint> &a,bool f=true){
        int n=(int)a.size();
        for(int m=1;m<n;m*=2){
            Mint w=1;
            for(int s=0,k=0;s<n;s+=2*m){
                for(int i=s,j=s+m;i<s+m;i++,j++){
                    auto x=a[i],y=a[j];
                    a[i]=x+y,a[j]=(x-y)*w;
                }
                w*=idw[__builtin_ctz(++k)];
            }
        }
        if(f){
            Mint inv_sz=Mint(1)/n;
            for(int i=0;i<n;i++) a[i]*=inv_sz;
        }
    }
    vector<Mint> multiply(vector<Mint> a,vector<Mint> b){
        int need=(int)a.size()+b.size()-1;
        int nbase=1;
        while((1<<nbase)<need) nbase++;
        int sz=1<<nbase;
        a.resize(sz,0);b.resize(sz,0);
        ntt(a);ntt(b);
        Mint inv_sz=Mint(1)/sz;
        for(int i=0;i<sz;i++) a[i]*=b[i]*inv_sz;
        intt(a,false);
        a.resize(need);
        return a;
    }
};
template<typename T>
struct Matrix{
    vector<vector<T>> a;

    Matrix(){}
    Matrix(int n):a(n,vector<T>(n,0)){}
    Matrix(int h,int w):a(h,vector<T>(w,0)){}

    int h(){return (int)a.size();}
    int w(){return (int)a[0].size();}

    const vector<T> &operator[](int k)const{
        return a.at(k);// reference   
    }
    vector<T> &operator[](int k){
        return a.at(k);
    }

    Matrix id(int n){
        Matrix ret(n);
        for(int i=0;i<n;i++) ret[i][i]=1;
        return ret;
    }

    Matrix &operator+=(const Matrix &rhs){
        assert(h()==rhs.h() and w()==rhs.w());
        for(int i=0;i<h();i++)for(int j=0;j<w();j++) (*this)[i][j]+=rhs[i][j];
        return (*this);
    }
    Matrix &operator-=(const Matrix &rhs){
        assert(h()==rhs.h() and w()==rhs.w());
        for(int i=0;i<h();i++)for(int j=0;j<w();j++) (*this)[i][j]-=rhs[i][j];
        return (*this);
    }
    Matrix &operator*=(const Matrix &rhs){
        assert(w()==rhs.h());
        vector<vector<T>> res(h(),vector<T>(rhs.w()));
        for(int i=0;i<h();i++)for(int j=0;j<rhs.w();j++)for(int k=0;k<w();k++)
            res[i][j]=res[i][j]+(*this)[i][k]*rhs[k][j];
        swap(a,res);
        return (*this);
    }
    Matrix operator+(const Matrix &rhs)const{return Matrix(*this)+=rhs;}
    Matrix operator-(const Matrix &rhs)const{return Matrix(*this)-=rhs;}
    Matrix operator*(const Matrix &rhs)const{return Matrix(*this)*=rhs;}

    Matrix pow(long long k){
        Matrix ret=Matrix::id(h());
        Matrix b=Matrix(*this);
        while(k){
            if(k&1) ret*=(*this);
            b*=b;
            k>>=1;
        }
        return ret;
    }

    T det(){
        assert(h()==w());
        Matrix x(*this);
        T ret=1;
        for(int i=0;i<w();i++){
            int idx=-1;
            for(int j=i;j<w();j++)if(x[j][i]!=0) idx=j;
            if(idx==-1) return 0;// 三角行列の対角成分の1つが0
            if(i!=idx){
                ret*=-1;
                swap(x[i],x[idx]);
            }
            T b=x[i][i];
            ret*=b;
            for(int j=0;j<w();j++) x[i][j]/=b;
            for(int j=i+1;j<w();j++){
                T t=x[j][i];
                for(int k=0;k<w();k++) x[j][k]-=x[i][k]*t;
            }
        }
        return ret;
    }
};
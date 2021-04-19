template<typename T>
struct BinaryIndexedTree{
    vector<T> data;
    BinaryIndexedTree()=default;
    BinaryIndexedTree(int sz):data(sz+1,0){}
    BinaryIndexedTree(const vector<T> &a):data(a.size()+1,0){
        for(int i=0;i<(int)a.size();i++)data[i+1]=a[i];
        for(int i=1;i<(int)data.size();i++){
            int j=i+(i&-i);
            if(j<(int)data.size()) data[j]+=data[i];
        }
    }
    void add(int k,const T &x){for(++k;k<(int)data.size();k+=(k&-k)) data[k]+=x;}
    // sum [0,k)
    T sum(int k){
        T ret=T();
        for(;k>0;k-=(k&-k))ret+=data[k];
        return ret;
    }
    // sum [l,r)
    T query(int l,int r){
        return sum(r)-sum(l);
    }
    T operator[](const int &k){return query(k,k+1);}
    // sum[0,i)>=xとなる最小のi
    int lower_bound(T x){
        int r=1,i=0;
        while(r<(int)data.size())r<<=1;
        for(;r>0;r>>=1)if(i+r<(int)data.size() and data[i+r]<x){
            x-=data[i+r];i+=r;
        }
        return i+1;
    }
};
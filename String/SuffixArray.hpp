/*
https://ei1333.github.io/library/string/suffix-array.hpp
SA[i] := S[i ~ |S|)
*/
struct SuffixArray{
    vector<int> SA;
    const string s;

    SuffixArray(const string &s):s(s){
        SA.resize(s.size());
        iota(begin(SA),end(SA),0);
        sort(begin(SA),end(SA),[&](int i,int j){
            return s[i]==s[j]?i>j:s[i]<s[j];
        });
        vector<int> cl(s.size()),c(s.begin(),s.end()),cnt(s.size());
        for(int len=1;len<(int)s.size();len<<=1){
            for(int i=0;i<(int)s.size();i++){
                if(i>0 and c[SA[i-1]]==c[SA[i]] and SA[i-1]+len<(int)s.size() and c[SA[i-1]+len/2]==c[SA[i]+len/2])
                     cl[SA[i]]=cl[SA[i-1]];
                else cl[SA[i]]=i;
            }
            iota(begin(cnt),end(cnt),0);
            copy(begin(SA),end(SA),begin(c));
            for(int i=0;i<(int)s.size();i++){
                int tmp=c[i]-len;
                if(tmp>=0) SA[cnt[cl[tmp]]++]=tmp;
            }
            swap(c,cl);
        }
    }

    int operator[](int idx)const{ return SA[idx]; }

    int size()const{return (int)s.size();}

    bool lt_substr(const string &t,int si,int ti){
        int sn=(int)s.size(),tn=(int)t.size();
        while(si<sn and ti<tn){
            if(s[si]<t[ti]) return true;
            if(s[si]>t[ti]) return false;
            si++,ti++;
        }
        return si>=sn and ti<tn;
    }

    int lower_bound(const string &t){
        int lw=-1,hi=(int)SA.size();
        while(hi-lw>1){
            int mid=(lw+hi)/2;
            if(lt_substr(t,SA[mid],0)) lw=mid;
            else                       hi=mid;
        }
        return hi;
    }

    pair<int,int> lower_upper_bound(string &t){
        int lower=lower_bound(t);
        int lw=lower-1,hi=(int)SA.size();
        t.back()++;
        while(hi-lw>1){
            int mid=(lw+hi)/2;
            if(lt_substr(t,SA[mid],0)) lw=mid;
            else                       hi=mid; 
        }
        t.back()--;
        return {lower,hi};
    }

    // 未verify
    vector<int> LongestCommonPrefixArray(bool output=false){
        vector<int> rank(size()),LCP(size());
        for(int i=0;i<size();i++) rank[SA[i]]=i;
        for(int i=0,h=0;i<size();i++){
            if(rank[i]+1<size()){
                for(int j=SA[rank[i]+1];max(i,j)+h<size() and s[i+h]==s[j+h];++h) ;
                LCP[rank[i]+1]=h;
                if(h>0) h--;
            }
        }
        if(output){
            for(int i=0;i<size();i++) cout<<i<<" : lcp = "<<LCP[i]<<" : "<<s.substr(SA[i])<<endl;
        }
        return LCP;
    }

    void out(){
        for(int i=0;i<size();i++) cout<<i<<" : "<<s.substr(SA[i])<<endl;
    }
};
// 文字種aに対し，build O(na)
struct PalindromicTree{
    struct node{
        map<char,int> link;// link aba -> xabax
        int len,cnt,idx;// idx:この回文の1つの左端, RHなどのため
        int suffix_link;
        node(){}
        node(int len,int cnt,int idx,int suffix_link):len(len),cnt(cnt),idx(idx),suffix_link(suffix_link){}
    };

    vector<node> v;// 0:(-1), 1: (0)
    int n,ptr;

    PalindromicTree(){}
    PalindromicTree(const string &s):v(2),n(2),ptr(1){
        v[0]=node(-1,0,-1,0);v[1]=node(0,0,-1,0);
        for(int i=0;i<(int)s.size();i++) process(s,i);
        build_freq();
    }

    bool process(const string &s,int pos){
        int cur=ptr;// link parent
        while(true){
            int rev=pos-v[cur].len-1;
            if(rev>=0 and s[rev]==s[pos]) break;
            cur=v[cur].suffix_link;
        }
        if(v[cur].link.count(s[pos])){
            ptr=v[cur].link[s[pos]];
            v[ptr].cnt++;
            return false;
        }
        ptr=n++;

        v.emplace_back(v[cur].len+2,1,pos-v[cur].len-1,-1);
        v[cur].link[s[pos]]=ptr;// link
        if(v[ptr].len==1){
            v[ptr].suffix_link=1;
            return true;
        }

        while(true){
            cur=v[cur].suffix_link;
            int rev=pos-v[cur].len-1;
            if(rev>=0 and s[rev]==s[pos]){
                v[ptr].suffix_link=v[cur].link[s[pos]];
                break;
            }
        }
        return true;
    }
    // DAGをトポソ
    vector<int> calc_ord(){
        vector<int> ret;
        ret.emplace_back(0);
        ret.emplace_back(1);
        for(int i=0;i<(int)ret.size();i++)for(auto &p:v[ret[i]].link) ret.emplace_back(p.second);
        return ret;
    }
    void build_freq(){
        auto ord=calc_ord();
        // 一番長い回文にしかcnt+=1をしていないので，linkで集約する
        for(int i=(int)ord.size()-1;i>=0;i--) v[v[ord[i]].suffix_link].cnt+=v[ord[i]].cnt;
    }
    int count_unique(){return n-2;}
    int size(){return n;}
    node operator[](const int &k){return v[k];}
};
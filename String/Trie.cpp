template<int sz>
struct Trie{
private:
    struct Node{
        int nxt[sz],cnt;
        vector<int> accept;
        Node():cnt(0){memset(nxt,-1,sizeof(nxt));}
    };

    function<int(char)> conv;
    vector<Node> nodes;
    int root;

    void add(const string &s,int id,int s_idx=0,int node_idx=0){
        if(s_idx==(int)s.size()){
            nodes[node_idx].accept.push_back(id);
            return ;
        }
        int k=conv(s[s_idx]);
        if(nodes[node_idx].nxt[k]==-1){
            nodes[node_idx].nxt[k]=(int)nodes.size();
            nodes.push_back(Node());
        }
        add(s,id,s_idx+1,nodes[node_idx].nxt[k]);
        nodes[node_idx].cnt++;
    }
    void query(const string &s,const function<void(int)> &f,int s_idx,int node_idx){
        for(auto &idx:nodes[node_idx].accept)f(idx);
        if(s_idx==(int)s.size()) return ;
        else {
            int k=conv(s[s_idx]);
            if(nodes[node_idx].nxt[k]==-1) return;
            query(s,f,s_idx+1,nodes[node_idx].nxt[k]);
        }
    }

public:
 
    Trie(function<int(char)> conv):conv(conv),root(0){nodes.push_back(Node());}
    void add(const string &s,int idx=-1){
        if(idx<0) idx=count();
        add(s,idx,0,0);
    }
    // f(k) := 文字列のidxを通過するのでそれに対する処理, s[s_idx]から読み始める
    void query(const string &s,const function<void(int)> &f,int s_idx=0){ query(s,f,s_idx,0); }

    bool search(const string &s){
        int node_idx=0;
        for(int i=0;i<(int)s.size();i++){
            int k=conv(s[i]);
            if(nodes[node_idx].nxt[k]==-1) return false;
            node_idx=nodes[node_idx].nxt[k];
        }
        return !nodes[node_idx].empty();
    }
    int count(){
        return nodes[0].cnt;
    }
    int size(){
        return (int)nodes.size();
    }
};
// // converter, lower_case alphabet -> int
// int conv(char x){return x-'a';}
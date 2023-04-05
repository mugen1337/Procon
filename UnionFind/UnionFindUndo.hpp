// 経路圧縮なし，マージテクでunite，クエリ毎O(logN)
struct UnionFindUndo{
    int con;
    vector<int> data;
    stack<tuple<int,int,bool>> history;
    UnionFindUndo(int sz){
        con=sz;
        data.assign(sz,-1);
    }
    bool unite(int x,int y){
        x=root(x),y=root(y);
        
        if(x==y){
            history.push(make_tuple(x,data[x],false));
            history.push(make_tuple(y,data[y],false));
            return false;
        }
        con--;
        history.push(make_tuple(x,data[x],true));
        history.push(make_tuple(y,data[y],false));
        if(data[x]>data[y]) swap(x,y);
        data[x]+=data[y];
        data[y]=x;
        return true;
    }
    int root(int k){return (data[k]<0?k:(root(data[k])));}
    int size(int k){return (-data[root(k)]);}
    bool sameroot(int x,int y){return root(x)==root(y);}
    void undo(){
        {
            auto [fs,sc,con_flag]=history.top();history.pop();
            if(con_flag) con++;
            data[fs]=sc;
        }
        {
            auto [fs,sc,con_flag]=history.top();history.pop();
            if(con_flag) con++;
            data[fs]=sc;
        }
    }
    void snapshot(){while(!history.empty())history.pop();}
    void rollback(){while(!history.empty())undo();}
};
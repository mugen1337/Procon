/*
refs : https://beet-aizu.github.io/library/algorithm/mo.cpp
       https://ei1333.github.io/library/other/mo.cpp
*/
struct Mo{
    using F=function<void(int)>;
    int n,idx,ql,qr;
    vector<pair<int,int>> query;
    vector<int> ord;
    // [l,r) 
    // add_left  : l-1を足す, add_right : rを足す
    // erase_left: lを消す,  erase_right: r-1を消す
    F add_left,add_right,erase_left,erase_right;
 
    Mo(int n,F add_left,F add_right,F erase_left,F erase_right):
    n(n),idx(0),ql(0),qr(0),
    add_left(add_left),add_right(add_right),erase_left(erase_left),erase_right(erase_right)
    {}
 
    void add(int l,int r){
        query.emplace_back(l,r);
    }
 
    void build(){
        int q=(int)query.size();
        int bs=n/min(n,int(sqrt(q)));
        // 左端のブロックでソート
        // 左端のブロックが同じなら右端でソート
        ord.resize(q);
        iota(begin(ord),end(ord),0);
        sort(begin(ord),end(ord),[&](int a,int b){
            int al=query[a].first/bs,bl=query[b].first/bs;
            if(al!=bl) return al<bl;
            // 偶奇で始点を左右に振ると動きに無駄がない
            if(al&1) return query[a].second>query[b].second;
            return query[a].second<query[b].second;
        });
    }
 
    // 1個クエリを進め，処理したクエリのindexを返す
    // processが終わってから結果を格納すること
    // ans[process()]=res; はできない
    int process(){
        if(idx>=(int)ord.size()) return -1;
        int cur=ord[idx++];
        while(ql>query[cur].first)  add_left(--ql);
        while(qr<query[cur].second) add_right(qr++);
        while(ql<query[cur].first)  erase_left(ql++);
        while(qr>query[cur].second) erase_right(--qr);
        return cur;
    }
};
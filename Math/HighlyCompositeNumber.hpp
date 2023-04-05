/* 
N以下で最も約数の多い自然数
    ret : (Num, divs)

    10^18なら余裕で耐える．
    それ以上は未確認
*/
template<typename INT=ll>
pair<INT,INT> HighlyCompositeNumber(INT N, bool out=false){
    vector<INT> P={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,
                   71,73,79,83,89,97,101,103,107,109,113,127,131,137,139};
    using Tp=tuple<INT,INT,vector<INT>>;// number, divisor count, exp
    priority_queue<Tp,vector<Tp>,greater<Tp>> que;
    que.push(Tp(2,2,{1}));
    Tp res=Tp(2,2,1);

    while(not que.empty()){
        auto [num,divs,e]=que.top();que.pop();
        if(get<1>(res)<divs) res=Tp(num,divs,e);

        int m=(int)e.size();
        if(e[0]==1){
            INT new_num=num*P[m];
            if(new_num<=N){
                auto new_e=e;
                new_e.push_back(1);
                que.emplace(new_num,divs*2,new_e);
            }
        }

        int e0=e[0];
        for(int i=0;i<m;i++){
            if(e0>e[i]) break;
            num*=P[i];
            if(num>N) break;
            e[i]++;
            divs/=e0+1;
            divs*=e0+2;
            que.emplace(num,divs,e);
        }
    }
    if(out){
        auto [num, divs, e]=res;
        cout<<"HCN : "<<num<<"   ( <= "<<N<<" )"<<endl;
        cout<<num<<" = ";
        for(int i=0;i<(int)e.size();i++)
            cout<<P[i]<<"^"<<e[i]<<(i+1==(int)e.size()?"":" * ");
        cout<<endl;
        cout<<"divisor count : "<<divs<<endl;
        cout<<endl;
    }
    return make_pair(get<0>(res),get<1>(res));
}
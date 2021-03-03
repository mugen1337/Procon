#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include "../template.cpp"

#include "../Heap/LeftistHeap.cpp"


signed main(){
    LeftistHeap<int,false> que;

    string s;
    while(cin>>s,s!="end"){
        if(s=="insert"){
            int x;cin>>x;
            que.push(x);
        }else{
            cout<<que.pop()<<endl;
        }
    }
    return 0;
}


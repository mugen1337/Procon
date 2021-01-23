template<typename INT>
INT LargestRectangle(vector<INT> v){
    int n=(int)v.size();
    INT inf=numeric_limits<INT>::max()/2;
    stack<pair<INT,INT>> st;
    st.emplace(-inf,-1);// ばんぺいん
    INT ret=0;
    for(int i=0;i<n;i++){
        while(v[i]<st.top().first){
            auto p=st.top();st.pop();
            ret=max(ret,(i-st.top().second-1)*p.first);
        }
        st.emplace(v[i],i);
    }
    while(!st.empty()){
        auto p=st.top();st.pop();
        if(p.first==-inf) continue;
        ret=max(ret,(n-st.top().second-1)*p.first);
    }
    return ret;
}
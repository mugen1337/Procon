// ぐるっと外積とると打ち消されとかを考えて面積の２倍が手に入る
Int Area2(vector<P> poly){
    int N=(int)poly.size();
    Int S=0;
    for(int i=0;i<N;i++) S+=poly[i].first*poly[(i+1)%N].second-poly[i].second*poly[(i+1)%N].first;
    return S;
}
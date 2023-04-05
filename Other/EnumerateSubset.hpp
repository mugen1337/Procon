vector<int> enumerate_subset(int bit,bool include_bit_empty=false){
    vector<int> ret;
    int subset=(bit-1)&bit;
    do{
        ret.push_back(subset);
        subset=(subset-1)&bit;
    }while(subset!=0);
    if(include_bit_empty){
        ret.push_back(0);
        if(0!=bit) ret.push_back(bit);
    }
    return ret;
}
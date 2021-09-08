#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../template.cpp"

#include "../String/SuffixArray.cpp"

signed main(){
    string s;cin>>s;
    SuffixArray SA(s);
    rep(i,(int)s.size()) cout<<SA[i]<<(i+1==(int)s.size()?"\n":" ");

    SA.LongestCommonPrefixArray(true);
    return 0;
}
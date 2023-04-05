#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../template.hpp"

#include "../String/SuffixArray.hpp"

signed main(){
    string s;cin>>s;
    SuffixArray SA(s);
    rep(i,(int)s.size()) cout<<SA[i]<<(i+1==(int)s.size()?"\n":" ");
    return 0;
}
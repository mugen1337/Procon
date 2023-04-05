---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/HighlyCompositeNumber.hpp\"\n/* \nN\u4EE5\u4E0B\u3067\
    \u6700\u3082\u7D04\u6570\u306E\u591A\u3044\u81EA\u7136\u6570\n    ret : (Num,\
    \ divs)\n\n    10^18\u306A\u3089\u4F59\u88D5\u3067\u8010\u3048\u308B\uFF0E\n \
    \   \u305D\u308C\u4EE5\u4E0A\u306F\u672A\u78BA\u8A8D\n*/\ntemplate<typename INT=ll>\n\
    pair<INT,INT> HighlyCompositeNumber(INT N, bool out=false){\n    vector<INT> P={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,\n\
    \                   71,73,79,83,89,97,101,103,107,109,113,127,131,137,139};\n\
    \    using Tp=tuple<INT,INT,vector<INT>>;// number, divisor count, exp\n    priority_queue<Tp,vector<Tp>,greater<Tp>>\
    \ que;\n    que.push(Tp(2,2,{1}));\n    Tp res=Tp(2,2,1);\n\n    while(not que.empty()){\n\
    \        auto [num,divs,e]=que.top();que.pop();\n        if(get<1>(res)<divs)\
    \ res=Tp(num,divs,e);\n\n        int m=(int)e.size();\n        if(e[0]==1){\n\
    \            INT new_num=num*P[m];\n            if(new_num<=N){\n            \
    \    auto new_e=e;\n                new_e.push_back(1);\n                que.emplace(new_num,divs*2,new_e);\n\
    \            }\n        }\n\n        int e0=e[0];\n        for(int i=0;i<m;i++){\n\
    \            if(e0>e[i]) break;\n            num*=P[i];\n            if(num>N)\
    \ break;\n            e[i]++;\n            divs/=e0+1;\n            divs*=e0+2;\n\
    \            que.emplace(num,divs,e);\n        }\n    }\n    if(out){\n      \
    \  auto [num, divs, e]=res;\n        cout<<\"HCN : \"<<num<<\"   ( <= \"<<N<<\"\
    \ )\"<<endl;\n        cout<<num<<\" = \";\n        for(int i=0;i<(int)e.size();i++)\n\
    \            cout<<P[i]<<\"^\"<<e[i]<<(i+1==(int)e.size()?\"\":\" * \");\n   \
    \     cout<<endl;\n        cout<<\"divisor count : \"<<divs<<endl;\n        cout<<endl;\n\
    \    }\n    return make_pair(get<0>(res),get<1>(res));\n}\n"
  code: "/* \nN\u4EE5\u4E0B\u3067\u6700\u3082\u7D04\u6570\u306E\u591A\u3044\u81EA\u7136\
    \u6570\n    ret : (Num, divs)\n\n    10^18\u306A\u3089\u4F59\u88D5\u3067\u8010\
    \u3048\u308B\uFF0E\n    \u305D\u308C\u4EE5\u4E0A\u306F\u672A\u78BA\u8A8D\n*/\n\
    template<typename INT=ll>\npair<INT,INT> HighlyCompositeNumber(INT N, bool out=false){\n\
    \    vector<INT> P={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,\n  \
    \                 71,73,79,83,89,97,101,103,107,109,113,127,131,137,139};\n  \
    \  using Tp=tuple<INT,INT,vector<INT>>;// number, divisor count, exp\n    priority_queue<Tp,vector<Tp>,greater<Tp>>\
    \ que;\n    que.push(Tp(2,2,{1}));\n    Tp res=Tp(2,2,1);\n\n    while(not que.empty()){\n\
    \        auto [num,divs,e]=que.top();que.pop();\n        if(get<1>(res)<divs)\
    \ res=Tp(num,divs,e);\n\n        int m=(int)e.size();\n        if(e[0]==1){\n\
    \            INT new_num=num*P[m];\n            if(new_num<=N){\n            \
    \    auto new_e=e;\n                new_e.push_back(1);\n                que.emplace(new_num,divs*2,new_e);\n\
    \            }\n        }\n\n        int e0=e[0];\n        for(int i=0;i<m;i++){\n\
    \            if(e0>e[i]) break;\n            num*=P[i];\n            if(num>N)\
    \ break;\n            e[i]++;\n            divs/=e0+1;\n            divs*=e0+2;\n\
    \            que.emplace(num,divs,e);\n        }\n    }\n    if(out){\n      \
    \  auto [num, divs, e]=res;\n        cout<<\"HCN : \"<<num<<\"   ( <= \"<<N<<\"\
    \ )\"<<endl;\n        cout<<num<<\" = \";\n        for(int i=0;i<(int)e.size();i++)\n\
    \            cout<<P[i]<<\"^\"<<e[i]<<(i+1==(int)e.size()?\"\":\" * \");\n   \
    \     cout<<endl;\n        cout<<\"divisor count : \"<<divs<<endl;\n        cout<<endl;\n\
    \    }\n    return make_pair(get<0>(res),get<1>(res));\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/HighlyCompositeNumber.hpp
  requiredBy: []
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/HighlyCompositeNumber.hpp
layout: document
redirect_from:
- /library/Math/HighlyCompositeNumber.hpp
- /library/Math/HighlyCompositeNumber.hpp.html
title: Math/HighlyCompositeNumber.hpp
---

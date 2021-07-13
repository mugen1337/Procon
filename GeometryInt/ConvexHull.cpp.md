---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"GeometryInt/ConvexHull.cpp\"\n// v \u6574\u6570\u3067\u51F8\
    \u6CD5\nvector<P> convex_hull(vector<P> p){\n    int n=(int)p.size(),k=0;\n  \
    \  if(n<=2)return p;\n    sort(begin(p),end(p));\n    vector<P> ch(2*n);\n   \
    \ auto crf=[&](P u,P v){return u.first*v.second-u.second*v.first;};\n    auto\
    \ dff=[&](P u,P v){return make_pair(u.first-v.first,u.second-v.second);};\n  \
    \  for(int i=0;i<n;ch[k++]=p[i++]){\n        while(k>=2 and crf(dff(ch[k-1],ch[k-2]),dff(p[i],ch[k-1]))<0)k--;\n\
    \        // while(k>=2 and crf(dff(ch[k-1],ch[k-2]),dff(p[i],ch[k-1]))<=0)k--;\n\
    \    }\n    for(int i=n-2,t=k+1;i>=0;ch[k++]=p[i--]){\n        while(k>=t and\
    \ crf(dff(ch[k-1],ch[k-2]),dff(p[i],ch[k-1]))<0)k--;\n        // while(k>=t and\
    \ crf(dff(ch[k-1],ch[k-2]),dff(p[i],ch[k-1]))<=0)k--;\n    }\n    ch.resize(k-1);\n\
    \    return ch;\n}\n"
  code: "// v \u6574\u6570\u3067\u51F8\u6CD5\nvector<P> convex_hull(vector<P> p){\n\
    \    int n=(int)p.size(),k=0;\n    if(n<=2)return p;\n    sort(begin(p),end(p));\n\
    \    vector<P> ch(2*n);\n    auto crf=[&](P u,P v){return u.first*v.second-u.second*v.first;};\n\
    \    auto dff=[&](P u,P v){return make_pair(u.first-v.first,u.second-v.second);};\n\
    \    for(int i=0;i<n;ch[k++]=p[i++]){\n        while(k>=2 and crf(dff(ch[k-1],ch[k-2]),dff(p[i],ch[k-1]))<0)k--;\n\
    \        // while(k>=2 and crf(dff(ch[k-1],ch[k-2]),dff(p[i],ch[k-1]))<=0)k--;\n\
    \    }\n    for(int i=n-2,t=k+1;i>=0;ch[k++]=p[i--]){\n        while(k>=t and\
    \ crf(dff(ch[k-1],ch[k-2]),dff(p[i],ch[k-1]))<0)k--;\n        // while(k>=t and\
    \ crf(dff(ch[k-1],ch[k-2]),dff(p[i],ch[k-1]))<=0)k--;\n    }\n    ch.resize(k-1);\n\
    \    return ch;\n}"
  dependsOn: []
  isVerificationFile: false
  path: GeometryInt/ConvexHull.cpp
  requiredBy: []
  timestamp: '2021-07-13 22:36:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: GeometryInt/ConvexHull.cpp
layout: document
redirect_from:
- /library/GeometryInt/ConvexHull.cpp
- /library/GeometryInt/ConvexHull.cpp.html
title: GeometryInt/ConvexHull.cpp
---

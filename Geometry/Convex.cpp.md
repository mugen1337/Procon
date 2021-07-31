---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/include.cpp
    title: Geometry/include.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry/Convex.cpp\"\n// \u51F8\u591A\u89D2\u5F62\u7CFB\
    \u7D71\n// \u51F8\u591A\u89D2\u5F62\u306E\u9802\u70B9\u306F\u53CD\u6642\u8A08\u5468\
    \u308A\u306B\u8A2A\u308C\u308B\u9806\u5E8F\n// v\n// \u9802\u70B9\u306F\u53CD\u6642\
    \u8A08\u5468\u308A\u306B\u8A2A\u308C\u308B\u9806\u5E8F\uFF0C\u6642\u8A08\u56DE\
    \u308A\u3068\u306A\u308B\u3088\u3046\u306A3\u70B9\u304C\u3042\u308B\u3068false\n\
    bool is_convex(const vector<Point> &ps){\n    int n=(int)ps.size();\n    for(int\
    \ i=0;i<n;i++)if(ccw(ps[(i+n-1)%n],ps[i],ps[(i+1)%n])==-1)return false;\n    return\
    \ true;\n}\n\n// \u51F8\u5305\uFF0C\u3042\u3093\u307E\u308A\u3088\u304F\u308F\u304B\
    \u3063\u3066\u306A\u3044\uFF0E\u76F4\u7DDA\u72B6\u306B\u9802\u70B9\u3092\u306E\
    \u305B\u306A\u3044\u5834\u5408(\u2191)\uFF0C\u306E\u305B\u308B\u5834\u5408(\u2193\
    )\nvector<Point> convex_hull(vector<Point> p){\n    int n=(int)p.size(),k=0;\n\
    \    if(n<=2)return p;\n    sort(begin(p),end(p),[](Point a,Point b){\n      \
    \  return real(a)!=real(b)?real(a)<real(b):imag(a)<imag(b);\n    });\n    vector<Point>ch(2*n);\n\
    \    for(int i=0;i<n;ch[k++]=p[i++]){\n        // while(k>=2 and cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<EPS)k--;\n\
    \        while(k>=2 and cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<0)k--;\n    }\n  \
    \  for(int i=n-2,t=k+1;i>=0;ch[k++]=p[i--]){\n        // while(k>=t and cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<EPS)k--;\n\
    \        while(k>=t and cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<0)k--;\n    }\n  \
    \  ch.resize(k-1);\n    return ch;\n}\n"
  code: "// \u51F8\u591A\u89D2\u5F62\u7CFB\u7D71\n// \u51F8\u591A\u89D2\u5F62\u306E\
    \u9802\u70B9\u306F\u53CD\u6642\u8A08\u5468\u308A\u306B\u8A2A\u308C\u308B\u9806\
    \u5E8F\n// v\n// \u9802\u70B9\u306F\u53CD\u6642\u8A08\u5468\u308A\u306B\u8A2A\u308C\
    \u308B\u9806\u5E8F\uFF0C\u6642\u8A08\u56DE\u308A\u3068\u306A\u308B\u3088\u3046\
    \u306A3\u70B9\u304C\u3042\u308B\u3068false\nbool is_convex(const vector<Point>\
    \ &ps){\n    int n=(int)ps.size();\n    for(int i=0;i<n;i++)if(ccw(ps[(i+n-1)%n],ps[i],ps[(i+1)%n])==-1)return\
    \ false;\n    return true;\n}\n\n// \u51F8\u5305\uFF0C\u3042\u3093\u307E\u308A\
    \u3088\u304F\u308F\u304B\u3063\u3066\u306A\u3044\uFF0E\u76F4\u7DDA\u72B6\u306B\
    \u9802\u70B9\u3092\u306E\u305B\u306A\u3044\u5834\u5408(\u2191)\uFF0C\u306E\u305B\
    \u308B\u5834\u5408(\u2193)\nvector<Point> convex_hull(vector<Point> p){\n    int\
    \ n=(int)p.size(),k=0;\n    if(n<=2)return p;\n    sort(begin(p),end(p),[](Point\
    \ a,Point b){\n        return real(a)!=real(b)?real(a)<real(b):imag(a)<imag(b);\n\
    \    });\n    vector<Point>ch(2*n);\n    for(int i=0;i<n;ch[k++]=p[i++]){\n  \
    \      // while(k>=2 and cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<EPS)k--;\n      \
    \  while(k>=2 and cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<0)k--;\n    }\n    for(int\
    \ i=n-2,t=k+1;i>=0;ch[k++]=p[i--]){\n        // while(k>=t and cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<EPS)k--;\n\
    \        while(k>=t and cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<0)k--;\n    }\n  \
    \  ch.resize(k-1);\n    return ch;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Convex.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-08-01 02:48:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Convex.cpp
layout: document
redirect_from:
- /library/Geometry/Convex.cpp
- /library/Geometry/Convex.cpp.html
title: Geometry/Convex.cpp
---

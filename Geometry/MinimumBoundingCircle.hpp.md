---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/include.hpp
    title: Geometry/include.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry/MinimumBoundingCircle.hpp\"\n//\u6700\u5C0F\u5305\
    \u542B\u5186\u3092\u8FD4\u3059\u3000\u8A08\u7B97\u91CF\u306F\u671F\u5F85\u5024\
    O(n)\nCircle MinimumBoundingCircle(vector<Point> v){\n    int n=v.size();\n  \
    \  //\u30E9\u30F3\u30C0\u30E0\u30B7\u30E3\u30C3\u30D5\u30EB\uFF0E\u3044\u3062\u308F\
    \u308B\u3055\u308C\u305F\u304F\u306A\u3044\u3082\u3093\u3060\n    mt19937 mt(time(0));\n\
    \    shuffle(v.begin(),v.end(),mt);\n    Circle ret(0,0);\n\n    auto make_circle2=[&](Point\
    \ a,Point b){\n        return Circle((a+b)*0.5,dis(a,b)/2);\n    };\n\n    auto\
    \ make_circle3=[&](Point A,Point B,Point C){\n        Point cent=circumscribed_circle(A,B,C).center;\n\
    \        return Circle(cent,dis(cent,A));\n    };\n\n    auto isIn=[&](Point a){\n\
    \        return dis(ret.center,a)<ret.r+EPS;\n    };\n\n    ret=make_circle2(v[0],v[1]);\n\
    \    for(int i=2;i<n;i++){\n        //v[i]\u304C\u5186\u306B\u5165\u3063\u3066\
    \u3044\u306A\u3044\u306A\u3089\n        if(!isIn(v[i])){\n            //\u5186\
    \u5185\u306B\u306A\u3044\u306A\u3089\u70B9v[i]\u306F\u5FC5\u305A\u5186\u5468\u4E0A\
    \u306B\u6765\u308B\n            ret=make_circle2(v[0],v[i]);\n            for(int\
    \ j=1;j<i;j++){\n                if(!isIn(v[j])){\n                    //\u3053\
    \u306E\u6642i\u3068j\u304C\u5186\u5468\u4E0A\u3092\u8003\u3048\u308B\n       \
    \             ret=make_circle2(v[i],v[j]);\n                    //\u6700\u5F8C\
    \u306E1\u70B9\u306E\u6C7A\u5B9A\n                    for(int k=0;k<j;k++)if(!isIn(v[k]))\
    \ ret=make_circle3(v[i],v[j],v[k]);\n                }\n            }\n      \
    \  }\n    }\n    return ret;\n}\n"
  code: "//\u6700\u5C0F\u5305\u542B\u5186\u3092\u8FD4\u3059\u3000\u8A08\u7B97\u91CF\
    \u306F\u671F\u5F85\u5024O(n)\nCircle MinimumBoundingCircle(vector<Point> v){\n\
    \    int n=v.size();\n    //\u30E9\u30F3\u30C0\u30E0\u30B7\u30E3\u30C3\u30D5\u30EB\
    \uFF0E\u3044\u3062\u308F\u308B\u3055\u308C\u305F\u304F\u306A\u3044\u3082\u3093\
    \u3060\n    mt19937 mt(time(0));\n    shuffle(v.begin(),v.end(),mt);\n    Circle\
    \ ret(0,0);\n\n    auto make_circle2=[&](Point a,Point b){\n        return Circle((a+b)*0.5,dis(a,b)/2);\n\
    \    };\n\n    auto make_circle3=[&](Point A,Point B,Point C){\n        Point\
    \ cent=circumscribed_circle(A,B,C).center;\n        return Circle(cent,dis(cent,A));\n\
    \    };\n\n    auto isIn=[&](Point a){\n        return dis(ret.center,a)<ret.r+EPS;\n\
    \    };\n\n    ret=make_circle2(v[0],v[1]);\n    for(int i=2;i<n;i++){\n     \
    \   //v[i]\u304C\u5186\u306B\u5165\u3063\u3066\u3044\u306A\u3044\u306A\u3089\n\
    \        if(!isIn(v[i])){\n            //\u5186\u5185\u306B\u306A\u3044\u306A\u3089\
    \u70B9v[i]\u306F\u5FC5\u305A\u5186\u5468\u4E0A\u306B\u6765\u308B\n           \
    \ ret=make_circle2(v[0],v[i]);\n            for(int j=1;j<i;j++){\n          \
    \      if(!isIn(v[j])){\n                    //\u3053\u306E\u6642i\u3068j\u304C\
    \u5186\u5468\u4E0A\u3092\u8003\u3048\u308B\n                    ret=make_circle2(v[i],v[j]);\n\
    \                    //\u6700\u5F8C\u306E1\u70B9\u306E\u6C7A\u5B9A\n         \
    \           for(int k=0;k<j;k++)if(!isIn(v[k])) ret=make_circle3(v[i],v[j],v[k]);\n\
    \                }\n            }\n        }\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/MinimumBoundingCircle.hpp
  requiredBy:
  - Geometry/include.hpp
  timestamp: '2023-04-05 23:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/MinimumBoundingCircle.hpp
layout: document
redirect_from:
- /library/Geometry/MinimumBoundingCircle.hpp
- /library/Geometry/MinimumBoundingCircle.hpp.html
title: Geometry/MinimumBoundingCircle.hpp
---

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
  bundledCode: "#line 1 \"Geometry/ClosestPair.cpp\"\n// \u6700\u8FD1\u70B9\u5BFE\n\
    // O(NlogN)\nReal closest_pair(vector<Point> ps){\n    sort(ALL(ps),[&](Point\
    \ a,Point b){\n        return real(a)<real(b);\n    });\n    function<Real(int,int)>\
    \ rec=[&](int l,int r){\n        if(r-l<=1) return 1e18;\n        int m=(l+r)/2;\n\
    \        Real x=real(ps[m]);\n        Real ret=min(rec(l,m),rec(m,r));\n     \
    \   inplace_merge(begin(ps)+l,begin(ps)+m,begin(ps)+r,[&](Point a,Point b){\n\
    \            return imag(a)<imag(b);\n        });\n        // \u5206\u5272\u3092\
    \u8DE8\u3044\u3067\u6700\u5C0F\u8DDD\u96E2\u304C\u3042\u308B\u304B\u8ABF\u3079\
    \u308B\n        vector<Point> b;\n        for(int i=l;i<r;i++){\n            if(abs(real(ps[i])-x)>=ret)\
    \ continue;\n            for(int j=(int)b.size()-1;j>=0;j--){\n              \
    \  if(abs(imag(ps[i]-b[j]))>=ret) break;\n                ret=min(ret,abs(ps[i]-b[j]));\n\
    \            }\n            b.push_back(ps[i]);\n        }\n        return ret;\n\
    \    };\n    return rec(0,(int)ps.size());\n}\n"
  code: "// \u6700\u8FD1\u70B9\u5BFE\n// O(NlogN)\nReal closest_pair(vector<Point>\
    \ ps){\n    sort(ALL(ps),[&](Point a,Point b){\n        return real(a)<real(b);\n\
    \    });\n    function<Real(int,int)> rec=[&](int l,int r){\n        if(r-l<=1)\
    \ return 1e18;\n        int m=(l+r)/2;\n        Real x=real(ps[m]);\n        Real\
    \ ret=min(rec(l,m),rec(m,r));\n        inplace_merge(begin(ps)+l,begin(ps)+m,begin(ps)+r,[&](Point\
    \ a,Point b){\n            return imag(a)<imag(b);\n        });\n        // \u5206\
    \u5272\u3092\u8DE8\u3044\u3067\u6700\u5C0F\u8DDD\u96E2\u304C\u3042\u308B\u304B\
    \u8ABF\u3079\u308B\n        vector<Point> b;\n        for(int i=l;i<r;i++){\n\
    \            if(abs(real(ps[i])-x)>=ret) continue;\n            for(int j=(int)b.size()-1;j>=0;j--){\n\
    \                if(abs(imag(ps[i]-b[j]))>=ret) break;\n                ret=min(ret,abs(ps[i]-b[j]));\n\
    \            }\n            b.push_back(ps[i]);\n        }\n        return ret;\n\
    \    };\n    return rec(0,(int)ps.size());\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/ClosestPair.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-08-01 02:48:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/ClosestPair.cpp
layout: document
redirect_from:
- /library/Geometry/ClosestPair.cpp
- /library/Geometry/ClosestPair.cpp.html
title: Geometry/ClosestPair.cpp
---

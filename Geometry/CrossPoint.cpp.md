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
  bundledCode: "#line 1 \"Geometry/CrossPoint.cpp\"\n//intersect\u3092\u30C1\u30A7\
    \u30C3\u30AF\u3059\u308B\u3053\u3068\n//v\nPoint crosspoint(Line l,Line m){\n\
    \   Real A=cross(m.p2-m.p1,m.p1-l.p1);\n   Real B=cross(m.p2-m.p1,l.p2-l.p1);\n\
    \   if(eq(A,0) and eq(B,0)) return l.p1;\n   if(eq(B,0))             throw \"\
    NAI\";\n   return l.p1+A/B*(l.p2-l.p1);   \n}\nPoint crosspoint(Segment l,Segment\
    \ m){\n   return crosspoint(Line(l),Line(m));\n}\nvector<Point> crosspoint(Circle\
    \ c,Line l){\n   vector<Point> ret;\n   Point h=projection(l,c.center);\n   Real\
    \ d=sqrt(c.r*c.r-norm(h-c.center));\n   Point e=(l.p2-l.p1)*(1/abs(l.p2-l.p1));\n\
    \   if(c.r*c.r+EPS<norm(h-c.center)) return ret;\n   if(eq(dis(l,c.center),c.r)){\n\
    \       ret.push_back(h);\n       return ret;\n   }\n   ret.push_back(h+e*d);ret.push_back(h-e*d);\n\
    \   return ret;\n}\n//\u8981verify\uFF0C\nvector<Point> crosspoint(Circle c,Segment\
    \ s){\n   Line l=Line(s.p1,s.p2);\n   int ko=intersect(c,s);\n   if(ko==2) return\
    \ crosspoint(c,l);\n   vector<Point> ret;\n   if(ko==0) return ret;\n   ret=crosspoint(c,l);\n\
    \   if(ret.size()==1) return ret;\n   vector<Point> rret;\n   //\u4EA4\u70B9\u3067\
    \u631F\u3081\u308B\u65B9\u3092\u8FD4\u3059\n   if(dot(s.p1-ret[0],s.p2-ret[0])<0)\
    \  rret.push_back(ret[0]);\n   else                                rret.push_back(ret[1]);\n\
    \   return rret;\n}\n//v\nvector<Point> crosspoint(Circle c1,Circle c2){\n   vector<Point>\
    \ ret;\n   int isec=intersect(c1,c2);\n   if(isec==0 or isec==4) return ret;\n\
    \   Real d=abs(c1.center-c2.center);\n   Real a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));\n\
    \   Real t=atan2(c2.center.imag()-c1.center.imag(),c2.center.real()-c1.center.real());\n\
    \   ret.push_back(c1.center+Point(cos(t+a)*c1.r,sin(t+a)*c1.r));\n   ret.push_back(c1.center+Point(cos(t-a)*c1.r,sin(t-a)*c1.r));\n\
    \   return ret;\n}\n"
  code: "//intersect\u3092\u30C1\u30A7\u30C3\u30AF\u3059\u308B\u3053\u3068\n//v\n\
    Point crosspoint(Line l,Line m){\n   Real A=cross(m.p2-m.p1,m.p1-l.p1);\n   Real\
    \ B=cross(m.p2-m.p1,l.p2-l.p1);\n   if(eq(A,0) and eq(B,0)) return l.p1;\n   if(eq(B,0))\
    \             throw \"NAI\";\n   return l.p1+A/B*(l.p2-l.p1);   \n}\nPoint crosspoint(Segment\
    \ l,Segment m){\n   return crosspoint(Line(l),Line(m));\n}\nvector<Point> crosspoint(Circle\
    \ c,Line l){\n   vector<Point> ret;\n   Point h=projection(l,c.center);\n   Real\
    \ d=sqrt(c.r*c.r-norm(h-c.center));\n   Point e=(l.p2-l.p1)*(1/abs(l.p2-l.p1));\n\
    \   if(c.r*c.r+EPS<norm(h-c.center)) return ret;\n   if(eq(dis(l,c.center),c.r)){\n\
    \       ret.push_back(h);\n       return ret;\n   }\n   ret.push_back(h+e*d);ret.push_back(h-e*d);\n\
    \   return ret;\n}\n//\u8981verify\uFF0C\nvector<Point> crosspoint(Circle c,Segment\
    \ s){\n   Line l=Line(s.p1,s.p2);\n   int ko=intersect(c,s);\n   if(ko==2) return\
    \ crosspoint(c,l);\n   vector<Point> ret;\n   if(ko==0) return ret;\n   ret=crosspoint(c,l);\n\
    \   if(ret.size()==1) return ret;\n   vector<Point> rret;\n   //\u4EA4\u70B9\u3067\
    \u631F\u3081\u308B\u65B9\u3092\u8FD4\u3059\n   if(dot(s.p1-ret[0],s.p2-ret[0])<0)\
    \  rret.push_back(ret[0]);\n   else                                rret.push_back(ret[1]);\n\
    \   return rret;\n}\n//v\nvector<Point> crosspoint(Circle c1,Circle c2){\n   vector<Point>\
    \ ret;\n   int isec=intersect(c1,c2);\n   if(isec==0 or isec==4) return ret;\n\
    \   Real d=abs(c1.center-c2.center);\n   Real a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));\n\
    \   Real t=atan2(c2.center.imag()-c1.center.imag(),c2.center.real()-c1.center.real());\n\
    \   ret.push_back(c1.center+Point(cos(t+a)*c1.r,sin(t+a)*c1.r));\n   ret.push_back(c1.center+Point(cos(t-a)*c1.r,sin(t-a)*c1.r));\n\
    \   return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/CrossPoint.cpp
  requiredBy:
  - Geometry/include.cpp
  timestamp: '2021-05-23 14:57:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/CrossPoint.cpp
layout: document
redirect_from:
- /library/Geometry/CrossPoint.cpp
- /library/Geometry/CrossPoint.cpp.html
title: Geometry/CrossPoint.cpp
---

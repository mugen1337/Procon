---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../SegmentTree/SegmentTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../template.cpp\"\n\n#include \"../SegmentTree/SegmentTree.cpp\"\n\
    \nsigned main(){\n    int n,q;cin>>n>>q;\n\n    auto segfunc=[](ll a,ll b){\n\
    \        return a+b;\n    };\n    \n    SegmentTree<ll> seg(n,0,segfunc);\n  \
    \  rep(i,n){\n        ll a;cin>>a;\n        seg.set(i,a);\n    }\n    seg.build();\n\
    \n    for(;q--;){\n        int type;cin>>type;\n        if(type==0){\n       \
    \     int p;ll x;cin>>p>>x;\n            seg.update(p,seg.query(p,p+1)+x);\n \
    \       }\n        else{\n            int l,r;cin>>l>>r;\n            cout<<seg.query(l,r)<<endl;\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_Point-Add-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_Point-Add-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Point-Add-Range-Sum.test.cpp
- /verify/test/yosupo_Point-Add-Range-Sum.test.cpp.html
title: test/yosupo_Point-Add-Range-Sum.test.cpp
---

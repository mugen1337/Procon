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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../datastructure/RangeTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../template.cpp\"\n\n#include \"../datastructure/RangeTree.cpp\"\n\nsigned\
    \ main(){\n    int n,q;cin>>n>>q;\n    vector<tuple<int,int,ll>> v;\n    rep(i,n){\n\
    \        int x,y;ll w;cin>>x>>y>>w;\n        v.emplace_back(x,y,w);\n    }\n\n\
    \    RangeTree<int,int,ll> seg(v);\n\n\n    while(q--){\n        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;\n\
    \        cout<<seg.query(x1,y1,x2,y2)<<\"\\n\";\n    }\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_Rectangle_Sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_Rectangle_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Rectangle_Sum.test.cpp
- /verify/test/yosupo_Rectangle_Sum.test.cpp.html
title: test/yosupo_Rectangle_Sum.test.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../DP/LongestCommonSubstring.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n\n#include \"../template.cpp\"\n\n#include \"../DP/LongestCommonSubstring.cpp\"\
    \n\nvoid solve(){\n    string a,b;cin>>a>>b;\n    auto res=LongestCommonSubsecence(a,b);\n\
    \    // cout<<res<<endl;\n    cout<<res.size()<<endl;\n}\n\nsigned main(){\n \
    \   int q;cin>>q;\n    while(q--) solve();\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/AOJ_ALDS1_10_c.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ_ALDS1_10_c.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ_ALDS1_10_c.test.cpp
- /verify/test/AOJ_ALDS1_10_c.test.cpp.html
title: test/AOJ_ALDS1_10_c.test.cpp
---

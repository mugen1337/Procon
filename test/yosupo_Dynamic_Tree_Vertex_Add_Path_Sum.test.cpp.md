---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Graph2/LinkCutTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#include \"../template.cpp\"\n\n#include \"../Graph2/LinkCutTree.cpp\"\n\n\
    signed main(){\n    int n,q;cin>>n>>q;\n    vector<ll> v(n);\n    cin>>v;\n\n\
    \    LinkCutTree<ll> lct(v,[](ll a,ll b){return a+b;},0);\n\n    rep(i,n-1){\n\
    \        int u,v;cin>>u>>v;\n        lct.link(u,v);\n    }\n\n    while(q--){\n\
    \        int type;cin>>type;\n        if(type==0){\n            int a,b,c,d;cin>>a>>b>>c>>d;\n\
    \            lct.cut(a,b);\n            lct.link(c,d);\n        }else if(type==1){\n\
    \            int p;ll x;cin>>p>>x;\n            lct.update(p,lct.get(p)+x);\n\
    \        }else{\n            int u,v;cin>>u>>v;\n            cout<<lct.query(u,v)<<endl;\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
- /verify/test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp.html
title: test/yosupo_Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
---

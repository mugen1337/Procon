---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/graph/flow/primal-dual.hpp
  bundledCode: "#line 1 \"Flow/PrimalDual.cpp\"\n// https://ei1333.github.io/library/graph/flow/primal-dual.hpp\n\
    template<typename flow_t, typename cost_t>\nstruct PrimalDual{\n    struct edge{\n\
    \        int to;\n        flow_t cap;\n        cost_t cost;\n        int rev;//\u3053\
    \u306E\u8FBA\u306E\u9006\u8FBA\u304Cg[from]\u306E\u4F55\u756A\u76EE\u306B\u3042\
    \u308B\u304B\n        bool isrev;\n    };\n \n    vector<vector<edge>> graph;\n\
    \    vector<cost_t> potential,min_cost;\n    vector<int> prevv,preve;//\u70B9\uFF0C\
    \u8FBA\n    const cost_t TINF;\n \n    PrimalDual(int V):graph(V),TINF(numeric_limits<cost_t>::max()){}\n\
    \ \n    void add_edge(int from,int to,flow_t cap,cost_t cost){\n        graph[from].push_back((edge){to,cap,cost,(int)graph[to].size(),false});\n\
    \        graph[to].push_back((edge){from,0,-cost,(int)graph[from].size()-1,true});\n\
    \    }\n \n    cost_t min_cost_flow(int s,int t,flow_t f,bool &ok){\n        int\
    \ V=(int)graph.size();\n        cost_t ret=0;\n        using Pi=pair<cost_t,int>;\n\
    \        priority_queue<Pi,vector<Pi>,greater<Pi>> que;\n        potential.assign(V,0);\n\
    \        preve.assign(V,-1);\n        prevv.assign(V,-1);\n \n        while(f>0){\n\
    \            min_cost.assign(V,TINF);\n            que.emplace(0,s);\n       \
    \     min_cost[s]=0;\n            //dijkstra\u30D1\u30FC\u30C8\n            while(!que.empty()){\n\
    \                Pi p=que.top();que.pop();\n                if(min_cost[p.second]<p.first)\
    \ continue;\n                for(int i=0;i<(int)graph[p.second].size();i++){\n\
    \                    edge &e=graph[p.second][i];\n                    cost_t nextCost=min_cost[p.second]+e.cost+potential[p.second]-potential[e.to];\n\
    \                    if(e.cap>0 and min_cost[e.to]>nextCost){\n              \
    \          min_cost[e.to]=nextCost;\n                        prevv[e.to]=p.second,preve[e.to]=i;\n\
    \                        que.emplace(min_cost[e.to],e.to);\n                 \
    \   }\n                }\n            }\n            if(min_cost[t]==TINF){\n\
    \                ok=false;\n                return ret;\n            }\n     \
    \       // dijkstra\u306E\u7D50\u679C\u306B\u5FDC\u3058\u3066potential\u3092\u8ABF\
    \u7BC0\n            for(int v=0;v<V;v++)potential[v]+=min_cost[v];\n         \
    \   flow_t addflow=f;\n            for(int v=t;v!=s;v=prevv[v]){\n           \
    \     addflow=min(addflow,graph[prevv[v]][preve[v]].cap);\n            }\n   \
    \         f-=addflow;\n            ret+=addflow*potential[t];\n            for(int\
    \ v=t;v!=s;v=prevv[v]){\n                edge &e=graph[prevv[v]][preve[v]];\n\
    \                e.cap-=addflow;\n                graph[v][e.rev].cap+=addflow;\n\
    \            }\n        }\n        ok=true;\n        return ret;\n    }\n \n \
    \   void output(){\n        for(int i=0;i<graph.size();i++){\n            for(auto\
    \ &e:graph[i]){\n                if(e.isrev)continue;\n                auto &rev_e=graph[e.to][e.rev];\n\
    \                cout<<i<<\"->\"<<e.to<<\" (flow: \"<<rev_e.cap<<\" / \"<<rev_e.cap+e.cap<<\"\
    )\"<<endl;\n            }\n        }\n    }\n};\n"
  code: "// https://ei1333.github.io/library/graph/flow/primal-dual.hpp\ntemplate<typename\
    \ flow_t, typename cost_t>\nstruct PrimalDual{\n    struct edge{\n        int\
    \ to;\n        flow_t cap;\n        cost_t cost;\n        int rev;//\u3053\u306E\
    \u8FBA\u306E\u9006\u8FBA\u304Cg[from]\u306E\u4F55\u756A\u76EE\u306B\u3042\u308B\
    \u304B\n        bool isrev;\n    };\n \n    vector<vector<edge>> graph;\n    vector<cost_t>\
    \ potential,min_cost;\n    vector<int> prevv,preve;//\u70B9\uFF0C\u8FBA\n    const\
    \ cost_t TINF;\n \n    PrimalDual(int V):graph(V),TINF(numeric_limits<cost_t>::max()){}\n\
    \ \n    void add_edge(int from,int to,flow_t cap,cost_t cost){\n        graph[from].push_back((edge){to,cap,cost,(int)graph[to].size(),false});\n\
    \        graph[to].push_back((edge){from,0,-cost,(int)graph[from].size()-1,true});\n\
    \    }\n \n    cost_t min_cost_flow(int s,int t,flow_t f,bool &ok){\n        int\
    \ V=(int)graph.size();\n        cost_t ret=0;\n        using Pi=pair<cost_t,int>;\n\
    \        priority_queue<Pi,vector<Pi>,greater<Pi>> que;\n        potential.assign(V,0);\n\
    \        preve.assign(V,-1);\n        prevv.assign(V,-1);\n \n        while(f>0){\n\
    \            min_cost.assign(V,TINF);\n            que.emplace(0,s);\n       \
    \     min_cost[s]=0;\n            //dijkstra\u30D1\u30FC\u30C8\n            while(!que.empty()){\n\
    \                Pi p=que.top();que.pop();\n                if(min_cost[p.second]<p.first)\
    \ continue;\n                for(int i=0;i<(int)graph[p.second].size();i++){\n\
    \                    edge &e=graph[p.second][i];\n                    cost_t nextCost=min_cost[p.second]+e.cost+potential[p.second]-potential[e.to];\n\
    \                    if(e.cap>0 and min_cost[e.to]>nextCost){\n              \
    \          min_cost[e.to]=nextCost;\n                        prevv[e.to]=p.second,preve[e.to]=i;\n\
    \                        que.emplace(min_cost[e.to],e.to);\n                 \
    \   }\n                }\n            }\n            if(min_cost[t]==TINF){\n\
    \                ok=false;\n                return ret;\n            }\n     \
    \       // dijkstra\u306E\u7D50\u679C\u306B\u5FDC\u3058\u3066potential\u3092\u8ABF\
    \u7BC0\n            for(int v=0;v<V;v++)potential[v]+=min_cost[v];\n         \
    \   flow_t addflow=f;\n            for(int v=t;v!=s;v=prevv[v]){\n           \
    \     addflow=min(addflow,graph[prevv[v]][preve[v]].cap);\n            }\n   \
    \         f-=addflow;\n            ret+=addflow*potential[t];\n            for(int\
    \ v=t;v!=s;v=prevv[v]){\n                edge &e=graph[prevv[v]][preve[v]];\n\
    \                e.cap-=addflow;\n                graph[v][e.rev].cap+=addflow;\n\
    \            }\n        }\n        ok=true;\n        return ret;\n    }\n \n \
    \   void output(){\n        for(int i=0;i<graph.size();i++){\n            for(auto\
    \ &e:graph[i]){\n                if(e.isrev)continue;\n                auto &rev_e=graph[e.to][e.rev];\n\
    \                cout<<i<<\"->\"<<e.to<<\" (flow: \"<<rev_e.cap<<\" / \"<<rev_e.cap+e.cap<<\"\
    )\"<<endl;\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Flow/PrimalDual.cpp
  requiredBy: []
  timestamp: '2021-07-25 20:39:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Flow/PrimalDual.cpp
layout: document
redirect_from:
- /library/Flow/PrimalDual.cpp
- /library/Flow/PrimalDual.cpp.html
title: Flow/PrimalDual.cpp
---

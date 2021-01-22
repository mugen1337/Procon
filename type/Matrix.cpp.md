---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_det.test.cpp
    title: test/yosupo_det.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"type/Matrix.cpp\"\ntemplate<typename T>\nstruct Matrix{\n\
    \    vector<vector<T>> a;\n\n    Matrix(){}\n    Matrix(int n):a(n,vector<T>(n,0)){}\n\
    \    Matrix(int h,int w):a(h,vector<T>(w,0)){}\n\n    int h(){return (int)a.size();}\n\
    \    int w(){return (int)a[0].size();}\n\n    const vector<T> &operator[](int\
    \ k)const{\n        return a.at(k);// reference   \n    }\n    vector<T> &operator[](int\
    \ k){\n        return a.at(k);\n    }\n\n    Matrix id(int n){\n        Matrix\
    \ ret(n);\n        for(int i=0;i<n;i++) ret[i][i]=1;\n        return ret;\n  \
    \  }\n\n    Matrix &operator+=(const Matrix &rhs){\n        assert(h()==rhs.h()\
    \ and w()==rhs.w());\n        for(int i=0;i<h();i++)for(int j=0;j<w();j++) (*this)[i][j]+=rhs[i][j];\n\
    \        return (*this);\n    }\n    Matrix &operator-=(const Matrix &rhs){\n\
    \        assert(h()==rhs.h() and w()==rhs.w());\n        for(int i=0;i<h();i++)for(int\
    \ j=0;j<w();j++) (*this)[i][j]-=rhs[i][j];\n        return (*this);\n    }\n \
    \   Matrix &operator*=(const Matrix &rhs){\n        assert(w()==rhs.h());\n  \
    \      vector<vector<T>> res(h(),vector<T>(rhs.w()));\n        for(int i=0;i<h();i++)for(int\
    \ j=0;j<rhs.w();j++)for(int k=0;k<w();k++)\n            res[i][j]=res[i][j]+(*this)[i][k]*rhs[k][j];\n\
    \        swap(a,res);\n        return (*this);\n    }\n    Matrix operator+(const\
    \ Matrix &rhs)const{return Matrix(*this)+=rhs;}\n    Matrix operator-(const Matrix\
    \ &rhs)const{return Matrix(*this)-=rhs;}\n    Matrix operator*(const Matrix &rhs)const{return\
    \ Matrix(*this)*=rhs;}\n\n    Matrix pow(long long k){\n        Matrix ret=Matrix::id(h());\n\
    \        Matrix b=Matrix(*this);\n        while(k){\n            if(k&1) ret*=(*this);\n\
    \            b*=b;\n            k>>=1;\n        }\n        return ret;\n    }\n\
    \n    T det(){\n        assert(h()==w());\n        Matrix x(*this);\n        T\
    \ ret=1;\n        for(int i=0;i<w();i++){\n            int idx=-1;\n         \
    \   for(int j=i;j<w();j++)if(x[j][i]!=0) idx=j;\n            if(idx==-1) return\
    \ 0;// \u4E09\u89D2\u884C\u5217\u306E\u5BFE\u89D2\u6210\u5206\u306E1\u3064\u304C\
    0\n            if(i!=idx){\n                ret*=-1;\n                swap(x[i],x[idx]);\n\
    \            }\n            T b=x[i][i];\n            ret*=b;\n            for(int\
    \ j=0;j<w();j++) x[i][j]/=b;\n            for(int j=i+1;j<w();j++){\n        \
    \        T t=x[j][i];\n                for(int k=0;k<w();k++) x[j][k]-=x[i][k]*t;\n\
    \            }\n        }\n        return ret;\n    }\n};\n"
  code: "template<typename T>\nstruct Matrix{\n    vector<vector<T>> a;\n\n    Matrix(){}\n\
    \    Matrix(int n):a(n,vector<T>(n,0)){}\n    Matrix(int h,int w):a(h,vector<T>(w,0)){}\n\
    \n    int h(){return (int)a.size();}\n    int w(){return (int)a[0].size();}\n\n\
    \    const vector<T> &operator[](int k)const{\n        return a.at(k);// reference\
    \   \n    }\n    vector<T> &operator[](int k){\n        return a.at(k);\n    }\n\
    \n    Matrix id(int n){\n        Matrix ret(n);\n        for(int i=0;i<n;i++)\
    \ ret[i][i]=1;\n        return ret;\n    }\n\n    Matrix &operator+=(const Matrix\
    \ &rhs){\n        assert(h()==rhs.h() and w()==rhs.w());\n        for(int i=0;i<h();i++)for(int\
    \ j=0;j<w();j++) (*this)[i][j]+=rhs[i][j];\n        return (*this);\n    }\n \
    \   Matrix &operator-=(const Matrix &rhs){\n        assert(h()==rhs.h() and w()==rhs.w());\n\
    \        for(int i=0;i<h();i++)for(int j=0;j<w();j++) (*this)[i][j]-=rhs[i][j];\n\
    \        return (*this);\n    }\n    Matrix &operator*=(const Matrix &rhs){\n\
    \        assert(w()==rhs.h());\n        vector<vector<T>> res(h(),vector<T>(rhs.w()));\n\
    \        for(int i=0;i<h();i++)for(int j=0;j<rhs.w();j++)for(int k=0;k<w();k++)\n\
    \            res[i][j]=res[i][j]+(*this)[i][k]*rhs[k][j];\n        swap(a,res);\n\
    \        return (*this);\n    }\n    Matrix operator+(const Matrix &rhs)const{return\
    \ Matrix(*this)+=rhs;}\n    Matrix operator-(const Matrix &rhs)const{return Matrix(*this)-=rhs;}\n\
    \    Matrix operator*(const Matrix &rhs)const{return Matrix(*this)*=rhs;}\n\n\
    \    Matrix pow(long long k){\n        Matrix ret=Matrix::id(h());\n        Matrix\
    \ b=Matrix(*this);\n        while(k){\n            if(k&1) ret*=(*this);\n   \
    \         b*=b;\n            k>>=1;\n        }\n        return ret;\n    }\n\n\
    \    T det(){\n        assert(h()==w());\n        Matrix x(*this);\n        T\
    \ ret=1;\n        for(int i=0;i<w();i++){\n            int idx=-1;\n         \
    \   for(int j=i;j<w();j++)if(x[j][i]!=0) idx=j;\n            if(idx==-1) return\
    \ 0;// \u4E09\u89D2\u884C\u5217\u306E\u5BFE\u89D2\u6210\u5206\u306E1\u3064\u304C\
    0\n            if(i!=idx){\n                ret*=-1;\n                swap(x[i],x[idx]);\n\
    \            }\n            T b=x[i][i];\n            ret*=b;\n            for(int\
    \ j=0;j<w();j++) x[i][j]/=b;\n            for(int j=i+1;j<w();j++){\n        \
    \        T t=x[j][i];\n                for(int k=0;k<w();k++) x[j][k]-=x[i][k]*t;\n\
    \            }\n        }\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: type/Matrix.cpp
  requiredBy: []
  timestamp: '2021-01-06 01:27:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_det.test.cpp
documentation_of: type/Matrix.cpp
layout: document
redirect_from:
- /library/type/Matrix.cpp
- /library/type/Matrix.cpp.html
title: type/Matrix.cpp
---

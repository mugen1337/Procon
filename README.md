# mugen1337 Library  

https://atcoder.jp/users/mugen1337  
https://codeforces.com/profile/mugen1337  

[![Actions Status](https://github.com/mugen1337/procon/workflows/verify/badge.svg)](https://github.com/mugen1337/procon/actions)  
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://mugen1337.github.io/procon/)  

## 環境

- WSL
- VSCode
- (clangd)

## 提出・コンテストでの活用

workディレクトリでコンテスト向けに作業することを想定

### compile

```sh
g++ a.cpp -I ../
```
### oj-bundle

`bundle-clip.sh a.cpp` ようにすると、ライブラリ展開し、クリップボードへ貯める

```sh
pip3 install online-judge-verify-helper
```
### bashrc

追記  
2個目は wsl から clip.exe 触るため

```sh
export PATH="/home/{userName}/.local/bin:$PATH"
export PATH="/mnt/c/Windows/System32:$PATH"
```

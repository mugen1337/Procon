---
title: Slope
documentation_of: //DataStructure/Slope.cpp
---

## 概要  
- add_all(a) : f(x) <- f(x) + a
- add_x_minus_a(a, cnt) : f(x) <- f(x) + max(x-a, 0) * cnt
- add_a_minus_x(a, cnt) : f(x) <- f(x) + max(a-x, 0) * cnt
- add_abs(a, cnt) : f(x) <- f(x) + |x-a| * cnt
- clear_left : f(x) <- min{y>=x} f(y) (右から累積minに相当)
- clear_right : f(x) <- min{y<=x} f(y) (左から累積minに相当)
- shift(a, b) : f(x) <- min{x-b <= y <= x-a} f(y)
- shift(a) : f(x) <- f(x-a)
- operator(a) : f(a)
- min : min{x} f(x)
- argmin : min を与えるxの左端，右端をペアで返す

## 計算量  
operator(a)はO(N)なので注意

## ref  
https://yukicoder.me/submissions/644671  
https://ei1333.github.io/library/structure/others/slope-queue.cpp  
https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8  

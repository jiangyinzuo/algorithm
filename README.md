# Algorithm

Codes and documentations for algorithms.

POJ, lintcode, 洛谷, 牛客, 计蒜客, leetcode, hduoj

https://oi-wiki.org/

## Development Environment

### 牛客网

- OpenJDK 1.8
- clang++11(-std=c++11 -O2)
- clang-11 (-std=c11 -O2)
- Go 1.14
- Python3.9 (不支持numpy, scipy)
- Rust 1.44

### LeetCode

C++
```
版本：clang 17 采用最新 C++ 23 标准，并使用 GCC 13 提供的 libstdc++。

编译时，将会采用 -O2 级优化，并提供 -gline-tables-only 参数。AddressSanitizer 也被开启来检测 out-of-bounds 和 use-after-free 错误。

为了使用方便，大部分标准库的头文件已经被自动导入。
```

Java
```
版本：OpenJDK 21。使用编译参数 --enable-preview --release 21

为了方便起见，大部分标准库的头文件已被导入。

包含 Pair 类: https://docs.oracle.com/javase/8/javafx/api/javafx/util/Pair.html
```

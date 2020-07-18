# C++

std::cin取消同步

```c++
std::cin.sync_with_stdio(false);
std::cin.tie(nullptr);
```

浮点数比较 可以取EPSILON = 1e-6
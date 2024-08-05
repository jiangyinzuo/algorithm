//
// Created by Jiang Yinzuo on 2020/12/3.
//

#include <cstdio>

/**
 * 树状数组
 * @tparam T 元素类型
 * @tparam N 数组长度
 */
template<typename T, std::size_t N>
class TreeArr {
private:
    T arr[N + 1]{}; // arr[i] 维护区间 (i - lowbit(i), i]

    /**
     * 获取二进制数最右边的1和后面的0组成的数
     * @example: low_bit(0b10010) == 0b10
     */
    int low_bit(int x) {
        return x & -x;
    }

    int get_father(int idx) {
        return idx + low_bit(idx);
    }

    int prec(int idx) {
        return idx - low_bit(idx);
    }

public:
    using upd_fn_t = T(T, T);

    void update(int idx, upd_fn_t upd_fn, T val) {
        while (idx <= N) {
            arr[idx] = upd_fn(arr[idx], val);
            idx = get_father(idx);
        }
    }

    using reduce_fn_t = T(T, T);

    /**
     * 求arr[1] reduce_fn arr[2] reduce_fn a[3] ... reduce_fn a[idx]
     */
    T reduce(int idx, reduce_fn_t reduce_fn) {
        T result = T{};
        while (idx > 0) {
            result = reduce_fn(result, arr[idx]);
            idx = this->prec(idx);
        }
        return result;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    TreeArr<int, 32000> tree_arr{};
    int ans[32000]{};
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d %*d", &x);
        ans[tree_arr.reduce(x + 1, [](auto a, auto b) { return a + b; })]++;
        tree_arr.update(x + 1, [](auto a, auto b) { return a + b; }, 1);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
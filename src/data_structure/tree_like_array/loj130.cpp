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
struct TreeArr {
    T arr[N + 1]; // arr[i] 维护区间 (i - lowbit(i), i]

    /**
     * 获取二进制数最右边的1和后面的0组成的数
     * @example: low_bit(0b10010) == 0b10
     */
    static int low_bit(int x) {
        return x & -x;
    }

    static int get_father(int idx) {
        return idx + low_bit(idx);
    }

    static int prec(int idx) {
        return idx - low_bit(idx);
    }

    using upd_fn_t = T(T, T);

    TreeArr() = default;

    explicit TreeArr(T init_value) {
        for (int i = 0; i <= N; ++i) {
            this->arr[i] = init_value;
        }
    }

    void init(T a[N + 1], upd_fn_t upd_fn) {
        for (int i = 1; i <= N; ++i) {
            this->arr[i] = upd_fn(this->arr[i], a[i]);
            int father = TreeArr<T, N>::get_father(i);
            if (father <= N) {
                this->arr[father] = upd_fn(this->arr[father], this->arr[i]);
            }
        }
    }

    /**
     * 单点修改
     */
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

    using reverse_fn_t = T(T, T);

    /**
     * 区间查询[l, r]
     * @param l
     * @param r
     * @param reduce_fn
     * @param reverse_fn
     * @return 查询结果
     */
    T query_range(int l, int r, reduce_fn_t reduce_fn, reverse_fn_t reverse_fn) {
        return reverse_fn(this->reduce(r, reduce_fn), this->reduce(l - 1, reduce_fn));
    }
};

constexpr size_t MAX_N = 1000000;
long long ARR[MAX_N + 1];
TreeArr<long long, MAX_N> TREE_ARR{};

int main() {
    auto add_fn = [](auto x, auto y) { return x + y; };
    auto minus_fn = [](auto x, auto y) { return x - y; };

    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &ARR[i]);
    }
    TREE_ARR.init(ARR, add_fn);

    for (int i = 0; i < q; ++i) {
        int op, l, r;
        long long val;
        scanf("%d", &op);
        switch (op) {
            case 1:
                scanf("%d %lld", &l, &val);
                TREE_ARR.update(l, add_fn, val);
                break;
            case 2:
                scanf("%d %d", &l, &r);
                printf("%lld\n", TREE_ARR.query_range(l, r, add_fn, minus_fn));
                break;
            default:
                break;
        }
    }
    return 0;
}
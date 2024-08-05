//
// Created by Jiang Yinzuo on 2020/12/12.
//
#include <cstdio>
#include <cstring>

template<typename T>
struct Matrix {
    int n;
    T **mat;
    explicit Matrix(int n) : n(n), mat(new T*[n]) {
        for (int i = 0; i < n; ++i) {
            mat[i] = new T[n];
        }
    }
    ~Matrix() {
        for (int i = 0; i < n; ++i) {
            delete []mat[i];
        }
        delete[] mat;
    }
    Matrix operator*(const Matrix &m) {
        Matrix<T> res(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res.mat[i][j] = 0;
                for (int k = 0; k < n; ++k) {
                    res.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return res;
    }
    Matrix operator%=(T mod) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] %= mod;
            }
        }
        return *this;
    }
    Matrix pow(T idx) {
        Matrix<T> ans(n);
        memset(ans, 0, sizeof(ans));
        Matrix<T> base(n);
        for (int i = 0; i < n; ++i) {
            ans.mat[i][i] = 1;
        }
        while (idx) {
            if (idx & 1) {
                ans = ans * base;
            }
            base = base * base;
            idx >>= 1;
        }
        return ans;
    }
    Matrix pow(T idx, T mod) {
        Matrix<T> ans(this->n);
        Matrix<T> base = *this;
        for (int i = 0; i < n; ++i) {
            ans.mat[i][i] = 1;
        }
        while (idx) {
            if (idx & 1) {
                ans = ans * base;
                ans %= mod;
            }
            base = base * base;
            base %= mod;
            idx >>= 1;
        }
        return ans;
    }
};

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    Matrix<int> base(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &base.mat[i][j]);
        }
    }
    auto ans = base.pow(k, 1000000007);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", ans.mat[i][j]);
        }
        puts("");
    }
    return 0;
}
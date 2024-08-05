def A(c, n):
    ans = c-2*n
    for i in range(c-3*n + 1, c-2*n):
        ans = ans * i % 1000000007
    return ans
def f(c, n): return A(c, n)*pow(6, n, 1000000007) % 1000000007

n, c = map(int, input().split())
print(f(c, n))
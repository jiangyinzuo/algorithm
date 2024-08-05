#include <iostream>

using namespace std;
const long long p = 1e9 + 7;

long long f[20000001], g, inv[20000001];

int main(int argc, const char *argv[]) {
    inv[1] = 500000004;
    f[1] = 500000004;
    g = 4;
    for (int i = 2; i <= 20000000; i++) {
        inv[i] = inv[i - 1] * inv[1] % p;
        f[i] = f[i - 1] * (g - 1) % p * inv[i] % p;
        g = (g << 1) % p;
    }
    for (int i = 1; i <= 20000000; i++) {
        f[i] = f[i - 1] ^ f[i];
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}
public class FastPow {
    static int fastPow(int base, int index, int mod) {
        int ans = 1;
        int _base = base % mod;
        while (index > 0) {
            if ((index & 1) == 1) {
                ans = (ans * _base) % mod;
            }
            _base = (_base * _base) % mod;
            index >>= 1;
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println(fastPow(2, 0, 5));
        System.out.println(fastPow(4, 1, 7));
        System.out.println(fastPow(4, 5, 7));
    }
}
public class Sieve {
    static boolean[] isPrime = new boolean[101];

    static void sieve(int maxNumber) {
        for (int i = 0; i <= maxNumber; ++i) {
            isPrime[i] = true;
        }

        for (int i = 2; i <= maxNumber; ++i) {
            if (isPrime[i]) {
                for (int j = i * 2; j <= maxNumber; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    public static void main(String[] args) {
        sieve(100);
        for (int i = 2; i <= 100; ++i) {
            if (isPrime[i]) {
                System.out.printf("%d ", i);
            }
            if (i % 10 == 0) {
                System.out.println();
            }
        }
    }
}
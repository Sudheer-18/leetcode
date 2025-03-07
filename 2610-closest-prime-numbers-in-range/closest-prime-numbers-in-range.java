class Solution {
    public void Sieve(boolean[] Primes) {
        Arrays.fill(Primes, true);
        Primes[0] = Primes[1] = false;
        for (int i = 2; i * i < Primes.length; i++) {
            if (Primes[i]) {
                for (int j = i * i; j < Primes.length; j += i) {
                    Primes[j] = false;
                }
            }
        }
    }

    public int[] closestPrimes(int left, int right) {
        boolean[] Primes = new boolean[right + 1];
        Sieve(Primes);
        int prev = -1, minDiff = Integer.MAX_VALUE;
        int[] ans = { -1, -1 };

        for (int i = left; i <= right; i++) {
            if (Primes[i]) {
                if (prev != -1 && i - prev < minDiff) {
                    minDiff = i - prev;
                    ans[0] = prev;
                    ans[1] = i;
                }
                prev = i;
            }
        }
        return ans;
    }
}

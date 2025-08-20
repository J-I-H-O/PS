package twoPointer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj1644 {

    static int N;
    static boolean[] isPrime;

    static void filterPrimes() {
        for (int i = 2; i * i <= N; i++) {
            if (!isPrime[i]) continue;
            for (int j = 2; i * j <= N; j++) {
                isPrime[i * j] = false;
            }
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        isPrime = new boolean[N + 1];
        for (int i = 2; i <= N; i++) {
            isPrime[i] = true;
        }

        filterPrimes();

        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= N; i++) {
            if (isPrime[i]) primes.add(i);
        }
        primes.add(0);  // 마지막 right까지 탐색하기 위함

        int ans = 0;
        int left = 0;
        int right = 0;
        int sum = primes.get(0);
        while (right < primes.size() - 1) {
            if (sum < N) {
                sum += primes.get(++right);
            } else if (sum > N) {
                sum -= primes.get(left++);
            } else {
                ans++;
                sum -= primes.get(left++);
                sum += primes.get(++right);
            }
        }
        System.out.println(ans);
    }
}

package math;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2581 {

    static boolean[] isPrime;

    static void eratosthenes() {
        // 2 ~ sqrt(n) 까지 배수 지우기
        for (int cur = 2; cur * cur < isPrime.length; cur++) {
            if (isPrime[cur]) {
                for (int mul = 2; cur * mul < isPrime.length; mul++) {
                    isPrime[cur * mul] = false;
                }
            }
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());

        // 초기엔 모두 소수로 가정
        isPrime = new boolean[N + 1];
        for (int i = 2; i < isPrime.length; i++) {
            isPrime[i] = true;
        }

        eratosthenes();

        int sum = 0;
        int min = 10001;
        for (int i = M; i <= N; i++) {
            if (isPrime[i]) {
                sum += i;
                min = Math.min(min, i);
            }
        }

        if (sum != 0) {
            System.out.println(sum);
            System.out.println(min);
        } else {
            System.out.println(-1);
        }
    }
}

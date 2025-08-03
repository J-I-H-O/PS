package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2023 {
    
    static int N;

    static boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // 더 최적화하고 싶다면, 첫 자리수의 시작점을 2, 3, 5, 7로 잡으면 됨
    static void backtracking(int num, int digit) {
        // 이전 자리수까지의 수가 모두 소수를 만족하며 목표한 자리수까지 도달한 경우
        if (digit == N) {
            System.out.println(num);
            return;
        }

        // 이전 자리수까지의 숫자가 소수가 아닌 경우는 더이상 고려하지 않음
        for (int i = 1; i < 10; i++) {
            int next = (num * 10) + i;
            if (isPrime(next)) {
                backtracking(next, digit + 1);
            }
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        backtracking(0, 0);
    }
}

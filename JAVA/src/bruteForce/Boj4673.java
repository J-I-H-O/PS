package bruteForce;

import java.io.IOException;

public class Boj4673 {

    static int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    public static void solution() throws IOException {
        int[] constructors = new int[10001];
        for (int i = 1; i <= 10000; i++) {
            int cur = i;
            while (true) {
                int next = cur + getDigitSum(cur);
                if (next > 10000) {
                    break;
                }
                constructors[next] = cur;
                cur = next;
            }
        }

        for (int i = 1; i <= 10000; i++) {
            if (constructors[i] == 0) {
                System.out.println(i);
            }
        }
    }
}

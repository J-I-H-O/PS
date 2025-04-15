package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1789 {

    /**
     * 1부터 i까지의 합이 sum을 넘어가는 순간, 넘어간 값 만큼의 수를 빼주면 됨. 즉, N의 최대값은 그 순간의 (i-1)
     */
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(br.readLine());

        long sum = 0;
        for (int i = 1; i <= N; i++) {
            sum += i;
            if (sum == N) {
                System.out.println(i);
                break;
            } else if (sum > N) {
                System.out.println(i - 1);
                break;
            }
        }
    }
}

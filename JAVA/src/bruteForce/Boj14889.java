package bruteForce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj14889 {

    static int N;
    static int[][] stats;
    static boolean[] selected;
    static int ans = Integer.MAX_VALUE;

    static void findAns() {
        int sum1 = 0;
        int sum2 = 0;
        for (int member1 = 0; member1 < N - 1; member1++) {
            for (int member2 = member1 + 1; member2 < N; member2++) {
                // 팀1
                if (selected[member1] && selected[member2]) {
                    sum1 += stats[member1][member2];
                    sum1 += stats[member2][member1];
                }
                // 팀2
                if (!selected[member1] && !selected[member2]) {
                    sum2 += stats[member1][member2];
                    sum2 += stats[member2][member1];
                }
            }
        }
        ans = Math.min(ans, Math.abs(sum1 - sum2));
    }

    static void combination(int cur, int cnt) {
        if (cnt == N / 2) {
            findAns();
            return;
        }

        for (int i = cur; i < N; i++) {
            selected[i] = true;
            combination(i + 1, cnt + 1);
            selected[i] = false;
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        stats = new int[N][N];
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                stats[i][j] = Integer.parseInt(input[j]);
            }
        }

        selected = new boolean[N];
        combination(0, 0);
        System.out.println(ans);
    }
}

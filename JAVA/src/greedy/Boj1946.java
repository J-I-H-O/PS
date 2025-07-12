package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Boj1946 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int TC = 0; TC < T; TC++) {
            int N = Integer.parseInt(br.readLine());
            int[][] score = new int[N][2];
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                score[i][0] = Integer.parseInt(input[0]);
                score[i][1] = Integer.parseInt(input[1]);
            }

            // 서류 점수로 지원자를 오름차순 정렬
            // => index가 높은 지원자는 앞선 지원자보다 서류 점수 등수가 낮은 지원자임.
            // => 따라서 면접 점수 등수가 앞선 모든 지원자보다 높은 경우에만 채용
            Arrays.sort(score, new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    return o1[0] - o2[0];
                }
            });

            int ans = 1;
            int topInterview = score[0][1];
            for (int cur = 1; cur < N; cur++) {
                int curInterview = score[cur][1];
                if (topInterview > curInterview) {
                    topInterview = curInterview;
                    ans++;
                }
            }
            System.out.println(ans);
        }
    }
}

package bruteForce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Boj14502 {

    static int N, M;
    static int ans;
    static int cnt;
    static int[][] map;
    static List<int[]> safePos = new ArrayList<>(); // 초기 상태에서 벽을 설치할 수 있는 공간의 좌표 저장
    static List<int[]> virusPos = new ArrayList<>(); // 초기 상태에서 바이러스의 좌표 저장
    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, 1, -1};

    public static void combination(int posIdx) {
        // 벽을 3개 모두 세운 경우, 안전 영역 크기 계산
        if (cnt == 3) {
            ans = Math.max(ans, cntSafe());
            return;
        }

        for (int i = posIdx; i < safePos.size(); i++) {
            cnt++;
            map[safePos.get(i)[0]][safePos.get(i)[1]] = 1;
            combination(i + 1);
            map[safePos.get(i)[0]][safePos.get(i)[1]] = 0;
            cnt--;
        }
    }

    public static int cntSafe() {
        // 바이러스 진행
        Queue<int[]> queue = new LinkedList<>(virusPos);
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int cr = cur[0];
            int cc = cur[1];

            for (int dir = 0; dir < 4; dir++) {
                int nr = cr + dr[dir];
                int nc = cc + dc[dir];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                if (map[nr][nc] != 0) continue;

                queue.add(new int[]{nr, nc});
                map[nr][nc] = 2;
            }
        }

        // 초기 상태로 초기화
        int curAns = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) curAns++;
                if (map[i][j] == 2) map[i][j] = 0;
            }
        }
        for (int[] virus : virusPos) {
            map[virus[0]][virus[1]] = 2;
        }
        return curAns;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        map = new int[N][M];
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(input[j]);
                if (map[i][j] == 0) safePos.add(new int[]{i, j});
                if (map[i][j] == 2) virusPos.add(new int[]{i, j});
            }
        }
        combination(0);
        System.out.println(ans);
    }
}

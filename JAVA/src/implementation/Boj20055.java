package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj20055 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        int[] durability = new int[N * 2];
        boolean[] robot = new boolean[N * 2];
        for (int i = 0; i < N * 2; i++) {
            durability[i] = Integer.parseInt(input[i]);
        }

        int loadIdx = 0;
        int brokenCnt = 0;
        for (int time = 1; brokenCnt < K; time++) {
            // 벨트를 직접 회전시키는 대신, 기준점을 회전시킴
            loadIdx = (N * 2 + loadIdx - 1) % (N * 2);
            int unloadIdx = (loadIdx + N - 1) % (N * 2);
            // 내리는 지점에 로봇이 존재하는 경우 제거
            robot[unloadIdx] = false;

            // 로봇 배치된 순서대로 이동. 이때 unload -> load 방향으로 역순으로 순회하면 로봇이 배치된 순서로 이동시킬 수 있음
            // 컨베이어의 위쪽에만 로봇이 존재할 수 있음. 따라서 N-1번만 순회
            for (int i = 0; i < N - 1; i++) {
                int curPos = (N * 2 + unloadIdx - i - 1) % (N * 2);
                int nextPos = (curPos + 1) % (N * 2);

                if (!robot[curPos]) continue;
                if (durability[nextPos] == 0 || robot[nextPos]) continue;

                robot[curPos] = false;
                robot[nextPos] = true;
                // 내리는 지점인 경우 로봇 제거
                if (nextPos == unloadIdx) robot[nextPos] = false;
                // 내구도가 0인 경우 표시
                if (--durability[nextPos] == 0) brokenCnt++;
            }

            // 로봇 추가
            if (!robot[loadIdx] && durability[loadIdx] > 0) {
                robot[loadIdx] = true;
                // 내구도가 0인 경우 표시
                if (--durability[loadIdx] == 0) brokenCnt++;
            }

            // 한 사이클이 끝났을 때 내구도가 없는 칸의 개수가 K개 이상인 경우 종료
            if (brokenCnt >= K) {
                System.out.println(time);
                break;
            }
        }
    }
}

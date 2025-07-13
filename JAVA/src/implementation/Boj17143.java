package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj17143 {

    static class Shark {
        int r;
        int c;
        int speed;
        int direction;  // 1: 위, 2: 아래, 3: 오, 4: 왼
        int size;

        public Shark(int r, int c, int speed, int direction, int size) {
            this.r = r;
            this.c = c;
            this.speed = speed;
            this.direction = direction;
            this.size = size;
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int R = Integer.parseInt(input[0]);
        int C = Integer.parseInt(input[1]);
        int M = Integer.parseInt(input[2]);

        Shark[] sharks = new Shark[M + 1];
        int[][] board = new int[R + 1][C + 1];  // 해당 칸에 위치한 상어 번호
        for (int sharkNum = 1; sharkNum <= M; sharkNum++) {
            input = br.readLine().split(" ");
            int r = Integer.parseInt(input[0]);
            int c = Integer.parseInt(input[1]);
            int speed = Integer.parseInt(input[2]);
            int direction = Integer.parseInt(input[3]);
            int size = Integer.parseInt(input[4]);

            sharks[sharkNum] = new Shark(r, c, speed, direction, size);
            board[r][c] = sharkNum;
        }

        int ans = 0;
        for (int curC = 1; curC <= C; curC++) {
            // 현재 열에 있는 가장 가까운 상어 찾아 낚기
            for (int curR = 1; curR <= R; curR++) {
                int sharkNumOnPos = board[curR][curC];
                // 해당 위치에 아직 잡히지 않은 상어가 존재하는 경우
                if (sharks[sharkNumOnPos] != null) {
                    board[sharks[sharkNumOnPos].r][sharks[sharkNumOnPos].c] = 0;
                    ans += sharks[sharkNumOnPos].size;
                    sharks[sharkNumOnPos] = null;
                    break;
                }
            }

            int[][] newBoard = new int[R + 1][C + 1];

            // 상어 이동
            for (int curSharkNum = 1; curSharkNum <= M; curSharkNum++) {
                Shark shark = sharks[curSharkNum];
                if (shark == null) continue;

                // 속력 최적화 => 이거 잘 이해 안됨...
                if (shark.direction == 1 || shark.direction == 2) {
                    shark.speed %= (R - 1) * 2;
                } else {
                    shark.speed %= (C - 1) * 2;
                }

                // 방향 전환 + 이동
                for (int i = 0; i < shark.speed; i++) {
                    if (shark.direction == 1 && shark.r == 1) shark.direction = 2;
                    if (shark.direction == 2 && shark.r == R) shark.direction = 1;
                    if (shark.direction == 3 && shark.c == C) shark.direction = 4;
                    if (shark.direction == 4 && shark.c == 1) shark.direction = 3;

                    if (shark.direction == 1) shark.r--;
                    if (shark.direction == 2) shark.r++;
                    if (shark.direction == 3) shark.c++;
                    if (shark.direction == 4) shark.c--;
                }

                // 이동 후 겹치는 상어 처리
                // 만약 실제 board를 사용했다면 이동한 상어가 아직 이동하지 않은 상어와 충돌한 것으로 잘못 판단할 수 있으므로
                // 새로운 board를 만들어 이동이 완료된 상어들 끼리만 충돌 처리를 하도록 구현
                if (newBoard[shark.r][shark.c] == 0) {
                    newBoard[shark.r][shark.c] = curSharkNum;
                } else {
                    int other = newBoard[shark.r][shark.c];
                    if (sharks[other].size < shark.size) {
                        sharks[other] = null;
                        newBoard[shark.r][shark.c] = curSharkNum;
                    } else {
                        sharks[curSharkNum] = null;
                    }
                }
            }
            board = newBoard;
        }
        System.out.println(ans);
    }
}

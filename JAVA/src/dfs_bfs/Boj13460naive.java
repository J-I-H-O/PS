package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj13460naive {

    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, 1, -1};
    static int N, M;
    static int ans = 11;

    static int[] move(int dir, int curR, int curC, char color, char[][] board) {
        int nextR = curR;
        int nextC = curC;
        while (true) {
            nextR += dr[dir];
            nextC += dc[dir];
            if (board[nextR][nextC] == 'O') {
                board[curR][curC] = '.';
                return null;    // 구멍에 들어간 경우를 표시하기 위함
            }
            if (board[nextR][nextC] != '.') {
                nextR -= dr[dir];
                nextC -= dc[dir];
                break;
            }
        }
        board[curR][curC] = '.';
        board[nextR][nextC] = color;

        return new int[]{nextR, nextC};
    }

    static void slide(int rRow, int rCol, int bRow, int bCol, int moveCnt, char[][] board) {
        if (moveCnt > 10) return;

        int[] nextRPos = null;
        int[] nextBPos = null;

        for (int dir = 0; dir < 4; dir++) {
            char[][] newBoard = new char[N][M];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    newBoard[i][j] = board[i][j];
                }
            }
            // 아래로 이동; 더 아래쪽에 있는 구슬 먼저 이동
            if (dir == 0) {
                if (rRow < bRow) {
                    nextBPos = move(dir, bRow, bCol, 'B', newBoard);
                    nextRPos = move(dir, rRow, rCol, 'R', newBoard);
                } else {
                    nextRPos = move(dir, rRow, rCol, 'R', newBoard);
                    nextBPos = move(dir, bRow, bCol, 'B', newBoard);
                }
            }
            // 위로 이동; 더 위쪽에 있는 구슬 먼저 이동
            if (dir == 1) {
                if (rRow > bRow) {
                    nextBPos = move(dir, bRow, bCol, 'B', newBoard);
                    nextRPos = move(dir, rRow, rCol, 'R', newBoard);
                } else {
                    nextRPos = move(dir, rRow, rCol, 'R', newBoard);
                    nextBPos = move(dir, bRow, bCol, 'B', newBoard);
                }
            }
            // 오른쪽으로 이동; 더 오른쪽에 있는 구슬 먼저 이동
            if (dir == 2) {
                if (rCol < bCol) {
                    nextBPos = move(dir, bRow, bCol, 'B', newBoard);
                    nextRPos = move(dir, rRow, rCol, 'R', newBoard);
                } else {
                    nextRPos = move(dir, rRow, rCol, 'R', newBoard);
                    nextBPos = move(dir, bRow, bCol, 'B', newBoard);
                }
            }
            // 왼쪽으로 이동; 더 왼쪽에 있는 구슬 먼저 이동
            if (dir == 3) {
                if (rCol > bCol) {
                    nextBPos = move(dir, bRow, bCol, 'B', newBoard);
                    nextRPos = move(dir, rRow, rCol, 'R', newBoard);
                } else {
                    nextRPos = move(dir, rRow, rCol, 'R', newBoard);
                    nextBPos = move(dir, bRow, bCol, 'B', newBoard);
                }
            }

            if (nextRPos == null && nextBPos != null) {
                ans = Math.min(ans, moveCnt);
            }
            if (nextRPos == null || nextBPos == null) continue; // 구멍에 공이 들어간 경우는 더이상 고려하지 않음

            slide(nextRPos[0], nextRPos[1], nextBPos[0], nextBPos[1], moveCnt + 1, newBoard);
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        int rRow = 0, rCol = 0, bRow = 0, bCol = 0;
        char[][] board = new char[N][M];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().toCharArray();
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 'R') {
                    rRow = i;
                    rCol = j;
                }
                if (board[i][j] == 'B') {
                    bRow = i;
                    bCol = j;
                }
            }
        }

        slide(rRow, rCol, bRow, bCol, 1, board);

        if (ans == 11) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
    }
}

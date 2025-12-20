package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class boj2239 {

    // 초기 보드에서 빈 칸의 좌표
    static List<int[]> positions = new ArrayList<>();

    public static void backtracking(int[][] board, int posNum) {
        int curR = positions.get(posNum)[0];
        int curC = positions.get(posNum)[1];

        // 현재 칸에 들어갈 수 없는 숫자 거르기
        boolean[] isAvailable = new boolean[10];
        Arrays.fill(isAvailable, true);

        for (int i = 0; i < 9; i++) {
            isAvailable[board[i][curC]] = false;    // 가로로 겹치는 숫자 제외
            isAvailable[board[curR][i]] = false;    // 세로로 겹치는 숫자 제외
        }
        for (int i = 3 * (curR / 3); i < 3 * (curR / 3) + 3; i++) {
            for (int j = 3 * (curC / 3); j < 3 * (curC / 3) + 3; j++) {
                isAvailable[board[i][j]] = false;    // 3*3 범위에 겹치는 숫자 제외
            }
        }

        for (int curNum = 1; curNum <= 9; curNum++) {
            if (!isAvailable[curNum]) continue;

            board[curR][curC] = curNum;

            // 마지막 칸 && 넣을 수 있는 수가 존재하는 경우 정답
            if (posNum == positions.size() - 1) {
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        System.out.print(board[i][j]);
                    }
                    System.out.println();
                }
                System.exit(0);
            }

            backtracking(board, posNum + 1);
            board[curR][curC] = 0;
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] board = new int[9][9];
        for (int i = 0; i < 9; i++) {
            char[] chars = br.readLine().toCharArray();
            for (int j = 0; j < 9; j++) {
                board[i][j] = chars[j] - '0';
                if (board[i][j] == 0) {
                    positions.add(new int[]{i, j});
                }
            }
        }

        backtracking(board, 0);
    }
}

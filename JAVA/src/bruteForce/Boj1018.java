package bruteForce;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj1018 {

    // 첫 번째 칸이 검은 색인 경우와 흰색인 경우로 나누어 둘 중 변경 횟수가 적은 값을 리턴
    public static int findMinCount(char[][] map, int startRow, int startCol, int endRow, int endCol) {
        char[][] correctLines = new char[][]{
                {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}
        };

        int currentCorrectLineIdx = 0;
        int count = 0;
        for (int row = startRow; row <= endRow; row++) {
            for (int col = startCol; col <= endCol; col++) {
                char correct = correctLines[currentCorrectLineIdx][col - startCol];
                char current = map[row][col];

                if (correct != current) {
                    count++;
                }
            }
            currentCorrectLineIdx = (currentCorrectLineIdx + 1) % 2;
        }
        return Math.min(count, 64 - count);
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();
        String[] inputSplit = input.split(" ");

        int n = Integer.parseInt(inputSplit[0]);
        int m = Integer.parseInt(inputSplit[1]);

        char[][] map = new char[n][m];
        for (int i = 0; i < n; i++) {
            input = br.readLine();
            char[] inputArray = input.toCharArray();
            map[i] = inputArray;
        }

        int ans = Integer.MAX_VALUE;
        // 가능한 모든 체스판의 경우의 수로 잘라보기
        for (int startRow = 0; startRow <= n - 8; startRow++) {       // 체스판 시작 지점의 row
            for (int startCol = 0; startCol <= m - 8; startCol++) {   // 체스판 시작 지점의 col
                int endRow = startRow + 7;
                int endCol = startCol + 7;
                ans = Math.min(ans, findMinCount(map, startRow, startCol, endRow, endCol));
            }
        }
        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
    }
}

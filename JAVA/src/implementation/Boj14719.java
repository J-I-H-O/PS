package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj14719 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int H = Integer.parseInt(input[0]);
        int W = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        int[] blocks = new int[W];
        for (int i = 0; i < W; i++) {
            blocks[i] = Integer.parseInt(input[i]);
        }

        // 각 열에 고이는 물의 높이 구하기. 현재 열은 자신보다 높은 블록에 둘러싸여 있을 때에만 물이 고임.
        // 이때 양쪽 끝 열에는 물이 고이지 않음
        int ans = 0;
        for (int i = 1; i < W - 1; i++) {
            int curBlock = blocks[i];
            // 현재 블록 보다 왼쪽에 위치한 블록 중 가장 높은 것
            int leftMax = 0;
            for (int j = i - 1; j >= 0; j--) {
                leftMax = Math.max(leftMax, blocks[j]);
            }
            // 현재 블록 보다 오른쪽에 위치한 블록 중 가장 높은 것
            int rightMax = 0;
            for (int j = i + 1; j < W; j++) {
                rightMax = Math.max(rightMax, blocks[j]);
            }

            // 현재 열에는 leftMax와 rightMax 중 더 작은 것과 현재 블록의 차 만큼의 물이 고임
            // 이때 leftMax와 rightMax 둘 중 하나라도 현재 블록보다 크지 않다면 물이 고이지 않음
            if (leftMax > curBlock && rightMax > curBlock) {
                ans += Math.min(leftMax, rightMax) - curBlock;
            }
        }
        System.out.println(ans);
    }
}

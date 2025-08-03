package twoPointer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Boj2470 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] solutions = new int[N];

        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            solutions[i] = Integer.parseInt(input[i]);
        }

        Arrays.sort(solutions);

        int left = 0, ansLeft = 0;
        int right = N - 1, ansRight = N - 1;
        while (left < right) {
            int sum = solutions[left] + solutions[right];
            if (Math.abs(sum) < Math.abs(solutions[ansLeft] + solutions[ansRight])) {
                ansLeft = left;
                ansRight = right;
            }
            /**
             * (sum < 0) 인 경우, 고정된 right에 대해 left를 오른쪽으로 옮기는 경우가 절댓값을 줄일 수 있는 유일한 방향
             * (sum > 0) 인 경우, 고정된 left에 대해 right를 왼쪽으로 옮기는 경우가 절댓값을 줄일 수 있는 유일한 방향
             */
            if (sum < 0) left++;
            else right--;
        }
        System.out.println(solutions[ansLeft] + " " + solutions[ansRight]);
    }
}

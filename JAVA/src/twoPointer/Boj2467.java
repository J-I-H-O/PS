package twoPointer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2467 {

    /**
     * 투 포인터
     * 합이 0보다 큰 경우, left를 오른쪽으로 옮김 => 합을 줄임
     * 합이 0보다 작은 경우, right를 왼쪽으로 옮김 => 합을 키움
     * => 항상 더 나아질 가능성이 있는 경우만 확인함
     */
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] solutions = new int[N];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            solutions[i] = Integer.parseInt(input[i]);
        }

        int left = 0;
        int right = N - 1;
        int ansLeft = left;
        int ansRight = right;
        int ansSum = Integer.MAX_VALUE;
        while (left < right) {
            int curSum = solutions[left] + solutions[right];
            if (Math.abs(curSum) < Math.abs(ansSum)) {
                ansLeft = left;
                ansRight = right;
                ansSum = curSum;
            }
            if (curSum < 0) left++;
            else right--;
        }
        System.out.println(solutions[ansLeft] + " " + solutions[ansRight]);
    }
}

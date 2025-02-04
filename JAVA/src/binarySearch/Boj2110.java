package binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Boj2110 {

    // naive : N개 중 C 개의 집 선택(조합), 그 중 가장 인접한 두 공유기 사이의 거리가 가장 큰 것이 정답
    // -> 최대 200000개 중 C개를 선택해야 하므로 시간 복잡도는 2^200000 (불가능)
    // 파라메트릭 서치 : 공유기를 설치할 수 있는 두 집 사이의 최소 거리를 기준으로 이분탐색
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int C = Integer.parseInt(input[1]);

        int[] houses = new int[N];
        for (int i = 0; i < N; i++) {
            houses[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(houses);

        int left = 1;
        int right = houses[N - 1] + 1;
        while (left < right) {
            // 공유기를 설치할 수 있는 집 사이의 최소 거리
            int mid = (left + right) / 2;

            // mid 만큼의 거리를 두고 몇 개의 집에 공유기를 설치할 수 있는지 판별
            int installCnt = 1;
            int lastInstallIdx = 0;
            for (int curIdx = 1; curIdx < N; curIdx++) {
                if (houses[curIdx] - houses[lastInstallIdx] >= mid) {
                    installCnt++;
                    lastInstallIdx = curIdx;
                }
            }

            if (installCnt < C) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        System.out.println(left - 1);
    }
}

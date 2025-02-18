package math;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2460 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int ans = 0;
        int curPeopleCnt = 0;
        for (int i = 0; i < 10; i++) {
            String[] input = br.readLine().split(" ");
            int subCnt = Integer.parseInt(input[0]);
            int addCnt = Integer.parseInt(input[1]);

            curPeopleCnt -= subCnt;
            curPeopleCnt += addCnt;

            ans = Math.max(ans, curPeopleCnt);
        }
        System.out.println(ans);
    }
}

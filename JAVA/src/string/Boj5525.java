package string;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj5525 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        String input = br.readLine() + " ";

        int ans = 0;
        int patternMatchCnt = 0;
        for (int initial = 0; initial < M - 2; ) {
            if (input.charAt(initial) == 'I' && input.charAt(initial + 1) == 'O' && input.charAt(initial + 2) == 'I') {
                patternMatchCnt++;
                if (patternMatchCnt == N) {
                    ans++;
                    patternMatchCnt--;
                }
                initial += 2;
            } else {
                patternMatchCnt = 0;
                initial++;
            }
        }
        System.out.println(ans);
    }
}

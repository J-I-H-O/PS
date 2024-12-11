package bruteForce;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj1065 {

    public static boolean isHansu(int num) {
        char[] digits = String.valueOf(num).toCharArray();
        for (int i = 0; i < digits.length - 2; i++) {
            if (digits[i] - digits[i + 1] != digits[i + 1] - digits[i + 2]) {
                return false;
            }
        }
        return true;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int ans;
        if (n < 100) {
            ans = n;
        } else {
            ans = 99;
        }

        for (int i = 100; i <= n; i++) {
            if (isHansu(i)) {
                ans++;
            }
        }

        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
        br.close();
    }
}

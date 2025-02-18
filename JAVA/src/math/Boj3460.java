package math;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj3460 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int TC = 0; TC < T; TC++) {
            int n = Integer.parseInt(br.readLine());
            List<Integer> binary = new ArrayList<>();
            while (n > 0) {
                binary.add(n % 2);
                n /= 2;
            }

            for (int i = 0; i < binary.size(); i++) {
                if (binary.get(i) == 1) {
                    System.out.print(i + " ");
                }
            }
        }
    }
}

package math;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj2501 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        List<Integer> factors = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            if (N % i == 0) {
                factors.add(i);
            }
        }

        if (factors.size() < K) {
            System.out.println(0);
        } else {
            System.out.println(factors.get(K - 1));
        }
    }
}

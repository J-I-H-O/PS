package sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Boj2693 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int TC = 0; TC < T; TC++) {
            List<Integer> list = Arrays.stream(br.readLine().split(" "))
                    .map(Integer::parseInt)
                    .sorted()
                    .collect(Collectors.toList());
            System.out.println(list.get(list.size() - 3));
        }
    }
}

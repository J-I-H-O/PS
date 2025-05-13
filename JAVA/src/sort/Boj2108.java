package sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Boj2108 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        List<Integer> nums = new ArrayList<>();
        Map<Integer, Integer> frequency = new HashMap<>();
        double sum = 0;
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(br.readLine());
            nums.add(num);
            frequency.merge(num, 1, Integer::sum);
            sum += num;
        }
        Collections.sort(nums);

        int maxFrequency = Collections.max(frequency.values());
        List<Integer> frequentNums = new ArrayList<>();
        frequency.entrySet().stream()
                .filter(entry -> entry.getValue() == maxFrequency)
                .forEach(entry -> frequentNums.add(entry.getKey()));
        Collections.sort(frequentNums);

        System.out.println(Math.round(sum / N));
        System.out.println(nums.get(N / 2));
        System.out.println(frequentNums.size() >= 2 ? frequentNums.get(1) : frequentNums.get(0));
        System.out.println(Math.abs(nums.get(0) - nums.get(nums.size() - 1)));
    }
}

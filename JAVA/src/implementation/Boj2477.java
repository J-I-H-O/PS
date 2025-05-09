package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj2477 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int K = Integer.parseInt(br.readLine());

        int maxVerticalIdx = 0;
        int maxVerticalLen = 0;
        int maxHorizonLen = 0;
        List<Integer> lines = new ArrayList<>();
        for (int i = 0; i < 6; i++) {
            String[] input = br.readLine().split(" ");
            int dir = Integer.parseInt(input[0]);
            int len = Integer.parseInt(input[1]);

            if (dir == 3 || dir == 4) {
                if (maxVerticalLen < len) {
                    maxVerticalLen = len;
                    maxVerticalIdx = i;
                }
            } else {
                maxHorizonLen = Math.max(maxHorizonLen, len);
            }

            lines.add(len);
        }

        int blankArea = 0;
        int nextToMaxVerticalIdx = (maxVerticalIdx + 1) % 6;
        if (lines.get(nextToMaxVerticalIdx) == maxHorizonLen) {
            blankArea = lines.get((maxVerticalIdx + 3) % 6) * lines.get((maxVerticalIdx + 4) % 6);
        } else {
            blankArea = lines.get((maxVerticalIdx + 2) % 6) * lines.get((maxVerticalIdx + 3) % 6);
        }
        System.out.println((maxVerticalLen * maxHorizonLen - blankArea) * K);
    }
}

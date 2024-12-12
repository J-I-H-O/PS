package dataStructure;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Boj1764 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        List<String> ans = new ArrayList<>();
        Map<String, Boolean> listen = new HashMap();
        for (int i = 0; i < n; i++) {
            listen.put(br.readLine(), true);
        }
        for (int i = 0; i < m; i++) {
            String current = br.readLine();
            if (listen.getOrDefault(current, false)) {
                ans.add(current);
            }
        }

        Collections.sort(ans);
        bw.write(ans.size() + "\n");
        for (String name : ans) {
            bw.write(name + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}

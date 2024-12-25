package dataStructure;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj16120_Timeout {

    public static String replace(String str) {
        String replaced = str.replace("PPAP", "P");
        if (replaced.equals(str)) {
            return replaced;
        }
        return replace(replaced);
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String ans = "NP";
        String input = br.readLine();
        String replaced = replace(input);

        if ("P".equals(replaced)) {
            ans = "PPAP";
        }

        bw.write(ans);
        bw.flush();
        bw.close();
        br.close();
    }
}

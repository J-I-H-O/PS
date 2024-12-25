package dataStructure;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj16120 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < input.length(); i++) {
            sb.append(input.charAt(i));
            int length = sb.length();
            if (length >= 4) {
                if (sb.charAt(length - 4) == 'P' && sb.charAt(length - 3) == 'P'
                        && sb.charAt(length - 2) == 'A' && sb.charAt(length - 1) == 'P') {
                    sb.replace(length - 4, length, "P");
                }
            }
        }

        String ans = "NP";
        if (sb.toString().equals("P")) {
            ans = "PPAP";
        }

        bw.write(ans);
        bw.flush();
        bw.close();
        br.close();
    }
}

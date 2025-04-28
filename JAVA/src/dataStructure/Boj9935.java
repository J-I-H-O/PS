package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj9935 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] string = br.readLine().toCharArray();
        char[] bomb = br.readLine().toCharArray();

        List<Character> list = new ArrayList<>();
        for (int i = 0; i < string.length; i++) {
            list.add(string[i]);
            if (list.size() >= bomb.length) {
                boolean isBombed = true;
                for (int j = 0; j < bomb.length; j++) {
                    if (list.get(list.size() - bomb.length + j) != bomb[j]) {
                        isBombed = false;
                        break;
                    }
                }
                if (isBombed) {
                    for (int j = 0; j < bomb.length; j++) {
                        list.remove(list.size() - 1);
                    }
                }
            }
        }

        if (list.isEmpty()) {
            System.out.println("FRULA");
        } else {
            StringBuilder sb = new StringBuilder();
            for (char ch : list) {
                sb.append(ch);
            }
            System.out.println(sb);
        }
    }
}

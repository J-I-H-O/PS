package recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2263 {

    static int[] inorder;
    static int[] postorder;

    public static void preorder(int inL, int inR, int postL, int postR) {
        if (postR < 0) return;
        if (inL > inR) return;

        // postorder의 마지막 노드가 현재 서브트리의 루트 노드
        // 루트 노드를 기준으로 inorder 좌우 분할
        int root = postorder[postR];
        int rootIdx = 0;
        for (int i = inL; i <= inR; i++) {
            if (inorder[i] == root) {
                rootIdx = i;
                break;
            }
        }

        int leftSize = rootIdx - inL;

        // preorder 이므로 현재 root를 먼저 출력
        System.out.print(root + " ");
        // postorderr 자를 땐 idx 기준이 아닌 크기 기준으로 잘라야 함
        preorder(inL, rootIdx - 1, postL, postL + leftSize - 1);
        preorder(rootIdx + 1, inR, postL + leftSize, postR - 1);
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        inorder = new int[n];
        postorder = new int[n];

        String[] input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            inorder[i] = Integer.parseInt(input[i]);
        }

        input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            postorder[i] = Integer.parseInt(input[i]);
        }

        preorder(0, n - 1, 0, n - 1);
    }
}

package dfs_bfs;

public class Pro43162 {

    public void dfs(int n, int[][] computers, boolean[] visited, int curComputer) {
        for (int i = 0; i < n; i++) {
            if (computers[curComputer][i] == 1 && !visited[i]) {
                visited[i] = true;
                dfs(n, computers, visited, i);
            }
        }
    }

    public int solution(int n, int[][] computers) {
        int ans = 0;
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                visited[i] = true;
                dfs(n, computers, visited, i);
            }
        }

        return ans;
    }
}

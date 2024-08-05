import java.util.Scanner;

class POJ2531 {
    private static int[][] network;
    private static int maxSum;
    private static int[] set;

    private static void dfs(int nodeId, int sum, int nodeCount) {
        if (nodeId == nodeCount + 1) {
            if (sum > maxSum) {
                maxSum = sum;
            }
            return;
        }
        
        
        for (int i = 1; i >= 0; --i) {
            int tempSum = sum;
            set[nodeId] = i;
            if (i == 1) {
                for (int j = 1; j <= nodeCount; ++j) {
                    if (set[j] == 1) {
                        tempSum -= network[nodeId][j];
                    } else {
                        tempSum += network[nodeId][j];
                    }
                }
            }
            dfs(nodeId+1, tempSum, nodeCount);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int nodeCount = scanner.nextInt();
        network = new int[nodeCount+1][nodeCount+1];
        set = new int[nodeCount+1];

        for (int i = 1; i <= nodeCount; ++i) {
            for (int j = 1; j <= nodeCount; ++j) {
                network[i][j] = scanner.nextInt();
            }
        }
        scanner.close();

        dfs(1, 0, nodeCount);
        System.out.println(maxSum);
    }
}
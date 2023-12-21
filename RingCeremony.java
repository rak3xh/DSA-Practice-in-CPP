import java.util.*;

public class RingCeremony {

    public static int[] ringCeremony(int N, int Q, int[] arr, int[][] queries) {
        int[] result = new int[Q];

        for (int i = 0; i < Q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];

            // Check if r - l - k is present in the given range
            if (r - l - k >= 0 && r - l - k <= r - l) {
                if (arr[r - l - k + l] == (3 - l - k)) {
                    // Geek wins
                    result[i] = 1;
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        // Example
        int N = 5;
        int Q = 2;
        int[] arr = { -2, 3, 1, 2, 0 };
        int[][] queries = { { 0, 3, 0 }, { 0, 3, 4 } };

        int[] result = ringCeremony(N, Q, arr, queries);

        // Print the result
        for (int res : result) {
            System.out.print(res + " ");
        }
    }
}

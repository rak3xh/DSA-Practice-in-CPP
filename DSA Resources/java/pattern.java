import java.util.Scanner;

public class pattern {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of lines: ");
        int n = scanner.nextInt();

        // har line ke liye loop
        for (int i = 0; i < n; ++i) {
            // space print karane ke liye
            for (int j = 0; j < n - i - 1; ++j) {
                System.out.print(" ");
            }
            // pehla wala triangle jo ki ascending mei hai
            for (char ch = 'A'; ch <= 'A' + i; ++ch) {
                System.out.print(ch);
            }
            // second wala triangle jo ki descending mei hai
            for (char ch = (char) ('A' + i - 1); ch >= 'A'; --ch) {
                System.out.print(ch);
            }
            // next line jaane ke liye
            System.out.println();
        }

        scanner.close();
    }
}

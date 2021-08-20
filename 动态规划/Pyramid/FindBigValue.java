import java.lang.Math;
import java.util.Scanner;

public class FindBigValue {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();   //行数

        long max = 0;
        int[] dp   = new int[n + 2];
        int[] temp = new int[n + 2];

        temp[1] = in.nextInt();
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= i+1 ; j++) {
                int num = in.nextInt();
                dp[j] = Math.max(temp[j - 1], temp[j]) + num;
                max = Math.max(dp[j], max);
            }
            System.arraycopy(dp, 0, temp, 0, n+2);
        }
        System.out.println(max);
    }
}
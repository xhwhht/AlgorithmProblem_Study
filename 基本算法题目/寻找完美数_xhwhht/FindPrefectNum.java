package Problem02;

import java.util.Scanner;

public class FindPrefectNum {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);


        int  M, pref, FinSum;

        int[] sum = new int[2];

        M = cin.nextInt();                      //输入测试的组数
        int[] res = new int[M];

        for(int i = 0; i < M; i++) {
            String inputX = cin.next();
            String inputY = cin.next();

            sum[0] = num(inputX);            //输入区间

            sum[1] = num(inputY);
            pref = prefect(inputY);

            FinSum = sum[1] - sum[0] + pref;
            res[i] = FinSum;
        }

        for (int i = 0; i < M; i++) {
            System.out.println(res[i]);
        }


    }

    // 1 到（ X or Y ）之间的完美数个数

    public static int num(String str)
    {
        int sum;
        String[] str1 = str.split("");
        int n = str1.length;
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(str1[i]);      //使用Integer.parseInt()将分开的字符串转为整数
        }
        sum = (n-1) * 9 + a[0] - 1;
        return sum;
    }

    // 端点是否为完美数

    public static int prefect(String str)
    {

        String[] str1 = str.split("");
        if (str1.length == 1) {
            return 1;
        }

        for (int i = 1; i < str1.length; i++) {

            if(!str1[i].equals(str1[0])) {
                return 0 ;
            }
        }
        return 1;
    }
}

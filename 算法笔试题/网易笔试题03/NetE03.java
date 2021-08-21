package Problem01;

import java.util.Scanner;

public class NetE03 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();		             //以字符串形式读入数据（空格隔开，也可换成','等字符隔开）

        String[] str = s.split(" ");	         //使用split函数将字符串分割成字符串数组
        int n = 0;
        for (String data : str) {		              //增强for循环获得个数
            n++;
        }

        int[] a = new int[n];			              //定义int数组
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(str[i]);          //使用Integer.parseInt()将分开的字符串转为整数
        }

        //正文
        int sum=0;
        int[] b = new int[n];
        b[0]=1;

        for (int i = 1; i <n; i++) {

            if(a[i]>a[i-1])
            {
                b[i]=b[i-1]+1;
            }
            else if (a[i]==a[i-1])
            {
                if(b[i-1]>1)
                {
                    b[i]=1;
                }
                else
                {
                    b[i]=b[i-1];
                }
            }

            else
            {
                if(b[i-1]>1)
                {
                    b[i]=1;
                }
                else
                {
                    b[i]=b[i-1];
                }
            }
        }
        for (int i = 0; i <n; i++) {
            sum=sum+b[i];
        }
        System.out.print(sum);
    }
}
